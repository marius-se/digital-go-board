#include <iostream>

class Goban { };

// Renderer
class Renderer {
public:
    ~Renderer();
    virtual void render(const Goban& goban) const = 0;
};

class TerminalRenderer : public Renderer {
public:
    TerminalRenderer() {}
    ~TerminalRenderer() {}

    void render(const Goban& goban) const override {
        std::cout << "Printing current Goban";
    }
};

// GoGameManager
class GoGameManager {
public:
    GoGameManager() = default;
    GoGameManager(const Renderer& renderer) :renderer{}, goban{} {}

    bool makeMove(int x, int y) const {
        // move logic... then:
        renderer.render(goban);
        return true;
    }
private:
    Goban goban;
    Renderer renderer;
};

// Entry point - main
int main() {
    // if development {
        const TerminalRenderer &renderer{};
    // else {
        // const EPaperRenderer &renderer{};
    // }
    const GoGameManager goGameManager(renderer);

    goGameManager.makeMove(1,2);
}