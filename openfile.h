#ifndef OPENFILE_H_INCLUDED
#define OPENFILE_H_INCLUDED
reservation_list *loadRoom(int noofres);
reservation_list *loadRes(int noofres);
int getlines(char* s);
void save(reservation_list *room,int mode,int line);
int login();
#endif // OPENFILE_H_INCLUDED
