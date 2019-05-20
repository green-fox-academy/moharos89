//
// Created by Bence on 2019.05.20..
//

#include "linked_list.h"

void append(linked_list_t *head, int data)
{
    linked_list_t *new_node = (linked_list_t *) malloc(sizeof(linked_list_t));
    new_node->data = data;
    new_node->next = NULL;
    linked_list_t *it = head;
    while (it->next != NULL) {
        it = it->next;
    }
    it->next = new_node;
}

linked_list_t *push_front(linked_list_t *head, int data)
{
    linked_list_t *new_node = (linked_list_t *) malloc(sizeof(linked_list_t));
    new_node->next = head;
    new_node->data = data;
    return new_node;
}

void insert(linked_list_t *head, linked_list_t *insertAfter, int data)
{
    linked_list_t *it = head;
    while (it->next != NULL) {
        if (it == insertAfter) {
            linked_list_t *new_node = (linked_list_t *) malloc(sizeof(linked_list_t));
            new_node->data = data;
            new_node->next = insertAfter->next;
            insertAfter->next = new_node;
        }
    }
}

int size(linked_list_t *head)
{
    linked_list_t *it = head;
    int counter = 0;
    while (it != NULL) {
        it = it->next;
        counter++;
    }
    return counter;
}

int empty(linked_list_t *head)
{
    if (head == NULL) {
        return 1;
    } else {
        return 0;
    }
}

linked_list_t *pop_front(linked_list_t *head)
{
    linked_list_t *temp = head->next;
    free(head);
    head = NULL;
    return temp;
}

int delete_by_value(linked_list_t **head, int value)
{
    int counter = 0;
    linked_list_t *it = *head;
    while (it != NULL) {
        if (it == *head && it->data == value) {
            counter++;
            linked_list_t *firstTemp = *head;
            *head = (*head)->next;
            free(firstTemp);
            firstTemp = NULL;
        } else if (it->next->data == value) {
            counter++;
            linked_list_t *temp = it->next;
            it->next = it->next->next;
            free(temp);
            temp = NULL;
            it = it->next;
        }
    }
    return counter;
}

linked_list_t *search(linked_list_t *head, int value)
{
    linked_list_t *it = head;
    while (it != NULL) {
        if (it->data == value) {
            return it;
        } else {
            it = it->next;
        }
    }
    return NULL;
}