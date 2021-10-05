#include <check.h>
#include <stack.h>
#include <stdlib.h>
#include <stdio.h>

START_TEST (test_new_stack)
{
    stack64_t s = stack64(5);
    ck_assert_int_eq(s.size, 5);
    ck_assert_ptr_ne(s.stack, NULL);
    ck_assert(stack64_is_empty(&s));
}
END_TEST

Suite *stack_suite(void)
{
    Suite *s = suite_create("stack");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_new_stack);
    suite_add_tcase(s, tc_core);
    return s;
}

int main(void)
{
    int failed_count = 0;
    Suite *s = stack_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    failed_count = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
