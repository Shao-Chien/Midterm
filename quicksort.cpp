#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
int partition(int v[],int l,int u);
void quicksort(int v[],int a,int b);
void quickmedian(int A[],int a,int b);

int main()
{
	int i, j, k, N, *v;
	time_t T = 1 ;
	//Create Random Integers
	srand(time(&T));
	N = 10;
	v = (int*) malloc (N* sizeof(int)); // 開n個空間 
	printf("Before sorting : ");
	for(i=1;i<N;++i) // 從 N=1 開始 
	{
		v[i] = rand()%100;
		printf("%d,",v[i]);
	}
	printf("\n");
	printf("After sorting :  ");
		
    quicksort(v,0,N-1);
    for(i=0;i<N-1;++i) 
	{
		printf("%d,",v[i]);
	}
	printf("\n");
	
	quickmedian(v,0,N-1);
		
}

void quicksort(int A[],int a,int b)
{
        if(a<b)
        {
                int q;
                q = partition(A,a,b);
                quicksort(A,a,q-1);
                quicksort(A,q+1,b);
        }
}

void quickmedian(int A[],int a,int b)
{
	if(a<b)
	{
		int q;
		q = partition(A,a,b);
		if(q=(b-a-1)/2.)
		{
			printf("The median is %d .",A[q]);
		}
		else
		{
		quickmedian(A,a,q-1);
		quickmedian(A,q+1,b);
		}
	}
}

int partition(int A[],int l,int u)
{
        int i;
        i = l-1;
        for(int j=l;j<u;j++)
        {
                if(A[j]<A[u])
                {
                        i++;
                        int t = A[i];
                        A[i]=A[j];
                        A[j]=t;
                }
        }
        i++;
        int t=A[i];
        A[i]=A[u];
        A[u]=t;
		return i;
}
