#include "logic.h"

int isTab(char c) { return c == ' ' || c == '\n' || c == '\t' || c == '\0'; }
int isDec(char c) { return (c >= '0' && c <= '9') || isX(c); }
int isFuncChar(char c) {
  return c == 'c' || c == 's' || c == 't' || c == 'a' || c == 'l';
}
int isSign(char c) { return c == '+' || c == '-'; }
int isOperation(char c) {
  return c == '/' || c == '*' || c == '+' || c == '-' || c == '^';
}
int isMod(char *string) {
  return *string == 'm' && *(string + 1) == 'o' && *(string + 2) == 'd';
}
int isX(char c) { return c == 'x' || c == 'X'; }
int isDot(char c) { return c == '.' || c == ','; }
int isUnaryOperator(char *string, int elemNumber) {
  int RESULT_CODE = FAILURE;
  char prev = *(string - 1);
  char cur = *string;
  char next = *(string + 1);

  if (isSign(cur) && next == '(') {
    RESULT_CODE = FAILURE;
  } else if (elemNumber == 0 && isSign(cur) && (isDec(next) || isDot(next))) {
    RESULT_CODE = SUCCESS;
  } else if (elemNumber > 0 && isSign(cur) && !isDec(prev) && prev != ')') {
    RESULT_CODE = SUCCESS;
  }

  return RESULT_CODE;
}

int isNumber(char *string, int elemNumber) {
  int RESULT_CODE = FAILURE;
  char *ptr = string;
  int dot = 0;

  if (isUnaryOperator(string, elemNumber)) {
    RESULT_CODE = SUCCESS;
    ptr++;
  }
  if (isX(*ptr)) {
    RESULT_CODE = SUCCESS;
    ptr++;
  } else {
    for (; *ptr && (isDec(*ptr) || isDot(*ptr)); ptr++) {
      if (dot && isDot(*ptr)) {
        RESULT_CODE = FAILURE;
        break;
      } else if (isDot(*ptr)) {
        dot = 1;
      } else {
        RESULT_CODE = SUCCESS;
      }
    }
  }

  return RESULT_CODE;
}
int isFunc(char *string, int *funcType) {
  int RESULT_CODE = FAILURE;
  char *functions[9] = {"cos(",  "sin(",  "tan(", "acos(", "asin(",
                        "atan(", "sqrt(", "ln(",  "log("};

  for (int i = 0; RESULT_CODE == FAILURE && i < 9; i++) {
    char *ptr = string;

    if (!strncmp(functions[i], ptr, strlen(functions[i]))) {
      *funcType = i + 11;
      RESULT_CODE = SUCCESS;
    }
  }

  return RESULT_CODE;
}

int isWrongBrackets(char *string) {
  int RESULT_CODE = FAILURE;
  char *ptr = string;
  int lbracket = 0;
  int rbracket = 0;

  for (; RESULT_CODE != SUCCESS && *ptr; ptr++) {
    if (*ptr == '(') {
      lbracket++;
    } else if (*ptr == ')') {
      rbracket++;
      if (rbracket > lbracket) RESULT_CODE = SUCCESS;
    }
  }
  if (rbracket != lbracket) RESULT_CODE = SUCCESS;

  return RESULT_CODE;
}
int isWrongSigns(char *string) {
  int RESULT_CODE = FAILURE;
  char *ptr = string;

  for (; RESULT_CODE != SUCCESS && *ptr; ptr++) {
    if (*ptr == '(' &&
        (*(ptr + 1) == '*' || *(ptr + 1) == '/' || *(ptr + 1) == '^')) {
      RESULT_CODE = SUCCESS;
    }
  }

  return RESULT_CODE;
}
int isEmptyString(char *string) {
  int RESULT_CODE = SUCCESS;
  char *ptr = string;

  for (; RESULT_CODE != FAILURE && *ptr; ptr++) {
    if (!isTab(*ptr)) RESULT_CODE = FAILURE;
  }

  return RESULT_CODE;
}

// adds a number to the stack
void appendNumber(stack_t **numberStack, char **number, long double x) {
  int dot = 0;
  int sign = 1;

  if (isSign(**number)) {
    if (**number == '-') sign = -1;
    (*number)++;
  }
  if (isX(**number)) {
    (*number)++;
    push(numberStack, x * sign, 0, NUMBER);
  } else {
    char temp[256] = {0};

    for (int i = 0; **number && (isDec(**number) || isDot(**number)) &&
                    !(dot && isDot(**number));
         (*number)++, i++) {
      if (isDot(**number) && !dot) {
        dot = 1;
        if (**number == ',') **number = '.';
      }
      temp[i] = **number;
    }
    push(numberStack, atof(temp) * sign, 0, NUMBER);
  }
}

