/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/
#include "TrigonometryScene.h"
#include "VectorScene.h"
#include "PolarScene.h"
#include "SpringScene.h"
#include "raylib.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(1280, 720, "Hello Raylib");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	// Load a texture from the resources directory
	Texture wabbit = LoadTexture("wabbit_alpha.png");
	

	//create trig scene
	Scene* scene = new SpringScene("SpringScene", 1280, 720);
	scene->Initialize();

	SetTargetFPS(60);
	float timeAccumulator = 0;

	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		scene->Update();
			
		//ensure something runs at a consistent rate
		timeAccumulator += std::min(GetFrameTime(), 0.5f);
		while (timeAccumulator >= Scene::fixedDeltaTime)
		{
			scene->FixedUpdate();
			timeAccumulator -= Scene::fixedDeltaTime;
		}
		scene->BeginDraw();
		scene->Draw();
		scene->DrawGUI();
		scene->EndDraw();
	}

	// cleanup
	// unload our texture so it can be cleaned up
	UnloadTexture(wabbit);

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
