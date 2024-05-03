#include<stdio.h>
#include"message.h"


//Este será el main de prueba
int main()
{	
	Logger* logger = create_log(); //Crea el logger que utilizaremos
	
	
	Message mensaje1 = {0};
	mensaje1.string = (char*)calloc(mensaje1.size, sizeof(char));
	
	

	liberate_memory(logger); //Libera la memoria que ocupaba el logger
	return 0;
}
