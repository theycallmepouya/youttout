#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "login.h"

/* this function finds the right node by the information given by user */

user* login ( char* user_name , char* password , user* head ){

    user* current = head ;
    
    int true = 1 ;
    while (true){

        if ( strcmp(current->username,user_name) == 0  && strcmp(current->password,password) == 0 ){
            printf("login successful \n");
            return current ;
        }

        if ( strcmp(current->username,user_name) == 0  && strcmp(current->password,password) != 0 ){
            printf("wrong password \n");
            return NULL ;
        }

        if ( current == NULL ){
            printf("Account does not exist :( \n");
            return NULL ;
        }

        current = current->next_user ;
    }

}