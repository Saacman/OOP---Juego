#include "animation.hpp"
#include "entity.hpp"

// Constructor
Animation::Animation(Entity* owner) : Component(owner), currentFrames(Status::None, nullptr){ }

// Awake obtiene un puntero al componente sprite de nuestra entidad
void Animation::Awake(){
    sprite = owner->GetComponent<Sprite>();
}

// Update actualiza la animacion actual
void Animation::Update(float dTime){
    if(currentFrames.first != Status::None) {
        bool newFrame = currentFrames.second->UpdateFrame(dTime);

        if (newFrame) {
            const FrameData* data = currentFrames.second->getCurrent();
            sprite->Load(data->id);
            sprite->setTextureRect(data->x, data->y, data->width, data->height);
        }
    }
}

// AddAnimation inserta el par (estado y frames) a la coleccion
void Animation::AddFrames(Status status, std::shared_ptr<Frames> set) {
    //auto inserted = frames.insert(std::make_pair(status, set));
    frames.insert(std::make_pair(status, set));
    // Si no hay un set de frames asignado, pasamos al recien insertado
    if (currentFrames.first == Status::None) setStatus(status);
}

// Cambiar el set de frames
void Animation::setStatus(Status status) {
    // Solo lo cambiamos si no es nuestro set actual
    if (currentFrames.first == status) return;
    // Buscamos el set en la coleccion
    auto set = frames.find(status);
    // La asignamos al set actual
    if(set != frames.end()) {
        currentFrames.first = set->first;
        currentFrames.second = set->second;

        currentFrames.second->reset();
    }
}
// Retorna el estado actual
const Status& Animation::getStatus() const {
    return currentFrames.first;
}
