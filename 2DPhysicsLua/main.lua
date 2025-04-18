function love.load()
    -- 800 es ancho y 600 es alto
    w = 1920
    h = 1080

    circle = {
        x = 0,
        y = 0,
        radius = 50,
    }

    -- Calcula bordes en coordenadas de pantalla
    border = {
        left = circle.radius,
        right = h - circle.radius,
        top = circle.radius,
        bot = (h - circle.radius) - h / 2,
    }

    color = {
        black = { 0, 0, 0 },
        white = { 1, 1, 1 },
    }

    vel_y = 0
    grav = 0.5
    -- primero va el ancho luego el alto 800x600
    love.window.setMode(w, h, { resizable = false })
    love.window.setTitle("Círculo Centrado")
end

function love.draw()
    -- Física (debería ir en love.update, pero se mantiene aquí para simplificar)
    vel_y = vel_y + grav
    circle.y = math.min(circle.y + vel_y, border.bot) -- Limita movimiento

    -- Dibujado
    love.graphics.clear(color.black)
    love.graphics.translate(love.graphics.getWidth() / 2, love.graphics.getHeight() / 2)
    love.graphics.setColor(color.white)
    love.graphics.circle("fill", circle.x, circle.y, circle.radius)

    -- Detección de colisión
    if circle.y >= border.bot then
        vel_y = 0 -- Detener movimiento
    end
end
