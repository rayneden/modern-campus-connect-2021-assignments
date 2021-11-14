#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ARRAY_SIZE 30
#define MAP_SIZE 1000

typedef struct book
{
    int book_id;
    char book_name[ARRAY_SIZE];
    char book_author[ARRAY_SIZE];
} Book;

Book *map[MAP_SIZE];

//char *hash_array[1000];

void init()
{
    for (int i = 0; i < MAP_SIZE; i++)
        map[i] = NULL;
}


unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash%1000;
}

void add_book(){
    Book *book;
    book = (Book *)malloc(sizeof(Book));

    printf("Enter Book ID:\n");
    scanf("%d", &book->book_id);  

    printf("Enter Book Name and Author:\n");
    scanf("\n%[^\n]s\n", book->book_name);
    scanf("\n%[^\n]s", book->book_author);

    int key = hash(book->book_name);
    if (map[key] != NULL) {
        //collision detected
    }
    map[key] = book;
}

void delete_book(){
    Book *book;
    book = (Book *)malloc(sizeof(Book));

    char delete[ARRAY_SIZE];
    printf("Enter the name of the book to delete:\n");
    scanf("\n%[^\n]s", delete);
    
    
    int index = hash(delete);
    if (!strcmp(delete, map[index]->book_name) && map[index] != NULL){
        map[index] = NULL;
        printf("\n\n!! BOOK DELETED !!\n\n");
    } else {
        printf("\n\n?? BOOK DOES NOT EXIST ??\n\n");
    }
}

void search_name(){
    Book *book;
    book = (Book *)malloc(sizeof(Book));

    char search[ARRAY_SIZE];
    printf("Enter the name of the book to search:\n");
    scanf("\n%[^\n]s", search);

    int index = hash(search);
    if (!strcmp(search, map[index]->book_name) && map[index] != NULL){
        book = map[index];
        printf("\n!! BOOK FOUND !!\nBook: %s -- by %s\n\n", book->book_name, book->book_author);
    } else {
        printf("\n\n?? BOOK NOT FOUND ??\n\n");
    }
}

void display_books(){
    printf("Book ID -- Book Name -- Author\n\n");
    for (int i = 0; i < MAP_SIZE; i++)
    {
        if (map[i] != NULL){
            printf("%d\t--\t%s by %s\n",map[i]->book_id, map[i]->book_name, map[i]->book_author);        }
    }
}


int main(void){
    
    int ch;
    do{
        printf("BOOKS\n--------------------------\n1. Add Book\n2. Delete Book\n3. Search book by name\n4. Display Books\n0. Exit\n--------------------------\n");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                add_book();
                break;
            case 2:
                delete_book();
                break;
            case 3:
                search_name();
                break;
            case 4:
                display_books();
                break;

        }
    } while (ch);
}