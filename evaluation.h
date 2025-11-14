/*!
 * \file    evaluation.h
 * \brief   Declaration of functions to process a stack of int as a post-fix expression
 */

#ifndef EVALUATION
#define EVALUATION

#include "application.h"
#include "stack.h"

Boolean add(Stack *s);
Boolean substract(Stack *s);

int test_eval(void);

int plus (int a, int b);
int moins (int a, int b);
int mul (int a, int b);
int divi (int a, int b);
typedef struct{
    char c;
    Boolean (*act) (Stack *);
}Map_element;

int evaluateExpression(char *str);
int evaluateExpression_pf(char *str);

int test_evalString(void);


#endif
