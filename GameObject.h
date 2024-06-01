#pragma once
#include "cocos2d.h"
#include <vector>

class GameObject;

class Component {
    GameObject* object;
public:
    virtual void init(GameObject* target);
};

class TransformComponent : public Component {
public:
    cocos2d::Vec2 position;
    cocos2d::Size size;

    void init(GameObject* target) override;
};

class SpriteComponent : public Component {
public:
    cocos2d::Sprite* sprite;

    void init(GameObject* object) override;
};

class ComponentManager {
public:
    void registerComponents(GameObject* object);

    template <typename T>
    T* getComponent() {
        for (auto component : components) {
            T* castedObject = dynamic_cast<T*>(component);
            if (castedObject) {
                return castedObject;
            }
        }
        return nullptr;
    }
    std::vector<Component*> getComponentsArray();
protected:
    std::vector<Component*> components;
};

class GameObject {
    int id;
    ComponentManager manager;
public:
    GameObject(int id);
    ComponentManager* getManager();
    int getID();
    void setID(int id);
};
