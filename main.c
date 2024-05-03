#include<stdio.h>
#include"message.h"


//Este será el main de prueba
int main()
{	
	Logger* logger = create_log();
	
	
	

	liberate_memory(logger);
	return 0;
}
