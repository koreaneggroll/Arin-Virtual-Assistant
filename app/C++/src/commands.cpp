#include "../includes/commands.h"


bool isSpace(char *str){
    bool is_space;

    int len = strlen(str);

    for(int i = 0; i < len; i++){
        if(str[i] == ' '){
            is_space = true;
            break;
        }
    }
    
    return is_space;
    
}


char *replaceSpaces(char *str){
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == ' '){
            str[i] = '+';
        }
    }

    return str;
}


void clear(){
    std::cout << "\e[1;1H\e[2J";
}