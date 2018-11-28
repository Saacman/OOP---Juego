#include "app.hpp"

int main() {
    App app;

    while (app.IsRunning()) {
        app.CaptureInput();
        app.Update();
        app.LateUpdate();
        app.Draw();
        app.GetdTime();
    }
    return 0;
}
// g++ -std=c++11 -o test main.cpp app.cpp window.cpp r_path.cpp input.cpp bitmask.cpp gamestate.cpp fsm.cpp splashscreen.cpp -lsfml-graphics -lsfml-window -lsfml-system
