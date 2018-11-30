#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <iostream>
#include <memory>
#include "window.hpp"

#include <vector>
#include "component.hpp"
#include "transform.hpp"

class Entity
{
public:
    Entity();

    void Awake();

    void Start();

    void Update(float deltaTime);
    void LateUpdate(float deltaTime);
    void Draw(Window& window);

    // Funcion plantilla.
    template <typename T> std::shared_ptr<T> AddComponent()
    {
        // Comprueba que solo se añadan clases derivadas de Component. Se comprueba en tiempo de ejecución.
        static_assert(std::is_base_of<Component, T>::value,"T se debe derivar de Component");
        // revisar si no tenemos algun componente de ese tipo
        for (auto& exisitingComponent : components) {
            // Evitar añadir el mismo componente deo veces
            if (std::dynamic_pointer_cast<T>(exisitingComponent))
            {
                return std::dynamic_pointer_cast<T>(exisitingComponent);
            }
        }
        // Lo añadimos
        std::shared_ptr<T> newComponent = std::make_shared<T>(this);
        components.push_back(newComponent);

        return newComponent;
    };

    template <typename T> std::shared_ptr<T> GetComponent()
    {
        for (auto& exisitingComponent : components)
        {
            if (std::dynamic_pointer_cast<T>(exisitingComponent))
            {
                return std::dynamic_pointer_cast<T>(exisitingComponent);
            }
        }

        return nullptr;
    };

    std::shared_ptr<Transform> transform;

private:
    std::vector<std::shared_ptr<Component>> components;
};

#endif
