//
// Created by avilay on 12/19/24.
//

#include <stdio.h>
#include <list.h>
#include <linked_list.h>

typedef struct Cookie {
  char* flavor;
  int calories;
} Cookie;

void print_cookie(Cookie* cookie) {
  printf("%p: <Cookie(flavor=%s, calories=%d)>\n", cookie, cookie->flavor, cookie->calories);
}

void print_list(List* list) {
  printf("List has %lu elements\n", list->len);
  for (int i = 0; i < list->len; i++) {
    Cookie* cookie = list_value_at(list, i);
    print_cookie(cookie);
  }
}

void demo_list() {
  printf("Size of cookie: %lu\n", sizeof(Cookie));

  Cookie chocolate_chip = {.flavor="Chocolate Chip", .calories=200};
  Cookie snicker_doodle = {.flavor="Snicker Doodle", .calories=180};
  Cookie oatmeal_raisin = {.flavor="Oatmeal Raisin", .calories=180};
  Cookie mint_chip = {.flavor="Mint Chip", .calories=200};
  Cookie double_chocolate_chip = {.flavor="Double Chocolate Chip", .calories=200};
  Cookie semi_sweet_cookie = {.flavor="SemiSweet Chip", .calories=200};

  List* cookies = list_new(sizeof(Cookie), 2);
  list_append(cookies, &chocolate_chip);
  list_append(cookies, &snicker_doodle);
  list_append(cookies, &oatmeal_raisin);
  list_append(cookies, &mint_chip);
  list_append(cookies, &double_chocolate_chip);
  list_append(cookies, &semi_sweet_cookie);
  print_list(cookies);

  Cookie* cookie = list_pop(cookies);
  puts("\nPopped cookie");
  print_cookie(cookie);
  puts("\n");

  print_list(cookies);

  cookie = list_remove_at(cookies, 2);
  puts("\nRemoved cookie");
  print_cookie(cookie);
  puts("\n");

  print_list(cookies);
  list_free(cookies);
}

void demo_linked_list() {
  Cookie chocolate_chip = {.flavor="Chocolate Chip", .calories=200};
  Cookie snicker_doodle = {.flavor="Snicker Doodle", .calories=180};
  Cookie oatmeal_raisin = {.flavor="Oatmeal Raisin", .calories=180};
  Cookie mint_chip = {.flavor="Mint Chip", .calories=200};
  Cookie double_chocolate_chip = {.flavor="Double Chocolate Chip", .calories=200};
  Cookie semi_sweet_cookie = {.flavor="SemiSweet Chip", .calories=200};

  LinkedListNode* head = linked_list_new(&chocolate_chip);
  // linked_list_add(&head, &snicker_doodle);
  // linked_list_add(&head, &oatmeal_raisin);
  // linked_list_add(&head, &mint_chip);
  // linked_list_add(&head, &double_chocolate_chip);
  // linked_list_add(&head, &semi_sweet_cookie);
  head = linked_list_add(head, &chocolate_chip);
  head = linked_list_add(head, &snicker_doodle);
  head = linked_list_add(head, &oatmeal_raisin);
  head = linked_list_add(head, &mint_chip);
  head = linked_list_add(head, &double_chocolate_chip);
  head = linked_list_add(head, &semi_sweet_cookie);

  LinkedListNode* curr = head;
  while (curr != NULL) {
    Cookie* cookie = curr->data;
    print_cookie(cookie);
    curr = curr->next;
  }
  linked_list_free(head);
}

unsigned long hash(unsigned char* bytes) {
  unsigned long hash = 5381;
  int c;
  while ((c = *bytes++)) {
    hash = ((hash << 5) + hash) + c;

  }
}

int main() {
  demo_linked_list();
  // demo_list();
}