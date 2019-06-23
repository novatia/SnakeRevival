#pragma once
#include "Page.h"
#include "Draw.h"
#include "ALetter.h"
#include "ELetter.h"
#include "GLetter.h"
#include "MLetter.h"
#include "OLetter.h"
#include "RLetter.h"
#include "VLetter.h"
#include "Text.h"


namespace SnakeRevival {
	namespace composite {

		class GameOver :
			public Page
		{
		public:
			GameOver();
			~GameOver();
			virtual void Update() override;
			void RotateColours();
			bool IsDone();
			void UnsetDone();
		private:
			bool m_Done;
			Color m_ColorCounter = Color::White;

			GLetter *m_G;
			ALetter *m_A;
			MLetter *m_M;
			ELetter *m_E;
			OLetter *m_O;
			VLetter *m_V;
			ELetter *m_E1;
			RLetter *m_R;
			Text *m_GoToMenu;
		};

	}
}