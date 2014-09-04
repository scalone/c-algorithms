#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAXSIZE 10

typedef int bool;
typedef struct _STACK {
  int values[MAXSIZE];
  int top;
} STACK;

bool init(STACK *stack)
{
  stack->top = -1;

  return TRUE;
}

bool push(STACK *stack, int element)
{
  if (stack->top < MAXSIZE) {
    stack->top++;
    stack->values[stack->top] = element;
    return TRUE;
  }

  return FALSE;
}

bool pop(STACK *stack, int *element)
{
  if (stack->top >= 0) {
    *element = stack->values[stack->top];
    stack->values[stack->top] = 0;
    stack->top--;
    return TRUE;
  }

  return FALSE;
}

bool show(STACK *stack)
{
  if (stack->top < 0)
    return FALSE;

  for (int i = stack->top; i >= 0; i--)
  {
    printf ("%d-", stack->values[i]);
  }

  return TRUE;
}

//bool change(Stack p, int base, int top, Node option)
//{
  //if (top >= base) {
    //p[top] = option;
    //return TRUE;
  //}

  //return FALSE;
//}

void destroy(int *base, int *top, int *limit)
{
  *base  = 0;
  *top   = *base - 1;
  *limit = 0 ;
}

char menu(void)
{
  char option;

  do {
    option = '\0';
    printf("\nOperation\n (p)ush\n p(o)p\n (s)how\n (d)estroy\n (e)xit? \n");
    scanf("%c", &option);
    getchar();
  } while (option != 'p' && option != 'o' && option != 's' && option != 'd' && option != 'e');

  return option;
}

int main(int argc, char *argv[])
{
  STACK stack;

  init(&stack);

  while(42) {
    char option = menu();
    int value=0;
    switch(option) {
      case 'p':
        printf("\nInform integer to add into stack: ");
        scanf("%d", &value);
        getchar();

        if (push(&stack, value))
          printf("\nSuccess.\n");
        else
          printf("\nError: Stack full.\n");

        break;
      case 'o':
        if (pop(&stack, &value))
          printf("\nSuccess: %d.\n", value);
        else
          printf("\nError: Stack empty.");

        break;
      case 's':
        if (show(&stack))
          printf("\nSuccess.\n");
        else
          printf("\nError: Stack empty.");

        break;
      //case 'd':
        //destroy(&base, &top, &limit);
        //printf("\nDestroyed");

        break;
      default:
        exit(0);
    }
  }
}




