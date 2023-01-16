#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "post.h"

/* this function adds a post with given information to posts list */

int posting ( char* post_text , char* post_writer , int post_id , post* head ){

    post* current = head ;

    while ( current->next_post != NULL ){
        current = current->next_post ;
    }

    current->next_post = (post*)malloc(sizeof(post));
    if ( current->next_post == NULL ){
        printf("Memory allocation failed! \n");
        return 0 ;
    }

    current->next_post->post_content = (char*)malloc(sizeof(post_text)) ;
    if ( current->next_post->post_content == NULL ){
        printf("Memory allocation failed! \n");
        return 0 ; 
    }

    current->next_post->post_writer = (char*)malloc(sizeof(post_writer)) ;
    if ( current->next_post->post_writer == NULL ){
        printf("Memory allocation failed! \n");
        return 0 ;
    }

    current->next_post->like = 0 ;
    current->next_post->post_id = post_id ;

    strcpy(current->next_post->post_content,post_text) ;
    strcpy(current->next_post->post_writer,post_writer) ;

    current->next_post->next_post = NULL ;

    return 1 ;

}