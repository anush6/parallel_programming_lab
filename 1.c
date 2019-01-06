#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

void main() {
/* Note: only one thread should the code defined in section clause, hence by printing the thread id inside
sections when can find out which thread is executing the section*/
    int a[10000],b[10000],c[10000],d[10000],i;
    for(i=0;i<10000;i++)
        a[i] = b[i] = i*10;
    #pragma omp parallel num_threads(8)
    {
        int tid = omp_get_thread_num();
        int x;
        #pragma omp sections
        {
        	#pragma omp section
        	{
        	    printf("Thread no executing section 1 %d \n",omp_get_thread_num());
        	    for(x=0;x<10000;x++) {
    	            c[x] = a[x] + b[x];
    	        }
        	}
        	#pragma omp section
        	{
        	    printf("Thread no executing section 2 %d \n",omp_get_thread_num());
        	    for(x=0;x<10000;x++) {
    	            d[x] = a[x] * b[x];
    	        }
        	}
        }
    }
    for(i=0;i<10;i++)
        printf("%d %d\n",c[i],d[i]);
}
