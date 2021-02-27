//INCLUDES
#include <iostream>
#include <time.h>
#include "../includes/commands.h"


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
        //evaluate function
        void evaluate(string buffer);
        //actual functions
        void hello();
        void seetime();
        friend void prompt();

};
typedef Virtual_Assistant vs;

vs Vir_ass;




//FUNCTION PROTOTYPES
void prompt();




int main(void){
    prompt();
}



//FUNCTIONS USER
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




//FUNCTIONS VIRTUAL ASSISTANT
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