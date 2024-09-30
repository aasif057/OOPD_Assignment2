#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Base class for Staff
class Staff {
public:
    char name[100];
    char email[100];
    char room[20];
    char phone[20];
    char position[50];

    Staff(const char* n, const char* e, const char* r, const char* p) {
        strcpy(name, n);
        strcpy(email, e);
        strcpy(room, r);
        strcpy(phone, p);
        strcpy(position, p);
    }

    virtual ~Staff() {}  // Virtual destructor
};

// Registrar class
class Registrar : public Staff {
public:
    Registrar(const char* n, const char* e, const char* r, const char* p) 
        : Staff(n, e, r, p) {}
};

// Dean class
class Dean : public Staff {
public:
    Dean(const char* n, const char* e, const char* r, const char* p) 
        : Staff(n, e, r, p) {}
};

// Associate Dean class
class AssociateDean : public Staff {
public:
    AssociateDean(const char* n, const char* e, const char* r, const char* p) 
        : Staff(n, e, r, p) {}
};

// Administrative Officer class
class AdministrativeOfficer : public Staff {
public:
    AdministrativeOfficer(const char* n, const char* e, const char* r, const char* p) 
        : Staff(n, e, r, p) {}
};

// Junior Administrative Officer class
class JuniorAdministrativeOfficer : public Staff {
public:
    JuniorAdministrativeOfficer(const char* n, const char* e, const char* r, const char* p) 
        : Staff(n, e, r, p) {}
};

// Administrative Department class
class AdministrativeDepartment {
private:
    Registrar* registrar; // Pointer to the department's registrar
    Dean* dean; // Pointer to the department's dean
    AssociateDean* associateDean; // Pointer to the department's associate dean
    AdministrativeOfficer* officers[10]; // Array for administrative officers
    JuniorAdministrativeOfficer* juniorOfficers[10]; // Array for junior officers

    int officerCount;
    int juniorOfficerCount;

public:
    AdministrativeDepartment() 
        : registrar(nullptr), dean(nullptr), associateDean(nullptr), officerCount(0), juniorOfficerCount(0) {}

    void setRegistrar(Registrar* reg) {
        registrar = reg;
    }

    void setDean(Dean* d) {
        dean = d;
    }

    void setAssociateDean(AssociateDean* ad) {
        associateDean = ad;
    }

    void addOfficer(AdministrativeOfficer* officer) {
        if (officerCount < 10) {
            officers[officerCount++] = officer;
        } else {
            cout << "Max number of officers reached!" << endl;
        }
    }

    void addJuniorOfficer(JuniorAdministrativeOfficer* officer) {
        if (juniorOfficerCount < 10) {
            juniorOfficers[juniorOfficerCount++] = officer;
        } else {
            cout << "Max number of junior officers reached!" << endl;
        }
    }

    // Method to display department members with hierarchy
    void displayMembers() const {
        cout << "Department Members:" << endl;
        if (registrar) {
            cout << "Registrar: " << registrar->name << endl;
        }
        if (dean) {
            cout << "Dean: " << dean->name << endl;
        }
        else{
            cout << "No Dean" << endl;
        }
        if (associateDean) {
            cout << "Associate Dean: " << associateDean->name << endl;
        }
        else{
            cout << "No Associate Dean" << endl;
        }
        for (int i = 0; i < officerCount; i++) {
            cout << "Administrative Officer: " << officers[i]->name << endl;
        }
        for (int i = 0; i < juniorOfficerCount; i++) {
            cout << "Junior Administrative Officer: " << juniorOfficers[i]->name << endl;
        }
        cout << endl; // Add a line break for better readability
    }
    bool searchMember(const char* nameToSearch) const {
        if (registrar && strcmp(registrar->name, nameToSearch) == 0) {
            cout << "Name: " << registrar->name << ", Email: " << registrar->email << ", Room: " << registrar->room << ", Phone: " << registrar->phone << endl;
            return true;
        }
        if (dean && strcmp(dean->name, nameToSearch) == 0) {
            cout << "Name: " << dean->name << ", Email: " << dean->email << ", Room: " << dean->room << ", Phone: " << dean->phone << endl;
            return true;
        }
        if (associateDean && strcmp(associateDean->name, nameToSearch) == 0) {
            cout << "Name: " << associateDean->name << ", Email: " << associateDean->email << ", Room: " << associateDean->room << ", Phone: " << associateDean->phone << endl;
            return true;
        }
        for (int i = 0; i < officerCount; i++) {
            if (strcmp(officers[i]->name, nameToSearch) == 0) {
                cout << "Name: " << officers[i]->name << ", Email: " << officers[i]->email << ", Room: " << officers[i]->room << ", Phone: " << officers[i]->phone << endl;
                return true;
            }
        }
        for (int i = 0; i < juniorOfficerCount; i++) {
            if (strcmp(juniorOfficers[i]->name, nameToSearch) == 0) {
                cout << "Name: " << juniorOfficers[i]->name << ", Email: " << juniorOfficers[i]->email << ", Room: " << juniorOfficers[i]->room << ", Phone: " << juniorOfficers[i]->phone << endl;
                return true;
            }
        }
        return false;
    }
};

