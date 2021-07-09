#include "../header/Game.h"

int main() {

    // Init Game Engine
    Game game;

    // Game Loop
    while (game.running()) {
        // Update
        game.update();

        // Render
        game.render();

    }

    // End of the application
    return 0;
}