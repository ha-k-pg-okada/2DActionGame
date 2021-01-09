#include "MapChip.h"
#include "DxLib.h"

#define STAGE_WIDTH (640)					// �X�e�[�W�̉���
#define STAGE_HEIGHT (320)					// �X�e�[�W�̏c��
#define MAPCHIP_WIDTH (64)					// �}�b�v�`�b�v�̉���
#define MAPCHIP_HEIGHT (64)					// �}�b�v�`�b�v�̏c��
#define MAP_SIZE_WIDTH (STAGE_WIDTH / MAPCHIP_WIDTH)		// MAP�̉���(�l�̓`�b�v��)
#define MAP_SIZE_HEIGHT (STAGE_HEIGHT / MAPCHIP_HEIGHT)		// MAP�̏c��(�l�̓`�b�v��)

// �}�b�v�`�b�v�z�� (�l�̓`�b�v�摜�ɑΉ�)
int MapChipList[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH]
{
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{ 1, 0, 0, 0, 0, 3, 3, 0, 0, 1},
	{ 1, 0, 2, 2, 0, 0, 0, 0, 0, 1},
	{ 1, 0, 0, 0, 0, 0, 4, 4, 0, 1},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};


MapChip::MapChip()
{

}

MapChip::~MapChip()
{

}

void MapChip::Draw()
{
	//Texture* texture_data = GetTexture(TextureList::MapChip);

	

	// �e�N�X�`���̃T�C�Y�ƃ}�b�v�`�b�v�̃T�C�Y���牡�Əc�̃`�b�v��������o��
	//int width_chip_num = texture_data->Width / MAPCHIP_WIDTH;
	//int height_chip_num = texture_data->Height / MAPCHIP_HEIGHT;

	for (int y = 0; y < MAP_SIZE_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_SIZE_WIDTH; x++)
		{
			// �`�b�v�ԍ��擾
			int chip_id = MapChipList[y][x];

			// �����Ȓl�����`�F�b�N
			if (chip_id == 0)
			{
				continue;
			}

			// chip_id����`�b�v�̃e�N�X�`�����W������o��
			float tex_pos_x = (float)(chip_id % width_chip_num) * MAPCHIP_WIDTH;
			float tex_pos_y = (float)(chip_id / height_chip_num) * MAPCHIP_HEIGHT;

			// �`����W������o��
			float position_x = (float)MAPCHIP_WIDTH * x;
			float position_y = (float)MAPCHIP_HEIGHT * y;

			// �`�b�v�̕`��
			/*DrawTextureUV(
				position_x,
				position_y,
				texture_data,
				tex_pos_x,
				tex_pos_y,
				MAPCHIP_WIDTH,
				MAPCHIP_HEIGHT);*/

			LoadDivGraph("Res/MapChip.png", position_x, position_y, texture_data, tex_pos_x, tex_pos_y, MAPCHIP_WIDTH, MAPCHIP_HEIGHT, true);

			
		}
	}
}