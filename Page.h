#pragma once
#include "VerticalLayout.h"
#include "HorizontalLayout.h"
#include "LayerLayout.h"
#include "IActionListener.h"

namespace SnakeRevival {
	namespace composite {
		class Page : public IEntity
		{
		public:
			Page();
			virtual ~Page();
			virtual std::wstring GetView();
			virtual void SelectNext();
			virtual void AddActionListener(strategy::IActionListener *ActionListener);
			virtual void Update() override;
		protected:
			std::unique_ptr<LayerLayout> m_RootObject;
			strategy::IActionListener *m_ActionListener;
		};
	}
}
