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
void google();
void stackoverflow();
void wikipedia();
void editor();
void terminal();
void todo();
void skype();
void music();
void youtube();
void classroom();
void discord();
void github();
void notes();
void game();
//void stop();




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


    
    //welcome message
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



    else if(strcmp(buffer, GOOGLE) == 0){
        //calls the command
        google();
        //returns to the prompt
        prompt();
    }



    else if(strcmp(buffer, STACKOVERFLOW) == 0){
        //calls the command
        stackoverflow();
        //returns to the prompt
        prompt();
    }



    else if(strcmp(buffer, WIKIPEDIA) == 0){
        //calls the command
        wikipedia();
        //returns to the prompt
        prompt();
    }



    else if(strcmp(buffer, EDITOR) == 0){
        //calls the command
        editor();
        //returns to the prompt
        prompt();
    }



    else if(strcmp(buffer, TERMINAL) == 0){
        //calls the command
        terminal();
        //returns to the prompt
        prompt();
    }



    else if(strcmp(buffer, TODO) == 0){
        //calls the command
        todo();
        //returns to the prompt
        prompt();
    }



    else if(strcmp(buffer, SKYPE) == 0){
        //calls the command
        skype();
        //returns to the prompt
        prompt();
    }



    else if(strcmp(buffer, MUSIC) == 0){
        //calls the command
        music();
        //returns to the prompt
        prompt();
    }



    else if(strcmp(buffer, YOUTUBE) == 0){
        //calls the command
        youtube();
        //returns to the prompt
        prompt();
    }



    else if(strcmp(buffer, CLEAR) == 0){
        //calls the command
        clear();
        //returns to the prompt
        prompt();
    }



    else if(strcmp(buffer, SCHOOL) == 0){
        //calls the command
        classroom();
        //returns to the prompt
        prompt();
    }



    else if(strcmp(buffer, DISCORD) == 0){
        //calls the command
        discord();
        //returns to the prompt
        prompt();
    }



    else if(strcmp(buffer, GITHUB) == 0){
        //calls the command
        github();
        //returns to the prompt
        prompt();
    }



    else if(strcmp(buffer, NOTES) == 0){
        //calls the command
        notes();
        //returns to the prompt
        prompt();
    }



    else if(strcmp(buffer, GAME) == 0){
        //calls the command
        game();
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


        printf("\nnew password is: %s\n", pass);

        //Confirmation
        printf("\nSet this as your password? (1 = y/0 = n): ");
        scanf("%d", &ch);
        printf("\n");
    }while(ch != 1 && ch != 0);

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
        //prompt
        printf("\nWhat's your name? ");
        scanf("%s", name);

        printf("\nYour Name: %s\n", name);

        //asks for confirmation
        printf("\nSet this as your name? (1 = y/0 = n): ");
        scanf("%d", &ch);
        printf("\n");

    }while(ch != 1 && ch != 0);


    //create a file
    FILE *file;

    //open file
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



//sets an alarm
void reminder(){
    char *command = (char*)malloc(sizeof(char) * 15);
    char *title = (char*)malloc(sizeof(char) * 25);
    char *description = (char*)malloc(sizeof(char) * 50);

    if(command == NULL){
        printf("\n\n\nERR: Couldn't allocate memory\n\n\n");
        exit(1);
    }

    if(title == NULL){
        printf("\n\n\nERR: Couldn't allocate memory\n\n\n");
        exit(1);
    }

    /*if(description == NULL){
        printf("\n\n\nERR: Couldn't allocate memory\n\n\n");
        exit(1);
    }*/



    printf("\nNOTE: you have to keep the program running if you want the alarm to work\n");

    printf("\nTitle of the alarm: ");
    scanf("%s", title);

    //Waste value so we can use fgets after scanf
    //char c;
    //c = getc(stdin);

    sleep(1);

    //printf("\nDescription: ");
    //fgets(description, 50, stdin);

    strcpy(command, "notify-send ");
    strcat(title, " ");
    //strcat(title, description);
    strcat(command, title);

    printf("\n%s\n", command);


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

        system(command);
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
        
        system(command);
    }

    printf("\nSeconds from now: ");
    scanf("%d", &s);

    if(s > 60 || s < 0){
        printf("\n\n\nERR: Not a valid time\n\n\n");
        exit(1);
    }

    else{
        sleep(s);

        system(command);
    }

    free(command);
    free(title);
    free(description);

}



//opens google
void google(){
    //use your prefered browser
    //open the app
    system("brave https://google.com/");
    //close the terminal
    terminal();
}



//opens stackoverflow
void stackoverflow(){
    //use your prefered browser
    //open app
    system("brave https://stackoverflow.com/");
    //close the terminal
    terminal();
}



//opens wikipedia
void wikipedia(){
    //use your preffered browser
    //open the app
    system("brave https://wikipedia.com/");
    //close the terminal
    terminal();
}



//opens a text editor
void editor(){
    //use your preffered text editor
    //open the app
    system("code");
    //close the terminal
    terminal();
}



//opens a terminal
void terminal(){
    //use your preffered text editor
    system("yakuake");
}



//opens my todo app
void todo(){
    //use your preffered to do app
    system("todo");
}



//This function is for my use
void skype(){
    //open the app
    system("skype");
    //close the terminal
    terminal();
}



//opens spotify
void music(){
    //use your preffered streaming service
    //open the app
    system("spotify");
    //close the terminal
    terminal();
}



//opens youtube
void youtube(){
    //use your preffered browser
    //opens the app
    system("brave https://youtube.com");
    //close the terminal
    terminal();
}



//opens google classroom
//open another platform if you use something else
void classroom(){
    //open the app
    system("brave https://classroom.google.com/u/2/h");
    //close the terminal
    terminal();
}



//opens up discord using the terminal
void discord(){
    //open the app
    system("discord");
    //close the terminal
    terminal();
}



//opens up github desktop and my profile in my browser
void github(){
    //this only works if you got github desktop
    system("github");
    //you can change this to your own github page
    system("brave https://github.com/koreaneggroll");
    //close the terminal
    terminal();
}



//opens a note taking app
//use your preffered note taking app
void notes(){
    //open the app
    system("simplenote");
    //closes the terminal
    terminal();
}



//opens up steam for your gaming purposes :)
void game(){
    //open the app
    system("steam");
    //close the terminal
    terminal();
    //prompt();
}


//opens up a drawing app for your programming needs
void paint(){
    system("pinta");
    terminal();
}



//halts the program
//void stop(){
  //  exit(1);
//}



//PROMPTS

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

        //gets rid of some unused memory
        if(strcmp(buffer, STOP) == 0){
            free(buffer);
            exit(0);
        }

        //Calls a function to evaluate what it should do based on the buffer
        evaluate(buffer);
    }

    //frees some memory
    //free(buffer);

}