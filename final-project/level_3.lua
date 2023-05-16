-- Crear un vector de bricks en Lua
local bricks = {
    { x = 90, y = 200 },
    { x = 200, y = 200 },
    { x = 310, y = 200 },
    { x = 420, y = 200 },
    { x = 420, y = 200 },
    { x = 90, y = 255 },
    { x = 200, y = 255 },
    { x = 310, y = 255 },
    { x = 420, y = 255 },
    { x = 90, y = 255 },
    { x = 200, y = 310 },
    { x = 310, y = 310 },
    { x = 420, y = 310 }
    -- Agregar más bricks según sea necesario
}

-- Pasar el vector de bricks a C++
createBricks(bricks)