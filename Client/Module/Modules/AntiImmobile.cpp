#include "AntiImmobile.h"

AntiImmobile::AntiImmobile() : Module(0, Category::MISC, "Disables the immobile flag set by some servers to prevent you from moving.") {
}
AntiImmobile::~AntiImmobile() {
}

const char* AntiImmobile::getModuleName() {
	return "AntiImmobile";
}