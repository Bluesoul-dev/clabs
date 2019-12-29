#include<stdio.h>
#include<stdlib.h>
float minimum(float a, float b)
{
 if (a < b)
 {
  return a;
 }
 else
 {
  return b;
 }
}

void main(int argc, char* argv[])
{
 for (int i = 1;i < argc;i++)
 {
  printf("%.2f ", atof(argv[i]));
 }
 printf("\n");
 float min = atof(argv[1]);
 for (int i = 2;i < argc;i++)
 {
  min = minimum(min, atof(argv[i]));
 }
 printf("This min is %.2f", min);

 getchar();
}


