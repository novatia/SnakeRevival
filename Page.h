#pragma once
#include "VerticalLayout.h"
#include "HorizontalLayout.h"
#include <memory.h>

class Page 
	
{
public:
	Page();
	virtual ~Page();

protected:
	std::unique_ptr<HorizontalLayout> root_object;
};
