#ifndef __j1EMITTER_H__
#define __j1EMITTER_H__

#include "j1Module.h"

class j1Emitter
{
public:

	j1Emitter();

	// Destructor
	virtual ~j1Emitter();

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

#endif // __j1EMITTER_H__