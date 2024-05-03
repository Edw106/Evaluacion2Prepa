//__________________________________
//______________message.h_______________
//__________________________________
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



















































//__________________________________
//______________MAIN_______________
//__________________________________
#include<stdio.h>
//#include"message.h"


//Este será el main de prueba
int main()
{        
        Logger* logger = create_log(); //Crea el logger que utilizaremos
        
        
        printf("Programa de la NASA para leer mensajes en binario\n");
        //Pedir cadena de caracteres binarios de 2 bytes, 16 bits
        printf("Introduzca en bits el tamaño de la cadena:\n");
        char tamanoenbinario[17]="hola como esta ud";
        
        
        //Es el num de bits leídos a continuación 
        // Convertir
        char parte1[9];
        char parte2[9];
        extract_string(tamanoenbinario, 1, 8, parte1);
        print_string(parte1);
        extract_string(tamanoenbinario, 9, 16, parte2);
        print_string(parte2);
        
        
        
        liberate_memory(logger); //Libera la memoria que ocupaba el logger
        return 0;
}






































































//__________________________________
//____________message.c_______________
//__________________________________



//#include<message.h>

// ----------------------------------------------------
// ------------------MIS FUNCIONES---------------------
// ----------------------------------------------------

// Let's warm up!
int potentiation(int base, int exp) //FUNCIONA CORRECTAMENTE
{
    int R = 1;
    for(int i = 1; i <= exp; i++)
    {
                R *= base;
        }
        return R;
}

char int_to_char(int number) //FUNCIONA CORRECTAMENTE
{
    return ((char)number);
}

void print_string(char* string) //FUNCIONA CORRECTAMENTE
{
    printf("%s", string);
}

// Let's code!
int binary_to_int(char* binary_string) //FUNCIONA CORRECTAMENTE
{
        int Resultado = 0;
        for(int i = 0; i < 8; i++)
        {
                char ch = binary_string[i];

                int dig = ch - 48;

                int _2alaN = potentiation(2, 7-i);

                Resultado += _2alaN * dig;
        }

        return Resultado;
}

void add_character(char* mssg_string, unsigned int* mssg_size, char letter) //????????????????????????????
{
        (*mssg_size)++;
        mssg_string = (char*)realloc(mssg_string, (*mssg_size) * sizeof(char));
        mssg_string[(*mssg_size)-1] = letter;
}

void extract_string(char* mssg_string, int initial_pos, int final_pos, char* buffer) //FUNCIONA CORRECTAMENTE
{
        initial_pos--; //Por ser array
        final_pos--;

        int pos = initial_pos;

        int i = 0;
    while(pos <= final_pos)
    {
                buffer[i] = mssg_string[pos];

                i++;
                pos ++;
        }
}















// ----------------------------------------------------
// ---------------FUNCIONES YA HECHAS------------------
// ----------------------------------------------------




// ¿QUÉ HACE ESA VAINA INTERNAMENTE?
Logger* create_log()
{
    Logger* new_logger = calloc(1, sizeof(Logger));
    // Crea un NUEVO VECTOR de LOGGER (de tam 1)

    new_logger->logs = NULL;
    // HACE QUE logs (un apuntador a un arreglo de message) apunte a NADA

    new_logger->size = 0;
    // Pone el tamaño en 0
    // ESTO SIGNIFICA que hay 0 mensajes en logs (??)

    return new_logger;
    //retorna el arreglo de logger (mejor dicho, su direccion)
}








// QUE HACE?
int add_to_log(Logger* logger, Message* message)
{
    logger->logs = (Message**)realloc(logger->logs,(logger->size + 1) * (sizeof(Message*)));
    logger->logs[logger->size] = message;
    logger->size += 1;
}

void translate_message(char* binary_string, int size, Logger* logger)
{
    int char_cant = (size/8);
    Message* message = (Message*)calloc(1, sizeof(Message));
    message->string = (char*)calloc(char_cant,sizeof(char));
    message->size = 0;

    char temp_buffer[9];

    for(int i = 0; i < char_cant; i++)
    {
        extract_string(binary_string, (8*i), ((8*i)-1), temp_buffer);
        int num = binary_to_int(temp_buffer);
        add_character(message->string, &message->size, int_to_char(num));
    }

    add_to_log(logger, message);

    print_string(message->string);
}

void liberate_memory(Logger* logger)
{
        //LIBERA LA MEMORIA :V

    for(int i = 0; i < logger->size; i++)
    {
        Message* temp_holder = logger->logs[i];
        logger->logs[i] = NULL;
        free(temp_holder->string);
        free(temp_holder);
        temp_holder = NULL;
    }

    free(logger);
    logger = NULL;
}