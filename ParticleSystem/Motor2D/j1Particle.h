#ifndef __j1PARTICLE_H__
#define __j1PARTICLE_H__

#include "j1Module.h"

class j1Particle
{
public:

	j1Particle();

	// Destructor
	virtual ~j1Particle();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

private:
};

#endif // __j1PARTICLE_H__