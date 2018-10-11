#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
int arr[12];
int sum=0,sum1=0,val=0,val1=0;
int fd[2];
int fd1[2];
pipe(fd);
pipe(fd1);
for(int i=0;i<12;i++)
{
	arr[i]=i;
}

int cpid=fork();
if(cpid==0)
{
	for (int j=0;j<4;j++)
	{
		sum=sum+arr[j];
	}
	write(fd[1],&sum,sizeof(sum));
	close (fd[1]);
	printf("child sum=%d",sum);
	return sum;
	
}
else{
	int cpid2=fork();
	if(cpid==0)
	{
		for (int j=4;j<8;j++)
		{
			sum=sum+arr[j];
		}
		write(fd1[1],&sum,sizeof(sum));
		close (fd1[1]);
		printf("child sum=%d",sum);
		return sum;
	
	}
	else

	{
	
	close(fd[1]);
	close(fd1[0]);
	for(int k=8;k<12;k++)
	{
		sum1=sum1+arr[k];
	}
	
	read(fd[0],&val,sizeof(val));
	read(fd1[0],&val1,sizeof(val1));
	sum1=sum1+val+val1;
	printf("parent sum=%d",sum1);
	close(fd[0]);
	close(fd1[0]);
	}

}
}	


