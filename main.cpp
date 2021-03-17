#include "iostream"
#include "array"

#include "Renderer/Renderer.h"
#include "Renderer/TerminalRenderer.h"
//#include "Renderer/EPaperRenderer.h"
#include "Goban.h"

// GoGameManager
class GoGameManager {
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
private:
    Goban goban;
    Renderer* renderer;
};

// Entry point - main
int main() {
    TerminalRenderer renderer{};

    GoGameManager goGameManager(&renderer);

    goGameManager.start();
    goGameManager.makeMove({10,10}, black);
}