#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// global variables
int givenN;
int n;
int size;
int unused_space;
int max_part;
int partitions[50];
int processes[50];
int pSizes[50];
int nextCounter = 0;

// worst fit Algorithm
int worst_fit(){

  int pId;
  printf("Enter the process ID:: ");
  scanf("%d", &pId);

  if(pId < 0 || pId > 49){
    printf("Wrong ID\n");
    return 0;
  }

  printf("Enter the process size :: ");
  scanf("%d", &pSizes[pId]);

  if(max_part < pSizes[pId]){
    printf("Process cannot be accomodated as it exceeded maximum parition size\n");
    return 0;
  }

  int worstId = -1, worstSize = -1;
  bool intFrag = false;

  for(int i = 0; i <= n; i++){

    bool notFree = false;

    for(int j = 0; j < 50; j++){

      if(processes[j] == i){
        notFree = true;
        if(partitions[i] - pSizes[j] >= pSizes[pId]){
          intFrag = true;
          break;
        }
      }
    }

    if(notFree == false){
      if(pSizes[pId] <= partitions[i]){

        if(worstSize < partitions[i] - pSizes[pId]){

          worstSize = partitions[i] - pSizes[pId];
          worstId = i;
        }
      }
    }
  }

  if(worstId == -1){

    if(intFrag == true){
      printf("Internal Fragmentation for process %d\n", pId);
    }

    else if(pSizes[pId] <= unused_space){
      printf("External Fragmentation for process %d\n", pId);
    }

    else{
      printf("Process size is larger than all available partitions\n");
    }
  }

  else{
    printf("Process %d can be inserted at partition %d\n", pId, worstId);
    processes[pId] = worstId;
  }

  return 0;
}

// best fit algorithm
int best_fit(){

  int pId;
  printf("Enter the process ID:: ");
  scanf("%d", &pId);

  if(pId < 0 || pId > 49){
    printf("Wrong ID\n");
    return 0;
  }

  printf("Enter the process size :: ");
  scanf("%d", &pSizes[pId]);

  if(max_part < pSizes[pId]){
    printf("Process cannot be accomodated as it exceeded maximum parition size\n");
    return 0;
  }

  int bestId = -1, bestSize = 9999;
  bool intFrag = false;

  for(int i = 0; i <= n; i++){

    bool notFree = false;

    for(int j = 0; j < 50; j++){

      if(processes[j] == i){
        notFree = true;
        if(partitions[i] - pSizes[j] >= pSizes[pId]){
          intFrag = true;
          break;
        }
      }
    }

    if(notFree == false){
      if(pSizes[pId] <= partitions[i]){

        if(bestSize > partitions[i] - pSizes[pId]){

          bestSize = partitions[i] - pSizes[pId];
          bestId = i;
        }
      }
    }
  }

  if(bestId == -1){

    if(intFrag == true){
      printf("Internal Fragmentation for process %d\n", pId);
    }

    else if(pSizes[pId] <= unused_space){
      printf("External Fragmentation for process %d\n", pId);
    }

    else{
      printf("Process size is larger than all available partitions\n");
    }
  }

  else{
    printf("Process %d can be inserted at partition %d\n", pId, bestId);
    processes[pId] = bestId;
  }

  return 0;
}

// first fit
int first_fit(){

  int pId;
  printf("Enter the process ID:: ");
  scanf("%d", &pId);

  if(pId < 0 || pId > 49){
    printf("Wrong ID\n");
    return 0;
  }

  printf("Enter the process size :: ");
  scanf("%d", &pSizes[pId]);

  if(max_part < pSizes[pId]){
    printf("Process cannot be accomodated as it exceeded maximum parition size\n");
    return 0;
  }

  int firstId = -1;
  bool intFrag = false;

  for(int i = 0; i <= n; i++){

    bool notFree = false;

    for(int j = 0; j < 50; j++){

      if(processes[j] == i){
        notFree = true;
        if(partitions[i] - pSizes[j] >= pSizes[pId]){
          intFrag = true;
          break;
        }
      }
    }

    if(notFree == false){
      if(pSizes[pId] <= partitions[i]){

        firstId = i;
        break;
      }
    }
  }

  if(firstId == -1){

    if(intFrag == true){
      printf("Internal Fragmentation for process %d\n", pId);
    }

    else if(pSizes[pId] <= unused_space){
      printf("External Fragmentation for process %d\n", pId);
    }

    else{
      printf("Process size is larger than all available partitions\n");
    }
  }

  else{
    printf("Process %d can be inserted at partition %d\n", pId, firstId);
    processes[pId] = firstId;
  }

  return 0;
}

