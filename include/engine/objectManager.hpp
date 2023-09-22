#pragma once
#include <SDL2/SDL.h>
#include "gameObject.hpp"
#include <vector>

class ObjectManager
{
    private:
        std::vector<GameObject *> objectList;
        
    public:
        ObjectManager();
        ~ObjectManager();
        int addObject(GameObject *obj);
        void removeObject(long unsigned int id);
        GameObject *getObject(long unsigned int id);
        int getObjectId(GameObject *obj);
        void updateObjects(void);
        void drawObjects(void);
};