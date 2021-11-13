#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ARRAY_SIZE 40

struct book{
    int book_id;
    char book_name[ARRAY_SIZE];
    char book_author[ARRAY_SIZE];
    struct book *next;
};

void add_book(struct book **head){

    struct book *new_book = (struct book *)malloc(sizeof(struct book));
    struct book *last = *head;

    printf("Enter Book ID:\n");
    scanf("%d", &new_book->book_id);  

    printf("Enter Book Name and Author:\n");
    scanf("\n%[^\n]s\n", new_book->book_name);
    scanf("\n%[^\n]s", new_book->book_author);
    

    if(*head==NULL){
        *head = new_book;
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }

    last->next = new_book;
}

void delete_book(struct book **head, int del){
    struct book *temp = *head;
    struct book *prev;

    if(temp == NULL){
        return;
    }

    if(temp->book_id==del && temp->next!=NULL){
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp->book_id != del && temp!=NULL){
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp-> next;

    free(temp);
} 

void display(struct book *book){
    printf("Book ID -- Book Name -- Author\n\n");
    while (book!=NULL){
        printf("%d\t--\t%s by %s\n",book->book_id, book->book_name, book->book_author);
        book = book->next;
    }
    printf("\n");
}

void search_name(struct book **head){
    struct book *temp = *head;
    char search[ARRAY_SIZE];

    printf("\nEnter Book Name to search:\n");
    scanf("\n%[^\n]s", search);

    printf("Search Results\n------------------------\n");
    while(temp!=NULL){
        if(!strcmp(temp->book_name, search)){
            printf("%d\t--\t%s by %s\n", temp->book_id, temp->book_name, temp->book_author);
        }
        temp = temp -> next;
    }
    printf("\n\n");
}

int main(void){
    struct book *head = NULL;
    int ch, del;
    do{
        printf("BOOKS\n--------------------------\n1. Add Book\n2. Delete Book\n3. Search book by name\n4. Display Books\n0. Exit\n--------------------------\n");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                add_book(&head);
                break;
            case 2:
                printf("Enter Book ID to delete:\n");
                scanf("%d",&del);
                delete_book(&head, del);
                printf("\n-- Book Deleted --\n\n");
                break;
            case 3:
                search_name(&head);
                break;
            case 4:
                display(head);
                break;

        }
    } while (ch);

    return 0;
}
