#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;

// Base class for Faculty
class Faculty {
public:
    char name[100];
    char email[100];
    char room[100];
    char phone[50];
    char position[50];

    Faculty(const char* n, const char* e, const char* r, const char* p) {
        strcpy(name, n);
        strcpy(email, e);
        strcpy(room, r);
        strcpy(phone, p);
        strcpy(position, p);
    }

    virtual ~Faculty() {}  // Virtual destructor
};

// Administrative Officer class
class AdministrativeOfficer : public Faculty {
public:
    AdministrativeOfficer(const char* n, const char* e, const char* r, const char* p) 
        : Faculty(n, e, r, p) {}
};

// Head class
class Head : public Faculty {
public:
    Head(const char* n, const char* e, const char* r, const char* p) 
        : Faculty(n, e, r, p) {}
};

// Professor class
class Professor : public Faculty {
public:
    Professor(const char* n, const char* e, const char* r, const char* p) 
        : Faculty(n, e, r, p) {}
};

// Associate Professor class
class AssociateProfessor : public Faculty {
public:
    AssociateProfessor(const char* n, const char* e, const char* r, const char* p) 
        : Faculty(n, e, r, p) {}
};

// Assistant Professor class
class AssistantProfessor : public Faculty {
public:
    AssistantProfessor(const char* n, const char* e, const char* r, const char* p) 
        : Faculty(n, e, r, p) {}
};

// Academics Departments class
class AcademicsDepartment {
private:
    AdministrativeOfficer* administrativeOfficer; // Pointer to the Administrative Officer
    Head* head; // Pointer to department Head
    Professor* professors[20]; // Array for Professors
    AssociateProfessor* associateProfessors[20]; // Array for Associate Professors
    AssistantProfessor* assistantProfessors[20]; // Array for Assistant Professors

    int professorCount;
    int associateCount;
    int assistantCount;

public:
    AcademicsDepartment() 
        : administrativeOfficer(nullptr), head(nullptr), professorCount(0), associateCount(0), assistantCount(0) {}

    void setAdministrativeOfficer(AdministrativeOfficer* ao) {
        administrativeOfficer = ao;
    }

    void setHead(Head* h) {
        head = h;
    }

    void addProfessor(Professor* p) {
        if (professorCount < 20) {
            professors[professorCount++] = p;
        } else {
            cout << "Max number of Professors reached!" << endl;
        }
    }

    void addAssociateProfessor(AssociateProfessor* associate) {
        if (associateCount < 20) {
            associateProfessors[associateCount++] = associate;
        } else {
            cout << "Max number of Associate Professors reached!" << endl;
        }
    }

    void addAssistantProfessor(AssistantProfessor* assistant) {
        if (assistantCount < 20) {
            assistantProfessors[assistantCount++] = assistant;
        } else {
            cout << "Max number of Assistant Professors reached!" << endl;
        }
    }

    // Method to display department members with hierarchy
    void displayMembers() const {
        cout << "Department Members:" << endl;
        if (administrativeOfficer) {
            cout << "Administrative Officer: " << administrativeOfficer->name << endl;
        }
        if (head) {
            cout << "Head: " << head->name << endl;
        }
        for (int i = 0; i < professorCount; i++) {
            cout << "Professor: " << professors[i]->name << endl;
        }
        for (int i = 0; i < associateCount; i++) {
            cout << "Associate Professor: " << associateProfessors[i]->name << endl;
        }
        for (int i = 0; i < assistantCount; i++) {
            cout << "Assistant Professor: " << assistantProfessors[i]->name << endl;
        }
        cout << "-----------------------------------------------------------" << endl; // Add a line break for better readability
    }

    // Destructor to clean up dynamically allocated objects
    ~AcademicsDepartment() {
        delete administrativeOfficer;
        delete head;
        for (int i = 0; i < professorCount; i++) {
            delete professors[i];
        }
        for (int i = 0; i < associateCount; i++) {
            delete associateProfessors[i];
        }
        for (int i = 0; i < assistantCount; i++) {
            delete assistantProfessors[i];
        }
    }

