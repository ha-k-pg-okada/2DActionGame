#ifndef MAPCHIP_H
#define MAPCHIP_H

#include "Common/Vec.h"

enum MapChipId
{
	OneBlock = 1,
	TwoBlock,
	ThreeBlock,
	FourBlock,
	FiveBlock,
	SixBlock,
	SevenBlock,
	EightBlock,
	NineBlock,
	TenBlock,
	ElevenBlock,
	TwelveBlock,
	ThirteenBlock,
	FourteenBlock,
	FifteenBlock
};

class MapChip
{
public:
	MapChip();
	~MapChip();

public:
	void Draw();

private:
	Vec2 Chip_size;
	Vec2 Position;

	int MapChipDate[0];
};



#endif // !
