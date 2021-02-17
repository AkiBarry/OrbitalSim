#pragma once

#include "Entity.hpp"

class CParticle : public CEntity
{
public:
	CParticle(CVec2 pos, CVec2 vel)
	{
		Pos = pos;
		velocity = vel;
	}

	CVec2 velocity;
};