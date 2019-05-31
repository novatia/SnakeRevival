#include "pch.h"
#include "GotoLevel1Action.h"
#include "SnakeRevivalGameLoop.h"

using namespace SnakeRevival;
using namespace strategy;

void GotoLevel1Action::ActionPerformed()
{
	SnakeRevivalGameLoop * sr_instance = SnakeRevivalGameLoop::GetInstance();
	sr_instance->m_CurrentView = &sr_instance->m_Level1;
}
