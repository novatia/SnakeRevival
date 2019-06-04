#pragma once
#include "Page.h"
#include "WormBody.h"
#include "Fruit.h"
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
			Text *m_Score;
			Direction m_SnakeDirection;
			float m_SnakePosition_X=15;
			float m_SnakePosition_Y=15;
			
			int m_ScoreValue;
			float m_SnakeSpeed = 3;
			bool m_GameOver;

		};
	}
}