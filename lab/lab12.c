#include<stdio.h>
main(){
    int num;
    int count = 0;
    scanf("%d",&num);
    if(num<=99999){
        while(num){
            if(num%2==1)count++;
            num/=2;
        }
        printf("%d",count);
    }
    else{
        printf("error");
    }
    return 0;
}