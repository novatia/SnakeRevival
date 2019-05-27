#pragma once
class IEntity
{
public:
	IEntity() {
	};
	virtual ~IEntity() {
	};

	virtual void Update() = 0;
};

/*

IEntity::IEntity()
{
}


IEntity::~IEntity()
{
}
*/