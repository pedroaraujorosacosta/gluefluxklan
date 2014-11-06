#include <iostream>
#include <string>

#include "Object.h"
#include "MobileObj.h"
#include "Game.h"
#include "Frog.h"

#include "River.h"
#include "Road.h"
#include "Turtle.h"
#include "FloatingLog.h"
#include "Bus.h"
#include "Car.h"

#include "ManagerObj.h"


ManagerObj::ManagerObj(Game *game) : Manager(game) {

	setDificuldade(1);
	setLateralEsquerda(-20.0);
	setLateralDireita(20.0);

	//collision variables init
	carWeigth = 1.2;
	busWeigth = 2.4;
	logWeigth = 2.2;
	turtleWeigth = 2.0;
	frogHeigth = 1.0;
	frogWeigth = 1.4; 

	/*
	validPositions = new bool*[8];
	for (int t = 0; t < 8; ++t) {
		validPositions[t] = new bool[5];
	}
	for (int t = 0; t < 8; ++t) {
		for (int i = 0; i < 5; ++i){
			validPositions[t][i] = false;
		}
	}
	*/

	float posRiver[] = { 0.0, 7, -3.0 };
	objects.push_back(new River(posRiver, game));
	float posroad[] = { 0.0, -7, -3.0 };
	objects.push_back(new Road(posroad, game));


	//LANE 1
	float posFloatingLog1[] = { -5.0, 11.0, -2.5 };
	float dirFloatingLog1[] = { 1, 0.0, 0.0 };

	float posFloatingLog2[] = { 1.0, 11.0, -2.5 };
	float dirFloatingLog2[] = { 1, 0.0, 0.0 };

	float posFloatingLog3[] = { 8.0, 11.0, -2.5 };
	float dirFloatingLog3[] = { 1, 0.0, 0.0 };

	objectsMobileLane1.push_back(new FloatingLog(posFloatingLog1, game, getLane1Velocity(), dirFloatingLog1));
	objectsMobileLane1.push_back(new FloatingLog(posFloatingLog2, game, getLane1Velocity(), dirFloatingLog2));
	objectsMobileLane1.push_back(new FloatingLog(posFloatingLog3, game, getLane1Velocity(), dirFloatingLog3));

	//LANE 2

	float posTurtle1[] = { lateralDireita, 9, -2.5 };
	float dirTurtle1[] = { -1, 0.0, 0.0 };

	float posTurtle2[] = { 2.0, 9, -2.5 };
	float dirTurtle2[] = { -1, 0.0, 0.0 };

	float posTurtle3[] = { -4, 9, -2.5 };
	float dirTurtle3[] = { -1, 0.0, 0.0 };

	objectsMobileLane2.push_back(new Turtle(posTurtle1, game, getLane2Velocity(), dirTurtle1));
	objectsMobileLane2.push_back(new Turtle(posTurtle2, game, getLane2Velocity(), dirTurtle2));
	objectsMobileLane2.push_back(new Turtle(posTurtle3, game, getLane2Velocity(), dirTurtle3));

	//LANE 3

	float posFloatingLog4[] = { lateralEsquerda, 7.0, -2.5 };
	float dirFloatingLog4[] = { 1, 0.0, 0.0 };

	float posFloatingLog5[] = { 7.0, 7.0, -2.5 };
	float dirFloatingLog5[] = { 1, 0.0, 0.0 };

	float posFloatingLog6[] = { -2.0, 7.0, -2.5 };
	float dirFloatingLog6[] = { 1, 0.0, 0.0 };

	objectsMobileLane3.push_back(new FloatingLog(posFloatingLog4, game, getLane3Velocity(), dirFloatingLog4));
	objectsMobileLane3.push_back(new FloatingLog(posFloatingLog5, game, getLane3Velocity(), dirFloatingLog5));
	objectsMobileLane3.push_back(new FloatingLog(posFloatingLog6, game, getLane3Velocity(), dirFloatingLog6));

	//BRIDGE new Lane 4

	float posFloatingLog7[] = { 0.0, 5.0, -2.5 };
	float dirFloatingLog7[] = { 1, 0.0, 0.0 };


	objectsMobileLane4.push_back(new FloatingLog(posFloatingLog7, game, getLane4Velocity(), dirFloatingLog4));

	//BRIDGE new Lane 5

	float posFloatingLog8[] = { 0.0, 3.0, -2.5 };
	float dirFloatingLog8[] = { 1, 0.0, 0.0 };

	objectsMobileLane5.push_back(new FloatingLog(posFloatingLog8, game, getLane5Velocity(), dirFloatingLog4));

	//LANE 4

	float posBus[] = { lateralEsquerda, -3, -1.8 };
	float dirBus[] = { 1, 0.0, 0.0 };

	objectsMobileLane6.push_back(new Bus(posBus, game, getLane6Velocity(), dirBus));

	//LANE 5

	float posCar1[] = { lateralDireita, -5, -1.8 };
	float dirCar1[] = { -1, 0.0, 0.0 };

	float posCar2[] = { -2.0, -5, -1.8 };
	float dirCar2[] = { -1, 0.0, 0.0 };


	objectsMobileLane7.push_back(new Car(posCar1, game, getLane7Velocity(), dirCar1));
	objectsMobileLane7.push_back(new Car(posCar2, game, getLane7Velocity(), dirCar2));

	//LANE 6

	float posCar3[] = { 2.0, -7.0, -1.8 };
	float dirCar3[] = { 1, 0.0, 0.0 };

	float posCar4[] = { lateralEsquerda, -7.0, -1.8 };
	float dirCar4[] = { 1, 0.0, 0.0 };

	objectsMobileLane8.push_back(new Car(posCar3, game, getLane8Velocity(), dirCar3));
	objectsMobileLane8.push_back(new Car(posCar4, game, getLane8Velocity(), dirCar4));


}

