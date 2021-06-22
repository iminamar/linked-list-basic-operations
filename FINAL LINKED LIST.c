#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *newNode;

void create(void);
void first(void);
void last(void);
void display(void);
int length();
void nth(void);
void delete ()
{

    int location, i = 1, len = length();
    printf("Enter location: ");
    scanf("%d", &location);
    if (location > len)
    {
        printf("invalid location !!! ");
    }
    else if (location == 1)
    {
        struct node *p = head;
        head = p->next;
        p->next = NULL;
        free(p);
    }
    else
    {
        struct node *p = head, *q;
        int i = 1;
        while (i < location - 1)
        {
            p = p->next;
            i++;
        }
        q = p->next;
        p->next = q->next;
        q->next = NULL;
        free(q);
    }
}
int main()
{
    int n = 1, choice;
    while (n == 1)
    {
        printf("--------------- MENU ---------------\n");
        printf("1. Create linked list: \n");
        printf("2. Add at first: \n");
        printf("3. Add at last: \n");
        printf("4. Add at nth node: \n");
        printf("5. Display: \n");
        printf("6. length: \n");
        printf("7. Delete linked list: \n");
        printf("------------------------------------\n");
        printf("choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            first();
            break;
        case 3:
            last();
            break;
        case 4:
            nth();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Length : %d\n", length());
            break;
        case 7:
            delete ();
            break;

        default:
            printf("invalid bro:!!\n");
            break;
        }
        printf("------------------------------------\n");
        printf("\npress 1 or 0: ");
        scanf("%d", &n);
        printf("\n------------------------------------\n");
    }

    return 0;
}

void create()
{
    int n;
    printf("how many nodes ?: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            struct node *p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = newNode;
        }
    }
}

void first()
{
    struct node *p = head;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
}
void last()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = newNode;
}

void nth()
{

    int pos, i = 1, len = length();
    printf("enter position: ");
    scanf("%d", &pos);
    if (pos > len)
    {
        printf("invalid memory !!\n");
    }
    else
    {
        struct node *p = head;
        while (i < pos)
        {
            p = p->next;
            i++;
        }

        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->next = p->next;
        p->next = newNode;
    }
}
void display()
{
    if (head == NULL)
    {
        printf("No Nodes Found !!! \n");
    }
    else
    {
        struct node *p = head;
        while (p != NULL)
        {
            printf("%d->", p->data);
            p = p->next;
        }
    }
    printf("\n");
}

int length()
{
    int count = 0;
    struct node *p = head;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}