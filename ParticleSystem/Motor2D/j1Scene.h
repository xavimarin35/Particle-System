#ifndef __j1SCENE_H__
#define __j1SCENE_H__

#include "j1Module.h"
#include "j1Particle.h"
#include "j1Pool.h"
#include "j1Emitter.h"
#include "p2Point.h"

struct SDL_Texture;

class j1Scene : public j1Module
{
public:

	j1Scene();
	virtual ~j1Scene();

	bool Awake();
	bool Start();
	bool PreUpdate();
	bool Update(float dt);
	bool PostUpdate();
	bool CleanUp();


private:

	j1Emitter* mouseFire = nullptr;
	j1Emitter* staticFire = nullptr;

	bool visibleFire = false;
};

#endif // __j1SCENE_H__