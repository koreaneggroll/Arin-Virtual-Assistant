//INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


//DEFINES
#define true 1
#define false 0
#define clear() printf("\e[1;1H\e[2J");


//DATA
typedef enum{
    SETPSW,
    HELLO,
    TIME,
    EXIT,
}commands;


//PROTOTYPES
void prompt();




int main(void){
    prompt();
}



void prompt(){
    clear();

    char *buffer = (char*)malloc(sizeof(char) * 50);

    while(true){
        printf("arn-virtual-assistant# ");
        scanf("%s", buffer);
    }
}