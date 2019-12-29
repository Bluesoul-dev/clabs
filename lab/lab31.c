#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMUM 100

void main()
{
 char t[MAXIMUM] = {0};
 char s[MAXIMUM] = {0};
 scanf("%s%s",t,s);

 int i = 0;
 for (i = MAXIMUM - 1;i >= 0;i--)
 {
  if (s[i] == t[0])
  {
   int j = 0;
   int count = 0;
   while (t[j] != '\0')
   {
    if (s[i + j] == t[j])
    {
     count++;
    }
    j++;
   }
   if (count == j)
   {
    break;
   }
  }
 
 }
 
 printf("The pos where t first in s is %d\n", i);
 getchar();
}