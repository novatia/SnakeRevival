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
			Text *m_PlayButton;
			Text *m_QuitButton;
			Text *m_Performance;

			SLetter *m_S;
			NLetter *m_N;
			ALetter *m_A;
			KLetter *m_K;
			ELetter *m_E;

			Color m_ColorCounter;
		};
	}
}