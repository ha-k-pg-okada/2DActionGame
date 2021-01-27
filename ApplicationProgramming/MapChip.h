#ifndef MAPCHIP_H
#define MAPCHIP_H

#include "Common/Vec.h"

#define MAP_CHIP_ALL   (16)					// �}�b�v�`�b�v�̐�
#define MAP_CHIP_X     (4)					// �}�b�v�`�b�v�̉����̐�
#define MAP_CHIP_Y     (4)					// �}�b�v�`�b�v�̏c���̐�
#define SIZE_MAP_X     (64)					// �}�b�v�`�b�v�̏c��
#define SIZE_MAP_Y     (64)		            // �}�b�v�`�b�v�̏c��
#define MAP_CHIP_MAX_X (20)		            // �X�e�[�W�̏c��
#define MAP_CHIP_MAX_Y (8)		            // �X�e�[�W�̉���

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
	void Update();

	bool OncollisionRectAndMapChip(Vec2 obj_pos, Vec2 obj_size, int Number);
	void Collision(Vec2 position,  Vec2* hitBlockPos);

	

	

	bool GetChipType(Vec2 position);
	bool isActive;

	
private:
	Vec2 Chip_size;
	int MapChipDate[MAP_CHIP_ALL];
	Vec2 Position;

	
	

	
};



#endif // !
