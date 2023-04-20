#ifndef SYSTEM_H
#define SYSTEM_H



class System
{
    public:
        GetSystemEntities()
        {
            
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