#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
	//y_k = sum( x_n * w^{-kn} , n=0..N-1
	// w = cos(2*pi/N)+i*sin(2*pi/N)
	int k, n, N;
	double *y_r, *y_i, *x_r, *x_i, w_r, w_i;
	clock_t t1, t2;
	//input n
	printf ("Plese input N = ");
	scanf("%d",&N);//輸入N作為變數
	printf("N = %d\n",N);
	x_r = (double *) malloc(N*sizeof(double));
	x_i = (double *) malloc(N*sizeof(double));
	y_r = (double *) malloc(N*sizeof(double));
	y_i = (double *) malloc(N*sizeof(double));
	for(n=0;n<N;++n)
	{
		x_r[n] = n;
		x_i[n] = 0;  
	}
	t1 = clock();//開始計時 
	for(k=0;k<N;++k)
	{
		y_r[k] = 0.0;
		y_i[k] = 0.0;
		for(n=0;n<N;n++)
		{
			//w^{-k^n}
			w_r = cos(-k*n*2*M_PI/N);
			w_i = sin(-k*n*2*M_PI/N);
			y_r[k]=y_r[k]+x_r[n]*w_r - x_i[n]*w_i;
			y_i[k]=y_i[k]+x_r[n]*w_i + x_i[n]/w_r;
		}
	 } 
	 t2 = clock();//結束計時
	 printf("%f secs\n", 1.0*(t2-t1)/CLOCKS_PER_SEC) ;
	 for(n=0;n<N;++n)
	 {
	 	printf("%d : %f + %f i\n",n,y_r[n],y_i[n]);
	 }
	 return 0;
	 
}
/*int FFT(double *x_r,double *x_i, double *y_r, double *y_i, int N)
{
	int k, n;
	double *u_r,*u_i, *v_r, *v_i, w_r, w_i;
	
	u_r = (double *) malloc(N*sizeof(double));
	u_i = (double *) malloc(N*sizeof(double));
	v_r = (double *) malloc(N*sizeof(double));
	v_i = (double *) malloc(N*sizeof(double));
	for(n=0;n<N/2;n++)
	{
		u_r[n] = x_r[2*n];
		u_i[n] = x_i[2*n];
		w_r[n+ N/2] = x_r[2*n+1];
		u_i[n+ N/2] = x_i[2*n+1];
		
	}
	FFT(u_r,u_i,v_r,v_i,N/2);
	FFT(u_r+N/2, u_i+N/2, v_r+N/2, v_i+N/2, N/2);
}
*/

