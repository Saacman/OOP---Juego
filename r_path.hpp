#ifndef RESOURCE_PATH_HPP
#define RESOURCE_PATH_HPP

#include <string>
class ResourcePath {
public:
    ResourcePath();

    inline const std::string& Get() // 1
    {
        return path;
    }
private:
    std::string path;
};

#endif
