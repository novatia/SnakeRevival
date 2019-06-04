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

void SnakeRevival::singleton::SoundManager::PlayIntro()
{

}
