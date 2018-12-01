#include "app.hpp"

int main() {
    //Crea el objeto "motor" para gestionar el juego
    App app;

    //Crea un ciclo con el cual se permitirá  llamar las funciones de app siempre y cuando este corriendo
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
// Comentario inofensivo
