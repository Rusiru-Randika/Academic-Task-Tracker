// Student No : EC/2022/043
// Student Name : K. Rusiru Randika
// Group ID : 02

#include <stdio.h>
#include <string.h>
// Add linking between files
#include "admin_file_assign.c"

// Function to check admin credentials
int admin_check() {
    FILE *file;
    char entered_username[256];
    char entered_password[256];
    char line[256];
    char correct_password[256];
    int username_found = 0;

    // Loop to repeatedly ask for the username until it is correct
    while (!username_found) {
        // Open the admin.csv file in read mode
        file = fopen("admin.csv", "r");
        if (file == NULL) {
            printf("Error: Could not open file\n");
            return 1;
        }

        // Prompt the user to enter the admin name
        printf("Enter the Admin Name: ");
        scanf("%255s", entered_username);

        // Check if the username exists in the file
        while (fgets(line, sizeof(line), file)) {
            char *username = strtok(line, ",");
            char *password = strtok(NULL, ",");

            // Remove newline character from the password, if present
            if (password != NULL) {
                password[strcspn(password, "\n")] = 0;
            }

            // Compare the entered username with the username in the file
            if (username != NULL && strcmp(username, entered_username) == 0) {
                username_found = 1;
                // Store the correct password for later verification
                strcpy(correct_password, password);
                break;
            }
        }

        // Close the file
        fclose(file);

        // If username is not found, prompt the user to try again
        if (!username_found) {
            printf("Admin not found. Please try again.\n");
        }
    }

    // Loop to repeatedly ask for the password until it is correct
    int password_correct = 0;
    while (!password_correct) {
        // Prompt the user to enter the password
        printf("Enter the Password: ");
        scanf("%255s", entered_password);

        // Compare the entered password with the correct password
        if (strcmp(correct_password, entered_password) == 0) {
            password_correct = 1;
            printf("Admin Name and Password are correct.\n");
            // Call the admin_file function with the entered username
            admin_file(entered_username);
        } else {
            // If password is incorrect, prompt the user to try again
            printf("Incorrect password. Please try again.\n");
        }
    }
    return 0;
}
