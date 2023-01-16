#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "signup_check.h"

/* this function checks if a username is unique or not */

int signup_checking ( char* username , user* head ){

    user* current = head ;

    while ( current != NULL ){

        if ( strcmp(current->username,username) == 0 ){
            return 0 ;
        }

        current = current->next_user ;
    }

    return 1 ;
}