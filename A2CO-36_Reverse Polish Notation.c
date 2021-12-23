/*

Write a program in C to convert a given arithmetic expression in infix notation to postfix notation.
Show the status of stack and output expression after processing each symbol. 
Implement the stack using singly linked list and the concept of pointers in C. 
Assume there are only five operators: exponent, multiplication, division, addition and subtraction.

Name : Muniba Rahman
Faculty no. : 20COB275
Sr no. : A2CO-36

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

struct node
{
	char item;
	struct node* next; //to store the address of the next node	
};

typedef struct node node;
node* top = NULL; 

//function to create a node of the stack
node* createNode(char x)
{
	node* temp = (node*)malloc(sizeof(node)); //allocating memory to a node
	temp->item = x;
	temp->next = NULL;
	return temp;
}

bool isEmpty()
{
	//TOP pointer will be null if there is no node in the stack
	if(top == NULL)
		return true;
	else
		return false;
}

//insert a character into the stack
void push(char x)
{
	node* temp;
	temp = createNode(x);
	if(isEmpty()) 
		top = temp;
	else
	{
		temp->next = top;
		top = temp;
	}
}

//to pop a character out of the stack
char pop()
{
	char t;
	t = top->item;
	top = top->next;
	return t;
}

//return priority of operators
int priority(char n)
{
	if(n == '+' || n == '-')
		return 1;
	else if(n == '*' || n == '/')
		return 2;
	else if(n == '^') 
		return 3;
	else 
		return 0;
}

/*
void display()
{
	node* temp = top;
	printf("\n");
	while(temp!=NULL)
	{
		printf("%c\t-->\t",temp->item);
		temp = temp->next;
	}
	printf("\\0");
}
*/

void toPostfix(char exp[])
{
	//push '(' into the stack
	push('(');
	//add a ')' at the end of the infix expression
	strcat(exp,")");

	for(int i=0; i<=strlen(exp); ++i)
	{
		//if an operand is encountered, add it to postfix expression
		if((exp[i]>='A' && exp[i]<='Z')||(exp[i]>='a' && exp[i]<='z')||(exp[i]>='0' && exp[i]<='9'))
			printf("%c",exp[i]);
		//if left parenthesis is encountered, push it into stack
		else if(exp[i] == '(')
			push(exp[i]);
		//if right parenthesis is encountered 
		else if(exp[i] == ')')
		{
			char t = top->item;
			//pop until left parenthesis is encountered
			while(t!='(')
			{
				printf("%c",pop());
				t = top->item;
			}
			//remove the '(' from stack
			pop();
		}
		//if an operator is encountered
		else
		{
			char t = top->item;
			if((priority(exp[i]) == priority(t)) || (priority(exp[i]) < priority(t)))
			{
				//pop until an operator of higher precedence or parenthesis is not found in the stack
				while((priority(exp[i]) == priority(t)) || (priority(exp[i]) < priority(t)))
				{
					printf("%c",pop());
					t = top->item;
				}
			}	
			//add operator to the stack
			push(exp[i]);
		}
	}
}

int main()
{
	char s[MAX];
	//scanf("%s",s);
	printf("Enter an infix expression : ");
	gets(s);
	printf("Postfix expression : ");
	toPostfix(s);
	return 0;
}