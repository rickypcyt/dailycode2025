function love.load()
    h = 800 -- Ancho de la ventana
    w = 600 -- Alto de la ventana

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
        bot = w - circle.radius, -- Usa el alto correcto (w)
    }

    -- Calcula el borde inferior en coordenadas traducidas (centro como origen)
    border.translated_bot = border.bot - w / 2 -- 550 - 300 = 250

    color = {
        black = { 0, 0, 0 },
        white = { 1, 1, 1 },
    }

    vel_y = 0
    grav = 0.5

    love.window.setMode(h, w, { resizable = false })
    love.window.setTitle("Círculo Centrado")
end

function love.draw()
    -- Física (debería ir en love.update, pero se mantiene aquí para simplificar)
    vel_y = vel_y + grav
    circle.y = math.min(circle.y + vel_y, border.translated_bot) -- Limita movimiento

    -- Dibujado
    love.graphics.clear(color.black)
    love.graphics.translate(love.graphics.getWidth() / 2, love.graphics.getHeight() / 2)
    love.graphics.setColor(color.white)
    love.graphics.circle("fill", circle.x, circle.y, circle.radius)

    -- Detección de colisión
    if circle.y >= border.translated_bot then
        vel_y = 0 -- Detener movimiento
    end
end
