// Student No: EC/2022/079
// Student Name: B.I.Umayanga
// Group ID : 02


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_ENTRIES 100

char task[MAX_ENTRIES][100];
char due_date[MAX_ENTRIES][11];
int task_count = 0;

// Function to validate the date
bool is_valid_date(int day, int month, int year) {
    if (year < 2024 || year > 2500) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    
    if (month == 2) {
        bool is_leap = (year % 4 == 0);
        if (is_leap && day > 29) return false;
        if (!is_leap && day > 28) return false;
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
    return true;
}

// Function to format the date
int format_date(char *date) {
    int day, month, year;
    if (sscanf(date, "%d/%d/%d", &day, &month, &year) != 3) {
        printf("Error: Invalid date format. Please use DD/MM/YYYY.\n");
        return 1;
    }
    if (!is_valid_date(day, month, year)) {
        printf("Error: Invalid date entered. Please check the day, month, and year values.\n");
        return 1;
    }
    sprintf(date, "%02d/%02d/%04d", day, month, year);
    return 0;
}

// Function to clear the screen
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Function to load tasks from a file
void load_tasks(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file %s\n", filename);
        exit(1);
    }

    char line[1024];
    task_count = 0;
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;
        char *token = strtok(line, ",");
        if (token == NULL) continue;
        strcpy(task[task_count], token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        format_date(token);
        strcpy(due_date[task_count], token);

        task_count++;
    }

    fclose(file);
}

// Function to convert date to integer for comparison
int convert_date_to_int(const char *date_str) {
    int day, month, year;
    sscanf(date_str, "%d/%d/%d", &day, &month, &year);
    return year * 10000 + month * 100 + day;
}

// Function to sort tasks by due date using selection sort
void selection_sort(int indices[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (convert_date_to_int(due_date[indices[j]]) < convert_date_to_int(due_date[indices[min_idx]])) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = indices[i];
            indices[i] = indices[min_idx];
            indices[min_idx] = temp;
        }
    }
}

// Function to display tasks
void display_tasks() {
    int indices[MAX_ENTRIES];
    for (int i = 0; i < task_count; i++) {
        indices[i] = i;
    }

    selection_sort(indices, task_count);
    printf("\nTasks:\n");
    for (int i = 0; i < task_count; i++) {
        int idx = indices[i];
        printf("%d. Task: %s, Due Date: %s\n", i + 1, task[idx], due_date[idx]);
    }
}

// Function to add a new task
void add_task() {
    if (task_count >= MAX_ENTRIES) {
        printf("Error: Maximum number of tasks reached.\n");
        return;
    }

    printf("Enter task name: ");
    scanf(" %[^\n]", task[task_count]);

    while (true) {
        printf("Enter due date (DD/MM/YYYY): ");
        char date[11];
        scanf(" %[^\n]", date);

        if (!format_date(date)) {
            strcpy(due_date[task_count], date);
            break;
        }
    }

    task_count++;
    printf("Task added successfully.\n");
}

// Function to edit the due date of a task
void edit_task_due_date(int index) {
    if (index < 0 || index >= task_count) {
        printf("Invalid task index.\n");
        return;
    }

    printf("Editing due date for task '%s'\n", task[index]);

    while (true) {
        printf("Enter new due date (DD/MM/YYYY): ");
        char date[11];
        scanf(" %[^\n]", date);

        if (!format_date(date)) {
            strcpy(due_date[index], date);
            printf("Due date updated successfully.\n");
            break;
        }
    }
}

// Function to delete a task
void delete_task(int index) {
    if (index < 0 || index >= task_count) {
        printf("Invalid task index.\n");
        return;
    }

    for (int i = index; i < task_count - 1; i++) {
        strcpy(task[i], task[i + 1]);
        strcpy(due_date[i], due_date[i + 1]);
    }

    task_count--;
    printf("Task deleted successfully.\n");

    if (task_count == 0) {
        printf("No tasks remaining.\n");
    }
}

// Function to save tasks to a file
void save_tasks(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Failed to open %s for writing\n", filename);
        exit(1);
    }

    int indices[MAX_ENTRIES];
    for (int i = 0; i < task_count; i++) {
        indices[i] = i;
    }

    selection_sort(indices, task_count);
    for (int i = 0; i < task_count; i++) {
        int idx = indices[i];
        fprintf(file, "%s,%s\n", task[idx], due_date[idx]);
    }
    fclose(file);
    printf("Tasks saved successfully\n");
}

// Function to update the indices array
void update_indices(int indices[]) {
    for (int i = 0; i < task_count; i++) {
        indices[i] = i;
    }
    selection_sort(indices, task_count);
}

// Main function to manage tasks
int tasks(const char *filename) {
    load_tasks(filename);

    int indices[MAX_ENTRIES];
    update_indices(indices);
    int choice;
    char input[10];

    do {
        clear_screen();
        display_tasks();

        printf("\nOptions:\n");
        printf("1. Add Task\n");
        printf("2. Edit Task Due Date\n");
        printf("3. Delete Task\n");
        printf("4. Exit Admin Mode\n");
        printf("Enter your choice: ");
        scanf("%s", input);

        choice = atoi(input);

        switch (choice) {
            case 1:
                add_task();
                save_tasks(filename);
                update_indices(indices);
                break;
            case 2: {
                char input_task_index[10];
                int task_index;
                do {
                    printf("Enter task number to edit due date: ");
                    scanf("%s", input_task_index);
                    task_index = atoi(input_task_index);

                    if (task_index < 1 || task_index > task_count) {
                        printf("Error: Invalid task number. Please enter a valid task number.\n");
                        sleep(2);
                    }
                } while (task_index < 1 || task_index > task_count);

                edit_task_due_date(indices[task_index - 1]);
                save_tasks(filename);
                break;
            }
            case 3: {
                char input_task_index[10];
                int task_index;
                do {
                    printf("Enter task number to delete: ");
                    scanf("%s", input_task_index);
                    task_index = atoi(input_task_index);

                    if (task_index < 1 || task_index > task_count) {
                        printf("Error: Invalid task number. Please enter a valid task number.\n");
                        sleep(2);
                    }
                } while (task_index < 1 || task_index > task_count);

                delete_task(indices[task_index - 1]);
                save_tasks(filename);
                break;
            }
            case 4:
                printf("Exiting Admin Mode\n");
                sleep(2);
                break;
            default:
                printf("Invalid choice. Please select between 1 and 4.\n");
                sleep(2);
        }
    } while (choice != 4);

    return 0;
}
