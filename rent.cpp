#include <iostream>
using namespace std;

string tenant_id[30], tenant_name[30], apartment_no[30], rent_month[30], rent_amount[30], contact_no[30];
int total = 0;

// 1. Enter: Add new tenant records
void enter() {
    int ch = 0;
    cout << "How many tenant records do you want to enter? ";
    cin >> ch;
    if (ch <= 0) return;

    int start = total;
    total += ch;
    for (int i = start; i < total; ++i) {
        cout << "\nEnter data for tenant " << (i + 1) << ":\n";
        cout << "Tenant ID: ";        cin >> tenant_id[i];
        cout << "Name: ";             cin >> tenant_name[i];
        cout << "Apartment No.: ";    cin >> apartment_no[i];
        cout << "Rent Month (e.g., Jun-2025): "; cin >> rent_month[i];
        cout << "Rent Amount: ";      cin >> rent_amount[i];
        cout << "Contact No.: ";      cin >> contact_no[i];
    }
}

// 2. Show: Display all tenant records
void show() {
    if (total == 0) {
        cout << "No tenant records available.\n";
        return;
    }
    for (int i = 0; i < total; ++i) {
        cout << "\nTenant Record " << (i + 1) << ":\n";
        cout << "Tenant ID: "     << tenant_id[i] << "\n";
        cout << "Name: "          << tenant_name[i] << "\n";
        cout << "Apartment No.: " << apartment_no[i] << "\n";
        cout << "Rent Month: "    << rent_month[i] << "\n";
        cout << "Rent Amount: "   << rent_amount[i] << "\n";
        cout << "Contact No.: "   << contact_no[i] << "\n";
    }
}

// 3. Search: Find a tenant by ID
void searchRecord() {
    if (total == 0) {
        cout << "No tenant records to search.\n";
        return;
    }
    string tid;
    cout << "Enter Tenant ID to search: ";
    cin >> tid;

    for (int i = 0; i < total; ++i) {
        if (tenant_id[i] == tid) {
            cout << "\nRecord found:\n";
            cout << "Tenant ID: "     << tenant_id[i] << "\n";
            cout << "Name: "          << tenant_name[i] << "\n";
            cout << "Apartment No.: " << apartment_no[i] << "\n";
            cout << "Rent Month: "    << rent_month[i] << "\n";
            cout << "Rent Amount: "   << rent_amount[i] << "\n";
            cout << "Contact No.: "   << contact_no[i] << "\n";
            return;
        }
    }
    cout << "Tenant ID " << tid << " not found.\n";
}

// 4. Update: Modify an existing tenant's record
void update() {
    if (total == 0) {
        cout << "No tenant records to update.\n";
        return;
    }
    string tid;
    cout << "Enter Tenant ID to update: ";
    cin >> tid;

    for (int i = 0; i < total; ++i) {
        if (tenant_id[i] == tid) {
            cout << "\nPrevious data for tenant " << (i + 1) << ":\n";
            cout << "Tenant ID: "     << tenant_id[i] << "\n";
            cout << "Name: "          << tenant_name[i] << "\n";
            cout << "Apartment No.: " << apartment_no[i] << "\n";
            cout << "Rent Month: "    << rent_month[i] << "\n";
            cout << "Rent Amount: "   << rent_amount[i] << "\n";
            cout << "Contact No.: "   << contact_no[i] << "\n";

            cout << "\nEnter new data:\n";
            cout << "Tenant ID: ";        cin >> tenant_id[i];
            cout << "Name: ";             cin >> tenant_name[i];
            cout << "Apartment No.: ";    cin >> apartment_no[i];
            cout << "Rent Month: ";       cin >> rent_month[i];
            cout << "Rent Amount: ";      cin >> rent_amount[i];
            cout << "Contact No.: ";      cin >> contact_no[i];
            cout << "Record updated.\n";
            return;
        }
    }
    cout << "Tenant ID " << tid << " not found.\n";
}

// 5. Delete: Option to delete all records
void Delete() {
    if (total == 0) {
        cout << "No tenant records to delete.\n";
        return;
    }
    int a;
    cout << "Are you sure you want to delete all records? (Press 1 to confirm): ";
    cin >> a;
    if (a == 1) {
        total = 0;
        cout << "All tenant records have been deleted.\n";
    } else {
        cout << "Deletion canceled.\n";
    }
}

int main() {
    int value;
    while (true) {
        cout << "\n===== Tenant Rent Management =====\n";
        cout << "1. Enter tenant records\n";
        cout << "2. Show all records\n";
        cout << "3. Search by Tenant ID\n";
        cout << "4. Update a record\n";
        cout << "5. Delete all records\n";
        cout << "6. Quit\n";
        cout << "Choose an option: ";
cin >> value;

        switch (value) {
            case 1: enter();       break;
            case 2: show();        break;
            case 3: searchRecord();break;
            case 4: update();      break;
            case 5: Delete();      break;
            case 6: exit(0);       break;
            default: cout << "Invalid option, try again.\n";
        }
    }
    return 0;
}
