#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[16];
    int value;
    struct node *next;
};

typedef struct node NODE;

struct LinkedList
{
    NODE *head;
    NODE *tail;
};

typedef struct LinkedList LINKEDLIST;

void CreateList(LINKEDLIST *list)
{
    list->head = NULL;
    list->tail = NULL;
}

NODE *CreateNode(char *name, int value)
{
    NODE *node;
    node->value = value;
    memset(node->name, 0, 16);
    if (strlen(name) < 16)
    {
        strncpy(node->name, name, strlen(name));
    }
    else
    {
        memcpy(node->name, name, 16);
    }
    node->next = NULL;
    return node;
}

NODE *searchNode(LINKEDLIST *list, int p)
{
    NODE *temp;
    for (temp = list->head; temp != NULL; temp = temp->next)
    {
        if (temp->value == p)
        {
            return temp;
        }
    }
    return NULL;
}

void addHead(LINKEDLIST *list, char* name, int value)
{
    if (list == NULL)
    {
        return;
    }
    // check exist
    if (searchNode(list, value) != NULL)
    {
        return;
    }

    NODE* node = CreateNode(name, value);

    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        node->next = list->head;
        list->head = node;
    }
}

void addTail(LINKEDLIST *list, char* name, int value)
{
    if (list == NULL)
    {
        return;
    }
    // check exist
    if (searchNode(list, value) != NULL)
    {
        return;
    }

    NODE* node = CreateNode(name, value);

    if (list->tail == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->head->next = node;
        list->head = node;
    }
}

void insertAfter(LINKEDLIST *list, char* name, int value, int otherNodeValue)
{
    if (list == NULL)
    {
        return;
    }
    // check exist
    if (searchNode(list, value) != NULL || searchNode(list, otherNodeValue) == NULL)
    {
        return;
    }

    NODE* node = CreateNode(name, value);

    if (list->tail == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        NODE *temp;
        for (temp = list->head; temp != NULL; temp = temp->next)
        {
            if (temp->value == otherNodeValue)
            {
                node->next = temp->next;
                temp->next = node;
            }
        }
    }
}

NODE *deleteNode(LINKEDLIST *list, int p)
{
    if (searchNode(list, p))
    {
        return NULL;
    }

    NODE *temp, *temp2;

    // if node is head
    if (list->head->value == p)
    {
        temp = list->head;
        list->head = list->head->next;
        return temp;
    }

    // if node is tail
    for (temp = list->head; temp != NULL; temp = temp->next)
    {
        if (temp->next->value == list->tail->value && list->tail->value == p)
        {
            temp2 = list->tail;
            list->tail = temp;
            temp->next = NULL;
            return temp2;
        }
    }

    // if node is in the middle of linked list
    for (temp = list->head; temp != NULL; temp = temp->next)
    {
        if (temp->next->value == p)
        {
            temp2 = temp->next;
            temp->next = temp->next->next;
            return temp2;
        }
    }
}

int editNode(LINKEDLIST *list, int currentValue)
{
    NODE *temp;
    int newValue;
    char newName[16];

    memset(newName, 0, 16);
    printf("Enter new value: ");
    scanf("%d", &newValue);
    if (searchNode(list, currentValue) != NULL)
    {
        return 0;
    }

    printf("Enter new name: ");
    fgets(newName, sizeof(newName), stdin);

    for (temp = list->head; temp != NULL; temp = temp->next)
    {
        if (temp->value == currentValue)
        {
            temp->value = newValue;
            if (strlen(newName) < 16)
            {
                strncpy(temp->name, newName, strlen(newName));
            }
            else
            {
                memcpy(temp->name, newName, 16);
            }
            return 1;
        }
    }
}

void displayNodeInfomation(LINKEDLIST *list, int value)
{
    NODE *node = searchNode(list, value);
    if (node == NULL)
    {
        return;
    }
    printf("Name of node: %s", node->name);
    printf("Value of node: %d", node->value);
}

void sortTheList(LINKEDLIST *list)
{
}

void main()
{
    int inputKey;
    printf("------------- Functions:\n");
    printf("1 - Add new element to list\n");
    printf("2 - Edit name of element by value\n");
    printf("3 - Delete an element from list\n");
    printf("4 - Search for specify node of list\n");
    printf("5 - Display information of list\n");
    printf("6 - Sort the list in ascending order\n");
    printf("Select a function:  ");
    printf("\n");
    LINKEDLIST *list;
    CreateList(list);
    // get input to specify function
    inputKey = getchar();
    while (1)
    {
        if (inputKey == '1')
        {
            char *name = (char *)calloc(16, sizeof(char));
            int value;
            printf("--- Add new element to list\n");
            inputKey = getchar();
            printf("1 - Add head\n");
            printf("2 - Add tail\n");
            printf("2 - Insert after specify node\n");

            printf("Enter name of node: ");
            fgets(name, sizeof(name), stdin);
            printf("Enter value of node: ");
            scanf("%d", &value);

            if (inputKey == '1')
            {
                addHead(list, name, value);
            }
            else if (inputKey == '2')
            {
                addTail(list, name, value);
            }
            else if (inputKey == '3')
            {
                int beforeValue;
                printf("Insert after node which has value of : ");
                scanf("%d", &beforeValue);
                insertAfter(list, name, value, beforeValue);
            }
        }
        else if (inputKey == '2')
        {
        }
        else if (inputKey == '3')
        {
        }
        else if (inputKey == '4')
        {
        }
        else if (inputKey == '5')
        {
        }
        else if (inputKey == '6')
        {
        }
        else
        {
            printf("\nInvalid input.\n");
        }
    }
}