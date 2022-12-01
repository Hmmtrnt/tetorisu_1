// ����
#pragma once
#include "DxLib.h"

// �~�m�̕�
#define BLOCK_HEIGHT 4		// �c
#define BLOCK_WIDTH 4		// ��

// �X�e�[�W�̕�
#define STAGE_HEIGHT 21
#define STAGE_WIDTH 12

// �`�悷��u���b�N�̊Ԃ̕�
#define DRAW_BLOCK_WIDTH 20

namespace Mino
{
	// �~�m�̑傫��
	constexpr int kBlockHeight = 4;		// �c
	constexpr int kBlockWidth = 4;		// ��

	// �F
	const int kColor_Red = GetColor(255, 0, 0);		// ��
	const int kColor_Black = GetColor(0, 0, 0);		// ��

	// �~�m�̌`
	constexpr int kBlocks[BLOCK_HEIGHT][BLOCK_WIDTH] = {
		{0,0,0,0},
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0}
	};
}

namespace Stage
{
	// �F
	const int kColor_Red = GetColor(255, 0, 0);		// ��
	const int kColor_Black = GetColor(0, 0, 0);		// ��
}