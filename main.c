#include<stdio.h>
#include"message.h"


//Este será el main de prueba
int main()
{	
	Logger* logger = create_log(); //Crea el logger que utilizaremos
	
	
	Message* prueba = (Message*)calloc(1, sizeof(Message)); //Por que Jaffar crea todo como tipo apuntador?? No entiendo pero bueno //Y luego usa ->
	
	//Message prueba = {8, "Esto es "};
	
	//~ prueba->size = 8;
	//~ prueba->string = "Esto es";
	//~ print_string(prueba->string);
	
	
	//~ add_character(prueba->string, &prueba->size, 'C');
	//~ print_string(prueba->string);
	
	char string[10];
	I

	liberate_memory(logger); //Libera la memoria que ocupaba el logger
	return 0;
}
