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

    inline static Vector2 anchor01 = { 72, 48 }; //24,56
    inline static Vector2 anchor02 = { 96, 88 };
    inline static Vector2 anchor03 = { 96, 280 };
    inline static Vector2 anchor04 = { 96, 376 };

    inline static bool physicsWindowBoxActive = true;
    inline static float massValue = 1.0f;
    inline static float sizeValue = 0.1f;

    inline static float gravityScaleValue = 1.0f;
    inline static float dampingValue = 0.0f;
    inline static float restitutionValue = 0.9f;

    inline static bool bodyTypeEditMode = false;
    inline static int bodyTypeActive = 0;

    inline static float springDampingValue = 0.0f;
    inline static float stiffnessValue = 0.0f;

    inline static float gravitationValue = 0.0f;
    inline static float gravityValue = -9.8f;
    inline static bool simulateActive = true;
    inline static float springSiffnessMultiplierValue = 0.5f;
    inline static bool resetPressed = false;

};