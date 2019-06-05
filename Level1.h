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
			Direction m_SnakeDirection;
			float m_SnakePosition_X;
			float m_SnakePosition_Y;
			
			int m_ScoreValue;
			float m_SnakeSpeed = 3;
			bool m_GameOver;

		};
	}
}