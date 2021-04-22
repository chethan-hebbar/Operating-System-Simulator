#include <stdio.h>
#include <stdlib.h>
struct reader
{
    int id;
    int arvl;
    int arvl_i; //intermidiate arvl times
    int bust;
    int bust_i; //intermediate bust time
    int cont;   //whether process completed(-1) or process not initiated(0) or process running(1)
    int comp;   //time at which it complete
};
struct writer
{
    int id;
    int arvl;
    int bust;
    int comp;
    int complete; //check if it is completed(1) or not(0)
};
int rw_time = 0; // queue time different from cpu time(original time)
int time_cpu = 0;
int rw_left = 0;                                             // processes left
struct reader *read(struct reader *RP, int readers_count) // read function allow the eligible reader to read at a time

{
    int i;
    struct reader *R = RP;
    for (i = 0; i < readers_count; i++)
    {
        if (R[i].arvl_i <= time_cpu && R[i].cont >= 0)
        {
            if (R[i].cont == 0)
                printf("reading %d at time %d\n ", R[i].id, time_cpu);
            R[i].bust_i--;
            R[i].arvl_i++;
            if (R[i].bust_i <= 0) //processs complete
            {
                rw_left--;
                R[i].cont = -1;
                R[i].arvl_i = -1;
                R[i].comp = time_cpu + 1;
                printf("                                                read %d at time %d\n", R[i].id, time_cpu + 1);
            }
            else
            {
                R[i].cont = 1; //process under reading
            }
        }
    }

    time_cpu++;
    return R;
}
struct writer *sort(struct writer *S, int n) //sorting the writer who came first NOTE reader doesnt need to sort because all may access the document
{
    int i = 0, j = i + 1;
    for (i; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (S[i].arvl > S[j].arvl)
            {
                struct writer temp = S[i];
                S[i] = S[j];
                S[j] = temp;
            }
        }
    }
    return S;
}
int RW()
{

    int readers_count;
    int writers_count;
    int i;

    printf("no.of readers:- ");
    scanf("%d", &readers_count);
    printf("no.of writers:- ");
    scanf("%d", &writers_count);
    struct reader RD[readers_count + 1];
    struct writer WT[writers_count + 1];

    for (i = 0; i < readers_count; i++)
    {
        printf("\nreader %d: arrl time and bust time :- ", i + 1);
        scanf("%d %d", &RD[i].arvl, &RD[i].bust);
        RD[i].id = i + 1;
        RD[i].cont = 0;
        RD[i].arvl_i = RD[i].arvl;
        RD[i].bust_i = RD[i].bust;
    }
    for (i = 0; i < writers_count; i++)
    {
        WT[i].id = i + 1;
        printf("\nwriter %d: arrl time and bust time :- ", i + 1);
        scanf("%d %d", &WT[i].arvl, &WT[i].bust);

        WT[i].complete = 0;
    }

    rw_left = readers_count + writers_count;
    int cpu = 0;
    //to check any process is running in cpu means if cpu is free it is zero ,then we increment the value of time
    sort(WT, writers_count);
strt:
    while (rw_left > 0)
    { //if a reader is already reading ,we cant write so we check if any the readers is continuing
        for (i = 0; i < readers_count; i++)
        {
            if (RD[i].cont == 1)
            {
                read(RD, readers_count);
                cpu++;
                goto strt;
            }

        } // we give writer first preference
        for (i = 0; i < writers_count; i++)
        {

            if (rw_time <= time_cpu && rw_time >= WT[i].arvl && WT[i].complete == 0)
            {
                printf("writing %d at time %d\n", WT[i].id, time_cpu);
                time_cpu = time_cpu + WT[i].bust;
                WT[i].complete = 1;
                WT[i].comp = time_cpu;
                cpu += WT[i].bust;
                rw_left--;
                printf("                                                wrote %d at time %d\n", WT[i].id, time_cpu);
                goto strt;
            }
        }
        for (i = 0; i < readers_count; i++)
        { //printf("4");
            if (rw_time <= time_cpu && rw_time >= RD[i].arvl_i && RD[i].cont >= 0)
            {
                //read function
                read(RD, readers_count);
                cpu++;
                goto strt;
            }
        }
        rw_time++;
        cpu--;
        if (cpu < 0)
        {
            time_cpu++;
            cpu = 0;
        }
    } //output

    for (i = 0; i < writers_count; i++)
    {
        printf("writer \"%d\" arrived at %d with %d bust time completed at %d \n", WT[i].id, WT[i].arvl, WT[i].bust, WT[i].comp);
    }
    printf("\n");
    for (i = 0; i < readers_count; i++)
    {
        printf("reader \"%d\" arrived at %d with %d bust time completed reading at %d \n", RD[i].id, RD[i].arvl, RD[i].bust, RD[i].comp);
    }
    return 0;
}
