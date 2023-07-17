#include "stack.h"

void push(stack_t **head, double value, int priority, type_t type) {
  stack_t *temp = malloc(sizeof(stack_t));

  if (temp != NULL) {
    temp->value = value;
    temp->priority = priority;
    temp->type = type;
    temp->next = *head;
    *head = temp;
  }
}

void pop(stack_t **head) {
  stack_t *temp = *head;

  if (*head != NULL) {
    *head = (*head)->next;
    free(temp);
  }
}

void popValue(stack_t **head, double *value) {
  stack_t *temp = *head;

  if (temp != NULL) {
    *value = temp->value;
    *head = (*head)->next;
    free(temp);
  }
}

stack_t peek(stack_t **head) {
  stack_t *temp = *head;

  if (*head != NULL) {
    temp = *head;
  }

  return *temp;
}

size_t getSize(const stack_t *head) {
  size_t size = 0;

  while (head) {
    size++;
    head = head->next;
  }

  return size;
}

stack_t *init() {
  stack_t *stack;

  stack = malloc(sizeof(stack_t));
  stack->value = -1;
  stack->priority = -1;
  stack->type = -1;
  stack->next = NULL;

  return stack;
}

void deleteStack(stack_t **stack) {
  while (*stack != NULL) {
    pop(stack);
  }
}

// void printStack(stack_t *head) {
//     if (head != NULL) {
//         printf("\n\n");
//         while (head->next) {
//             if (head->type != (type_t)-1) printf("VALUE = %Lf, TYPE = %d\n",
//             head->value, head->type); head = head->next;
//         }
//         printf("\n\n");
//     }
// }
