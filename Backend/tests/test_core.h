#ifndef SRC_BACKEND_TESTS_TEST_CORE_H_
#define SRC_BACKEND_TESTS_TEST_CORE_H_

#include <check.h>

#include "../calculator.h"

Suite *st_stack(void);
Suite *st_smart(void);
Suite *st_credit(void);
Suite *st_deposit(void);

#endif  // SRC_BACKEND_TESTS_TEST_CORE_H_
