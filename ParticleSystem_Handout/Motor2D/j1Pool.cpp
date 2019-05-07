#include "j1Pool.h"
#include "j1Emitter.h"
#include "j1Particle.h"
#include <assert.h>

j1Pool::j1Pool(j1Emitter* emitter)
{
	size = emitter->GetSize();

	// TODO 2: Create an array of particles and assign the first position of the array to a declared particle
	// Take a look to the j1Pool.h to know how you must call the array, the first particle and the size!!




}

j1Pool::~j1Pool()
{
	delete[] vec;
	vec = nullptr;
}

bool j1Pool::Update(float dt)
{
	for (int i = 0; i < size; i++)
	{
		if (vec[i].Living() == true)
		{
			vec[i].Update(dt);
			vec[i].Draw();
		}
		else if(vec[i].Living() == false)
		{
			startParticle = &vec[i];
			
		}
		else { 
			return false; 
		}
	}

	return true;
}

void j1Pool::CreateParticles(fPoint pos, float speed, float angle, float size, int life, SDL_Rect tex, SDL_Color startColor, SDL_Color endColor)
{
	assert(startParticle != nullptr);

	j1Particle* p = startParticle;
	p->LoadParticleProperties(pos, speed, angle, size, life, tex, startColor, endColor);
}