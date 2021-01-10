#include "MapChip.h"
#include "DxLib.h"

#define MAP_CHIP_ALL   (16)					// �}�b�v�`�b�v�̐�
#define MAP_CHIP_X     (4)					// �}�b�v�`�b�v�̉����̐�
#define MAP_CHIP_Y     (4)					// �}�b�v�`�b�v�̏c���̐�
#define SIZE_MAP_X     (64)					// �}�b�v�`�b�v�̏c��
#define SIZE_MAP_Y     (64)		            // �}�b�v�`�b�v�̏c��
#define MAP_CHIP_MAX_X (10)		            // �X�e�[�W�̏c��
#define MAP_CHIP_MAX_Y (8)		            // �X�e�[�W�̉���

// �}�b�v�`�b�v�z�� 
int MapChipList[MAP_CHIP_MAX_Y][MAP_CHIP_MAX_X]
{
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{ 1, 0, 0, 0, 0, 3, 3, 0, 0, 1},
	{ 1, 0, 2, 2, 0, 0, 0, 0, 0, 1},
	{ 1, 0, 0, 0, 0, 0, 4, 4, 0, 1},
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{ 1, 0, 2, 2, 0, 0, 0, 0, 0, 1},
	{ 1, 0, 0, 0, 0, 0, 4, 4, 0, 1},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};


MapChip::MapChip()
{
	MapChipDate[MAP_CHIP_ALL];
	Chip_size = Vec2(64.0f, 64.0f);
	Position;
}

MapChip::~MapChip()
{

}

void MapChip::Draw()
{
	//�}�b�v�`�b�v�摜�ǂݍ���
	LoadDivGraph("Res/MapChip.png", MAP_CHIP_ALL, MAP_CHIP_X, MAP_CHIP_Y, SIZE_MAP_X, SIZE_MAP_Y, MapChipDate);

	for (int y = 0; y < MAP_CHIP_MAX_Y; y++)
	{
		for (int x = 0; x < MAP_CHIP_MAX_X; x++)
		{
			// �`�b�v�ԍ��擾
			int chip_id = MapChipList[y][x];

			// �����Ȓl�����`�F�b�N
			if (chip_id == 0)
			{
				continue;
			}

			// �`����W���Z�o
			Position = Vec2(x * Chip_size.X, y * Chip_size.Y);

			switch (chip_id)
			{
			case 0:                                                                        break;
			case 1:  DrawGraph(Position.X, Position.Y, MapChipDate[OneBlock],      true);  break;
			case 2:  DrawGraph(Position.X, Position.Y, MapChipDate[TwoBlock],      true);  break;
			case 3:  DrawGraph(Position.X, Position.Y, MapChipDate[ThreeBlock],    true);  break;
			case 4:  DrawGraph(Position.X, Position.Y, MapChipDate[FourBlock],     true);  break;
			case 5:  DrawGraph(Position.X, Position.Y, MapChipDate[FiveBlock],     true);  break;
			case 6:  DrawGraph(Position.X, Position.Y, MapChipDate[SixBlock],      true);  break;
			case 7:  DrawGraph(Position.X, Position.Y, MapChipDate[SevenBlock],    true);  break;
			case 8:  DrawGraph(Position.X, Position.Y, MapChipDate[EightBlock],    true);  break;
			case 9:  DrawGraph(Position.X, Position.Y, MapChipDate[NineBlock],     true);  break;
			case 10: DrawGraph(Position.X, Position.Y, MapChipDate[TenBlock],      true);  break;
			case 11: DrawGraph(Position.X, Position.Y, MapChipDate[ElevenBlock],   true);  break;
			case 12: DrawGraph(Position.X, Position.Y, MapChipDate[TwelveBlock],   true);  break;
			case 13: DrawGraph(Position.X, Position.Y, MapChipDate[ThirteenBlock], true);  break;
			case 14: DrawGraph(Position.X, Position.Y, MapChipDate[FourteenBlock], true);  break;
			case 15: DrawGraph(Position.X, Position.Y, MapChipDate[FifteenBlock],  true);  break;
			}
		}
	}
}