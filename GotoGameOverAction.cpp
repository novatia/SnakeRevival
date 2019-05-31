#include "pch.h"
#include "GotoGameOverAction.h"
#include "SnakeRevivalGameLoop.h"

using namespace SnakeRevival;
using namespace strategy;

void GotoGameOverAction::ActionPerformed()
{
	SnakeRevivalGameLoop * sr_instance = SnakeRevivalGameLoop::GetInstance();
	sr_instance->m_CurrentView = &sr_instance->m_GameOver;
}
