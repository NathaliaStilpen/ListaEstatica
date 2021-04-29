#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct dataNode{
    int id;
}DataNode;


typedef struct node{
    DataNode data;
    struct node* next;
}Node;


typedef struct list {
    int size;
    Node* head;
}List;

List* creatList();
void push(List* list, DataNode data);
void printList(List* list);
void pop(List* list);
bool isEmpty(List* list);
Node* atPos(List* list, int index);
int indexOf(List* list, Node* node);

List* creatList()
{
    List* list = (List*) malloc(sizeof(List));

    list -> size = 2;
    list -> head = NULL;

    return list;
}

void push(List* list, DataNode data)
{
    Node* node = (Node*) malloc(sizeof(Node));

    node -> data = data;
    node -> next = list -> head;
    list -> head = node;
    list -> size++;

}

void printList(List* list){

    if (isEmpty(list))
    {
         printf("Lista vazia\n");
         return;
    }

    Node* pointer = list ->head;

    while(pointer != NULL)
    {
        printf("%d ", pointer -> data.id);
        pointer = pointer -> next;
    }

    printf("\n");

}


bool isEmpty(List* list)
{
    return(list -> size == 0);
}

void pop(List* list)
{
    if(!isEmpty(list))
    {
        Node* pointer = list->head;
    list -> head = pointer -> next;
    free(pointer);
    list -> size--;
    }
}

Node* atPos(List* list, int index)
{
    if(index >= 0 && index < list -> size)
    {
        Node* node = list -> head;

        int i;
        for (i = 0; i < index; i++)
            node = node -> next;

        return node;
    }

    printf("Indice invalido");
    return NULL;
}

int indexOf(List* list, Node* node)
{
    if(node != NULL)
    {
        Node* pointer = list -> head;

        int index = 0 ;
        while(pointer != node && pointer != NULL)
        {
               pointer = pointer -> next;
               index++;
        }

        if (pointer != NULL)
        return index;
    }

    printf("No não pertencente a lista\n");
    return -1;
}

int main()
{
    List* l = creatList();

    DataNode data;
    data.id = 5;

    push(l, data);

    data.id = 9;
    push(l, data);



    printList(l);

    Node* node = (Node*) malloc(sizeof(Node));
    printf("%d", indexOf(l, node));



}
