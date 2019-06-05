#include "pch.h"
#include "SoundManager.h"


using namespace SnakeRevival;
using namespace singleton;

SoundManager* SoundManager::m_Instance;
SoundManager::SoundManager()
{

}

SoundManager* SoundManager::GetInstance()
{
	if (m_Instance == nullptr)
		m_Instance = new SoundManager();

	return m_Instance;
}

void SoundManager::PlayBeepPitchH() {
	for (int i = 500; i < 1000; i += 100) {
		Beep(i, 50);
	}
}

void SoundManager::PlayBeepPitchL() {
	for (int i = 3000; i > 0; i -= 10) {
		Beep(i, 1);
	}
}


void SnakeRevival::singleton::SoundManager::PlayIntro()
{
	PlayBeepPitchH();
}
