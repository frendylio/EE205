#include <stdexcept>
#include <iostream>
#include <assert.h>
#include "Game.hpp"
#include "Templates.hpp"
#include "Pieces.hpp"
#include "KeyBuffer.hpp"
#include "Audio.hpp"
#include "Sound.hpp"


// Here are my Global Variables That I used
// Instead of just writing it on my code
// I set it here so is more easy to change it if I screw up
using namespace sf;
float PIECE_MOVE_TIME = .5; // How fast my Pieces moves in seconds
static constexpr float PIT_WALL_WIDTH = 5; //how many pixels is the wall of the pit? -- Check my Images folders to see how width
static const sf::Vector2f PIT_OFFSET = sf::Vector2f(275, 45); // OFFSET of my pit

// Currently, I always have the same set of pieces, Perhaps I can use Random funciton to see with pieces goes first??
static const sf::Vector2f PIECE_SPAWN_OFFSET = {PIT_OFFSET.x + PIT_WALL_WIDTH, PIT_OFFSET.y + PIT_WALL_WIDTH}; // Where does my pieces spawn
static const PitCoordinates PIECE_SPAWN_COORDINATES = {4,0};
static const sf::Vector2f NEXT_PIECE_OFFSET = {PIT_OFFSET.x - 100, PIT_OFFSET.y};
static const sf::Vector2f SCORE_POSITION = {NEXT_PIECE_OFFSET.x, NEXT_PIECE_OFFSET.y + 100};

static bool isPieceStopped = false;

//prototypes for helper functions
static UPtr<Piece> generateNextPiece(const TextureHolder&);
static bool canPieceMoveDown(const Piece &piece, const Pit &pit);
static bool canPieceMoveLeft(const Piece &piece, const Pit &pit);
static bool canPieceMoveRight(const Piece &piece, const Pit &pit);
static bool canPieceRotateLeft(const Piece &piece, const Pit &pit);
static void dropPiece(Piece& piece, const Pit& pit);
static bool shouldGameEnd(const Piece& piece, const Pit& pit);

//Fonts And Images Global Variables and SOunds and Stuff
char TetrisClearSound[] = "res/music/Tetris/TetrisClear.ogg";
char PitImage[] = "res/images/Tetris/Pit.png";
char IImage[] = "res/images/Tetris/I.png";
char JImage[] = "res/images/Tetris/J.png";
char LImage[] = "res/images/Tetris/L.png";
char OImage[] = "res/images/Tetris/O.png";
char SImage[] = "res/images/Tetris/S.png";
char ZImage[] = "res/images/Tetris/Z.png";
char TImage[] = "res/images/Tetris/T.png";
char FontTetris[] = "res/fonts/Tetris/crackman.ttf";

int GoFast;

Game::Game(const std::string &resourcesPath) {

    loadResources();
    initGameState();
}

void Game::initGameState() {
    mPit = makeUPtr<Pit>(mTextureHolder.get(TextureID::Pit), PIT_OFFSET);

    auto pitBounds = mPit->boundingRect();
    mScore = makeUPtr<Score>(mFontHolder, sf::Vector2f(pitBounds.left + pitBounds.width + 100, NEXT_PIECE_OFFSET.y));

    mGameOverText = makeUPtr<sf::Text>("\t\t\tGame Over!\n        Want to Play Again?", mFontHolder.get(FontID::GameFont));
    
    mGameOverText->setPosition(110,500);
// maybe put sound too faster?
    mFast1 = makeUPtr<sf::Text>("\t\t\tLETS MAKE IT FASTER!", mFontHolder.get(FontID::GameFont));
    mFast1->setPosition(55,0);

    mFast2 = makeUPtr<sf::Text>("\t\t\tWOW CAN YOU SURVIVE THIS?!", mFontHolder.get(FontID::GameFont));
    mFast2->setPosition(0,0);

    mNextPiece = generateNextPiece(mTextureHolder);
    mCurrentPiece = makeUPtr<I>(mTextureHolder, PIECE_SPAWN_OFFSET);
    mCurrentPiece->moveToCoords(PIECE_SPAWN_COORDINATES);

    if( !TetrisSoundBuffer.loadFromFile(TetrisClearSound))
    {
        std::cout << "Error on Tetris loading Cleaner Sound Effect" << std::endl;
    }

    TetrisSound.setBuffer(TetrisSoundBuffer);

}

