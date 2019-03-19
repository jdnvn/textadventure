#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rooms.h"
#include "items.h"

//Creates a room struct that contains a room's description and the items in a room
Room *room(char* description, Item* items){
  Room *newRoom = NULL;
  newRoom = (Room *) malloc(sizeof(Room));
  if(newRoom == NULL){
    return NULL;
  }
  strcpy(newRoom->description, description);
  newRoom->items = items;
  return newRoom;
}

//The room_exit methods allow a user to exit their room in the different directions
void room_exit_north(Room *current, Room *other){
  current->north = other;
}

void room_exit_south(Room *current, Room *other){
  current->south = other;
}

void room_exit_east(Room *current, Room *other){
  current->east = other;
}

void room_exit_west(Room *current, Room *other){
  current->west = other;
}

void room_exit_up(Room *current, Room *other){
  current->up = other;
}

void room_exit_down(Room *current, Room *other){
  current->down = other;
}

//Initializes every room with a description and a list of its items
void initializeMap(){

  room0 = room("The room is dim, only lit by the candles scattered around. There is a crimson red pentagram painted in the center of the room. There are unlocked doors to the NORTH, EAST, SOUTH, and WEST.\n", item("", "", "", item("candle", "This candle only provides a faint light.\n", "Even with this candle it is hard to see.\n\n", NULL)));

  room1 = room("The bathroom. You see a shattered mirror in the Mark Corner of the room, shards of glass are scattered on the floor. As you shift your gaze you spot a decaying corpse lying in a half filled claw footed tub. There is an unlocked door to the SOUTH.\n", item("", "", "", item("comb", "A weird spikey object, usually used for hair.\n", "Is this really the time to fix your hair?\n\n", NULL)));

  room2 = room("The kitchen. It is eerily empty of any food or utensils aside from a broken corkscrew. An empty wine cask is lying on its side, revealing a trap door going DOWN where it once stood. There are unlocked doors to the SOUTH and to the WEST.\n", item("", "", "", item("corkscrew", "Opens bottles, preferably wine\n", "Ya thirsty big guy?\n\n", NULL)));

  room3 = room("The wine cellar. There is a wine collection along the walls. Red eyes peer at you in the shadows, as rats scurry along the floor. There is a ladder to go UP\n", item("", "", "", item("key", "Slightly rusty, maybe unlocks a door?", "Generally, large locked doors require a key to open them...\n\n", NULL)));

  room4 = room("The dining room. There is a long table with a bloody cloth strewed across. A chandelier hangs above the ceiling of the room. There are unlocked doors to the NORTH and to the EAST.\n", item("","", "", item("doll", "Has a green shirt on.\n","Upon inspection this doll has a teal shirt..\n\n", NULL)));

  room5 = room("The foyer. A ragged red rug leads towards an door on the SOUTH side of the room. The door is carved out of wood and is locked behind some chain and a padlock. There are unlocked doors to the NORTH and WEST. \n", item("", "", "", item("shoe", "This is one beat-up shoe.\n", "This shoe does not fit me, nor is it mine to use.\n\n", NULL)));

  room6 = room("The master bedroom. There is a painting of Tim Richards hanging above the bed. The windows are boarded up, yet moonlight manages to seep in through the cracks. There is a ladder in the corner of the room that leads UP to an attic. There is an unlocked door to the EAST.\n", item("", "", "", item("horseshoe", "Just a single rusty horseshoe.\n", "I wonder how this horseshoe ended up in here.\n\n", NULL)));

  room7 = room("The attic. The only thing in the attic is a shrine of Marc Liberatore, surrounded by candles with a well-kept sword laying in front of the shrine. There is a ladder to go DOWN\n", item("", "", "", item("sword", "A fine blade, it glimmers in the light.", "WOW, YOU SWUNG YOUR MIGHTY SWORD\n\n", NULL)));

  //room0
  room_exit_north(room0, room1);
  room_exit_south(room0, room4);
  room_exit_east(room0, room2);
  room_exit_west(room0, room6);

  //room1
  room_exit_south(room1, room0);

  //room2
  room_exit_west(room2, room0);
  room_exit_down(room2, room3);
  room_exit_south(room2, room5);

  //room3
  room_exit_up(room3, room2);

  //room4
  room_exit_north(room4, room0);
  room_exit_east(room4, room5);

  //room5
  room_exit_north(room5, room2);
  room_exit_west(room5, room4);

  //room6
  room_exit_east(room6, room0);
  room_exit_up(room6, room7);

  //room7
  room_exit_down(room7, room6);
  
}

//Displays the description of the current room and the room's items to the console
void look(Room *room){
  printf("%s", room->description);
  Item *node = room->items;
  printf("\nThis room contains items:");
  if(node->next==NULL){
    printf("\nThere are no items in this room.\n");
  }else{
    while(node != NULL){
      printf("%s \n", node->name);
      node = node->next;
    }
  }
  printf("\n");
}

//Frees the items in the inventory of the user and sets them to NULL
void freeInv(Item *inventory){
  Item *temp;
  while(inventory != NULL){
    temp = inventory;
    inventory = inventory->next;
    free(temp);
    temp = NULL;
  }
}

//Takes in a specific room and frees all items inside the room and sets them to NULL, and after frees the room itself
void freeRoom(Room *room){
  Item *currItem = room->items;
  Item *prevItem;
  while(currItem != NULL){
    prevItem = currItem;
    currItem = currItem->next;
    free(prevItem);
    prevItem = NULL;
  }
  free(room);
}

//Frees rooms 0-7 and sets the pointers to NULL
void freeAll(){
  freeRoom(room0);
  room0 = NULL;
  freeRoom(room1);
  room1 = NULL;
  freeRoom(room2);
  room2 = NULL;
  freeRoom(room3);
  room3 = NULL;
  freeRoom(room4);
  room4 = NULL;
  freeRoom(room5);
  room5 = NULL;
  freeRoom(room6);
  room6 = NULL;
  freeRoom(room7);
  room7 = NULL;
}