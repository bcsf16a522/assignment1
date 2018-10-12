#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
int array[1000];
int child_sum=0,Parent_sum=0,val=0,val1=0,val2=0,val3=0,val4=0,val5=0,val6=0,val7=0,val8=0,val9=0;
int fd[2],fd1[2],fd2[2],fd3[2],fd4[2],fd5[2],fd6[2],fd7[2],fd8[2],fd9[2];
pipe(fd),pipe(fd1),pipe(fd2),pipe(fd3),pipe(fd4),pipe(fd5),pipe(fd6),pipe(fd7),pipe(fd8),pipe(fd9);

for(int i=0;i<1000;i++)
{
	array[i]=i;
}

int cpid=fork();
if(cpid==0)
{
	for (int j=100;j<200;j++)
	{
		child_sum=child_sum+array[j];
	}

	write(fd[1],&child_sum,sizeof(child_sum));
	close (fd[1]);
	//printf("child2 sum=%d",sum);
	return child_sum;
	
}
else
{
	int cpid2=fork();
	if(cpid2==0)
	{	close(fd[1]);
		for (int j=200;j<300;j++)
		{
			child_sum=child_sum+array[j];
		}
		write(fd1[1],&child_sum,sizeof(child_sum));
		close (fd1[1]);
		//printf("child1 sum=%d",sum);
		return child_sum;
	
	}
	else
	{
		int cpid3=fork();
		if(cpid3==0)
		{	
			close(fd1[1]);
			for (int j=300;j<400;j++)
			{
				child_sum=child_sum+array[j];
			}
			write(fd2[1],&child_sum,sizeof(child_sum));
			close (fd2[1]);
			//printf("child1 sum=%d",sum);
			return child_sum;
	
		}
		
		else
		{
			int cpid4=fork();
			if(cpid4==0)
			{
				close(fd2[1]);
				for (int j=400;j<500;j++)
				{
					child_sum=child_sum+array[j];
				}
				write(fd3[1],&child_sum,sizeof(child_sum));
				close (fd3[1]);
				//printf("child1 sum=%d",sum);
				return child_sum;
			}
			else
			{
				int cpid5=fork();
				if(cpid5==0)
				{
					close(fd3[1]);
					for (int j=500;j<600;j++)
					{
						child_sum=child_sum+array[j];
					}
					write(fd4[1],&child_sum,sizeof(child_sum));
					close (fd4[1]);
					//printf("child1 sum=%d",sum);
					return child_sum;

				}
				else
				{
					int cpid6=fork();
					if(cpid6==0)
					{
						close(fd4[1]);
						for (int j=600;j<700;j++)
						{
							child_sum=child_sum+array[j];
						}
						write(fd5[1],&child_sum,sizeof(child_sum));
						close (fd5[1]);
						//printf("child1 sum=%d",sum);
						return child_sum;

					}
					else
					{
						int cpid7=fork();
						if(cpid7==0)
						{
							close(fd5[1]);
							for (int j=700;j<800;j++)
							{
								child_sum=child_sum+array[j];
							}
							write(fd6[1],&child_sum,sizeof(child_sum));
							close (fd6[1]);
							//printf("child1 sum=%d",sum);
							return child_sum;
						}
						else
						{
							int cpid8=fork();
							if(cpid8==0)
							{
								close(fd6[1]);
								for (int j=800;j<900;j++)
								{
									child_sum=child_sum+array[j];
								}
								write(fd7[1],&child_sum,sizeof(child_sum));
								close (fd7[1]);
								//printf("child1 sum=%d",sum);
								return child_sum;			
							}
							else
							{	
								int cpid9=fork();
								if(cpid9==0)
								{
									close(fd7[1]);
									for (int j=900;j<1000;j++)
									{
										child_sum=child_sum+array[j];
									}
									write(fd8[1],&child_sum,sizeof(child_sum));
									close (fd8[1]);
									//printf("child1 sum=%d",sum);
									return child_sum;

								}
								else
								{
									close(fd[1]);						
									close(fd1[1]);
									close(fd2[1]);
									close(fd3[1]);
									close(fd4[1]);
									close(fd5[1]);
									close(fd6[1]);
									close(fd7[1]);
									close(fd8[1]);
									close(fd9[1]);

									for (int k=0;k<100;k++)
									{	
										Parent_sum=Parent_sum+array[k];
									}
									read(fd[0],&val,sizeof(val));
									read(fd1[0],&val1,sizeof(val1));
									read(fd2[0],&val2,sizeof(val2));
									read(fd3[0],&val3,sizeof(val3));
									read(fd4[0],&val4,sizeof(val4));
									read(fd5[0],&val5,sizeof(val5));
									read(fd6[0],&val6,sizeof(val6));
									read(fd7[0],&val7,sizeof(val7));
									read(fd8[0],&val8,sizeof(val8));
									read(fd9[0],&val9,sizeof(val9));
										
									Parent_sum=Parent_sum+val+val1+val2+val3+val4+val5+val6+val7+val8+val9;
										
									printf("parent sum=%d",Parent_sum);
									return Parent_sum;
								}			
							}
						}
					}
				}				
			}
		}
	}
}
}


	


