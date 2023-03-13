#include "test_core.h"

START_TEST(SMART_CALCULATOR_NUMBERS1) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("2 + 3 / 4", 0, result);  // 2 3 4 / +

  ck_assert_str_eq(result, "2.7500000");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS2) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("-3 - 4", 0, result);  // -3 4 -

  ck_assert_str_eq(result, "-7.0000000");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS3) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("5", 0, result);  // 5

  ck_assert_str_eq(result, "5.0000000");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS4) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("(2 + 3 / 4)", 0, result);  // 2 3 4 / +

  ck_assert_str_eq(result, "2.7500000");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS5) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("2 - -3", 0, result);  // 2 -3 -

  ck_assert_str_eq(result, "5.0000000");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS6) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("+2 + 3", 0, result);  // 2 3 +

  ck_assert_str_eq(result, "5.0000000");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS7) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("-(1 - 152)", 0, result);

  ck_assert_str_eq(result, "151.0000000");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS8) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("-1 * -1 * (-1 * -1)", 0, result);

  ck_assert_str_eq(result, "1.0000000");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS9) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("-1 * -1 * -1", 0, result);

  ck_assert_str_eq(result, "-1.0000000");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS10) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("-1 * (10 - -15)", 0, result);

  ck_assert_str_eq(result, "-25.0000000");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS11) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("1 - 3 * -1 + 2 / -2 ^ 3", 0, result);

  ck_assert_str_eq(result, "3.7500000");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS12) {
  char result[512] = {0};
  int RESULT_CODE =
      SmartCalculator("(1 - 5) + (2 * (3 - 5) + (2 * (4 / 8)))", 0, result);

  ck_assert_str_eq(result, "-7.0000000");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS13) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("9124.234 + 3849.1239", 0, result);

  ck_assert_str_eq(result, "12973.3579000");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS14) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator(".1 / .1", 0, result);

  ck_assert_str_eq(result, "1.0000000");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS15) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("1 / 0", 0, result);

  ck_assert_str_eq(result, "INF");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS16) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("0 / 0", 0, result);

  ck_assert_str_eq(result, "NAN");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS17) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator(
      "-.9 / -0.3 + (((((128 / 16) * 2) + 3) - 4) / 8)", 0, result);

  ck_assert_str_eq(result, "4.8750000");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS18) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("1 - (-4)", 0, result);

  ck_assert_str_eq(result, "5.0000000");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS19) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("5 mod 3", 0, result);

  ck_assert_str_eq(result, "2.0000000");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS20) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("442 mod 35 * 28", 0, result);

  ck_assert_str_eq(result, "616.0000000");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS21) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("442 mod 35 ^ 3", 0, result);

  ck_assert_str_eq(result, "442.0000000");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS22) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("2893.124 mod 129.324 mod 1.32", 0, result);

  ck_assert_str_eq(result, "0.4760000");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS23) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("+", 0, result);

  ck_assert_str_eq(result, "ERROR");
  ck_assert_int_eq(RESULT_CODE, FAILURE);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS24) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("-", 0, result);

  ck_assert_str_eq(result, "ERROR");
  ck_assert_int_eq(RESULT_CODE, FAILURE);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS25) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("*", 0, result);

  ck_assert_str_eq(result, "ERROR");
  ck_assert_int_eq(RESULT_CODE, FAILURE);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS26) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("mod", 0, result);

  ck_assert_str_eq(result, "ERROR");
  ck_assert_int_eq(RESULT_CODE, FAILURE);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS27) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("mod 3", 0, result);

  ck_assert_str_eq(result, "ERROR");
  ck_assert_int_eq(RESULT_CODE, FAILURE);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS28) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("* 3", 0, result);

  ck_assert_str_eq(result, "ERROR");
  ck_assert_int_eq(RESULT_CODE, FAILURE);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS29) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("3 *", 0, result);

  ck_assert_str_eq(result, "ERROR");
  ck_assert_int_eq(RESULT_CODE, FAILURE);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS30) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("- 3", 0, result);

  ck_assert_str_eq(result, "-3.0000000");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS31) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("1.1.2 / 2.1", 0, result);

  ck_assert_str_eq(result, "ERROR");
  ck_assert_int_eq(RESULT_CODE, FAILURE);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS32) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("x", 2.5, result);

  ck_assert_str_eq(result, "2.5000000");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS33) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("x + x", 2.5, result);

  ck_assert_str_eq(result, "5.0000000");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS34) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("x / x", 2.5, result);

  ck_assert_str_eq(result, "1.0000000");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS35) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("45 * (*28 + 31)", 0, result);

  ck_assert_str_eq(result, "ERROR");
  ck_assert_int_eq(RESULT_CODE, FAILURE);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS36) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("-2^2", 0, result);

  ck_assert_str_eq(result, "4.0000000");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS37) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("2^2^3", 0, result);

  ck_assert_str_eq(result, "64.0000000");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_NUMBERS38) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("3,5*2,8", 0, result);

  ck_assert_str_eq(result, "9.8000000");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST

