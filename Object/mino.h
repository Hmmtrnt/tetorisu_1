// ƒ~ƒm
#pragma once
class mino
{
public:
	mino();
	virtual ~mino();

	void init();
	void end();
	void update();
	void draw();

private:
	int block[Mino::kBlockHeight][Mino::kBlockWidth];
	int blocks[Mino::kBlockHeight][Mino::kBlockWidth];
};