#ifndef __j1EMITTER_H__
#define __j1EMITTER_H__

#include "j1Module.h"

#include "j1Particle.h"
#include "j1ParticleManager.h"

#include "p2Point.h"

enum EMMITER_TYPE
{
	EMMITER_FIRE,
	EMMITER_EXPLOSION
};

class j1Emitter
{
public:

	j1Emitter(fPoint pos);
	virtual ~j1Emitter();


	bool Update(float dt);
	bool CleanUp();

private:
};

#endif // __j1EMITTER_H__