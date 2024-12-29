#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include "structs.h"
#include "color.h"
void loginMenu(){
    char check[MAX_SIZE];
    usleep(500000);
    yellow();
    printf("======================================\n");
    printf("1.Reserve a room\n");
    printf("2.Check-in\n");
    printf("3.Cancel Reservation\n");
    printf("4.Check-out\n");
    printf("5.Check Room Availability\n");
    printf("6.View Customer Details\n");
    printf("7.Edit Reservation Details\n");
    printf("8.Query (search)\n");
    printf("9.Reservation Report\n");
    printf("10.Exit\n");
    printf("======================================\n");
    cyan();
    printf("> Please enter your choice:\n");
    white();
    scanf("%s",check);
    while(strcmp(check,"1")&&strcmp(check,"2")&&strcmp(check,"3")&&strcmp(check,"4")&&
          strcmp(check,"5")&&strcmp(check,"6")&&strcmp(check,"7")&&strcmp(check,"8")
          &&strcmp(check,"9")&&strcmp(check,"10"))
    {
        red();
        usleep(500000);
        printf("> You entered wrong number!\n");
        cyan();
        printf("> Please enter a valid choice:\n");
        white();
        scanf("%s",check);
    }
    switch(atoi(check))
    {
    case 1:
        roomReservation();
        break;
    case 2:
        checkIn();
        break;
    case 3:
        cancelReservation();
        break;
    case 4:
        checkOut();
        break;
    case 5:
        trackRoomAvailabitity();
        break;
    case 6:
        viewCustomersDetails();
        break;
    case 7:
        editReservation();
        break;
    case 8:
        query();
        break;
    case 9:
        report();
        break;
    case 10:
        getchar();
        quit();
    }
    }
void BackToMenuOrExit(){
    char buffer[MAX_SIZE];
    usleep(500000);
    yellow();
    printf("======================================\n");
    printf("1.Back to the menu\n2.Exit\n");
    printf("======================================\n");
    cyan();
    printf("> Please enter your choice:\n");
    white();
    scanf("%s",buffer);
    while(atoll(buffer)!=1&&atoll(buffer)!=2)
    {
        red();
        printf("> Invalid choice!\n");
        cyan();
        printf("> Please enter a valid choice:\n");
        white();
        scanf("%s",buffer);
    }
    switch(atoll(buffer))
    {
    case 1:
        green();
    printf("======================================\n");
    printf("> Going Back to Main Menu...\n");
    printf("======================================\n");
    usleep(500000);
        loginMenu();
        break;
    case 2:
        getchar();
        quit();
        break;
}
}
void systemInterface(){
    char check[MAX_SIZE];
    yellow();
    usleep(500000);
    printf("======================================\n");
    printf("1.Login\n");
    printf("2.Exit\n");
    printf("======================================\n");
    cyan();
    printf("> Please enter your choice:\n");
    white();
    gets(check);
    while(strcmp(check,"1")&&strcmp(check,"2"))
    {
        red();
        printf("> Invalid input!\n");
        printf("> Enter a valid number:\n");
        white();
        gets(check);
    }
    switch(atoi(check))
    {
    case 1:
        while(!login()){
        red();
        printf("> Enter again!\n");
        white();
        }
        loginMenu();
        break;
    case 2:
        usleep(500000);
        white();
        quit();
    }
}
void quit(){
    char yesOrNo[MAX_SIZE];
    char yes[]="yes",no[]="no";
    int counter=0;
    red();
    printf("======================================\n");
    printf("> Are you sure you want to quit?\n-Yes\n-No\n");
    printf("======================================\n");
    cyan("> Please enter your choice:\n");
    white();
    readAnswer(yesOrNo,sizeof(yesOrNo));
    while(strcmp(yesOrNo , yes) != 0 && strcmp(yesOrNo , no) != 0)
    {
        if(counter == 3)
        {
            red();
            printf("==================================================\n");
            printf("> Sorry, we didn't understand your choice.\n> Program is terminated after 3 wrong inputs!\n");
            printf("==================================================\n");
            white();
            exit(1);
        }
        yellow();
        printf("> Please enter:\nyes or no\n");
        white();
        readAnswer(yesOrNo,sizeof(yesOrNo));
        counter++;
    }
    if(!strcmp(yesOrNo,yes))
    {
        red();
        printf("======================================\n");
        printf("> Leaving the program...\n");
        printf("======================================\n");
        white();
        exit(1);
    }
    else if(!strcmp(yesOrNo,no))
    {   green();
        printf("======================================\n");
        printf("> Returning to the login menu...\n");
        printf("======================================\n");
        white();
        systemInterface();
        return;}
}
