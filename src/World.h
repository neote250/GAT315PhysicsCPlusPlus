#pragma once
#include "raylib.h"
#include "Body.h"
#include "Spring.h"
#include "Contact.h"
#include <vector>

using bodies_t = std::vector<Body*>;
using springs_t = std::vector<Spring*>;
using contacts_t = std::vector<Contact>;


class World
{
public:
	World() = default;
	~World();

	void Initialize(Vector2 Gravity = Vector2{ 0,-9.81f }, size_t poolSize = 30);
	void DestroyAll();

	void Step(float dt);
	void Draw(const class Scene& scene);

	Body* CreateBody(const Vector2& position, float size, const Color& color);
	Body* CreateBody(Body::Type type, const Vector2& position, float mass, float size, const Color& color);
	bodies_t& GetBodies() { return m_bodies; }

	Spring* CreateSpring(Body* bodyA, Body* bodyB, float restLength, float stiffness, float damping);


	inline static Vector2 gravity{ 0,-9.81f };
	inline static float gravitation{ 0 };
	inline static float springStiffnessMultiplier{ 1 };
	inline static bool simulate{ true };

private:
	bodies_t m_bodies;
	springs_t m_springs;
	contacts_t m_contacts;
};