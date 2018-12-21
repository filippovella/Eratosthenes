#include <stdio.h>
#include <time.h>

#define VALUE 1000001
int main()
{

	unsigned long N;
	unsigned long i,step,c;
	int cont =1;
	int check=0;
	int p;
  char vect[ VALUE ]={0};

  clock_t c_0,c_1;
  time_t  t_0,t_1;
    
	double delta_c_1,delta_t_1;
	N=VALUE;

	do
	{
		printf("Input N (between 2 and %lu)\n",(unsigned long)VALUE-1);
		check=scanf("%lu",&N);
		if( check<1) while( ( c=getchar())!='\n');
	}	
	while(N<=1 || N>= VALUE || check <= 0  );
			
	c_0=clock();
  t_0=time(NULL);
  			
	i=2;
	while( i  <= N )
	{
		if(vect[i]==1)
		{
			step = i+i;
			while( step <= N)
			{
				vect[step]=1;
				step+=i;
			}
		}	
		i++;		
	}
	
	c_1=clock();
  t_1 = time(NULL);
    
	delta_t_1=(double)(t_1-t_0);
  delta_c_1=(double)(c_1-c_0);
	   
	printf("The prime numbers between 1 and %lu are:\n", N);
	p=1;
	for(i=1;i<=N;i++)
	{
		if(!vect[i])
		{	
			printf("%10lu",i);
			if(!(p%7))
				printf("\n");

			p++;
		}
	}
  
  printf("\n");

  printf("%4s = %15e\n","Time",  delta_t_1);
  printf("%4s = %15f\n","CPU",  delta_c_1/CLOCKS_PER_SEC);

  return 0;
}
