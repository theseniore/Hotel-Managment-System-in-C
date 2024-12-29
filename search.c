#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include "structs.h"
#include "color.h"
void viewCustomersDetails(){
    int i;
    int flag=0;
    int n = getlines("Reservation.txt");
reservation_list *reslist = loadRes(n);
char residORroomnum[MAX_SIZE];
yellow();
printf("======================================\n");
printf("View Customer Details\n");
printf("======================================\n");
cyan();
printf("> Enter the reservation id or room number:\n");
white();
scanf("%s",residORroomnum);
for ( i = 0; i < n; i++)
{
    if (strcmp(reslist[i].room_number,residORroomnum)==0||strcmp(reslist[i].reservation_id,residORroomnum)==0)
    {
        flag=1;
        break;
    }
}
if (flag)
{
    green();
    usleep(500000);
    printf("======================================\n");
    printf("- Reservation ID is: %s\n",reslist[i].reservation_id);
    printf("- Room number is: %s\n",reslist[i].room_number);
    printf("- Status is: %s\n",reslist[i].confirmation);
    printf("- Name is: %s\n",reslist[i].name);
    printf("- National Number is: %s\n",reslist[i].id);
    printf("- Number Of Nights is: %s\n",reslist[i].number_of_nights);
    printf("- Date is: %s-%s-%s\n",reslist[i].Date.day,reslist[i].Date.month,reslist[i].Date.year);
    printf("- Email: %s\n",reslist[i].email);
    printf("- Mobile Number: %s\n",reslist[i].mobile_number);
    printf("======================================\n");
    white();
    BackToMenuOrExit();
}
else {
    red();
    printf("> Invalid number or the room is not Reserved\n");
    white();
    BackToMenuOrExit();
}}
void query(){
char choose[MAX_SIZE];
int flag = 0;
int flag2=0;
yellow();
usleep(400000);
printf("======================================\n");
printf("QUERY/SEARCH MENU\n");
printf("======================================\n");
yellow();
printf("======================================\n");
printf("> Please enter your choice:\n");
printf("1. Search by customer name\n");
printf("2. Search by room number\n");
printf("3. Search by room status\n");
printf("======================================\n");
cyan();
printf("> Enter your choice:\n");
white();
scanf("%s",choose);
while(strcmp(choose,"1")&&strcmp(choose,"2")&&strcmp(choose,"3"))
{
    red();
    printf("> Invalid choice!\n");
    cyan();
    printf("> Enter a Valid choice:\n");
    white();
    scanf("%s",choose);
}
int i;
int z;
int n = getlines("Reservation.txt");
reservation_list *reslist = loadRes(n);
int k = getlines("Room.txt");
reservation_list *roomlist = loadRoom(k);
switch (atoi(choose))
{
case 1:{
getchar();
char name[MAX_SIZE];
cyan();
printf("> Enter customer name:\n");
white();
gets(name);
while(!nameValidation(name))
{
    red();
    printf("> The name format is wrong!\n");
    cyan();
    printf("> Enter a Valid name:\n");
    white();
    gets(name);
}
setName(name);
printf("\n");
    for ( i = 0; i < n; i++)
    {
        if (strcmp(name,reslist[i].name)==0)
        {
           flag=1;
           break;
        }

    }
    if (flag==1)
    {
        usleep(400000);
        green();
        printf("======================================\n");
        printf("- Reservation ID number is: %s\n",reslist[i].reservation_id);
        printf("- Room number is: %s\n",reslist[i].room_number);
        printf("- Name is: %s\n",reslist[i].name);
        printf("- National ID is: %s\n",reslist[i].id);
        printf("- Number of nights is: %s\n",reslist[i].number_of_nights);
        printf("- Date: %s-%s-%s\n",reslist[i].Date.day,reslist[i].Date.month,reslist[i].Date.year);
        printf("- Email is: %s\n",reslist[i].email);
        printf("- Mobile number is: %s\n",reslist[i].mobile_number);
        printf("======================================\n");
        white();
        BackToMenuOrExit();}
    else
    {
        red();
        usleep(500000);
        printf("======================================\n");
        printf("> No customer found!\n");
        printf("======================================\n");
        white();
        BackToMenuOrExit();
    }
    break;}
case 2: {
getchar();
char roomnum[MAX_SIZE];
while(1){
cyan();
printf("> Enter the room number: \n");
white();
scanf("%s",roomnum);
if(roomNumberValidation(roomnum))
    break;
red();
printf("> Invalid room number format!\n");
}
for ( i = 0; i < k; i++)
{
    if (strcmp(roomnum,roomlist[i].room_number0)==0)
    {
        flag=1;
        if (strcmp(roomlist[i].room_status,"Reserved")==0)
        {
            flag2=1;
        }
        break;
    }
}
if (flag)
{green();
usleep(500000);
printf("======================================\n");
printf("- Room number is: %s\n",roomnum);
printf("- Status is: %s\n",roomlist[i].room_status);
printf("- Room type is: %s\n",roomlist[i].room_category);
printf("- The price is: %s\n",roomlist[i].price_per_night);
printf("======================================\n");
white();
    if (flag2)
    {
       for (z = 0; z < n; z++)
       {
        if (strcmp(roomnum,reslist[z].room_number)==0)
        {
            break;
        }
       }
    green();
    usleep(500000);
    printf("======================================\n");
    printf("- Name is: %s\n",reslist[z].name);
    printf("- Reservation ID: %s\n",reslist[z].reservation_id);
    printf("======================================\n");
white();
BackToMenuOrExit();
}
}
else{
    usleep(500000);
    red();
    printf("> Room not found\n");
    white();
    BackToMenuOrExit();
};
BackToMenuOrExit();
   break;}
case 3: {
    usleep(400000);
    yellow();
    printf("======================================\n");
    printf("> What status do you want to search?\n");
    printf("1. Available\n");
    printf("2. Reserved\n");
    printf("======================================\n");
    cyan();
    printf("> Enter your choice:\n");
    char choose2[MAX_SIZE];
    white();
    scanf("%s",choose2);
    int stop=1;
    while(atoi(choose2)!=1&&atoi(choose2)!=2)
        {
            red();
            printf("> Invalid choose\n");
            cyan();
            printf("> Please enter a valid choice:\n");
            white();
            scanf("%s",choose2);
        }
if(stop){
    yellow();
    printf("%20s  %20s  %20s  %20s\n","Room Number","Room Status","Room Category","Price");
    white();
    usleep(500000);
    for ( i = 0; i < k; i++)
    {
        if (atoi(choose2)==1 && strcmp(roomlist[i].room_status,"Available")==0)
        {
            usleep(50000);
            green();
            printf("%20s  %20s  %20s  %20s",roomlist[i].room_number0,roomlist[i].room_status,roomlist[i].room_category,roomlist[i].price_per_night);
            printf("\n");
            white();
        }
        else if (atoi(choose2)==2&&strcmp(roomlist[i].room_status,"Reserved")==0)
        {
            usleep(50000);
         red();
            printf("%20s  %20s  %20s  %20s",roomlist[i].room_number0,roomlist[i].room_status,roomlist[i].room_category,roomlist[i].price_per_night);
            printf("\n");
            white();
        }
    }}}
    BackToMenuOrExit();
break;
}}
void report(){
        int n = getlines("Reservation.txt");
        reservation_list* list = loadRes(n);
        reservation_list L1;
        yellow();
        printf("======================================\n");
        printf("Reservation Report\n");
        printf("======================================\n");
       while(1){
            cyan();
            printf("> Enter date by year:\n");
            white();
            scanf("%s",L1.Date.year);
            if(atoi(L1.Date.year)>=2024&&atoi(L1.Date.year)<=2026)
            {
                break;
            }red();
            printf("> Invalid year try again!\n");
            white();
            }
        while (1)
        {
            cyan();
            printf("> Enter date by month:\n");
            white();
            scanf("%s",L1.Date.month);
            setDayAndMonth(L1.Date.month);
            if (atoi(L1.Date.month)<=12&&atoi(L1.Date.month)>=1)
            {
                break;
            }red();
            printf("> Invalid month!\n");
            white();
        }
        while (1)
        {
            cyan();
            printf("> Enter date by day:\n");
            white();
            scanf("%s",L1.Date.day);
            setDayAndMonth(L1.Date.day);
            if (atoi(L1.Date.day)<=checkMonth(L1.Date.month,L1.Date.year)&&atoi(L1.Date.day)>=1)
            {
                break;
            }red();
            printf("> Invalid day try again!\n");
            cyan();
        }
        int flag =0;
        for(int i=0;i<n;i++)
        {
            if((atoi(L1.Date.day)==atoi(list[i].Date.day))&&(atoi(L1.Date.month)==atoi(list[i].Date.month))&&(atoi(L1.Date.year)==atoi(list[i].Date.year)))
            {
                green();
                flag =1;
            usleep(700000);
            printf("======================================\n");
            printf("> Reservation Details on %s/%s/%s:\n",L1.Date.day,L1.Date.month,L1.Date.year);
            printf("- Reservation ID is : #%s\n",list[i].reservation_id);
            printf("- Room ID is: %s\n",list[i].room_number);
            printf("- The confirmation status is: %s\n", list[i].confirmation);
            printf("- Name is: %s\n", list[i].name);
            printf("- National ID is: %s\n", list[i].id);
            printf("- Number of nights is: %s\n", list[i].number_of_nights);
            printf("- the Email is: %s\n", list[i].email);
            printf("- the mobile number is: %s\n", list[i].mobile_number);
            printf("======================================\n");
            white();
            }
        }
        if(!flag)
        {
                red();
                printf("> No data for the specified date:\n");
                white();
                BackToMenuOrExit();
        }
        BackToMenuOrExit();
    }
void trackRoomAvailabitity(){
  int n=getlines("Room.txt");
reservation_list *roomlist=loadRoom(n);
int i;
yellow();
printf("======================================\n");
printf(" Tracking Rooms Availability\n");
printf("======================================\n");
printf("%s  %14s  %20s  %20s\n","Room Number","Room Status","Room Category","Price");
green();
for ( i = 0; i < n; i++)
    {
        if (!strcmp(roomlist[i].room_status,"Available"))
        {
            green();
            usleep(50000);
            printf("%s  %20s  %20s  %20s",roomlist[i].room_number0,roomlist[i].room_status,roomlist[i].room_category,roomlist[i].price_per_night);
            printf("\n");
            white();
        }
        else{
         red();
            printf("%s  %20s  %20s  %20s",roomlist[i].room_number0,roomlist[i].room_status,roomlist[i].room_category,roomlist[i].price_per_night);
            printf("\n");
            white();
        }
    }
    BackToMenuOrExit();
}
