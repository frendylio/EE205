#include "Graphics.hpp"
#include "Audio.hpp"
#include <iostream>
#include "src/Menu/Menu.hpp"

using namespace sf;

int main()
{
//Music for Menu
bool musicStop = false;

//Mini Games Name	
char tetris[] = "Tetris.exe";
char Yumma[] = "Yumma.exe";
char Blaine[] = "Blaine.exe";

	RenderWindow window(VideoMode(1020, 574), "Menu");

//Texture
    Texture t2;
	t2.loadFromFile("res/images/Menu/background3.png");
	Sprite background(t2);

//Music	
	Music music;
	if(!music.openFromFile("res/music/Menu/Menu_Music.ogg"))
	{
		//Menu_Music.ogg
		std::cout << "Error with Music Menu" << std::endl;
	}
	music.play();
	//loop my music 
	music.setLoop(true);

	Menu menu(window.getSize().x, window.getSize().y);
	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::KeyReleased:
				//music
					if (musicStop == true){
						std::cout << "Music" <<musicStop<< std::endl;
						music.stop();
						musicStop = false;
						music.openFromFile("res/music/Menu/Menu_Music.ogg");
						music.play();
					}

				switch (event.key.code)
				{
				case Keyboard::Up:
					menu.MoveUp();
					break;

				case Keyboard::Down:
					menu.MoveDown();
					break;

				case Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0: // Tetris

						music.stop();
						musicStop = true;
							if(!music.openFromFile("res/music/Tetris/Tetris.ogg"))
							{
								//Menu_Music.ogg
								std::cout << "Error with Tetris Music" << std::endl;
							}
							music.play();

						system(tetris);
						std::cout << "Tetris button has been pressed" << std::endl;
						break;
					case 1: // RPG Game

						music.stop();
						musicStop = true;
							if(!music.openFromFile("res/music/TheRpg/MedievalRPGMusicGameMusic.ogg"))
							{
								//Menu_Music.ogg
								std::cout << "Error with Tetris Music" << std::endl;
							}
							music.play();

						system(Blaine);
						std::cout << "The RPG Game has been pressed" << std::endl;
						break;
					case 2: // Yumma Game

						music.stop();
						musicStop = true;
							if(!music.openFromFile("res/music/TheRpg/MedievalRPGMusicGameMusic.ogg"))
							{
								//Menu_Music.ogg
								std::cout << "Error with Tetris Music" << std::endl;
							}
							music.play();

						system(Yumma);
						std::cout << "Yumma Game has been pressed" << std::endl;
						break;						
					case 3: // Exit
						window.close();
						break;
					}

					break;
				}

				break;
			case Event::Closed:
				window.close();

				break;

			}
		}

		window.clear();
		window.draw(background);
		menu.draw(window);

		window.display();
	}
}