#pragma once

#include <string>
#include <map>
#include "Graphics.hpp"

// This is for fonts, images and stuff
template <typename Identifier, typename Resource>
class ResourceHolder {
public:

    template <typename... Args>
    void load(Identifier id, const std::string &filename, Args... args);

    const Resource &get(Identifier id) const;

private:
    std::map<Identifier, Resource> mResourceMap;
};


enum class TextureID{
    Pit,
    I,
    J,
    L,
    O,
    S,
    T,
    Z,
    Background
};

enum class FontID {
    GameFont
};


typedef ResourceHolder<TextureID, sf::Texture> TextureHolder;
typedef ResourceHolder<FontID, sf::Font> FontHolder;

#include "ResourceHolder.inl"


