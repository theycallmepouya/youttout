#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entrycheck2.h"

/* this function checks the given input for the subsidiary loop of the program */

int entrycheck2 ( char* userentry ){

    char* order = (char*)malloc(1*sizeof(char));

    if ( order == NULL ){
        printf("Memory allocation failed! \n");
        return 10 ;
    }

    int i ;
    for ( i = 0 ; userentry[i] != ' ' ; i++ ){
        order[i] = userentry[i] ;
        order = realloc ( order , i+2 );

        if ( order == NULL ){
            printf("Memory allocation failed! \n");
            return 10 ;
        }
    }
    order[i+1] = '\0' ;

    if ( order[0] == 'p' && order[1] == 'o' && order[2] == 's' && order[3] == 't' ){
        free(order) ;
        return 1 ;
    }

    else if ( order[0] == 'd' && order[1] == 'e' && order[2] == 'l' && order[3] == 'e' && order[4] == 't' && order[5] == 'e' ){
        free(order) ;
        return 2 ;
    }

    else if ( order[0] == 'l' && order[1] == 'i' && order[2] == 'k' && order[3] == 'e' ){
        free(order) ;
        return 3 ;
    }

    else if ( order[0] == 'i' && order[1] == 'n' && order[2] == 'f' && order[3] == 'o' ){
        free(order) ;
        return 4 ;
    }
    
    else if ( order[0] == 'l' && order[1] == 'o' && order[2] == 'g' && order[3] == 'o' && order[4] == 'u' && order[5] == 't' ){
        free(order) ;
        return 5 ;
    }

    else {
        free(order) ;
        return 0 ;
    }


}