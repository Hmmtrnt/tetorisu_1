#include "SceneMain.h"
#include "SceneResult.h"
#include "DxLib.h"
#include "Pad.h"
#include "mino.h"
#include "stage.h"

SceneMain::SceneMain()
{
	m_mino = new mino;
	m_stage = new stage;
}

SceneMain::~SceneMain()
{
	delete m_mino;
	delete m_stage;
}

// ������
void SceneMain::init()
{
	m_mino->init();
	m_stage->init();
}

// �I������
void SceneMain::end()
{
	m_mino->end();
	m_stage->end();
}

// �X�V����
SceneBase* SceneMain::update()
{
	m_mino->update();
	m_stage->update();
	m_mino->moveBlock();
	if (Pad::isTrigger(PAD_INPUT_2))
	{
		return (new SceneResult);
	}
	return this;
}

// �`�揈��
void SceneMain::draw()
{
	m_stage->draw();
	m_mino->drawConfirm();
	m_mino->draw();
//	DrawString(0, 0, "SceneMain", GetColor(255, 255, 255));
}