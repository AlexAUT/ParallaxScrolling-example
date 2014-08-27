#include <iostream>

#include <SFML/Graphics.hpp>

#include "parallaxSystem.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Parralay Scrolling");
	window.setVerticalSyncEnabled(true);

	aw::ParallaxSystem scrollSystem;
	//Offset = the center of the "main"view
	scrollSystem.setCenterXOffset(0.f);

	scrollSystem.addLayer(1.0f); //Scrolls 1:1 with setXOffset/moveX
	scrollSystem.addLayer(0.5f); //Scrolls at half speed
	scrollSystem.addLayer(0.25f); //Scrolls at 1/4 speed

	//3 objects to show the difference between the 3layer
	sf::RectangleShape rect1({ 100.f, 100.f });
	rect1.setPosition({ 0, 100 });
	rect1.setFillColor(sf::Color::Red);
	sf::RectangleShape rect2({ 100.f, 100.f });
	rect2.setPosition({ 0, 250 });
	rect2.setFillColor(sf::Color::Green);
	sf::RectangleShape rect3({ 100.f, 100.f });
	rect3.setPosition({ 0, 400 });
	rect3.setFillColor(sf::Color::Blue);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			scrollSystem.moveCenterX(-1.f); //Scroll the view
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			scrollSystem.moveCenterX(1.f); //Scroll the view
		}

		window.clear();
		
		sf::View view = window.getDefaultView();
		//Set the first layer active
		scrollSystem.setLayerOnView(view, 0);
		window.setView(view);
		//draw the first rect with the view of the first layer
		window.draw(rect1);
		//... the same for the other layers
		scrollSystem.setLayerOnView(view, 1);
		window.setView(view);
		window.draw(rect2);

		scrollSystem.setLayerOnView(view, 2);
		window.setView(view);
		window.draw(rect3);

		window.display();
	}

	return 0;
}