//
// Created by avilay on 12/19/24.
//

#pragma once
#include <stddef.h>

typedef struct List {
  void* _data;
  size_t _element_size;
  size_t len;
  size_t _capacity;
} List;

char* list_version();

List* list_new(size_t element_size, size_t capacity);
void list_free(List* list);
int list_append(List* plist, const void* element);
void* list_value_at(const List* list, size_t idx);
void* list_pop(List* list);
void* list_remove_at(List* list, size_t idx);
