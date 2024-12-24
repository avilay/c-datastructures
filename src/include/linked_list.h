//
// Created by avilay on 12/19/24.
//

#pragma once

typedef struct LinkedListNode {
  void* data;
  struct LinkedListNode* next;
} LinkedListNode;

LinkedListNode* linked_list_new(void* data);
void linked_list_free(LinkedListNode* node);
LinkedListNode* linked_list_add(LinkedListNode* head, void* data);

