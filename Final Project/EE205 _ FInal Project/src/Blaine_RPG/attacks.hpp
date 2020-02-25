#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <SFML/Main.hpp>
#include <stdio.h>
#include <iostream>

class fire{
private:
	//creating a vector of fireballs
	sf::Sprite fireball;
	sf::Texture fireball_graphic;
	bool isRunning_fireball;
	float damage_fireball = 10;
	sf::Vector2f position;
	sf::RenderWindow& attackWindow;
	sf::Clock clock;
	int diagonal;
public:
	fire(sf::RenderWindow& renderWindow) : attackWindow(renderWindow)
	{	///creating window
		isRunning_fireball = false;

		fireball_graphic.loadFromFile("res/images/Blaine_RPG/Assets/Small_Fireball_10x26.png");

		fireball.setTexture(fireball_graphic, true);
		//This is for setting the fireball to the correct size
		/*fireball.setTextureRect(sf::IntRect(10, 0, 10, 26));*/
	}

	//Default constructor...
	fire();

	~fire();


	//void animation()
	//{
	//	sf::IntRect fireball_dimensions(100, 0, 10, 26);

	//	//This is for implementing the firball with animation/s
	//	if (clock.getElapsedTime().asSeconds() > 5.0f) {
	//		if (fireball.getTextureRect() == fireball_dimensions)
	//		{
	//			fireball.setTexture(fireball_graphic);
	//			fireball.setTextureRect(sf::IntRect(0, 0, 10, 26));
	//			diagonal = 0;
	//		}
	//		else
	//		{
	//			diagonal += 10;
	//			fireball.setTexture(fireball_graphic);
	//			fireball.setTextureRect(sf::IntRect(diagonal, 0, 10, 26));
	//		}
	//		clock.restart();
	//	}


	//}

	void movement()
	{
		if (isRunning_fireball == true)
		{
			fireball.move(0.f, float(0.04));
		}
	}

	sf::Vector2f getSpritePosition()
	{
		const sf::Vector2f position = fireball.getPosition();
	
		return position;
	}

	const sf::Sprite getSprite()
	{
		return fireball;
	}

	void draw()
	{	
		if(isRunning_fireball = true)
		attackWindow.draw(fireball);
	}

	float getDamage()
	{
		return damage_fireball;
	}

	void setActive()
	{
		isRunning_fireball = true;
	}

	bool checkActive()
	{
		return isRunning_fireball;
	}

	void setFalse()
	{
		isRunning_fireball = false;
	}

	void setPosition(int x, int y)
	{
		fireball.setPosition(x, y);
	}

};