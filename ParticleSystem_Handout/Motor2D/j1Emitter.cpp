#include "j1Emitter.h"
#include "j1Pool.h"
#include "j1Particle.h"

#include <time.h>


j1Emitter::j1Emitter(fPoint pos, float speed, float size, fPoint angle, int rnd, int emission, int particleLife, double emitterLife, SDL_Color startColor, SDL_Color endColor, SDL_Rect tex)
{ 
	srand(time(NULL));
	
	this->pos = pos;
	this->speed = speed;
	this->emitterSize = size;
	this->angle = angle;
	this->rnd = rnd;
	this->emission = emission;
	this->particleLife = particleLife;
	this->emitterLife = emitterLife;
	this->startColor = startColor;
	this->endColor = endColor;
	this->rect = tex;

	container = new j1Pool(this);
}

j1Emitter::~j1Emitter()
{
	delete container;
}

bool j1Emitter::Update(float dt)
{
	bool ret = true;

	if (container->Update(dt) == false) {
		remove = true;
		ret = false;
	}
		
	int emissionRate = (int)(emission + rnd);

	for (int i = 1; i <= emissionRate; i++)
	{
		randomSpeed = speed * RandomizeParticles(0.0f, 2.0f);
		randomAngle = RandomizeParticles(angle.x, angle.y);
		randomSize = emitterSize * RandomizeParticles(0.0f, 1.0f);
		container->CreateParticles(pos, randomSpeed, randomAngle, randomSize, particleLife, rect, startColor, endColor);
	}

	return ret;
}

float j1Emitter::RandomizeParticles(float min, float max)
{

	float random = ((float)rand()) / (float)RAND_MAX;
	
	return (max - min + 0.25) * random + min;

}
