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


typedef struct{

    char name[25];

}Virtual_Assistant;
typedef Virtual_Assistant vs;

vs Vir_ass = {"Arn"};




//PROTOTYPES
void prompt();
void evaluate(char *buffer);
void seetime();
void hello();
void setpsw();
void setname();
void stop();




int main(void){

    //READS FROM THE FILES TO SET THE PASSWORD OF THE USER
    FILE *file;

    file = fopen("pass.txt", "rb");

    if(file == NULL){
        printf("\n\n\nWARNING: No password set\n\n\n");
    }
    
    else{
        fseek(file, SEEK_END, 0);
        ftell(file);
        rewind(file);
        fread(user.password, 25, 1, file);
        fclose(file);
    }

    
    
    
        //READS FROM THE FILES TO SET THE NAME OF THE USER
    FILE *fp;

    fp = fopen("name.txt", "rb");

    if(fp == NULL){
        printf("\n\n\nWARNING: No name set\n\n\n");
    }
    
    else{
        fseek(fp, SEEK_END, 0);
        ftell(fp);
        rewind(fp);
        fread(user.name, 25, 1, fp);
        fclose(fp);
    }

    
    
    printf("\n\nHello there %s, i'm your virtual assistant %s\n\n", user.name, Vir_ass.name);

    //clear();
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



//Responds with 'hello + username'
void hello(){
    printf("Hello %s\n", user.name);
}



//Sets the password for the user
void setpsw(){
    char* pass = (char*)malloc(sizeof(char) * 25);


    //Error handling
    if(pass == NULL){
        printf("\n\n\nERR: Couldn't allocate memory\n\n\n");
    }


    int ch;
    do{
        //prompt
        printf("\nNew Password: ");
        //get input
        scanf("%s", pass);


        printf("new password is: %s\n", pass);

        //Confirmation
        printf("Set this as your password? (1 = y/0 = n): ");
        scanf("%d", &ch);
    }while(ch != 1);

    //Create a file
    FILE* file;
    //Open the file
    file = fopen("pass.txt", "w");


    //Error handling
    if(file == NULL){
        printf("\n\n\nERR: Couldn't open file\n\n\n");
        exit(1);
    }

    //Write the password inside the file
    fprintf(file, "%s", pass);
    
    //Closes the file
    fclose(file);
    //frees the memory inside the 'pass' variable
    free(pass);

}



//Sets the name for the user
void setname(){
    char* name = (char*)malloc(sizeof(char) * 25);


    //Error handling
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


    //Error handling
    if(file == NULL){
        printf("\n\n\nERR: Couldn't open file\n\n\n");
        exit(1);
    }


    fprintf(file, "%s", name);

    fclose(file);
    free(name);

}



void stop(){
    exit(1);
}



//Prompts the user for a command
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