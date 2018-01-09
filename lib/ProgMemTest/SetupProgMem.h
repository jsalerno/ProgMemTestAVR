#include <stdlib.h>
#include <pins_arduino.h>

#ifndef LIBRARIES_SETUPPROGMEM_H_
#define LIBRARIES_SETUPPROGMEM_H_

#define MAX_NAME_LENGTH		8
#define MAX_DESC_LENGTH		16

/* pin positions of each of the component items */
struct ItemConfig {
	uint8_t pinPosition;
	int itemId;
};

/* Item Profile Struct */
struct ItemProfile {
	int itemId;
	char name[MAX_NAME_LENGTH];
	char description[MAX_DESC_LENGTH];
	/* manufacturer specs */
	float VC; /* loop test voltage in Volts */
	float RL; /* load resistance in kOhm */
};

/* Lookup objects to place into a table that will store Item Profiles by itemId key */
struct ItemLookup {
	int itemId;
	const ItemProfile * profile;
};

///// ALL FIELDS INTO PROGMEM //////

enum PROGMEM Items {
	Item0 = 0,
	Item1 = 1,
	Item2 = 2,
	Item3 = 3,
	Item4 = 4,
	Item5 = 5,
	Item6 = 6,
	Item7 = 7
};

/* pairing of Pin to some electronic Item */
const ItemConfig AOPin PROGMEM = {A0, Item0};
const ItemConfig A1Pin PROGMEM = {A1, Item1};
const ItemConfig A2Pin PROGMEM = {A2, Item2};
const ItemConfig A3Pin PROGMEM = {A3, Item3};
const ItemConfig A4Pin PROGMEM = {A4, Item4};
const ItemConfig A5Pin PROGMEM = {A5, Item5};
const ItemConfig A6Pin PROGMEM = {A6, Item6};
const ItemConfig A7Pin PROGMEM = {A7, Item7};

/* Make the pins accessible via a simple pin array for iteration */
const ItemConfig PIN_ARRAY[8] PROGMEM = {AOPin, A1Pin, A2Pin, A3Pin, A4Pin, A5Pin, A6Pin, A7Pin};

/* Some Profile information about each Item */
const ItemProfile Item0Profile PROGMEM = ItemProfile {Item0, "Item 0", "Desc. 0", 0.0, 0.0};
const ItemProfile Item1Profile PROGMEM = ItemProfile {Item1, "Item 1", "Desc. 1", 1.0, 0.1};
const ItemProfile Item2Profile PROGMEM = ItemProfile {Item2, "Item 2", "Desc. 2", 2.0, 0.2};
const ItemProfile Item3Profile PROGMEM = ItemProfile {Item3, "Item 3", "Desc. 3", 3.0, 0.3};
const ItemProfile Item4Profile PROGMEM = ItemProfile {Item4, "Item 4", "Desc. 4", 4.0, 0.4};
const ItemProfile Item5Profile PROGMEM = ItemProfile {Item5, "Item 5", "Desc. 5", 5.0, 0.5};
const ItemProfile Item6Profile PROGMEM = ItemProfile {Item6, "Item 6", "Desc. 6", 6.0, 0.6};
const ItemProfile Item7Profile PROGMEM = ItemProfile {Item7, "Item 7", "Desc. 7", 7.0, 0.7};

/* The Lookup Table of Item to ItemProfile, storing a pointer reference to the object, not the object */
const ItemLookup itemLookup[] PROGMEM = {
	{	Item0, &Item0Profile},
	{	Item1, &Item1Profile},
	{	Item2, &Item2Profile},
	{	Item3, &Item3Profile},
	{	Item4, &Item4Profile},
	{	Item5, &Item5Profile},
	{	Item6, &Item6Profile},
	{	Item7, &Item7Profile},
};

/* return the number of pins this system supports */
int getNumberOfPins();
/* for the specified index in the pin array, return the ItemConfig */
const ItemConfig getConfigAtIndex(int index);
/* get the ItemLookup object for an Item with a given itemId */
const ItemLookup getItemLookupByItemId(const int itemId);
/* get the ItemLookup->ItemProfile* pointer for an Item with a given itemId */
const ItemProfile * getItemProfileByItemId(int ItemId);

#endif
