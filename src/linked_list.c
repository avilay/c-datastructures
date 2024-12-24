//
// Created by avilay on 12/19/24.
//

#include "include/linked_list.h"
#include <stdlib.h>
#include <errno.h>

LinkedListNode* linked_list_new(void* data) {
  LinkedListNode* node = malloc(sizeof(LinkedListNode));
  if (node == NULL) {
    errno = ENOMEM;
    return NULL;
  }
  node->data = data;
  node->next = NULL;
  return node;
}

void linked_list_free(LinkedListNode* node) {
  if (node != NULL) {
    // free(node->data);
    linked_list_free(node->next);
  }
  free(node);
}

// int linked_list_add(LinkedListNode** plist, void* data) {
//   if (plist == NULL || *plist == NULL) {
//     errno = EINVAL;
//     return -1;
//   }
//   LinkedListNode* new_node = malloc(sizeof(LinkedListNode));
//   if (new_node == NULL) {
//     errno = ENOMEM;
//     return -1;
//   }
//
//   LinkedListNode* list = *plist;
//   new_node->data = data;
//   new_node->next = list;
//   *plist = new_node;
//   return 0;
// }
LinkedListNode* linked_list_add(LinkedListNode* head, void* data) {
  if (head == NULL || data == NULL) {
    errno = EINVAL;
    return NULL;
  }
  LinkedListNode* new_node = linked_list_new(data);
  if (new_node == NULL) {
    errno = ENOMEM;
    return NULL;
  }
  new_node->next = head;
  return new_node;
}