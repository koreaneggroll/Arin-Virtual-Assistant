//INCLUDES
#include <iostream>
#include <time.h>
#include "../includes/commands.h"
#include <fstream>
#include <stdlib.h>
#include <unistd.h>


using namespace std;



//DATA


class User{
    private:
        string name;
        string password;
    public:
        //setters
        void setName(string nm);
        void setPass(string ps);
        //getters
        string getName();
        string getPass();
};
typedef User usr;

usr user;



class Virtual_Assistant{
    private:
        string name;
        usr customer;
    public:
        //setters
        void setName(string nm);
        void setCustomer(string nm, string pass);
        
        //getters
        string getName();
        string getCustomer();

        //evaluate function
        void evaluate(string buffer);

        //actual functions
        void hello();
        void seetime();
        void setPsw();
        void setUserName();
        void reminder();
        void google();
        void youtube();
        void stackoverflow();
        void wikipedia();
        void terminal();
        void editor();
        void todo();
        void skype();
        void music();
        void school();
        void discord();
        void github();
        void notes();
        void game();
        void paint();
        void math();
        void writer();
        void impress();
        void whatsapp();
        void startup();
        void ulauncher();
        void temperature();
        void day();
        friend void prompt();

};
typedef Virtual_Assistant vs;

vs Vir_ass;


//DATA END



//FUNCTION PROTOTYPES START
void prompt();
//FUNCTION PROTOTYPES END


int main(void){
    Vir_ass.setName("Arn");




    prompt();
}



//FUNCTIONS USER START
void User::setName(string nm){
    name = nm;
}

void User::setPass(string ps){
    password = ps;
}

string User::getName(){
    return name;
}

string User::getPass(){
    return password;
}
//FUNCTION USER END




//FUNCTIONS VIRTUAL ASSISTANT START
//SETTERS START
void Virtual_Assistant::setName(string nm){
    name = nm;
}


void Virtual_Assistant::setCustomer(string nm, string pass){
    customer.setName(nm);
    customer.setPass(pass);
}
//SETTERS END





//GETTERS START
string Virtual_Assistant::getName(){
    return name;
}


string Virtual_Assistant::getCustomer(){
    return customer.getName();
}

//GETTERS END


void Virtual_Assistant::evaluate(string buffer){

    if(buffer == "hello"){
        Vir_ass.hello();
        prompt();
    }

    else if(buffer == "time"){
        Vir_ass.seetime();
        prompt();
    }

    else if(buffer == "setpsw"){
        Vir_ass.setPsw();
        prompt();
    }
    
    else if(buffer == "reminder"){
        Vir_ass.reminder();
        prompt();
    }

    else if(buffer == "clear"){
        clear();
        prompt();
    }

    else if(buffer == "google"){
        Vir_ass.google();
        prompt();
    }

    else if(buffer == "yt"){
        Vir_ass.youtube();
        prompt();
    }

    else if(buffer == "so"){
        Vir_ass.stackoverflow();
        prompt();
    }

    else if(buffer == "wiki"){
        Vir_ass.wikipedia();
        prompt();
    }

    else if(buffer == "terminal"){
        Vir_ass.terminal();
        prompt();
    }

    else if(buffer == "editor"){
        Vir_ass.editor();
        prompt();
    }

    else if(buffer == "todo"){
        Vir_ass.todo();
        prompt();
    }

    else if(buffer == "skype"){
        Vir_ass.skype();
        prompt();
    }

    else if(buffer == "music"){
        Vir_ass.music();
        prompt();
    }

    else if(buffer == "school"){
        Vir_ass.school();
        prompt();
    }

    else if(buffer == "discord"){
        Vir_ass.discord();
        prompt();
    }

    else if(buffer == "github"){
        Vir_ass.github();
        prompt();
    }

    else if(buffer == "notes"){
        Vir_ass.notes();
        prompt();
    }

    else if(buffer == "game"){
        Vir_ass.game();
        prompt();
    }

    else if(buffer == "paint"){
        Vir_ass.paint();
        prompt();
    }

    else if(buffer == "math"){
        Vir_ass.math();
        prompt();
    }

    else if(buffer == "impress"){
        Vir_ass.impress();
        prompt();
    }

    else if(buffer == "wp"){
        Vir_ass.whatsapp();
        prompt();
    }

    else if(buffer == "startup"){
        Vir_ass.startup();
        prompt();
    }
    
    else if(buffer == "ulauncher"){
        Vir_ass.ulauncher();
        prompt();
    }

    else if(buffer == "temp"){
        Vir_ass.temperature();
        prompt();
    }

    else if(buffer == "day"){
        Vir_ass.day();
        prompt();
    }

    else{
        cout << endl;
        cout << "I'm sorry, I don't understand whats '" << buffer << "'" << endl;
        cout << endl;
    }

}


