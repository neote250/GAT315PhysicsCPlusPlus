#pragma once
#include <vector>
#include"raylib.h"

struct Body;

class World
{
public:
	World() = default;
	~World();

	void Initialize(Vector2 Gravity = Vector2{ 0,-9.81f }, size_t poolSize = 30);

	Body* CreateBody(const Vector2& position, float size, const Color& color);
	void Step(float dt);
	void Draw(const class Scene& scene);

	void DestroyAll();

	static Vector2 gravity;
private:
	std::vector<Body*> m_bodies;

};