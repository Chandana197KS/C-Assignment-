#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include "list.h"



//1.Create a single list with methods to add and delete elements from head and tail positions.
//Provide method to check whether an element is present in the list. Count number of elements in the list.

//Create Node variable which is a private function
static Node* _new_node_(int32_t element)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = element;
    new_node->next = NULL;
    return new_node;
}

//Create New List
List new_list()
{
    List new_list = {NULL,NULL,0};
    return new_list;
}

//Count number of elements in the list
uint32_t list_count(const List *list)
{
    assert (list != NULL);
    return list->count;
}

//Add new node at head
List * list_add_at_head(List *list, int32_t element)
{
    assert(list != NULL);
    Node *new_node = _new_node_(element);
    new_node->next = list->head;
    list->head = new_node;
    if(list->tail == NULL)
        list->tail = new_node;

    list->count++; //counts

    assert((list->head == list->tail && list->count == 1) || (list->head != list->tail && list->count != 0));

    return list;
}

//Add new node at tail
List * list_add_at_tail(List *list, int32_t element)
{
    assert(list != NULL);
    Node *new_node = _new_node_(element);
    new_node->next = NULL;

    //If nodes are present in the list
    if(list->tail != NULL)
    {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    //First Node
    else
    {
        list->tail = list->head = new_node;
    }

    //Increment Count
    ++list->count;

    assert((list->head == list->tail && list->count == 1) || (list->head != list->tail && list->count != 0));

    return list;
}
//Delete node at head
List * list_delete_at_head(List *list)
{
    assert(list != NULL);
    Node *cur;

    //Node present in the list
    if(list->count > 0)
    {
        cur = list->head;
        list->head = list->head->next;

        //If only one node in the list
        if(list->head == NULL)
            list->tail = NULL;
        //Decrement Count
        --list->count;
        //Free memory
        free(cur);
    }

    return list;

}

//Delete node at tail
List * list_delete_at_tail(List *list)
{
    assert(list != NULL);
    Node *cur,*last;

    //Only one node in the list
    if(list->count > 0)
    {
        last = list->tail;

        //Only one node in list
        if(list->tail == list->head)
            list->head = list->tail = NULL;
        //More than one node in list
        else
        {
            for(cur = list->head; cur->next != last; cur = cur->next);
            cur->next = NULL;
            list->tail = cur;
        }
        //decrement count
        --list->count;
        //free memory
        free(last);
    }
    return list;
}

//Check if element is present in the linked list
uint8_t list_lookup(const List *list,int32_t element)
{
    assert(list != NULL);
    Node *cur;
    for(cur = list->head; cur != NULL; cur = cur->next)
    {
        if(cur->data == element)
            break;
    }
    return(cur != NULL);
}

//2. Add methods to Q1 to find maximum and minimum elements in the list.

//Maximum in the list
int32_t find_max_in_list(const List *list)
{
    assert(list != NULL);
    //Check if list is empty
    assert(list->count != 0);

    Node *cur;
    int32_t max = list->head->data;
    for(cur = list->head; cur != NULL; cur = cur->next )
    {
        if(cur->data > max)
            max = cur->data;
    }
    return max;
}

//Minimum in the list
int32_t find_min_in_list(const List *list)
{
    assert(list != NULL);
    //Check if list is empty
    assert(list->count != 0);

    Node *cur;
    int32_t min = list->head->data;
    for(cur = list->head; cur != NULL; cur = cur->next)
    {
        if(cur->data < min)
            min = cur->data;
    }
    return min;
}


//3. Modify Q1 such that one can add a new element after any specified element.
List* add_element_after_an_element(List *list, int32_t element, int32_t key)
{
    assert(list != NULL);
    assert(list->count != 0);
    Node *new_node = _new_node_(element);

    Node *cur;
    for(cur = list->head; cur != NULL; cur = cur->next)
    {
        if(cur->data == key)
        {
            //Update tail if element is added at the end
            if(cur == list->tail)
                list->tail = new_node;

            new_node->next = cur->next;
            cur->next = new_node;
            list->count++;
            break;
        }
    }
    return list;
}

//4. Modify Q1 such that one can delete any specified element from the list.
List* delete_specified_element(List *list, int32_t element)
{
    assert(list != NULL || list->count != 0);
    Node *cur,*del;

    //Only one element in the list
    if(list->count == 1 && list->head->data == element)
    {
        del = list->head;
        list->head = list->tail = NULL;
        --list->count;

    }
    //More than one element
    else
    {
        cur = list->head;
        //If element is at head
        if(cur->data == element)
        {
            del = cur;
            list->head = cur->next;
            --list->count;
        }
        else
        {
          while(cur->next != NULL)
            {
                if (cur->next->data == element)
                {

                    del = cur->next;

                    //Update tail if last element is deleted
                    if(list->tail->data == del->data)
                    {
                        list->tail = cur;

                        //No element after tail
                        cur->next = NULL;

                        //Decrement Count
                        --list->count;
                        break;
                    }
                    //Link element after deleted element to previous element.
                    else
                        cur->next = cur->next->next;

                    //Decrement Count
                    --list->count;

                }
                cur = cur->next;
            }
        }


    }
    free(del);
    return list;

}



//5. Write a method to reverse the elements in the same list.
List* reverse_list(List *list)
{
    assert(list != NULL);
    assert(list->count != 0);
    //Reverse List
    List reverse = new_list();
    List *rev = &reverse;
    Node *cur;

    for(cur = list->head; cur != NULL; cur = cur->next)
        list_add_at_head(rev,cur->data);

    return rev;

}

//6. Create two separate single lists. Check two list are same. If the two lists have the same number of elements in the same order, then they are treated as same.

uint8_t list_compare(const List *list1,const List *list2)
{
    assert(list1 != NULL && list2 != NULL);


    //Check if two lists are of same length
    if(list1->count != list2->count)
        return 0;

    Node *cur1,*cur2;
    cur1 = list1->head;
    cur2 = list2->head;

    while(cur1 != NULL && cur2 != NULL)
    {
        if(cur1->data != cur2->data)
            return 0;

        //If the node is identical go to next node
        cur1 = cur1->next;
        cur2 = cur2->next;

    }
    //Return 1 if all the nodes are identical
    return 1;

}

//7. Write a method which creates the union of elements from two lists.
List * list_union(List *list1 , List *list2)
{
    assert(list1 != NULL && list2 != NULL);
    Node *cur1 = list1->head;
    Node *cur2 = list2->head;

    List union_ls = new_list();
    List *union_list = &union_ls;

    //Add all elements of list 1 to union list
    while(cur1 != NULL)
    {
        list_add_at_tail(union_list,cur1->data);
        cur1 = cur1->next;
    }
    //Add elements that are not in list1 to union list from list2
    while(cur2 != NULL)
    {
        if(list_lookup(union_list,cur2->data) != 1)
            list_add_at_tail(union_list,cur2->data);

        cur2 = cur2->next;
    }

    return union_list;
}

//8. Write a method which creates the intersection of elements from two lists
List * list_intersection(List *list1 , List *list2)
{
    assert(list1 != NULL && list2 != NULL);
    Node *cur1 = list1->head;

    List intersection_ls = new_list();
    List *intersect_list = &intersection_ls;

    //Add elements that are in both list 1 and list 2  to intersect list
    while(cur1 != NULL)
    {
        if(list_lookup(list2,cur1->data) == 1)
            list_add_at_tail(intersect_list,cur1->data);

        cur1 = cur1->next;
    }
    return intersect_list;
}

//9. Create single list such that it should always contain unique elements.
//   Care should be taken that, if element is already present in the list, you should not add it again.
List * list_add_unique(List *list, int32_t element)
{
    assert(list != NULL);

    //Only add if element is not in the list
    if(list_lookup(list,element) != 1)
        list_add_at_tail(list,element);


    return list;
}

//10. Create double linked list with methods to add, remove, to check the existence of element.

//Create Node variable which is a private function
static Dnode* _new_doubly_node_(int32_t element)
{
    Dnode *new_node = (Dnode*)malloc(sizeof(Dnode));
    new_node->data = element;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

//Create New doubly List
Dlist new_doubly_list()
{
    Dlist new_list = {NULL,NULL,0};
    return new_list;
}

//Add New node at head
Dlist* dlist_add_at_head(Dlist *dlist,int32_t element)
{
    assert(dlist != NULL);

    //Create new node
    Dnode *new_node = _new_doubly_node_(element);

    //If node is first node
    if(dlist->count == 0)
    {
        dlist->head = dlist->tail = new_node;
    }
    //Nodes are present in the list
    else
    {
        new_node->next = dlist->head;
        //Update prev pointer of previous head
        dlist->head->prev = new_node;
        dlist->head = new_node;
    }

    ++dlist->count;

    assert((dlist->head == dlist->tail && dlist->count == 1) || (dlist->head != dlist->tail && dlist->count != 0));

    return dlist;

}

//Add New node at tail
Dlist* dlist_add_at_tail(Dlist *dlist, int32_t element)
{
    assert(dlist != NULL);

    //Create new node
    Dnode *new_node = _new_doubly_node_(element);

    //If node is first node
    if(dlist->count == 0)
    {
        dlist->head=dlist->tail= new_node;
    }
    //Nodes are present in the list
    else
    {
        new_node->prev = dlist->tail;
        dlist->tail->next = new_node;
        dlist->tail = new_node;
    }
    ++dlist->count;

    assert((dlist->head == dlist->tail && dlist->count == 1) || (dlist->head != dlist->tail && dlist->count != 0));

    return dlist;
}

//Remove Specified element from list
Dlist* dlist_delete_element(Dlist *dlist, int32_t element)
{
    assert(dlist != NULL);

    Dnode *cur,*del;
    if(dlist->count > 0)
    {
        //If only one node in list
        if(dlist->count == 1 && dlist->head->data == element)
        {
            del = dlist->head;
            dlist->head = dlist->tail = NULL;
            --dlist->count;
        }
        else
        {
            for(cur = dlist->head; cur != NULL; cur = cur->next)
            {
                if(cur->data == element)
                {
                    del = cur;

                    --dlist->count;
                    //If deleted node is the first node
                    if(cur->prev == NULL)
                    {
                        dlist->head = cur->next;
                        cur->next->prev = NULL;
                        break;
                    }
                    //If deleted node is last node
                    else if(cur->next == NULL)
                    {
                        dlist->tail = cur->prev;
                        cur->prev->next = NULL;
                        break;
                    }
                    else
                    {
                        cur->next->prev = cur->prev;
                        cur->prev->next = cur->next;
                        break;
                    }

                }
            }
        }
        free(del);
    }
    return dlist;
}

//Check if element is present in the linked list
uint8_t dlist_lookup(Dlist *dlist, int32_t element)
{
    assert(dlist != NULL);
    Dnode *cur;
    for(cur = dlist->head; cur != NULL; cur = cur->next)
    {
        if(cur->data == element)
            break;
    }
    return(cur != NULL);
}
