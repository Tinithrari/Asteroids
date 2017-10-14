#pragma once

#include "Updatable.hpp"

#include <SFML/Graphics.hpp>

using namespace sf;

namespace world
{
    class Ship : public Updatable, public Drawable
    {
    private:
        Sprite _ship;
    public:
        Ship();
        ~Ship();

        virtual void processEvent(sf::Event & e) override;
        virtual void update(float delta) override;

        virtual void draw(RenderTarget & target, RenderStates states) const override;
    };
}
