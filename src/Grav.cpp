#include "Grav.h"
#include "raymath.h"

void ApplyGravitation(bodies_t& bodies, float strength)
{
    for (int i = 0; i < bodies.size(); i++)
    {
        Body* bodyA = bodies[i];

        for (int j = i+1; j < bodies.size(); j++)
        {
            Body* bodyB = bodies[j];

            Vector2 direction = bodyB->position - bodyA->position;
            float distance = Vector2Distance(bodyB->position, bodyA->position);
            distance = (distance < 1) ? 1: distance;
            float forceMagnitude = ((bodyA->mass * bodyB->mass) / (distance * distance)) * strength;
            Vector2 forceVector = Vector2Normalize(direction * forceMagnitude);
            bodyA->ApplyForce(Vector2Negate(forceVector));
            bodyB->ApplyForce(forceVector);
        }
    }
}
