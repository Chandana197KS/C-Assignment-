
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include "list.h"

void test_new_list()
{
    List list = new_list();
    List *test_list = &list;
    assert(test_list->count == 0);
    assert(test_list->head == NULL);
    assert(test_list->tail == NULL);
}

void test_list_add_and_delete_at_head()
{
    List list = new_list();
    List *test_list = &list;

    list_add_at_head(test_list,15);
    list_add_at_head(test_list,80);


    assert(test_list->head->data == 80);
    assert(test_list->tail->data == 15);
    assert(test_list->tail->next == NULL);


    list_delete_at_head(test_list);
    assert(test_list->head->data == 15);
}

void test_list_add_and_delete_at_tail()
{
    List list = new_list();
    List *test_list = &list;

    list_add_at_tail(test_list,50);
    list_add_at_tail(test_list,80);
    list_add_at_tail(test_list,70);

    assert(test_list->tail->data == 70);
    assert(test_list->tail->next == NULL);
    assert(test_list->head->next->data == 80);

    list_delete_at_tail(test_list);
    assert(test_list->tail->data == 80);
}


void test_list_count()
{
    List list = new_list();
    List *test_list = &list;

    list_add_at_tail(test_list,50);
    list_add_at_tail(test_list,80);
    list_add_at_tail(test_list,70);

    assert(test_list->count == 3);
}
void test_list_lookup()
{
    List list = new_list();
    List *test_list = &list;

    list_add_at_tail(test_list,50);
    list_add_at_tail(test_list,80);
    list_add_at_tail(test_list,70);

    assert(list_lookup(test_list, 50) == 1);
    assert(list_lookup(test_list, 60) == 0);

}

void test_find_max_and_min_in_list()
{
    List list = new_list();
    List *test_list = &list;

    list_add_at_tail(test_list,50);
    list_add_at_tail(test_list,80);
    list_add_at_tail(test_list,70);

    assert(find_max_in_list(test_list) == 80);
    assert(find_min_in_list(test_list) == 50);
}


void test_reverse_list()
{
    List list = new_list();
    List *test_list = &list;
    List *test_reverse;

    list_add_at_tail(test_list,50);
    list_add_at_tail(test_list,80);
    list_add_at_tail(test_list,70);

    assert(test_list->tail->data == 70);
    assert(test_list->tail->next == NULL);
    assert(test_list->head->next->data == 80);

    test_reverse = reverse_list(test_list);

    assert(test_reverse->head->data == 70);
    assert(test_reverse->head->next->data == 80);
    assert(test_reverse->tail->data == 50);

}

void test_add_element_after_an_element()
{
    List list = new_list();
    List *test_list = &list;

    list_add_at_tail(test_list,50);
    list_add_at_tail(test_list,80);
    list_add_at_tail(test_list,70);

    test_list = add_element_after_an_element(test_list,60,80);
    assert(test_list->head->data == 50);
    assert(test_list->head->next->data == 80);
    assert(test_list->head->next->next->data == 60);
    assert(test_list->count == 4);

    add_element_after_an_element(test_list,100,70);
    assert(test_list->head->data== 50);
    assert(test_list->head->next->data== 80);
    assert(test_list->head->next->next->data == 60);
    assert(test_list->head->next->next->next->data == 70);
    assert(test_list->head->next->next->next->next->data == 100);
    assert(test_list->head->next->next->next->next->next == NULL);

    assert(test_list->tail->data == 100);
    assert(test_list->count == 5);
}

