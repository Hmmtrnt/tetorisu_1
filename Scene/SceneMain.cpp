#include "SceneMain.h"
#include "SceneResult.h"
#include "DxLib.h"
#include "Pad.h"
#include "mino.h"
#include "stage.h"

SceneMain::SceneMain()
{
	m_pMino = new Mino;
	m_pStage = new Stage;
}

SceneMain::~SceneMain()
{
	delete m_pMino;
	delete m_pStage;
}

// ‰Šú‰»
void SceneMain::init()
{
	m_pMino->init();
	m_pStage->init();
}

// I—¹ˆ—
void SceneMain::end()
{
	m_pMino->end();
	m_pStage->end();
}

// XVˆ—
SceneBase* SceneMain::update()
{
	m_pMino->update();
	m_pStage->update();
	m_pMino->moveBlock();
	if (Pad::isTrigger(PAD_INPUT_2))
	{
		return (new SceneResult);
	}
	return this;
}

// •`‰æˆ—
void SceneMain::draw()
{
	m_pStage->draw();
	m_pMino->drawConfirm();
	m_pMino->draw();
}