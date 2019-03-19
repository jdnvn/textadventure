#ifndef ITEMS_H
#define ITEMS_H
#include "rooms.h"
#include <stdbool.h>

struct Item {
  struct Item *next;
  char name[100];
  char description[100];
  char use[100];
};

typedef struct Item Item;

//Players inventory declared
Item *inventory;

struct Item *item(char newName[], char newDesc[], char use[], struct Item *ptr);

char *item_name(struct Item *item);

char *item_description(struct Item *item);

void addToInventory(struct Item *toAdd);

struct Item *item_next(struct Item *item);

struct Item *item_take(char name[], struct Item *items);

void item_drop(char name[], Item *roomItems, Item *inventory2);

bool hasItem(Item *inventory2, char *item);

void item_use(char *name);

#endif