ManagerObj::~ManagerObj() {

}

void ManagerObj::draw() {
	for (Object* o : objects)
		o->draw();
	for (MobileObj* o : objectsMobileLane1)
		if ((o->getPositionXXs() < 20) && (o->getPositionXXs()  > -20))
			o->draw();
	for (MobileObj* o : objectsMobileLane2)
		if ((o->getPositionXXs() < 20) && (o->getPositionXXs()  > -20))
			o->draw();
	for (MobileObj* o : objectsMobileLane3)
		if ((o->getPositionXXs() < 20) && (o->getPositionXXs()  > -20))
			o->draw();
	for (MobileObj* o : objectsMobileLane6)
		if ((o->getPositionXXs() < 20) && (o->getPositionXXs()  > -20))
			o->draw();
	for (MobileObj* o : objectsMobileLane7)
		if ((o->getPositionXXs() < 20) && (o->getPositionXXs()  > -20))
			o->draw();
	for (MobileObj* o : objectsMobileLane8)
		if ((o->getPositionXXs() < 20) && (o->getPositionXXs()  > -20))
			o->draw();

	//bridge test
	for (MobileObj* o : objectsMobileLane4)
		o->draw();
	for (MobileObj* o : objectsMobileLane5)
		o->draw();


}

void ManagerObj::init(){


}

void ManagerObj::reset() {

	dificuldade = 1;

	for (MobileObj* o : objectsMobileLane1){
		o->reset();
	}
	for (MobileObj* o : objectsMobileLane2){
		o->reset();
	}
	for (MobileObj* o : objectsMobileLane3){
		o->reset();
	}
	for (MobileObj* o : objectsMobileLane4){
		o->reset();
	}
	for (MobileObj* o : objectsMobileLane5){
		o->reset();
	}
	for (MobileObj* o : objectsMobileLane6){
		o->reset();
	}
	for (MobileObj* o : objectsMobileLane7){
		o->reset();
	}
	for (MobileObj* o : objectsMobileLane8){
		o->reset();
	}
}

bool ManagerObj::laneCollision(std::vector<MobileObj*> lane, MobileObj* obj)
{
	bool collision = false;
	for (MobileObj *el : lane) 
	{
		if (el != obj)
		{
			if ((obj->getWidth() / 2 + el->getWidth() / 2) > fabs((obj->getPositionXXs() - el->getPositionXXs())))
				collision = true;
		}
	}

	return collision;
}

