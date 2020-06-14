#pragma once

class GameObject;

class Component {
public:
	virtual void setGameObject(GameObject* gameObject);
protected:
	GameObject* gameObject;
};
