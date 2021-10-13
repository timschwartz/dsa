#include <check.h>
#include <linked_list.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

START_TEST (test_empty_list)
{
    linked_list_t *l = linked_list();
    ck_assert_int_eq(l->element, 0);
    ck_assert_ptr_eq(l->next, NULL);
}
END_TEST

START_TEST (test_make_list)
{
    linked_list_t *l = linked_list();
    uint64_t check_array[10];

    int i = 0;
    for(i = sizeof(check_array) / sizeof(uint64_t) - 1; i >= 0; i--)
    {
        check_array[i] = rand();
        l = linked_list_add(check_array[i], l);
    }

    i = 0;
    do
    {
        printf("Checking %d: %d\n", i, l->element);
        ck_assert_int_eq(l->element, check_array[i]);
        i++;
        l = l->next;
    } while(l->next != NULL);
}
END_TEST

Suite *linked_list_suite(void)
{
    Suite *s = suite_create("linked_list");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_empty_list);
    tcase_add_test(tc_core, test_make_list);
    suite_add_tcase(s, tc_core);
    return s;
}

int main(void)
{
    srand(time(NULL));
    int failed_count = 0;
    Suite *s = linked_list_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    failed_count = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
