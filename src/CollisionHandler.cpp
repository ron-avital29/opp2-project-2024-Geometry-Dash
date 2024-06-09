#include "CollisionHandler.h"

#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>

#include "Player.h"
#include "Block.h"
#include "Movable.h"
#include "Static.h"
//and many more

namespace // anonymous namespace � the standard way to make function "static"
{
    // primary collision-processing functions
    void playerBlock(Object& player, Object& block)
    {
        // To get the actual types and use them:
        // SpaceShip& ship = dynamic_cast<SpaceShip&>(spaceShip);
        // Asteroid&  ast  = dynamic_cast<Asteroid&>(asteroid);
        // or:
        // SpaceShip& ship = static_cast<SpaceShip&>(spaceShip);
        // Asteroid&  ast  = static_cast<Asteroid&>(asteroid);

        std::cout << "Player and Block collision!\n";
    }
    //...

    // secondary collision-processing functions that just
    // implement symmetry: swap the parameters and call a
    // primary function
    void blockPlayer(Object& block,
        Object& player)
    {
        playerBlock(player, block);
    }

    void shouldntBeHere(Object& o1, Object& o2)
    {
        //puts("I shouldnt be here");
    }
    //...

    using HitFunctionPtr = void (*)(Object&, Object&);
    // typedef void (*HitFunctionPtr)(GameObject&, GameObject&);
    using Key = std::pair<std::type_index, std::type_index>;
    // std::unordered_map is better, but it requires defining good hash function for pair
    using HitMap = std::map<Key, HitFunctionPtr>;
    
    HitMap initializeCollisionMap()
    {

        HitMap phm;
        phm[Key(typeid(Player), typeid(Block))] = &playerBlock;
        phm[Key(typeid(Block), typeid(Player))] = &blockPlayer;
        phm[Key(typeid(Object), typeid(Object))] = &shouldntBeHere;

        //add more

        /*phm[Key(typeid(SpaceShip), typeid(SpaceStation))] = &shipStation;
        phm[Key(typeid(Asteroid), typeid(SpaceStation))] = &asteroidStation;*/
        //...
        return phm;
    }

    HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
    {
        static HitMap collisionMap = initializeCollisionMap();
        auto mapEntry = collisionMap.find(std::make_pair(class1, class2));

        //std::cout << "end: " << class1.name() << " with " << class2.name() << std::endl;
        if (mapEntry == collisionMap.end())
        {
            return nullptr;
        }
        return mapEntry->second;
    }
}

void processCollision(Object& object1, Object& object2)
{
    auto phf = lookup(typeid(object1), typeid(object2));

    std::cout << typeid(object1).name() << " " << typeid(object2).name() << "\n";

    if (!phf)
    {
        return; //erase
        //throw UnknownCollision(object1, object2);
    }
    phf(object1, object2);
}