//Loading My Textures and Fonts 
void Game::loadResources() {
    mTextureHolder.load(TextureID::Pit, PitImage);
    mTextureHolder.load(TextureID::I, IImage);
    mTextureHolder.load(TextureID::J, JImage);
    mTextureHolder.load(TextureID::L, LImage);
    mTextureHolder.load(TextureID::O, OImage);
    mTextureHolder.load(TextureID::S, SImage);
    mTextureHolder.load(TextureID::Z, ZImage);
    mTextureHolder.load(TextureID::T, TImage);

    mFontHolder.load(FontID::GameFont, FontTetris);
}

//PIece moving fast
static bool canPieceMoveDown(const Piece &piece, const Pit &pit) {
    Piece tmpPiece = piece;
    tmpPiece.moveDown();

    for (auto& coords : tmpPiece.coordinatesOfAllBlocks()) {
        if (!pit.isBlockInBounds(coords) || pit.isBlockAtCoordinates(coords)) {
            return false;
        }
    }

    return true;
}

// MOve LEFT
static bool canPieceMoveLeft(const Piece &piece, const Pit &pit) {
    Piece tmpPiece = piece;
    tmpPiece.moveLeft();

    for (auto& coords : tmpPiece.coordinatesOfAllBlocks()) {
        if (!pit.isBlockInBounds(coords) || pit.isBlockAtCoordinates(coords)) {
            return false;
        }
    }
    return true;
}

// MOve Right
static bool canPieceMoveRight(const Piece &piece, const Pit &pit) {
    Piece tmpPiece = piece;
    tmpPiece.moveRight();

    for (auto& coords : tmpPiece.coordinatesOfAllBlocks()) {
        if (!pit.isBlockInBounds(coords) || pit.isBlockAtCoordinates(coords)) {
            return false;
        }
    }

    return true;
}

//Rotate Left
static bool canPieceRotateLeft(const Piece &piece, const Pit &pit) {
    Piece tmpPiece = piece;
    tmpPiece.rotateLeft();

    for (auto& coords : tmpPiece.coordinatesOfAllBlocks()) {
        if (!pit.isBlockInBounds(coords) || pit.isBlockAtCoordinates(coords)) {
            return false;
        }
    }

    return true;
}

// Space Drown down
static void dropPiece(Piece& piece, const Pit& pit) {
    while (canPieceMoveDown(piece, pit)) {
        piece.moveDown();
    }

    isPieceStopped = true;
}

void Game::resetGameState() {
    initGameState();
}

// What Key is what 
// IN the future maybe connect it to the Option Menu
// SO User can customize it?
// Also, I wanted to do a Hold Key but I google it and looks a lot of work to implement
// Like need to storage it and count for a lot of things
// So for now no Pieces Hold Key
void Game::handleKeyEvent(const sf::Event &e) {
    KeyBuffer::processEvent(e);

    if (KeyBuffer::hasKeys()) {
        if (!mIsGameOver) {
            switch(KeyBuffer::popKey()) {
            case sf::Keyboard::Left:
                if (canPieceMoveLeft(*mCurrentPiece, *mPit)) mCurrentPiece->moveLeft();
                break;
            case sf::Keyboard::Right:
                if (canPieceMoveRight(*mCurrentPiece, *mPit)) mCurrentPiece->moveRight();
                break;
            case sf::Keyboard::Down:
                if (canPieceMoveDown(*mCurrentPiece, *mPit)) mCurrentPiece->moveDown();
                break;
            case sf::Keyboard::Space:
                dropPiece(*mCurrentPiece, *mPit);
                break;
            case sf::Keyboard::Up:
                if (canPieceRotateLeft(*mCurrentPiece, *mPit)) mCurrentPiece->rotateLeft();
                break;
            case sf::Keyboard::Escape:
                mIsRunning = false;
                break;
            default:
                break;

            }
        }
        else {
            switch(KeyBuffer::popKey()) {
            case sf::Keyboard::Return:
                mIsGameOver = false;
                initGameState();
                break;
            default:
                break;
            }
        }
    }

}

bool Game::isRunning() const noexcept {
    return mIsRunning;
}



void Game::handleEvent(const sf::Event &e) {
    switch (e.type) {
    case sf::Event::Closed:
        mIsRunning = false;
        break;
    case sf::Event::KeyPressed:
    case sf::Event::KeyReleased:
        handleKeyEvent(e);
    default:
        break;

    }


}

