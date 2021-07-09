//
// Created by Federico Bertossi on 07/07/21.
//

#include "../header/Game.h"
#include <iostream>

// Constructors
Game::Game() {
    this->initVariables();
    this->initWindow();
    this->initPlayer();
    this->initTextures();
    this->initEnemy();

}

// Destructors
Game::~Game() {
    delete this->window;
    delete this->player;
    delete this->enemy;

    // Delete textures
    for (auto &i : this->textures) {
        delete i.second;
    }

    // Delete bullets
    for (auto *i : this->bullets) {
        delete i;
    }

}

// Accessors
bool Game::running() {
    return this->window->isOpen();
}


// Functions
void Game::render() {
    this->window->clear(sf::Color(127, 205, 255));

    // Game Draw
    this->player->render(*this->window);
    this->enemy->render(*this->window);

    for (auto *bullet : this->bullets) {
        bullet->render(this->window);
    }

    this->window->display();
    this->enemy->render(*this->window);
}

void Game::update() {
    this->pollEvents();
    this->updateInput();
    this->updateBullets();
    this->player->update();
    this->enemy->update();
}


// Private functions

void Game::initVariables() {
    this->window = nullptr;
}

void Game::initWindow() {
    this->videoMode.height = 600; // 600
    this->videoMode.width = 800; // 800
    this->window = new sf::RenderWindow
            (this->videoMode, "Ship Game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);
}


void Game::pollEvents() {
// Event Polling
    while (this->window->pollEvent(this->event)) {
        switch (event.type) {
            case sf::Event::Closed :
                window->close();
                break;
//            case sf::Event::KeyPressed:: :
//                window->close();
        }
    }
}

void Game::initPlayer() {
    this->player = new Player();
}

void Game::initEnemy(){
    this->enemy = new Enemy();
}

void Game::updateInput() {
    // Move player
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->player->move(-1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->player->move(0.f, 1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->player->move(1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->player->move(0.f, -1.f);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack()) {
        this->bullets.push_back(
                new Bullet(this->textures["BULLET"], this->player->getPos().x + 90, this->player->getPos().y + 40s, 1.f, 0.f,
                           1.5f));
        std::cout << "Fire!\n";
    }
}

void Game::initTextures() {
    this->textures["BULLET"] = new sf::Texture();
    if (!this->textures["BULLET"]->loadFromFile("../assets/textures/bullet.png")) {
        std::cout << "ERROR:PLAYER:INITTEXTURES:Could not load texture files" << '\n';
    }
}

void Game::updateBullets() {
    unsigned counter = 0;
    for (auto *bullet : this->bullets) {
        bullet->update();

        if (bullet->getBounds().top + bullet->getBounds().height < 0.f) {
            // Delete bullet
            delete this->bullets.at(counter);
            this->bullets.erase(this->bullets.begin() + counter);
            --counter;
        }

        ++counter;
    }
}

