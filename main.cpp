#include "app.hpp"

int main() {
    App app;

    while (app.IsRunning()) {
        app.captureInput();
        app.Update();
        app.LateUpdate();
        app.Draw();
        app. getdTime();
    }
    return 0;
}
