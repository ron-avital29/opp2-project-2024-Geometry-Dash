#include "Singletones/FactoryMovables.h"

#include "Singletones/TexturesManger.h"
#include "GameObj/Object.h"
#include "GameObj\MovablesObj\Movable.h"
#include "Singletones/TexturesManger.h"
#include "GameObj/MovablesObj/Player.h"
#include "GameObj/MovablesObj/Robot.h"

#include <iostream>

std::unique_ptr<Movable> FactoryMovables::createMovable(ObjectTypes type, World& world, sf::Vector2f position)
{
    auto it = getMovablesMap().find(type);

    if (it == getMovablesMap().end())
    {
        return nullptr;     //throw
    }
    return it->second(world, position); //this is where all the magic happens :) the Movable object is created here and returned (unique)
}

bool FactoryMovables::registeritMovable(ObjectTypes type, std::unique_ptr<Movable>(*f)(World&, sf::Vector2f))
{
    getMovablesMap().emplace(type, f);
    return true;
}

MovablesMap& FactoryMovables::getMovablesMap()
{
    static MovablesMap m_MovablesMap;
    return m_MovablesMap;
}