void Virtual_Assistant::terminal(){
    //closes or opens the terminal
    system("yakuake");
}


void Virtual_Assistant::editor(){

    clock_t begin = clock();

    //use your preffered text editor
    //open the app
    system("code");

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "\n\nIt took " << time_spent << " sec\n\n";

    //close the terminal
    Vir_ass.terminal();
}


void Virtual_Assistant::todo(){
    //use your preffered to do app
    system("todo");
}


void Virtual_Assistant::skype(){
    clock_t begin = clock();

    //open the app
    system("skype");

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "\n\nIt took " << time_spent << " sec\n\n";

    //close the terminal
    Vir_ass.terminal();
}


void Virtual_Assistant::music(){
    clock_t begin = clock();

    //use your preffered streaming service
    //open the app
    system("spotify");

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "\n\nIt took " << time_spent << " sec\n\n";

    //close the terminal
    Vir_ass.terminal();
}


void Virtual_Assistant::school(){
    //open the app
    clock_t begin = clock();
    system("brave https://classroom.google.com/u/2/h");

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n\nIt took %f sec\n\n", time_spent);

    //close the terminal
    Vir_ass.terminal();
}


void Virtual_Assistant::discord(){
    //open the app
    clock_t begin = clock();
    system("discord");

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "\n\nIt took " << time_spent << " sec\n\n";

    //close the terminal
    Vir_ass.terminal();
}


void Virtual_Assistant::github(){

    clock_t begin = clock();

    //this only works if you got github desktop
    system("github");
    //you can change this to your own github page
    system("brave https://github.com/koreaneggroll");

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "\n\nIt took " << time_spent << " sec\n\n";

    //close the terminal
    Vir_ass.terminal();
}


void Virtual_Assistant::notes(){

    clock_t begin = clock();

    //open the app
    system("simplenote");

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "\n\nIt took " << time_spent << " sec\n\n";

    //closes the terminal
    Vir_ass.terminal();
}


void Virtual_Assistant::game(){
    clock_t begin = clock();

    //open the app
    system("steam");

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "\n\nIt took " << time_spent << " sec\n\n";

    //close the terminal
    Vir_ass.terminal();
}


void Virtual_Assistant::hello(){
    cout << endl;
    cout << "Hello " << Vir_ass.customer.getName() << endl;
    cout << endl;
}


void Virtual_Assistant::paint(){
    clock_t begin = clock();

    //open the app
    system("pinta");

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "\n\nIt took " << time_spent << " sec\n\n";

    //close the terminal
    Vir_ass.terminal();
}


void Virtual_Assistant::math(){
        
    clock_t begin = clock();

    //open the app
    system("loffice --math");

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "\n\nIt took " << time_spent << " sec\n\n";

    //close the terminal
    Vir_ass.terminal();
}


void Virtual_Assistant::writer(){
        
    clock_t begin = clock();

    //open the app
    system("loffice --writer");

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "\n\nIt took " << time_spent << " sec\n\n";

    //close the terminal
    Vir_ass.terminal();
}


void Virtual_Assistant::impress(){
    clock_t begin = clock();

    //open the app
    system("loffice --impress");

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "\n\nIt took " << time_spent << " sec\n\n";

    //close the terminal
    Vir_ass.terminal();
}


void Virtual_Assistant::whatsapp(){
        
    clock_t begin = clock();

    //open the app
    system("brave https://web.whatsapp.com/");

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "\n\nIt took " << time_spent << " sec\n\n";

    //close the terminal
    Vir_ass.terminal();
}


