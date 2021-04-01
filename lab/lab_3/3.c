#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *pre;
    struct node *next;
}*start, *end;


void create(int n)
{
    int i, num;
    struct node *fnNode;

    if(n >= 1)
    {
        start = (struct node *)malloc(sizeof(struct node));

        if(start != NULL)
        {
            printf("Input data for node 1 : ");
            scanf("%d", &num);

            start->num = num;
            start->pre = NULL;
            start->next = NULL;
            end = start;

            for(i=2; i<=n; i++)
            {
                fnNode = (struct node *)malloc(sizeof(struct node));
                if(fnNode != NULL)
                {
                    printf("Input data for node %d : ", i);
                    scanf("%d", &num);
                    fnNode->num = num;
                    fnNode->pre = end;
                    fnNode->next = NULL;

                    end->next = fnNode;
                    end = fnNode;
                }
                else
                {
                    printf("Memory can not be allocated.");
                    break;
                }
            }
        }
        else
        {
            printf("Memory can not be allocated.");
        }
    }
}



void display(int m)
{
    struct node *tmp;
    int n = 1;

    tmp = start;
    if (m==0)
    {
        printf("\nData entered in the list are :\n");
    }
    else
    {
        printf("\nAfter insertion the new list are :\n");
    }
    while(tmp != NULL)
    {
        printf(" node %d : %d\n", n, tmp->num);
        n++;
        tmp = tmp->next;
    }
}

void insert(int num)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->num = num;
    newnode->next = NULL;
    newnode->pre = end;
    end->next = newnode;
    end = newnode;
}

int main()
{
    int n, num1;
    start = NULL;
    end = NULL;

    printf("Input the number of nodes : ");
    scanf("%d", &n);

    create(n);
    display(0);

    printf("\nInput data for the last node : ");
    scanf("%d", &num1);

    insert(num1);
    display(1);

    return 0;
}



