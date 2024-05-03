#include<stdio.h>
#include"message.h"


//Este será el main de prueba
int main()
{	
	Logger* logger = create_log(); //Crea el logger que utilizaremos
	
	Message prueba = {8, "Esto es "};
	
	
	add_character(prueba.string, &prueba.size, 'C');
	
	
	

	liberate_memory(logger); //Libera la memoria que ocupaba el logger
	return 0;
}
