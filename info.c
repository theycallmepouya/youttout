#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "info.h"

/* this function prints all the information about user activity */

void infoing ( char* username , post* head ){

    post* current = head ;

    while ( current != NULL ){

        if ( strcmp(current->post_writer,username) == 0 ){
            printf("------------------------------------------\n") ;
            printf("POST_ID : %d \n",current->post_id) ;
            printf("POST_TEXT : %s \n",current->post_content) ;
            printf("POST_LIKES : %d \n",current->like) ;
        }

        current = current->next_post ;
    }
}