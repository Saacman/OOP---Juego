#ifndef RESOURCE_PATH_HPP
#define RESOURCE_PATH_HPP

#include <string>
class ResourcePath {
public:
    ResourcePath();

    inline const std::string& Get()
    {
        return path;
    }
    // inline const std::string& GetTextures()
    // {
    //     return "Resources/Textures/";
    // }
private:
    std::string path;
};

#endif
