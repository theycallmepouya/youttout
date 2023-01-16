#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "tutorial1.h"
#include "getstring.h"
#include "entrycheck1.h"
#include "slentry_username.h"
#include "slentry_password.h"
#include "signup.h"
#include "tutorial2.h"
#include "entrycheck2.h"
#include "login.h"
#include "post.h"
#include "like.h"
#include "delete.h"
#include "info.h"
#include "find_user.h"
#include "signup_check.h"
#include "file_accounts.h"
#include "file_posts.h"

int main () {

    printf("Welcome to YOU-T TOU-T \n");

    /* Creating the dummy node for users list */
    user* user_list = (user*)malloc(sizeof(user));
    if ( user_list == NULL ){
        printf("Memory allocation failed !\n");
        return 0 ;
    }
    user_list->next_user = NULL ;

    /* Creating the dummy node for posts list */
    post* post_list = (post*)malloc(sizeof(post));
    if ( post_list == NULL ){
        printf("Memory allocation failed! \n");
        return 0 ;
    }
    post_list->next_post = NULL ;

    int post_id = 0 ;

    /* The main loop of the program */
    int true = 1 ;
    while (true) {

        /* getting the entry from user */
        tutorial1() ;
        char* user_entry = getstring() ;
        int check = entrycheck1(user_entry) ;

        /* SIGN Up */
        if ( check == 1 ){

            char* username = slentry_username(user_entry) ;
            char* password = slentry_password(user_entry) ;

            int signup_checker = signup_checking(username,user_list) ;
            if ( signup_checker == 1 ){

                /*printf("you signed up as : \n");
                printf("username : %s\n",username) ;
                printf("password : %s\n",password) ;*/

                signup(username,password,user_list) ;
            }

            else if ( signup_checker == 0 ){
                printf("Given username already exists \n");
            }

            free(username) ;
            free(password) ;

        }

        /* LOG IN */
        if ( check == 2 ){

            char* username = slentry_username(user_entry) ;
            char* password = slentry_password(user_entry) ;

            /*printf("username : %s\n",username) ;
            printf("password : %s\n",password) ;*/

            user* logged_in = login(username,password,user_list) ;

            if ( logged_in != NULL ){

                /* The subsidiary loop of the program */
                int true2 = 1 ;
                while(true2) {

                    /* getting the entry from user */
                    tutorial2() ;
                    char* user_entry2 = getstring() ;
                    int check2 = entrycheck2(user_entry2) ;

                    /* POST */
                    if ( check2 == 1 ){

                        char* post_text = slentry_username(user_entry2) ;
                        posting(post_text,username,post_id,post_list) ;

                        printf("You posted : %s , with post_id of : %d \n",post_text,post_id) ;
                        post_id++ ;
                        logged_in->number_of_posts = logged_in->number_of_posts + 1 ;

                        free(post_text) ;

                    }

                    /* DELETE */
                    if ( check2 == 2 ){

                        char* post_id_to_delete_char = slentry_username(user_entry2) ;
                        int post_id_to_delete_int = atoi(post_id_to_delete_char) ;
                        int delete_check = deleting(post_id_to_delete_int,username,post_list) ;


                        free(post_id_to_delete_char) ;
                    }

                    /* LIKE */
                    if ( check2 == 3 ){

                        char* post_writer_to_like = slentry_username(user_entry2) ;
                        char* post_id_to_like_char = slentry_password(user_entry2) ;
                        int post_id_to_like_int = atoi(post_id_to_like_char) ;

                        int like_check = like(username,post_writer_to_like,post_id_to_like_int,post_list) ;
                        
                        if ( like_check == 1 ){
                            printf("liked post id : %d\n",post_id_to_like_int) ;
                        } 

                        free(post_writer_to_like) ;
                        free(post_id_to_like_char) ;
                    }

                    /* INFO */
                    if ( check2 == 4 ){
                        printf("Your username is : %s \n",username) ;
                        printf("Your password is : %s \n",password) ;
                        infoing(username,post_list) ;

                    }

                    /* LOGOUT */
                    if ( check2 == 5 ){
                        printf("You logged out successfully \n");
                        
                        true2 = 0 ;
                    }

                    /* WRONG INPUT */
                    if ( check2 == 0 ){
                        printf ("Seems like you made a mistake. \n ");
                    }

                    /* SYSTEM FAILURE */
                    if ( check2 == 10 ){
                        printf("It is an unfortunate failure of your memory, why don't you try again? \n");
                    }

                    free(user_entry2) ;

                }
            }

            free(username) ;
            free(password) ;

        }

        /* FIND USER */
        if ( check == 3 ){

            char* username = slentry_username(user_entry) ;
            finding(username,post_list) ;

            free(username) ;
        }

        /* WRONG INPUT */
        if ( check == 0 ){
            printf ("Seems like you made a mistake. Please tell me what do you wanna do one more time : \n ");
        }

        /* END */
        if ( check == 10 ){
            printf ("Hope you had a good time at YOU-T TOU-T ! \n");
            true = 0 ;
        }

        free(user_entry) ;
    }

    /* PHASE 2 */

    accounts(user_list) ;
    posts(post_list) ;

    return 0 ;
}

/*gcc main.c like.c post.c tutorial2.c signup.c login.c slentry_password.c slentry_username.c entrycheck1.c entrycheck2.c getstring.c tutorial1.c delete.c info.c find_user.c signup_check.c file_accounts.c file_posts.c*/