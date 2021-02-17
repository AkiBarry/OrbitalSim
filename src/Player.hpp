#pragma once

#include "Vector.hpp"
#include <list>

class CPlayer
{
public:
	enum class Dir {LEFT, RIGHT, UP, DOWN};

	Dir CurDir;
	Dir OldDir;
	bool Alive;
	std::list<CVec2> Blocks;
	CPlayer()
	{
		CurDir = Dir::RIGHT;
		OldDir = Dir::RIGHT;
		Alive = false;
	}

	void Reset()
	{
		Blocks.clear();
		Blocks.push_front(CVec2(100.f, 100.f));
		CurDir = Dir::RIGHT;
		OldDir = Dir::RIGHT;
		Alive = true;
	}
};

