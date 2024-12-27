// Student No: EC/2022/054
// Student Name: W.A.B Sankalpa
// Group ID : 02

#include <stdio.h>
#include <string.h>

// Function declarations
int checkDepartment(const char* studentNumber);
int checkYear(const char* studentNumber);
int checkStudentID(const char* studentNumber, int departmentCode, int year);
void studentAccess();

// Function to check the department using the first two letters
int checkDepartment(const char* studentNumber) {
    char department[3];
    strncpy(department, studentNumber, 2);
    department[2] = '\0';

    if (strcmp(department, "EC") == 0) {
        return 1;
    } else if (strcmp(department, "PS") == 0) {
        return 2;
    } else {
        return 0;  // Invalid department
    }
}

// Function to check the year
int checkYear(const char* studentNumber) {
    int year;
    sscanf(studentNumber, "%*[^/]/%d/%*d", &year);

    if (year == 2021 || year == 2022 || year == 2023) {
        return year;
    } else {
        return 0;  // Invalid year
    }
}

// Function to check the last three numbers based on the department and year
int checkStudentID(const char* studentNumber, int departmentCode, int year) {
    int id;
    sscanf(studentNumber, "%*[^/]/%*d/%d", &id);

    if (departmentCode == 1) {  // EC department
        if ((year == 2021 && id <= 77) || (year == 2022 && id <= 75) || (year == 2023 && id <= 78)) {
            return 1;
        } else {
            return 0;  // Invalid ID for the year in EC department
        }
    } else if (departmentCode == 2) {  // PS department
        if ((year == 2021 && id <= 250) || (year == 2022 && id <= 245) || (year == 2023 && id <= 240)) {
            return 1;
        } else {
            return 0;  // Invalid ID for the year in PS department
        }
    } else {
        return 0;  // Invalid department
    }
}

// Student access function
void studentAccess() {
    char studentNumber[15];
    int departmentCode, year, validID;

    printf("Enter your student number (e.g., EC/2022/054): ");
    scanf("%s", studentNumber);

    // Check if the student number is exactly 11 characters long
    if (strlen(studentNumber) != 11) {
        printf("Invalid student number! Please check and try again.\n");
        studentAccess();  // Recursive call to studentAccess function
        return;
    }

    departmentCode = checkDepartment(studentNumber);
    year = checkYear(studentNumber);
    validID = checkStudentID(studentNumber, departmentCode, year);

    if (departmentCode && year && validID) {
        printf("Student Number: %s\n", studentNumber);
        if (departmentCode == 1) {
            printf("Department: EC\n");
        } else {
            printf("Department: PS\n");
        }
        printf("Year: %d\n", year);

        // Print specific tasks based on department and year using logical AND (&&) conditions
        if (departmentCode == 1 && year == 2021) {
            printf("Tasks for EC department, year 2021:\n");
            const char *filename = "EC2021.csv";
            load_tasks(filename);
            display_tasks();
        } else if (departmentCode == 1 && year == 2022) {
            printf("Tasks for EC department, year 2022:\n");
            const char *filename = "EC2022.csv";
            load_tasks(filename);
            display_tasks();
        } else if (departmentCode == 1 && year == 2023) {
            printf("Tasks for EC department, year 2023:\n");
            printf("1. Research Paper - Due: 2024-10-15\n");
            printf("2. Lab Report - Date: 2024-10-20\n");
            printf("3. End-semester Exam - Date: 2024-11-01\n");
        } else if (departmentCode == 2 && year == 2021) {
            printf("Tasks for PS department, year 2021:\n");
            printf("1. Lab Experiment - Due: 2024-08-15\n");
            printf("2. Theory Test - Date: 2024-08-25\n");
            printf("3. Research Project - Date: 2024-09-05\n");
        } else if (departmentCode == 2 && year == 2022) {
            printf("Tasks for PS department, year 2022:\n");
            printf("1. Case Study - Due: 2024-09-15\n");
            printf("2. Mid-term Test - Date: 2024-09-20\n");
            printf("3. Final Exam - Date: 2024-10-05\n");
        } else if (departmentCode == 2 && year == 2023) {
            printf("Tasks for PS department, year 2023:\n");
            printf("1. Term Paper - Due: 2024-10-10\n");
            printf("2. Oral Exam - Date: 2024-10-15\n");
            printf("3. Final Project - Date: 2024-11-01\n");
        }
    } else {
        printf("Invalid student number! Please check and try again.\n");
        studentAccess();  // Recursive call to studentAccess function
    }
}
