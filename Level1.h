#pragma once
#include "Page.h"
#include "WormBody.h"
#include "Fruit.h"
#include "Spider.h"
#include "Text.h"

namespace SnakeRevival {
	namespace composite {
		class Level1 :
			public Page
		{
		public:
			Level1();
			~Level1();
			virtual void Update() override;
			bool IsGameOver();
			void UnsetGameOver();
			void ResetLevel();
		private:
			WormBody *m_Snake;
			Fruit *m_Fruit;
			Spider *m_Spider;
			Text *m_Score;
			Text *m_Performance;

			Direction m_CurrentSnakeDirection;
			float m_SnakePosition_X;
			float m_SnakePosition_Y;
			
			float m_SpiderPosition_X;
			float m_SpiderPosition_Y;
			bool m_PatrollingLeft;
			float m_SpiderSpeed = 4;


			bool m_SpiderCollideSnake;

			int m_ScoreValue;
			float m_SnakeSpeed = 3;
			bool m_GameOver;

			/*these members are necessary to freeze the input direction acquisition 
			until the snake head has really changed its position: they decouple the input speed
			and the game loop speed; furtherly, the input speed doesn't depend on the snake speed
			which is managed by the multiplied float values 
			*/
			bool m_enableInput = true;
			std::pair<int, int> m_SnakePositionPreviousUpdate;
		};
	}
}