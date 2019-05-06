#include "j1ParticleManager.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Textures.h"
#include "j1Render.h"

j1ParticleManager::j1ParticleManager() : j1Module()
{
}

j1ParticleManager::~j1ParticleManager()
{
}

bool j1ParticleManager::Start()
{
	particle_tex = App->tex->Load("textures/particle_small.png");

	return true;
}

bool j1ParticleManager::Awake(pugi::xml_node& config)
{
	bool ret = true;

	pugi::xml_document config_ps;
	pugi::xml_node* node = &App->LoadParticleSystemConfig(config_ps);
	pugi::xml_node info = node->child("info").child("emitter");

	for (; info != nullptr; info = info.next_sibling())
	{
		int typeNum = info.attribute("type").as_int();

		if (typeNum == 1)
			LoadData(info, EMITTER_MOUSE);
		else if (typeNum == 2)
			LoadData(info, EMITTER_FIRE);
	}

	return ret;
}


bool j1ParticleManager::Update(float dt)
{
	for (std::list<j1Emitter*>::iterator it = emittersList.begin(); it != emittersList.end(); ++it)
	{
		if ((*it) != nullptr)
			(*it)->Update(dt);
	}

	return true;
}

bool j1ParticleManager::PostUpdate()
{
	for (std::list<j1Emitter*>::iterator it = emittersList.begin(); it != emittersList.end(); ++it)
	{
		if ((*it)->remove)
		{
			delete (*it);
			emittersList.erase(it);
		}
	}

	return true;
}

bool j1ParticleManager::CleanUp()
{
	App->tex->UnLoad(particle_tex);

	for (std::list<j1Emitter*>::iterator it = emittersList.begin(); it != emittersList.end(); ++it)
	{
		if ((*it) != nullptr)
			delete (*it);
	}

	emittersList.clear();

	return true;
}

j1Emitter* j1ParticleManager::SpawnEmitter(fPoint pos, EMITTER_TYPE type)
{
	j1Emitter* ret = nullptr;
	if (type == EMITTER_MOUSE) {
		ret = new j1Emitter(pos, vecData[type].speed, vecData[type].size, vecData[type].angle, vecData[type].rnd, vecData[type].emission,
			vecData[type].particleLife, vecData[type].emitterLife, vecData[type].startColor, vecData[type].endColor, vecData[type].r);
	}
	else if(type == EMITTER_FIRE) {
		ret = new j1Emitter(pos, vecData[type].speed, vecData[type].size, vecData[type].angle, vecData[type].rnd, vecData[type].emission,
			vecData[type].particleLife, vecData[type].emitterLife, vecData[type].startColor, vecData[type].endColor, vecData[type].r);
	}

	emittersList.push_back(ret);
	
	return ret;
}

void j1ParticleManager::LoadData(pugi::xml_node& node, EMITTER_TYPE type)
{
	DataToLoad data;

	data.speed = node.child("speed").attribute("value").as_float();
	data.size = node.child("size").attribute("value").as_float();
	data.angle.x = node.child("angle").attribute("min").as_float();
	data.angle.y = node.child("angle").attribute("max").as_float();
	data.emission = node.child("emission").attribute("value").as_int();
	data.rnd = node.child("rnd").attribute("value").as_int();
	data.particleLife = node.child("particleLife").attribute("value").as_int();
	data.emitterLife = node.child("emitterLife").attribute("value").as_float();

	data.startColor.r = node.child("startColor").attribute("r").as_uint();
	data.startColor.g = node.child("startColor").attribute("g").as_uint();
	data.startColor.b = node.child("startColor").attribute("b").as_uint();
	data.startColor.a = node.child("startColor").attribute("a").as_uint();

	data.endColor.r = node.child("endColor").attribute("r").as_uint();
	data.endColor.g = node.child("endColor").attribute("g").as_uint();
	data.endColor.b = node.child("endColor").attribute("b").as_uint();
	data.endColor.a = node.child("endColor").attribute("a").as_uint();

	data.r.x = node.child("rect").attribute("x").as_int();
	data.r.y = node.child("rect").attribute("y").as_int();
	data.r.w = node.child("rect").attribute("w").as_int();
	data.r.h = node.child("rect").attribute("h").as_int();

	vecData[type] = data;
}

bool j1ParticleManager::RemoveMouseFire(j1Emitter & emitter)
{
	
	for (std::list<j1Emitter*>::const_iterator it = emittersList.begin(); it != emittersList.end(); ++it)
	{
		if ((*it) == &emitter)
		{
			(*it)->remove = true;
			return true;
		}
	}

	return false;
}

bool j1ParticleManager::RemoveEverything()
{
	bool ret = false;

	for (std::list<j1Emitter*>::const_iterator it = emittersList.begin(); it != emittersList.end(); ++it)
	{
		if ((*it) != nullptr) {
			(*it)->remove = true;
			ret = true;
		}
	}

	return ret;
}





