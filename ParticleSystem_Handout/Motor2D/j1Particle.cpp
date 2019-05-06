#include "j1Particle.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1ParticleManager.h"
#include "j1Emitter.h"
#include "j1Pool.h"

#include "p2Point.h"
#include "p2Defs.h"


j1Particle::j1Particle(){}

j1Particle::~j1Particle()
{
}

void j1Particle::Update(float dt)
{
	prop.life--;

	prop.transparency = (float)prop.life / (float)prop.startLife;
	float alpha = (prop.transparency * 255.0f);
	prop.startColor.a = alpha;
	prop.size = prop.startSize * prop.transparency;
	prop.rectSize.w = prop.rectSize.h = prop.size;

	prop.pos.x += prop.speed.x * dt;
	prop.pos.y += prop.speed.y * dt;
}

void j1Particle::Draw()
{
	// prop.fraction += (1.0f / prop.startLife) ---> The particle color changes to endColor duris its life
	// prop.fraction += (0.0f / prop.startLife) ---> The particle color remains the startColor during its life
	prop.fraction += (RandomizeParticleColor(0.0f, 15.0f) / prop.startLife);

	drawRect = { (int)prop.startSize, (int)prop.startSize };
	App->render->Blit(App->ps_manager->particle_tex, prop.pos.x + ((drawRect.w - prop.rectSize.w) / 2), prop.pos.y + ((drawRect.h - prop.rectSize.h) / 2), &prop.rect, &prop.rectSize, InperpolateColors(prop.startColor, prop.endColor, prop.fraction));
}

bool j1Particle::Living()
{
	bool ret = true;

	if (prop.life > 0)
		ret = true;
	else
		ret = false;

	return ret;
}

void j1Particle::LoadParticleProperties(fPoint pos, float speed, float angle, float size, int life, SDL_Rect tex, SDL_Color startColor, SDL_Color endColor)
{
	prop.pos = pos;
	prop.speed.x = speed * cos(angle * PI / (180));
	prop.speed.y = -speed * sin(angle * PI / (180));
	prop.life = prop.startLife = life;
	prop.size = prop.startSize = size;
	prop.rect = prop.rectSize = tex;
	prop.startColor = startColor;
	prop.endColor = endColor;

	prop.fraction = 0.0f;
}


float j1Particle::RandomizeParticleColor(float min, float max)
{
	float random = ((float)rand()) / (float)RAND_MAX;

	return (max - min + 0.25) * random + min;
}

SDL_Color j1Particle::InperpolateColors(SDL_Color color1, SDL_Color color2, float fraction)
{
	SDL_Color result;

	// TODO 1: Create the function to interpolate colors
	// The formula of interpolation is: result = (c2 - c1) * f + c1
	// Remember that a SDL_Color is a struct with 3 primary colors!!







	return result;
}

