// �~�m
#pragma once
#include "common.h"

class Stage;

class Mino
{
public:
	Mino();
	virtual ~Mino();

	void init();
	void end();
	void update();
	// �`�揈��
	void draw();
	// �ϐ��m�F�p�`�揈��
	void drawConfirm();
	// �~�m�̓�������
	void moveBlock();
	// �~�m���Œ肷�鏈��
	void stopBlock();


	int m_getPosX()const { return m_posX; }
	int m_getPosY()const { return m_posY; }
	int m_getCount()const { return (int)m_countY; }
	int m_block[BLOCK_HEIGHT][BLOCK_WIDTH];

private:
	int m_posX;
	int m_posY;

	float m_countY;
	float m_speed;

	Stage* m_Pstage;
};