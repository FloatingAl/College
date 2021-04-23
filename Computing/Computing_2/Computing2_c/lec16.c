#include <stdio.h>

int max(int *arr,int firstIndex, int lastIndex);

int main(void)
{
  int arrx[5] = {10,20,0,100,30};
  printf("max is equal: %d \n", max(arrx, 0, 4);
  return 0;
}
   
 int fib(int i)   
 {
   if(i < 1)
     return 0;
   if(i==1)
     return 1;

   return fib(i-1) + fib(i-2);
 }

  int fib2(int i)
  {
    int F[46];
    F[0] = 0;
    F[1] = 1;
    for(int j = 2; j < i; j++)
      F[j] = F[j-1] + F[j-2];
  }



 
int max(int *arr,int firstIndex, int lastIndex)
{
  int u,v;
  int middleIndex;

  if(lastIndex == firstIndex)
    {
      return arr[lastIndex];
    }
  middleIndex = (firstIndex+lastIndex)/2;
  u = max(arr, firstIndex, middleIndex);
  v = max(arr, middleIndex+1 , lastIndex);
  if(u > v)
    return u;
  return v;
}
