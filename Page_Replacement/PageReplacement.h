#include<stdio.h>

// global vars
int pn,nf; // number of frames and number of pages
int in[100];    // sequence of pages
int p[50];      // frames
int hit=0;      // hit
int i,j,k;      // loop control variables
int pgfaultcnt=0;   // number of page faults


// inputting data function
int getData()
{
    printf("Enter length of page reference sequence: ");
    scanf("%d",&pn);
    printf("Enter the page reference sequence:\n");
    for(i=0; i<pn; i++)
        scanf("%d",&in[i]);
    printf("Enter no of frames:");
    scanf("%d",&nf);

    return 0;
}

// initializing global vars
int initialize()
{
    pgfaultcnt = 0;
    for(i = 0; i < nf; i++){
        p[i] = 9999;
    }

    return 0;
}

// check for hit
int isHit(int data)
{
    hit = 0;
    for(j = 0; j < nf; j++)
    {
        if(p[j] == data)
        {
            hit = 1;
            break;
        }

    }

    return hit;
}

// getting the index of frame
int getHitIndex(int data)
{
    int hitind;
    for(k = 0; k < nf; k++)
    {
        if(p[k] == data)
        {
            hitind = k;
            break;
        }
    }
    
    return hitind;
}


int dispPages()
{
    for(k = 0; k < nf; k++)
    {
        if(p[k] != 9999)
            printf(" %d", p[k]);
    }

    return 0;
}

int dispPgFaultCnt()
{
    printf("\nTotal no of page faults:%d\n", pgfaultcnt);
    printf("Page fault ratio = %lf\n", (double)pgfaultcnt / (double)pn);
    return 0;
}

// FIFO algorithm
int fifo()
{
    initialize();
    for(i = 0; i < pn; i++)
    {
        printf("\nFor %d :", in[i]);

        if(isHit(in[i]) == 0)
        {
            // just shift the entries by 1 to get rid of first entry
            for(k = 0; k < nf - 1; k++)
                p[k] = p[k+1];

            // and then add the new page
            p[k] = in[i];
            pgfaultcnt++;
            dispPages();
        }

        else
            printf("No page fault");
    }

    dispPgFaultCnt();

    return 0;
}


// optimal replacement
int optimal()
{
    initialize();
    int near[50];
    for (i = 0; i < pn; i++)
    {

        printf("\nFor %d :", in[i]);

        if (isHit(in[i]) == 0)
        {
            int frameEmpty = 1;
            for (int k = 0; k < nf; k++)
            {
                if (p[k] == 9999)
                {
                    p[k] = in[i];
                    dispPages();
                    frameEmpty = 0;
                    pgfaultcnt++;
                    break;
                }
            }

            if (frameEmpty)
            {

                for (j = 0; j < nf; j++)
                {
                    int pg = p[j];
                    int found = 0;
                    for (k = i; k < pn; k++)
                    {
                        if (pg == in[k])
                        {
                            near[j] = k;
                            found = 1;
                            break;
                        }
                        else
                            found = 0;
                    }
                    if (!found)
                        near[j] = 9999;
                }
                int max = -9999;
                int repindex;
                for (j = 0; j < nf; j++)
                {
                    if (near[j] > max)
                    {
                        max = near[j];
                        repindex = j;
                    }
                }
                p[repindex] = in[i];
                pgfaultcnt++;

                dispPages();
            }
        }
        else
            printf("No page fault");
    }
    dispPgFaultCnt();

    return 0;
}

// most recently used page algorithm
int mru()
{
    initialize();

    int most[50];
    for(i = 0; i < pn; i++)
    {

        printf("\nFor %d :", in[i]);

        // if it is not a hit
        if(isHit(in[i]) == 0)
        {
            // store the earliest occuring page already in frame using least[]
            for(j = 0; j < nf; j++)
            {
                int pg = p[j];
                int found = 0;
                for(k = i-1; k >= 0; k--)
                {
                    if(pg == in[k])
                    {
                        most[j] = k;
                        found = 1;
                        break;
                    }
                    else
                        found = 0;
                }
                if(!found)
                    most[j] = 9999;
            }

            // getting the page to be replaced
            int max = -1;
            int repindex;

            for(j = 0; j < nf; j++)
            {
                if(most[j] > max)
                {
                    max = most[j];
                    repindex = j;   // index of the least recently used page
                }
            }
            p[repindex] = in[i];
            pgfaultcnt++;

            dispPages();
        }

        else
            printf("No page fault!");
    }

    dispPgFaultCnt();
    return 0;
}


// least recently used page algorithm
int lru()
{
    initialize();

    int least[50];
    for(i = 0; i < pn; i++)
    {

        printf("\nFor %d :", in[i]);

        // if it is not a hit
        if(isHit(in[i]) == 0)
        {
            // store the earliest occuring page already in frame using least[]
            for(j = 0; j < nf; j++)
            {
                int pg = p[j];
                int found = 0;
                for(k = i-1; k >= 0; k--)
                {
                    if(pg == in[k])
                    {
                        least[j] = k;
                        found = 1;
                        break;
                    }
                    else
                        found = 0;
                }
                if(!found)
                    least[j] = -9999;
            }

            // getting the page to be replaced
            int min = 9999;
            int repindex;

            for(j = 0; j < nf; j++)
            {
                if(least[j] < min)
                {
                    min = least[j];
                    repindex = j;   // index of the least recently used page
                }
            }
            p[repindex] = in[i];
            pgfaultcnt++;

            dispPages();
        }

        else
            printf("No page fault!");
    }

    dispPgFaultCnt();
    return 0;
}


// driver function
int PAGE()
{
    int choice;
    while(1)
    {
        printf("Page Replacement Algorithms\n1.Enter data\n2.FIFO\n3.Optimal\n4.LRU\n5.MRU\n6.Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            getData();
            break;

        case 2:
            fifo();
            break;

        case 3:
            optimal();
            break;

        case 4:
            lru();
            break;

        case 5:
            mru();
            break;

        default:
            return 0;
            break;
        }
    }
}
