#include <iostream>
#include <array>

struct Coordinate { uint x; uint y; };
enum Stone { none, black, white };

class Goban {
public:
    Goban() {
        for (int i = 0; i < 19; ++i) {
            for (int j = 0; j < 19; ++j) {
                state[i][j] = none;
            }
        }
    }

    void setStone(const Coordinate targetCoordinate, const Stone stone) {
        state[targetCoordinate.y - 1][targetCoordinate.x - 1] = stone;
    }

    Stone getStone(const Coordinate coordinate) {
        return state[coordinate.y - 1][coordinate.x - 1];
    }

    auto getCurrentState() const {
        return state;
    }
private:
    std::array<std::array<Stone, 19>, 19> state;
};

// Renderer
struct Renderer { virtual void render(const Goban& goban) const = 0; };

struct TerminalRenderer : Renderer {
    void render(const Goban& goban) const override {
        const auto currentGobanState = goban.getCurrentState();
        std::cout << "###########" << std::endl;
        for (int i = 0; i < 19; ++i) {
            for (int j = 0; j < 19; ++j) {
                switch (currentGobanState[i][j]) {
                    case none:
                        std::cout << '0';
                        break;
                    case black:
                        std::cout << 'b';
                        break;
                    case white:
                        std::cout << 'w';
                        break;
                }
                std::cout << ' ';
            }
            std::cout << std::endl;
        }
        std::cout << "###########" << std::endl;
    }
};

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
    //goGameManager.makeMove({10,10}, black);
}