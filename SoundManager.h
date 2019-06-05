#pragma once

#pragma once
namespace SnakeRevival {
	namespace singleton {

		class SoundManager
		{
		private:
			SoundManager();
			static SoundManager* m_Instance;

		public:
			static SoundManager* GetInstance();
			void PlayIntro();
			void PlayBeepPitchH();
			void PlayBeepPitchL();

		};
	}
}