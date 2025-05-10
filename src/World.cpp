#include "World.h"
#include "Body.h"
#include "scene.h"

Vector2 World::gravity{ 0,-9.81f };

World::~World()
{

}

void World::Initialize(Vector2 Gravity, size_t poolSize)
{
    World::gravity = gravity;
    m_bodies.reserve(poolSize);
}

Body* World::CreateBody(const Vector2& position, float size, const Color& color)
{
    Body* body = new Body(position, size, color);
    m_bodies.push_back(body);
    return body;
}

void World::Step(float dt)
{
    for (auto body : m_bodies)
    {
        body->Step(dt);
    }
}

void World::Draw(const Scene& scene)
{
    for (auto body : m_bodies)
    {
        body->Draw(scene);
    }
}

void World::DestroyAll()
{
    for (auto body : m_bodies)
    {
        delete body;
    }
    m_bodies.clear();
}
