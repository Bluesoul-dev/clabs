#include <stdio.h>

int main()
{
  int fahr,celsius;
  int lower,upper,step;

  lower=0;
  upper=100;
  step=5;

printf("celsius fahr");
  celsius=lower;
  while(celsius<=upper){
   fahr=32+celsius*1.8;
   printf("\n%d\t%d",celsius,fahr);
   celsius=celsius+step;
  }
return 0;
}