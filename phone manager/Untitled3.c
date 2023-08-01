
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

void saveContactsToFile(const Contact* phoneBook, int numContacts, const char* fileName) {
    FILE* file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", fileName);
        return;
    }

    for (int i = 0; i < numContacts; i++) {
        fprintf(file, "|\t%s\t|\t%s\t|\n", phoneBook[i].name, phoneBook[i].phone);
    }

    fclose(file);
}

int main() {
    Contact phoneBook[MAX_CONTACTS];
    int numContacts = 0;
    int choice;
    char fileName[100];
    int optionsPrinted = 0; // To track if options have been printed once

    printf("Phone Book Management System\n");

    do {
        if (!optionsPrinted) {
            printf("\n1. Add Contact\n");
            printf("2. View Contacts\n");
            printf("3. Save Contacts to File\n");
            printf("4. Options\n");
            printf("5. Exit\n");
            optionsPrinted = 1;
        }

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (numContacts == MAX_CONTACTS) {
                    printf("Phone book is full. Cannot add more contacts.\n");
                    break;
                }

                printf("Enter the name: ");
                scanf(" %[^\n]", phoneBook[numContacts].name);

                printf("Enter the phone number: ");
                scanf("%s", phoneBook[numContacts].phone);

                numContacts++;
                printf("Contact added successfully.\n");
                break;
            }
            case 2: {
                if (numContacts == 0) {
                    printf("Phone book is empty.\n");
                    break;
                }

                printf("Phone Book Contacts:\n");
                for (int i = 0; i < numContacts; i++) {
                    printf("%d. Name: %s Phone: %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
                }
                break;
            }
            case 3: {
                printf("Enter the name of the file to save contacts: ");
                scanf("%s", fileName);
                saveContactsToFile(phoneBook, numContacts, fileName);
                printf("Contacts saved to %s\n", fileName);
                break;
            }
            case 4:
                optionsPrinted = 0; // Allow options to be printed again
                break;
            case 5:
                printf("Exiting the phone book management system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
