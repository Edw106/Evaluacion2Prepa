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
int potentiation(int base, int exp);
char int_to_char(int number);
void print_string(char* string);

// Let's code!
int binary_to_int(char* binary_string);
void add_character(char* mssg_string, unsigned int* mssg_size, char letter);
void extract_string(char* mssg_string, int initial_pos, int final_pos, char* buffer);




// Already coded :v

int add_to_log(Logger* logger, Message* message);
void translate_message(char* binary_string, int size, Logger* logger);

Logger* create_log();
void liberate_memory(Logger* logger);
#endif
