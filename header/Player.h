//
// Created by Federico Bertossi on 07/07/21.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Player {
private:
    sf::Sprite sprite;
    sf::Texture texture;

    float movementSpeed{};

    float attackCooldown{};
    float attackCooldownMax{};

    // Private functions
    void initVariables();
    void initTexture();

    void initSprite();

public:
    Player();

    virtual ~Player();

    // Accessor
    const sf::Vector2f &getPos() const;

    // Functions
    void move(const float dirX, const float dirY);

    bool canAttack();

    void updateAttack();

    void update();

    void render(sf::RenderTarget &target);


};


#endif //HELLOSFML_PLAYER_H
