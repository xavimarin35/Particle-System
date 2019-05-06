#ifndef __J1PARTICLEMANAGER_H__
#define __J1PARTICLEMANAGER_H__

#include "j1App.h"
#include "p2Point.h"
#include "j1Module.h"
#include "j1Emitter.h"
#include "j1Pool.h"

#include <list>
#include <string>

#define NUM_EMITTERS 2

class j1Emitter;
enum EMITTER_TYPE;

class j1ParticleManager : public j1Module
{

private:

	struct DataToLoad
	{
		EMITTER_TYPE type;
		SDL_Rect r;

		float speed;
		int emission;
		fPoint angle;
		int particleLife;
		double emitterLife;
		float size;
		int rnd;
		
		SDL_Color startColor;
		SDL_Color endColor;
	};
	
public:

	j1ParticleManager();
	~j1ParticleManager();

	bool Start();
	bool Awake(pugi::xml_node& config_node);
	bool Update(float dt);
	bool PostUpdate();
	bool CleanUp();


	j1Emitter* SpawnEmitter(fPoint pos, EMITTER_TYPE type);
	void LoadData(pugi::xml_node& node, EMITTER_TYPE type);
	bool RemoveMouseFire(j1Emitter& emitter);
	bool RemoveEverything();
	
	SDL_Texture* particle_tex = nullptr;
	EMITTER_TYPE type;
	std::list<j1Emitter*> emittersList;
	DataToLoad vecData[NUM_EMITTERS];

};

#endif