void Virtual_Assistant::startup(){

    clock_t begin = clock();

    //open the apps
    Vir_ass.ulauncher();
    Vir_ass.whatsapp();
    Vir_ass.editor();
    Vir_ass.github();
    Vir_ass.music();
    Vir_ass.youtube();


    /*
        Here i'm trying to only call the 'school' function only on schooldays
        but idk how :|
    */
    
    
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "\n\nIt took " << time_spent << " sec\n\n";
}


void Virtual_Assistant::ulauncher(){

    clock_t begin = clock();

    //open app
    system("ulauncher");

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "\n\nIt took " << time_spent << " sec\n\n";

    //closes the terminal
    Vir_ass.terminal();
}


void Virtual_Assistant::temperature(){
    clock_t begin = clock();


    //google whats the temperature
    system("brave https://www.google.com/search?q=whats+the+temperature+outside&oq=whats+the+temperature+outside&aqs=chrome..69i57.6492j0j1&sourceid=chrome&ie=UTF-8");

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "\n\nIt took " << time_spent << " sec\n\n";


    //close the temperature
    Vir_ass.terminal();
}


void Virtual_Assistant::day(){
    clock_t begin = clock();


    //google what day is it
    system("brave https://www.google.com/search?q=what+day+is+it+%3F&oq=what+day+is+it+%3F+&aqs=chrome..69i57j69i60.2066j0j1&sourceid=chrome&ie=UTF-8");

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "\n\nIt took " << time_spent << " sec\n\n";


    //close the terminal
    Vir_ass.terminal();
}


void Virtual_Assistant::seetime(){
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    cout << "\nCurrent local time and date" << asctime (timeinfo) << endl;
}


void Virtual_Assistant::setPsw(){
    char *pass = (char*)malloc(sizeof(char) * 25);
    char sure;


    if(!pass){
        cout << "\n\n\nERR: Couldn't allocate memory\n\n\n";
        exit(1);
    }


    do{
        cout << "\nNew Password: ";

        cin >> pass;


        if(isSpace(pass)){
            cout << "\nI'm sorry but your password cannot contain spaces" << endl;
            cout << "Please try again" << endl;

            prompt();
        }


        cout << "\nYour new password will be: " << pass << endl;
        cout << "Are you sure you want to set this as your new password? (y/n): ";

        cin >> sure;

    }while(sure != 'y' && sure != 'n');



    Vir_ass.customer.setPass(pass);



    //create a file
    ofstream file;

    //open the file
    file.open("./bin/pass.txt");

    //write to the file
    file << pass;

    //close the file
    file.close();
}


void Virtual_Assistant::setUserName(){
    char *nm = (char*)malloc(sizeof(char) * 25);
    char sure;


    if(!nm){
        cout << "\n\n\nERR: Couldn't allocate memory\n\n\n";
        exit(1);
    }


    do{
        cout << "Name: ";

        cin >> nm;


        if(isSpace(nm)){
            cout << "\nI'm sorry but you name cannot contain spaces" << endl;
            prompt();
        }


        cout << "\nAre you sure you want to set this as your name? y/n: ";
        cin >> sure;

    }while(sure != 'y' && sure != 'n');


    Vir_ass.customer.setName(nm);

    //create the file
    ofstream file;

    //open the file
    file.open("./bin/name.txt");

    //write to the file
    file << nm;

    //close the file
    file.close();
}


void Virtual_Assistant::reminder(){
    int h, m, s;


    cout << "\nHours from now: ";
    cin >> h;


    if(h > 24 || h < 0){
        cout << "\n\nNot a valid time\n\n";
        prompt();
    }


    else{
        int htos = h * 3600;
        sleep(htos);

        system("notify-send alarm");
    }


    cout << "\nMinutes from now: ";
    cin >> m;


    if(m > 60 || m < 0){
        cout << "\n\nNot a valid time\n\n";
        prompt();
    }


    else{
        int mtos = m * 60;
        sleep(mtos);

        system("notify-send alarm");
    }


    cout << "\nSeconds from now: ";
    cin >> s;


    if(s > 60 || s < 0){
        cout << "\n\nNot a valid time\n\n";
        prompt();
    }


    else{
        sleep(s);

        system("notify-send alarm");
    }

}


