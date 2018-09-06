#include <stdio.h>


typedef struct  {
    struct node * next;
    struct node * prev;
    int val;
} node;

void print_list(node * head)
{
    node * current = head;
    while(current!=NULL)
    {
        printf("%d <-> ",current->val);
        current = current->next;
    }
}
void delete_node(node ** head, int val)
{
    if(*head==NULL)
        return;
    node * current = (*head);
    node * prev = NULL;
    if(current->val == val)
    {
        (*head) = (*head)->next;
        (*head)->prev = NULL;
    }
    else
    {
        while(current!=NULL)
        {
            if(current->val == val)
                break;
            prev = current;
            current = current->next;
        }
        if(current == NULL)
            return;
        prev->next = current->next;
        current = current->next;
        if(current == NULL)
            return;
        current->prev = prev;

    }
}
void insert_node(node **head, int val){
    if(*head == NULL)
    {
        *head = malloc(sizeof(node));
        (*head)->val = val;
        (*head)->next = NULL;
        (*head)->prev = NULL;
    }
    else
    {
        node * current = *head;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = malloc(sizeof(node));
        node * prev = current;
        current = current->next;
        current->val = val;
        current->prev = prev;
    }


}
int main() {
    node * head;
    insert_node(&head, 5);
    insert_node(&head, 4);
    insert_node(&head, 3);
    print_list(head);
    delete_node(&head,3);
    delete_node(&head,5);
    printf("\n");
    print_list(head);





    return 0;
}
