#pragma once
#include "Page.h"
#include "Text.h"
#include "SLetter.h"
#include "NLetter.h"
#include "ALetter.h"
#include "KLetter.h"
#include "ELetter.h"

namespace SnakeRevival {
	namespace composite {

		class MainMenu :
			public Page
		{
		public:
			MainMenu();
			~MainMenu();
			virtual void SelectNext();
			virtual void Update() override;
			void RotateColours();
		private:
			composite::Text *m_PlayButton;
			composite::Text *m_QuitButton;
			composite::Text *m_Performance;

			composite::SLetter *m_S;
			composite::NLetter *m_N;
			composite::ALetter *m_A;
			composite::KLetter *m_K;
			composite::ELetter *m_E;

			Color m_ColorCounter = Color::White;
		};
	}
}