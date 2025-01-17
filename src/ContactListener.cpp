#pragma once
#pragma region header
#include "ContactListener.h"
#include "GameObj/MovablesObj/Player.h"
#include "GameObj/StaticObj/Block.h"
#pragma endregion header

void ContactListener::BeginContact(b2Contact* contact)
{
    b2Body* firstBody = contact->GetFixtureA()->GetBody();
    b2Body* secondBody = contact->GetFixtureB()->GetBody();
    Object* firstObj = reinterpret_cast<Object*>(firstBody->GetUserData().pointer);
    Object* secondObj = reinterpret_cast<Object*>(secondBody->GetUserData().pointer);

    processCollision(*firstObj, *secondObj);
}