void test_delete_specified_element()
{
    List list = new_list();
    List *test_list = &list;

    list_add_at_tail(test_list,50);
    list_add_at_tail(test_list,60);
    list_add_at_tail(test_list,70);
    list_add_at_tail(test_list,80);
    list_add_at_tail(test_list,90);
    list_add_at_tail(test_list,100);

    delete_specified_element(test_list, 50);
    assert(test_list->head->data == 60);
    assert(test_list->count == 5);
    assert(test_list->tail->data == 100);

    delete_specified_element(test_list, 90);
    assert(test_list->head->data == 60);
    assert(test_list->head->next->data == 70);
    assert(test_list->head->next->next->data == 80);
    assert(test_list->head->next->next->next->data == 100);
    assert(test_list->count == 4);
    assert(test_list->tail->data == 100);

    delete_specified_element(test_list, 70);
    assert(test_list->head->data == 60);
    assert(test_list->head->next->data == 80);
    assert(test_list->head->next->next->data == 100);
    assert(test_list->head->next->next->next == NULL);
    assert(test_list->count == 3);
    assert(test_list->tail->data == 100);

    delete_specified_element(test_list, 60);
    assert(test_list->head->data == 80);
    assert(test_list->head->next->data == 100);
    assert(test_list->head->next->next == NULL);
    assert(test_list->count == 2);
    assert(test_list->tail->data == 100);

    delete_specified_element(test_list, 100);
    assert(test_list->head->data == 80);
    assert(test_list->head->next == NULL);
    assert(test_list->count == 1);
    assert(test_list->tail->data == 80);


}

void test_list_compare()
{
    //Create lists
    List list1 = new_list();
    List *test_list1 = &list1;

    list_add_at_tail(test_list1,50);
    list_add_at_tail(test_list1,60);
    list_add_at_tail(test_list1,70);
    list_add_at_tail(test_list1,80);
    list_add_at_tail(test_list1,90);
    list_add_at_tail(test_list1,100);

    List list2 = new_list();
    List *test_list2 = &list2;

    list_add_at_tail(test_list2,50);
    list_add_at_tail(test_list2,60);
    list_add_at_tail(test_list2,70);
    list_add_at_tail(test_list2,80);
    list_add_at_tail(test_list2,90);
    list_add_at_tail(test_list2,100);

    List list3 = new_list();
    List *test_list3 = &list3;

    list_add_at_tail(test_list3,50);

    assert(list_compare(test_list1,test_list2) == 1);
    assert(list_compare(test_list2,test_list3) == 0);


}

void test_list_union()
{
    List list1 = new_list();
    List *test_list1 = &list1;

    list_add_at_tail(test_list1,50);
    list_add_at_tail(test_list1,60);
    list_add_at_tail(test_list1,70);
    list_add_at_tail(test_list1,80);


    List list2 = new_list();
    List *test_list2 = &list2;

    list_add_at_tail(test_list2,25);
    list_add_at_tail(test_list2,35);
    list_add_at_tail(test_list2,45);
    list_add_at_tail(test_list2,80);

    List list3 = new_list();
    List *test_union = &list3;

    test_union = list_union(test_list1,test_list2);

    assert(list_lookup(test_union,50) == 1);
    assert(list_lookup(test_union,60) == 1);
    assert(list_lookup(test_union,70) == 1);
    assert(list_lookup(test_union,80) == 1);
    assert(list_lookup(test_union,25) == 1);
    assert(list_lookup(test_union,35) == 1);
    assert(list_lookup(test_union,45) == 1);
    assert(test_union->count == 7);
}

void test_list_intersection()
{
    List list1 = new_list();
    List *test_list1 = &list1;

    list_add_at_tail(test_list1,50);
    list_add_at_tail(test_list1,60);
    list_add_at_tail(test_list1,70);
    list_add_at_tail(test_list1,80);


    List list2 = new_list();
    List *test_list2 = &list2;

    list_add_at_tail(test_list2,25);
    list_add_at_tail(test_list2,50);
    list_add_at_tail(test_list2,45);
    list_add_at_tail(test_list2,80);

    List list3 = new_list();
    List *test_intersect = &list3;

    test_intersect = list_intersection(test_list1,test_list2);

    assert(list_lookup(test_intersect,80) == 1);
    assert(list_lookup(test_intersect,50) == 1);
    assert(list_lookup(test_intersect,90) == 0);
    assert(test_intersect->count == 2);
}

