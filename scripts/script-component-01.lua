
entities = {
    
        group = "meteor",
        components = {
            transform = {
                position = { x = 0, y = 0 },
                scale = { x = 1.0, y = 1.0},
                rotation = 0.0,
            },
            kinematic = {
                velocity = { x = 20, y = 20},
                acceleration = { x = 0, y = 0},
                angularVelocity = 1,
                angularAcceleration = 0,
            },
            collider = {
                render = true,
                shape = {
                    type = "circle",
                    radius = 60,
                    color = {r = 255, g = 0, b = 0},
                    filled = true
                }
            },
            rigidbody = {
                mass = 1,
                shape = {
                    type = "circle",
                    radius = 60,
                    color = {r = 255, g = 0, b = 0}
                    filled = true
                }
            }
        }
    
}