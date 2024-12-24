//
// Created by avilay on 12/19/24.
//

#include "include/dict.h"
#include <errno.h>
#include <stdlib.h>

unsigned long _calc_hash(void* key, size_t key_size) {return 0;}

Dict * dict_new(size_t key_size, size_t value_size) {
  size_t capacity = 1000;
  KeyValue** chained_addrs = calloc(capacity, sizeof(KeyValue*));
  if (chained_addrs == NULL) {
    errno = ENOMEM;
    return NULL;
  }
  Dict* dict = malloc(sizeof(Dict));
  if (dict == NULL) {
    free(chained_addrs);
    errno = ENOMEM;
    return NULL;
  }

  dict->_key_size = key_size;
  dict->_value_size = value_size;
  dict->_chained_addrs = chained_addrs;
  dict->_capacity = capacity;
  dict->len = 0;
  return dict;
}

void dict_free(Dict* dict) {
  if (dict != NULL) {
    free(dict->_chained_addrs);
  }
  free(dict);
}

void* dict_get(Dict* dict, const void* key) {
  return NULL;
}

void dict_set(Dict* dict, const void* key, void* value) {
  unsigned long hash = _calc_hash(key, dict->_key_size);
  size_t idx = hash % dict->_capacity;

}

void dict_remove(Dict* dict, const void* key) {}

