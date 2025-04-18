function love.load()
    circle = {
        x = 0,
        y = 0,
        radius = 50,
        color = { 1, 1, 1 },
    }

    love.window.setMode(800, 600, {
        resizable = false,
    })

    love.window.setTitle("Círculo Centrado")
end

function love.draw()
    love.graphics.clear(0, 0, 0)
    love.graphics.translate(love.graphics.getWidth() / 2, love.graphics.getHeight() / 2)
    love.graphics.setColor(circle.color)
    love.graphics.circle("fill", circle.x, circle.y, circle.radius)
end
