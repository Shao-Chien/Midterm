#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i, j, k, N, *v;
	time_t T = 1 ;
	//Create Random Integers
	srand(time(&T));
	N = 10;
	v = (int*) malloc (N* sizeof(int)); // �}n�ӪŶ� 
	for(i=1;i<N;++i) // �q N=1 �}�l 
	{
		v[i] = rand()%100;
		printf("%d,",v[i]);
	}
	printf("\n");
	
	for(i=1;i<N;i++)
	{
		k = v[i];
		for(j=i-1;j>=0 && k<v[j];--j) // ��B�z�Ȥp��w���ǦC�Ȯ�,�N�����w���ǦC�k�� 
		{
			v[j+1]=v[j];
		}
		
		v[j+1]=k;//�N�B�z�����J���T��m 
	}
	for(i=0;i<N-1;++i) //�L�X�ƧǦn���� 
	{
		printf("%d,",v[i]);
	}
}
