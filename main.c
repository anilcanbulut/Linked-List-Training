#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int id;
    struct node *next;
}Node;

void push(Node **headptr, int num);
void read(Node *headptr);
void swap(Node **headptr, int x, int y);
void reversing(Node **headptr);

int main()
{

Node *head;
head = malloc(sizeof(Node));
head = NULL;

push(&head, 5);
push(&head, 4);
push(&head, 3);
push(&head, 2);
push(&head, 1);


read(head);
printf("\nAfter reversing: \n");
//swap(&head, 4, 2);
reversing(&head);
read(head);

return 0;
}
void push(Node **headptr, int num) {
    Node *new_node;
    new_node = malloc(sizeof(Node));
    new_node->id = num;

        new_node->next = (*headptr);
        (*headptr) = new_node;

}

void read(Node *headptr) {
    Node *iter;
    iter = headptr;

    while(iter != NULL) {
        printf("%d\n", iter->id);
        iter = iter->next;
    }

}
void swap(Node **headptr, int x, int y) {

    Node *prevx;
    Node *prevy;
    Node *currx;
    Node *curry;

    Node *temp;

    currx = (*headptr)->next;
    prevx = (*headptr);
    while (currx != NULL && currx->id != x) {
        prevx = currx;
        currx = currx->next;
    }

    curry = (*headptr)->next;
    prevy = (*headptr);
    while (curry != NULL && curry->id != y) {
        prevy = curry;
        curry = curry->next;
    }

       prevx->next = curry;
       prevy->next = currx;

   temp = curry->next;
   curry->next = currx->next;
   currx->next  = temp;
}
void reversing(Node **headptr) {
    Node *curr;
    Node *prev;
    Node *next;

    next = NULL;
    curr = (*headptr);
    prev = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    (*headptr) = prev;


}
