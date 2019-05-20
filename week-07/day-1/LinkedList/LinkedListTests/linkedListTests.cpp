//
// Created by Bence on 2019.05.20..
//

#include "gtest/gtest.h"

extern "C" {
#include "linked_list.h"
}

TEST(linkedList, TestAppendOneNewNode)
{
    //Arrange
    linked_list_t *list = (linked_list_t *) malloc(sizeof(linked_list_t));
    list->data = 2;
    list->next =NULL;
    //Act
    append(list , 3);
    int result = list->next->data;
    //Assert
    ASSERT_EQ(result , 3);
    free(list->next);
    list->next = NULL;
    free(list);
    list = NULL;
}