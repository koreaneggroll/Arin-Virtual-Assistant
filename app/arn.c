//INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <signal.h>
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
void reminder();
void ALARMhandler(int sig);
void stop();




int main(void){

    //READS FROM THE FILES TO SET THE PASSWORD OF THE USER
    FILE *file;
    //opens the file
    file = fopen("pass.txt", "rb");
    //Error handling
    if(file == NULL){
        printf("\n\n\nWARNING: No password set\n\n\n");
    }
    //if the file exists it reads it and stores the data in user.password
    else{
        fseek(file, SEEK_END, 0);
        ftell(file);
        rewind(file);
        fread(user.password, 25, 1, file);
        //closes the file
        fclose(file);
    }

    
    
    
    //READS FROM THE FILES TO SET THE NAME OF THE USER
    FILE *fp;
    //Opens the file
    fp = fopen("name.txt", "rb");
    //Error handling
    if(fp == NULL){
        //Gives a warning
        printf("\n\n\nWARNING: No name set\n\n\n");
    }
    //If the file exists it reads it and stores the data in user.name
    else{
        fseek(fp, SEEK_END, 0);
        ftell(fp);
        rewind(fp);
        fread(user.name, 25, 1, fp);
        //closes the file
        fclose(fp);
    }

    
    
    printf("\n\nHello there %s, i'm your virtual assistant %s\n\n", user.name, Vir_ass.name);

    //clear();
    prompt();
}



void evaluate(char *buffer){
    if(strcmp(buffer, TIME) == 0){
        //calls the command
        seetime();
        //returns to the prompt
        prompt();
    }

    else if(strcmp(buffer, HELLO) == 0){
        //calls the command
        hello();
        //returns to the prompt
        prompt();
    }

    else if(strcmp(buffer, SETPSW) == 0){
        //calls the command
        setpsw();
        //returns to the prompt
        prompt();
    }

    else if(strcmp(buffer, SETNAME) == 0){
        //calls the command
        setname();
        //returns to the prompt
        prompt();
    }

    else if(strcmp(buffer, REMINDER) == 0){
        //calls the command
        
        reminder();
        //returns to the prompt
        prompt();
    }

    else if(strcmp(buffer, STOP) == 0){
        //calls the command
        stop();
        //returns to the prompt
        prompt();
    }

    //If it goes through all the if statements we know that there isn't a command with that name
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
    printf("\nCurrent local time and date: %s\n", asctime (timeinfo));
}



//Responds with 'hello + username'
void hello(){
    printf("\nHello %s\n", user.name);
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

    //Frees some memory
    fclose(file);
    free(name);

}


void reminder(){

    printf("\nNOTE: you have to keep the program running if you want the alarm to work\n");

    int h, m, s;
    //prompts the user for when the alarm should go off
    printf("\nHours from now: ");
    scanf("%d", &h);

    if(h > 12 || h < 0){
        printf("\n\n\nERR: Not a valid time\n\n\n");
        exit(1);
    }
    //Starts alarm if everything went well
    else{
        int htos = h * 3600;//stands for hours to seconds
        sleep(htos);

        system("notify-send alarm");
    }

    printf("\nMinutes from now: ");
    scanf("%d", &m);

    //Checks if the time inputted is a valid time period
    if(m > 60 || h < 0){
        printf("\n\n\nERR: Not a valid time\n\n\n");
        exit(1);
    }
    //Starts alarm if everything went well
    else{
        int mtos = m * 60;//stands for minutes to seconds
        sleep(mtos);
        
        system("notify-send alarm");
    }

    printf("\nSeconds from now: ");
    scanf("%d", &s);

    if(s > 60 || s < 0){
        printf("\n\n\nERR: Not a valid time\n\n\n");
        exit(1);
    }

    else{
        sleep(s);

        system("notify-send alarm");
    }


}


//halts the program
void stop(){
    exit(1);
}



//Prompts the user for a command
void prompt(){

    char *buffer = (char*)malloc(sizeof(char) * 25);

    //Error handling
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

    //frees some memory
    free(buffer);

}