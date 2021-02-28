#include <stdio.h>
#include "book_management.h"
#include "user_management.h"
struct Book book_list[30];
int length;
void user_menu(struct user u)
{
    FILE *fin;
    FILE *fout;
    load_books(fin);
    fout = fopen("book_management.bin", "wb");
    int id;
    int year;
    char title[30];
    while (1)
    {
        int choice;
        printf("1:Borrow book\n");
        printf("2: Return book\n");
        printf("3:Display  books available\n");
        printf("4:Display borrowed books\n");
        printf("5:Filter book by title\n");
        printf("6:Filter book by year\n");
        printf("7:quit\n");
        scanf("%i", &choice);
        if (choice == 1)
        {

            borrow_book(u);
            update_record(u);
            //printf("%s",u.borrowed);
        }

        else if (choice == 2)
        {
            ret_book(u);
            update_record(u);
            //printf("%s",u.borrowed);
        }

        else if (choice == 3)
        {
            read_booklist();
        }

        else if (choice == 4)
        {
            display_issued(u);
        }
        else if (choice == 5)
        {
            printf("Please enter title\n");
            scanf("%s", title);
            find_book_by_title(title);
        }
        else if(choice==6)
        {
            printf("please enter year\n");
            scanf("%i", &year);
            find_book_by_year(year);

                
        }
        else{

            break;
        }
    }

    /*if (load_books(fin) == 1)
    {
        fclose(fin);
    }*/
    store_books(fout);
    fclose(fout);
}
