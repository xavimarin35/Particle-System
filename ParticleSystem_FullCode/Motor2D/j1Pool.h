#ifndef __j1POOL_H__
#define __j1POOL_H__

#include "j1App.h"
#include "j1Particle.h"
#include "j1Emitter.h"
#include "p2Point.h"
#include "j1ParticleManager.h"

#include <assert.h>

class j1Emitter;

class j1Pool
{

public:

	j1Pool(j1Emitter* emitter);
	~j1Pool();

	void CreateParticles(fPoint pos, float speed, float angle, float size, int life, SDL_Rect tex, SDL_Color startColor, SDL_Color endColor);
	bool Update(float dt);

	j1Particle* startParticle;
	j1Particle* vec = nullptr;

	int size = 0;
};

#endif