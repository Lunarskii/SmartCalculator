#include "test_core.h"

START_TEST(DEPOSIT_CALCULATOR1) {
  long double depositAmount = 500;
  int period = 365;
  long double percent = 30;
  long double tax = 35;
  int frequency = 0;
  int capitalization = 0;
  long double payment = 0;
  long double invoiceSum = 0;
  long double taxSum = 0;

  DepositCalculator(depositAmount, period, percent, tax, frequency,
                    capitalization, &payment, &invoiceSum, &taxSum);

  ck_assert_ldouble_eq(payment, 150);
  ck_assert_ldouble_eq(invoiceSum, 500);
  ck_assert_ldouble_eq(taxSum, 52.5);
}
END_TEST
START_TEST(DEPOSIT_CALCULATOR2) {
  long double depositAmount = 500;
  int period = 365;
  long double percent = 30;
  long double tax = 35;
  int frequency = 91;
  int capitalization = 1;
  long double payment = 0;
  long double invoiceSum = 0;
  long double taxSum = 0;

  DepositCalculator(depositAmount, period, percent, tax, frequency,
                    capitalization, &payment, &invoiceSum, &taxSum);

  ck_assert_ldouble_eq_tol(payment, 167.22, 1e-2);
  ck_assert_ldouble_eq_tol(invoiceSum, 667.22, 1e-2);
  ck_assert_ldouble_eq_tol(taxSum, 58.527, 1e-2);
}
END_TEST
START_TEST(DEPOSIT_CALCULATOR3) {
  long double depositAmount = 123.12;
  int period = 18000;
  long double percent = 11;
  long double tax = 35;
  int frequency = 0;
  int capitalization = 0;
  long double payment = 0;
  long double invoiceSum = 0;
  long double taxSum = 0;

  DepositCalculator(depositAmount, period, percent, tax, frequency,
                    capitalization, &payment, &invoiceSum, &taxSum);

  ck_assert_ldouble_eq_tol(payment, 667.88, 1e-2);
  ck_assert_ldouble_eq_tol(invoiceSum, 123.12, 1e-2);
  ck_assert_ldouble_eq_tol(taxSum, 0, 1e-2);
}
END_TEST

Suite *st_deposit(void) {
  Suite *s = suite_create("st_deposit");
  TCase *tc = tcase_create("deposit_tc");

  tcase_add_test(tc, DEPOSIT_CALCULATOR1);
  tcase_add_test(tc, DEPOSIT_CALCULATOR2);
  tcase_add_test(tc, DEPOSIT_CALCULATOR3);

  suite_add_tcase(s, tc);
  return s;
}