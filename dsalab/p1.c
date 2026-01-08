#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure definition
struct Contact {
    int roll;
    char studentName[50];
    char parentName[50];
    char phone[15];
};

// Global variables
struct Contact c[MAX];
int count = 0;

// Function declarations
void addContact();
void displayContacts();
void searchContact();
void updateContact();
void deleteContact();

int main() {
    int choice;

    do {
        printf("\n--- Student / Parent Contact Management System ---\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: updateContact(); break;
            case 5: deleteContact(); break;
            case 6: printf("Exiting program...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 6);

    return 0;
}

// Add contact
void addContact() {
    if (count >= MAX) {
        printf("Contact list full!\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &c[count].roll);

    printf("Enter Student Name: ");
    scanf("%s", c[count].studentName);

    printf("Enter Parent Name: ");
    scanf("%s", c[count].parentName);

    printf("Enter Parent Mobile Number: ");
    scanf("%s", c[count].phone);

    count++;
    printf("Contact added successfully!\n");
}

// Display contacts
void displayContacts() {
    if (count == 0) {
        printf("No contacts available!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nRoll No: %d", c[i].roll);
        printf("\nStudent Name: %s", c[i].studentName);
        printf("\nParent Name: %s", c[i].parentName);
        printf("\nMobile Number: %s\n", c[i].phone);
    }
}

// Search contact
void searchContact() {
    int roll, found = 0;
    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (c[i].roll == roll) {
            printf("\nContact Found!");
            printf("\nStudent Name: %s", c[i].studentName);
            printf("\nParent Name: %s", c[i].parentName);
            printf("\nMobile Number: %s\n", c[i].phone);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Contact not found!\n");
}

// Update contact
void updateContact() {
    int roll, found = 0;
    printf("Enter Roll Number to update: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (c[i].roll == roll) {
            printf("Enter New Student Name: ");
            scanf("%s", c[i].studentName);

            printf("Enter New Parent Name: ");
            scanf("%s", c[i].parentName);

            printf("Enter New Mobile Number: ");
            scanf("%s", c[i].phone);

            printf("Contact updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Contact not found!\n");
}

// Delete contact
void deleteContact() {
    int roll, found = 0;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (c[i].roll == roll) {
            for (int j = i; j < count - 1; j++) {
                c[j] = c[j + 1];
            }
            count--;
            printf("Contact deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Contact not found!\n");
}