// Function to load data from CSV file for a specific department
void loadAdministrativeData(const char* filename, AdministrativeDepartment& department, const char* departmentName) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file: " << filename << endl;
        return;
    }

    char line[256];
    file.getline(line, 256); // Skip header

    while (file.getline(line, 256)) {
        char name[100], email[100], room[500], phone[100], position[200], dept[100];
        // cout << line << endl;
        // Updated sscanf to read 6 columns including department
        sscanf(line, "%99[^,],%99[^,],%499[^,],%99[^,],%199[^,],%99[^\n]", name, email, room, phone, position, dept);

        // Only process staff if they belong to the correct department
        if (strcmp(dept, departmentName) == 0) {
            if (strcmp(position, "Dean") == 0) {
                department.setDean(new Dean(name, email, room, phone));
            } else if (strcmp(position, "Associate Dean") == 0) {
                department.setAssociateDean(new AssociateDean(name, email, room, phone));
            } else if (strcmp(position, "Administrative Officer") == 0 || strcmp(position, "Library Officer") == 0) {
                department.addOfficer(new AdministrativeOfficer(name, email, room, phone));
            } else if (strcmp(position, "Junior Administrative Officer") == 0 || strcmp(position, "Junior Library Officer") == 0) {
                department.addJuniorOfficer(new JuniorAdministrativeOfficer(name, email, room, phone));
            }
        }
    }
}

int main() {
    // Create departments
    AdministrativeDepartment irdDepartment;
    AdministrativeDepartment academicsDepartment;
    AdministrativeDepartment studentAffairsDepartment;
    AdministrativeDepartment storePurchaseDepartment;
    AdministrativeDepartment libraryDepartment;

    Registrar* registrar = new Registrar("Dr. Deepika Bhaskar", "deepika@iiitd.ac.in", "Room No. B-204 (Academic Block)", "+91-11-26907419");
    
    // Set registrar for each department
    irdDepartment.setRegistrar(registrar);
    academicsDepartment.setRegistrar(registrar);
    studentAffairsDepartment.setRegistrar(registrar);
    storePurchaseDepartment.setRegistrar(registrar);
    libraryDepartment.setRegistrar(registrar);

    // Load data from CSV for each department
    loadAdministrativeData("/home/aasif057/Documents/OOPD/OOPD_Assignment2/iiit_admin_data.csv", irdDepartment, "IRD");
    loadAdministrativeData("/home/aasif057/Documents/OOPD/OOPD_Assignment2/iiit_admin_data.csv", academicsDepartment, "Academics");
    loadAdministrativeData("/home/aasif057/Documents/OOPD/OOPD_Assignment2/iiit_admin_data.csv", studentAffairsDepartment, "Student Affairs");
    loadAdministrativeData("/home/aasif057/Documents/OOPD/OOPD_Assignment2/iiit_admin_data.csv", storePurchaseDepartment, "Store & Purchase");
    loadAdministrativeData("/home/aasif057/Documents/OOPD/OOPD_Assignment2/iiit_admin_data.csv", libraryDepartment, "Library");

    // Display department members
    cout << "Administrative Structure:\n" << endl;
    cout << "IRD" << endl;
    irdDepartment.displayMembers();
    cout << "Academics" << endl;
    academicsDepartment.displayMembers();
    cout << "Student Affairs" << endl;
    studentAffairsDepartment.displayMembers();
    cout << "Store & Purchase" << endl;
    storePurchaseDepartment.displayMembers();
    cout << "Library" << endl;
    libraryDepartment.displayMembers();
    

    // Search A Staff
    char nameToSearch[100];
    cout << "Enter the name of the staff member to search: ";
    cin.getline(nameToSearch, 100);

    // Search through all departments
    if (irdDepartment.searchMember(nameToSearch)) {
        cout << "Found" << endl;
    }
    else if (academicsDepartment.searchMember(nameToSearch)) {
        cout << "Found" << endl;
    }
    else if (studentAffairsDepartment.searchMember(nameToSearch)) {
        cout << "Found" << endl;
    }
    else if (storePurchaseDepartment.searchMember(nameToSearch)) {
        cout << "Found" << endl;
    }
    else if (libraryDepartment.searchMember(nameToSearch)) {
        cout << "Found" << endl;
    }
    else {
        cout << nameToSearch << "' not found in any department!" << endl;
    }

    delete registrar;
    return 0;
}
