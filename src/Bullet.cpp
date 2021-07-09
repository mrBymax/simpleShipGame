//
// Created by Federico Bertossi on 07/07/21.
//

#include "../header/Bullet.h"

Bullet::Bullet(sf::Texture *texture, float posX, float posY, float dirX, float dirY, float movementSpeed) {
    this->shape.setTexture(*texture);
    this->shape.setPosition(posX, posY);

    this->direction.x = dirX;
    this->direction.y = dirY;
    this->movementSpeed = movementSpeed;
}

Bullet::~Bullet() {

}

void Bullet::update() {
    // Movement update
    this->shape.move(this->movementSpeed * this->direction);
}

void Bullet::render(sf::RenderTarget *target) {
    target->draw(this->shape);
}

Bullet::Bullet() { // Default constructor

}

sf::FloatRect Bullet::getBounds() const {
    return this->shape.getGlobalBounds();
}



