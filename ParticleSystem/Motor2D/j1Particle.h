#ifndef __j1PARTICLE_H__
#define __j1PARTICLE_H__

#include "p2Point.h"
#include "SDL/include/SDL.h"

struct SDL_Texture;

class j1Particle
{
public:

	j1Particle();
	~j1Particle();

	struct ParticleProperties
	{
		fPoint pos;
		fPoint speed;
		float size;
		float startSize;
		int life;
		int startLife;
		SDL_Rect rect;
		SDL_Rect rectSize;
		SDL_Color startColor;
		SDL_Color endColor;
		float transparency;
		float fraction;
		
	} prop;

	SDL_Rect drawRect;

	void Update(float dt);
	void Draw();
	bool Living();

	float RandomizeParticleColor(float min, float max);
	void LoadParticleProperties(fPoint pos, float speed, float angle, float size, int life, SDL_Rect tex, SDL_Color startColor, SDL_Color endColor);
	SDL_Color InperpolateColors(SDL_Color startColor, SDL_Color endColor, float fraction);
};

#endif