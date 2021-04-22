#include <stdio.h>

 
// driver function
int Bankers()
{

	int current[5][5], maximum_claim[5][5], available[5];
	int allocation[5] = {0, 0, 0, 0, 0};
	int maxres[5], running[5], safe = 0;
	int counter = 0, i, j, exec, resources, processe, k = 1;
	printf("We have 5 different resources :: R0 R1 R2 R3 R4 \n");
	printf("\nEnter number of processes: ");
    	scanf("%d", &processe);
	
	int sequence[5] = {};
	int seqCounter = 0;

    	for (i = 0; i < processe; i++) 
	{
        	running[i] = 1;
        	counter++;
    	}
 
    	printf("\nEnter number of resources :: ");
    	scanf("%d", &resources);
 
    	printf("\nEnter maximum number of resources ::");
    	for (i = 0; i < resources; i++) 
	{ 
	        scanf("%d", &maxres[i]);
    	}
 
   	printf("\nEnter allocated resources for processes:\n");
    	for (i = 0; i < processe; i++) 
	{
	        for(j = 0; j < resources; j++) 
		{
  			scanf("%d", &current[i][j]);
        	}
    	}
 
    	printf("\nEnter required resources for processes:\n");
    	for (i = 0; i < processe; i++) 
	{
        	for(j = 0; j < resources; j++) 
		{
            		scanf("%d", &maximum_claim[i][j]);
        	}
    	}
 
	printf("\nThe maximum number of resources is: ");
    	for (i = 0; i < resources; i++) 
	{
	        printf("\t%d", maxres[i]);
	}
 
    	printf("\n\nThe Allocated Resources Table:\n");
    	for (i = 0; i < processe; i++) 
	{
	        for (j = 0; j < resources; j++) 
		{
            		printf("\t%d", current[i][j]);
        	}
		printf("\n");
    	}
 
    	printf("\nThe Required Resources Table:\n");
    	for (i = 0; i < processe; i++) 
	{
        	for (j = 0; j < resources; j++) 
		{
		        printf("\t%d", maximum_claim[i][j]);
        	}
        	printf("\n");
    	}
 
    	for (i = 0; i < processe; i++) 
	{
        	for (j = 0; j < resources; j++) 
		{
            		allocation[j] += current[i][j];
        	}
    	}
 
    	printf("\nAllocated resources ::");
    	for (i = 0; i < resources; i++) 
	{
        	printf("\t%d", allocation[i]);
    	}
 
    	for (i = 0; i < resources; i++) 
	{
	        available[i] = maxres[i] - allocation[i];
	}
 
    	printf("\nAvailable resources ::");
    	for (i = 0; i < resources; i++) 
	{
        	printf("\t%d", available[i]);
    	}
    	printf("\n");
 
    	while (counter != 0) 
	{
        	safe = 0;
        	for (i = 0; i < processe; i++) 
		{
            		if (running[i]) 
			{
                		exec = 1;
                		for (j = 0; j < resources; j++) 
				{
                    			if (maximum_claim[i][j] - current[i][j] > available[j]) 
					{
                        			exec = 0;
                        			break;
                    			}
                		}
                		if (exec) 
				{
                    			printf("\nProcess%d is executing\n", i + 1);
								sequence[seqCounter] = i + 1;
								seqCounter++;
                    			running[i] = 0;
                    			counter--;
                    			safe = 1;
 
                    			for (j = 0; j < resources; j++) 
					{
                        			available[j] += current[i][j];
                    			}
			                break;
                		}
            		}
        	}
        	if (!safe) 
		{
            		printf("\nThe system is in an unsafe state.\n");
            		break;
        	} 
		else 
		{
            		printf("\nThe system is in a safe state");
					printf("\nThe safe sequence :: ");

					for(int i = 0; i < processe; i++){
						printf("P%d ", sequence[i]);
					}

            		printf("\nFinal available resources ::");
 
            		for (i = 0; i < resources; i++) 
			{
                		printf("\t%d", available[i]);
            		}
 
		        printf("\n");
        	}
    	}
    	return 0;
}