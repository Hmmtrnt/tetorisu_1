// 共通
#pragma once
#include "DxLib.h"

// ミノの幅
#define BLOCK_HEIGHT 4		// 縦
#define BLOCK_WIDTH 4		// 横

// ステージの幅
#define STAGE_HEIGHT 21
#define STAGE_WIDTH 12

// 描画するブロックの間の幅
#define DRAW_BLOCK_WIDTH 20

namespace kMino
{
	// ミノの大きさ
	constexpr int kBlockHeight = 4;		// 縦
	constexpr int kBlockWidth = 4;		// 横

	// 色
	const int kColor_Red = GetColor(255, 0, 0);		// 赤
	const int kColor_Black = GetColor(0, 0, 0);		// 黒

	// ミノの形
	// Oミノ
	constexpr int kOMino[BLOCK_HEIGHT][BLOCK_WIDTH] = {
		{0,0,0,0},
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0}
	};
	// Iミノ
	constexpr int kIMino[BLOCK_HEIGHT][BLOCK_WIDTH] = {
		{0,0,1,0},
		{0,0,1,0},
		{0,0,1,0},
		{0,0,1,0}
	};
	// Sミノ
	constexpr int kSMino[BLOCK_HEIGHT][BLOCK_WIDTH] = {
		{0,0,0,0},
		{0,0,1,1},
		{0,1,1,0},
		{0,0,0,0}
	};
	// Zミノ
	constexpr int kZMino[BLOCK_HEIGHT][BLOCK_WIDTH] = {
		{0,0,0,0},
		{0,1,1,0},
		{0,0,1,1},
		{0,0,0,0}
	};
	// Jミノ
	constexpr int kJMino[BLOCK_HEIGHT][BLOCK_WIDTH] = {
		{0,0,0,0},
		{0,0,1,0},
		{0,0,1,0},
		{0,1,1,0}
	};
	// Lミノ
	constexpr int kLMino[BLOCK_HEIGHT][BLOCK_WIDTH] = {
		{0,0,0,0},
		{0,1,0,0},
		{0,1,0,0},
		{0,1,1,0}
	};
	// Tミノ
	constexpr int kTMino[BLOCK_HEIGHT][BLOCK_WIDTH] = {
		{0,0,0,0},
		{0,0,1,0},
		{0,1,1,1},
		{0,0,0,0}
	};
}

namespace kStage
{
	// 色
	const int kColor_Red = GetColor(255, 0, 0);		// 赤
	const int kColor_Black = GetColor(0, 0, 0);		// 黒
}