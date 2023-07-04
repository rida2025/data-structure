#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct linked_list {
    int value;
    struct linked_list* next;
} linkedlist;

linkedlist* creatlist(int valuex) {
    linkedlist* list = malloc(sizeof(linkedlist));
    list->value = valuex;
    list->next = NULL;
    return list;
}

void addelement(linkedlist* list, int valuex){
    if(list == NULL){
        list->value = valuex;
        list->next = NULL;
    }
    linkedlist* newnode = malloc(sizeof(linkedlist));
    newnode->value = valuex;
    newnode->next = NULL;
    
    linkedlist* current = list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newnode;
    
    printf("add element %d\n", valuex);
}


void showlist(linkedlist* list) {
    if (list == NULL) {
        printf("list is empty");
        return;
    }

    linkedlist* i = list;
    while (i != NULL) {
        printf("[value=%d]->", i->value);
        i = i->next;
    }
    printf("\n");
}

int main(void) {
    linkedlist* list = creatlist(9);
    addelement(list, 15);
    addelement(list, 20);
    addelement(list, 18);
    addelement(list, 23);
    addelement(list, 19);
    addelement(list, 20);
    showlist(list);

    linkedlist* current = list;
    linkedlist* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}