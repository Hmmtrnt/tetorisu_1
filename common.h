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

namespace kMino
{
	// �~�m�̑傫��
	constexpr int kBlockHeight = 4;		// �c
	constexpr int kBlockWidth = 4;		// ��

	// �F
	const int kColor_Red = GetColor(255, 0, 0);		// ��
	const int kColor_Black = GetColor(0, 0, 0);		// ��

	// �~�m�̌`
	// O�~�m
	constexpr int kOMino[BLOCK_HEIGHT][BLOCK_WIDTH] = {
		{0,0,0,0},
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0}
	};
	// I�~�m
	constexpr int kIMino[BLOCK_HEIGHT][BLOCK_WIDTH] = {
		{0,0,1,0},
		{0,0,1,0},
		{0,0,1,0},
		{0,0,1,0}
	};
	// S�~�m
	constexpr int kSMino[BLOCK_HEIGHT][BLOCK_WIDTH] = {
		{0,0,0,0},
		{0,0,1,1},
		{0,1,1,0},
		{0,0,0,0}
	};
	// Z�~�m
	constexpr int kZMino[BLOCK_HEIGHT][BLOCK_WIDTH] = {
		{0,0,0,0},
		{0,1,1,0},
		{0,0,1,1},
		{0,0,0,0}
	};
	// J�~�m
	constexpr int kJMino[BLOCK_HEIGHT][BLOCK_WIDTH] = {
		{0,0,0,0},
		{0,0,1,0},
		{0,0,1,0},
		{0,1,1,0}
	};
	// L�~�m
	constexpr int kLMino[BLOCK_HEIGHT][BLOCK_WIDTH] = {
		{0,0,0,0},
		{0,1,0,0},
		{0,1,0,0},
		{0,1,1,0}
	};
	// T�~�m
	constexpr int kTMino[BLOCK_HEIGHT][BLOCK_WIDTH] = {
		{0,0,0,0},
		{0,0,1,0},
		{0,1,1,1},
		{0,0,0,0}
	};
}

namespace kStage
{
	// �F
	const int kColor_Red = GetColor(255, 0, 0);		// ��
	const int kColor_Black = GetColor(0, 0, 0);		// ��
}