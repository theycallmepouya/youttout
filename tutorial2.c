#include <stdio.h>
#include "tutorial2.h"

/* This function just prints some instructins for user so that user does not make a mistake */

void tutorial2 () {

    printf("What do you wanna do now? \n");
    printf("1) for posting a new post type : post <text> \n");
    printf("2) for deleting a post type : delete <post_id> \n");
    printf("3) for liking a post type : like <user_name> <post_id> \n");
    printf("4) for getting your information type : info \n");
    printf("5) for loging out of your account type : logout \n");
}