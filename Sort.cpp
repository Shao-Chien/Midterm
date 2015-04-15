#include <stdio.h>
#include <stalub.h>
#include <time.h>

int main()
{
	int i, N, *v;
	//Create Random Integers
	srand(time(&t));
	N = 10;
	v = (int*) malloc (N* sizeof(int)); 
	for(i=0;i<N;++i)
	{
		v[i] = rand()%100;
		printf("%d,",v[i]);
	}
	printf("\n")
	//Bubble Sort
	//Comapre v[i] and v[j]
	//if v[i]>v[j]
	//由左至右,相鄰兩兩比較,較大者往右挪
	//最後最大值會出現在陣列右端
	//地回處理尚未排序的(N-1)個元素
	for(i=0;i<N-1;++i)//由左至右 注意N-1 
	{
		if(v[i]>v[i+1])//compare (v[0],v[1]),(v[1],v[2]),....(v[8],v[9])
		{
			temp = v[i]; //開一個記憶體 把v[i]放進去 
			v[i] = v[i+1];
			v[i+1] = temp;
		}
	} 
	return 0;
}


