#ifndef SCRIPTSYSTEM_H
#define SCRIPTSYSTEM_H

#include "ScriptComponent.h"

class ScriptSystem
{
    public:
        ScriptSystem()
        {
            RequireComponent<ScriptComponent>();
        }

        void Update()
        {
            for (auto entity: GetSystemEntities())
            {
                const auto script = entity.GetComponent<ScriptComponent>();
                script.func();
            }
        }
};


#endif