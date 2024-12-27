//Student No: EC/2022/025
//Student Name: S.H.K.Chamarindi
//Group ID: 02

#include <stdio.h>
#include <string.h>
#include "task_manage.c"

// Function to handle admin file based on entered username
int admin_file(char entered_username[256]) {
    // Check if the username belongs to the EC Department
    if (strncmp(entered_username, "EC", 2) == 0) {
        // Check for specific years and call tasks function with the corresponding filename
        if (entered_username[5] == '2' && entered_username[6] == '0') {
            printf("EC Department 2020\n");
            const char *filename = "EC2020.csv";
            tasks(filename);
        } 
        else if (entered_username[5] == '2' && entered_username[6] == '1') {
            printf("EC Department 2021\n");
            const char *filename = "EC2021.csv";
            tasks(filename);
        } 
        else if (entered_username[5] == '2' && entered_username[6] == '2') {
            printf("EC Department 2022\n");
            const char *filename = "EC2022.csv";
            tasks(filename);
        } 
        else if (entered_username[5] == '2' && entered_username[6] == '3') {
            printf("EC Department 2023\n");
            const char *filename = "EC2023.csv";
            tasks(filename);
        } 
        // Handle case for unknown year in EC Department
        else {
            printf("Unknown EC Department\n");
        }
    // Check if the username belongs to the PS Department
    } else if (strncmp(entered_username, "PS", 2) == 0) {
        // Check for specific years and call tasks function with the corresponding filename
        if (entered_username[5] == '2' && entered_username[6] == '0') {
            printf("PS Department 2020\n");
            const char *filename = "PS2020.csv";
            tasks(filename);
        } 
        else if (entered_username[5] == '2' && entered_username[6] == '1') {
            printf("PS Department 2021\n");
            const char *filename = "PS2021.csv";
            tasks(filename);
        } 
        else if (entered_username[5] == '2' && entered_username[6] == '2') {
            printf("PS Department 2022\n");
            const char *filename = "PS2022.csv";
            tasks(filename);
        } 
        else if (entered_username[5] == '2' && entered_username[6] == '3') {
            printf("PS Department 2023\n");
            const char *filename = "PS2023.csv";
            tasks(filename);
        } 
        // Handle case for unknown year in PS Department
        else {
            printf("Unknown PS Department\n");
        }
    } 
    // Handle case for unknown department
    else {
        printf("Unknown Department\n");
    }
    return 0; // Return success
}
