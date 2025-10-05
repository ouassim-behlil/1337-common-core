#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "../code/libft.h"

static int  g_del_call_count;

static void reset_del_counter(void)
{
    g_del_call_count = 0;
}

static void tracking_del(void *ptr)
{
    if (ptr)
    {
        ++g_del_call_count;
        free(ptr);
    }
}

static int *alloc_int(int value)
{
    int *ptr;

    ptr = malloc(sizeof(*ptr));
    assert(ptr != NULL);
    *ptr = value;
    return (ptr);
}

static t_list *raw_node(void *content)
{
    t_list *node;

    node = malloc(sizeof(*node));
    assert(node != NULL);
    node->content = content;
    node->next = NULL;
    return (node);
}

static void free_list_nodes(t_list *lst)
{
    while (lst)
    {
        t_list *next = lst->next;

        free(lst);
        lst = next;
    }
}

static void test_ft_lstnew_basic(void)
{
    const char  *text = "libft";
    t_list      *node;

    node = ft_lstnew((void *)text);
    assert(node != NULL);
    assert(node->content == text);
    assert(node->next == NULL);
    free(node);
}

static void test_ft_lstnew_null_content(void)
{
    t_list  *node;

    node = ft_lstnew(NULL);
    assert(node != NULL);
    assert(node->content == NULL);
    assert(node->next == NULL);
    free(node);
}

static void test_ft_lstadd_front_basic(void)
{
    t_list  *head;
    t_list  *new_node;

    head = raw_node("second");
    new_node = raw_node("first");
    ft_lstadd_front(&head, new_node);
    assert(head == new_node);
    assert(head->next != NULL);
    assert(head->next->content == (void *)"second");
    free_list_nodes(head);
}

static void test_ft_lstadd_front_null_pointer(void)
{
    t_list  *orphan;

    orphan = raw_node("orphan");
    ft_lstadd_front(NULL, orphan);
    assert(orphan->next == NULL);
    free(orphan);
}

static void test_ft_lstadd_front_null_new(void)
{
    t_list  *head;

    head = raw_node("solo");
    ft_lstadd_front(&head, NULL);
    assert(head->content == (void *)"solo");
    assert(head->next == NULL);
    free(head);
}

static void test_ft_lstadd_back_basic(void)
{
    t_list  *head;
    t_list  *second;

    head = raw_node("first");
    second = raw_node("second");
    ft_lstadd_back(&head, second);
    assert(head->next == second);
    assert(second->next == NULL);
    free_list_nodes(head);
}

static void test_ft_lstadd_back_empty_list(void)
{
    t_list  *head;
    t_list  *node;

    head = NULL;
    node = raw_node("solo");
    ft_lstadd_back(&head, node);
    assert(head == node);
    assert(head->next == NULL);
    free(head);
}

static void test_ft_lstadd_back_null_pointer(void)
{
    t_list  *orphan;

    orphan = raw_node("orphan");
    ft_lstadd_back(NULL, orphan);
    assert(orphan->next == NULL);
    free(orphan);
}

static void test_ft_lstadd_back_null_new(void)
{
    t_list  *head;

    head = raw_node("solo");
    ft_lstadd_back(&head, NULL);
    assert(head->next == NULL);
    free(head);
}

static void test_ft_lstsize_counts_nodes(void)
{
    t_list  *head;

    head = raw_node("first");
    head->next = raw_node("second");
    head->next->next = raw_node("third");
    assert(ft_lstsize(head) == 3);
    free_list_nodes(head);
    assert(ft_lstsize(NULL) == 0);
}

static void test_ft_lstlast_returns_tail(void)
{
    t_list  *head;
    t_list  *tail;

    head = raw_node("first");
    head->next = raw_node("second");
    head->next->next = raw_node("third");
    tail = ft_lstlast(head);
    assert(tail != NULL);
    assert(tail->content == (void *)"third");
    assert(tail->next == NULL);
    free_list_nodes(head);
    assert(ft_lstlast(NULL) == NULL);
}

