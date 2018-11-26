#include "fsm.hpp"
// Constructor por defecto
FSM::FSM() : m_states(0), currentState(0) { }

void FSM::ProcessInput() {
    if(currentState) {
        currentState->ProcessInput();
    }
}
void FSM::Update( float dTime) {
    if(currentState) {
        currentState->Update(dTime);
    }
}
void FSM::LateUpdate(float dTime) {
    if(currentState) {
        currentState->LateUpdate(dTime);
    }
}
void FSM::Draw(Window& window) {
    if(currentState) {
        currentState->Draw(window);
    }
}

// Añadir estados a la FSM, retorna su id
unsigned int FSM::Add(std::shared_ptr<State> state) {
    auto inserted = m_states.insert(std::make_pair(insertedStateID, state));
    // Revisar acceso
    //inserted.second->init();
    inserted.first->second->init();
    return insertedStateID++;
}

// Cambiar al estado dado el id
void FSM::SwitchTo(unsigned int id) {
    auto hold = m_states.find(id);
    if(hold != m_states.end()) {

        if(currentState) currentState->deactivate();

        currentState = hold->second;

        currentState->activate();
    }
}

// Remover estado de la FSM
void FSM::Remove(unsigned int id) {
    auto hold = m_states.find(id);
    if(hold != m_states.end()) {

        if(currentState == hold->second) currentState = nullptr;

        hold -> second -> terminate();

        currentState->activate();
        m_states.erase(hold);
    }
}
