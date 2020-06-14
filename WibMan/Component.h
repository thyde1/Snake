#pragma once

class GameObject;

class Component {
public:
	void setGameObject(GameObject* gameObject);
protected:
	GameObject* gameObject;
};
