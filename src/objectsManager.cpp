#include "objectManager.hpp"

/**
 * @brief Construct a new Object Manager:: Object Manager object
 * 
 */
ObjectManager::ObjectManager()
{

}

/**
 * @brief Destroy the Object Manager:: Object Manager object
 * 
 */
ObjectManager::~ObjectManager()
{}

/**
 * @brief add the object in the list
 * 
 * @param obj object to be added
 * @return int object id in list
 */
int ObjectManager::addObject(GameObject *obj)
{
    this->objectList.push_back(obj);
    return this->objectList.size() - 1;
}

/**
 * @brief remove an object from the list
 * 
 * @param id object id
 */
void ObjectManager::removeObject(int id)
{
    if (id == this->objectList.size() - 1)
        this->objectList.pop_back();
    else
        this->objectList.erase(this->objectList.begin() + id - 1);
}

/**
 * @brief return an object from id
 * 
 * @param id object id
 * @return GameObject* 
 */
GameObject *ObjectManager::getObject(int id)
{
    return this->objectList[id];
}

/**
 * @brief return an id from an object pointer
 * 
 * @param obj object
 * @return int object id
 */
int ObjectManager::getObjectId(GameObject *obj)
{
    int i = 0;
    for (GameObject *o : this->objectList)
    {
        if (o == obj)
            return i;
        i++;
    }
    return -1;
}

/**
 * @brief updates every active game object
 * 
 */
void ObjectManager::updateObjects(void)
{
    for (GameObject *obj : this->objectList)
        obj->update();
}

/**
 * @brief draw every active game object on the screen based on list order (last objects are drawn last)
 * 
 */
void ObjectManager::drawObjects(void)
{
    for (GameObject *obj : this->objectList)
        obj->draw();
}