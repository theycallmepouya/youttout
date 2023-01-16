#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

/* this function writes all the information of all the users in a txt file */

void accounts ( user* head ){

    user* current = head->next_user ;

    FILE* myfile = fopen("accounts.txt","w") ;

    while( current != NULL ){

        fprintf(myfile,"%s ",current->username) ;
        
        fprintf(myfile,"%s ",current->password) ;
        
        fprintf(myfile,"%d \n",current->number_of_posts) ;
        
        current = current->next_user ;
    }


    fclose(myfile) ;
}