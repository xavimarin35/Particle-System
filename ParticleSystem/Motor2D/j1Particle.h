#ifndef __j1PARTICLE_H__
#define __j1PARTICLE_H__

#include "j1Module.h"
#include "p2Point.h"
#include "SDL/include/SDL.h"

struct SDL_Texture;

/*
struct ParticleColor
{
	uint r, g, b, alpha;
};
*/

struct ParticleInfo
{
	SDL_Color startColor;
	SDL_Color endColor;
	fPoint pos;
	fPoint vel;
	int life;
	float startSize;
	float endSize;

	SDL_BlendMode blend;
	SDL_Texture* tex;
};


class j1Particle
{
public:

	j1Particle();
	~j1Particle();

	bool Update(float dt);
	bool CleanUp();

private:

	int framesLeft_;

	SDL_Color startColor;
	SDL_Color endColor;
	fPoint pos;
	fPoint vel;
	int life;
	float startSize;
	float endSize;

	SDL_BlendMode blend;
	SDL_Texture* tex = nullptr;
};

#endif // __j1PARTICLE_H__