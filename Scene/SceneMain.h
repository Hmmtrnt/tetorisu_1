// ���C�����
#pragma once
#include "SceneBase.h"

class mino;
class stage;

class SceneMain : public SceneBase
{
public:
	SceneMain();
	virtual ~SceneMain();

	virtual void init();			// ������
	virtual void end();				// �I������
	virtual SceneBase* update();	// �X�V����
	virtual void draw();			// �`�揈��

private:
	mino* m_mino;
	stage* m_stage;
};