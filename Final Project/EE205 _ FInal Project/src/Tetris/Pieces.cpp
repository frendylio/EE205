#include "Pieces.hpp"
#include "Pit.hpp"
#include <iostream>



//Moving
static void moveBlocksToNewPositions(std::array<Block,4> &blocks, const std::array<PitCoordinates,4> &rotationPosition, const sf::Vector2f& offset){
    for(auto i = 0u; i < blocks.size(); i++) {
        const PitCoordinates& blockPosition = rotationPosition[i];
        blocks[i].moveAbsolute(blockPosition, offset);
    }
}

//Overloading operator , this is to get positions like (X,Y)
std::ostream& operator<<(std::ostream &os, const Block &block)
{
    return os << "X: " << block.getPosition().x << " Y: " << block.getPosition().y;
}

//For position
    Block::Block(const sf::Texture &texture, const sf::Vector2f &pixelPosition, const PitCoordinates &coords)
: mBlockSprite(texture), mCoordinates(coords)

{
    mBlockSprite.setPosition(sf::Vector2f(pixelPosition));
}

//moving
void Block::moveAbsolute(const PitCoordinates& newPos, const sf::Vector2f& offset ) {
    sf::Vector2f texSize(mBlockSprite.getTextureRect().width,
            mBlockSprite.getTextureRect().height);

    sf::Vector2f relativePos(newPos.column * texSize.x, newPos.row * texSize.y);
    mBlockSprite.setPosition(relativePos + offset);
    mCoordinates = newPos;
}

//Move down faster
void Block::moveDown() {
    mCoordinates.row++;
    const sf::Vector2f& currentPos = mBlockSprite.getPosition();

    mBlockSprite.setPosition(currentPos.x, currentPos.y + mBlockSprite.getTextureRect().height);
}

//draw blocks when moving
void Block::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mBlockSprite, states);
}

//GEt block position
const sf::Vector2f& Block::getPosition() const {
    return mBlockSprite.getPosition();
}

//get block (X,Y) -- I am not really sure why we need const and not const function; but tutorial made it like that so ... I just did it too :(
    //const functions is not allow them to modify the object on which they are called
    const PitCoordinates& Block::coordinates() const {
        return mCoordinates;
    }

    //Non-const functions can only be called by non-const objects.
    PitCoordinates& Block::coordinates() {
        return mCoordinates;
    }


//------------------------//
//piece methods
//------------------------//
//Rotate pieces
Piece::Piece(const Array2D<PitCoordinates,4,4> &rotationPositions, const sf::Texture &blockTexture, const sf::Vector2f &offsetPosition)
    :mOffset(offsetPosition), mRotatationPositions(rotationPositions),
    mBlocks{{
        Block(blockTexture, offsetPosition +
                sf::Vector2f(rotationPositions[0][0].column * blockTexture.getSize().x, rotationPositions[0][0].row * blockTexture.getSize().y), rotationPositions[0][0]),
        Block(blockTexture, offsetPosition +
                sf::Vector2f(rotationPositions[0][1].column * blockTexture.getSize().x, rotationPositions[0][1].row * blockTexture.getSize().y), rotationPositions[0][1]),
        Block(blockTexture, offsetPosition +
                sf::Vector2f(rotationPositions[0][2].column * blockTexture.getSize().x, rotationPositions[0][2].row * blockTexture.getSize().y), rotationPositions[0][2]),
        Block(blockTexture, offsetPosition +
                sf::Vector2f(rotationPositions[0][3].column * blockTexture.getSize().x, rotationPositions[0][3].row * blockTexture.getSize().y), rotationPositions[0][3]),
    }}

{}

//Rotate piece to Left
void Piece::rotateLeft() {
    mCurrentRotation++;
    mCurrentRotation %= mRotatationPositions.size();
    moveBlocksToNewPositions(mBlocks, mRotatationPositions[mCurrentRotation], mOffset);
}

//move peice to left
void Piece::moveLeft() {

    for(auto& blockPositions : mRotatationPositions) {
        for(auto& blockPosition : blockPositions) {
            blockPosition.column--;
        }
    }
    moveBlocksToNewPositions(mBlocks, mRotatationPositions[mCurrentRotation], mOffset);
}

//Move right
void Piece::moveRight() {

    for(auto& blockPositions : mRotatationPositions) {
        for(auto& blockPosition : blockPositions) {
            blockPosition.column++;
        }
    }

    moveBlocksToNewPositions(mBlocks, mRotatationPositions[mCurrentRotation], mOffset);
}

//Move faster  aka Press down
void Piece::moveDown() {
    for(auto& blockPositions : mRotatationPositions) {
        for(auto& blockPosition : blockPositions) {
            blockPosition.row++;
        }
    }
    moveBlocksToNewPositions(mBlocks, mRotatationPositions[mCurrentRotation], mOffset);
}

