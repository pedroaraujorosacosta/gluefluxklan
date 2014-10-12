#ifndef __FROG_H__
#define __FROG_H__

#include "Blocker.h"
#include "Cube.h"
#include "Sphere.h"

class Frog : public Blocker {

	Sphere *body;
	Sphere *eyes;


protected:
	void init();
public:
	Frog(float* position, Game *game, float velocity, float *direction);
	~Frog();
	void draw(GLuint programID);
	void update();
	void move(float *direction);
	void stop();
};
#endif