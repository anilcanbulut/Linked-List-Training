#include <stdio.h>

typedef struct person {
    int id;
    struct person *next;
}Person;

void make(Person *headptr);
void read(Person *headptr);
void insertionToBeginning(Person **headptr, int num);
void addToEnd(Person *headptr, int num);
void sorting(Person **headptr, int num);
void removing_firt_item(Person **headptr);
void removing_last_item(Person *headptr);
void remove_specific_item(Person **headptr, int num);
void find_item(Person *headptr, int item);
void reversing(Node **headptr);
void swap(Node **headptr, int x, int y);

int main() {

int i;

Person *head;
head = malloc(sizeof(Person));

make(head);
read(head);

/*insertionToBeginning(&head, 10);
printf("\nAfter adding: \n");
read(head); */

/*
printf("\nAfter adding to end: \n");
addToEnd(head, 20);
read(head); */

/*
sorting(&head,20);
printf("\nAfter sorting: \n");
read(head);
/*
printf("After removing the first element: \n");
removing(&head);
read(head); */

/*
removing_last_item(head);
printf("After removing the last item: \n");
read(head); */

/*
remove_specific_item(&head, 20);
printf("After removing the specific item: \n");
read(head); */

printf("\n");
find_item(head, 15);


return 0;
}

void make(Person *headptr) {
    int i;
    Person *iter;
    iter = headptr;

    for(i=0; i<5; i++) {
            printf("Enter the id: ");
            scanf("%d", &(iter->id));

            if(i==4) {
                iter->next = NULL;
            }else {
                iter->next = malloc(sizeof(Person));
                iter = iter->next;
            }
    }

}

void read(Person *headptr) {
    Person *iter;
    iter = headptr;

    while(iter != NULL) {
        printf("%d\n", iter->id);
        iter = iter->next;
    }

}

void insertionToBeginning(Person **headptr, int num) {

    Person *iter;
    iter = malloc(sizeof(Person));
    iter->id = num;

    iter->next = *headptr;
    *headptr = iter;


}
void addToEnd(Person *headptr, int num) {

    Person *iter;
    iter = headptr;

    while(iter->next != NULL) {
        iter = iter->next;
    }
    iter->next = malloc(sizeof(Person));
    iter->next->id = num;
    iter->next->next = NULL;

}
void sorting(Person **headptr, int num) {
    Person *current;
    Person *previous;
    Person *node;

    node = malloc(sizeof(Person));

    previous = NULL;
    current = *headptr;
    node->id = num;
    node->next = NULL;

    while(current != NULL && (num > current->id)) {
        previous = current;
        current = current->next;
    }
    if(previous == NULL) {
        node->next = *headptr;
        *headptr = node;
    }else {
        previous->next = node;
        node->next = current;
    }

}
void removing_first_item(Person **headptr) {
    Person *node;
    node = (*headptr)->next;
    free(*headptr);
    (*headptr) = node;

}
void removing_last_item(Person *headptr) {
    Person *current;
    current = headptr;

    if(current->next == NULL)
        free(current);

    while(current->next->next != NULL) {
        current = current->next;

    }
    free(current->next);
    current->next = NULL;
}
void remove_specific_item(Person **headptr, int num) {
    Person *current;
    Person *previous;
    Person *node;

    if(num == (*headptr)->id) {
        node = *headptr;
        *headptr = (*headptr)->next;
        free(node);
    }

    previous = *headptr;
    current = (*headptr)->next;

    while(current != NULL && (current->id != num)) {
        previous = current;
        current = current->next;
    }

    if(current == NULL) {
        printf("First struct is already NULL!\n");
    }else {
        node = current;
        previous->next = current->next;
        free(node);

    }

}
void find_item(Person *headptr, int item) {
    Person *iter;
    iter = headptr;
    int position = 1;

    if(iter == NULL) {
        printf("Struct is not initialized!");
    }

    while(iter != NULL) {

        if(iter->id == item) {
            printf("%d found in %d. position.\n", item, position);
            break;
        }else {
             printf("We couldn't find the item!");
             break;
        }

        iter = iter->next;
        position++;
    }

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
