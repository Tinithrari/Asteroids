#include <SFML/Graphics.hpp>

using namespace sf;

int main(void)
{
	RenderWindow win(VideoMode(800,600), "Asteroids");

	while (win.isOpen()) 
	{
		Event e;

		while (win.pollEvent(e))
		{
			if (e.type == Event::Closed)
				win.close();
		}

		win.clear();
		win.display();
	}

	return 0;
}