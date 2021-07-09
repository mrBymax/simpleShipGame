//
// Created by Federico Bertossi on 07/07/21.
//

#ifndef GAME_H
#define GAME_H

#include <map>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
// Class that acts as game engine

class Game {
private:

    // Variables
    // Window
    sf::RenderWindow *window{};
    sf::VideoMode videoMode;
    sf::Event event{};

    // Resources
    std::map<std::string, sf::Texture *> textures;
    std::vector<Bullet *> bullets;

    // Player
    Player *player{};

    // Enemy
    Enemy *enemy{};

    // Private functions
    void initVariables();

    void initWindow();

    void initPlayer();

    void initTextures();

    void initEnemy();

public:

    // Constructors and Destructors
    Game();

    virtual ~Game();

    // Accessors
    bool running();

    // Functions
    void pollEvents();

    void update();

    void render();

    void updateInput();

    void updateBullets();
};


#endif //GAME_H
