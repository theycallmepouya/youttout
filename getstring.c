#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getstring.h"

/* this function takes the user entry and puts it in a dynamic array whitout any memory leak */

char* getstring () {

    char* string = (char*)malloc(1*sizeof(char)) ;

    if ( string == NULL ){
        printf("Memory allocation failed! \n");
        return NULL ;
    }

    char c ;
    int i = 0 ;

    while ( (c = getchar()) != '\n' ){
        string[i++] = c ;
        string = realloc ( string , (i+1)*sizeof(char) ) ;

        if ( string == NULL ){
            printf("Memory allocation failed! \n");
            return NULL ;
        }

    }
    string[i] = ' ' ;
    string[i+1] = '\0' ;
    
    return string ;

}