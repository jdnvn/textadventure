#ifndef ROOMS_H
#define ROOMS_H

struct Room {
  char description[400];
  struct Item *items;
  struct Room *north;
  struct Room *east;
  struct Room *south;
  struct Room *west;
  struct Room *up;
  struct Room *down;
};

typedef struct Room Room;

Room *room0;
Room *room1;
Room *room2;
Room *room3;
Room *room4;
Room *room5;
Room *room6;
Room *room7;
Room *room8;
Room *roomTemp;

Room *room(char* description, struct Item* items);

void room_exit_north(Room *current, Room *other);
void room_exit_south(Room *current, Room *other);
void room_exit_east(Room *current, Room *other);
void room_exit_west(Room *current, Room *other);
void room_exit_up(Room *current, Room *other);
void room_exit_down(Room *current, Room *other);

void initializeMap();
void look(Room *room);

void freeInv(struct Item *inventory);
void freeRoom(Room *room);
void freeAll();

#endif