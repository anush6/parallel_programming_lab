#include<omp.h>
#include<stdio.h>

void main() {
    int i;
	#pragma omp parallel for num_threads(8) 
	for(i = 97; i<=122; i++)
	    printf("%c",i);
    printf("\n");
}
/* If they ask u to print it in order use the below code
void main() {
    int i;
	#pragma omp parallel for num_threads(8) ordered
	for(i = 97; i<=122; i++)
	#pragma omp ordered
	    printf("%c",i);
    printf("\n");
}
*/

