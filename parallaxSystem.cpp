#include "parallaxSystem.hpp"

#include <cassert>

#include <SFML/Graphics/View.hpp>

namespace aw
{
	void ParallaxSystem::setCenterXOffset(float offset)
	{
		mCenterXOffset = offset;
	}

	void ParallaxSystem::moveCenterX(float offset)
	{
		mCenterXOffset += offset;
	}

	void ParallaxSystem::addLayer(float scrollFactor)
	{
		mLayers.push_back(scrollFactor);
	}

	void ParallaxSystem::setLayerOnView(sf::View &view, std::size_t index)
	{
		assert(index < mLayers.size());
		view.setCenter(mCenterXOffset * mLayers[index], view.getCenter().y);
	}
}