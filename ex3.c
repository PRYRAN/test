#include <stdio.h>


typedef struct  {
    struct node * next;
    int val;
} node;

void print_list(node * head)
{
    node * current = head;
    while(current!=NULL)
    {
        printf("%d -> ",current->val);
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

    }
}
void insert_node(node **head, int val){
    if(*head == NULL)
    {
        *head = malloc(sizeof(node));
        (*head)->val = val;
        (*head)->next = NULL;
    }
    else
    {
        node * current = *head;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = malloc(sizeof(node));
        current = current->next;
        current->val = val;
    }


}
int main() {
    node * head;
    insert_node(&head, 5);
    insert_node(&head, 4);
    insert_node(&head, 10);
    insert_node(&head, 11);
    print_list(head);
    printf("\n");
    delete_node(&head,5);
    delete_node(&head,10);
    print_list(head);

    return 0;
}
