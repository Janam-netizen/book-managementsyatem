#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"
#include "user_management.h"

void display(struct user *address)
{
    printf("%s,%s\n", address->username, address->password);
}
struct user check(char username[30], char password[30])
{
    int flag = 0;
    struct user u;
    FILE *file = fopen("users.bin", "rb");
    while ((fread(&u, sizeof(u), 1, file) == 1))
    {
        if (strcmp(u.username, username) == 0 && strcmp(u.password, password) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag != 1)
    {

        strcpy(u.username, "undefined");
    }
    return u;
    fclose(file);
}

void prompt_login(char username[30], char password[30])
{
    printf("enter username\n");
    scanf("%s", username);
    printf("enter password\n");
    scanf("%s", password);

    //return 0;

} //prompts to enter username and password

void create_newuser(char username[30], char password[30])
{
    int i;
    struct user newuser;
    FILE *file = fopen("users.bin", "ab");
    prompt_login(username, password);
    if (strcmp(check(username, password).username, "undefined") != 0)
    {
        printf("User with similar username already exist\n");

        //return 0;
    }
    else
    {

        strcpy(newuser.username, username);
        strcpy(newuser.password, password);
        for (i = 0; i < 30; i++)
        {
            newuser.borrowed[i] = 0;
        }
        
        //newuser.issued.length=0;
        //newuser.issued.array=(struct Book*)malloc(sizeof(Book));

        fwrite(&newuser, sizeof(newuser), 1, file);
        printf("successfully registere\n");
        fclose(file);
    }

} // Registers a user if user has unique username

//returns 1 if user exists in file and 0 if user does not exist...
struct user login(char username[30], char password[30])
{
    prompt_login(username, password);
    struct user u = check(username, password);
    if (strcmp(u.username, "undefined") == 0)
    {
        printf("Unsuccesfull login\n");
    }
    else
    {
        printf("Successfull login");
    }

    return u;
}
void readfile()
{

    struct user object2;
    struct Book b;

    FILE *file = fopen("users.bin", "rb");
    if (file != NULL)
    {
        while (fread(&object2, sizeof(struct user), 1, file) == 1)
        {
            display(&object2);
        }
    }
    fclose(file);
    //printf("%p\n",object2);
    //free(object2);
}
/*void check(char username[30], char password[30]{




}*/
