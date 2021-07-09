//
// Created by Federico Bertossi on 08/07/21.
//

#ifndef ENEMY_H
#define ENEMY_H


#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Enemy {
private:
    sf::Sprite sprite;
    sf::Texture texture;

    int hp{};
    int hpMax{};
    int damage{};

    void initSprite();

    void initTexture();
    void initVariables();

public:
    Enemy();

    virtual ~Enemy();

    // Functions
    void update();
    void render(sf::RenderTarget &target);
};


#endif // ENEMY_H
