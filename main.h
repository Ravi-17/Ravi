 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 2

typedef struct{
unsigned int mod_no;
char oem[10];
unsigned int display;
unsigned int battery;
unsigned int RAM;
unsigned int ROM;
unsigned int camera;
double price;
}mobile;


void readAll(mobile*,int);
void readOne(mobile*);
void displayAll(const mobile*,int);
void displayOne(const mobile*);


void search_by_mod_no(const mobile*, const int*,int);
double avg_price(const mobile*,int);
void min_RAM(const mobile*,int);
void min_storage(const mobile*,int);
