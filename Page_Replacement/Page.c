// Program to simulate Disk Scheduling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// keeps track of requests and faults
int requests, faults;
int pages[100];
int frames[99];

// function to display the page and frame table
int display(int noF, int noP)
{
    printf("Page Table\n");
    for (int i = 0; i < noP; i++)
    {
        printf("%d\n", pages[i]);
    }

    printf("Frame Table\n");
    for (int i = 0; i < noF; i++)
    {
        printf("%d\n", frames[i]);
    }
}

// scheduling using FCFS
int fcfs(int noF, int noP, int pageSize)
{
    // counters
    int frameCounter, pageCounter;

    // initialsing frames and pages
    for (int i = 0; i < noP; i++)
    {
        frames[i] = -1;
        pages[i] = -1;
    }

    display(noF, noP);

    bool loop = true;

    while (loop)
    {

        int choice;
        printf("1) Start\n2) Stop\n");
        scanf("%d", &choice);

        if (choice == 2)
        {
            loop = false;
        }

        else if (choice == 1)
        {
            int pageNumber, memOffset;
            printf("Enter the page number and word offset :: ");
            scanf("%d %d", &pageNumber, &memOffset);

            if (pageNumber > noP || memOffset > pow(2, 10) * pageSize)
            {
                printf("Page does'nt exist or Memory Offset overflow\n");
            }

            else
            {
                requests = requests + 1;
                int hit = 0;

                for (int i = 0; i < noF; i++)
                {
                    if (frames[i] == pageNumber)
                    {
                        hit = 1;
                        printf("Physical Address is :: [%d | %d]\n", i, memOffset);
                        display(noF, noP);
                        break;
                    }
                }

                if (hit == 0)
                {
                    faults = faults + 1;

                    int frameEmpty = 0;

                    for (int i = 0; i < noF; i++)
                    {
                        if (frames[i] == -1)
                        {
                            frameEmpty = 1;
                            frames[i] = pageNumber;
                            pages[pageNumber] = i;
                            printf("Physical Address :: [%d | %d]\n", i, memOffset);
                            display(noF, noP);
                            break;
                        }
                    }

                    if (frameEmpty == 0)
                    {

                        printf("%d page is going to be removed to accomodate new page\n", frames[0]);
                        pages[frames[0]] = -1;
                        for (int i = 0; i < noF; i++)
                        {
                            frames[i] = frames[i + 1];
                            pages[frames[i]]--;
                        }

                        frames[noF - 1] = pageNumber;
                        pages[pageNumber] = noF - 1;

                        printf("Physical Address :: [%d | %d]\n", 0, memOffset);
                        display(noF, noP);
                    }
                }
            }
        }

        else
        {
            printf("Wrong choice, please try again\n");
        }
    }
    return 0;
}

// driver function
int Page()
{
    // the memory sizes
    int vMemSize, pMemSize, pageSize, noF, noP;

    // taking in the inputs
    printf("Virtual Memory Size = ");
    scanf("%d", &vMemSize);

    printf("Physical Memory Size = ");
    scanf("%d", &pMemSize);

    printf("Page Size = ");
    scanf("%d", &pageSize);

    // getting the number of frames and pages
    noF = pMemSize / pageSize;
    noP = vMemSize / pageSize;

    fcfs(noF, noP, pageSize);

    printf("Total number of faults :: %d\n", faults);
    printf("Requests: %d\n", requests);
    printf("Fault ratio :: %lf\n", (double)faults / (double)requests);
    display(noF, noP);

    return 0;
}
