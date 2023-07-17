#include "test_core.h"

START_TEST(CREDIT_CALCULATOR_ANNUITY1) {
  long double creditAmount = 89124.34;
  int period = 9;
  long double percent = 17;
  int type = ANNUITY;
  long double payment = 0;
  long double overpayment = 0;
  long double totalPayment = 0;
  CreditCalculator(creditAmount, period, percent, type, &payment, &overpayment,
                   &totalPayment, NULL, NULL);

  ck_assert_ldouble_eq_tol(payment, 10617.3, 1e-2);
  ck_assert_ldouble_eq_tol(overpayment, 6431.36, 1e-2);
  ck_assert_ldouble_eq_tol(totalPayment, 95555.70, 1e-2);
}
END_TEST
START_TEST(CREDIT_CALCULATOR_ANNUITY2) {
  long double creditAmount = 439809.32;
  int period = 1;
  long double percent = 1;
  int type = ANNUITY;
  long double payment = 0;
  long double overpayment = 0;
  long double totalPayment = 0;
  CreditCalculator(creditAmount, period, percent, type, &payment, &overpayment,
                   &totalPayment, NULL, NULL);

  ck_assert_ldouble_eq_tol(payment, 440175.83, 1e-2);
  ck_assert_ldouble_eq_tol(overpayment, 366.51, 1e-2);
  ck_assert_ldouble_eq_tol(totalPayment, 440175.83, 1e-2);
}
END_TEST
START_TEST(CREDIT_CALCULATOR_ANNUITY3) {
  long double creditAmount = 439809.32;
  int period = 1;
  long double percent = 0.01;
  int type = ANNUITY;
  long double payment = 0;
  long double overpayment = 0;
  long double totalPayment = 0;
  CreditCalculator(creditAmount, period, percent, type, &payment, &overpayment,
                   &totalPayment, NULL, NULL);

  ck_assert_ldouble_eq_tol(payment, 439812.99, 1e-2);
  ck_assert_ldouble_eq_tol(overpayment, 3.67, 1e-2);
  ck_assert_ldouble_eq_tol(totalPayment, 439812.99, 1e-2);
}
END_TEST
START_TEST(CREDIT_CALCULATOR_ANNUITY4) {
  long double creditAmount = 100;
  int period = 600;
  long double percent = 15;
  int type = ANNUITY;
  long double payment = 0;
  long double overpayment = 0;
  long double totalPayment = 0;
  CreditCalculator(creditAmount, period, percent, type, &payment, &overpayment,
                   &totalPayment, NULL, NULL);

  ck_assert_ldouble_eq_tol(payment, 1.25, 1e2);
  ck_assert_ldouble_eq_tol(overpayment, 650, 1e2);
  ck_assert_ldouble_eq_tol(totalPayment, 750, 1e2);
}
END_TEST
START_TEST(CREDIT_CALCULATOR_ANNUITY5) {
  long double creditAmount = 324812.24;
  int period = 600;
  long double percent = 15;
  int type = ANNUITY;
  long double payment = 0;
  long double overpayment = 0;
  long double totalPayment = 0;
  CreditCalculator(creditAmount, period, percent, type, &payment, &overpayment,
                   &totalPayment, NULL, NULL);

  ck_assert_ldouble_eq_tol(payment, 4062.51, 1e2);
  ck_assert_ldouble_eq_tol(overpayment, 2112693.76, 1e2);
  ck_assert_ldouble_eq_tol(totalPayment, 2437506.00, 1e2);
}
END_TEST

