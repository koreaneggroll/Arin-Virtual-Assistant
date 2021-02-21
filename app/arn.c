//INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "commands.h"



//DATA

typedef struct{

    char name[25];
    char password[25];

}User;
typedef User usr;

usr user;


//PROTOTYPES
void prompt();
void evaluate(char *buffer);
void seetime();
void hello();
void setpsw();
void setname();
int stop();




int main(void){
    clear();
    prompt();
}



void evaluate(char *buffer){
    if(strcmp(buffer, TIME) == 0){
        seetime();
        prompt();
    }

    else if(strcmp(buffer, HELLO) == 0){
        hello();
        prompt();
    }

    else if(strcmp(buffer, SETPSW) == 0){
        setpsw();
        prompt();
    }

    else if(strcmp(buffer, SETNAME) == 0){
        setname();
        prompt();
    }

    else if(strcmp(buffer, STOP) == 0){
        stop();
        prompt();
    }

    else{
        printf("\nNo Instruction '%s'\n", buffer);
    }
}



//COMMAND FUNCTIONS

//prints out what time and date it is
void seetime(){
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    printf ( "Current local time and date: %s", asctime (timeinfo) );
}



void hello(){
    printf("Hello %s\n", user.name);
}



void setpsw(){
    char* pass = (char*)malloc(sizeof(char) * 25);


    if(pass == NULL){
        printf("\n\n\nERR: Couldn't allocate memory\n\n\n");
    }


    int ch;
    do{
        printf("\nNew Password: ");
        scanf("%s", pass);


        printf("new password is: %s\n", pass);

        printf("Set this as your password? (1 = y/0 = n): ");
        scanf("%d", &ch);
    }while(ch != 1);

    FILE* file;

    file = fopen("pass.txt", "w");


    if(file == NULL){
        printf("\n\n\nERR: Couldn't open file\n\n\n");
        exit(1);
    }


    fprintf(file, "%s", pass);

    fclose(file);
    free(pass);

}



void setname(){
    char* name = (char*)malloc(sizeof(char) * 25);

    if(name == NULL){
        printf("\n\n\nERR: Couldn't allocate memory\n\n\n");
        exit(1);
    }

    int ch;
    do{
        printf("\nWhat's your name? ");
        scanf("%s", name);

        printf("Your Name: %s\n", name);

        printf("Set this as your name? (1 = y/0 = n): ");
        scanf("%d", &ch);

    }while(ch != 1);

    FILE *file;

    file = fopen("name.txt", "w");


    if(file == NULL){
        printf("\n\n\nERR: Couldn't open file\n\n\n");
        exit(1);
    }


    fprintf(file, "%s", name);

    fclose(file);
    free(name);

}



int stop(){
    return 1;
}




void prompt(){

    char buffer[50];


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