    bool searchMember(const char* nameToSearch) const {
        if (administrativeOfficer && strcmp(administrativeOfficer->name, nameToSearch) == 0) {
            cout << "Name: " << administrativeOfficer->name << ", Email: " << administrativeOfficer->email 
                 << ", Room: " << administrativeOfficer->room << ", Phone: " << administrativeOfficer->phone << endl;
            return true;
        }
        if (head && strcmp(head->name, nameToSearch) == 0) {
            cout << "Name: " << head->name << ", Email: " << head->email 
                 << ", Room: " << head->room << ", Phone: " << head->phone << endl;
            return true;
        }
        for (int i = 0; i < professorCount; i++) {
            if (strcmp(professors[i]->name, nameToSearch) == 0) {
                cout << "Name: " << professors[i]->name << ", Email: " << professors[i]->email 
                     << ", Room: " << professors[i]->room << ", Phone: " << professors[i]->phone << endl;
                return true;
            }
        }
        for (int i = 0; i < associateCount; i++) {
            if (strcmp(associateProfessors[i]->name, nameToSearch) == 0) {
                cout << "Name: " << associateProfessors[i]->name << ", Email: " << associateProfessors[i]->email 
                     << ", Room: " << associateProfessors[i]->room << ", Phone: " << associateProfessors[i]->phone << endl;
                return true;
            }
        }
        for (int i = 0; i < assistantCount; i++) {
            if (strcmp(assistantProfessors[i]->name, nameToSearch) == 0) {
                cout << "Name: " << assistantProfessors[i]->name << ", Email: " << assistantProfessors[i]->email 
                     << ", Room: " << assistantProfessors[i]->room << ", Phone: " << assistantProfessors[i]->phone << endl;
                return true;
            }
        }
        return false;
    }
};
void trim(char* str) {
    // Remove leading spaces
    char* start = str;
    while (isspace((unsigned char)*start)) start++;

    // All spaces, set the string to an empty one
    if (*start == 0) {
        *str = 0;
        return;
    }

    // Remove trailing spaces
    char* end = start + strlen(start) - 1;
    while (end > start && isspace((unsigned char)*end)) end--;

    // Null-terminate the string after the last non-space character
    end[1] = '\0';

    // Move the trimmed string to the beginning
    if (start != str) {
        memmove(str, start, end - start + 2);
    }
}
// Function to load data from CSV file for a specific department
void loadAdministrativeData(const char* filename, AcademicsDepartment& department, const char* departmentName) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file: " << filename << endl;
        return;
    }

    char line[256];
    file.getline(line, 256); // Skip header

    while (file.getline(line, 256)) {
        char name[300], email[200], room[500], phone[200], position[300], dept[100];
        sscanf(line, "%299[^,],%199[^,],%499[^,],%199[^,],%299[^,],%99[^\n]", name, email, room, phone, position, dept);
        trim(dept);
        if (strcmp(dept, departmentName) == 0) {
            cout << "Yes" << endl;
            if (strcmp(position, "Head") == 0) {
                department.setHead(new Head(name, email, room, phone));
            } else if (strcmp(position, "Professor") == 0) {
                department.addProfessor(new Professor(name, email, room, phone));
            } else if (strcmp(position, "Associate Professor") == 0) {
                department.addAssociateProfessor(new AssociateProfessor(name, email, room, phone));
            } else if (strcmp(position, "Assistant Professor") == 0) {
                department.addAssistantProfessor(new AssistantProfessor(name, email, room, phone));
            }
        }
    }
}

int main() {
    // Create departments
    AcademicsDepartment eceDepartment;
    AcademicsDepartment cseDepartment;
    AcademicsDepartment sshDepartment;
    AcademicsDepartment mathDepartment;
    AcademicsDepartment cbDepartment;
    AcademicsDepartment hcdDepartment;

    //Add Administrative Officer
    AdministrativeOfficer* administrativeOfficer = new AdministrativeOfficer("Sumit J Darak", "doaa@iiitd.ac.in", "NA", "+91-11-26907427");
    //Add Administrative Officer to every Department
    eceDepartment.setAdministrativeOfficer(administrativeOfficer);
    cseDepartment.setAdministrativeOfficer(administrativeOfficer);
    sshDepartment.setAdministrativeOfficer(administrativeOfficer);
    mathDepartment.setAdministrativeOfficer(administrativeOfficer);
    cbDepartment.setAdministrativeOfficer(administrativeOfficer);
    hcdDepartment.setAdministrativeOfficer(administrativeOfficer);

    // Load data from CSV for each department
    loadAdministrativeData("/home/aasif057/Documents/OOPD/OOPD_Assignment2/iiitd_faculty_data.csv", eceDepartment, "ECE");
    loadAdministrativeData("/home/aasif057/Documents/OOPD/OOPD_Assignment2/iiitd_faculty_data.csv", cseDepartment, "CSE");
    loadAdministrativeData("/home/aasif057/Documents/OOPD/OOPD_Assignment2/iiitd_faculty_data.csv", sshDepartment, "SSH");
    loadAdministrativeData("/home/aasif057/Documents/OOPD/OOPD_Assignment2/iiitd_faculty_data.csv", mathDepartment, "Math");
    loadAdministrativeData("/home/aasif057/Documents/OOPD/OOPD_Assignment2/iiitd_faculty_data.csv", cbDepartment, "CB");
    loadAdministrativeData("/home/aasif057/Documents/OOPD/OOPD_Assignment2/iiitd_faculty_data.csv", hcdDepartment, "HCD");

    // Display department members
    cout << "Administrative Structure:\n" << endl;
    cout << "ECE Department" << endl;
    eceDepartment.displayMembers();
    cout << "CSE Department" << endl;
    cseDepartment.displayMembers();
    cout << "SSH Department" << endl;
    sshDepartment.displayMembers();
    cout << "Math Department" << endl;
    mathDepartment.displayMembers();

    char nameToSearch[100];
    cout << "Enter the name of the Faculty member to search: ";
    cin.getline(nameToSearch, 100);

    // Search through all departments
    if (eceDepartment.searchMember(nameToSearch) || cseDepartment.searchMember(nameToSearch) || 
        sshDepartment.searchMember(nameToSearch) || mathDepartment.searchMember(nameToSearch) || 
        cbDepartment.searchMember(nameToSearch) || hcdDepartment.searchMember(nameToSearch)) {
        cout << "Found" << endl;
    } else {
        cout << nameToSearch << " not found in any department!" << endl;
    }
    return 0;
}
