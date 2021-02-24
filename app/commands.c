#include "commands.h"
#include <stdbool.h>
#include <string.h>



bool is_space(char *str){

    bool is_space = false;

    for(int i = 0; i < strlen(str); i++){
        if(str[i] == ' '){
            is_space = true;
            break;
        }
    }

    return is_space;
}