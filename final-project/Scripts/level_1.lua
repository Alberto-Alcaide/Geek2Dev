-- Crear un vector de bricks en Lua
local bricks = {
    { x = 90, y = 200, color = "blue" },
    { x = 200, y = 200, color = "blue" },
    { x = 310, y = 200, color = "blue" },
    { x = 420, y = 200, color = "blue" }
    -- Agregar más bricks según sea necesario
}

-- Pasar el vector de bricks a C++
createBricks(bricks)