#ifndef SLIDER_H
#define SLIDER_H

#include "Common/Vec.h"

class Slider
{
public:
	Slider();
	~Slider();

public:
	void Init();
	void Update();
	void Draw();

	Vec2 GetSliderPos();

private:
	Vec2 Position;		
	Vec2 Size;			
	float MinValue;		// �ŏ��l
	float MaxValue;		// �ő�l
	float CurrentValue;	// ���ݒl
	int Counter;
};


#endif // !SLIDER_H
