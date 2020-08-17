#pragma once
//comment
#include "Vector2D.h"

#define UNIT_MASS 1.0f
#define GRAVITY 9.8f

class RigidBody {

public:
	RigidBody() {

		Mass = UNIT_MASS;
		Gravity = GRAVITY;
	}

	inline void SetMass(float mass) { Mass = mass; }
	inline void SetGravity(float gravity) { Gravity = gravity; }

	inline void ApplyForce(Vector2D F) { Force = F; }
	inline void ApplyForceX(float Fx) { Force.X = Fx; }
	inline void ApplyForceY(float Fy) { Force.Y = Fy; }
	inline void UnsetForce() { Force = Vector2D(0, 0); }

	inline void ApplyFriction(Vector2D Fr) { Friction = Fr; }
	inline void UnSetFriction() { Friction = Vector2D(0, 0); }

	void Update(float dt) {

		Acceleration.X = (Force + Friction.X) / Mass;
		Acceleration.X = (Gravity + Force) / Mass;
	}

private:
	float Mass;
	float Gravity;

	Vector2D Force;
	Vector2D Friction;

	Vector2D Position;
	Vector2D Velocity;
	Vector2D Acceleration;
};
