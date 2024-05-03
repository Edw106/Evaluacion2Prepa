#ifndef MESSAGE_H
#define MESSAGE_H
#include<stdlib.h>
#include <stdio.h>

typedef struct //Message contiene
{
    unsigned int size; //Un tamaño
    char* string; //Un string
} Message;







typedef struct //Logger contiene:
{
    Message** logs;
    //Un apuntador a un apuntador tipo message
	//(probablemente es un apuntador a un arreglo de message)
    
    unsigned int size;
    //un tamaño
    
}Logger;









// Let's warm up!
int potentiation(int, int);
char int_to_char(int);
void print_string(char*);

// Let's code!
int binary_to_int(char*);
void add_character(char*, unsigned int*, char);
void extract_string(char*, int, int, char*);



int add_to_log(Logger*, Message*);
void translate_message(char*, int, Logger*);

Logger* create_log();
void liberate_memory(Logger*);
#endif
