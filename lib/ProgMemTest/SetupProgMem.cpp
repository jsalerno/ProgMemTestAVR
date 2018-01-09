#include <avr/pgmspace.h>
#include <stdio.h>

#include "PROGMEM_readAnything.h"
#include "SetupProgMem.h"

int getNumberOfPins() {
	int numPins = sizeof(PIN_ARRAY) / sizeof(*PIN_ARRAY);
	return numPins;
}

const ItemConfig getConfigAtIndex(int index) {
	ItemConfig item = PROGMEM_getAnything<ItemConfig>(&(PIN_ARRAY[index]));
	return item;
}

const ItemLookup getItemLookupByItemId(const int itemId) {
	const int numItems = sizeof(itemLookup) / sizeof(*itemLookup);
	int entry = 0;

	ItemLookup lookup;
	while (entry < numItems) {
		const ItemLookup item = itemLookup[entry];
		lookup = PROGMEM_getAnything<ItemLookup>(&item);

		if (itemId == lookup.itemId) {
			break;
		}
		entry++;
	}
	return lookup;
}

const ItemProfile * getItemProfileByItemId(const int itemId) {
	const int numItems = sizeof(itemLookup) / sizeof(*itemLookup);
	int entry = 0;

	ItemLookup lookup;
	while (entry < numItems) {
		lookup = PROGMEM_getAnything(&(itemLookup[entry]));

		if (itemId == lookup.itemId) {
			break;
		}
		entry++;
	}
	return lookup.profile;
}