//move offset
void Piece::moveToOffset(const sf::Vector2f& offset) {
    mOffset = offset;

    moveBlocksToNewPositions(mBlocks, mRotatationPositions[mCurrentRotation], mOffset);
}


const std::array<Block, 4> Piece::blocks() const {
    return mBlocks;
}

// Move My 4x4 block
void Piece::moveToCoords(const PitCoordinates &coordsOfTopLeftBlock) {
    PitCoordinates coordOffset;
    coordOffset.column = coordsOfTopLeftBlock.column - mRotatationPositions[mCurrentRotation][0].column;
    coordOffset.row = coordsOfTopLeftBlock.row - mRotatationPositions[mCurrentRotation][0].row;


    for (auto& rotation : mRotatationPositions) {
        for (auto& coords : rotation) {
            coords.column += coordOffset.column;
            coords.row += coordOffset.row;
        }
    }

    moveBlocksToNewPositions(mBlocks, mRotatationPositions[mCurrentRotation], mOffset);


}
const std::array<PitCoordinates, 4>& Piece::coordinatesOfAllBlocks() const {
    return mRotatationPositions[mCurrentRotation];
}

void Piece::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(auto &block : mBlocks){
        target.draw(block, states);
    }
}

////////////////////
//-So Imagine that each pieces is on a 4 x 4 square Starting from -1 to 2 
// x x x x   
// x x x x
// x x x x
// x x x x
// I made an array to check all the possible position that my Pieces/Shapes can go inside my 4x4 square
// It mades sense if you see drawings that I made ...
// Like I move my Pieces by 4 x 4 square and the Pieces can rotate inside the 4x4 square
/////////////////////

//PIECE 
// X
// X
// X
// X
I::I(const TextureHolder &textures, const sf::Vector2f &pos)
    :Piece({{
            {{{0,0},{0,1},{0,2},{0,3}}},
            {{{1,1},{0,1},{-1,1},{-2,1}}},
            {{{0,2},{0,1},{0,0},{0,-1}}},
            {{{-1,1},{0,1},{1,1},{2,1}}},
            }},
            textures.get(TextureID::I), pos)
{}

//PIECE 
//  X
//  X
// XX
//
J::J(const TextureHolder &textures, const sf::Vector2f &pos)
    :Piece({{
            {{{1,0},{1,1},{1,2},{0,2}}},
            {{{2,1},{1,1},{0,1},{0,0}}},
            {{{1,2},{1,1},{1,0},{2,0}}},
            {{{0,1},{1,1},{2,1},{2,2}}},
            }},
            textures.get(TextureID::J), pos)
{}

//PIECE 
// 
// XX
// XX
//
O::O(const TextureHolder &textures, const sf::Vector2f &pos)
    :Piece({{
            {{{0,0},{1,0},{0,1},{1,1}}},
            {{{0,0},{1,0},{0,1},{1,1}}},
            {{{0,0},{1,0},{0,1},{1,1}}},
            {{{0,0},{1,0},{0,1},{1,1}}},
            }},
            textures.get(TextureID::O), pos)
{}

//PIECE 
// | 
// | 
// |_
//
L::L(const TextureHolder &textures, const sf::Vector2f &pos)
    :Piece({{
            {{{0,0},{0,1},{0,2},{1,2}}},
            {{{-1,1},{0,1},{1,1},{-1,2}}},
            {{{0,0},{0,1},{0,2},{-1,0}}},
            {{{-1,1},{0,1},{1,1},{1,0}}},
            }},
            textures.get(TextureID::L), pos)
{}

//PIECE 
// __ 
//   |__
//
//

Z::Z(const TextureHolder &textures, const sf::Vector2f &pos)
    :Piece({{
            {{{0,0},{1,0},{1,1},{2,1}}},
            {{{1,-1},{1,0},{0,0},{0,1}}},
            {{{0,-1},{1,-1},{1,0},{2,0}}},
            {{{1,1},{1,0},{2,0},{2,-1}}},
            }},
            textures.get(TextureID::Z), pos)
{}

//PIECE 
//    __
// __|
//
//

S::S(const TextureHolder &textures, const sf::Vector2f &pos)
    :Piece({{
            {{{2,0},{1,0},{1,1},{0,1}}},
            {{{1,1},{1,0},{0,0},{0,-1}}},
            {{{2,-1},{1,-1},{1,0},{0,0}}},
            {{{2,1},{2,0},{1,0},{1,-1}}},
            }},
            textures.get(TextureID::S), pos)
{}

//Piece
//     ____
//      |
//      |
T::T(const TextureHolder &textures, const sf::Vector2f &pos)
    :Piece({{
            {{{0,0},{1,0},{2,0},{1,1}}},
            {{{1,-1},{1,0},{1,1},{0,0}}},
            {{{0,0},{1,0},{2,0},{1,-1}}},
            {{{1,1},{1,0},{1,-1},{2,0}}},
            }},
            textures.get(TextureID::T), pos)
{}



