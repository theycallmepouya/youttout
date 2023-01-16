#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "like.h"

/* this function adds one to number of likes of given post */

int like (char* post_liker , char* post_writer , int post_id , post* head ){

    post* current = head ;

    int true = 1 ;
    while (true){

        if ( strcmp(post_liker,post_writer) == 0 ){
            printf("you can not like your own post :) \n");
            return 0 ;
        }

        else {

            if ( strcmp(current->post_writer,post_writer) == 0 && current->post_id == post_id ){
                printf("you liked %s \n",current->post_content) ;
                current->like = current->like + 1 ;
                return 1 ;
            }

            if ( strcmp(current->post_writer,post_writer) == 0 && current->post_id != post_id ){
                printf("given username does not have a post with given post_id \n") ;
                return 0 ;
            }

            if ( strcmp(current->post_writer,post_writer) != 0 && current->post_id == post_id ){
                printf("given post does not belong to given username \n") ;
                return 0 ;
            }

            if ( current == NULL ){
                printf("given information is not correct :( \n");
                return 0 ;
            }

        }

        current = current->next_post ;
    }
}