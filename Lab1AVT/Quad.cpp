#include "Quad.h"
#include "MatrixStack.h"
#include "Game.h"

Quad::Quad(float *position, Game *game) : Object(position, game)
{
	init();
	createBufferObjects();
}

Quad::Quad(float *position, float originX, float originY, float width, float height, Game *game) : Object(position, game)
{
	initCustomQuad(originX, originY, width, height);
	createBufferObjects();
}

void Quad::draw(){

	MatrixStack* modelview = game->getModelViewStack();

	sendMaterials();

	modelview->push();
	//then, puts the unitary cube in the right position
	modelview->translateMatrix(this->position[0], this->position[1], this->position[2]);
	modelview->scaleMatrix(scale[0], scale[1], scale[2]);
	//puts the unitary cube in the origin of the referencial
	modelview->translateMatrix(-0.5f, 0.0f, -0.5f);

	sendDataToShader();
	modelview->pop();
}

void Quad::drawCustomQuad(float originX, float originY, float width, float height)
{
	destroyBufferObjects();
	initCustomQuad(originX, originY, width, height);
	createBufferObjects();

	MatrixStack* modelview = game->getModelViewStack();

	sendMaterials();

	modelview->push();

	modelview->scaleMatrix(scale[0], scale[1], scale[2]);
	//puts the unitary cube in the origin of the referencial
	modelview->translateMatrix(0.0f, 0.0f, -1.0f);

	sendDataToShader();
	modelview->pop();
}

void Quad::init() {
	this->verticeCount = 4;
	this->faceCount = 2;

	float vertex[] = {
		0.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f		
	};

	this->vertices = new float[4 * verticeCount];

	for (int i = 0; i < verticeCount * 4; i++) {
		vertices[i] = vertex[i];
	}

	float norm[] = {
		0.0f, -1.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		0.0f, -1.0f, 0.0f
	};

	this->normals = new float[3 * verticeCount];

	for (int i = 0; i < verticeCount * 3; i++) {
		normals[i] = norm[i];
	}

	float texs[] = {
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f
	};

	this->texCoords = new float[2 * verticeCount];

	for (int i = 0; i < verticeCount * 2; i++) {
		texCoords[i] = texs[i];
	}

	unsigned int faces[] = {
		0, 1, 2, 
		0, 2, 3
	};

	this->faceIndex = new unsigned int[3 * faceCount];

	for (int i = 0; i < faceCount * 3; i++) {
		faceIndex[i] = faces[i];
	}
}

void Quad::initCustomQuad(float originX, float originY, float width, float height) {
	this->verticeCount = 4;
	this->faceCount = 2;

	float vertex[] = {
		originX, originY, 0.0f, 1.0f,
		originX + width, originY, 0.0f, 1.0f,
		originX + width, originY + height, 0.0f, 1.0f,
		originX, originY + height, 0.0f, 1.0f
	};

	this->vertices = new float[4 * verticeCount];

	for (int i = 0; i < verticeCount * 4; i++) {
		vertices[i] = vertex[i];
	}

	float norm[] = {
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f
	};

	this->normals = new float[3 * verticeCount];

	for (int i = 0; i < verticeCount * 3; i++) {
		normals[i] = norm[i];
	}

	float texs[] = {
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f
	};

	this->texCoords = new float[2 * verticeCount];

	for (int i = 0; i < verticeCount * 2; i++) {
		texCoords[i] = texs[i];
	}

	unsigned int faces[] = {
		0, 1, 2,
		0, 2, 3
	};

	this->faceIndex = new unsigned int[3 * faceCount];

	for (int i = 0; i < faceCount * 3; i++) {
		faceIndex[i] = faces[i];
	}
}