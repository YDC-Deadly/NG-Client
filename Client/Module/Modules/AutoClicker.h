#pragma once

#include "Module.h"
#include "../ModuleManager.h"

class AutoClicker : public Module {
private:
	int delay = 0;
	int Odelay = 0;
	bool weapons = true;
	bool breakBlocks = true;
	bool rightclick = false;
	bool hold = false;

public:
	AutoClicker();
	~AutoClicker();

	// Inherited via Module
	virtual const char* getModuleName() override;
	virtual void onTick(GameMode* gm) override;
};
