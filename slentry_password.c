#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slentry_password.h"

/* this function seperates the input by spaces and gives us the third part */

char* slentry_password ( char* user_entry ){

    int i = 0 ;
    char* password = (char*)malloc(1*sizeof(char)) ;

    if ( password == NULL ){
        printf("Memory allocation failed1 \n");
        return NULL ;
    }
    
    for ( i ; user_entry[i] != ' ' ; i++ ){
    }

    i = i + 1 ;

    for ( i ; user_entry[i] != ' ' ; i++ ){
    }

    i = i + 1 ;

    int j = 0 ;
    for ( i ; user_entry[i] != ' ' ; i++ ){
        password[j] = user_entry[i] ;
        j++ ;
        password = (char*)realloc(password,(j+1)*sizeof(char));

        if ( password == NULL ){
            printf("Memory allocation failed! \n");
            return NULL ;
        }
    }
    password[j] = '\0' ;

    return password ;
}