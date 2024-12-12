import requests
from bs4 import BeautifulSoup
from lxml import etree
import csv
import re
# URL of the main page to scrape
url = "https://www.iiitd.ac.in/people/faculty"

# Send a GET request to fetch the page content
response = requests.get(url)
# Check if the request was successful
if response.status_code == 200:
    # Parse the HTML content using BeautifulSoup
    soup = BeautifulSoup(response.content, "html.parser")
    dom = etree.HTML(str(soup))

    # List to store data for CSV
    scraped_data = []

    for person in dom.xpath('//*/div[@class="col-md-2 card rteleft facultycard margin-top-30"]'):
        # Extract the name (within an <h3> tag)
        name = person.xpath(".//h3//text()")
        name = name[0] if name else "NA"

        # Extract the link to the individual page (within the <a> tag inside <h3>)
        individual_link_elements = person.xpath('.//h3[@class="team-title"]//a[@href]')
        individual_link = individual_link_elements[0].get("href") if individual_link_elements else None

        # Extract the email (within <i> tag sibling <a>)
        email_elements = person.xpath('.//div[@class="team-description"]//a[@href]')
        email_href = (
            email_elements[0].get("href").replace("mailto:", "")
            if email_elements
            else "NA"
        )

        # Extract Position and Department
        pos = person.xpath('.//h2[@class="team-subtitle"]//text()')
        position = " ".join(pos).strip() if pos else "NA"
        department = "NA"
        department_match = re.search(r"\((.*?)\)", position)
        if department_match:        
            department = department_match.group(1)
        if position!="NA":
            position = re.sub(r"\((.*?)\)","", position)
        # Initialize room number and phone number
        room_number = "NA"
        phone_number = "NA"

        # Follow the individual link if it exists
        if individual_link:
            individual_page_url = "https://www.iiitd.ac.in" + individual_link
            individual_response = requests.get(individual_page_url)

            if individual_response.status_code == 200:
                individual_soup = BeautifulSoup(individual_response.content, "html.parser")
                individual_dom = etree.HTML(str(individual_soup))

                # Extract room number (if present) - update the XPath based on actual structure
                phone_number_elements = individual_dom.xpath('//i[@class="fa fa-phone"]/../following-sibling::div/div/text()')
                phone_number = phone_number_elements[0].strip() if phone_number_elements else "NA"

                # Extract phone number (if present) - update the XPath based on actual structure
                room_number_elements = individual_dom.xpath('//i[@class="fa fa-map-marker"]/../following-sibling::div/div/text()')
                room_number = room_number_elements[0].strip() if room_number_elements else "NA"

        # Store each person's data in a dictionary
        person_data = {
            "Name": name,
            "Email": email_href,
            "Room": room_number,
            "Phone": phone_number,
            "Position": position,
            "Department": department
        }

        # Add the data to the list
        scraped_data.append(person_data)

    # Write the data to a CSV file (uncomment to enable writing to CSV)
    with open("iiitd_faculty_data.csv", "w", newline="", encoding="utf-8") as csvfile:
        fieldnames = ["Name", "Email", "Room", "Phone", "Position", "Department"]
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)

        writer.writeheader()  # Write the header
        writer.writerows(scraped_data)  # Write the rows of data

    print("Data successfully written to 'iiitd_admin_data.csv'.")

else:
    print(f"Failed to retrieve the page. Status code: {response.status_code}")
