#include <Arduino.h>  // for type definitions

/**
 * Thanks to Nick Gammon for this code in his reply in this stackoverflow thread :
 * https://arduino.stackexchange.com/questions/13545/using-progmem-to-store-array-of-structs
 */
template<typename T> void PROGMEM_readAnything(const T * sce, T& dest) {
	memcpy_P(&dest, sce, sizeof(T));
}

template<typename T> T PROGMEM_getAnything(const T * sce) {
	static T temp;
	memcpy_P(&temp, sce, sizeof(T));
	return temp;
}
