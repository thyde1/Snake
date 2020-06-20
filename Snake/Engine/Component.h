#pragma once

class GameObject;

class Component {
public:
    GameObject* getGameObject();
    virtual void setGameObject(GameObject* gameObject);
    virtual void init();
protected:
    GameObject* gameObject = nullptr;
};