// If pieces at top, then you loose/ end game If not continue playing
static bool shouldGameEnd(const Piece& piece, const Pit& pit) {
    for (auto& block : piece.blocks()) {
        if (pit.isBlockAtCoordinates(block.coordinates())) {
            return false;
        }
    }

    return true;
}


// Now is defualted for same order of pieces IDK why
// Will fix in the future
static UPtr<Piece> generateNextPiece(const TextureHolder &textureHolder) {
    PieceTypes chosenPiece = static_cast<PieceTypes>(rand() % NUM_PIECE_TYPES);

    switch(chosenPiece) {
    case PieceTypes::I:
        return makeUPtr<I>(textureHolder, NEXT_PIECE_OFFSET);
        break;
    case PieceTypes::O:
        return makeUPtr<O>(textureHolder, NEXT_PIECE_OFFSET);
        break;
    case PieceTypes::J:
        return makeUPtr<J>(textureHolder, NEXT_PIECE_OFFSET);
        break;
    case PieceTypes::L:
        return makeUPtr<L>(textureHolder, NEXT_PIECE_OFFSET);
        break;
    case PieceTypes::Z:
        return makeUPtr<Z>(textureHolder, NEXT_PIECE_OFFSET);
        break;
    case PieceTypes::S:
        return makeUPtr<S>(textureHolder, NEXT_PIECE_OFFSET);
        break;
    case PieceTypes::T:
        return makeUPtr<T>(textureHolder, NEXT_PIECE_OFFSET);
        break;
    default:
        assert("This should be unreachable.");
        return nullptr;

    }
}



void Game::update(const sf::Time &delta) {
    static float secondsSinceLastPieceMove = 0;
    secondsSinceLastPieceMove += delta.asSeconds();

    if(!mIsGameOver) {
        //timer is up, or we are waiting for a new block
        if (secondsSinceLastPieceMove > PIECE_MOVE_TIME || isPieceStopped) {
            secondsSinceLastPieceMove = 0;

            if (!isPieceStopped && canPieceMoveDown(*mCurrentPiece, *mPit)) {
                mCurrentPiece->moveDown();
            }
            else { //cannot move down anymore.
                isPieceStopped = false;

                //1. add blocks to pit
                for (auto& block : mCurrentPiece->blocks()) {
                    mPit->putBlock(block);
                }


                int scoreToAdd = 0;

                //2. if there are full lines, we want to delete them and add to score
                switch(mPit->deleteFullRows()){

                //delete row

                case 1:
                    TetrisSound.play();
                    scoreToAdd = 40;
                    break;
                case 2:
                    TetrisSound.play();
                    scoreToAdd = 100;
                    break;
                case 3:
                    TetrisSound.play();
                    scoreToAdd = 300;
                    break;
                case 4:
                    TetrisSound.play();
                    scoreToAdd = 1200;
                    break;

                }

                mScore->setValue(mScore->getValue() + scoreToAdd);
                GoFast = mScore->getValue();
                if (GoFast >= 100){
                   PIECE_MOVE_TIME = .1;
                }

                if (GoFast >= 200){
                   PIECE_MOVE_TIME = .05;
                }

                //3. if there is room, spawn new piece, else lose

                mCurrentPiece = std::move(mNextPiece);
                mCurrentPiece->moveToOffset(PIECE_SPAWN_OFFSET);
                mCurrentPiece->moveToCoords(PIECE_SPAWN_COORDINATES);
                mNextPiece = generateNextPiece(mTextureHolder);

                if (!shouldGameEnd(*mCurrentPiece, *mPit)) {
                    mIsGameOver = true;

                }

            }

        }
    }

}

void Game::render(sf::RenderTarget &rt) const {
    rt.clear(sf::Color(34,34,34));
    rt.draw(*mPit);
    rt.draw(*mScore);
    rt.draw(*mNextPiece);
    rt.draw(*mCurrentPiece);

    if (GoFast >= 100){
            rt.draw(*mFast1);
        }

    if (GoFast >= 200){
            rt.clear(sf::Color(34,34,34));
            rt.draw(*mPit);
            rt.draw(*mScore);
            rt.draw(*mNextPiece);
            rt.draw(*mCurrentPiece);
            rt.draw(*mFast2);
        }
    

    if (mIsGameOver) {
        rt.draw(*mGameOverText);
    }
    
}

