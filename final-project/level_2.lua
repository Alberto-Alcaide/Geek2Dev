-- Crear un vector de bricks en Lua
local bricks = {
    { x = 90, y = 200, color = "red" },
    { x = 200, y = 200, color = "red" },
    { x = 310, y = 200, color = "red" },
    { x = 420, y = 200, color = "red" },
    { x = 90, y = 310, color = "red" },
    { x = 200, y = 310, color = "red" },
    { x = 310, y = 310, color = "red" },
    { x = 420, y = 310, color = "red" }
    -- Agregar más bricks según sea necesario
}

-- Pasar el vector de bricks a C++
createBricks(bricks)