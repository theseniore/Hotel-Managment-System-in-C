#ifndef SMALLCHANGE_H_INCLUDED
#define SMALLCHANGE_H_INCLUDED
void setDayAndMonth(char*s);
void readAnswer(char yesOrNo[], int arraySize);
void tostring(char str[], int num);
int checkMonth(char *month,char *year);
void setName(char* s);
void updateRoomStatus(char *room_number,int mode);
void sortDate(reservation_list *list,int line);
#endif // SMALLCHANGE_H_INCLUDED
