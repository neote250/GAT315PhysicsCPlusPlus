#pragma once
#include "raylib.h"
#include "World.h"

class GUI
{
public:
	static void Update();
	static void Draw();

	static struct Body* GetBodyIntersect(const Vector2& position, bodies_t& bodies, const SceneCamera& camera);

public:
	inline static bool mouseOverGUI = false;

	inline static Vector2 anchor01 = { 24, 56 };

	inline static bool PhysicsWindowBoxActive = true;

	inline static float BodyMassSliderValue = 1.0f;
	inline static float BodySizeSliderValue = 0.1f;
	inline static float RestitutionSliderValue = 1.0f;
	inline static float GravityScaleSliderValue = 1.0f;
	inline static float WGravForceSliderValue = 0.0f;
	inline static float BodyDampingSliderValue = 0.0f;
	inline static bool BodyTypeSelectionDropdownEditMode = false;
	inline static int BodyTypeSelectionDropdownActive = 0;
	inline static float GravitySliderValue = 0.0f;

};