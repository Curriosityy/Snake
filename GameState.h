#pragma once
class GameState
{
public:
	enum Game_State {MENU,PLAY,GAME_OVER,EXIT};
	Game_State State;
	GameState();
	~GameState();
};

