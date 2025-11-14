main-stack : test.o stack.o evaluation.o  main-exprString.o
	gcc test.o stack.o evaluation.o main-expr.o -o main-stack 

test.o : test.c  application.h test.h stack.h 
	gcc -c test.c 
	
stack.o :  stack.c  application.h test.h stack.h
	gcc -c stack.c 
	
evaluation.o: evaluation.c  application.h test.h stack.h  evaluation.h
	gcc -c evaluation.c 

evaluationString.o: evaluation.c  application.h test.h stack.h  evaluation.h
	gcc -c evaluationString.c 
	
main-exprString.o : main-exprString.c application.h test.h stack.h  evaluation.h 
	gcc -c main-exprString.c 
	
## main-stack.o:  main-stack.c  application.h test.h stack.h
	##gcc -c main-stack.c 
	

s