// next fit algorithm
int next_fit(){

  int pId;
  printf("Enter the process ID:: ");
  scanf("%d", &pId);

  if(pId < 0 || pId > 49){
    printf("Wrong ID\n");
    return 0;
  }

  printf("Enter the process size :: ");
  scanf("%d", &pSizes[pId]);

  if(max_part < pSizes[pId]){
    printf("Process cannot be accomodated as it exceeded maximum parition size\n");
    return 0;
  }

  int nextId = -1;
  bool intFrag = false;

  int cycle = 0;
  printf("Counter is %d and Number of partitions = %d", nextCounter, n);
  for(int i = nextCounter; i <= n; i++){

    bool notFree = false;
    printf("Entered the loop\n");

    for(int j = 0; j < 50; j++){

      if(processes[j] == i){
        printf("Partition %d is full with process %d\n", i, j);
        notFree = true;
        if(partitions[i] - pSizes[j] >= pSizes[pId]){
          intFrag = true;
          break;
        }
      }
    }

    if(notFree == false){
      printf("Partition %d is free\n", i);

      if(pSizes[pId] <= partitions[i]){
        printf("Partition %d can hold process\n", i);
        nextId = i;
        
        if(nextCounter == n){
          printf("Counter is updated to 0\n");
          nextCounter = 0;
        }

        else{
          printf("Counter updated to %d\n", i);
          nextCounter = i + 1;
        }
        

        break;
      }
    }

    if(i == n && cycle == 0){
      cycle = 1;
      i = 0;
    }
  }

  if(nextId == -1){

    if(intFrag == true){
      printf("Internal Fragmentation for process %d and counter = %d\n", pId, nextCounter);
    }

    else if(pSizes[pId] <= unused_space){
      printf("External Fragmentation for process %d and counter = %d\n", pId, nextCounter);
    }

    else{
      printf("Process size is larger than all available partitions and counter = %d\n", nextCounter);
    }
  }

  else{
    printf("Process %d can be inserted at partition %d and counter = %d\n", pId, nextId, nextCounter);
    processes[pId] = nextId;
  }

  return 0;
}


// delete
int delete(){
  int pId;
  printf("Enter the process ID :: ");
  scanf("%d", &pId);

  if(pId < 0 || pId > 49){
    printf("Wrong ID\n");
    return 0;
  }

  processes[pId] = -1;
  return 0;
}

// display
int display(){
  for(int i = 0; i < 50; i++){
    if(processes[i] != -1){
      printf("Process %d :: Partition %d\nInternal Fragmentation :: %d\n", i, processes[i], partitions[processes[i]] - pSizes[i]);
    }
  }
  return 0;
}

// driver function
int driver_mft(){

  printf("Enter the number of partitions :: ");
  scanf("%d", &givenN);

  printf("Enter total size :: ");
  scanf("%d", &size);

  int sum = 0;

  for(n = 0; n < 50; n++){

    if(n > givenN || sum >= size){
      printf("Invalid partition size or size exceeded!\n");
      --n;
      break;
    }

    else{
      printf("Enter the size of Partition %d :: ", n);
      scanf("%d", &partitions[n]);

      if(partitions[n] > (size - sum)){
        printf("Unused space created\n");
        unused_space = size - sum;
        break;
      }

      sum += partitions[n];

      if(max_part < partitions[n]){
        max_part = partitions[n];
      }
    }
  }

  for(int i = 0; i < 50; i++){
    processes[i] = -1;
  }


  // switch case
  int choice = 1;
  while(choice != 5){

    printf("1)First-Fit\n2)Best-Fit\n3)Worst-Fit\n4)Next-Fit\n5)Stop\n");
    scanf("%d", &choice);

    int control = 0;
    switch(choice){
      case(1):
  
        while(control != 4){
          printf("1)Insert\n2)Delete\n3)Display\n4)Stop\n");
          scanf("%d", &control);

          switch(control){
             case 1:
              first_fit();
              break;
            
            case 2:
              delete();
              break;

            case 3:
              display();
              break;
            
            default:
              for(int i = 0; i < 50; i++){
                processes[i] = -1;
              }
              break;
          }
        }

      case(2):
        while(control != 4){
          printf("1)Insert\n2)Delete\n3)Display\n4)Stop\n");
          scanf("%d", &control);

          switch(control){
             case 1:
              best_fit();
              break;
            
            case 2:
              delete();
              break;

            case 3:
              display();
              break;
            
            default:
              for(int i = 0; i < 50; i++){
                processes[i] = -1;
              }
              break;
          }
        }

      case(3):
        while(control != 4){
          printf("1)Insert\n2)Delete\n3)Display\n4)Stop\n");
          scanf("%d", &control);

          switch(control){
             case 1:
              worst_fit();
              break;
            
            case 2:
              delete();
              break;

            case 3:
              display();
              break;
            
            default:
              for(int i = 0; i < 50; i++){
                processes[i] = -1;
              }
              break;
          }
        }

      case(4):
        while(control != 4){
          printf("1)Insert\n2)Delete\n3)Display\n4)Stop\n");
          scanf("%d", &control);

          switch(control){
             case 1:
              next_fit();
              break;
            
            case 2:
              delete();
              break;

            case 3:
              display();
              break;
            
            default:
              for(int i = 0; i < 50; i++){
                processes[i] = -1;
              }
              nextCounter = 0;
              break;
          }
        }

      default:
        break;
    }
  }

  return 0;
}