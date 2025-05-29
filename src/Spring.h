#pragma once
#include "scene.h"
#include "raylib.h"

struct Spring
{
public:
	struct Body* bodyA;
	struct Body* bodyB;
	float restLength;
	float k;
	float damping;

public:
	Spring() = default;
	Spring(Body* bodyA, Body* bodyB, float restLength, float k, float damping = 0):
		bodyA{bodyA},
		bodyB{bodyB},
		restLength{restLength},
		k{k},
		damping {damping}
	{ }
	void ApplyForce(float kMultiplier = 1);
	static void ApplyForce(const Vector2& position, struct Body& body, float restLength, float k);

	void Draw(const Scene& scene);
};


//v3 direction = a-b
//float distance = dir.mag
//float rad = a.rad + b.rad

//intersects
//contact depth = a.rad + b.rad ...

//separation = contact depth / total inverse mass

//total inverse mass = 1.5
//contact depth = 2
//separation = 2/1.5 = 1.33
//sepA = 1.33*1
//sep B = 0.667
//sep AB = sepA + sepB