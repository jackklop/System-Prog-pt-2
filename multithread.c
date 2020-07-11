#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include "multitest.h"
#define dummy(x) thread(x)


void* searchs(void *args)
{	
	int i;
	//printf("Start = %d\n", start);
	groupSize = splitSize;
	if(listSize-start < splitSize){groupSize = listSize-start;}

	for(i = start; i < start+groupSize; i++)
	{
		if(arr[i] == num)
		{
			flag = 1;
		}
		if(flag == 0){indexlocation++;}
	}

	start+=splitSize;
}

int thread(int n)
{
	// THREAD
	pthread_t thread[n];
	int i;

	for (i = 0; i < n; i++)
	{ 
		pthread_create(&thread[i], NULL, search, NULL);
   	}
	for (i = 0; i < n; i++) {
		//printf("threaded %d\n",i);
		//pthread_start(thread[i]);
      		pthread_join(thread[i], NULL);
  		//start+=splitSize;
	}
	
	void pthread_exit(void *thread);
   
	if (flag == 1){
     	 printf("Number %d is found at index %d\n", num, indexlocation);
	}
	else{
		printf("The Number %d is not present\n", num);
	}
	void pthread_exit(void *thread);

	return 0;
}