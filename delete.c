#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "delete.h"

/* this function deletes the post that matches with given information */

int deleting ( int post_id , char* username , post* head ){

    post* current = head ;
    post* previous = NULL ;

    if ( current->next_post == NULL ){
        printf("There is not any post to be liked \n");
        return 0 ;
    }

    while ( current->next_post->post_id != post_id ){
        previous = current ;
        current = current->next_post ;
    }

    previous = current ;
    current = current->next_post ;

    if ( current->post_id == post_id && strcmp(current->post_writer,username) == 0 ){
        
        printf("you deleted %s with post_id of : %d \n",current->post_content,current->post_id) ;
        previous->next_post = current->next_post ;
        free(current) ;
        return 1 ;
    }

    else {
        printf("post of given post_id does not belong to you :( \n");
        return 0 ;
    }


}