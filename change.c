#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include "structs.h"
void setDayAndMonth(char*s){
    if(!strcmp(s,"1"))
    strcpy(s,"01");
    else if(!strcmp(s,"2"))
    strcpy(s,"02");
    else if(!strcmp(s,"3"))
    strcpy(s,"03");
    else if(!strcmp(s,"4"))
    strcpy(s,"04");
    else if(!strcmp(s,"5"))
    strcpy(s,"05");
    else if(!strcmp(s,"6"))
    strcpy(s,"06");
    else if(!strcmp(s,"7"))
    strcpy(s,"07");
    else if(!strcmp(s,"8"))
    strcpy(s,"08");
    else if(!strcmp(s,"9"))
    strcpy(s,"09");
}
void readAnswer(char yesOrNo[], int arraySize){
    fgets(yesOrNo, arraySize, stdin);
    yesOrNo[strcspn(yesOrNo, "\n")] = 0;
    for (int i = 0; yesOrNo[i] != '\0'; i++) {
        yesOrNo[i] = tolower(yesOrNo[i]);}
}
void tostring(char str[],int num){
    int i,rem,l=0,n=num;
    while(n != 0)
    {
        l++;
        n/=10;
    }
    for(i=0;i<l;i++)
    {
        rem= num%10;
        num= num/10;
        str[l-(i+1)]=rem+'0';
    }
    str[l]='\0';
}
int checkMonth(char *month,char *year){
    switch (atoi(month)){
    case 1: return 31;
    case 2:
        if(atoi(year)%4==0)
        return 29;
        return 28;
    case 3: return 31;
    case 4: return 30;
    case 5: return 31;
    case 6: return 30;
    case 7: return 31;
    case 8: return 31;
    case 9: return 30;
    case 10: return 31;
    case 11: return 30;
    case 12: return 31;
    }
}
void setName(char* s){
    s[0] = toupper(s[0]);
    for(int i=1;s[i]!='\0';i++)
    {
        if(s[i-1]==' ')
        s[i] = toupper(s[i]);
        else
        s[i] = tolower(s[i]);
    }
}
void sortDate(reservation_list *list,int line){
    reservation_list temp;
    int i,j;
    for(i=0;i<line-1;i++){
        for(j=0;j<line-i-1;j++){
            if(atoi(list[j].Date.year)>atoi(list[j+1].Date.year)){
                temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
            }else if(atoi(list[j].Date.year)==atoi(list[j+1].Date.year)){
                if(atoi(list[j].Date.month)>atoi(list[j+1].Date.month)){
                    temp=list[j];
                    list[j]=list[j+1];
                    list[j+1]=temp;
                }else if(atoi(list[j].Date.month)==atoi(list[j+1].Date.month)){
                    if(atoi(list[j].Date.day)>atoi(list[j+1].Date.day)){
                        temp=list[j];
                        list[j]=list[j+1];
                        list[j+1]=temp;
                    }
                }
            }
        }
    }
}
void updateRoomStatus(char *room_number,int mode){
    int n,flag=1;
    n = getlines("Room.txt");
    reservation_list *room =loadRoom(n);
    for (int i=0;i<n;i++) {
        if (strcmp(room[i].room_number0,room_number)==0)
            { flag=0;
            if (strcmp(room[i].room_status,"Available")==0&&mode==1) {
                strcpy(room[i].room_status, "Reserved");
                green();
                usleep(500000);
                printf("======================================\n");
                printf("> Room %s has been reserved\n",room_number);
                printf("======================================\n");
                white();
                    save(room,2,n);
                return;
            }
            else if (strcmp(room[i].room_status,"Reserved")==0&&mode==2) {
                strcpy(room[i].room_status,"Available");
                green();
                usleep(500000);
                printf("======================================\n");
                printf("> Room %s is now available\n",room_number);
                printf("======================================\n");
                if(flag)
                white();
                    save(room,2,n);
                return;
            }
        }
    }
    red();
    usleep(500000);
    if(flag)
    {printf("======================================\n");
    printf("Room number %s is not found.\n", room_number);
    printf("======================================\n");}
}
