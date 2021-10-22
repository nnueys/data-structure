#include <stdio.h>
#define  MAX_STACK_SIZE  100

typedef struct int_stack_type {
	int	lines[MAX_STACK_SIZE];
	int	last;
    char n_hanoi;
} Stack;

Stack a,b,c;
int times = 0;

int pushStack(Stack *s, int x){
	if (s->last >= MAX_STACK_SIZE -1)
		return 0;
	else {
		s->last++;
		s->lines[s->last] = x;
		return 1;
	}
}

int popStack(Stack *s, int *x) {
	if (s->last <0)
		return 0;
	else {
		*x = s->lines[s->last];
		s->last--;
		return 1;
	}
}

void printStack(Stack s){
	int i;
    printf("Tower");
    printf("\n");
    printf("%c: ", s.n_hanoi);
	for (i=0; i<=s.last; i++)
		printf("%d ", s.lines[i]);
	printf("\n");
    printf("\n");
}

void printTower() {
    printStack(a);
    printf("\n");
    printStack(b);
    printf("\n");
    printStack(c);
    printf("\n");
    printf("\n");
}

void move(int n, Stack *a, Stack *b, Stack *c) {
    int x;
    if (n == 1) { // last rod
        popStack(a, &x);
        pushStack(c, x);
        printf("Move #%d:\n", ++times);
        printf("move(%d,%c,%c,%c)\n",n-1, a->n_hanoi, b->n_hanoi, c->n_hanoi);
        printf("\n");
        printTower();
        return;
    }
    // move out
    move(n-1, a, c, b);
    popStack(a, &x);
    pushStack(c, x);
    printf("Move #%d:\n", ++times);
    printf("move(%d,%c,%c,%c)\n",n-1, a->n_hanoi, b->n_hanoi, c->n_hanoi);
    printf("\n");
    printTower();
    // move in
    move(n-1, b, a, c);
}

int main(){
    int n;
	printf("N = ");
    scanf("%d", &n);
    a.last = -1;
    b.last = -1;
    c.last = -1;
    a.n_hanoi = 'A';
    b.n_hanoi = 'B';
    c.n_hanoi = 'C';
    for (int i = n-1; i >= 0; i--) {
        pushStack(&a, i);
    }
    printf("\nStart\n\n");
    printTower(a, b, c);
    move(n, &a, &b, &c);
    return 0;
}