#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
 
int main( int argc, char* argv[] ) {
    int f[2];
    pid_t child;
 
    char readBuffer[50];
    char writeBuffer[50];
    int readCount;
 
    pipe( f);
 
    if( argc < 3 ) {
        printf( "Atleast need 2 parameters " );
        exit(1);
    }
 
    int fileOpen = open( argv[1], 0 );
    int targetFile = open( argv[2], 0666 );
     
    if ( fileOpen == -1 || targetFile == -1 ) {
        printf( "Opening file failed " );
        exit(1);
    }
    child = fork();
 
    if( child == 0 ) {
        
        close( f1] );
 
        read( f[0], readBuffer, sizeof( readBuffer ) );
        printf( "The recived string is : %s", readBuffer );
 
        
        write( targetFile, readBuffer, strlen( readBuffer ) + 1 );
    } else {
       
        close( f[0] );
        
 
        while( (readCount = read( fileOpen, readBuffer, sizeof( readBuffer) ) > 0 ) )  {
        write( f[1], readBuffer, sizeof( readBuffer ) );
        }
        close( f[1] );
    }
}


