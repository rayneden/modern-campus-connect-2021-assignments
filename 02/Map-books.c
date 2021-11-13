#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ARRAY_SIZE 30

char *hash_array[1000];

unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash%1000;
}

void add_book(){
    char book[ARRAY_SIZE];

    printf("Enter the name of the book:\n");
    scanf("\n%[^\n]s", book);
    
    hash_array[hash(book)]=book;
}

void delete_book(){
    char book[ARRAY_SIZE];
    printf("Enter the name of the book to delete:\n");
    scanf("\n%[^\n]s", book);

    if(!strcmp(hash_array[hash(book)], book)){
        free(hash_array[hash(book)]);
    } else {
        printf("\n\n?? Book not found. ??\n\n");
    }
}

void search_name(){
    char book[ARRAY_SIZE];
    printf("Enter the name of the book to search:\n");
    scanf("\n%[^\n]s", book);

    if(!strcmp(hash_array[hash(book)], book)){
        printf("\n\n!! Book Found !!\n\n");
    } else {
        printf("\n\n?? Book not found. ??\n\n");
    }
}


int main(void){
    

    int ch, del;
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
                //display(head);
                break;

        }
    } while (ch);
}