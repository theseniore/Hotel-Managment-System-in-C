#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include "structs.h"
int numberValidation(char*s){
    for(int i=0;s[i]!='\0';i++)
    {
        if(!(s[i]>='0'&&s[i]<='9'))
            return 0;
    }
    return 1;
}
int mobileNumberValidation(char*s){
    int i;
    if(s[0]!='0'||s[1]!='1')
        return 0;
    if(s[2]!='0'&&s[2]!='1'&&s[2]!='2'&&s[2]!='5')
        return 0;
    for(i=3;s[i]!='\0';i++){
        if(s[i]<'0'||s[i]>'9')
        {
            return 0;
        }
    }
    if(!(i==11))
    return 0;
    return 1;
}
int reservationIdValidation(char*s){
    int i;
    for(i=0;s[i]!='\0';i++){
        if(s[i]<'0'||s[i]>'9')
        {
            return 0;
        }
    }
    if(!(i==6))
    return 0;
    return 1;
}
int roomNumberValidation(char*s){
    int i;
    for(i=0;s[i]!='\0';i++){
        if(s[i]<'0'||s[i]>'9')
        {
            return 0;
        }
    }
    if(!(i==4))
    return 0;
    return 1;
}
int idValidation(char* s){
    int i;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]<'0'||s[i]>'9')
           return 0;
    }
    if(i==14)
        return 1;
    else
        return 0;
}
int nameValidation(char* s){
if (s[0]=='\0')
    return 0;
if (s[0]==' '||s[strlen(s)-1]==' ')
    return 0;
    for(int i=0;s[i]!='\0';i++){
    if (s[i]==' '&&s[i+1]==' ')
    return 0;
    if (!((s[i]>='A'&&s[i]<='Z')||
              (s[i]>='a'&&s[i]<='z')||
              s[i]==' '))
            return 0;
    }
    return 1;
}
int emailValidation(char* email){
    int atCount=0,len=strlen(email);
    char *at=strchr(email,'@'),*dot=strrchr(email,'.');
    if(len==0||email[0]=='.'||email[0]=='@'||email[len-1]=='.'||!at||!dot||at>dot||dot-at<2||strlen(dot+1)<2)
        return 0;
    for(int i=0;i<len;i++){
        if(email[i]=='@')atCount++;
        if(strchr(" /:;<>,[]",email[i])||(email[i]=='.'&&email[i-1]=='.'))return 0;
    }
    return atCount==1;
}
