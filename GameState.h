#pragma once
class GameState
{
public:
	enum PropablyGameState {MENU,PLAY,GAME_OVER,EXIT};
	PropablyGameState State;
	GameState();
	~GameState();
};

