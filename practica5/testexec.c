#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main( void ) {
	int pid = fork();

	if ( pid == 0 ) {
		execlp( "ls","ls", "-a","/",(char*)NULL); //Este comando reemplaza el código por completo
	}
	printf( "Soy el Padre\n" );

	return 0;
}