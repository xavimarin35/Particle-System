#ifndef __j1PARTICLEMANAGER_H__
#define __j1PARTICLEMANAGER_H__

#include "j1Module.h"

class j1ParticleManager : public j1Module
{
public:

	j1ParticleManager();
	virtual ~j1ParticleManager();

	bool Update(float dt);
	bool CleanUp();

private:
};

#endif // __j1PARTICLEMANAGER_H__
