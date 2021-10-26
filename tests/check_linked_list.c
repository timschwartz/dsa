#include <check.h>
#include <linked_list.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

START_TEST (test_empty_list)
{
    sl_list_t l = sl_list();
    ck_assert_ptr_eq(l.head, NULL);
}
END_TEST

START_TEST (test_make_list)
{
    sl_list_t l = sl_list();
    sl_node_t *n;
    uint64_t check_array[10];

    int i = 0;
    for(i = 0; i < sizeof(check_array) / sizeof(uint64_t); i++)
    {
        check_array[i] = rand();
        l = sl_list_add(l, check_array[i]);
    }

    n = l.head;
    for(i = 0; i < sizeof(check_array) / sizeof(uint64_t); i++)
    {
        ck_assert_int_eq(n->element, check_array[i]);
        n = n->next;
    }
}
END_TEST

START_TEST (test_insert_after)
{
    sl_list_t l = sl_list();
    l.head = sl_node_empty();
    ck_assert_ptr_eq(l.head->next, NULL);
    sl_node_t *n = sl_node_insert_after(l.head, 0xDEADBEEF);
    ck_assert_ptr_eq(l.head->next, n);
}
END_TEST

START_TEST (test_remove_after)
{
    sl_list_t l = sl_list();
    l.head = sl_node_empty();
    l.head->element = 0xCAFEBABE;
    sl_node_t *n = sl_node_insert_after(l.head, 0xDEADBEEF);
    n = sl_node_insert_after(n, 0xDECAFBAD);

    ck_assert_int_eq(l.head->next->element, 0xDEADBEEF);
    ck_assert_int_eq(l.head->next->next->element, 0xDECAFBAD);

    n = sl_node_remove_after(l.head);
    ck_assert_int_eq(l.head->next->element, 0xDECAFBAD);
}
END_TEST

START_TEST (test_insert_beginning)
{
    sl_list_t l = sl_list();
    l.head = sl_node_empty();
    l.head->element = 0xDEADBEEF;
    l = sl_list_insert_beginning(l, 0xCAFEBABE);
    ck_assert_int_eq(l.head->element, 0xCAFEBABE);
    ck_assert_int_eq(l.head->next->element, 0xDEADBEEF);
}
END_TEST

START_TEST (test_remove_beginning)
{
    sl_list_t l = sl_list();
    l.head = sl_node_empty();
    l.head->element = 0xDEADBEEF;
    l = sl_list_insert_beginning(l, 0xCAFEBABE);
    ck_assert_int_eq(l.head->element, 0xCAFEBABE);
    ck_assert_int_eq(l.head->next->element, 0xDEADBEEF);

    l = sl_list_remove_beginning(l);
    ck_assert_int_eq(l.head->element, 0xDEADBEEF);
}
END_TEST

Suite *linked_list_suite(void)
{
    Suite *s = suite_create("linked_list");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_empty_list);
    tcase_add_test(tc_core, test_make_list);
    tcase_add_test(tc_core, test_insert_after);
    tcase_add_test(tc_core, test_remove_after);
    tcase_add_test(tc_core, test_insert_beginning);
    tcase_add_test(tc_core, test_remove_beginning);
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
