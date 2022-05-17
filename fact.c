// OpenMP program to print Hello World
// using C language
 
// OpenMP header
#include <omp.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char* argv[])
{
     clock_t start, end;
     double c;
     start = clock();
int i,f=1,num;
  printf("Enter a number: ");
  scanf("%d",&num);
  #pragma omp parallel for shared(num) private(i) reduction(*:f)
  for(i=1;i<=num;i++)
      f=f*i;
  printf("Factorial of %d is: %d",num,f);
  end = clock();
  c = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf(" and took %f seconds to execute \n", c);
}
