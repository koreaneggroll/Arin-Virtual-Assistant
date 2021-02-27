#include "../includes/commands.h"


bool is_space(std::string str){
    bool is_space;

    for(int i = 0; i < str.size(); i++){
        if(str[i] == ' '){
            is_space = true;
            break;
        }
    }
    
    return is_space;
    
}