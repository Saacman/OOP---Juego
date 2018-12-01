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
