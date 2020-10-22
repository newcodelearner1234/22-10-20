#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

void *table(int n);

pthread_t phil[5];
pthread_mutex_t chop[5];

int main()
{
	int i,j;
	void *msg;

	printf("\n Avatansh Awasthi 1947208");
	printf("\n Program to demonstrate the stages of thnking,eating and finishing of food by a philosopher in the dining philosopher problem.\n");

	for(i=1;i<=5;i+=1)
	{
		j=pthread_mutex_init(&chop[i],NULL);

		if(j==-1)
		{
			printf("\n Mutex initialisation failed !!!");
			exit(1);
		}
	}

	for(i=1;i<=5;i+=1)
	{
		j=pthread_create(&phil[i],NULL,(void *)table,(int *)(intptr_t)i);

		if(j!=0)
		{
			printf("\n Thread creation error \n");
			exit(1);
		}
	}

	for(i=1;i<=5;i+=1)
	{
		j=pthread_join(phil[i],&msg);

		if(j!=0)
		{
			printf("\n Thread join failed");
			exit(1);
		}
	}

	for(i=1;i<=5;i+=1)
	{
		j=pthread_mutex_destroy(&chop[i]);

		if(j!=0)
		{
			printf("\n Mutex was destroyed");
			exit(1);
		}
	}

return 0;
}

void *table(int n)
{
	printf("\n Philosopher %d is thinking",n);
	pthread_mutex_lock(&chop[n]);
	pthread_mutex_lock(&chop[(n+1)%5]);
	printf("\n Philosopher %d is eating",n);

	sleep(5);

	pthread_mutex_unlock(&chop[n]);
	pthread_mutex_unlock(&chop[(n+1)%5]);
	printf("\n Philosopher %d has finished eating",n);
}


