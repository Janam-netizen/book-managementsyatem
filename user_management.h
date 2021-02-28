#ifndef USER_MANAGEMENT_GUARD__H 
#define USER_MANAGEMENT_GUARD__H
struct user
{
    char username[30];
    char password[30];
    int borrowed[30];
    //struct BookArray issued;

    //char name[30];
};
//returns stored user data with same user name and password
struct user check(char username[30], char password[30]);
//prompt for login and password
void prompt_login(char username[30], char password[30]);
//Faccilitates registration of new users
void create_newuser(char username[30], char password[30]);
//Enables user to login through username and password
struct user login(char username[30],char password[30]);
//Displays data of all users
void readfile();
void borrow_book(struct user u);
void ret_book(struct user u);
void display_issued(struct user u);
void update_record(struct user u);
void user_menu(struct user u);
# endif
