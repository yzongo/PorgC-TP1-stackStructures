/*!
 * \file  evaluation.c
 * \brief  Definition of functions to process a stack of int as a post-fix expression
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "application.h"
#include "evaluation.h"
#include "stack.h"
#include "test.h"

/* mettre le prototype au début du fichier*/

static Boolean binary_operator_pf(Stack *s, int (*op)(int, int));


int plus (int a, int b){
	return a+b;
}
int moins (int a, int b){
	return a-b;
}
int mul (int a, int b){
	return a*b;
}
int divi (int a, int b){
	return a/b;
}
static Boolean binary_operator(Stack *s, int operation){

  int op1,op2; /*the operands*/
  int res; /*the result*/

  if (isEmpty(s)){
    fprintf(stderr,"Empty stack : can not proceed to the binary operation\n");
    return(FALSE);
  }
  op1=pop(s);

  if (isEmpty(s)){
    fprintf(stderr,"Empty stack : can not proceed to the binary operation\n");
    return(FALSE);
  }
  op2=pop(s);

  /* computation*/
  switch(operation){
      case ADD:
        res = op1 + op2;
        break;
      case SUBSTRACT:
        res = op2 - op1;
        break;
       case MULTIPLY:
        res = op2 * op1;
        break;
        case DIVIDE:
        res = op2 / op1;
        break;
       
      default:
        fprintf(stderr,"Unknown operator\n");
        return(FALSE);
  }

  /* Put the result in the stack */
  push(s,res);

  return(TRUE);
}


 Boolean add(Stack *s){
  return binary_operator_pf(s, &plus);
}

 Boolean substract(Stack *s){
  return binary_operator_pf(s, &moins);
}

 Boolean multiply(Stack *s){
  return binary_operator_pf(s, &mul);
}

 Boolean divide(Stack *s){
  return binary_operator_pf(s, &divi);
}

Boolean sqrt

/*!
 * \fn int test_eval(void)  
 * Tests evaluation of postfix expressions
 * \return EXIT_SUCCESS if everything is ok
 */
int test_eval(void){

    Stack s;
    init_stack(&s);
    push(&s,1);
    push(&s,2);
    substract(&s);
    display_test_int("Test substract()",-1,pop(&s)); push(&s,-1); /*the push is to put back the popped value for the test*/
    push(&s,3);
    add(&s);
    display_test_int("Test add()",2,pop(&s)); push(&s,2); /*the push is to put back the popped value for the test*/
    push(&s,4);
    push(&s,5);
    add(&s);
    add(&s);

    display_test_check_by_user("Test substract() and add() : (display stack should be 0 11)");
    display_stack(&s);

    /* to be completed when multiply is implemented*/

    /* to be completed when divide is implemented*/

    /* Test the 3 9 3 - 4 * 3 / + expression*/
    
   

    return(EXIT_SUCCESS);
    
}

static Boolean  binary_operator_pf(Stack *s, int (*op)(int,int)){

  int op1,op2; /*the operands*/
  int res; /*the result*/

  if (isEmpty(s)){
    fprintf(stderr,"Empty stack : can not proceed to the binary operation\n");
    return(FALSE);
  }
  op1=pop(s);

  if (isEmpty(s)){
    fprintf(stderr,"Empty stack : can not procee d to the binary operation\n");
    return(FALSE);
  }
  op2=pop(s);

  /* computation*/
 	res= (*op)(op1,op2);

  /* Put the result in the stack */
  push(s,res);

  return(TRUE);
}


