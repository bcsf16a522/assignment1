#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<math.h>
#include<sys/types.h>

int data_array[1000],increment=0,MAX_size=1000,sum[10]={0};


void * sum_function(void * arg)
{
	int start=increment++;
	for(int l=(start*(MAX_size/10));l<(start+1)*(MAX_size/10);l++)
	{	
		sum[start]+=data_array[l];
	}

}

int main()
{
	for(int i=0;i<MAX_size;i++)
	{
		data_array[i]=i;
	}

	int status[10]={0},total_sum=0;
	pthread_t thread[10];
	for(int i=0;i<10;i++)
		pthread_create(&thread[i],NULL,sum_function,(void*)NULL);

	for(int i=0;i<10;i++)
		pthread_join(thread[i],(void**)NULL);
	
	for(int i=0;i<10;i++)
		total_sum+=sum[i];

	printf("\n TOTAL SUM = %d\n",total_sum);
	
	return 0;
}
