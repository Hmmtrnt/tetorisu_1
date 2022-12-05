#include "Player.h"
#include "common.h"
#include "Mino.h"
#include "Stage.h"
#include "Pad.h"

Player::Player()
{
	m_pMino = new Mino;
	m_pStage = new Stage;
}

Player::~Player()
{
	delete m_pMino;
	delete m_pStage;
}

void Player::init()
{
}

void Player::end()
{
}

void Player::update(int posX)
{
	if (Pad::isTrigger(PAD_INPUT_LEFT) == 1)
	{
		if (!m_pStage->HitFlagLeft())
		{
			posX--;
		}
	}
	if (Pad::isTrigger(PAD_INPUT_RIGHT) == 1)
	{
		if (!m_pStage->HitFlagRight())
		{
			posX++;
		}
	}
}
