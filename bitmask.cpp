#include "bitmask.hpp"

BitMask::BitMask() : m_bits(0) { }

// Metodos para obtener y modificar la mascara
// setMask es un constructor copia?
// void BitMask::setMask(BitMask& other) {
//     m_bits = other.GetMask();
// }
BitMask::BitMask(BitMask& other) {
    m_bits = other.GetMask();
}

uint32_t BitMask::getMask() const {
    return m_bits;
}

void BitMask::Clear() {
    m_bits = 0;
}

// Metodos para obtener y modificar bits especificos
bool BitMask::getBit(int index) const {
    return (m_bits & (1 << index)) != 0;
}

// coloca un 1 en la psoicion indicada
void BitMask::setBit(int index) {
    m_bits = m_bits | (1 << index);
}
void BitMask::setBit(int index, bool value) {
    // Se puede definir este metodo con dos metodos anteriores
    if (value) setBit(index);
    else clearBit(index);
}
void BitMask::clearBit(int index) {
    m_bits = m_bits & ~(1 << index);
}