static void test_ft_lstdelone_calls_del(void)
{
    t_list  *node;

    reset_del_counter();
    node = raw_node(alloc_int(42));
    ft_lstdelone(node, tracking_del);
    assert(g_del_call_count == 1);
}

static void test_ft_lstclear_clears_list(void)
{
    t_list  *head;

    reset_del_counter();
    head = raw_node(alloc_int(1));
    head->next = raw_node(alloc_int(2));
    head->next->next = raw_node(alloc_int(3));
    ft_lstclear(&head, tracking_del);
    assert(head == NULL);
    assert(g_del_call_count == 3);
}

static void increment_int(void *ptr)
{
    if (ptr)
        ++*(int *)ptr;
}

static void test_ft_lstiter_applies_callback(void)
{
    int     values[3] = {1, 2, 3};
    t_list  *head;

    head = raw_node(&values[0]);
    head->next = raw_node(&values[1]);
    head->next->next = raw_node(&values[2]);
    ft_lstiter(head, increment_int);
    assert(values[0] == 2);
    assert(values[1] == 3);
    assert(values[2] == 4);
    free_list_nodes(head);
    ft_lstiter(NULL, increment_int);
}

static void test_ft_lstiter_with_null_function(void)
{
    int     value;
    t_list  *node;

    value = 10;
    node = raw_node(&value);
    ft_lstiter(node, NULL);
    assert(value == 10);
    free(node);
}

static void *duplicate_int_and_offset(void *ptr)
{
    int *dup;

    dup = malloc(sizeof(*dup));
    assert(dup != NULL);
    *dup = *(int *)ptr + 5;
    return (dup);
}

static void test_ft_lstmap_builds_new_list(void)
{
    int     values[3] = {4, 7, 11};
    t_list  *head;
    t_list  *mapped;
    t_list  *iter_orig;
    t_list  *iter_map;

    reset_del_counter();
    head = raw_node(&values[0]);
    head->next = raw_node(&values[1]);
    head->next->next = raw_node(&values[2]);
    mapped = ft_lstmap(head, duplicate_int_and_offset, tracking_del);
    assert(mapped != NULL);
    iter_orig = head;
    iter_map = mapped;
    while (iter_orig && iter_map)
    {
        int *mapped_value;

        mapped_value = (int *)iter_map->content;
        assert(mapped_value != NULL);
        assert(*mapped_value == *(int *)iter_orig->content + 5);
        assert(iter_map != iter_orig);
        iter_orig = iter_orig->next;
        iter_map = iter_map->next;
    }
    assert(iter_orig == NULL);
    assert(iter_map == NULL);
    assert(g_del_call_count == 0);
    ft_lstclear(&mapped, tracking_del);
    assert(mapped == NULL);
    assert(g_del_call_count == 3);
    free_list_nodes(head);
}

static void test_ft_lstmap_null_inputs(void)
{
    int     value;
    t_list  *node;
    t_list  *result;

    value = 21;
    node = raw_node(&value);
    result = ft_lstmap(NULL, duplicate_int_and_offset, tracking_del);
    assert(result == NULL);
    result = ft_lstmap(node, NULL, tracking_del);
    assert(result == NULL);
    result = ft_lstmap(node, duplicate_int_and_offset, NULL);
    assert(result == NULL);
    free(node);
}

void    run_ft_lst_tests(void)
{
    test_ft_lstnew_basic();
    test_ft_lstnew_null_content();
    test_ft_lstadd_front_basic();
    test_ft_lstadd_front_null_pointer();
    test_ft_lstadd_front_null_new();
    test_ft_lstadd_back_basic();
    test_ft_lstadd_back_empty_list();
    test_ft_lstadd_back_null_pointer();
    test_ft_lstadd_back_null_new();
    test_ft_lstsize_counts_nodes();
    test_ft_lstlast_returns_tail();
    test_ft_lstdelone_calls_del();
    test_ft_lstclear_clears_list();
    test_ft_lstiter_applies_callback();
    test_ft_lstiter_with_null_function();
    test_ft_lstmap_builds_new_list();
    test_ft_lstmap_null_inputs();
    printf("ft_lst*: all %s tests passed\n", "17");
}
