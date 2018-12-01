#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "component.hpp"
#include "frames.hpp"
#include "sprite.hpp"
// Componente de animación
enum class Status{None, Still, Walk};
class Animation : public Component {
public:
    Animation(Entity* owner);
    void Awake() override;
    void Update(float dTime) override;
    void AddFrames(Status status, std::shared_ptr<Frames> set);
    void setStatus(Status status);
    const Status& getStatus() const;
private:
    // Puntero al componente de sprite
    std::shared_ptr<Sprite> sprite;
    // Animaciones guardadas
    std::map<Status, std::shared_ptr<Frames>> frames;
    // Animacion actual
    std::pair<Status, std::shared_ptr<Frames>> currentFrames;

};
#endif
