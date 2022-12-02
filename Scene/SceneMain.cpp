#include "SceneMain.h"
#include "SceneResult.h"
#include "DxLib.h"
#include "Pad.h"
#include "mino.h"
#include "stage.h"

SceneMain::SceneMain()
{
	m_mino = new Mino;
	m_Pstage = new Stage;
}

SceneMain::~SceneMain()
{
	delete m_mino;
	delete m_Pstage;
}

// ‰Šú‰»
void SceneMain::init()
{
	m_mino->init();
	m_Pstage->init();
}

// I—¹ˆ—
void SceneMain::end()
{
	m_mino->end();
	m_Pstage->end();
}

// XVˆ—
SceneBase* SceneMain::update()
{
	m_mino->update();
	m_Pstage->update();
	m_mino->moveBlock();
	if (Pad::isTrigger(PAD_INPUT_2))
	{
		return (new SceneResult);
	}
	return this;
}

// •`‰æˆ—
void SceneMain::draw()
{
	m_Pstage->draw();
	m_mino->drawConfirm();
	m_mino->draw();
}