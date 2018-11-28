#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "window.hpp"
// Forward declaration. El compilador aún no tiene la definición
class Object;
// Clase base de todos los componentes
class Component {
public:
    Component(Object* owner) : owner(owner){}

    virtual void Awake() {};
    virtual void Start() {};

    virtual void Update(float deltaTime) {};
    virtual void LateUpdate(float deltaTime) {};
    virtual void Draw(Window& window) {};

protected:
    Object* owner;
};

#endif
