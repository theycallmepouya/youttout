#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "file_posts.h"

/* this function writes all the information of all the posts in a txt file */

void posts ( post* head ){

    post* current = head->next_post ;

    FILE* myfile = fopen("posts.txt","w") ;

    while ( current != NULL ){

        fprintf(myfile,"%s ",current->post_content) ;

        fprintf(myfile,"%s ",current->post_writer) ;

        fprintf(myfile,"%d \n",current->like) ;

        current = current->next_post ;
    }

    fclose(myfile) ;
}