//
// Created by avilay on 12/19/24.
//

#include "include/list.h"
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * list_version() {
  return "0.0.1";
}

List* list_new(const size_t element_size, const size_t capacity) {
  void* data = calloc(capacity, element_size);
  if (data == NULL) {
    errno = ENOMEM;
    return NULL;
  }

  List* list = calloc(1, sizeof(List));
  if (list == NULL) {
    free(data);
    errno = ENOMEM;
    return NULL;
  }

  list->_data = data;
  list->_element_size = element_size;
  list->_capacity = capacity;
  list->len = 0;
  return list;
}

void list_free(List* list) {
  if (list != NULL) {
    free(list->_data);
  }
  free(list);
}

int list_append(List* list, const void* element) {
  // if (plist == NULL || *plist == NULL) {
  //   errno = EINVAL;
  //   return -1;
  // }
  if (list == NULL || element == NULL) {
    errno = EINVAL;
    return -1;
  }

  // List* list = *plist;

  // Need to expand memory
  if (list->len == list->_capacity) {
    size_t new_capacity = list->_capacity * 2;
    void* new_data = realloc(list->_data, (new_capacity * list->_element_size));
    if (new_data == NULL) {
      errno = ENOMEM;
      return -1;
    }
    list->_data = new_data;
    list->_capacity = new_capacity;
  }

  // Happy case
  void* ptr = list->_data + (list->len * list->_element_size);
  memcpy(ptr, element, list->_element_size);
  list->len++;
  return 0;
}

void* list_value_at(const List * list, const size_t idx) {
  if (list == NULL) {
    errno = EINVAL;
    return NULL;
  }

  void* ptr = list->_data + (idx * list->_element_size);
  return ptr;
}

void* list_pop(List* list) {
  if (list == NULL || list->len == 0) {
    errno = EINVAL;
    return NULL;
  }
  void* last_element = list->_data + ((list->len - 1) * (list->_element_size));
  void* last_element_copy = malloc(list->_element_size);
  if (last_element_copy == NULL) {
    errno = ENOMEM;
    return NULL;
  }
  memcpy(last_element_copy, last_element, list->_element_size);
  list->len -= 1;
  return last_element_copy;
}

void* list_remove_at(List* list, size_t idx) {
  // Basic algo: lets say I have [0, 1, 2, 3, 4, 5, 6]
  // and I want to remove idx 2
  // first copy the element to somewhere else
  // 2_ = copy(idx 2)
  // Now move all the elements starting from 2 to one over -
  // [0, 1, *, 3, 4, 5, 6] => [0, 1, 3, 4, 5, 6]
  // decrease the len of the array

  if (list == NULL || list->len == 0) {
    errno = EINVAL;
    return NULL;
  }

  void* tbd_element = list->_data + (idx * list->_element_size);
  void* tbd_element_copy = malloc(list->_element_size);
  if (tbd_element == NULL) {
    errno = ENOMEM;
    return NULL;
  }
  memcpy(tbd_element_copy, tbd_element, list->_element_size);

  size_t n_elements_to_copy = list->len - idx - 1;
  memcpy(tbd_element, tbd_element + list->_element_size, n_elements_to_copy * list->_element_size);
  list->len -= 1;

  return tbd_element_copy;
}
