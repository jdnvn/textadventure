#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "items.h"
#include "rooms.h"


//Creates an item with a Name, Description, and pointer to another item
Item *item(char newName[], char newDesc[], char use[], Item *ptr) {
  Item *newItem = NULL;
  newItem = (Item *) malloc(sizeof(Item));
  if(newItem == NULL){
    return NULL;
  }
  strcpy(newItem->name, newName);
  strcpy(newItem->description, newDesc);
  strcpy(newItem->use, use);
  newItem->next = ptr;
  return newItem;
}      

//Returns an item's name          
char *item_name(Item *item){
  return item->name;
}

//Returns an item's description
char *item_description(Item *item){
  return item->description;
}

//Returns a the message when an item is used
char *item_use_desc(Item *item){
  return item->use;
}

//Returns an item that is being pointed to by the passed in item (list)
Item *item_next(Item *item){
  return item->next;
}

//Used in item_take, adds an item to the player's inventory
void addToInventory(Item *toAdd){
  Item *prev = NULL;
  Item *node = inventory;
  while(node != NULL){
    prev = node;
    node = node->next;
  }
  prev->next = toAdd;
}

//Method that allows the player to "pick up" an item in from a room and adds it to the inventory
Item *item_take(char name[], Item *items){
  Item *prev=NULL;
  Item *node=items;
  while(node != NULL) {
    int roomItemLen = (int)strlen(name);
    //Compares room items to user input item to find match. compares with length of input item-1 because of null character
    if (strncasecmp(item_name(node), name, roomItemLen-1) == 0) { 
      Item *take = item(item_name(node), item_description(node), item_use_desc(node), NULL);
      //Checks if it is the first item of the list
      if(strcasecmp(item_name(prev), "") == 0) {
        if(node->next==NULL){
          prev->next = NULL;
        }else {
          strcpy(node->name, item_name(node->next));
          strcpy(node->description, item_description(node->next));
          strcpy(node->use, item_use_desc(node->next));
          node->next = node->next->next;
        }
      } else {
        prev->next = node->next;
      }
      addToInventory(take);
      return take;
    }
    prev = node;
    node = node->next;
  }
  return NULL;
}

//Drops an item from your inventory and places it in the room items list
void item_drop(char name[], Item *roomItems, Item *inventory2){
  Item *prev = NULL;
  Item *node = inventory2;
  //traverses through the inventory to find item
  while(node != NULL){
    if(strncasecmp(node->name, name, (int)strlen(name)-1) == 0){
      Item *drop = item(item_name(node), item_description(node), item_use_desc(node), NULL);
      //uses dummy head item to delete item if first item
      if(strcmp(item_name(prev), "") == 0){
        if(node->next==NULL){
          prev->next = node->next;
        }else {
          strcpy(node->name, item_name(node->next));
          strcpy(node->description, item_description(node->next));
          strcpy(node->use, item_use_desc(node->next));
          node->next = node->next->next;
        }
      //if not first item, uses previous node to hop over it and delete from list
      }else {
        prev->next = node->next;
      }
      //sets drop to the first item in the room items list
      drop->next = roomItems->next;
      roomItems->next = drop;
      break;
    }
    prev = node;
    node = node->next;
  }
}

//Checks to see if an item is in the user's inventory
bool hasItem(Item *inventory2, char *item){ 
  Item *temp = inventory2;
  while(temp != NULL){ //iterate through inventory, returns true if finds item, otherwise retursn false
    if(strncasecmp(item_name(temp), item, (int)strlen(item)-1) == 0){
      return true;
    }
    temp = temp->next;
  }
  return false;
}

//Method that checks if the paramater item is in your inventory, then calls that items "use description / message", if it is, to be displayed to the console 
void item_use(char *name){
  if(hasItem(inventory, name)){
    Item *temp = inventory;
    while(temp != NULL){
      if(strncasecmp(item_name(temp), name, (int)strlen(name)-1)==0){
        printf("%s", item_use_desc(temp));
        break;
      }
      temp = temp->next;
    }
  }else{
    printf("That item is not currently in your inventory\n\n");
  }
}