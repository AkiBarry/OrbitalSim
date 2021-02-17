#pragma once
class CGame
{
public:
	enum class State { MENU, INGAME, PAUSED, LOSE };

	State GameState;

	float tick_rate;

	CGame()
	{
		GameState = State::INGAME;
		tick_rate = 64.f;
	}
};

