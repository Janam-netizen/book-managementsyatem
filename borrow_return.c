#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include "user_management.h"
#include "book_management.h"
extern struct Book book_list[30];

extern int length;

void borrow_book(struct user u)
{
    int id;

    printf("Please enter the id of  book to be  borrowed\n");
    scanf("%i", &id);
    if (id > length || id == length || id < 0)
    {
        printf("Invalid book id\n");
    }
    else if (u.borrowed[id] == 1)
    {
        printf("Book already borrowed\n");
    }
    else if (book_list[id].copies == 0)
    {
        printf("Book no longer available\n");
    }
    else
    {

        u.borrowed[id] = 1;
        book_list[id].copies -= 1;
        printf("book successfully borrowed\n");
    }
}

void ret_book(struct user u)
{
    int id;

    printf("Please enter the id of  book to be returned\n");

    scanf("%i", &id);

    if (u.borrowed[id] == 1)
    {
        u.borrowed[id] = 0;
        book_list[id].copies += 1;
    }
    else
    {

        printf("Book not  borrowed\n");
    }
}
void display_issued(struct user u)
{
    for (int i = 0; i < length; i++)
    {
        if (u.borrowed[i] == 1)
        {

            display_book(book_list[i]);
        }
    }
}
void update_record(struct user u)
{
   struct  user x;
   FILE *file;
    file = fopen("users.bin", "rb+");
    while (fread(&x, sizeof(x), 1, file))
    {

        if (strcpy(x.username, u.username) == 0 && strcpy(x.password, u.password) == 0)
        {
            fseek(file, -sizeof(struct user), SEEK_CUR);
            fwrite(&x,  sizeof(struct user), 1, file);
        }
    }
    fclose(file);
}
