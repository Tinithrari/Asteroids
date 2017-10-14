#pragma once

#include "Updatable.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

class Application : private Updatable
{
private:
	sf::Clock _clock;
	sf::RenderWindow _window;
	virtual void processEvent(sf::Event & e) override;
	virtual void update(float delta) override;
	void render();
public:
	Application();
	~Application();
	void run();
};

