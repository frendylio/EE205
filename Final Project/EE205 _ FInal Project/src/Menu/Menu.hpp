#pragma once
#include "Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 4 // how many we want to display

//Class Menu
class Menu
{
public:
	//Menu size
	Menu(float width, float height);
	
	//Descontructor
	~Menu();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
	//Number of options to choose
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

};
