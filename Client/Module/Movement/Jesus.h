#pragma once
#include "../../../Client/Module/Module.h"
#include "../ModuleManager.h"
class Jesus : public Module {
public:
	bool wasInWater = false;
	float sink = 0.1f;
	SettingEnum mode = this;
	Jesus() : Module(0x0, Category::MOVEMENT, "Walk over water, like Jesus") {
		registerEnumSetting("Mode", &mode, 0);
		mode.addEntry("Solid", 0);
		mode.addEntry("Bounce", 1);
		registerFloatSetting("Height", &sink, 0.1f, 0.0f, 1.f, "");
	};
	~Jesus(){};

	void Jesus::onTick(GameMode* gm) {
		if (gm->player->isSneaking()) return;

		if (gm->player->isInWater()) {
			gm->player->entityLocation->velocity.y = 0.06f;
			gm->player->setOnGround(true);
			wasInWater = true;
		} else if (gm->player->isInWater()) {  // || gm->player->isInLava()) {
			gm->player->entityLocation->velocity.y = sink;
			gm->player->setOnGround(true);
			wasInWater = true;
		} else {
			if (wasInWater) {
				wasInWater = false;
				gm->player->entityLocation->velocity.x *= 1.2f;
				gm->player->entityLocation->velocity.x *= 1.2f;
			}
		}
		if (mode.selected == 1) return;
		{
			if (gm->player->isSneaking()) return;
			if (gm->player->isOnFire()) return;

			Vec3 pos = *gm->player->getPos();
			pos.y -= 1.62f;

			pos.z = gm->player->aabb->upper.z;
			pos.x = gm->player->aabb->upper.x;  // upper upper

			Block* block = Game.getLocalPlayer()->getRegion()->getBlock(Vec3i(pos));
			BlockLegacy* blockLegacy = (block->blockLegacy);

			if (blockLegacy->material->isLiquid && gm->player->entityLocation->velocity.y <= 0) {
				Vec3 pos = *gm->player->getPos();
				pos.y -= 0.62f;
				pos.y = ceilf(pos.y);
				pos.y += 0.61f;
				gm->player->setPos(pos);
				gm->player->setOnGround(true);
				gm->player->entityLocation->velocity.y = 0.f;
			}

			pos.x = gm->player->aabb->lower.x;
			pos.z = gm->player->aabb->lower.z;  // lower lower

			block = Game.getLocalPlayer()->getRegion()->getBlock(Vec3i(pos));
			blockLegacy = (block->blockLegacy);

			if (blockLegacy->material->isLiquid && gm->player->entityLocation->velocity.y <= 0) {
				Vec3 pos = *gm->player->getPos();
				pos.y -= 0.62f;
				pos.y = ceilf(pos.y);
				pos.y += 0.61f;
				gm->player->setPos(pos);
				gm->player->setOnGround(true);
				gm->player->entityLocation->velocity.y = 0.f;
			}

			pos.x = gm->player->aabb->upper.x;  // upper x and lower z
			block = Game.getLocalPlayer()->getRegion()->getBlock(Vec3i(pos));
			blockLegacy = (block->blockLegacy);

			if (blockLegacy->material->isLiquid && gm->player->entityLocation->velocity.y <= 0) {
				Vec3 pos = *gm->player->getPos();
				pos.y -= 0.62f;
				pos.y = ceilf(pos.y);
				pos.y += 0.61f;
				gm->player->setPos(pos);
				gm->player->entityLocation->velocity.y = 0.f;
			}

			pos.x = gm->player->aabb->lower.x;
			pos.z = gm->player->aabb->upper.z;  // lower x and upper z

			block = Game.getLocalPlayer()->getRegion()->getBlock(Vec3i(pos));
			blockLegacy = (block->blockLegacy);

			if (blockLegacy->material->isLiquid && gm->player->entityLocation->velocity.y <= 0) {
				Vec3 pos = *gm->player->getPos();
				pos.y -= 0.62f;
				pos.y = ceilf(pos.y);
				pos.y += 0.61f;
				gm->player->setPos(pos);
				gm->player->setOnGround(true);
				gm->player->entityLocation->velocity.y = 0.f;
			}

			if (gm->player->isInWater()) {
				gm->player->entityLocation->velocity.y = 0.1f;
				gm->player->setOnGround(true);
			}
		}
	}

	virtual const char* getModuleName() override {
		return "Jesus";
	}

	std::string getModSettings() {
		return mode.GetSelectedEntry().GetName();
	}
};