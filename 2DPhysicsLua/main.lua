function love.load()
    circle = {
        x = 0,
        y = 0,
        radius = 50,
    }

    HEIGHT = 800
    WIDTH = 600

    color = {
        black = { 0, 0, 0 },
        white = { 1, 1, 1 },
    }

    love.window.setMode(HEIGHT, WIDTH, {
        resizable = false,
    })

    love.window.setTitle("Círculo Centrado")
end

function love.draw()
    love.graphics.clear(black)
    love.graphics.translate(love.graphics.getWidth() / 2, love.graphics.getHeight() / 2)
    love.graphics.setColor(color.white)
    love.graphics.circle("fill", circle.x, circle.y, circle.radius)
end
