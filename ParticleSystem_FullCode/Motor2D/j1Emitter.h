#ifndef __j1EMITTER_H__
#define __j1EMITTER_H__

#include "p2Point.h"
#include "j1ParticleManager.h"
#include "j1Pool.h"
#include "j1PerfTimer.h"

struct SDL_Texture;
class j1Pool;

enum EMITTER_TYPE
{
	EMITTER_NONE = -1,
	EMITTER_MOUSE,
	EMITTER_FIRE
};

class j1Emitter
{
private:

	EMITTER_TYPE type = EMITTER_NONE;

	fPoint pos;
	fPoint angle;
	float speed;
	float emitterSize;
	int emission;
	int rnd;
	int particleLife;
	SDL_Rect rect;
	double emitterLife;

	SDL_Color startColor;
	SDL_Color endColor;

public:

	j1Emitter(fPoint pos, float maxSpeed, float maxSize, fPoint angleRange, int emitVariance, int emitNumber, int maxParticleLife, double emitterLife, SDL_Color startColor, SDL_Color endColor, SDL_Rect textureRect);
	~j1Emitter();
	
	bool Update(float dt);
	float RandomizeParticles(float min, float max);
	int GetSize() const { return size; }
	void UpdatePos(fPoint newPos) { pos = newPos; }

	j1Pool* container = nullptr;
	int size = 5000;
	bool remove = false;

	float randomSpeed;
	float randomAngle;
	float randomSize;
};

#endif