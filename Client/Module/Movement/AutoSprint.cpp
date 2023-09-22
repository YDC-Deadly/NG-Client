#include "AutoSprint.h"

AutoSprint::AutoSprint() : Module(0x0, Category::MOVEMENT, "Automatically sprint without holding the key.") {
	registerBoolSetting("All Directions", &alldirections, alldirections, "All Directions: Enable or disable movement in all directions");
}

AutoSprint::~AutoSprint() {
}

const char* AutoSprint::getModuleName() {
	return ("AutoSprint");
}

void AutoSprint::onTick(GameMode* gm) {
	if (!gm->player->isSprinting() && gm->player->location->velocity.magnitudexz() > 0.01f) {
		GameSettingsInput* input = Game.getClientInstance()->getGameSettingsInput();
		if (alldirections || GameData::isKeyDown(*input->forwardKey))
			gm->player->setSprinting(true);
	}
}