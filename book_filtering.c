#include <stdio.h>
#include <string.h>
#include "book_management.h"
//finds books with a given title.
//returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the
//provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
//array is the null pointer.
//struct BookArray lib;
int length;
struct Book book_list[30];
struct BookArray find_book_by_title(const char *title)
{
    struct BookArray b;
    b.length = 0;

    int ctr = 0;
    for (int i = 0; i <length; i++)
    {

        if (strcmp(title, book_list[i].t) == 0)
        {   display_book(book_list[i]);
            //b.array[ctr++] = book_list[i];
        }
    }
    b.length = ctr;
    return b;
}
int isequal(char *sstr, char *lstr)
{   char *token = strtok(sstr, ",");
    char authors[10][10];
    int ctr = 0;
    while (token != NULL)
    {
        strcpy(authors[ctr++], token);
        //printf(" %s\n", authors[ctr-1]); //printing each token
        token = strtok(NULL, ",");
    }
    int flag = 0;
    for (int i = 0; i < ctr; i++)
    {
        if (strstr(lstr, authors[i])==NULL)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        printf("not equual\n");
    }
    else{
        printf("equal\n");



    }
    return flag;
}

//finds books with the given authors.
//returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the
//provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
//array is the null pointer.
struct BookArray find_book_by_author(const char *author)
{   struct BookArray b;




}

//finds books published in the given year.
//returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the
//provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
//array is the null pointer.
struct BookArray find_book_by_year(unsigned int year)
{

    struct BookArray b;
    b.length = 0;

    int ctr = 0;
    for (int i = 0; i <length; i++)
    {

        if (year == book_list[i].year)
        {display_book(book_list[i]);

            //b.array[ctr++] = book_list[i];
        }
    }
    //b.length = ctr;
    return b;
}
/*int main()
{
    //printf("%i",strcmp(x,y));
    char *string = "Robert.s,J.K rowling";
    char *y="janam";
printf("%i",strcmp(y,"janam"));    

//printf("%i",isequal(y,string));
}*/