START_TEST(CREDIT_CALCULATOR_DIFFERENTIATED1) {
  long double creditAmount = 89124.34;
  int period = 9;
  long double percent = 17;
  int type = DIFFERENTIATED;
  long double payment = 0;
  long double overpayment = 0;
  long double totalPayment = 0;
  long double max = 0;
  long double min = 0;
  CreditCalculator(creditAmount, period, percent, type, &payment, &overpayment,
                   &totalPayment, &max, &min);

  ck_assert_ldouble_eq_tol(max, 11165.30, 1e2);
  ck_assert_ldouble_eq_tol(min, 10042.99, 1e2);
  ck_assert_ldouble_eq_tol(overpayment, 6312.97, 1e2);
  ck_assert_ldouble_eq_tol(totalPayment, 95437.31, 1e2);
}
END_TEST
START_TEST(CREDIT_CALCULATOR_DIFFERENTIATED2) {
  long double creditAmount = 439809.32;
  int period = 1;
  long double percent = 1;
  int type = DIFFERENTIATED;
  long double payment = 0;
  long double overpayment = 0;
  long double totalPayment = 0;
  long double max = 0;
  long double min = 0;
  CreditCalculator(creditAmount, period, percent, type, &payment, &overpayment,
                   &totalPayment, &max, &min);

  ck_assert_ldouble_eq_tol(max, 440175.83, 1e2);
  ck_assert_ldouble_eq_tol(min, 440175.83, 1e2);
  ck_assert_ldouble_eq_tol(overpayment, 366.51, 1e2);
  ck_assert_ldouble_eq_tol(totalPayment, 440175.83, 1e2);
}
END_TEST
START_TEST(CREDIT_CALCULATOR_DIFFERENTIATED3) {
  long double creditAmount = 439809.32;
  int period = 1;
  long double percent = 0.01;
  int type = DIFFERENTIATED;
  long double payment = 0;
  long double overpayment = 0;
  long double totalPayment = 0;
  long double max = 0;
  long double min = 0;
  CreditCalculator(creditAmount, period, percent, type, &payment, &overpayment,
                   &totalPayment, &max, &min);

  ck_assert_ldouble_eq_tol(max, 439812.99, 1e2);
  ck_assert_ldouble_eq_tol(min, 439812.99, 1e2);
  ck_assert_ldouble_eq_tol(overpayment, 3.67, 1e2);
  ck_assert_ldouble_eq_tol(totalPayment, 439812.99, 1e2);
}
END_TEST
START_TEST(CREDIT_CALCULATOR_DIFFERENTIATED4) {
  long double creditAmount = 100;
  int period = 600;
  long double percent = 15;
  int type = DIFFERENTIATED;
  long double payment = 0;
  long double overpayment = 0;
  long double totalPayment = 0;
  long double max = 0;
  long double min = 0;
  CreditCalculator(creditAmount, period, percent, type, &payment, &overpayment,
                   &totalPayment, &max, &min);

  ck_assert_ldouble_eq_tol(max, 1.42, 1e2);
  ck_assert_ldouble_eq_tol(min, 0.17, 1e2);
  ck_assert_ldouble_eq_tol(overpayment, 375.63, 1e2);
  ck_assert_ldouble_eq_tol(totalPayment, 475.63, 1e2);
}
END_TEST
START_TEST(CREDIT_CALCULATOR_DIFFERENTIATED5) {
  long double creditAmount = 324812.24;
  int period = 600;
  long double percent = 15;
  int type = DIFFERENTIATED;
  long double payment = 0;
  long double overpayment = 0;
  long double totalPayment = 0;
  long double max = 0;
  long double min = 0;
  CreditCalculator(creditAmount, period, percent, type, &payment, &overpayment,
                   &totalPayment, &max, &min);

  ck_assert_ldouble_eq_tol(max, 4601.51, 1e2);
  ck_assert_ldouble_eq_tol(min, 548.12, 1e2);
  ck_assert_ldouble_eq_tol(overpayment, 1220075.98, 1e3);
  ck_assert_ldouble_eq_tol(totalPayment, 1544888.22, 1e3);
}
END_TEST

Suite *st_credit(void) {
  Suite *s = suite_create("st_credit");
  TCase *tc = tcase_create("credit_tc");

  tcase_add_test(tc, CREDIT_CALCULATOR_ANNUITY1);
  tcase_add_test(tc, CREDIT_CALCULATOR_ANNUITY2);
  tcase_add_test(tc, CREDIT_CALCULATOR_ANNUITY3);
  tcase_add_test(tc, CREDIT_CALCULATOR_ANNUITY4);
  tcase_add_test(tc, CREDIT_CALCULATOR_ANNUITY5);

  tcase_add_test(tc, CREDIT_CALCULATOR_DIFFERENTIATED1);
  tcase_add_test(tc, CREDIT_CALCULATOR_DIFFERENTIATED2);
  tcase_add_test(tc, CREDIT_CALCULATOR_DIFFERENTIATED3);
  tcase_add_test(tc, CREDIT_CALCULATOR_DIFFERENTIATED4);
  tcase_add_test(tc, CREDIT_CALCULATOR_DIFFERENTIATED5);

  suite_add_tcase(s, tc);
  return s;
}