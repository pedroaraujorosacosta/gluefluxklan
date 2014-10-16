#include "Torus.h"
#include "Stack.h"
#include "Game.h"

Torus::Torus(float* position, Game *game, float innerRadius, float outerRadius, int rings, int sides) : Object(position, game) 
{
	float tubeRadius = (outerRadius - innerRadius) * 0.5f;
	float *p = circularProfile(-3.14159f, 3.14159f, tubeRadius, sides, innerRadius + tubeRadius);
	computeVAO(sides + 1, p + 2, p, rings, 0.0f);
	free(p);
}


void Torus::draw(GLuint programID)
{
	Stack* modelview = game->getModelViewStack();

	sendMaterials();

	modelview->push();
	//then, puts the sphere in the right position
	modelview->translateMatrix(this->position[0], this->position[1], this->position[2]);

	sendDataToShader(programID);
	modelview->pop();
}

void Torus::init()
{

}