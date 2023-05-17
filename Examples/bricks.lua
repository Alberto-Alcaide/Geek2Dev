-- Crear un vector de bricks en Lua
local bricks = {
    { x = 100, y = 200 },
    { x = 150, y = 300 }
    -- Agregar más bricks según sea necesario
}

-- Pasar el vector de bricks a C++
createBricks(bricks)