//INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>


//DEFINES
#define true 1
#define false 0
#define clear() printf("\e[1;1H\e[2J");


//DATA
typedef enum{
    Setpsw,
    Hello,
    Time,
    Exit,
}commands;


typedef struct{

    char name[25];

}User;
typedef User usr;

usr user;


//PROTOTYPES
void prompt();
void evaluate(char *buffer);




int main(void){
    prompt();
}



void evaluate(char *buffer){
    if(strcmp(buffer, Time)){
        //TODO
    }

    else if(strcmp(buffer, Hello)){
        //TODO
    }

    else if(strcmp(buffer, Setpsw)){
        //TODO
    }

    else if(strcmp(buffer, Exit)){
        //TODO
    }
}



//COMMAND FUNCTIONS

//prints out what time and date it is
void time(){

}



void hello(){

    if(user.name == NULL){
        printf("Hello there\n");
    }

    else{
        printf("Hello %s\n", user.name);
    }
}



void setpsw(){

}



void exit(){
    exit(0);
}




void prompt(){
    clear();

    char *buffer = (char*)malloc(sizeof(char) * 50);


    if(buffer == NULL){
        printf("\n\n\nERR: Couldn't allocate memory to 'buffer'\n\n\n");
        exit(1);
    }


    //Prompts the user for a command until the user writes 'exit'
    while(true){
        //Prompt
        printf("arn-virtual-assistant# ");
        //gets the input and stores it in buffer
        scanf("%s", buffer);
        //Calls a function to evaluate what it should do based on the buffer
        evaluate(buffer);
    }
}