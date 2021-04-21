/* buffer ,size,overflow ,underflow, producer > costumer ,*/

#include <stdio.h>
#include <stdlib.h>

struct user
{
    int p;
    int producer; //1 for producer 0 for costumer -1 if completed
    int id;       //to avoid clashes
    int arvl;     // arrival time
    int bust;     //bust time
    int comp;     //completed time
};
int cpu_time = 0; //actual running time

int buffer;

void sort(struct user *s, int n) // SORTING FOR FCFS
{
    int i = 0;
    for (i; i < n - 1; i++)
    {
        int j = i + 1;
        for (j; j < n; j++)
        {
            if (s[i].arvl > s[j].arvl || (s[i].arvl == s[j].arvl && s[i].producer < s[j].producer) || (s[i].arvl == s[j].arvl && s[i].producer == s[j].producer && s[i].id > s[j].id))
            {
                struct user temp;
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}
int main()
{
    int prod_count;
    int cust_count;
    printf("buffer size:- ");
    scanf("%d", &buffer);
    printf("enter the number of producers and costumers :- \n");
    scanf("%d %d", &prod_count, &cust_count);
    struct user u[prod_count + cust_count];

    int i = 0;
    for (i = 0; i < prod_count; i++)
    {
        printf(" producer process %d : arrival time : ", i + 1);
        scanf("%d", &u[i].arvl);
        printf(" bust time :");
        scanf("%d", &u[i].bust);
        u[i].producer = 1;
        u[i].p = 1;
        u[i].id = i + 1;
        u[i].comp = -1; // -1 indicate they cant fetch  (point number 11)
    }

    for (i = 0; i < cust_count; i++)

    {
        printf(" customer process %d : arrival time : ", i + 1);
        scanf("%d", &u[i + prod_count].arvl);
        printf(" bust time :");
        scanf("%d", &u[i + prod_count].bust);
        u[i + prod_count].producer = 0;
        u[i + prod_count].id = i + 1;
        u[i + prod_count].p = 0;
        u[i + prod_count].comp = -1;
    }
    sort(u, cust_count + prod_count);
    int total = prod_count + cust_count;
    int status = 0; //buffer
    int y = 0;      //wait checker
    while (prod_count + cust_count)
    {
        /*  if (prod_count==0 && cust_count>0 && status==0 )
    {
        break; // point number 11
    }
    else if(cust_count==0 && prod_count>0 &&status==buffer)
    {
        break;
    }*/

        for (i = 0; i < total; i++)
        {
            if (u[i].producer == -1)
            {
                continue;
            }
            if ((status == 0 && u[i].producer == 0) || (status == buffer && u[i].producer == 1))
            {
                if (u[i].producer == 1)
                    printf("producer process %d is waiting due to full buffer\n", u[i].id);
                else
                    printf("consumer process %d is waiting due to empty buffer\n", u[i].id);
                continue;
            }
            if (u[i].arvl > cpu_time)
            {
                cpu_time = u[i].arvl + u[i].bust;
            }
            else
            {
                cpu_time = u[i].bust + cpu_time;
            }
            u[i].comp = cpu_time;
            if (u[i].producer)
            {
                printf("producer process %d initiated and  completed at %d\n", u[i].id, u[i].comp);
                status++;
                prod_count--;
            }
            else
            {
                printf("consumer process %d initiated and completed at %d\n", u[i].id, u[i].comp);
                status--;
                cust_count--;
            }
            u[i].producer = -1;
            y = i;
            while (y < total)
            {
                if (u[y].arvl < cpu_time && u[y].producer != -1)
                {
                    if (u[y].producer == 1)
                        printf("producer process %d waiting from time %d\n", u[y].id, u[y].arvl);
                    if (u[y].producer == 0)
                        printf("customer process %d waiting from time %d \n", u[y].id, u[y].arvl);
                }
                y++;
            }
            break;
        }
    }
    printf("+..........................................................................................................+\n");
    for (i = 0; i < total; i++)
        if (u[i].p)
        {
            if (u[i].comp == -1)
                printf("PRODUCER process %d arrived at %d   after bust time %d...couldnt complete ERROR due to buffer overflow and no consumer to consume it %d", u[i].id, u[i].arvl, u[i].bust, u[i].comp);
            else
                printf("PRODUCER process %d arrived at %d   after bust time %d... completed at time %d\n", u[i].id, u[i].arvl, u[i].bust, u[i].comp);
        }
    printf("+..........................................................................................................+\n");
    for (i = 0; i < total; i++)
        if (u[i].p == 0)
        {
            if (u[i].comp == -1)
                printf("costumer process %d arrived at %d   after bust time %d...couldnt complete ERROR due to empty buffer and no producer to produce it %d", u[i].id, u[i].arvl, u[i].bust, u[i].comp);
            else
                printf("costumer process %d arrived at %d   after bust time %d... completed at time %d\n", u[i].id, u[i].arvl, u[i].bust, u[i].comp);
        }
}
