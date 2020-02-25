//I DO NOT RECOMEND COMPILING IT, JUST RUN THE EXECUTABLES 

//PLEASE USE VISUAL CODE, not sure if you can use wiliki...

//Made By Frendy, Blaine, Yuma, Issac

//Each Person had a main priority of a section of this game.
//This does not means that everyone just did their own thing; everyone contributed to each other section in a way or another.
//For Example, giving feedback to each other or suggesting other ways to write the code.

How to Compile:
1- Have SFML INSTALL, the location must be in drive C:
2- Under .vscode, go to tasks.json
3- Inside the task.json go to the args section and Comment/Uncomment the cpp files and the name of the executable for each section of this game:
    Example: Since I want to compile Tetris, I uncommented the Tetris section and the Tetris name.
            "args": [
                "-g",
            //Blaine
               // "Blaine_Rpg.cpp",
               // "src/Blaine_RPG/collision.hpp",
               // "src/Blaine_RPG/attacks.hpp",
               // "src/Blaine_RPG/game.hpp",

            //Key Gen 
               // "keygen.cpp",
               // "src/KeyGen/checker.hpp",

            // Yumma
               // "YummaMain.cpp",

// Uncomment this
            //Tetris
                "TetrisMain.cpp",
                "src/Tetris/Game.cpp",
                "src/Tetris/KeyBuffer.cpp",
                "src/Tetris/Pieces.cpp",
                "src/Tetris/Pit.cpp",
               "src/Tetris/Score.cpp",

            //Menu
              //  "MainMenu.cpp",
              //  "src/Menu/Menu.cpp",
                //Include
                "-I${workspaceFolder}/**",
                "-IC:/SFML-2.5.1/include",
                "-IC:/SFML-2.5.1/include/SFML",
                //Load
                "-LC:/SFML-2.5.1/lib",
                "-LC:/SFML-2.5.1/lib/cmake/SFML",
                // For Grpahs
                "-lsfml-graphics",
                "-lsfml-window",
                "-lsfml-system",
                // FOr Menu
                "-lsfml-Audio",
                "-o",
               // "KeyGen2"
//Uncomment this
                "Tetris"
                
                //"Menu"
                //"Yumma"
            ]