#include "iostream"

#include "Renderer/Renderer.h"
#include "Renderer/EPaperRenderer.h"

#include "InputDevice.h"

#include "Goban.h"

// GoGameManager
class GoGameManager {
private:
    Goban goban;
    Renderer* renderer;
    Keyboard keyboardInput;

public:
    GoGameManager(Renderer* renderer) : renderer(renderer), goban{} {}

    void start() {
        renderer->render(goban);
    }

    bool makeMove(const Coordinate targetCoordinate, const Stone stone) {
        goban.setStone(targetCoordinate, stone);
        renderer->render(goban);
        return true;
    }

    void makeMove(const Stone stone) {
        Coordinate targetCoordinate;
        keyboardInput.waitForInput(targetCoordinate);
        if(targetCoordinate.isValid()) {
            goban.setStone(targetCoordinate, stone);
            renderer->render(goban);
        }
    }

};

// Entry point - main
int main() {
    EPaperRenderer renderer{1.48, 120};

    GoGameManager goGameManager(&renderer);

    goGameManager.start();
    goGameManager.makeMove(white);
    goGameManager.makeMove(black);
    goGameManager.makeMove(white);
    //goGameManager.makeMove({10,10}, black);
}
