#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "book_management.h"

int length;

struct Book book_list[30];
char *input(char *s)
{

    s = malloc(256);
    scanf("%255s", s);
    return s;
}
int store_books(FILE *file)
{
    struct Book b;

    fwrite(&length, sizeof(int), 1, file);
    /*for (int i = 0; i < length; i++)
    {
        b = book_list[i];
        fwrite(&b, sizeof(struct Book), 1, file);
    }*/
    fwrite(book_list, sizeof(book_list), 1, file);
return 1;
    //fclose(file);
}
struct Book create_new_book()
{
    struct Book b;

    printf("title:");

    scanf("%s", b.t);
    printf("\n");

    printf("authors");
    scanf("%s", b.a); //book title
    //scanf("%s",b.authors);
    //comma separated list of authors

    printf("\n");
    printf("Year:");
    scanf("%i", &b.year);
    printf("\n");
    printf("copies:"); // year of publication
    scanf("%i", &b.copies);
    printf("\n");
    return b;
}

int load_books(FILE *file)
{
    //check the presence of book_list file
    if (access("book_list.bin", F_OK) == 0)
    {
        file = fopen("book_list.bin", "rb");

        fread(&length, sizeof(int), 1, file);

        fread(book_list, sizeof(book_list), 1, file);
        return 1;
    }
    else
    {

        length = 0;
    }
    return 0;
    //fclose(file);
}
void display_book(struct Book b)
{
    printf("ID:%i\n", b.id);
    printf("title:%s\n", b.t);   //book title
    printf("authors:%s\n", b.a); //comma separated list of authors
    printf("year:%i\n", b.year); // year of publication
    printf("copies:%i\n", b.copies);
}
void read_booklist()
{

    for (int i = 0; i < length; i++)
    {

        display_book(book_list[i]);
    }
}
void add_book_admin(struct Book b)
{
    b.id = length;
    book_list[length] = b;
    length += 1;
}
void remove_book_admin(int id)
{
    printf("Please enter id of  book you would like to remove\n");
    scanf("%i", &id);
    if (id > length || id == length || id < 0)
    {

        printf("Invalid ID\n");
    }
    else
    {

        book_list[id].copies = 0;
        printf("Successfully removed\n");
    }
}

void admin_menu()
{
    FILE *fin;
    FILE *fout;
    char title[30];
    int year;
    int id;

    load_books(fin);

    fout = fopen("book_list.bin", "wb");

    while (1)
    {
        int choice;
        printf("Please select one of the options below\n");

        printf("1:Display books\n");
        printf("2:Add a new book\n");
        printf("3:Remove a book\n");
        printf("4:Filter book by title\n");
        printf("5:Filter book by year\n");
        printf("6:quit\n");

        scanf("%i", &choice);
        if (choice == 1)
        {
            read_booklist();
        }
        else if (choice == 2)
        {
            add_book_admin(create_new_book());
        }
        else if (choice == 3)
        {
            remove_book_admin(id);
        }
        else if (choice == 4)

        {
            printf("Please enter title\n");
            scanf("%s", title);
            find_book_by_title(title);
        }

        else if (choice == 5)
        {
            printf("please enter year\n");
            scanf("%i", &year);
            find_book_by_year(year);
        }
        else if (choice == 6)
        {
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