float ManagerObj::getRiverLaneVelocity(Vector &laneDir)
{
	canColideLane1 = false;
	canColideLane2 = false;
	canColideLane3 = false;
	canColideLane4 = false;
	canColideLane5 = false;
	laneDir = Vector(3);

	if ((11.8 > frogBottomYYs) && (10.2 < frogBottomYYs) || (11.8 > frogTopYYs) && (10.2 < frogTopYYs)){
		canColideLane1 = true;
	}
	if ((9.8 > frogBottomYYs) && (8.2 < frogBottomYYs) || (9.8 > frogTopYYs) && (8.2 < frogTopYYs)){
		canColideLane2 = true;
	}
	if ((7.8 > frogBottomYYs) && (6.2 < frogBottomYYs) || (7.8 > frogTopYYs) && (6.2 < frogTopYYs)){
		canColideLane3 = true;
	}
	if ((5.8 > frogBottomYYs) && (4.2 < frogBottomYYs) || (5.8 > frogTopYYs) && (4.2 < frogTopYYs)){
		canColideLane4 = true;
	}
	if ((3.8 > frogBottomYYs) && (2.2 < frogBottomYYs) || (3.8 > frogTopYYs) && (2.2 < frogTopYYs)){
		canColideLane5 = true;
	}

	for (MobileObj* o : objectsMobileLane1)
	{
		//XXs check
		//soma das dimens�es t�m de ser maiores que a dist�ncia para haver colis�o
		if (canColideLane1){
			if (((frogWeigth / 2 + o->getWidth() / 2) > fabs((frogXXs - o->getPositionXXs()))))
			{
				laneDir = getLane1Direction();
				return o->getVelocity();
			}
		}
	}

	for (MobileObj* o : objectsMobileLane2)
	{
		//XXs check
		//soma das dimens�es t�m de ser maiores que a dist�ncia para haver colis�o
		if (canColideLane2){
			if (((frogWeigth / 2 + o->getWidth() / 2) > fabs((frogXXs - o->getPositionXXs()))))
			{
				laneDir = getLane2Direction();
				return o->getVelocity();
			}
		}
	}

	for (MobileObj* o : objectsMobileLane3)
	{
		//XXs check
		//soma das dimens�es t�m de ser maiores que a dist�ncia para haver colis�o
		if (canColideLane3){
			if (((frogWeigth / 2 + o->getWidth() / 2) > fabs((frogXXs - o->getPositionXXs()))))
			{
				laneDir = getLane3Direction();
				return o->getVelocity();
			}
		}
	}

	for (MobileObj* o : objectsMobileLane4)
	{
		//XXs check
		//soma das dimens�es t�m de ser maiores que a dist�ncia para haver colis�o
		if (canColideLane4){
			if (((frogWeigth / 2 + o->getWidth() / 2) > fabs((frogXXs - o->getPositionXXs()))))
			{
				laneDir = getLane4Direction();
				return o->getVelocity();
			}
		}
	}

	for (MobileObj* o : objectsMobileLane5)
	{
		//XXs check
		//soma das dimens�es t�m de ser maiores que a dist�ncia para haver colis�o
		if (canColideLane5){
			if (((frogWeigth / 2 + o->getWidth() / 2) > fabs((frogXXs - o->getPositionXXs()))))
			{
				laneDir = getLane5Direction();
				return o->getVelocity();
			}
		}
	}

	return 0.0f;
}

