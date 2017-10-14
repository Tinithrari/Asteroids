#pragma once

#include "Updatable.hpp"

#include <SFML/Graphics.hpp>

using namespace sf;

namespace world
{
	class Asteroid : public Updatable, public Drawable
	{
	private:
		Sprite _sprite;
		int _size;
	public:
		Asteroid(int size, Vector2f position);
		~Asteroid();

		// Hérité via Updatable
		virtual void processEvent(sf::Event & e) override;
		virtual void update(float delta) override;

		// Hérité via Drawable
		virtual void draw(RenderTarget & target, RenderStates states) const override;
	};
}