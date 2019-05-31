#include "pch.h"
#include "GotoMainMenuAction.h"
#include "SnakeRevivalGameLoop.h"

using namespace SnakeRevival;
using namespace strategy;

void GotoMainMenuAction::ActionPerformed()
{
	SnakeRevivalGameLoop * sr_instance = SnakeRevivalGameLoop::GetInstance();
	sr_instance->m_CurrentView = &sr_instance->m_Menu;
}
