AM_CFLAGS = @CHECK_CFLAGS@ -I../include

TESTS = check_linked_list check_stack
check_PROGRAMS = check_linked_list check_stack

check_linked_list_SOURCES = check_linked_list.c $(top_builddir)/src/linked_list.c
check_linked_list_LDADD = @CHECK_LIBS@

check_stack_SOURCES = check_stack.c $(top_builddir)/src/stack.c
check_stack_LDADD = @CHECK_LIBS@
