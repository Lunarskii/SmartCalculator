#include "test_core.h"

START_TEST(TEST_STACK1) {
  stack_t *test;
  push(&test, 1, 2, NUMBER);
  push(&test, 3, 4, NUMBER);

  stack_t output1 = peek(&test);
  pop(&test);
  stack_t output2 = peek(&test);
  pop(&test);

  // printf("output1: ");
  // printStruct(output1);
  // printf("output2: ");
  // printStruct(output2);

  ck_assert_double_eq(output1.value, 3);
  ck_assert_double_eq(output2.value, 1);
  ck_assert_int_eq(output1.priority, 4);
  ck_assert_int_eq(output2.priority, 2);
}
END_TEST
START_TEST(TEST_STACK2) {
  stack_t *test;
  push(&test, 1, 2, NUMBER);
  push(&test, 3, 4, NUMBER);

  double operand1 = 0;
  double operand2 = 0;
  popValue(&test, &operand1);
  popValue(&test, &operand2);

  ck_assert_double_eq(operand1, 3);
  ck_assert_double_eq(operand2, 1);
}
END_TEST
// START_TEST(TEST_STACK) {

// } END_TEST
// START_TEST(TEST_STACK) {

// } END_TEST
// START_TEST(TEST_STACK) {

// } END_TEST

Suite *st_stack(void) {
  Suite *s = suite_create("st_stack");
  TCase *tc = tcase_create("stack_tc");

  tcase_add_test(tc, TEST_STACK1);
  tcase_add_test(tc, TEST_STACK2);

  suite_add_tcase(s, tc);
  return s;
}
