#include "Application.hpp"


const sf::Time Application::TimePerFrame = sf::seconds(1.f/60.f);

Application::Application()
: mWindow(sf::VideoMode(1024, 768), "Breakout", sf::Style::Close)
{
}

void Application::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (mWindow.isOpen())
	{
		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			proccessInput();
			update(TimePerFrame);

		}

		render();
	}
}

void Application::proccessInput()
{
	
}

void Application::update(sf::Time dt)
{
}

void Application::render()
{
}
