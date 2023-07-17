#ifndef SRC_POLISH_H_
#define SRC_POLISH_H_

#include <math.h>
#include <string.h>

#include "../stack/stack.h"

#define SUCCESS 1
#define FAILURE 0

#define ANNUITY 1
#define DIFFERENTIATED 2

int SmartCalculator(char *string, long double x, char *outputResult);
void CreditCalculator(long double creditAmount, int period, long double percent,
                      int type, long double *payment, long double *overpayment,
                      long double *totalPayment, long double *max,
                      long double *min);
void DepositCalculator(long double depositAmount, int period,
                       long double percent, long double tax, int frequency,
                       int capitalization, long double *payment,
                       long double *invoiceSum, long double *taxSum);
stack_t *polishNotation(char *input, long double x, stack_t *output,
                        int *RESULT_CODE);

int isTab(char c);
int isDec(char c);
int isSign(char c);
int isOperation(char c);
int isMod(char *string);
int isX(char c);
int isDot(char c);
int isUnaryOperator(char *string, int elemNumber);

int isNumber(char *string, int elemNumber);
int isFunc(char *string, int *funcType);

int isWrongBrackets(char *string);
int isWrongSigns(char *string);
int isEmptyString(char *string);

void appendNumber(stack_t **numberStack, char **number, long double value);
int appendFunc(stack_t **numberStack, char **function, long double x,
               int funcType);
void appendOperation(stack_t **stack, stack_t **output, char **string);
void appendBracket(stack_t **stack, char **string);

void transferToOutput(stack_t **stack, stack_t **output, char **string);
void transferToOutput2(stack_t **stack, stack_t **output);

void deleteSpaces(char *src, char *dest);

int detPriority(char operation);
int detOperation(char operation);

int calc(stack_t *output, double *result);
void numberProcessing(stack_t **output, stack_t **temp);
void functionProcessing(stack_t **output);
void transferOperationToTemp(stack_t **output, stack_t **temp);
void transferNumberToOutput(stack_t **temp, stack_t **output);
void calcOperations(double operand1, double operand2, type_t type,
                    double *result);
void calcFunctions(double x, type_t type, double *result);

#endif  // SRC_POLISH_H_
