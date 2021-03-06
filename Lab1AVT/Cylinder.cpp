#include "Cylinder.h"
#include "MatrixStack.h"
#include "Game.h"

Cylinder::Cylinder(float* position, Game *game, float height, float radius, int sides) : Object(position, game) 
{
	float p[] = {
		-radius, -height*0.5f,
		0.0f, -height*0.5f,
		radius, -height*0.5f,
		radius, height*0.5f,
		0.0f, height*0.5f,
		-radius, height*0.5f
	};

	computeVAO(4, p + 2, p, sides, 0.0f);
}


void Cylinder::draw()
{
	MatrixStack* modelview = game->getModelViewStack();

	sendMaterials();

	modelview->push();
	//then, puts the sphere in the right position
	modelview->translateMatrix(this->position[0], this->position[1], this->position[2]);
	modelview->scaleMatrix(scale[0], scale[1], scale[2]);

	sendDataToShader();
	modelview->pop();
}

void Cylinder::init()
{

}