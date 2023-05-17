-- Crear un vector de bricks en Lua
local bricks = {
    { x = 90, y = 150, color="green" },
    { x = 200, y = 150, color="green" },
    { x = 310, y = 150, color="green" },
    { x = 420, y = 150, color="green" },
    { x = 90, y = 205, color="green" },
    { x = 200, y = 205, color="green" },
    { x = 310, y = 205, color="green" },
    { x = 420, y = 205, color="green" },
    { x = 90, y = 255, color="green" },
    { x = 200, y = 255, color="green" },
    { x = 310, y = 255, color="green" },
    { x = 420, y = 255, color="green" }
    -- Agregar más bricks según sea necesario
}

-- Pasar el vector de bricks a C++
createBricks(bricks)