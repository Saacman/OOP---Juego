#include "input.hpp"

void Input::Update() {
    m_lastKeys.setMask(m_keys);
    m_keys.setBit((int)Key::Left)
}
