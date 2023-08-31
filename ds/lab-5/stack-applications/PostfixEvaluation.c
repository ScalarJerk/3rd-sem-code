#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Stack
struct Stack {
	int top;
	int capacity;
	int* arr;
};

// Function to create a stack
struct Stack* createStack(int cap) {
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	if (!stack)
		return NULL;

	stack->top = -1;
	stack->capacity = cap;
	stack->arr = (int*)malloc(stack->capacity * sizeof(int));
	if (!stack->arr)
		return NULL;

	return stack;
}

// Check if stack is empty
int isEmpty(struct Stack* stack) {
	return stack->top == -1;
}

// Get the top element of the stack
int peek(struct Stack* stack) {
	return stack->arr[stack->top];
}

// Pop operation
int pop(struct Stack* stack) {
	if (!isEmpty(stack))
		return stack->arr[stack->top--];
	return -1; // Return an invalid value to indicate error
}

// Push operation
void push(struct Stack* stack, int val) {
	stack->arr[++stack->top] = val;
}

// Evaluate postfix expression
int evaluatePostfix(char* exp) {
	// Create a stack of capacity equal to expression size
	struct Stack* stack = createStack(strlen(exp));
	int i;

	if (!stack)
		return -1; // Return an invalid value to indicate error

	// Scan all characters one by one
	for (i = 0; exp[i]; ++i) {
		// If the scanned character is an operand (number here),
		// push it to the stack.
		if (isdigit(exp[i]))
			push(stack, exp[i] - '0');
		else {
			// If the scanned character is an operator,
			// pop two elements from the stack and apply the operator.
			int val1 = pop(stack);
			int val2 = pop(stack);
			switch (exp[i]) {
			case '+':
				push(stack, val2 + val1);
				break;
			case '-':
				push(stack, val2 - val1);
				break;
			case '*':
				push(stack, val2 * val1);
				break;
			case '/':
				push(stack, val2 / val1);
				break;
			}
		}
	}
	return pop(stack); // The final result is left at the top of the stack
}

int main() {
	char exp[50];
	int result;

	do {
		// Input postfix expression from user
		printf("Enter a postfix expression: ");
		scanf("%s", exp);

		// Evaluate the expression
		result = evaluatePostfix(exp);
		if (result != -1)
			printf("Result: %d\n", result);
		else
			printf("Invalid expression\n");

		// Ask user if they want to enter another input
		char choice;
		printf("Do you want to evaluate another expression? (y/n): ");
		scanf(" %c", &choice);

		if (choice != 'y' && choice != 'Y')
			break;

	} while (1);

	return 0;
}
