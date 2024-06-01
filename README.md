# Cocos2d-x-ECS-example
my ECS implementation

usage example:
```
GameObject object(1);
    TransformComponent* transformComponent = object.getManager()->getComponent<TransformComponent>();

    cocos2d::Size spriteSize = transformComponent->size;

    SpriteComponent* spriteComponent = object.getManager()->getComponent<SpriteComponent>();
    addChild(spriteComponent->sprite);
```