// adds a function to the stack
int appendFunc(stack_t **numberStack, char **function, long double x,
               int funcType) {
  int RESULT_CODE = SUCCESS;
  char temp[256] = {0};
  char result[512] = {0};

  while (**function != '(') (*function)++;
  (*function)++;
  for (int i = 0, lbracket = 1; lbracket != 0; (*function)++) {
    if (**function == '(') {
      lbracket++;
    } else if (**function == ')') {
      lbracket--;
    }
    if (lbracket != 0) {
      temp[i] = **function;
      i++;
    }
  }
  SmartCalculator(temp, x, result);
  if (isNumber(result, 0) == SUCCESS) {
    push(numberStack, atof(result), 0, funcType);
  } else {
    RESULT_CODE = FAILURE;
  }

  return RESULT_CODE;
}

// adds an operation to the stack
void appendOperation(stack_t **stack, stack_t **output, char **string) {
  char prev = **string;
  (*string)--;
  char temp = **string;
  (*string)++;

  (*string)++;

  if (prev == '-' && **string == '(' && !isDec(temp)) {
    push(output, -1, 0, NUMBER);
    prev = '*';
  } else if (prev == '-' && isFuncChar(**string)) {
    push(output, 0, 0, NUMBER);
    prev = '-';
  }
  while (detPriority(prev) <= (*stack)->priority) {
    push(output, (*stack)->value, (*stack)->priority, (*stack)->type);
    pop(stack);
  }
  push(stack, 0, detPriority(prev), detOperation(prev));
  if (prev == 'm') (*string) += 2;
}

// adds a lbracket to the stack
void appendBracket(stack_t **stack, char **string) {
  push(stack, 0, 0, LBRACKET);
  (*string)++;
}

// moving operators from stack to output
void transferToOutput(stack_t **stack, stack_t **output, char **string) {
  stack_t temp = peek(stack);

  while (temp.type != LBRACKET) {
    push(output, temp.value, temp.priority, temp.type);
    pop(stack);
    temp = peek(stack);
  }
  pop(stack);
  (*string)++;
}

// moving the remaining from stack to output
void transferToOutput2(stack_t **stack, stack_t **output) {
  while (*stack != NULL && (*stack)->priority != -1) {
    push(output, 0, (*stack)->priority, (*stack)->type);
    pop(stack);
  }
}

// removes spaces in a string
void deleteSpaces(char *src, char *dest) {
  char *ptr = src;

  for (int i = 0; *ptr; ptr++) {
    if (*ptr != ' ') {
      dest[i] = *ptr;
      i++;
    }
  }
}

// determines the priority of the operation
int detPriority(char operation) {
  int priority = 0;

  if (operation == '+' || operation == '-') {
    priority = 1;
  } else if (operation == '*' || operation == '/') {
    priority = 2;
  } else if (operation == 'm') {
    priority = 3;
  } else if (operation == '^') {
    priority = 4;
  }

  return priority;
}

// defines the operation type
int detOperation(char operation) {
  int type = 0;

  if (operation == '+') {
    type = PLUS;
  } else if (operation == '-') {
    type = MINUS;
  } else if (operation == '*') {
    type = MULT;
  } else if (operation == '/') {
    type = DIV;
  } else if (operation == '^') {
    type = POWER;
  } else if (operation == 'm') {
    type = MOD;
  }

  return type;
}

// translates the expression into polish notation
stack_t *polishNotation(char *input, long double x, stack_t *output,
                        int *RESULT_CODE) {
  *RESULT_CODE = SUCCESS;
  stack_t *stack = init();
  char *ptr = input;
  int funcType = -1;

  for (int i = 0; *RESULT_CODE == SUCCESS && *ptr; i++) {
    if (isNumber(ptr, i)) {
      appendNumber(&output, &ptr, x);
    } else if (isFunc(ptr, &funcType)) {
      *RESULT_CODE = appendFunc(&output, &ptr, x, funcType);
    } else if (*ptr == '(') {
      appendBracket(&stack, &ptr);
    } else if (isOperation(*ptr) || isMod(ptr)) {
      appendOperation(&stack, &output, &ptr);
    } else if (*ptr == ')') {
      transferToOutput(&stack, &output, &ptr);
    } else {
      *RESULT_CODE = FAILURE;
    }
  }
  if (*RESULT_CODE == SUCCESS) transferToOutput2(&stack, &output);
  deleteStack(&stack);

  return output;
}