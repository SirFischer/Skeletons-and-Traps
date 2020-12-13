#pragma once

#include <string>
#include <map>

template <typename Resource, typename Identifier>

class ResourceHolder
{
private:
    std::map<Identifier, std::unique_ptr<assets>> mResourceMap;
public:

    void        load(Identifier id, const std::string& filename);

    Resource&   get(Identifier id);
    const Resource&   get(Identifier id) const;
};
