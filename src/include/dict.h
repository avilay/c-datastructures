//
// Created by avilay on 12/19/24.
//

#pragma once
#include <stddef.h>

typedef struct KeyValue {
  void* key;
  void* value;
} KeyValue;

typedef struct Dict {
  size_t _key_size;
  size_t _value_size;
  size_t _capacity;
  size_t len;
  KeyValue** _chained_addrs;
} Dict;

Dict* dict_new(size_t key_size, size_t value_size);
void dict_free(Dict* dict);

void* dict_get(Dict* dict, const void* key);
void dict_set(Dict* dict, const void* key, void* value);
void dict_remove(Dict* dict, const void* key);