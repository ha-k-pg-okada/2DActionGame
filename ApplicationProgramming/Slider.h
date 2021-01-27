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
	float MinValue;		// ç≈è¨íl
	float MaxValue;		// ç≈ëÂíl
	float CurrentValue;	// åªç›íl
	int Counter;
};


#endif // !SLIDER_H
