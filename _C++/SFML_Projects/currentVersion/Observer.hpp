#ifndef OBSERVER_HPP
#define OBSERVER_HPP

class Observable;
class Entity;
class Character;

class Observer
{
public:
	virtual void Update() = 0;
	virtual void Update(Character*) = 0;
	virtual void SetEntity(Entity*) = 0;
	virtual void DelEntity() = 0;
};

#endif //OBSERVER_HPP