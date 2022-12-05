// �~�m
#pragma once
#include "common.h"

class Stage;

class Mino
{
public:
	Mino();
	virtual ~Mino();

	virtual void init();
	virtual void end();
	virtual void update();
	// �`�揈��
	virtual void draw();
	// �ϐ��m�F�p�`�揈��
	virtual void drawConfirm();
	// �~�m�̓�������
	virtual void moveBlock();
	// �~�m���Œ肷�鏈��
	virtual void stopBlock();
	// �Q�[���I�[�o�[����
	virtual void gameOver();

	bool HitFlagLeft();
	bool HitFlagRight();

	int m_getPosX()const { return m_posX; }
	int m_getPosY()const { return m_posY; }
	int m_getCount()const { return (int)m_countY; }
	int m_block[BLOCK_HEIGHT][BLOCK_WIDTH];

private:

	int m_posX;
	int m_posY;
	float m_countY;
	float m_speed;

	Stage* m_pStage;
};