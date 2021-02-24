#include "commands.h"
#include <stdbool.h>
#include <string.h>



bool is_space(char *str){

    bool is_space = false;
    int len = strlen(str);

    for(int i = 0; i < len; i++){
        if(str[i] == ' '){
            is_space = true;
            break;
        }
    }

    return is_space;
}