#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include "multitest.h"
#define listSize 20000
#define splitSize 250

int flag = 0; //flag to indicate that item is found in the array or not
int start = 0;
int groupSize;		// size of portion of list
int smArr = 0;
int n;
int child_pid = 0;
int* arr;
int* temp;
int indexlocation = 0;
int num = 10;		


int* createArr() {
	int i;
	// Dynamically allocate memory using malloc() 
	arr = (int*)malloc(listSize * sizeof(int)); 
	
	// Get the elements of the array 
	for (i = 0; i < listSize; i++) { 
		arr[i] = i; 
	} 
/*
	for (i = 0; i < listSize; i++) { 
		printf("%d\n", arr[i]); 
	} //*/
	return 0; 
}

void shuffle ()
{	
	int i;
	int temp;
	srand(time(NULL));
	for (i = 0; i < listSize; i++){
  		int n = (rand() % (listSize)); 
		//printf("%d\n", n);		
		temp = arr[i];
		arr[i] = arr[n];
		arr[n] = temp;
	}

}

void split(int indexlocation)
{	
	int i;
	smArr = listSize/n;
	temp = (int*)malloc(smArr * sizeof(int));
	
	if(listSize-indexlocation <= listSize/n){
		smArr = listSize-indexlocation;
	}

	for (i = 0; i < smArr; i++)
	{
  		temp[i] = arr[i + indexlocation];
	}
}

//find the number of process we need
int numProcess(int x){
	int i = 0;
	int numOfProcess = 0;
	for (i = 0; x > 0; i++){
		//printf("value of x is %d\n", x);
		x = x - 250;
		numOfProcess++;
	}
	n = numOfProcess;
	return n;
}

int main()
{
	createArr();
	shuffle();

	//find the # of threads
	n = listSize/splitSize;
	if(listSize%splitSize != 0){++n;}
	printf("The Number of Threads is = %d\n", n);
	
	dummy(n);	

}

