#pragma once

class GameObject;

class Component {
public:
	virtual void setGameObject(GameObject* gameObject);
	virtual void init();
protected:
	GameObject* gameObject;
};
