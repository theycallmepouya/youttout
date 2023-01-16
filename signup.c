#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "signup.h"

/* this function adds a new node in the users list and puts given username and password in it */

int signup ( char* username , char* password , user* head ){

    user* current = head ;

    while ( current->next_user != NULL ){
        current = current->next_user ;
    }

    current->next_user = (user*)malloc(sizeof(user)) ;
    if ( current->next_user == NULL ){
        printf("Memory allocation failed! \n");
        return 0 ;
    }

    current->next_user->username = (char*)malloc(sizeof(username)) ;
    if ( current->next_user->username == NULL ){
        printf("Memory allocation failed! \n");
        return 0 ;
    }

    current->next_user->password = (char*)malloc(sizeof(password)) ;
    if ( current->next_user->password == NULL ){
        printf("Memory allocation failed! \n");
        return 0 ;
    }

    strcpy(current->next_user->username,username) ;
    strcpy(current->next_user->password,password) ;
    current->next_user->number_of_posts = 0 ;

    current->next_user->next_user = NULL ;

    return 1 ;
}