void ManagerObj::update(float dt, Frog* frog) {

	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	dificuldade = currentTime / 5000 + 1;


	//frog collision variables
	frogXXs = frog->getPositionXXs();
	frogYYs = frog->getPositionYYs();

	frogTopYYs = frogYYs + frogHeigth / 2;
	frogBottomYYs = frogYYs - frogHeigth / 2;
	frogRigthXXs = frogXXs + frogWeigth / 2;
	frogLeftXXs = frogYYs - frogWeigth / 2;

	canColideLane1 = false;
	canColideLane2 = false;
	canColideLane3 = false;
	canColideLane6 = false;
	canColideLane7 = false;
	canColideLane8 = false;

	canColideLane4 = false;
	canColideLane5 = false;

	onSurface = false;
	/*
	//validPositions a false
	for (int t = 0; t < 8; ++t) {
		for (int i = 0; i < 5; ++i){
			validPositions[t][i] = false;
		}
	}
	*/
	//YYS check
	//river collision lanes to use

	if ((11.8 > frogBottomYYs) && (10.2 < frogBottomYYs) || (11.8 > frogTopYYs) && (10.2 < frogTopYYs)){
		canColideLane1 = true;
	}
	if ((9.8 > frogBottomYYs) && (8.2 < frogBottomYYs) || (9.8 > frogTopYYs) && (8.2 < frogTopYYs)){
		canColideLane2 = true;
	}
	if ((7.8 > frogBottomYYs) && (6.2 < frogBottomYYs) || (7.8 > frogTopYYs) && (6.2 < frogTopYYs)){
		canColideLane3 = true;
	}
	if ((5.8 > frogBottomYYs) && (4.2 < frogBottomYYs) || (5.8 > frogTopYYs) && (4.2 < frogTopYYs)){
		canColideLane4 = true;
	}
	if ((3.8 > frogBottomYYs) && (2.2 < frogBottomYYs) || (3.8 > frogTopYYs) && (2.2 < frogTopYYs)){
		canColideLane5 = true;
	}

	//road collision lanes to use

	if ((-3.8 < frogBottomYYs) && (-2.2 > frogBottomYYs) || (-3.8 < frogTopYYs) && (-2.2 > frogTopYYs)){
		canColideLane6 = true;
	}
	if ((-5.8 < frogBottomYYs) && (-4.2 > frogBottomYYs) || (-5.8 < frogTopYYs) && (-4.2 > frogTopYYs)){
		canColideLane7 = true;
	}
	if ((-7.9 < frogBottomYYs) && (-6.3 > frogBottomYYs) || (-7.9 < frogTopYYs) && (-6.3 > frogTopYYs)){
		canColideLane8 = true;
	}



	//colision variables for the random //to be changed *******************************************************

	for (Object* o : objects){
		o->update(dt);
	}

	/*
	//fazer update �s posi��es v�lidas para o random
	for (MobileObj* o : objectsMobileLane1){
		updateValidPositions(1, o->getPositionXXs());
	}
	for (MobileObj* o : objectsMobileLane2){
		updateValidPositions(2, o->getPositionXXs());
	}
	for (MobileObj* o : objectsMobileLane3){
		updateValidPositions(3, o->getPositionXXs());
	}
	for (MobileObj* o : objectsMobileLane4){
		updateValidPositions(1, o->getPositionXXs());
	}
	for (MobileObj* o : objectsMobileLane5){
		updateValidPositions(1, o->getPositionXXs());
	}
	for (MobileObj* o : objectsMobileLane6){
		updateValidPositions(6, o->getPositionXXs());
	}
	for (MobileObj* o : objectsMobileLane7){
		updateValidPositions(7, o->getPositionXXs());
	}
	for (MobileObj* o : objectsMobileLane8){
		updateValidPositions(8, o->getPositionXXs());
	}

	*/

	for (MobileObj* o : objectsMobileLane1){
		o->update(dt);
		

		//XXs check
		//soma das dimens�es t�m de ser maiores que a dist�ncia para haver colis�o
		if (canColideLane1){
			if (((frogWeigth / 2 + logWeigth / 2) > fabs((frogXXs - o->getPositionXXs()))))
				onSurface = true;

		}

		o->multiplyVelocity(dificuldade);
		if (o->getPositionXXs() > (lateralDireita + 4)){
			do {
				o->setPositionXXs(lateralEsquerda - 4 - (rand() % 10));
			} while (laneCollision(objectsMobileLane1, o));
		}
		/*
		if (o->getPositionXXs() > (lateralDireita + 4)){
			randomIndex = validateRandomPosition(1, (rand() % 5));
			o->setPositionXXs(-(getRandomStartPosition(randomIndex)));

		}
		*/



	}
	//fazer update �s posi��es v�lidas para o random
	for (MobileObj* o : objectsMobileLane2){
		o->update(dt);

		if (canColideLane2){
			if (((frogWeigth / 2 + turtleWeigth / 2) > fabs((frogXXs - o->getPositionXXs()))))
				onSurface = true;
		}

		o->multiplyVelocity(dificuldade);
		if (o->getPositionXXs() < (lateralEsquerda - 4)){
			do {
				o->setPositionXXs(lateralDireita + 4 + (rand() % 10));
			} while (laneCollision(objectsMobileLane2, o));
		}
		/*
		if (o->getPositionXXs() < (lateralEsquerda - 4)){
			randomIndex = validateRandomPosition(2, (rand() % 4));
			o->setPositionXXs((getRandomStartPosition(randomIndex)));
		}
		*/


	}
	for (MobileObj* o : objectsMobileLane3){
		o->update(dt);

		if (canColideLane3){
			if (((frogWeigth / 2 + logWeigth / 2) > fabs((frogXXs - o->getPositionXXs()))))
				onSurface = true;
		}

		o->multiplyVelocity(dificuldade);
		if (o->getPositionXXs() > (lateralDireita + 4)){
			do {
				o->setPositionXXs(lateralEsquerda - 4 - (rand() % 10));
			} while (laneCollision(objectsMobileLane3, o));
		}
		/*
		if (o->getPositionXXs() > (lateralDireita + 4)){
			randomIndex = validateRandomPosition(3, (rand() % 5));
			o->setPositionXXs(-(getRandomStartPosition(randomIndex)));
		}
		*/
	}

	for (MobileObj* o : objectsMobileLane4){
		o->update(dt);

		if (canColideLane4){
			if (((frogWeigth / 2 + logWeigth / 2) > fabs((frogXXs - o->getPositionXXs()))))
				onSurface = true;
		}

		o->multiplyVelocity(dificuldade);
		if (o->getPositionXXs() > (lateralDireita + 4)){
			do {
				o->setPositionXXs(lateralEsquerda - 4 - (rand() % 10));
			} while (laneCollision(objectsMobileLane4, o));
		}
		/*
		if (o->getPositionXXs() > (lateralDireita + 4)){
			randomIndex = validateRandomPosition(4, (rand() % 5));
			o->setPositionXXs((getRandomStartPosition(randomIndex)));
		}
		*/

	}

	for (MobileObj* o : objectsMobileLane5){
		o->update(dt);

		if (canColideLane5){
			if (((frogWeigth / 2 + logWeigth / 2) > fabs((frogXXs - o->getPositionXXs()))))
				onSurface = true;
		}

		o->multiplyVelocity(dificuldade);
		if (o->getPositionXXs() > (lateralDireita + 4)){
			do {
				o->setPositionXXs(lateralEsquerda - 4 - (rand() % 10));
			} while (laneCollision(objectsMobileLane5, o));
		}
		/*
		if (o->getPositionXXs() > (lateralDireita + 4)){
			randomIndex = validateRandomPosition(5, (rand() % 5));
			o->setPositionXXs((getRandomStartPosition(randomIndex)));
		}
		*/

	}

	for (MobileObj* o : objectsMobileLane6){
		o->update(dt);

		if (canColideLane6){
			if ((frogWeigth / 2 + busWeigth / 2) > fabs((frogXXs - o->getPositionXXs())))
				frog->killed();
		}

		o->multiplyVelocity(dificuldade);
		if (o->getPositionXXs() > (lateralDireita + 4)){
			do {
				o->setPositionXXs(lateralEsquerda - 4 - (rand() % 10));
			} while (laneCollision(objectsMobileLane6, o));
		}
		/*
		if (o->getPositionXXs() > (lateralDireita + 4)){
			randomIndex = validateRandomPosition(6, (rand() % 5));
			o->setPositionXXs(-(getRandomStartPosition(randomIndex)));
		}
		*/

	}
	for (MobileObj* o : objectsMobileLane7){
		o->update(dt);

		if (canColideLane7){
			if ((frogWeigth / 2 + carWeigth / 2) > fabs((frogXXs - o->getPositionXXs())))
				frog->killed();
		}

		o->multiplyVelocity(dificuldade);

		if (o->getPositionXXs() < (lateralEsquerda - 4)){
			do {
				o->setPositionXXs(lateralDireita + 4 + (rand() % 10));
			} while (laneCollision(objectsMobileLane7, o));
		}

		/*
		if (o->getPositionXXs() < (lateralEsquerda - 4)){
			randomIndex = validateRandomPosition(7, (rand() % 5));
			o->setPositionXXs((getRandomStartPosition(randomIndex)));
		}
		*/

	}
	for (MobileObj* o : objectsMobileLane8){
		o->update(dt);
		
		if (canColideLane8){
			if ((frogWeigth / 2 + carWeigth / 2) > fabs((frogXXs - o->getPositionXXs())))
				frog->killed();
		}

		o->multiplyVelocity(dificuldade);

		if (o->getPositionXXs() > (lateralDireita + 4)){
			do {
				o->setPositionXXs(lateralEsquerda - 4 - (rand() % 10));
			} while (laneCollision(objectsMobileLane8, o));
		}
		/*
		if (o->getPositionXXs() > (lateralDireita + 4)){
			randomIndex = validateRandomPosition(8, (rand() % 5));
			o->setPositionXXs(-(getRandomStartPosition(randomIndex)));
		}
		*/

	}

	float vel[3];

	
	//se em river verificar se h� alguma colis�o, se houve ent�o tudo bem.
	if ((frogYYs > 2.0) && (frogYYs < 12.0)){
		if (!onSurface)
			frog->killed();
	}
		/*
		else if (frogOnLane1){
			vel = { getLane1Velocity(), 0, 0 };
			frog->move(vel);
		}
		else if (frogOnLane2){
			vel = { getLane2Velocity(), 0, 0 };
			frog->move(vel);
		}
		else if (frogOnLane3){
			vel = { getLane3Velocity(), 0, 0 };
			frog->move(vel);
		}
	}

	*/
		


}


