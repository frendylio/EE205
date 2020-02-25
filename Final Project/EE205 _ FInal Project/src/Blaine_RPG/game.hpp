#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <SFML/Main.hpp>
#include <stdio.h>
#include <iostream>
#include "collision.hpp"
#include "attacks.hpp"

class Game {
private:	
	/*sf::RenderWindow renderWindow;*/
	sf::RenderWindow renderWindow;
	sf::Texture background;
	sf::Texture adven;
	sf::Image image;
	sf::Event event;
	sf::Texture Skeleton;
	sf::Sprite sprite;
	sf::Sprite adventure;
	sf::Sprite skeleton;
	collision test;
	float direction;
	fire* fireball;
	float health_skeleton = 200;
public:
	//Constructor
	Game()
	{
		renderWindow.create(sf::VideoMode(1280, 720), "RPG GAME");

		fireball = new fire(renderWindow);

		background.loadFromFile("res/images/Blaine_RPG/background.png");
		//for the sprite loading image
		adven.loadFromFile("res/images/Blaine_RPG/Assets/adventurer-idle-00.png");
		Skeleton.loadFromFile("res/images/Blaine_RPG/Assets/big_demon_idle_anim_f0.png");
		//Setting textures of sprites
		
		sprite.setTexture(background, true);
		adventure.setTexture(adven, true );
		skeleton.setTexture(Skeleton, true);

		//setting scalse of the sprites
		adventure.scale(2, 2);
		skeleton.scale(2, 2);


		skeleton.setPosition(500, 500);
	}

	//void check_active()
	//{
	//	while (renderWindow.isOpen()) {
	//		// Check for all the events that occured since the last frame.
	//		while (renderWindow.pollEvent(event)) {
	//			//Handle events here
	//			if (event.type == sf::Event::EventType::Closed)
	//				renderWindow.close();

	//		}
	//	}
	//}
	void renderer()
	{

		//This will close the window if the window is closed
		renderWindow.clear();
		//draws background
		renderWindow.draw(sprite);
		renderWindow.draw(adventure);
		renderWindow.draw(skeleton);


		
		//-> is for accessing pointers to a class
		if(fireball->checkActive() == true)
		fireball->draw();
		renderWindow.display();
	}

	void actions()
	{
		//For moving things
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			// left key is pressed: move our character
			adventure.move(-2.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			// Right key is pressed: move our character
			adventure.move(2.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			// left key is pressed: move our character
			adventure.move(0.f, -2.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			// left key is pressed: move our character
			adventure.move(0.f, 2.f);
		}
		//This is for firing fireballs

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			//sets the direction it fires (Just horizontal for now)
			auto pos = adventure.getPosition();
			fireball->setActive();
			fireball->setPosition(pos.x, pos.y);
		}

		fireball->movement();
		

	}

	void collisions()
	{
		bool intersecting;

		const sf::Sprite testing_overlap = fireball->getSprite();

		//doing the circle test here for overlapping 
		intersecting = test.CircleTest(testing_overlap, skeleton);


		//checking collision of characters (roughly)
		if (intersecting == true)
		{
			std::cout << "Player is colliding" << std::endl;

			float damage_fireball = fireball->getDamage();

			health_skeleton = health_skeleton - damage_fireball;

			fireball->setFalse();

			fireball->setPosition(0, 0);

			//sf::Text text;

			//sf::Font font;

			//font.loadFromFile("charlotte.ttf");

			//// select the font
			//text.setFont(font); // font is a sf::Font

			//// set the string to display
			//text.setString("Hello world");

			//// set the character size
			//text.setCharacterSize(24); // in pixels, not points!

			//// set the color
			//text.setFillColor(sf::Color::Red);

			//// set the text style
			//text.setStyle(sf::Text::Bold | sf::Text::Underlined);

			//renderWindow.draw(text);

		}

	}
};