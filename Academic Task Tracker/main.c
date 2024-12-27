// Student No   : EC/2022/030
// Student Name : E.K.G.S.Kithmanthi
// Group ID     : 02


#include <stdio.h>
#include "admin_check.c" 
#include "user_check.c" 

int main() {
    int x;
    do{
        printf("****************************************************** \n");
        printf("\t //WELCOME TO THE ACADEMIC TASK TRACKER// \n");
        printf("****************************************************** \n\n"); 


        user_check(); // Call the function to perform user check

        printf("\n****************************************************** \n\n");
        printf("Do you want to go Main Menu : Press 1\n");
        printf("Do you want to Exit         : Press 0\n");
        printf("Enter your choice: ");
        scanf("%d", &x);

        system("cls");

    }while(x==1);
    printf("Exiting the program.\n");
    sleep(1); //Pause the program for 1 second before exiting 

    return 0;
}
