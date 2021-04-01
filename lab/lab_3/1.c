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



void display()
{
    struct node *tmp;
    int n = 1;

    tmp = start;
    printf("\n\nData entered on the list are :\n");

    while(tmp != NULL)
    {
        printf(" node %d : %d\n", n, tmp->num);
        n++;
        tmp = tmp->next;

    }
}



int main()
{
    int n;
    start = NULL;
    end = NULL;

    printf("Input the number of nodes : ");
    scanf("%d", &n);

    create(n);
    display();
    return 0;
}


