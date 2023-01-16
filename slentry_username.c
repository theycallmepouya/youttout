#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slentry_username.h"

/* this function seperates the input by spaces and gives us the second part */

char* slentry_username ( char* user_entry ){

    int i = 0 ;
    char* username = (char*)malloc(1*sizeof(char)) ;

    if ( username == NULL ){
        printf("Memory allocation failed1 \n");
        return NULL ;
    }
    
    for ( i = 0 ; user_entry[i] != ' ' ; i++ ){
    }

    i = i + 1 ;

    int j = 0 ;
    for ( i ; user_entry[i] != ' ' ; i++ ){
        username[j] = user_entry[i] ;
        j++ ;
        username = (char*)realloc(username,(j+1)*sizeof(char));

        if ( username == NULL ){
            printf("Memory allocation failed! \n");
            return NULL ;
        }
    }
    username[j] = '\0' ;

    return username ;
}