#ifndef SRC_BACKEND_STACK_STACK_H_
#define SRC_BACKEND_STACK_STACK_H_

#include <stdio.h>
#include <stdlib.h>

#define PLUS_OP +

typedef enum {
  NUMBER = 0,
  PLUS = 1,
  MINUS = 2,
  MULT = 3,
  DIV = 4,
  POWER = 5,
  MOD = 6,
  COS = 11,
  SIN = 12,
  TAN = 13,
  ACOS = 14,
  ASIN = 15,
  ATAN = 16,
  SQRT = 17,
  LN = 18,
  LOG = 19,
  LBRACKET = 20,
} type_t;

typedef struct stack_t {
  long double value;
  int priority;
  type_t type;
  struct stack_t *next;
} stack_t;

void push(stack_t **head, double value, int priority, type_t type);
void pop(stack_t **head);
void popValue(stack_t **head, double *value);
void pushBack(stack_t **head, double value, int priority, type_t type);
stack_t peek(stack_t **head);
size_t getSize(const stack_t *head);
stack_t *getLastElement(stack_t *head);
stack_t *init();
void deleteStack(stack_t **stack);
void printStack(stack_t *head);

#endif  // SRC_BACKEND_STACK_STACK_H_
