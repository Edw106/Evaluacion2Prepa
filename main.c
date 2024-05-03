#include<stdio.h>
#include"message.h"


//Este será el main de prueba
int main()
{	
	Logger* logger = create_log(); //Crea el logger que utilizaremos
	
	
	Message prueba = {8, "Esto es "};
	print_string(prueba.string);
	
	
	//~ add_character(prueba.string, &(prueba.size), 'C');
	//~ print_string(prueba.string);
	


	liberate_memory(logger); //Libera la memoria que ocupaba el logger
	return 0;
}
