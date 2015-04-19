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
	v = (int*) malloc (N* sizeof(int)); // 開n個空間 
	for(i=1;i<N;++i) // 從 N=1 開始 
	{
		v[i] = rand()%100;
		printf("%d,",v[i]);
	}
	printf("\n");
	
	for(i=1;i<N;i++)
	{
		k = v[i];
		for(j=i-1;j>=0 && k<v[j];--j) // 當處理值小於已知序列值時,將部分已知序列右挪 
		{
			v[j+1]=v[j];
		}
		
		v[j+1]=k;//將處理直插入正確位置 
	}
	for(i=0;i<N-1;++i) //印出排序好的值 
	{
		printf("%d,",v[i]);
	}
}