START_TEST(SMART_CALCULATOR_FUNCTIONS1) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("cos(1)", 0, result);

  ck_assert_str_eq(result, "0.5403023");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_FUNCTIONS2) {
  char result[512] = {0};
  int RESULT_CODE =
      SmartCalculator("cos(1 + cos(cos(3 + 4 * 5) + 10) / 2)", 0, result);

  ck_assert_str_eq(result, "0.8773672");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_FUNCTIONS3) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("cos(x)", 1.5, result);

  ck_assert_str_eq(result, "0.0707372");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_FUNCTIONS4) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("cos(125 + 90328 / sin(185))", 0, result);

  ck_assert_str_eq(result, "0.9990858");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_FUNCTIONS5) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("tan(9009142.324)", 0, result);

  ck_assert_str_eq(result, "0.2161690");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_FUNCTIONS6) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("atan(3892.1247032)", 0, result);

  ck_assert_str_eq(result, "1.5705394");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_FUNCTIONS7) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("log(3941.1348983123)", 0, result);

  ck_assert_str_eq(result, "3.5956213");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_FUNCTIONS8) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("sqrt(930124.1324903)", 0, result);

  ck_assert_str_eq(result, "964.4294336");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_FUNCTIONS9) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("ln(2089349.12740)", 0, result);

  ck_assert_str_eq(result, "14.5523632");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_FUNCTIONS10) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("-cos(1)", 0, result);

  ck_assert_str_eq(result, "-0.5403023");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_FUNCTIONS11) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("acos(0.92304912)", 0, result);

  ck_assert_str_eq(result, "0.3948635");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_FUNCTIONS12) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("asin(0.998329140)", 0, result);

  ck_assert_str_eq(result, "1.5129800");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_FUNCTIONS13) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("cos(-)", 0, result);

  ck_assert_str_eq(result, "ERROR");
  ck_assert_int_eq(RESULT_CODE, FAILURE);
}
END_TEST
START_TEST(SMART_CALCULATOR_FUNCTIONS14) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("cos(-1)", 0, result);

  ck_assert_str_eq(result, "0.5403023");
  ck_assert_int_eq(RESULT_CODE, SUCCESS);
}
END_TEST
START_TEST(SMART_CALCULATOR_FUNCTIONS15) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("cos(*)", 0, result);

  ck_assert_str_eq(result, "ERROR");
  ck_assert_int_eq(RESULT_CODE, FAILURE);
}
END_TEST
START_TEST(SMART_CALCULATOR_FUNCTIONS16) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("cos(*/+-)", 0, result);

  ck_assert_str_eq(result, "ERROR");
  ck_assert_int_eq(RESULT_CODE, FAILURE);
}
END_TEST
START_TEST(SMART_CALCULATOR_FUNCTIONS17) {
  char result[512] = {0};
  int RESULT_CODE = SmartCalculator("cos(cos(1.1.2))", 0, result);

  ck_assert_str_eq(result, "ERROR");
  ck_assert_int_eq(RESULT_CODE, FAILURE);
}
END_TEST

