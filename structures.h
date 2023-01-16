#ifndef USER
#define USER

typedef struct users user ;

struct users {
    char* username ;
    char* password ;
    int number_of_posts ;
    struct users* next_user ;
};
#endif

#ifndef POST
#define POST

typedef struct posts post ;

struct posts {
    char* post_writer ;
    int post_id ;
    int like ;
    char* post_content ;
    struct posts* next_post ;
};

#endif