-- -- -- -- -- --
-- Chess Game? --
-- -- -- -- -- --

function love.load()
    
    mousehold_move = 1
    
    king = {}
    king.x = 256
    king.y = 256
    king.moves = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}

    queen = {}
    queen.x = 128
    queen.y = 128
end

function love.update(dt)
    
    if kingfollow == 1 then
        king.x = love.mouse.getX() - 16
        king.y = love.mouse.getY() - 16
    end
    if queenfollow == 1 then
        
end

function love.draw()
    love.graphics.rectangle("fill", king.x, king.y, 32, 32)
    love.graphics.rectangle("fill", queen.x, queen.y, 32, 32)
end

function love.mousepressed(posx, posy, button, istouch)
    if mousehold_move == 1 then kingfollow = 1 end
end

function love.mousereleased(posx, posy, button, istouch)
    if mousehold_move == 1 then kingfollow = 0 end
end

function love.keypressed(key)
    
end

function love.keyreleased(key)
    -- key up
end

function love.quit()
    -- exit
end

