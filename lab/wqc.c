#include<stdio.h>
void fight(char *m){
	char a =*m;
    
	if(a ){
		fight(m=m+1);
      
	}
    printf("%c",a);
}
int main(){
    printf("请输入一个字符串我来倒置：");
	char *s;
    scanf("%s",*&s);
    
	fight(s);
    
	return 0;
}

