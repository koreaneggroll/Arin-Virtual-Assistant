#include <iostream>
#include <time.h>


using namespace std;



//DATA


class User{
    private:
        string name;
        string password;
};
typedef User usr;

usr user;



class Virtual_Assistant{
    private:
        string name;
        usr customer;
    public:
        void hello();
        friend void prompt();

};
typedef Virtual_Assistant vs;

vs Vir_ass;



//FUNCTION PROTOTYPES



int main(void){

}



void prompt(){
    string buffer;

    while(true){
        cout << "arn-virtual-assistant# ";
        cin >> buffer;

        if(buffer == "exit"){
            exit(0);
        }

        //TODO EVALUATE FUNCTION
    }
}