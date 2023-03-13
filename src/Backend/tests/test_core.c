#include "test_core.h"

int main(void) {
  Suite *list[] = {st_stack(), st_smart(), st_credit(), st_deposit(), NULL};
  for (Suite **current_testcase = list; *current_testcase != NULL;
       current_testcase++) {
    SRunner *sr = srunner_create(*current_testcase);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);  // CK_VERBOSE - ALL | CK_ENV - ONLY FAILS
    srunner_free(sr);
  }

  return 0;
}
