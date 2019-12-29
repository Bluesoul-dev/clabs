#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100


int getop(char[]);
int getch(void);
void ungetch(int);
void push(double);
double pop(void);
void clear(void); 
double prt(void);

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];//ungetch函数的缓冲区
int bufp = 0;//buff中下一个空闲位置

main() {
	
	
	int type;
	double op1;
	double op2;
	char s[MAXOP];
	

	while ((type=getop(s))!=EOF)
	{
		switch (type)

		{
		case NUMBER:
			push(atof(s));
			break;
	    case '+':
            push(pop() + pop());
			break;		
		case '*':
			push(pop()*pop());
			break;		
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("ERROR : ZERO divisor\n");
			break;
		case '%':     
			op2=(int)pop();
			if (op2 != 0)
				push((int)pop()%(int)op2);
			else
				printf("Error: ZERO divisor\n");
			break;
		case'p':
			op2=pop();
			push(op2);
		    break;
		case'c':
		    clear();
		    break;
		case'd':
		    op2=pop();
		    push(op2);
		    push(op2);
		    break;	
		case's':
		    op1=pop();
		    op2=pop();
		    push(op1);
		    push(op2);
		    break;
		case '\n':
			printf("\t%.8g\n", prt());//打印而不是弹出元素
			break;
		case 'allelements':
		    for(int i=0;i<sp;i++)
			printf("%g\t",val[i]);
		default:
			printf("Error: Unknown command %d\n", s);
			break;
		}

	}
	return 0;

}

void push(double f)//入栈：在栈顶添加指定元素，返回新数组长度
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("Error: stack full, cannnot push %g\n", f);
}
double pop(void)//出栈：删除栈顶的一个元素，返回删除的元素
{
	if (sp > 0)
		return val[--sp];
	else
		printf("Error: stack empty\n");
	return 0.0;
}


void clear(void)//清空栈
{
	sp=0;
}

int getop(char s[]) //获取下一个运算符
{
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t');
	s[1] = '\0';
	i=0;
	if (!isdigit(c) && c != '.'&&c !='-')
		return c;
	
	if (c=='-')
	    if(isdigit(c = getch())|| c =='.')
		 s[++i]=c;
	    else{
			if(c!=EOF)
			  ungetch(c);
			return '-';
		} 
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()));
	if (c == '.')
		while (isdigit(s[++i] = c = getch()));
	    s[i] = '\0';
	
	if (c != EOF)
		ungetch(c);

	return NUMBER;
}



int getch(void) //获取一个字符
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)//把字符压回输入
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

double prt()//打印栈顶元素不弹出
{
    return val[sp-1];
	}

  