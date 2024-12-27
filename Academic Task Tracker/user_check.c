// Student No   : EC/2022/030
// Student Name : E.K.G.S.Kithmanthi
// Group ID     : 02


#include <stdio.h>
#include "student.c"

int user_check(){
    int userType;

    do {
        printf("If you are a Student : Press 1 \n");
        printf("If you are an Admin  : Press 2 \n");
        printf("If you want to Exit  : Press 3 \n");

        printf("Enter your choice : ");

        if (scanf("%d", &userType) == 1) {

            if (userType == 1) {
                studentAccess(); // Call the function for student access
                break;
            } else if (userType == 2) {
                admin_check(); // Call the function for admin access
                break;
            } else if (userType == 3) {
                printf("Exiting the program.\n");
                sleep(1);// Pause the program for 1 second
                exit(0); 
            } else {
                printf("Invalid input. Please enter a valid number (1 or 2 or 3).\n\n");
            }

        } else {
            printf("Invalid input. Please enter a valid number (1 or 2 or 3).\n\n");
        
            while(getchar() != '\n');  // Clear the input buffer incase of invalid input
        }

    } while (1);//keep looping until a valid input is provided
    
    return 0;
}
