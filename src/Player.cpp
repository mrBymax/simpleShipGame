//
// Created by Federico Bertossi on 07/07/21.
//

#include "../header/Player.h"
#include <iostream>

Player::Player() {
    this->initVariables();
    this->initTexture();
    this->initSprite();
}


Player::~Player() {

}


void Player::update() {
    this->updateAttack();
}

void Player::render(sf::RenderTarget &target) {
    target.draw(this->sprite);
}

void Player::initTexture() {
// Load a texture from a file
    if (!this->texture.loadFromFile("../assets/textures/spriteBattleShip.png")) {
        std::cout << "ERROR:PLAYER:INITTEXTURES:Could not load texture files" << '\n';
    }
}

void Player::initSprite() {
    // Set a texture to a sprite
    this->sprite.setTexture(this->texture);

    // Resize
    this->sprite.scale(0.2f, 0.2f); // 140 x 100
}

void Player::move(const float dirX, const float dirY) {
    this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

const sf::Vector2f &Player::getPos() const {
    return this->sprite.getPosition();
}

void Player::updateAttack() {
    if (this->attackCooldown < this->attackCooldownMax) {
        this->attackCooldown += 0.5f;
    }
}

bool Player::canAttack() {
    if (this->attackCooldown >= this->attackCooldownMax) {
        this->attackCooldown = 0.f;
        return true;
    }
    return false;
}

void Player::initVariables() {
    this->movementSpeed = 1.f;

    this->attackCooldownMax = 10.f;
    this->attackCooldown = this->attackCooldownMax;
}

