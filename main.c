#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "items.h"
#include "rooms.h"

int main(void) {
  initializeMap();
  Room *currentRoom = room0;
  inventory = item("", "", "", NULL);
  printf("You wake up lying on the floor of a room.\n");
  printf("Use < commands > for a list of commands...\n");
  bool gameOver = false;

  while(!gameOver){
    printf("---------------------------------------------------------\n\n");
    char *input;
    char *command;
    char buffer[25];
    
    //Shows description and prompts user
    printf("Enter Command: ");
    fgets(buffer, 25, stdin);
    char s[2] = " ";
    command = strtok(buffer, s);
    input = strtok(NULL, s);
    printf("\n");

    // Commands
    if(strncasecmp(command, "look", 4) == 0){
    	look(currentRoom);
    }
    else if(strncasecmp(command, "inventory", 9) == 0){
      printf("Inventory: ");
      Item *invent = inventory;
      while(invent != NULL){
        printf("%s\n", invent->name);
        invent = invent->next;
      }
      if(inventory->next == NULL){
        printf("<Empty>\n");
      }
      printf("\n");
    }
    else if(strncasecmp(command, "go", 2) == 0){
      if(strncasecmp(input, "north", 5) == 0) {
        if(currentRoom->north != NULL){
          currentRoom = currentRoom->north;
        }else{ printf("You can't go north.\n"); }
      }
      else if (strncasecmp(input, "south", 5) == 0) { 
        if(currentRoom->south != NULL){
          currentRoom = currentRoom->south;
        } 
        else if (currentRoom != room5){ 
          printf("You can't go south.\n"); 
        }
      } 
      else if (strncasecmp(input, "east", 4) == 0) {
        if(currentRoom->east != NULL){
          currentRoom = currentRoom->east;
        }else{ printf("You can't go east.\n"); }
      }
      else if (strncasecmp(input, "west", 4) == 0) {
        if(currentRoom->west != NULL){
          currentRoom = currentRoom->west;
        }else{ printf("You can't go west.\n"); }
      }
      else if (strncasecmp(input, "up", 2) == 0) {
        if(currentRoom->up != NULL){
          currentRoom = currentRoom->up;
        }else{ printf("You can't go up.\n"); }
      }
      else if (strncasecmp(input, "down", 4) == 0) {
        if(currentRoom->down != NULL){
          currentRoom = currentRoom->down;
        }else{ printf("You can't go down.\n"); }
      }else{
        printf("Please use a valid direction.\n");
      }
    }
    else if (strncasecmp(command, "take", 4) == 0) {
      if(currentRoom->items == NULL){
        printf("There's nothing to take.\n");
      }else{
        Item *toTake = item_take(input, currentRoom->items);
        if(toTake == NULL){
          printf("There is no such item in the room.\n");
        }else{
          printf("Picked up %s\n%s\n", item_name(toTake), item_description(toTake));
        }
      }
    }
    else if (strncasecmp(command, "drop", 4) == 0) {
      if(strcmp(input, "")==0){
        printf("What do you want to drop?");
      }else{
        if(inventory == NULL){
          printf("There's nothing to drop.\n\n");
        }else{
          item_drop(input, currentRoom->items, inventory);
          printf("Item was dropped\n");
        }
      }
    }
    else if (strncasecmp(command, "use", 3) == 0){
      if ((strncasecmp(input, "key", 3) == 0) && (currentRoom == room5) && (hasItem(inventory, "key"))) {
        printf("NICE JOB, YOU HAVE ESCAPED THE HOUSE AND YOU WON THE GAME!\nNext time don't get caught snooping around your creepy neighbor's property...");
        freeInv(inventory);
        freeAll();
        exit(0);
      }else{
        item_use(input);
      }
    } 
    else if (strncasecmp(command, "commands", 8) == 0){
      printf("Commands: \ngo <direction> : moves to the room of a specified direction(north, south, east, west, up or down)\ntake <object> : picks up a specified item\ndrop <object> : drops a specified item\nuse <object> : uses a specified item\nlook : looks around the current room\ninventory : displays the items in your inventory\nquit : quits game\n\n");
    } 
    else if(strncasecmp(command, "quit", 4) == 0){
    		printf("Exit Successful\n");
        freeInv(inventory);
        freeAll();
        printf("\n");
    		exit(0);
    }
    else {
      printf("Please use valid command.\n");
    }
  }

  return 0;
}