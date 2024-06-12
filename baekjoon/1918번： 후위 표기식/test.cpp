#include <stdio.h>
#include <assert.h>

typedef struct{
	int max;
	int top;
	int* stk;
}	IntStack;

void clearstack(IntStack *s){
	free(s->stk);
	s->top = -1;
}

void push(IntStack *s, int data){
	assert(!(s->top >= s->max - 1));
	s->stk[++s->top] = data;
}

int pop(IntStack *s){
	int data;
	assert(!(s->top < 0));
	data = s->stk[s->top--];
	return data;
}

int peek(IntStack *s){
	int data;
	if (s->top < 0){
		return -1;
	}
	else {
		data = s->stk[s->top];
		return data;
	}
}

IntStack init(int max){
	IntStack stack;
	stack.max = max;
	stack.top = -1;	
	stack.stk = (int*)malloc(max*sizeof(int));
	return stack;
}

int main(){
	IntStack stack = init(110);
	char input[110];
	int sup[1000] = {-1};
	sup['+'] = 1;
	sup['-'] = 1;
	sup['*'] = 2;
	sup['/'] = 2;
	scanf("%s", input);
	
	int i = 0;
	char c = input[i];
	char k;

	while(c != '\0'){
		
		if (c != '+' && c != '-' && c != '*' && c != '/' && c != '(' && c != ')'){
			printf("%c", c);
		}
        
		else if(peek(&stack) == -1){
			push(&stack, c);
		}
		
		else if(c == '('){
			push(&stack, c);
		}
		
		else if(peek(&stack) == '('){
			push(&stack, c);
		}
		
		else if (c == ')'){
				while(peek(&stack) != '('){
					printf("%c",pop(&stack));
			}
			pop(&stack);
		}
		
		else if (sup[peek(&stack)] < sup[c]){
			push(&stack, c);
		}
		
		else if (sup[peek(&stack)] >= sup[c]){
			while (!(peek(&stack) == -1)){
				if (sup[peek(&stack)] < sup[c]){
					break;
				}
				printf("%c",pop(&stack));
			}
			push(&stack, c);
		}
		
		i++;
		c = input[i];
	}
	
	while(peek(&stack) != -1){
		k = pop(&stack);
		if (k != '(' && k != ')')
		printf("%c", k);
	}
	
	clearstack(&stack);
	return 0;
}