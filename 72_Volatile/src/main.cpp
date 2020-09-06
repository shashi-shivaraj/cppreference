#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <pthread.h>
#include <stdlib.h>

//the state of this variable is being changed at thread function and the main function depends on this variable to get modified.
volatile bool isDone = false; 

void* func(void *)
{
	sleep(1);
	isDone = true;
	return NULL;
}

int main()
{
	pthread_t newthread;

	int ret = pthread_create(&newthread , NULL, func, NULL);
	if(ret)
	{
		printf("pthread_create failed %d\n",ret);
		return -1;
	}

	ret = pthread_join(newthread,NULL);
	if(ret)
	{
		printf("pthread_join failed %d\n",ret);
	}

	while(!isDone) //if not declared volatile, compiler can replace this to while(true)
	{ }

	std::cout<<"OK moving on"<<std::endl;

	return 0;
}