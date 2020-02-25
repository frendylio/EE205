#include "Score.hpp"

//Drawing Score 
Score::Score(const FontHolder &fontHolder, const sf::Vector2f& position) 
    :mText("0", fontHolder.get(FontID::GameFont))
{
    mText.setPosition(position);
}

//Getters
int Score::getValue() const {
    return mValue;
}

void Score::setValue(int value) {
    mValue = value;
    mText.setString(std::to_string(value));
}

void Score::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mText, states);
}
