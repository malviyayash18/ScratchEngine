#pragma once

#include "Character.h"
#include "Animation.h"

class Warrior: public Character {

public:
	Warrior(Properties* Props);

	virtual void Draw();
	virtual void Clean();
	virtual void Update(float dt);

private:

	//int Row, Frame, Frame_Count;
	//int AnimationSpeed;

	Animation* animation;
};

