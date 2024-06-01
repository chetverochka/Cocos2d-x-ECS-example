#include "GameObject.h"

#define REG_COMPONENT(className, objectName) className* objectName = new className; objectName->init(object); components.push_back(objectName);

void Component::init(GameObject* target) {
    object = target;
}

void TransformComponent::init(GameObject* target) {
    Component::init(target);
    int id = target->getID();
    CCLOG("ID = %d", id);
    position = cocos2d::Vec2(350, 150);
    size = cocos2d::Size(50, 50);
}


void SpriteComponent::init(GameObject* object) {
    Component::init(object);

    int id = object->getID();
    std::string filepath = "";
    if (id == 1) {
        filepath = "object.png";
    }

    sprite = cocos2d::Sprite::create(filepath);
    if (!sprite) {
        return;
    }

    TransformComponent* transform = object->getManager()->getComponent<TransformComponent>();

    sprite->setPosition(transform->position);
    sprite->setContentSize(transform->size);
}


void ComponentManager::registerComponents(GameObject* object) {
    REG_COMPONENT(TransformComponent, transformComponent);
    REG_COMPONENT(SpriteComponent, spriteComponent);
}

std::vector<Component*> ComponentManager::getComponentsArray() {
    return components;
}


GameObject::GameObject(int id) : id(id) {
    manager.registerComponents(this);
}

ComponentManager* GameObject::getManager() {
    return &manager;
}

int GameObject::getID() {
    return id;
}

void GameObject::setID(int id) {
    this->id = id;
}
