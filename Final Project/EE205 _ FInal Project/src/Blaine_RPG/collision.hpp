#pragma once
#include <Graphics.hpp>
#include <System/Vector2.hpp>
#include <Window.hpp>
#include <Main.hpp>
#include <Graphics/Rect.hpp>
#include <stdio.h>
#include <iostream>
#include <cmath>

class collision {
public:

	bool CircleTest(const sf::Sprite& Object1, const sf::Sprite& Object2) {
		//Simplest circle test possible
		//Distance between points <= sum of radius

		//first getting the rect of both of these objects
		sf::IntRect Radius1 = Object1.getTextureRect();
		sf::IntRect Radius2 = Object2.getTextureRect();
		
		
		float Radius_1 = Radius1.width + Radius1.height / 4;
		float Radius_2 = Radius2.width + Radius2.height / 4;

		sf::Vector2f Object1_position = Object1.getPosition();
		sf::Vector2f Object2_position = Object2.getPosition();

		float xd = float(Object1_position.x - Object2_position.x);
		float yd = float(Object1_position.y - Object2_position.y);

		return sqrt(xd * xd + yd * yd) <= (Radius_1 + Radius_2);
	}
};