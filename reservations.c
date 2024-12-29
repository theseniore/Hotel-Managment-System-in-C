#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include "color.h"
#include "search.h"
#include "validation.h"
#include "structs.h"
#include "change.h"
#include "interface.h"
#include "openfile.h"

void editReservation(){
    int n=getlines("Reservation.txt"),freeroom=0;
    reservation_list *list=loadRes(n);
    int i;
    int flag=0;
    char ID_Roomcheck[MAX_SIZE];
    yellow();
    printf("======================================\n");
    printf("Edit Reservation\n");
    printf("======================================\n");
    while(1){
    cyan();
    printf("Enter your reservation ID or room number:\n");
    white();
    scanf("%s",ID_Roomcheck);
    if(reservationIdValidation(ID_Roomcheck)||roomNumberValidation(ID_Roomcheck))
        break;
    red();
    printf("> Invalid reservation ID/room number format!\n");
    }
    for (i = 0; i < n; i++)
    {
        if (!strcmp(ID_Roomcheck,list[i].reservation_id)||!strcmp(ID_Roomcheck,list[i].room_number)){
    flag=1;
    break;
        }
    }
    if (flag)
    {
        green();
        printf("======================================\n");
        printf("> Current Reservation Details is:\n");
        printf("- Name is: %s\n", list[i].name);
        printf("- Room Number is: %s\n", list[i].room_number);
        printf("- National Number is: %s\n", list[i].id);
        printf("- Email is: %s\n",list[i].email);
        printf("- Phone Number is: %s\n",list[i].mobile_number);
        printf("- Date is:%s-%s-%s\n",list[i].Date.day,list[i].Date.month,list[i].Date.year);
        printf("- Number of Nights is: %s\n",list[i].number_of_nights);
        printf("======================================\n");
        white();
    }
    else
    {
        red();
        usleep(500000);
        printf("\nReservation ID/Room number is not found\n");
        yellow();
        BackToMenuOrExit();
    }
    if (flag)
    {
        yellow();
        printf("======================================\n");
        printf("> What do you want to edit?\n");
        printf("1. Name\n");
        printf("2. Email\n");
        printf("3. Phone Number\n");
        printf("4. Date\n");
        printf("5. Number of Nights\n");
        printf("6. Room Category\n");
        printf("======================================\n");
        cyan();
        char choice[MAX_SIZE];
        printf("> Enter your choice:\n");
        white();
        scanf("%s",choice);
        while(strcmp(choice,"1")&&strcmp(choice,"2")&&strcmp(choice,"3")
              &&strcmp(choice,"4")&&strcmp(choice,"5")&&strcmp(choice,"6"))
        {
            red();
            printf("> Invalid choice!\n> Enter a valid choice:\n");
            white();
            scanf("%s",choice);
        }
        switch (atoi(choice))
        {
        case 1:
            cyan();
            printf("> Enter the new name:\n");
            white();
            getchar();
            gets(list[i].name);
            while(!(nameValidation(list[i].name)))
            {
            red();
            printf("> You entered wrong name format!\n");
            cyan();
            printf("> Please enter the name again!\n");
            white();
            gets(list[i].name);
            }
            setName(list[i].name);
            break;
        case 2:
            cyan();
            printf("> Enter the new email:\n");
            white();
            scanf("%s",list[i].email);
            while(!emailValidation(list[i].email))
            {
                red();
                printf("> Invalid email!\n");
                cyan();
                printf("> Please enter a valid email:\n");
                white();
                scanf("%s",list[i].email);
            }
            break;
        case 3:
            cyan();
            printf("> Enter the new Phone Number:\n");
            white();
            scanf("%s",list[i].mobile_number);
            while(!mobileNumberValidation(list[i].mobile_number))
            {
                red();
                printf("> Invalid Phone Number!\n");
                cyan();
                printf("> Please enter a valid Number:\n");
                white();
                scanf("%s",list[i].mobile_number);
            }
            break;
        case 4:
            while(1){
            cyan();
            printf("> Enter the new date by year:\n");
            white();
            scanf("%s",list[i].Date.year);
            if(atoi(list[i].Date.year)>=2024&&atoi(list[i].Date.year)<=2026)
            {
                break;
            }red();
            printf("> Invalid year try again!\n");
            }
        while (1)
        {
            cyan();
            printf("> Enter the new date by month:\n");
            white();
            scanf("%s",list[i].Date.month);
            setDayAndMonth(list[i].Date.month);
            if (atoi(list[i].Date.month)<=12&&atoi(list[i].Date.month)>=1)
            {
                break;
            }red();
            printf("> Invalid month!\n");
        }
        while (1)
        {
            cyan();
            printf("> Enter the new date by day:\n");
            white();
            scanf("%s",list[i].Date.day);
            setDayAndMonth(list[i].Date.day);
            if (atoi(list[i].Date.day)<=checkMonth(list[i].Date.month,list[i].Date.year)&&atoi(list[i].Date.day)>=1)
            {
                break;
            }red();
            printf("> Invalid day try again!\n");
        }
            break;
        case 5:
            cyan();
            printf("> Enter the new Number of Nights:\n");
            white();
            scanf("%s",list[i].number_of_nights);
            while(!(numberValidation(list[i].number_of_nights)))
            {
                red();
                printf("Invalid Number of nights!\n");
                cyan();
                printf("Please enter a valid number of nights:\n");
                white();
                scanf("%s",list[i].number_of_nights);
            }
            break;
        case 6:
                yellow();
    printf("======================================\n");
    printf("> Select Room Category:\n");
    printf("1. SeaView\n");
    printf("2. GardenView\n");
    printf("3. LakeView\n");
    printf("======================================\n");
    cyan();
    printf("> Enter your choice:\n");
    white();
    char RoomTypechose[MAX_SIZE];
    int j,n1= getlines("Room.txt");
    reservation_list *list1 = loadRoom(n1);
    scanf("%s",RoomTypechose);
    while(atoi(RoomTypechose)!=1&&atoi(RoomTypechose)!=2&&atoi(RoomTypechose)!=3)
    {
        red();
        printf("> Invalid Choice!\n");
        cyan();
        printf("> Enter your choice again:\n");
        white();
        scanf("%s",RoomTypechose);
    }
     if(atoi(RoomTypechose)==1)
    {
        strcpy(list[i].room_category,"SeaView");
    }
    else if(atoi(RoomTypechose)==2)
    {
        strcpy(list[i].room_category,"GardenView");
    }
    else if(atoi(RoomTypechose)==3)
    {
        strcpy(list[i].room_category,"LakeView");
    }
    for (j=0;j<n1;j++)
    {
        if (strcmp(list1[j].room_status,"Available")==0&&strcmp(list1[j].room_category,list[i].room_category)==0)
        {
            strcpy(ID_Roomcheck,list[i].room_number);
            strcpy(list[i].room_number,list1[j].room_number0);
            freeroom=1;
            break;
        }
    }
    if (freeroom)
    {
        green();
        usleep(500000);
        printf("======================================\n");
        printf("- Room found\n");
        printf("- The price is %s$\n",list1[j].price_per_night);
        printf("======================================\n");
        white();
         }
    else
    {
        red();
        usleep(500000);
        printf("======================================\n");
        printf("- There is no room available!\n");
        printf("======================================\n");
        white();
        free(list1);
        free(list);
        BackToMenuOrExit();
    }
        break;
        default:
            BackToMenuOrExit();
            }
yellow();
char choose[MAX_SIZE];
printf("======================================\n");
printf("> Do you want to save the changes?\n");
usleep(500000);
printf("1. Yes\n");
printf("2. No\n");
printf("======================================\n");
cyan();
printf("> Enter your choice:\n");
white();
scanf("%s",choose);
white();
while(atoi(choose)!=1&&atoi(choose)!=2)
{
        red();
        printf("> Invalid Choice!\n");
        cyan();
        usleep(500000);
        printf("> Enter your choice again:\n");
        scanf("%s",choose);
        white();
}
if (atoi(choose)==1)
{
    if(freeroom)
        {
            updateRoomStatus(list[i].room_number,1);
            updateRoomStatus(ID_Roomcheck,2);
        }
    save(list,1,n);
    green();
    printf("======================================\n");
    printf("> Changes saved successfully!\n");
    printf("======================================\n");
    BackToMenuOrExit();
    white();
}
else
    {red();
    printf("======================================\n");
    printf("> Nothing was saved!\n");
    printf("======================================\n");
    yellow();
    free(list);
    white();
    BackToMenuOrExit();
    }
}
}
void roomReservation(){
    int n=getlines("Room.txt");
    int m = getlines("Reservation.txt");
    int i;
    reservation_list *list=loadRoom(n);
    reservation_list *reservation=realloc(loadRes(m),(n+1)*sizeof(reservation_list));
    int freeroom=0;
    yellow();
    printf("======================================\n");
    printf("Room Reservation\n");
    printf("======================================\n");
    cyan();
    printf("> Enter Customer name:\n");
    getchar();
    white();
    gets(reservation[n].name);
    while(!nameValidation(reservation[n].name))
    {
        red();
        printf("> You entered wrong name format!\n");
        cyan();
        printf("> Please enter the name again!\n");
        white();
        gets(reservation[n].name);
    }
    setName(reservation[n].name);
    cyan();
    printf("> Enter National Number:\n");
    white();
    scanf("%s", reservation[n].id);
        while(!idValidation(reservation[n].id))
    {
        red();
        printf("> You entered wrong ID format!\n");
        cyan();
        printf("> Please enter the ID again!\n");
        white();
        scanf("%s",reservation[n].id);
    }
    cyan();
    printf("> Enter email:\n");
    white();
    scanf("%s",reservation[n].email);
    while(!emailValidation(reservation[n].email))
    {
        red();
        printf("> You entered wrong email format!\n");
        cyan();
        printf("> Please enter the email again!\n");
        white();
        scanf("%s",reservation[n].email);
    }
    cyan();
    printf("> Enter Phone Number:\n");
    white();
    scanf("%s", reservation[n].mobile_number);
     while(!mobileNumberValidation(reservation[n].mobile_number))
            {
                red();
                printf("> Please enter a valid Number:\n");
                white();
                scanf("%s", reservation[n].mobile_number);
            }
    cyan();
    printf("> Enter check-in year:\n");
    white();
    scanf("%s", reservation[n].Date.year);
    while((atoi(reservation[n].Date.year)<2024)||(atoi(reservation[n].Date.year)>2026))
    {
        red();
        printf("> Invalid year!\n");
        cyan();
        printf("> Please enter a valid year:\n");
        white();
        scanf("%s", reservation[n].Date.year);
    }
    while(1){
    cyan();
    printf("> Enter check-in month:\n");
    white();
    scanf("%s", reservation[n].Date.month);
    setDayAndMonth(reservation[n].Date.month);
    if (atoi(reservation[n].Date.month)<=12&&atoi(reservation[n].Date.month)>=1)
    {
        break;
    }
    red();
    printf("> Invalid month enter again\n");
    }
    while(1){
    cyan();
    printf("> Enter check-in day:\n");
    white();
    scanf("%s", reservation[n].Date.day);
    setDayAndMonth(reservation[n].Date.day);
    if (atoi(reservation[n].Date.day)>=1&&atoi(reservation[n].Date.day)<=checkMonth(reservation[n].Date.month,reservation[n].Date.year))
    {
        break;
    }
    red();
    printf("> Invalid day!\nEnter again\n");
    white();
    }
    cyan();
    printf("> Enter Number of Nights:\n");
    white();
    scanf("%s", reservation[n].number_of_nights);
    printf("\n");
    while((!numberValidation(reservation[n].number_of_nights))||(atoi(reservation[n].number_of_nights)<=0))
    {
        red();
        printf("> Invalid number of nights!\n");
        cyan();
        printf("> Please enter a valid number of nights:\n");
        scanf("%s", reservation[n].number_of_nights);
    }
    yellow();
    printf("======================================\n");
    printf("> Select Room Category:\n");
    printf("1. SeaView\n");
    printf("2. GardenView\n");
    printf("3. LakeView\n");
    printf("======================================\n");
    cyan();
    printf("> Enter your choice:\n");
    white();
    char RoomTypechose[MAX_SIZE];
    scanf("%s",RoomTypechose);
    while(strcmp(RoomTypechose,"1")&&strcmp(RoomTypechose,"2")&&strcmp(RoomTypechose,"3"))
    {
        red();
        printf("Invalid room type!\nPlease Enter a valid room type:\n");
        white();
        scanf("%s",RoomTypechose);
    }
    if(atoi(RoomTypechose)==1)
    {
        strcpy(reservation[n].room_category,"SeaView");
    }
    else if(atoi(RoomTypechose)==2)
    {
        strcpy(reservation[n].room_category,"GardenView");
    }
    else if(atoi(RoomTypechose)==3)
    {
        strcpy(reservation[n].room_category,"LakeView");
    }
    for(i=0;i<n;i++)
    {
        if(strcmp(list[i].room_status,"Available")==0&&strcmp(list[i].room_category,reservation[n].room_category)==0)
        {
            strcpy(reservation[n].room_number,list[i].room_number0);
            strcpy(reservation[n].confirmation,"unconfirmed");
            freeroom=1;
            break;
        }
    }
    if (freeroom)
    {
        int ran=0;
        srand(time(NULL));
        char buffer[MAX_SIZE];
        do{
                ran=0;
        tostring(buffer,rand()%899999+100000);
        for(int k=0;k<m;k++){
            if(!strcmp(buffer,reservation[k].reservation_id))
            {
                ran=1;
                break;
            }
        }
        strcpy(reservation[n].reservation_id,buffer);
        }while(ran);
        green();
        usleep(500000);
        printf("======================================\n");
        printf("> Room found\n");
        usleep(500000);
        printf("- The price is %s$ per night\n",list[i].price_per_night);
        printf("- Room number is %s\n",list[i].room_number0);
        printf("- Your Reservation ID is #%s\n",reservation[n].reservation_id);
        printf("======================================\n");
        white();
        yellow();
        printf("======================================\n");
        printf("> Do you want to save this Reservation?\n");
        usleep(500000);
        printf("1. yes\n");
        printf("2. no\n");
        printf("======================================\n");
        char choose[MAX_SIZE];
        while(1)
        {cyan();
        printf("> Please enter your choice:\n");
        white();
        scanf("%s",choose);
        if(atoi(choose)==1||atoi(choose)==2)
            break;
        red();
        printf("> Invalid Choice!\n");}
        white();
        if (atoi(choose)==1)
        {
        updateRoomStatus(reservation[n].room_number,1);
        save(reservation,1,n+1);
        green();
        printf("======================================\n");
        printf("> Reservation is done!\n");
        printf("======================================\n");
        white();
        }
    else
    {
        red();
       printf("======================================\n");
       printf("Nothing was Saved!\n");
       printf("======================================\n");
       white();
    }
    }
    else
    {
        red();
        printf("======================================\n");
        printf("> There is no room available!\n");
        printf("======================================\n");
        white();
    }
    free(reservation);
    free(list);
    BackToMenuOrExit();
}
void checkOut(){
    int n = getlines("Reservation.txt");
    reservation_list* list = loadRes(n);
    reservation_list L1;
    int m = getlines("Room.txt");
    reservation_list* list_room = loadRoom(m);
    yellow();
    printf("======================================\n");
    printf("Check-out\n");
    printf("======================================\n");
    cyan();
    printf("> Enter the room number:\n");
    white();
    scanf("%s",L1.room_number);
    int flag =0;
    int i;
    for(i=0;i<n;i++)
    {
        if(!strcmp(L1.room_number,list[i].room_number)){
                if(!strcmp(list[i].confirmation,"unconfirmed"))
                {
                    red();
                    usleep(500000);
                    printf("> Reservation is unconfirmed!\nCannot checkout!\n");
                    white();
                    BackToMenuOrExit();
                }
            flag = 1;
            strcpy(L1.number_of_nights,list[i].number_of_nights);
            strcpy(L1.Date.day,list[i].Date.day);
            strcpy(L1.Date.month,list[i].Date.month);
            strcpy(L1.Date.year,list[i].Date.year);
            break;
        }
    }
        if(!flag)
    {
        red();
        printf("> Room number not found!\n");
        white();
        BackToMenuOrExit();
    }
    int found=0;
    int j;
    for(j=0;j<m;j++)
    {
        if(!strcmp(L1.room_number,list_room[j].room_number0)){
        strcpy(L1.price_per_night,list_room[j].price_per_night);
        found = 1;
        break;
        }
    }
    if(!found)
    {
        red();
        printf("> No price was found to check out!\n");
        white();
        BackToMenuOrExit();
    }
    if(found&&flag)
    {
        long long total_bill;
        total_bill = atoll(L1.number_of_nights)*atoll(L1.price_per_night);
        green();
        usleep(500000);
        printf("> The total price to check out is %lld$\n",total_bill);
        white();
        char buffer[1000];
        yellow();
        printf("======================================\n");
        printf("> Do you want to save your changes?\n");
        usleep(500000);
        printf("1.Yes\n2.No\n");
        printf("======================================\n");
        cyan();
        printf("> Enter your choice:\n");
        white();
        scanf("%s",buffer);
        while(strcmp(buffer,"1")!=0&&strcmp(buffer,"2")!=0)
        {
            red();
            printf("> Invalid Choice!\n");
            cyan();
            printf("> Enter a Valid choice:\n");
            scanf("%s",buffer);

        }
        if(!strcmp(buffer,"2"))
        {
            red();
            printf("> Your check-out won't be saved\n");
            white();
        BackToMenuOrExit();
        }
        updateRoomStatus(L1.room_number,2);
        list[i].reservation_id[0] = '\0';
        save(list,1,n);
        free(list);
        free(list_room);
        BackToMenuOrExit();
    }
}
void cancelReservation(){
    int n=getlines("Reservation.txt"),i,flag=0;
    reservation_list *list=loadRes(n);
    char user[MAX_SIZE],room_number[MAX_SIZE],choice[MAX_SIZE];
    red();
    usleep(500000);
    printf("======================================\n");
    printf("Cancel Reservation Menu\n");
    printf("======================================\n");
    yellow();
    printf("======================================\n");
    printf("1.Cancel by Reservation ID\n");
    printf("2.Cancel by Room Number\n");
    printf("3.Back or Quit\n");
    printf("======================================\n");
    cyan();
    printf("> Please enter your choice:\n");
    white();
    scanf("%s",choice);
    white();
    while((strcmp(choice,"1"))&&(strcmp(choice,"2"))&&(strcmp(choice,"3")))
    {
        red();
        printf("> Invalid Choice!\n");
        cyan();
        printf("> Please enter your choice again:\n");
        scanf("%s",choice);
        white();
    }
if(!(strcmp(choice,"1")))
{
    while(1){
    cyan();
    printf("> Please enter Reservation ID:\n");
    white();
    scanf("%s",user);
    if(reservationIdValidation(user))
    {
        break;
    }
    red();
    printf("> Invalid reservation ID format!\n");
    }
    flag=1;
    for(i=0;i<n;i++)
        if(!strcmp(user,list[i].reservation_id))
           {
             flag=0;
             break;
           }
}
else if(!(strcmp(choice,"2")))
{
    while(1){
    cyan();
    printf("> Please enter room number:\n");
    white();
    scanf("%s",user);
    if(roomNumberValidation(user))
    {
        break;
    }
    red();
    printf("> Invalid room number format!\n");
    }
    flag=2;
    for(i=0;i<n;i++)
        if(!strcmp(user,list[i].room_number))
        {
            flag=0;
            break;
        }
}
else
{
    free(list);
    BackToMenuOrExit();
}
if(flag==1)
    {
        red();
        printf("> Reservation ID was not found!\n");
        white();
        free(list);
        BackToMenuOrExit();
    }
else if(flag==2)
{
        red();
        printf("> Room Number does not exist!\n");
        white();
        free(list);
        BackToMenuOrExit();
}
if(!strcmp(list[i].confirmation,"confirmed"))
{
    red();
    printf("> Can't cancel reservation because it is already confirmed!\n");
    white();
    free(list);
    BackToMenuOrExit();
}
else
{
    strcpy(room_number,list[i].room_number);
    list[i].reservation_id[0]='\0';
}
yellow();
printf("======================================\n");
printf("> Are you sure you want to save?\n");
printf("1.Yes\n");
printf("2.No\n");
printf("======================================\n");
cyan();
printf("> Please enter your choice:\n");
white();
scanf("%s",choice);
 while((strcmp(choice,"1"))&&(strcmp(choice,"2")))
    {
        red();
        printf("Invalid Choice!\n");
        cyan();
        printf("Please enter your choice again:/n");
        white();
        scanf("%s",choice);
    }
if(!(strcmp(choice,"1")))
{
    updateRoomStatus(list[i].room_number,2);
    save(list,1,n);
    green();
    printf("======================================\n");
    printf("> Saved Successfully!\n");
    printf("======================================\n");
    white();
}
else
{
    red();
    printf("======================================\n");
    printf("> Nothing was saved!\n");
    printf("======================================\n");
    white();
}
    free(list);
    BackToMenuOrExit();
}
void checkIn(){
    int n = getlines("Reservation.txt");
    reservation_list* list = loadRes(n);
    reservation_list L1;
    yellow();
    printf("======================================\n");
    printf("Check-in\n");
    printf("======================================\n");
    cyan();
    while(1)
    {cyan();
    printf("> Enter the reservation ID:\n");
    white();
    scanf("%s", L1.reservation_id);
    if(reservationIdValidation(L1.reservation_id))
    break;
    red();
    printf("Invalid ID format!\n");}
    while(1)
    {cyan();
    printf("> Enter the room number:\n");
    white();
    scanf("%s", L1.room_number);
    if(roomNumberValidation(L1.room_number))
        break;
    red();
     printf("Invalid room number format!\n");}
    getchar();
    while(1)
    {cyan();
    printf("> Enter your name:\n");
    white();
    gets(L1.name);
    if(nameValidation(L1.name))
        break;
    red();
    printf("Invalid Name format!\n");}
    setName(L1.name);
    while(1)
    {cyan();
    printf("> Enter the national ID:\n");
    white();
    scanf("%s", L1.id);
    if(idValidation(L1.id))
        break;
    red();
    printf("Invalid national ID format!\n");}
    while(1)
    {cyan();
    printf("> Enter the number of nights:\n");
    white();
    scanf("%s", L1.number_of_nights);
    if(numberValidation(L1.number_of_nights))
        break;
    red();
    printf("Invalid number of nights!\n");}
    while(1)
    {cyan();
    printf("> Enter the date as years:\n");
    white();
    scanf("%s", L1.Date.year);
    if(atoi(L1.Date.year)>=2024&&atoi(L1.Date.year)<=2026)
        break;
    red();
    printf("Invalid Year!\n");}
    while(1)
    {cyan();
    printf("Enter the date as months:\n");
    white();
    scanf("%s", L1.Date.month);
    if(atoi(L1.Date.month)>=1&&atoi(L1.Date.month)<=12)
        break;
    red();
    printf("Invalid Month!\n");}
    setDayAndMonth(L1.Date.month);
    while(1){
    cyan();
    printf("> Enter the date as days:\n");
    white();
    scanf("%s", L1.Date.day);
    if(L1.Date.day>=1&&atoi(L1.Date.day)<=checkMonth(L1.Date.month,L1.Date.year))
        break;
    red();
    printf("Invalid Day!\n");}
    setDayAndMonth(L1.Date.day);
    getchar();
    while(1)
    {cyan();
    printf("> Enter the email :\n");
    white();
    gets(L1.email);
    if(emailValidation(L1.email))
        break;
    red();
    printf("Invalid Email!\n");}
    while(1)
    {cyan();
    printf("> Enter the phone number :\n");
    white();
    scanf("%s",L1.mobile_number);
    if(mobileNumberValidation(L1.mobile_number))
        break;
    red();
    printf("> Invalid Phone Number!\n");}
    int flag =0,i;
    for(i=0; i<n; i++)
    {
        if(!strcmp(L1.reservation_id, list[i].reservation_id)&&!strcmp(L1.room_number, list[i].room_number)&&
           !strcmp(L1.name, list[i].name)&&!strcmp(L1.id, list[i].id)&&
           !strcmp(L1.number_of_nights, list[i].number_of_nights)&&!strcmp(L1.email, list[i].email)
           &&!strcmp(L1.mobile_number, list[i].mobile_number))
        {
         int L1_year = atoi(L1.Date.year);
         int L1_month = atoi(L1.Date.month);
         int L1_day = atoi(L1.Date.day);
         int list_year = atoi(list[i].Date.year);
         int list_month = atoi(list[i].Date.month);
         int list_day = atoi(list[i].Date.day);
         if (L1_year < list_year ||
            (L1_year == list_year && L1_month < list_month) ||
            (L1_year == list_year && L1_month == list_month && L1_day <= list_day))
            {
               flag = 1;
               break;
            }
        }
    }
    if(flag)
    {
        char buffer[1000];
        yellow();
        printf("======================================\n");
        printf("> Do you want to confirm the reservation?\n");
        printf("1.Yes\n2.No\n");
        printf("======================================\n");
        cyan();
        printf("> Enter your choice:\n");
        white();
        scanf("%s",buffer);
        while(strcmp(buffer,"1")&&strcmp(buffer,"2"))
        {
        red();
        printf("> You entered invalid choice!\n");
        cyan();
        printf("> Please enter a valid choice:\n");
        white();
        scanf("%s",buffer);
        }
        if(!strcmp(buffer,"1"))
        {
            int flag1=0;
                if(!strcmp(list[i].confirmation,"unconfirmed"))
                {
                    strcpy(list[i].confirmation,"confirmed");
                    green();
                    printf("======================================\n");
                    printf("> Your reservation is verified successfully!\n");
                    printf("======================================\n");
                    white();
                    yellow();
                     printf("======================================\n");
                    printf("> Do you want to save?\n");
                    printf("1.Yes\n2.No\n");
                    printf("======================================\n");
                    char choice[MAX_SIZE];
                    cyan();
                    printf("> Please enter your choice:\n");
                    white();
                    scanf("%s",choice);
                    while(strcmp(choice,"1")&&strcmp(choice,"2"))
                    {
                        red();
                        printf("> Your input is invalid!\n");
                        cyan();
                        printf("> Please enter a valid choice:\n");
                        white();
                        scanf("%s",choice);
                    }
                    if(!strcmp(choice,"1"))
                    {
                        updateRoomStatus(L1.room_number,1);
                        save(list,1,n);
                        green();
                        printf("> All data is saved successfully!\n");
                        white();
                        BackToMenuOrExit();
                    }
                    else if(!strcmp(choice,"2"))
                    {
                        red();
                        printf("> Your data was not saved!\n");
                        white();
                        BackToMenuOrExit();
                    }
                    flag1 = 1;
                }
            if(!flag1)
            {
            red();
            printf("> Your Reservation is already confirmed!");
            white();
            BackToMenuOrExit();
            }
        }
        else if(!strcmp(buffer,"2"))
        {
            red();
            printf("> Your reservation has declined!\n");
            white();
            BackToMenuOrExit();
        }
    }
    else
    {
        red();
        printf("> Your data is invalid!\n");
        white();
        BackToMenuOrExit();
    }
}
