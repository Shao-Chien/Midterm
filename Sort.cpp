#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i, j, N, *v, temp;
	time_t T = 1 ;
	//Create Random Integers
	srand(time(&T));
	N = 10;
	v = (int*) malloc (N* sizeof(int)); 
	for(i=0;i<N;++i)
	{
		v[i] = rand()%100;
		printf("%d,",v[i]);
	}
	printf("\n");
	//Bubble Sort
	//Comapre v[i] and v[j]
	//if v[i]>v[j]
	//�ѥ��ܥk,�۾F�����,���j�̩��k��
	//�̫�̤j�ȷ|�X�{�b�}�C�k��
	//�a�^�B�z�|���ƧǪ�(N-1)�Ӥ���
	for(j=1;j<N;++j)
	{
		for(i=0;i<N-1;++i)//�ѥ��ܥk �`�NN-1  
		{
			if(v[i]>v[i+1])//compare (v[0],v[1]),(v[1],v[2]),....(v[8],v[9])
			{				  //���j�̩��k�� 
				temp = v[i]; //�}�@�ӰO���� ��v[i]��i�h 
				v[i] = v[i+1];
				v[i+1] = temp;
			}
		} 
		for(i=0;i<N;++i)
		{
			printf("%d,",v[i]);
		}
		printf("\n");
	}
	return 0;
}


