#ifndef NAMEDGROUPCOMPONENT_H
#define NAMEDGROUPCOMPONENT_H

#include <iostream>

struct NameGroupComponent
{
    std::string name;
    std::string group;

    NameGroupComponent(std::string name = "", std::string group = "") : name(name), group(group) {} 
};



#endif