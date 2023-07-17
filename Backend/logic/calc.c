#include "logic.h"

int SmartCalculator(char *string, long double x, char *outputResult) {
  int RESULT_CODE = SUCCESS;
  stack_t *output = init();
  char input[256] = {0};
  char *ptr = input;
  double result = 0;

  deleteSpaces(string, input);
  if (isEmptyString(ptr) || isWrongBrackets(ptr) || isWrongSigns(ptr)) {
    RESULT_CODE = FAILURE;
    deleteStack(&output);
    strcpy(outputResult, "ERROR");
  } else {
    output = polishNotation(input, x, output, &RESULT_CODE);
    if (RESULT_CODE == SUCCESS) {
      RESULT_CODE = calc(output, &result);
      if (isnan(result)) {
        strcpy(outputResult, "NAN");
      } else if (isinf(result)) {
        strcpy(outputResult, "INF");
      } else if (RESULT_CODE == FAILURE) {
        strcpy(outputResult, "ERROR");
      } else {
        sprintf(outputResult, "%.7lf", result);
      }
    } else {
      deleteStack(&output);
      strcpy(outputResult, "ERROR");
    }
  }

  return RESULT_CODE;
}

void CreditCalculator(long double creditAmount, int period, long double percent,
                      int type, long double *payment, long double *overpayment,
                      long double *totalPayment, long double *max,
                      long double *min) {
  if (type == ANNUITY) {
    long double rate = percent / (long double)1200;
    long double x = rate * pow(rate + 1, (long double)period) /
                    (pow(rate + 1, (long double)period) - 1);

    *payment = x * creditAmount;
    *totalPayment = *payment * (long double)period;
    *overpayment = *totalPayment - creditAmount;
  } else if (type == DIFFERENTIATED) {
    long double rate = creditAmount / (long double)period;

    *max = rate + creditAmount * percent * 30.42 / 36524.25;
    *min = rate + rate * percent * 30.42 / 36524.25;
    *payment = (*max + *min) / 2;
    *totalPayment = *payment * (long double)period;
    *overpayment = *totalPayment - creditAmount;
  }
}

void DepositCalculator(long double depositAmount, int period,
                       long double percent, long double tax, int frequency,
                       int capitalization, long double *payment,
                       long double *invoiceSum, long double *taxSum) {
  int capitalizationPeriod = 0;

  if (frequency != 0) {
    capitalizationPeriod = period / frequency;
  } else {
    capitalization = 0;
  }
  if (capitalization == 0) {
    *payment = (depositAmount * (percent / 100) * (long double)period) / 365.0;
    *invoiceSum = depositAmount;
  } else {
    *payment = depositAmount *
                   pow(1.0 + (percent / 100) * (long double)frequency / 365.0,
                       (long double)capitalizationPeriod) -
               depositAmount;
    *invoiceSum = depositAmount + *payment;
  }
  if (percent > 12.5) {
    *taxSum = *payment * (tax / 100);
  }
}

int calc(stack_t *output, double *result) {
  int RESULT_CODE = SUCCESS;
  stack_t *temp = init();

  if (getSize(output) == 2 ||
      (getSize(output) == 3 && output->type >= PLUS && output->type <= MOD)) {
    if (output->type >= COS && output->type <= LOG) {
      functionProcessing(&output);
    } else if (output->type >= PLUS && output->type <= MOD) {
      RESULT_CODE = FAILURE;
    }
  } else {
    while (getSize(output) > 2 || getSize(temp) > 1) {
      if (output->type >= PLUS && output->type <= MOD) {
        transferOperationToTemp(&output, &temp);
      } else if (output->type >= COS && output->type <= LOG) {
        functionProcessing(&output);
      } else if ((getSize(output) <= 2 && getSize(temp) > 1) ||
                 (output->type == NUMBER && temp->type == NUMBER)) {
        transferNumberToOutput(&temp, &output);
      } else if (output->type == NUMBER) {
        numberProcessing(&output, &temp);
      }
    }
  }
  *result = output->value;
  deleteStack(&temp);
  deleteStack(&output);

  return RESULT_CODE;
}

// adds two operands
void numberProcessing(stack_t **output, stack_t **temp) {
  double operand1 = (*output)->value;
  double operand2 = 0;
  double rawResult = 0;

  pop(output);
  if ((*output)->type >= PLUS && (*output)->type <= MOD) {
    push(temp, operand1, 0, NUMBER);
    while ((*output)->type >= PLUS && (*output)->type <= MOD) {
      push(temp, 0, 0, (*output)->type);
      pop(output);
    }
  } else if (((*output)->type >= COS && (*output)->type <= LOG) ||
             (*output)->type == NUMBER) {
    if ((*output)->type >= COS && (*output)->type <= LOG) {
      calcFunctions((*output)->value, (*output)->type, &rawResult);
      pop(output);
      operand2 = rawResult;
    } else if ((*output)->type == NUMBER) {
      operand2 = (*output)->value;
      pop(output);
    }
    calcOperations(operand2, operand1, (*temp)->type, &rawResult);
    pop(temp);
    push(output, rawResult, 0, NUMBER);
  }
}

// solves the function
void functionProcessing(stack_t **output) {
  double rawResult = 0;

  calcFunctions((*output)->value, (*output)->type, &rawResult);
  pop(output);
  push(output, rawResult, 0, NUMBER);
}

// moves operators to a temporary stack
void transferOperationToTemp(stack_t **output, stack_t **temp) {
  while ((*output)->type >= PLUS && (*output)->type <= MOD) {
    push(temp, 0, 0, (*output)->type);
    pop(output);
  }
}

// moves the numbers back to the output stack
void transferNumberToOutput(stack_t **temp, stack_t **output) {
  while ((*temp)->type == NUMBER) {
    push(output, (*temp)->value, 0, (*temp)->type);
    pop(temp);
  }
}

void calcOperations(double operand1, double operand2, type_t type,
                    double *result) {
  if (type == PLUS) {
    *result = operand1 + operand2;
  } else if (type == MINUS) {
    *result = operand1 - operand2;
  } else if (type == MULT) {
    *result = operand1 * operand2;
  } else if (type == DIV) {
    *result = operand1 / operand2;
  } else if (type == POWER) {
    *result = pow(operand1, operand2);
  } else if (type == MOD) {
    *result = fmod(operand1, operand2);
  }
}

void calcFunctions(double x, type_t type, double *result) {
  if (type == COS) {
    *result = cos(x);
  } else if (type == SIN) {
    *result = sin(x);
  } else if (type == TAN) {
    *result = tan(x);
  } else if (type == ACOS) {
    *result = acos(x);
  } else if (type == ASIN) {
    *result = asin(x);
  } else if (type == ATAN) {
    *result = atan(x);
  } else if (type == SQRT) {
    *result = sqrt(x);
  } else if (type == LN) {
    *result = log(x);
  } else if (type == LOG) {
    *result = log10(x);
  }
}