//INCLUDES
#include <iostream>
#include <time.h>
#include "../includes/commands.h"
#include <fstream>


using namespace std;



//DATA


class User{
    private:
        string name;
        string password;
    public:
        void setName(string nm);
        void setPass(string ps);
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
        void setpsw();
        void setname();
        void reminder();
        void google();
        void youtube();
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
        //calls the command
        Vir_ass.hello();
        //returns to the prompt
        prompt();
    }

    


    else if(buffer == "time"){
        //calls the command
        Vir_ass.seetime();
        //returns to the prompt
        prompt();
    }



    else if(buffer == "setpsw"){
        //calls the command
        Vir_ass.setpsw();
        //returns to the prompt
        prompt();
    }




    else if(buffer == "clear"){
        //calls the command
        clear();
        //returns to the prompt
        prompt();
    }


    else{
        cout << endl;
        cout << "I'm sorry, I don't understand whats '" << buffer << "'" << endl;
        cout << endl;
    }

}





void Virtual_Assistant::hello(){
    cout << endl;
    cout << "Hello " << Vir_ass.customer.getName() << endl;
    cout << endl;
}




void Virtual_Assistant::seetime(){
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    cout << "\nCurrent local time and date" << asctime (timeinfo) << endl;
}




void Virtual_Assistant::setpsw(){
    char *password = (char*)malloc(sizeof(char) * 25);
    char sure;


    if(!password){
        cout << "\n\n\nERR: Couldn't allocate memory\n\n\n";
    }


    do{
        cout << "\nNew Password: ";

        cin >> password;


        if(is_space(password)){
            cout << "\nI'm sorry but your password cannot contain spaces" << endl;
            cout << "Please try again" << endl;

            prompt();
        }


        cout << "\nYour new password will be: " << password << endl;
        cout << "Are you sure you want to set this as your new password? (y/n): ";

        cin >> sure;

    }while(sure != 'y' && sure != 'n');

    //create a file
    ofstream file;

    //open the file
    file.open("./bin/pass.txt");

    //write to the file
    file << password << endl;

    //close the file
    file.close();
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