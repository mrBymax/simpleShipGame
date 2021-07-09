//
// Created by Federico Bertossi on 07/07/21.
//

#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Bullet {
private:
    sf::Sprite shape;

    sf::Vector2f direction;
    float movementSpeed;

public:
    Bullet(sf::Texture *texture, float posX, float posY, float dirX, float dirY, float movementSpeed);
    Bullet();

    virtual ~Bullet();

    // Accessories
    sf::FloatRect getBounds() const;

    void update();

    void render(sf::RenderTarget *target);

};


#endif // BULLET_H
