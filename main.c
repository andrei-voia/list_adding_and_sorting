#include <stdio.h>
#include <stdlib.h>

typedef struct test
{
    int number;
    struct nod *next;
} nod;


nod *start = NULL;
nod *end = NULL;
nod *node;


void create(int x)
{
    nod *p;
    p = (nod*)malloc(sizeof(nod));

    if(p == NULL)
    {
        printf("EROARE");
    }

    else
    {
        p->number = x;
        p->next = NULL;

        if(start == NULL)start = p;
        if(end == NULL)end = p;
        else
        {
            end->next = p;
            end = p;
        }
    }
}


void sort()
{
    int repeat = 1;
    nod *p;
    nod *x;
    nod *before;

    while(repeat)
    {
        repeat = 0;
        x = start;
        before = NULL;

        for(p = start->next; p!=NULL; p = p->next)
        {
            if(x->number > p->number)
            {
                if(before != NULL) before->next = p;
                else start = p;

                x->next = p->next;
                p->next = x;

                repeat = 1;
            }

            before = x;
            x = p;
        }
    }
}


void show()
{
    printf("\n");

    nod *p;
    for(p = start; p!=NULL; p = p->next)
    {
        printf("%d ",p->number);
    }
}


int main()
{
    printf("Hello world!\n");

    create(4);
    create(3);
    create(2);
    create(1);
    show();

    sort();
    show();

    return 0;
}
