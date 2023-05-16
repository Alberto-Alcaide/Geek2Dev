-- Crear un vector de bricks en Lua
local bricks = {
    { position = { x = 100, y = 200 }, color = "red" },
    { position = { x = 150, y = 250 }, color = "blue" },
    -- Agregar más bricks según sea necesario
}

-- Pasar el vector de bricks a C++
createBricks(bricks)