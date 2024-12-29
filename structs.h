#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
#define MAX_SIZE 1000
typedef struct{
    char username[MAX_SIZE];
    char password[MAX_SIZE];
} users;
typedef struct{
    char reservation_id[MAX_SIZE];
    char room_number[MAX_SIZE];
    char room_number0[MAX_SIZE];
    char confirmation[MAX_SIZE];
    char number_of_nights[MAX_SIZE];
    char name[MAX_SIZE];
    char id[MAX_SIZE];
    char email[MAX_SIZE];
    char mobile_number[MAX_SIZE];
    struct {
    char year[MAX_SIZE];
    char month[MAX_SIZE];
    char day[MAX_SIZE];
    } Date;
    char room_status[MAX_SIZE];
    char room_category[MAX_SIZE];
    char price_per_night[MAX_SIZE];
    char date1[MAX_SIZE];
} reservation_list;

#endif // STRUCTS_H_INCLUDED
