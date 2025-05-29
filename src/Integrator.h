#pragma once
#include "Body.h"
#include "raymath.h"

inline void ExplicitIntegrator(Body& body, float dt)
{
	body.position += body.velocity * dt;
	body.velocity += body.acceleration * dt;
	body.velocity *= 1.0f / (1.0f + (body.damping * dt));
}

inline void SemiImplicitIntegrator(Body& body, float dt)
{
	body.position += body.velocity * dt;
	body.velocity += body.acceleration * dt;
	body.velocity *= 1.0f / (1.0f + (body.damping * dt));
}
