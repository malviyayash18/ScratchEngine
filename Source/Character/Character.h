#pragma once

#include "GameObject.h"
#include "string"

class Character: public GameObject {

public:
	Character(Properties* Props): GameObject(Props) {  }

	virtual void Draw()=0;
	virtual void Clean()=0;
	virtual void Update(float dt)=0;

protected:
	std::string Name;

private:

};
