#include "j1App.h"
#include "j1Input.h"
#include "j1Scene.h"
#include "p2Log.h"
#include "j1Audio.h"

j1Scene::j1Scene() : j1Module()
{
	name = "scene";
}

j1Scene::~j1Scene()
{}

bool j1Scene::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

bool j1Scene::Start()
{
	return true;
}

bool j1Scene::PreUpdate()
{
	return true;
}

bool j1Scene::Update(float dt)
{

	if (App->input->GetMouseButtonDown(1) == KEY_DOWN)
	{
		visibleFire = !visibleFire;

		if (visibleFire == true) {
			int mouseX, mouseY;
			App->input->GetMousePosition(mouseX, mouseY);
			fPoint pos = { (float)mouseX, (float)mouseY };

			mouseFire = App->ps_manager->SpawnEmitter(pos, EMITTER_MOUSE);
		}
	
		else if (visibleFire == false) 
		{
			App->ps_manager->RemoveMouseFire(*mouseFire);
		}
	}

	if (mouseFire != nullptr)
	{
		// TODO 4: Use the UpdatePos(pos) to make mouseFire emitter follows the position of your mouse 




	}

	if (App->input->GetMouseButtonDown(3) == KEY_DOWN)
	{
		int mouseX, mouseY;
		App->input->GetMousePosition(mouseX, mouseY);
		fPoint pos = { (float)mouseX, (float)mouseY };
		staticFire = App->ps_manager->SpawnEmitter(pos, EMITTER_FIRE);
	}

	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
	{
		App->ps_manager->RemoveEverything();
	}

	return true;
}

bool j1Scene::PostUpdate()
{
	bool ret = true;

	if (App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;
}

bool j1Scene::CleanUp()
{
	LOG("Freeing scene");

	mouseFire = nullptr;
	staticFire = nullptr;

	return true;
}
