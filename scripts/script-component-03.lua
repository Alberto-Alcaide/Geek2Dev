on_update_script = {
    function(entity, world, delta_time, ellapsed_time)

        --math.randomseed(os.time())
        --local random = math.random(150,350);

        local position = get_position(entity, world)

        local vx = 20
        local vy = 20

        if position.x > 150 and position.x < 300 then

            vx = 150
            vy = 200

        end
        if position.x > 300 then

            vx = 200
            vy = -150
        end

        set_velocity(entity, world, vx, vy);

    end
}