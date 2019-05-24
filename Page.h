#pragma once
#include "VerticalLayout.h"
#include <memory.h>

class Page 
	
{
public:
	Page();
	virtual ~Page();

protected:
	std::unique_ptr<VerticalLayout> root_object;
};
