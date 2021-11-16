

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <stdint.h>

typedef struct _node_ Node;
typedef struct _list_ List;

struct _node_{
    int32_t data;
    Node *next;
};

struct _list_{
    Node *head;
    Node *tail;
    uint32_t count;
};

typedef struct _dnode_ Dnode;
typedef struct _dlist_ Dlist;

struct _dnode_{
    int32_t data;
    Dnode *prev;
    Dnode *next;
};

struct _dlist_{
    Dnode *head;
    Dnode *tail;
    uint32_t count;
};



List new_list();
uint32_t list_count(const List *list);
List* list_add_at_head(List *list,int32_t element);
List* list_add_at_tail(List *list,int32_t element);
List* list_delete_at_head(List *list);
List* list_delete_at_tail(List *list);
uint8_t list_lookup(const List *list,int32_t element);


List* add_element_after_an_element(List *list, int32_t element, int32_t key);
List* delete_specified_element(List *list, int32_t element);
uint8_t list_compare(const List *list1,const List *list2);
List * list_union(List *list1 , List *list2);
List * list_intersection(List *list1 , List *list2);
List * list_add_unique(List *list, int32_t element);

int32_t find_max_in_list(const List *list);
int32_t find_min_in_list(const List *list);

Dlist new_doubly_list();

Dlist* dlist_add_at_head(Dlist *dlist,int32_t element);
Dlist* dlist_add_at_tail(Dlist *dlist,int32_t element);
Dlist* dlist_remove_element(Dlist *dlist,int32_t element);
Dlist* dlist_delete_element(Dlist *dlist, int32_t element);
uint8_t dlist_lookup(Dlist *dlist, int32_t element);





List* reverse_list(List *list);

#endif // LIST_H_INCLUDED
