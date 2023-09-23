#include "TestCommand.h"
#include "../../../Utils/Logging.h"
#include "../../../Utils/Utils.h"
#include <sstream>
#include "../../../SDK/Tag.h"

TestCommand::TestCommand() : IMCCommand("test", "Test for Debugging purposes", "") {
}

TestCommand::~TestCommand() {
}

void listEnts() {
	Level* level = Game.getLocalPlayer()->getlevel();
	Entity* entity = level->getEntity();
	if (entity != nullptr) {
		int64_t id = entity->getEntityTypeId();
		const char* name = entity->getNameTag()->getText();
		Game.getGuiData()->displayClientMessageF("---------------");
		Game.getGuiData()->displayClientMessageF("Entity Name: %s", name);
		Game.getGuiData()->displayClientMessageF("Entity ID: %lld", id);
		Game.getGuiData()->displayClientMessageF("---------------");
	}
}

//void itemId() {
//	LocalPlayer* player = Game.getLocalPlayer();
//	if (player == nullptr) {
//		return;
//	}
//	PlayerInventoryProxy* supplies = player->getSupplies();
//	if (supplies == nullptr) {
//		return;
//	}
//	Inventory* inv = supplies->inventory;
//	if (inv == nullptr) {
//		return;
//	}
//	int n = supplies->selectedHotbarSlot;
//	ItemStack* stack = inv->getItemStack(n);
//	if (stack != nullptr && stack->item != nullptr) {
//		int64_t id = stack->getItem()->itemId;
//		const char* name = stack->getItem()->name.getText();
//		Game.getGuiData()->displayClientMessageF("---------------");
//		Game.getGuiData()->displayClientMessageF("Item Name: %s", name);
//		Game.getGuiData()->displayClientMessageF("Item ID: %lld", id);
//		Game.getGuiData()->displayClientMessageF("---------------");
//	}
//}

void showAimedBlockInfo() {
	LocalPlayer* player = Game.getLocalPlayer();
	Level* level = player->getlevel();
	Block* block = player->region->getBlock(level->block);
	if (block != nullptr && level != nullptr && block->blockLegacy != nullptr && block->blockLegacy->blockId != 7 && block->blockLegacy->blockId != 720) {
		const char* name = block->toLegacy()->name.getText();
		int64_t id = block->toLegacy()->blockId;
		Game.getGuiData()->displayClientMessageF("---------------");
		Game.getGuiData()->displayClientMessageF("Block Name: %s", name);
		Game.getGuiData()->displayClientMessageF("Block ID: %lld", id);
		Game.getGuiData()->displayClientMessageF("---------------");
	}
}

bool TestCommand::execute(std::vector<std::string>* args) {
	listEnts();
	//itemId();
	showAimedBlockInfo();
	return true;
}
