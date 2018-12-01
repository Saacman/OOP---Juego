#ifndef FRAMES_HPP
#define FRAMES_HPP

#include <vector>
// Clase encargada de administrar la información de los frames, obtenidos de las spritesheet
// Esta estructura guarda la información de 1 frame
struct FrameData {
    int id; // id de la textura
    int x; // Posición x del frame
    int y; // Posición y del frame
    int width; // Ancho del frame
    int height;// altura del frame
    float duration; // duración en pantalla
};

class Frames() {
public:
    Frames();

    void addFrame(int textureID, int x, int y, int width, int height, float duration);
    const FrameData* getCurrent() const;
    bool UpdateFrame(float dTime);
    void reset();

private:
    void incrementFrame();
    std::vector<FrameData> frames; // todos los frames guardados
    int currentIndex; // Frame actual
    float elapsedTime;

};
#endif
