#pragma once

#include "Graphics.hpp"
#include "Pit.hpp"
#include "ResourceHolder.hpp"
#include "Templates.hpp"
#include "Pieces.hpp"
#include "Score.hpp" 
#include "Audio.hpp"

class Game : sf::NonCopyable {

public:
    Game(const std::string &resourcesPath);
    
    void handleEvent(const sf::Event &e);
    void update(const sf::Time &delta);
    void render(sf::RenderTarget &rt) const;
    bool isRunning() const noexcept;
    void resetGameState();

private:
    UPtr<Pit> mPit;
    UPtr<Piece> mNextPiece;
    UPtr<Piece> mCurrentPiece;
    UPtr<Score> mScore;
    UPtr<sf::Text> mGameOverText;
    UPtr<sf::Text> mFast1;
    UPtr<sf::Text> mFast2;

    TextureHolder mTextureHolder;
    FontHolder mFontHolder;

    bool mIsRunning;
    bool mIsGameOver;
    std::string mResourcesPath;
    std::string mImagesPath;
    std::string mFontsPath;



    void loadResources();
    void initGameState();
    void handleKeyEvent(const sf::Event &e);

    sf::SoundBuffer TetrisSoundBuffer;
    sf::Sound   TetrisSound;
    
};

