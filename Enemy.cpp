//
// Created by Federico Bertossi on 08/07/21.
//

#include "header/Enemy.h"
#include <iostream>


Enemy::Enemy() {
    this->initTexture();
    this->initSprite();
    this->initVariables();
}

Enemy::~Enemy() {


}

// Functions
void Enemy::update() {
}

void Enemy::render(sf::RenderTarget &target) {
    target.draw(this->sprite);
}

void Enemy::initTexture() {
    if (!this->texture.loadFromFile("../assets/textures/isle.png")) { // TODO: insert the correct skin
        std::cout << "ERROR:PLAYER:INITTEXTURES:Could not load texture files" << '\n';
    }
}

void Enemy::initSprite() {
    // Set a texture to a sprite
    this->sprite.setTexture(this->texture);

    // Resize
    this->sprite.scale(0.5f, 0.5f); // 140 x 100
}

void Enemy::initVariables() {
    hp = 0;
    hpMax = 10;
    damage = 1;
}

