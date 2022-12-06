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
	// ��ڈȍ~�̃m�~�̕���
	virtual void initRevival();
	// �I������
	virtual void end();
	// �X�V����
	virtual void update();
	// �`�揈��
	virtual void draw();
	// �ϐ��m�F�p�`�揈��
	virtual void drawConfirm();
	// �~�m�̓�������
	virtual void moveBlock();
	// �~�m���Œ肷�鏈��
	virtual void stopBlock();
	// �~�m�̕ۑ�
	virtual void saveMino();
	// �~�m�̕���
	virtual void makeMino();

	// �ǔ��肽�����̓�
	void wallLeft();
	void wallRight();

	// ���̕ǔ���
	bool HitFlagLeft();
	// �E�̕ǔ���
	bool HitFlagRight();
	// �n�ʂ̔���
	bool HitFlagBottom();

	// ���W�Ȃǂ̏��擾
	int m_getPosX()const { return m_posX; }
	int m_getPosY()const { return m_posY; }

	int m_block[BLOCK_HEIGHT][BLOCK_WIDTH];

private:

	int m_posX;
	int m_posY;

	int time;

	float m_countY;
	float m_speed;

	// true�F���݂���@false�F���݂��Ȃ�
	bool m_makeMinoFlag;
	// true�F���������@false�F�������ĂȂ�
	bool m_hitMinoFlag;

	Stage* m_pStage;
};