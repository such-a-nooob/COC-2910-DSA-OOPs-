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

void toPostfix(char inexp[], char pfexp[])
{
	int n=0;
	//push '(' into the stack
	push('(');
	//add a ')' at the end of the infix expression
	strcat(inexp,")");

	for(int i=0; i<strlen(inexp); ++i)
	{
		//if an operand is encountered, add it to postfix expression
		if((inexp[i]>='A' && inexp[i]<='Z')||(inexp[i]>='a' && inexp[i]<='z')||(inexp[i]>='0' && inexp[i]<='9'))
			pfexp[n++] = inexp[i];
		//if left parenthesis is encountered, push it into stack
		else if(inexp[i] == '(')
			push(inexp[i]);
		//if right parenthesis is encountered 
		else if(inexp[i] == ')')
		{
			char t = top->item;
			//pop and add it to postfix expression until left parenthesis is encountered
			while(t!='(')
			{
				pfexp[n++] = pop();
				t = top->item;
			}
			//remove the '(' from stack
			pop();
		}
		//if an operator is encountered
		else
		{
			char t = top->item;
			if((priority(inexp[i]) == priority(t)) || (priority(inexp[i]) < priority(t)))
			{
				//pop and add it to postfix expression until an operator of lower precedence or parenthesis is not found in the stack
				while((priority(inexp[i]) == priority(t)) || (priority(inexp[i]) < priority(t)))
				{
					pfexp[n++] = pop();
					t = top->item;
				}
			}	
			//add operator to the stack
			push(inexp[i]);
		}
	}
	pfexp[n] = '\0';
}

int main()
{
	char infix[MAX], postfix[MAX];
	printf("Enter an infix expression : ");
	gets(infix);
	toPostfix(infix,postfix);
	printf("Postfix expression : %s",postfix);
	return 0;
}