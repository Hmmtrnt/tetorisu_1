// ƒvƒŒƒCƒ„[
#pragma once

class Mino;
class Stage;

class Player
{
public:
	Player();
	virtual ~Player();

	void init();
	void end();
	void update(int posX);

private:
	Mino* m_pMino;
	Stage* m_pStage;
};