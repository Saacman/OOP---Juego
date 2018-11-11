#ifndef STATE_HPP
#define STATE_HPP

#include "window.hpp"

class State {
public:
    virtual void init() = 0;
    virtual void terminate() = 0;
    virtual void activate() {}
    virtual void deactivate() {}

    virtual void ProcessInput() {}
    virtual void Update( float dTime) {}
    virtual void LateUpdate(float dTime) {}
    virtual void Draw(Window& window) {}
    
};

#endif
