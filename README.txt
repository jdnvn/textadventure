Group: Joey Donovan, Patrick Tomasetta, TJ Goldblatt, Marcin Knara

General overview of the game:

Your "avatar" wakes up in a room. Based on the descriptions of the rooms you are in you need to make your away around this "place" and find a way out.
There are a items to pick up in most rooms, but the goal is to find the only key. This key is USED to unlock the front / main door, which allows the player to escape.


How the game satisfies the requirements:

1. There are 8 rooms in our map, with 6 being on the same "floor", 1 being an attic, and 1 being a basement. 

2. Each room can contain an item, as most start with one.

3. We use an inventory. To view it the player can type the command "inventory" (We did not want it to clutter our game UI).

4. You can "see" the room using the command "look"

5. Move around the map by typing "go DIRECTION"

6. Pick up items by typing "take ITEM"

7. Use items by typing "use ITEM"

8. Our key item alters the state of a room. If you have the key, you can "use key" in the last room (the foyer, since it has the front door) and this will allow you to win the game. If you use the key in a different room, you get a message that hints at using it on the main door. If you do not have the key and try to "use key" in the foyer, you will not win until you have the key in your inventory. 

9. Drop items by typing "drop ITEM" in any room.

10. The winning state is when the player has a key in their inventory and uses it in "the foyer".

-Completed 100% of the requirements and delivered on time in proper format

-Data structures used to link the rooms in our map, the items in the rooms, and the items in the player's inventroy

-No unused code


