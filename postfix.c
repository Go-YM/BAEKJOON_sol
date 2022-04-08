/* postfix.c
 *
 *  Data Structures, Homework #5
 *  Department of Computer Science at Chungbuk National University
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//<stdio.h>,<stdlib.h>,<string.h>가 컴파일 전에 소스에 확장하도록 지시

#define MAX_STACK_SIZE 10	//MAX_STACK_SIZE를 10으로 초기화하고 상수로 지정
#define MAX_EXPRESSION_SIZE 20	//MAX_EXPRESSION_SIZE를 20으로 초기화하고 상수로 지정

/* stack 내에서 우선순위, lparen = 0 가장 낮음 */
typedef enum{
	lparen = 0,  /* ( 왼쪽 괄호 */
	rparen = 9,  /* ) 오른쪽 괄호*/
	times = 7,   /* * 곱셈 */
	divide = 6,  /* / 나눗셈 */
	plus = 5,    /* + 덧셈 */
	minus = 4,   /* - 뺄셈 */
	operand = 1 /* 피연산자 */
} precedence;
//구조체 precedence로 연산자들의 우선순위를 정함

char infixExp[MAX_EXPRESSION_SIZE];   	/* infix expression을 저장하는 배열 */
char postfixExp[MAX_EXPRESSION_SIZE];	/* postfix로 변경된 문자열을 저장하는 배열 */
char postfixStack[MAX_STACK_SIZE];	/* postfix로 변환을 위해 필요한 스택 */
int evalStack[MAX_STACK_SIZE];		/* 계산을 위해 필요한 스택 */

int postfixStackTop = -1;  /* postfixStack용 top */
int evalStackTop = -1;	   /* evalStack용 top */

int evalResult = 0;	   /* 계산 결과를 저장 */

//함수 원형
void postfixpush(char x);
char postfixPop();
void evalPush(int x);
int evalPop();
void getInfix();
precedence getToken(char symbol);
precedence getPriority(char x);
void charCat(char* c);
void toPostfix();
void debug();
void reset();
void evaluation();

