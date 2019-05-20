//
// Created by Bence on 2019.05.20..
//

#ifndef LINKEDLIST_LINKED_LIST_H
#define LINKEDLIST_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list *next;
} linked_list_t;

void append(linked_list_t *head , int data);

linked_list_t *push_front(linked_list_t *head , int data);

void insert(linked_list_t * head , linked_list_t* after , int data);

int size(linked_list_t *head);

int empty(linked_list_t *head);

linked_list_t *pop_front(linked_list_t *head);

int delete_by_value(linked_list_t **head , int value);

linked_list_t *search(linked_list_t *head , int value);

#endif //LINKEDLIST_LINKED_LIST_H
