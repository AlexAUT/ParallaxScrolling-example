#ifndef AW_PARALLAX_SYSTEM_HPP
#define AW_PARALLAX_SYSTEM_HPP

#include <vector>

namespace sf
{
	class View;
}

namespace aw
{
	class ParallaxSystem
	{
	public:
		
		void setCenterXOffset(float offset);
		void moveCenterX(float offset);

		//Scrollfactor:
		//1.f = the layer will scroll exact the same as XOffset
		//0.5f = the layer will scroll at half speed...
		void addLayer(float scrollFactor);

		void setLayerOnView(sf::View &view, std::size_t index);

	private:

	private:
		float mCenterXOffset;
		std::vector<float> mLayers;
	};
}

#endif