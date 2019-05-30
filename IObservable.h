#pragma once
#include "IObserver.h"

namespace gamestructure {

	enum class Event {

		HitAWall = 0,
		HitMyTail = 1,
		EatenFruitItem = 2,
		EatenSuperFruitItem = 3,
		EatenPoisonItem = 4,

	};
	class IObservable
	{
	public:
		IObservable() : observers(new std::list<IObserver*>())
		{
		};
		~IObservable() {
		};

		virtual void RegisterObserver(IObserver* observer) {
			observers->push_back(observer);

		};
		virtual void RemoveObserver(IObserver* observer) {
			observers->remove(observer);
		};
		virtual void NotifyObservers(Event occurredEvent)
		{
			if (observers->size() != 0)
			{
				std::list<IObserver*>::iterator it;

				for (it = observers->begin(); it != observers->end(); it++) {
					//(*it)->AnswerToObservable(occurredEvent);
				}
			}
		};
	private:
		std::list<IObserver*>* observers;
	};


	/*
	IObservable::IObservable() : observers(new std::list<IObserver*>())
	{
	}


	IObservable::~IObservable()
	{
	}

	
	void IObservable::RegisterObserver(IObserver* observer) {
		observers->push_back(observer);

	};
	void IObservable::RemoveObserver(IObserver* observer) {
		observers->remove(observer);
	};

	void IObservable::NotifyObservers(Event eventOccurred)
	{
		if (observers->size() != 0) 
		{
			std::list<IObserver*>::iterator it;

			for (it = observers->begin(); it != observers->end(); it++) {
				(*it)->AnswerToObservable();
			}
		}
	};
	*/
}