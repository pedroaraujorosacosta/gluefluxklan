#ifndef __MOBILEOBJ_H__
#define __MOBILEOBJ_H__

#include "Object.h"

class MobileObj : public Object {

protected:
	float direction[3];
	float velocity;

	virtual void init();
public:
	MobileObj(float* position, Game *game, float velocity, float *direction);
	virtual void draw(GLuint programID);
};
#endif