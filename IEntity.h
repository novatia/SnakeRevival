#pragma once

namespace SnakeRevival {
	class IEntity
	{
	public:
		IEntity() {
		};
		virtual ~IEntity() {
		};

		virtual void Update();
	};

}