#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argn,char **argv){
    char *fileName = argv[1];
    char buffer;
    int palabras=0;
    int lineas=0;
    int numChar=0;
    char espacio=0;

    int fd = open(fileName, O_RDONLY);
    if(fd < 0){
        printf("No se puede abrir \n");
        exit(1);
    }
    while(read (fd,&buffer,1) ){
        numChar++;
        if(buffer==10)  lineas++;
        if((buffer==32 || buffer == 10 || buffer == EOF) && espacio==0){
            espacio=1;
            palabras++;
        }else if(buffer != 32 && buffer != 10 &&  buffer != EOF){
            espacio=0;
        }
    }
    printf("%d ",lineas);
    printf("%d ",palabras);
    printf("%d",numChar);
    printf(" %s\n",fileName);
    
    close(fd);
    exit(0);
}