Suite *st_smart(void) {
  Suite *s = suite_create("st_smart");
  TCase *tc = tcase_create("smart_tc");

  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS1);   // 2 + 3 / 4
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS2);   // -3 - 4
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS3);   // 5
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS4);   // (2 + 3 / 4)
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS5);   // 2 - -3
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS6);   // +2 + 3
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS7);   // -(1 - 152)
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS8);   // -1 * -1 * (-1 * -1)
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS9);   // -1 * -1 * -1
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS10);  // -1 * (10 - -15)
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS11);  // 1 - 3 * -1 + 2 / -2^3
  tcase_add_test(
      tc,
      SMART_CALCULATOR_NUMBERS12);  // (1 - 5) + (2 * (3 - 5) + (2 * (4 / 8)))
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS13);  // 9124.234 + 3849.1239
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS14);  // .1 / .1
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS15);  // 1 / 0
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS16);  // 0 / 0
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS17);  // -.9 / -0.3 + (((((128 /
                                                   // 16) * 2) + 3) - 4) / 8)
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS18);  // 1 - (-4)
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS19);  // 5 mod 3
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS20);  // 442 mod 35 * 28
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS21);  // 442 mod 35 ^ 3
  tcase_add_test(tc,
                 SMART_CALCULATOR_NUMBERS22);  // 2893.124 mod 129.324 mod 1.32
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS23);  // +
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS24);  // -
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS25);  // *
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS26);  // mod
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS27);  // mod 3
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS28);  // * 3
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS29);  // 3 *
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS30);  // - 3
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS31);  // 1.1.2 / 2.1
  tcase_add_test(tc,
                 SMART_CALCULATOR_NUMBERS32);  // x                    x == 2.5
  tcase_add_test(tc,
                 SMART_CALCULATOR_NUMBERS33);  // x + x                x == 2.5
  tcase_add_test(tc,
                 SMART_CALCULATOR_NUMBERS34);  // x / x                x == 2.5
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS35);  // 45 * (*28 + 31)
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS36);  // -2^2
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS37);  // 2^2^3
  tcase_add_test(tc, SMART_CALCULATOR_NUMBERS38);  // 3,5 * 2,8

  tcase_add_test(tc, SMART_CALCULATOR_FUNCTIONS1);  // cos(1)
  tcase_add_test(
      tc,
      SMART_CALCULATOR_FUNCTIONS2);  // cos(1 + cos(cos(3 + 4 * 5) + 10) / 2)
  tcase_add_test(tc,
                 SMART_CALCULATOR_FUNCTIONS3);  // cos(x)              x = 1.5
  tcase_add_test(tc,
                 SMART_CALCULATOR_FUNCTIONS4);  // cos(125 + 90328 / sin(185))
  tcase_add_test(tc, SMART_CALCULATOR_FUNCTIONS5);   // tan(9009142.324)
  tcase_add_test(tc, SMART_CALCULATOR_FUNCTIONS6);   // atan(3892.1247032)
  tcase_add_test(tc, SMART_CALCULATOR_FUNCTIONS7);   // log(3941.1348983123)
  tcase_add_test(tc, SMART_CALCULATOR_FUNCTIONS8);   // sqrt(930124.1324903)
  tcase_add_test(tc, SMART_CALCULATOR_FUNCTIONS9);   // ln(2089349.12740)
  tcase_add_test(tc, SMART_CALCULATOR_FUNCTIONS10);  // -cos(1)
  tcase_add_test(tc, SMART_CALCULATOR_FUNCTIONS11);  // acos(0.92304912)
  tcase_add_test(tc, SMART_CALCULATOR_FUNCTIONS12);  // asin(0.998329140)
  tcase_add_test(tc, SMART_CALCULATOR_FUNCTIONS13);  // cos(-)
  tcase_add_test(tc, SMART_CALCULATOR_FUNCTIONS14);  // cos(-1)
  tcase_add_test(tc, SMART_CALCULATOR_FUNCTIONS15);  // cos(*)
  tcase_add_test(tc, SMART_CALCULATOR_FUNCTIONS16);  // cos(*/+-)
  tcase_add_test(tc, SMART_CALCULATOR_FUNCTIONS17);  // cos(cos(1.1.2))

  suite_add_tcase(s, tc);
  return s;
}