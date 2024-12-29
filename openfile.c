#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include "color.h"
#include "validation.h"
#include "structs.h"
#include "change.h"
#include "interface.h"







reservation_list *loadRoom(int noofroom){
 FILE *fPtr=fopen("Room.txt","r");
 if(fPtr==NULL)
{   red();
    printf("> There was an error in opening the file!\n");
    return NULL;
}
else
{
    int i=0;
    reservation_list *room=malloc(noofroom*sizeof(reservation_list));
    if(room==NULL){
            red();
        printf("> Can't Load the room list!\n");
        return NULL;}
    char x[noofroom][MAX_SIZE];
    while(fgets(x[i],MAX_SIZE, fPtr) != NULL)
{
 i++;
}
    for(i=0;i<noofroom;i++)
{
   sscanf(x[i],"%s %s %s %s",room[i].room_number0,room[i].room_status,room[i].room_category,room[i].price_per_night);
}
fclose(fPtr);
return room;
}
}
reservation_list *loadRes(int noofres){
 FILE *fReservation=fopen("Reservation.txt","r");
 if(fReservation==NULL)
{   red();
    printf("> There was an error in opening the file!\n");
    return NULL;
}
else
{
    int i=0;
    reservation_list *room=malloc(noofres*sizeof(reservation_list));
    if(room==NULL){
            red();
        printf("> Can't Load the reservation list!\n");
        return NULL;}
    char x[noofres][MAX_SIZE];
    while(fgets(x[i],MAX_SIZE,fReservation)!=NULL)
{
 i++;
}
    for(i=0;i<noofres;i++)
{
   sscanf(x[i],"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^-]-%[^-]-%[^,],%[^,],%s"
          ,room[i].reservation_id,room[i].room_number,room[i].confirmation,room[i].name,room[i].id,room[i].number_of_nights
          ,room[i].Date.day,room[i].Date.month
          ,room[i].Date.year,room[i].email,room[i].mobile_number);
}
fclose(fReservation);
return room;
}
}
int getlines(char* s){
    char buffer[MAX_SIZE];
    int line=0;
    FILE *f=fopen(s,"r");
    while(!feof(f))
        if(fgets(buffer,MAX_SIZE,f)!=NULL)
            line++;
            fclose(f);
            return line;
}
void save(reservation_list *room,int mode,int line){
    int i;
    if(mode==1)
    {
        sortDate(room,line);
        FILE *fReservation=fopen("Reservation.txt","w");
    for(i=0;i<line;i++)
    {
        if(room[i].reservation_id[0]!='\0')
            fprintf(fReservation,"%s,%s,%s,%s,%s,%s,%s-%s-%s,%s,%s\n",room[i].reservation_id,room[i].room_number,room[i].confirmation,room[i].name
                    ,room[i].id,room[i].number_of_nights,room[i].Date.day,room[i].Date.month
                    ,room[i].Date.year,room[i].email,room[i].mobile_number);
    }
        white();
    fclose(fReservation);
    }
    else if(mode==2)
   {
       FILE *fRoom=fopen("Room.txt","w");
    for(i=0;i<line;i++)
        fprintf(fRoom,"%s %s %s %s\n",room[i].room_number0,room[i].room_status,room[i].room_category,room[i].price_per_night);
        white();
        fclose(fRoom);
   }
}
int login(){
    FILE* fPtr = fopen("users.txt","r");
    if(fPtr==NULL)
    {
        red();
        printf("File didn't open!\n");
        white();
        BackToMenuOrExit();
    }else{
    int flag =0;
    users u1;
    char user_buffer[MAX_SIZE],pswd_buffer[MAX_SIZE];
    yellow();
    usleep(500000);
    printf("======================================\n");
    printf("Login\n");
    printf("======================================\n");
    cyan();
    printf("> Enter your username:\n");
    white();
    gets(u1.username);
    cyan();
    usleep(500000);
    printf("> Enter your password:\n");
    white();
    gets(u1.password);
    while(!feof(fPtr))
    {
        fscanf(fPtr,"%s %s\n",user_buffer,pswd_buffer);
        if(!strcmp(u1.password,pswd_buffer)&&!strcmp(u1.username,user_buffer))
        {
            flag = 1;
        }
        if(flag)
        {
            sleep(1);
            green();
            printf("=========================================\n");
            printf("> You entered to the system successfully!\n");
            printf("=========================================\n");
            usleep(500000);
            white();
            return 1;
        }
    }
    red();
    usleep(500000);
    fclose(fPtr);
    printf("> Your username or password is wrong!\n");
    white();
    return 0;
    }
}
