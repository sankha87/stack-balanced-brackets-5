#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Stack	// A structure to represent a stack 
{
	int top;
	int capacity;
	char *array;
};

struct Stack* createStack(int cap)	// function to create a stack of given capacity.
{
	struct Stack *st = (struct Stack*)malloc(sizeof(struct Stack));
	st->top = -1;
	st->capacity = cap;
	st->array = (char*)malloc(st->capacity * sizeof(char));
	return st;
}

int isFull(struct Stack *st)  // Stack is full when top is equal to the last index 
{
	return (st->top == st->capacity - 1);
}

int isEmpty(struct Stack *st)  // Stack is empty when top is equal to -1 
{
	return (st->top == -1);
}

void push(struct Stack *st, char item)
{
	if (isFull(st))
	{
		printf("\nStack is full \n");
		return;
	}
	st->top++;
	st->array[st->top] = item;
	printf("%c pushed to stack\n", item);
}

char pop(struct Stack *st)
{
	if (isEmpty(st))
		return INT_MIN;
	char temp = st->array[st->top];
	st->top--;
	return temp;
}

char peek(struct Stack *st)    // Function to return the top from stack without removing it
{
	if (isEmpty(st))
		return INT_MIN;
	return st->array[st->top];
}

bool isForward(char ch)
{
	if (ch == '[' || ch == '{' || ch == '(')
		return true;
	else
		return false;
}

bool isBackward(char ch)
{
	if (ch == ']' || ch == '}' || ch == ')')
		return true;
	else
		return false;
}

bool closing_brackets(char ch1, char ch2)
{
	if (ch1 == '[' && ch2 == ']')
		return true;
	else if (ch1 == '{' && ch2 == '}')
		return true;
	else if (ch1 == '(' && ch2 == ')')
		return true;
	else
		return false;
}

void disposeStack(struct Stack *st)
{
	if (st != NULL)
	{
		free(st->array);
		free(st);
	}
}

void main()
{
	int n;
	char *ch;
	bool b = true;
	struct Stack *s;
	printf("enter no of brackets : \n");
	scanf("%d", &n);
	s = createStack(n);

	if (n % 2 == 0)
	{
		ch = (char *)malloc(n * sizeof(char));
		printf("enter brackets : \n");
		scanf("%s", ch);

		for (int i = 0, j = 0; i < n; i++, j++)
		{
			if (isForward(*(ch + i)))
				push(s, *(ch + i));

			if (isBackward(*(ch + i)))
			{
				char ch2 = pop(s);

				if (closing_brackets(ch2, *(ch + i)))
					j -= 2;

				else
					b = false;
			}
		}

		if (s->top == -1 && b)
			printf("\nBalanced");
		else
			printf("\nNot balanced");
	}
	else
		printf("\nNot balanced");
	disposeStack(s);
	_getch();
}