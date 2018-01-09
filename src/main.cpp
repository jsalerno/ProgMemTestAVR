#include <Arduino.h>
#include <HardwareSerial.h>
#include "SetupProgMem.h"

void setup() {
	Serial.begin(115200);

	int numberOfPins = getNumberOfPins();
	Serial.print(F("numberOfPins:"));
	Serial.println(numberOfPins);

	for (int index = 0; index < numberOfPins; index++) {
		Serial.println(F("======================================"));
		Serial.print(F("index:"));
		Serial.println(index);

		const ItemConfig config = getConfigAtIndex(index);
		Serial.print(F("ITEM CONFIG:"));

		Serial.print(F("\titemId:"));
		Serial.println(config.itemId);
		Serial.print(F("\tpinPosition:"));
		Serial.println(config.pinPosition);
		Serial.println();

		/* get an ItemLookup object and then inspect it, including the ItemProfile* */
		{
			const ItemLookup lookup = getItemLookupByItemId(config.itemId);
			Serial.print(F("ITEM LOOKUP:"));

			Serial.print(F("\titemId:"));
			Serial.println(lookup.itemId);
			Serial.print(F("\titemId:"));

			const ItemProfile* const profile = lookup.profile;
			Serial.print(F("\t\tprofile.itemId:"));
			Serial.println(profile->itemId);
			Serial.print(F("\t\tprofile.name:"));
			Serial.println(profile->name);
			Serial.print(F("\t\tprofile.description:"));
			Serial.println(profile->description);
			Serial.print(F("\t\tprofile.RL:"));
			Serial.println(profile->RL);
			Serial.print(F("\t\tprofile.VC:"));
			Serial.println(profile->VC);
		}
		/* get an ItemProfile* */
		{
			const ItemProfile * profile = getItemProfileByItemId(config.itemId);
			Serial.print(F("ITEM PROFILE:"));

			Serial.print(F("\titemId:"));
			Serial.println(profile->itemId);
			Serial.print(F("\tname:"));
			Serial.println(profile->name);
			Serial.print(F("\tdescription:"));
			Serial.println(profile->description);
			Serial.print(F("\tRL:"));
			Serial.println(profile->RL);
			Serial.print(F("\tVC:"));
			Serial.println(profile->VC);
		}
	}
}

void debugItemProfile() {

}

void loop() {
	delay(10000);
}
