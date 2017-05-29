#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char* argv[]){
    int i ;
    int count = 0;
    char serial[9] = "S123N456\n";
    if(strlen(argv[1]) < 8){
        printf("\nError---try again.\n\n");
		exit(0);
    }
    for(i = 0; i < 8; ++i){
        count += (argv[1][i] ^ serial[i]); //add to count if character mismatch
    }
    if(count  == 0){ //every character matches
        printf("\nSerial number is correct!\n\n");
    }
	else{
		printf("\nSerial number is incorrect.\n\n");
	}
}
