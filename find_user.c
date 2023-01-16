#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "find_user.h"

/* this function finds a user with given username and prints all the needed information */

void finding ( char* username , post* head ){

    post* current = head ;

    int check = 0 ;

    while ( current != NULL ){

        if ( strcmp(current->post_writer,username) == 0 ){
            printf("--------------------------------\n");
            printf("POST_WRITER : %s \n",current->post_writer) ;
            printf("POST_ID : %d \n",current->post_id) ;
            printf("POST_TEXT : %s \n",current->post_content) ;
            printf("POST_LIKES : %d \n",current->like) ;
            check++ ;
        }

        current = current->next_post ;
    }

    if ( check == 0 ){
        printf("Given username does not exist in system :( \n") ;
    }
}