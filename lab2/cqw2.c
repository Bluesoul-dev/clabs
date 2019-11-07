#include <stdio.h>
int main()
{
    int b=0;
    unsigned int a=1;
    unsigned int c=0 -1;
    while(a !=0){
        b=b+1;
        a=a<<1;
    }
    printf("a=%d\n",b);
    printf("b=%u",c);
    return 0;
}