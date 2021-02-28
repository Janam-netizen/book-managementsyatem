#include <stdio.h>
#include <stdlib.h>
#include "book_management.h"
#include "user_management.h"
#include <string.h>
struct Book Book_list[30];
int length;
int in();
int main()
{
    char username[30];
    char password[30];
    struct user u;
    FILE *fin;
    //load_books(fin);
    //FILE *fout = fopen("book_list.bin", "wb");
    read_booklist();

    while (1)
    {
        char title[30];
        unsigned int year;
        int choice;
        printf("Please enter an option ranging from 1-3\n");
        printf("1:Login\n");
        printf("2:Register\n");
        printf("3:Admin menu\n");
        printf("4:quit\n");
        choice = in();

        switch (choice)
        {
        case 1:
        {
            u = login(username, password);
            if (strcmp(u.username, "undefined") != 0)
            {

                user_menu(u);
                //printf("%s",u.borrowed);
            }
            break;
        }
        case 2:
        {
            create_newuser(username, password);
            break;
        }
        case 3:
        {
            prompt_login(username, password);
            if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0)
            {
                admin_menu();
            }
            else
            {

                printf("wrong username or password\n");
            }
            break;
        }
        default:
            
            exit(1);
        }
    }
    //fclose(fin);

}
int in()
{
    int number;
    scanf("%d", &number);
    return (number);
}
