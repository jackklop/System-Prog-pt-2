#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <math.h>
#include "multitest.h"
//#define dummy(x) proc(x)
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

int search()
{	
	int i;
	for(i = 0; i < smArr; i++){
		if(temp[i] == num){
			return i + indexlocation;
		}
	}

	return -1;
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



int method(int n)
{

	// PROCESS
	while(n>0)
	{
		//check if child
		if(child_pid == 0)
		{
			//printf("forked\n");
			child_pid = fork();
		}
		else
		{
			break;
		}
		
		n--;
		indexlocation = indexlocation + listSize/n;
	}
	
	split(indexlocation);
	int index = search();
	
	int status,i;
	for (i = 0; i < n; i++){
		wait(&status);
	}

	//if found equal
	if(index != -1){
		printf("The number is at %d at index %d\n", num, index);
	}
	return 0;
}