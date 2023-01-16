#include <stdio.h>
#include "tutorial1.h"

/* This function just prints some instructins for user so that user does not make a mistake */

void tutorial1 (){

    printf("What do you wanna do ? \n");
    printf("1) for signing up type : signup <user name> <password> \n");
    printf("2) for loging in type : login <user name> <password> \n");
    printf("3) for finding a user type : find_user <user name> \n");
    printf("4) for ending the program type : end \n");
}