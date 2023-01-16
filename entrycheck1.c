#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entrycheck1.h"

/* this function checks the given input for the main loop of the program */

int entrycheck1 ( char* userentry ){

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

    if ( order[0] == 's' && order[1] == 'i' && order[2] == 'g' && order[3] == 'n' && order[4] == 'u' && order[5] == 'p' ){
        free(order) ;
        return 1 ;
    }

    else if ( order[0] == 'l' && order[1] == 'o' && order[2] == 'g' && order[3] == 'i' && order[4] == 'n' ){
        free(order) ;
        return 2 ;
    }

    else if ( order[0] == 'f' && order[1] == 'i' && order[2] == 'n' && order[3] == 'd' && order[4] == '_' && order[5] == 'u' && order[6] == 's' && order[7] == 'e' && order[8] == 'r' ){
        free(order) ;
        return 3 ;
    }

    else if ( order[0] == 'e' && order[1] == 'n' && order[2] == 'd' ){
        free(order) ;
        return 10 ;
    }
    
    else {
        free(order) ;
        return 0 ;
    }

}