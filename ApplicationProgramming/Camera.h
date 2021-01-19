#ifndef CAMERA_H
#define CAMERA_H

#include "Common/Vec.h"

#define FIELD_WIDTH (1280.0f)	//!< �t�B�[���h�̉���
#define FIELD_HEIGHT (480.0f)	//!< �t�B�[���h�̏c��

class Camera
{
public:
	Camera();
	~Camera();

public:
	Vec2 Update(Vec2 pos);

	void CameraUpdate(Vec2 pos);

private:
	Vec2 Position;

};



#endif // !CAMERA_H