void Virtual_Assistant::google(){
    //waste variable so we can use getline
    char c;
    c = getc(stdin);

    char *command = (char*)malloc(sizeof(char) * 35);
    char *search = (char*)malloc(sizeof(char) * 300);


    if(!command){
        cout << "\n\n\nERR: Couldn't allocate memory\n\n\n";
        exit(1);
    }


    if(!search){
        cout << "\n\n\nERR: Couldn't allocate memory\n\n\n";
        exit(1);
    }


    cout << "\n\nGoogle search: ";
    fgets(search, 300, stdin);

    clock_t begin = clock();

    search = replaceSpaces(search);

    strcpy(command, "brave https://google.com/search?q=");
    strcat(command, search);

    system(command);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "\n\nIt took " << time_spent << " sec\n\n";

    //closes the terminal
    Vir_ass.terminal();


    //frees memory(which doesn't work aparently)
    //free(command);
    //free(search);
}


void Virtual_Assistant::youtube(){
    //waste variable so we can use getline
    char c;
    c = getc(stdin);

    char *command = (char*)malloc(sizeof(char) * 52);
    char *search = (char*)malloc(sizeof(char) * 300);

    if(!command){
        cout << "\n\n\nERR: Couldn't allocate memory\n\n\n";
        exit(1);
    }

    if(!search){
        cout << "\n\n\nERR: Couldn't allocate memory\n\n\n";
        exit(1);
    }


    cout << "Youtube search: ";
    fgets(search, 300, stdin);

    clock_t begin = clock();

    search = replaceSpaces(search);

    strcpy(command, "brave https://www.youtube.com/results?search_query=");
    strcat(command, search);

    system(command);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "\n\nIt took " << time_spent << " sec\n\n";

    //close the terminal
    Vir_ass.terminal();


    //frees memory(which doesn't work aparently)
    //free(command);
    //free(search);
}


void Virtual_Assistant::stackoverflow(){
    
    //waste variable
    char c;
    c = getc(stdin);


    char *command = (char*)malloc(sizeof(char) * 42);
    char *search = (char*)malloc(sizeof(char) * 300);


    if(!command){
        cout << "\n\n\nERR: Couldn't allocate memory\n\n\n";
        exit(1);
    }

    if(!search){
        cout << "\n\n\nERR: Couldn't allocate memory\n\n\n";
        exit(1);
    }


    cout << "\n\nStackoverflow search: ";
    fgets(search, 300, stdin);


    clock_t begin = clock();

    search = replaceSpaces(search);

    strcpy(command, "brave https://stackoverflow.com/search?q=");
    strcat(command, search);

    system(command);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "\n\nIt took " << time_spent << " sec\n\n";

    //close the terminal
    Vir_ass.terminal();

    
    //frees some memory(which doesn't work aparently)
    //free(command);
    //free(search);
}


void Virtual_Assistant::wikipedia(){

    //waste variable
    char c;
    c = getc(stdin);

    char *command = (char*)malloc(sizeof(char) * 37);
    char *search = (char*)malloc(sizeof(char) * 300);

    if(!command){
        cout << "\n\n\nERR: Couldn't allocate memory\n\n\n";
        exit(1);
    }

    if(!search){
        cout << "\n\n\nERR: Couldn't allocate memory\n\n\n";
        exit(1);
    }


    cout << "\n\nWiki search: ";
    fgets(search, 300, stdin);

    for(int i = 0; i < strlen(search); i++){
        if(search[i] == ' '){
            search[i] = '_';
        }
    }

    strcpy(command, "brave https://en.wikipedia.org/wiki/");
    strcat(command, search);

    system(command);


    //closes the terminal
    Vir_ass.terminal();
}
//FUNCTIONS VIRTUAL ASSISTANT END




//NORMAL FUNCTIONS START
void prompt(){

    string buffer;

    while(true){
        cout << "arn-virtual-assistant# ";
        cin >> buffer;

        if(buffer == "exit"){
            exit(0);
        }

        Vir_ass.evaluate(buffer);
    }

}
//NORMAL FUNCTIONS END 