#ifndef __j1PARTICLE_H__
#define __j1PARTICLE_H__

#include "j1Module.h"

class j1Particle
{
public:

	j1Particle();
	virtual ~j1Particle();

	bool Update(float dt);
	bool CleanUp();

private:
};

#endif // __j1PARTICLE_H__