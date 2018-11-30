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
// TODO: MakeFile
// g++ -std=c++14 -o test2 main.cpp app.cpp window.cpp r_path.cpp input.cpp bitmask.cpp gamestate.cpp fsm.cpp splashscreen.cpp playercontrol.cpp sprite.cpp entity.cpp transform.cpp -lsfml-graphics -lsfml-window -lsfml-system
