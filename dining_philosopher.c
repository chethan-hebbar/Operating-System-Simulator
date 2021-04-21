#include <stdio.h>
#include <stdlib.h>

int time = 0;
struct user
{
    int id; //avoid deadlock
    int arvl;
    int arvl_i; // used during waiting
    int bust;
    int bust_i; // remaining bust time
    int left_hand;
    int right_hand; //right hand first
    struct user *left;
    struct user *right;
    int comp;
};

int main()
{
    int i = 0;
    int users;
    printf("no.of people");
    scanf("%d", &users);
    struct user phil[users];
    for (i = 0; i < users; i++) //input of all processes
    {
        phil[i].id = i + 1;
        phil[i].left_hand = phil[i].right_hand = 0;
        printf("enter the avrl and bust time of philosopher %d", phil[i].id);
        scanf("%d", &phil[i].arvl);
        scanf("%d", &phil[i].bust);
        phil[i].arvl_i = phil[i].arvl;
        phil[i].bust_i = phil[i].bust;
        phil[i].comp = -1;
        if (i == users - 1)
        {
            phil[i].right = &phil[0];
            phil[0].left = &phil[i];
        }
        else
        {
            phil[i].right = &phil[i + 1];
            phil[i + 1].left = &phil[i];
        }
    }
    int left = users;
    int p = 1;
atr:
    while (left) // runs until all the processes are completed
    {
        for (i = 0; i < users; i++)
        {
            if (phil[i].comp >= 0)
                continue;
            if (phil[i].comp == -1 && phil[i].arvl_i <= time)
            {
                if (phil[i].right->left_hand == 0 && phil[i].right_hand == 0)
                {
                    phil[i].right_hand = 1;
                    printf("philosopher %d has taken the right stick and checking for left stick if available \n", phil[i].id);
                }
            }
        }
        int dead = users;
        for (i = 0; i < users; i++)
        {
            if (phil[i].right_hand)
                dead--;
        }
        if (dead == 0)
        {
            printf("\ndeadend ......solving!!!! by giving  %d th stick to the philosopher 1\n", users);

            phil[0].left_hand = 1;
            phil[0].left->right_hand = 0;
            phil[0].left->comp = -1;
            phil[0].comp = 0;
        }

        for (i = 0; i < users; i++)
        {
            if (phil[i].comp >= 0 || phil[i].right_hand == 0)
                continue; //phil[i].comp==-1 && phil[i].arvl_i<=time &&

            if (phil[i].right_hand)
            {
                if (phil[i].left->right_hand == 0 && phil[i].left_hand == 0)
                {
                    phil[i].left_hand = 1;
                    phil[i].comp = 0;
                    printf("philosopher %d has picked up the left stick and right stick and ready to dine\n", phil[i].id);
                }
                else
                {
                    if (p)
                        printf("philosopher %d is waiting for the left stick till the left  philosopher to complete his/her turn\n", phil[i].id);
                }
            }
        }
        p = 0;
        for (i = 0; i < users; i++)
        {
            if (phil[i].comp < 0)
                continue;
            if (phil[i].comp == 0)
            {

                phil[i].bust_i--;
                if (phil[i].bust_i == 0)
                {
                    printf("philosopher %d has finished his job and sticks are placed back\n", phil[i].id);
                    p = 1;
                    left--;
                    phil[i].right_hand = 0;
                    phil[i].left_hand = 0;
                    phil[i].comp = time + 1;
                    //printf
                }
            }
            else if (phil[i].comp == 0)
            {
                phil[i].arvl_i++;
            }
        }
        time++;
    }
    int dead = 1;
    for (i = 0; i < users; i++)
    {
        if (phil[i].comp > 0)
            dead = 0;
        printf(" philosopher id: %d -> arrival %d bust time %d completed at  %d  \n", phil[i].id, phil[i].arvl, phil[i].bust, phil[i].comp);
    }
    if (dead)
    {
        printf("-1 in comp indicates deadend");
    }
    return 0;
}