//프로그램의 메인함수
int main()
{
	char command;

	//command가 q or Q일때 까지 반복하는 반복문
	do{	//메뉴 출력
		printf("----------------------------------------------------------------\n");
		printf("               Infix to Postfix, then Evaluation               \n");
		printf("----------------------------------------------------------------\n");
		printf(" Infix=i,   Postfix=p,  Eval=e,   Debug=d,   Reset=r,   Quit=q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);	//사용자로부터 command를 입력받음

		switch(command) {
		case 'i': case 'I':	//command가 i or I 일때
			getInfix();
			break;
		case 'p': case 'P':	//command가 p or P 일때
			toPostfix();
			break;
		case 'e': case 'E':	//command가 e or E 일때
			evaluation();
			break;
		case 'd': case 'D':	//command가 d or D 일때
			debug();
			break;
		case 'r': case 'R':	//command가 r or R 일때
			reset();
			break;
		case 'q': case 'Q':	//command가 q or Q 일때
			break;
		default:			//command를 잘못 입력했을때
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;	//1 반환
}

void postfixPush(char x)
{//postfix 삽입 하는 함수
    postfixStack[++postfixStackTop] = x;	//++Top후 Top에서 삽입
}

char postfixPop()
{//postfix 삭제 하는 함수 
    char x;
    if(postfixStackTop == -1)	//Stack이 비었을때
        return '\0';
    else {	//Stack이 차있을때
    	x = postfixStack[postfixStackTop--];	//Top에서 삭제후 Top--
    }
    return x;	//x 반환
}

void evalPush(int x)	
{//계산 값 삽입하는 함수
    evalStack[++evalStackTop] = x;		//++Top후 Top에서 삽입
}

int evalPop()
{
    if(evalStackTop == -1)	//Stack이 비어있을때
        return -1;	//-1 반환
    else	//Stack이 차있을때
        return evalStack[evalStackTop--];	//Top에서 삭제 한뒤 값 반환하고 Top--
}

/**
 * infix expression을 입력받는다.
 * infixExp에는 입력된 값을 저장한다.
 */
void getInfix()
{//사용자로부터 infix를 입력받는 함수
    printf("Type the expression >>> ");
    scanf("%s",infixExp);	//infixExp에 문자열 형식으로 저장받음
}

precedence getToken(char symbol)
{//연산자일때 우선순위를 반환해주는 함수
	switch(symbol) {
	case '(' : return lparen;
	case ')' : return rparen;
	case '+' : return plus;
	case '-' : return minus;
	case '/' : return divide;
	case '*' : return times;
	default : return operand;
	}
}

precedence getPriority(char x)
{// ???
	return getToken(x);
}

/**
 * 문자하나를 전달받아, postfixExp에 추가
 */
void charCat(char* c)
{//문자를 postfix에 옮겨주는 함수
	if (postfixExp == '\0')	//postfix가 널값이 아닐때 
		strncpy(postfixExp, c, 1); 	//c를 postfixExp에 복사
	else	//postfix가 널값일때
		strncat(postfixExp, c, 1);	//c를 postfixExp에 이어붙임
}

/**
 * infixExp의 문자를 하나씩 읽어가면서 stack을 이용하여 postfix로 변경한다.
 * 변경된 postfix는 postFixExp에 저장된다.
 */
void toPostfix()
{//infix를 postfix로 변환해주는 함수
	/* infixExp의 문자 하나씩을 읽기위한 포인터 */
	char *exp = infixExp;
	char x; /* 문자하나를 임시로 저장하기 위한 변수 */

	/* exp를 증가시켜가면서, 문자를 읽고 postfix로 변경 */
	while(*exp != '\0')	//*exp가 널값일때까지 반복하는 whil문
	{
		if(getPriority(*exp) == operand)
			{
				x = *exp;
				charCat(&x);
			}
			else if(getPriority(*exp) == lparen) 
			{

				postfixPush(*exp);
			}
			else if(getPriority(*exp) == rparen)
			{
				while((x = postfixPop()) != '(') 
				{
					charCat(&x);
				}
			}
			else
			{
				while(getPriority(postfixStack[postfixStackTop]) >= getPriority(*exp))
				{
					x = postfixPop();
					charCat(&x);
				}
				postfixPush(*exp);
			}
			exp++;
	}

    while(postfixStackTop != -1)
    {
    	x = postfixPop();
    	charCat(&x);
    }
}
void debug()
{
	printf("\n---DEBUG\n");
	printf("infixExp =  %s\n", infixExp);
	printf("postExp =  %s\n", postfixExp);
	printf("eval result = %d\n", evalResult);

	printf("postfixStack : ");
	for(int i = 0; i < MAX_STACK_SIZE; i++)
	{
		printf("%c  ", postfixStack[i]);
	}

	printf("\n");

}

void reset()
{
	infixExp[0] = '\0';
	postfixExp[0] = '\0';

	for(int i = 0; i < MAX_STACK_SIZE; i++)
	{
		postfixStack[i] = '\0';
	}
         
	postfixStackTop = -1;
	evalStackTop = -1;
	evalResult = 0;
}

void evaluation()
{
	int opr1, opr2, i;

	int length = strlen(postfixExp);
	char symbol;
	evalStackTop = -1;

	for(i = 0; i < length; i++)
	{
		symbol = postfixExp[i];
		if(getToken(symbol) == operand) 
		{
			evalPush(symbol - '0');
		}
		else 
		{
			opr2 = evalPop();
			opr1 = evalPop();

			switch(getToken(symbol)) 
			{
			case plus: evalPush(opr1 + opr2); break;
			case minus: evalPush(opr1 - opr2); break;
			case times: evalPush(opr1 * opr2); break;
			case divide: evalPush(opr1 / opr2); break;
			default: break;
			}
		}
	}

	evalResult = evalPop();
}