void ManagerObj::setDificuldade(float dificuldade){
	this->dificuldade = dificuldade;
}

void ManagerObj::setLateralEsquerda(float lateralEsquerda){
	this->lateralEsquerda = lateralEsquerda;
}

void ManagerObj::setLateralDireita(float lateralDireita){
	this->lateralDireita = lateralDireita;
}


float ManagerObj::getLane1Velocity() {

	return 0.2 * dificuldade;
}
float ManagerObj::getLane2Velocity() {

	return 1.2 * dificuldade;
}
float ManagerObj::getLane3Velocity() {

	return 0.2 * dificuldade;
}
float ManagerObj::getLane4Velocity() {

	return 0 * dificuldade;
}
float ManagerObj::getLane5Velocity() {

	return 0 * dificuldade;
}
float ManagerObj::getLane6Velocity() {

	return 1 * dificuldade;
}
float ManagerObj::getLane7Velocity() {

	return 2 * dificuldade;
}
float ManagerObj::getLane8Velocity() {

	return 2 * dificuldade;
}

/*
int ManagerObj::validateRandomPosition(int lane, int randomIndex){
		
	int laneArray = lane - 1;
	
	do{ randomIndex = ((randomIndex + 2) % 5); } while (validPositions[laneArray][randomIndex] == true);

	//s� deve haver 1 colis�o com a parede da direita 
	//validPositions[laneArray][randomIndex] = true;

	//std::cout << randomIndex << ' ';

	return randomIndex;
}
/*
int ManagerObj::getRandomStartPosition(int randomIndex){


	if (randomIndex == 0){
		
		//std::cout << 22 << std::endl;
		return 22;
	}
	else if (randomIndex == 1){
		//std::cout << 25.5 << std::endl;
		return 25.5;
	}
	else if (randomIndex == 2){
		 //std::cout << 29 << std::endl;
		 return 29;
	}
	else if (randomIndex == 3){
		//std::cout << 32.5 << std::endl;
		return 32.5;
	}
	else if (randomIndex == 4){
		 //std::cout << 35 << std::endl;
		 return 35;
	}
	else //never here
		return 0.0;
		
}
/*
void ManagerObj::updateValidPositions(int lane,float objectXXs){

	float pos = fabs(objectXXs);
	int laneArray = lane - 1;


	//std::cout << std::endl << "new check"  << ' ' << "object position is" << objectXXs << ' ';
	if ((pos > 19.5) && (pos < 24.1)){

		validPositions[laneArray][0] = true;
		//std::cout << "0 is" << validPositions[laneArray][0] << ' ';
	}

	if ((pos > 22.9) && (pos < 28.5)){
		validPositions[laneArray][1] = true;
		//std::cout << "1 is" << validPositions[laneArray][1] << ' ';
	}

	if ((pos > 25.4 && pos < 31.6)){
		validPositions[laneArray][2] = true;
		//std::cout << "2 is" << validPositions[laneArray][2] << ' ';
	}


	if ((pos > 28.9 && pos < 35.5)){
		validPositions[laneArray][3] = true;
		//std::cout << "3 is" << validPositions[laneArray][3] << ' ';
	}


	if ((pos > 30.4 && pos < 38.6)){
		validPositions[laneArray][4] = true;
		//std::cout << "4 is" << validPositions[laneArray][4] << ' ';
	}


}*/

Vector ManagerObj::getLane1Direction()
{
	float dirLane1[] = { 1, 0.0, 0.0 };
	Vector dir(dirLane1, 3);
	return dir;
}

Vector ManagerObj::getLane2Direction()
{
	float dirLane2[] = { -1, 0.0, 0.0 };
	Vector dir(dirLane2, 3);
	return dir;
}

Vector ManagerObj::getLane3Direction()
{
	float dirLane3[] = { 1, 0.0, 0.0 };
	Vector dir(dirLane3, 3);
	return dir;
}

Vector ManagerObj::getLane4Direction()
{
	float dirLane4[] = { 1, 0.0, 0.0 };
	Vector dir(dirLane4, 3);
	return dir;
}

Vector ManagerObj::getLane5Direction()
{
	float dirLane5[] = { 1, 0.0, 0.0 };
	Vector dir(dirLane5, 3);
	return dir;
}
