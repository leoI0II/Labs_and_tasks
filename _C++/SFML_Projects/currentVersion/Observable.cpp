#include "Observable.hpp"
#include"Observer.hpp"

void Observable::Notify()
{
	for (auto& obs : observers)
		obs->Update();
}

void Observable::AttachObserver(Observer* obs)
{
	observers.push_back(obs);
}

void Observable::DetachObserver(Observer* obs)
{
	for (auto it = observers.begin(); it != observers.end(); ++it) {
		if (*it == obs) {
			observers.erase(it);
			break;
		}
	}
}