void test_list_add_unique()
{
    List list = new_list();
    List *test_list = &list;

    list_add_unique(test_list,50);
    list_add_unique(test_list,60);
    list_add_unique(test_list,50);
    list_add_unique(test_list,40);

    assert(test_list->count == 3);
    assert(list_lookup(test_list,50) == 1);
    assert(list_lookup(test_list,60) == 1);
    assert(list_lookup(test_list,40) == 1);

}

void test_dlist_add_at_head()
{
    Dlist dlist = new_doubly_list();
    Dlist *test_dlist = &dlist;

    dlist_add_at_head(test_dlist,50);
    dlist_add_at_head(test_dlist,60);
    dlist_add_at_head(test_dlist,70);
    dlist_add_at_head(test_dlist,80);

    assert(test_dlist->tail->data == 50);
    assert(test_dlist->tail->prev->data == 60);
    assert(test_dlist->tail->next == NULL);
    assert(test_dlist->head->data == 80);
    assert(test_dlist->head->next->data == 70);
    assert(test_dlist->head->prev == NULL);
}

void test_dlist_add_at_tail()
{
    Dlist dlist = new_doubly_list();
    Dlist *test_dlist = &dlist;

    dlist_add_at_tail(test_dlist,50);
    dlist_add_at_tail(test_dlist,60);
    dlist_add_at_tail(test_dlist,70);
    dlist_add_at_tail(test_dlist,80);

    assert(test_dlist->tail->data == 80);
    assert(test_dlist->tail->prev->data == 70);
    assert(test_dlist->tail->next == NULL);
    assert(test_dlist->head->data == 50);
    assert(test_dlist->head->next->data == 60);
    assert(test_dlist->head->prev == NULL);
}

void test_dlist_delete_element()
{
    Dlist dlist = new_doubly_list();
    Dlist *test_dlist = &dlist;

    dlist_add_at_tail(test_dlist,50);
    dlist_add_at_tail(test_dlist,60);
    dlist_add_at_tail(test_dlist,70);
    dlist_add_at_tail(test_dlist,80);
    dlist_add_at_tail(test_dlist,90);

    dlist_delete_element(test_dlist,90);

    assert(test_dlist->tail->data == 80);
    assert(test_dlist->tail->next == NULL);
    assert(test_dlist->tail->prev->data == 70);
    assert(test_dlist->count == 4);

    dlist_delete_element(test_dlist,50);

    assert(test_dlist->head->prev == NULL);
    assert(test_dlist->head->data == 60);
    assert(test_dlist->head->next->data == 70);
    assert(test_dlist->count == 3);

    dlist_delete_element(test_dlist,70);

    assert(test_dlist->head->next == test_dlist->tail);
    assert(test_dlist->tail->prev == test_dlist->head);
    assert(test_dlist->count == 2);


}
void test_dlist_lookup()
{
    Dlist dlist = new_doubly_list();
    Dlist *test_dlist = &dlist;

    dlist_add_at_tail(test_dlist,50);
    dlist_add_at_tail(test_dlist,60);
    dlist_add_at_tail(test_dlist,70);

    assert(dlist_lookup(test_dlist,60) == 1);
    assert(dlist_lookup(test_dlist,50) == 1);
    assert(dlist_lookup(test_dlist,70) == 1);
    assert(dlist_lookup(test_dlist,80) == 0);

}



int main(){

    test_new_list();
    test_list_add_and_delete_at_head();
    test_list_add_and_delete_at_tail();
    test_list_count();
    test_list_lookup();
    test_find_max_and_min_in_list();
    test_add_element_after_an_element();
    test_reverse_list();
    test_delete_specified_element();
    test_list_compare();
    test_list_union();
    test_list_intersection();
    test_list_add_unique();
    test_dlist_add_at_head();
    test_dlist_add_at_tail();
    test_dlist_delete_element();


    return 0;

}
