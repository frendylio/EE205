#pragma once


#include <array>
#include <map>
#include <ostream>
#include "ResourceHolder.hpp"
#include "Templates.hpp"
#include "Pit.hpp"
#include "Graphics.hpp"


////////////////////////////////////////////////////////////////
/////Declaring My Blocks Classes 
/////       EACH PIECES is inside a 4x4 block 
///////////////////////////////////////////////////////////////
class Block : public sf::Drawable {
public:
    // Each Block is made of Pixels like 20x20 (In the image folder they are 20x20 so I used that)
    Block(const sf::Texture &texture, const sf::Vector2f &pixelPosition, const PitCoordinates &coords);

    //newPos = NewPosition;  is in block coordinates, while offset uses pixel measurements
    void moveAbsolute(const PitCoordinates &newPos, const sf::Vector2f& offset);
    void moveDown();

    const sf::Vector2f& getPosition() const;
    const PitCoordinates& coordinates() const;
    PitCoordinates& coordinates();
    
    friend std::ostream& operator<<(std::ostream &os, const Block &block);


private:
    sf::Sprite mBlockSprite;
    PitCoordinates mCoordinates;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
////////////////////////////////////////////////////////////////
//END-------------
///////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////
///// Declaring My PIeces Classes 
///////////////////////////////////////////////////////////////
class Piece : public sf::Drawable{
public:
    const std::array<PitCoordinates, 4>& coordinatesOfAllBlocks() const;
    const std::array<Block, 4> blocks() const;

//Declare movements of pieces and rotation and see coordinates
    void rotateLeft();
    void rotateRight();
    void moveLeft();
    void moveRight();
    void moveDown();
    void moveToOffset(const sf::Vector2f& offset); //moves piece to a pixel position
    void moveToCoords(const PitCoordinates &coordsOfTopLeftBlock);

protected:
    Piece(const Array2D<PitCoordinates,4,4> &rotationPositions, const sf::Texture &blockTexture, const sf::Vector2f &pixelPosition);

private:
    int mCurrentRotation = 0;
    sf::Vector2f mOffset;
    Array2D<PitCoordinates,4,4> mRotatationPositions;
    std::array<Block,4> mBlocks;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
////////////////////////////////////////////////////////////////
/////END Declaring My PIeces Classes 
///////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
///// Declaring My PIeces/ Shapes classes that inheritance from Piece :# 
///////////////////////////////////////////////////////////////
class I : public Piece{
public:
    I(const TextureHolder &textures, const sf::Vector2f &pos);

};


class J : public Piece{
public:
    J(const TextureHolder &textures, const sf::Vector2f &pos);

};

class L : public Piece{
public:
    L(const TextureHolder &textures, const sf::Vector2f &pos);

};
class O : public Piece{
public:
    O(const TextureHolder &textures, const sf::Vector2f &pos);

};
class S : public Piece{
public:
    S(const TextureHolder &textures, const sf::Vector2f &pos);

};
class Z : public Piece{
public:
    Z(const TextureHolder &textures, const sf::Vector2f &pos);

};
class T : public Piece{
public:
    T(const TextureHolder &textures, const sf::Vector2f &pos);

};
////////////////////////////////////////////////////////////////
///// END OF Declaring My PIeces/ Shapes and give them colours/Texture 
///////////////////////////////////////////////////////////////


//Enums are lists of constants, so My PIecesTypes can only be I,J .... , T
enum class PieceTypes {
    I = 0,
    J,
    L,
    O,
    S,
    Z, 
    T
};

// Number of PIece I have
constexpr int NUM_PIECE_TYPES = 7;
