//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// width of paddle
#define PADDLEWIDTH 70

// height of paddle
#define PADDLEHEIGHT 10

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);
    
    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
    
            
    double velocityX = drand48() / 20.0;
    double velocityY = 1.0 / 20.0;
    
    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {    
        GEvent movePaddle = getNextEvent(MOUSE_EVENT);
        
        if (movePaddle != 0)
        {
            if (getEventType(movePaddle) == MOUSE_MOVED)
            {
                double x = getX(movePaddle) - getWidth(paddle) / 2;
                setLocation(paddle, x, HEIGHT - PADDLEHEIGHT - 30);
            }
        }
        
        move(ball, velocityX, velocityY);
        
        if (getX(ball) + getWidth(ball) >= WIDTH)
        {
            velocityX = - velocityX;
        }
        else if (getX(ball) <= 0)
        {
            velocityX = - velocityX;
        }
        
        if (getY(ball) + getWidth(ball) >= HEIGHT)
        {
            lives--;
            velocityY = - velocityY;
        }
        else if(getY(ball) <= 0)
        {
            velocityY = -velocityY;
        }
        
        GObject object = detectCollision(window, ball);
        
        if (detectCollision(window, ball) != 0)
        {
            if (object == paddle)
            {
                velocityY = - velocityY;
            }
            
            else if (strcmp(getType(object), "GRect") == 0)
            {
                removeGWindow(window, object);
                bricks--;
                updateScoreboard(window, label, bricks);
                velocityY = -velocityY;
                if (velocityX < 0)
                {
                    velocityX = -drand48() / 20.0;
                }
                else 
                {
                    velocityX = drand48() / 20.0;
                }
            }
        }
    }
    
    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    int brickX = 0;
    int brickY = 0;
    int stepX = 4;
    int stepY = 4;
    double brickWidth = (WIDTH - 4) / COLS - stepX;
    int brickHeight = 12;

    for (int i = 0; i < ROWS; i++)
    {
        brickX = 0;
        
        char* color[ROWS] = { "RED", "ORANGE", "YELLOW", "GREEN", "BLUE"};
        
        for (int j = 0; j < COLS; j++)
        {
            GRect brick = newGRect(brickX + stepX,brickY + stepY + 40, brickWidth, brickHeight);
            setFilled(brick, true);
            setColor(brick, color[i]);
            add(window, brick);
            
            brickX += brickWidth + stepX;
        }
        
        brickY += brickHeight + stepY;
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    GOval ball = newGOval(WIDTH / 2 - RADIUS, HEIGHT / 2 - RADIUS, RADIUS * 2, RADIUS * 2);
    setFilled(ball, true);
    setColor(ball, "BLACK");
    add(window, ball);
    
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{   
    int paddleX = WIDTH / 2 - PADDLEWIDTH / 2;
    int paddleY = HEIGHT - PADDLEHEIGHT - 30;
    
    GRect paddle = newGRect(paddleX, paddleY, PADDLEWIDTH, PADDLEHEIGHT);
    
    setFilled(paddle, true);
    setColor(paddle, "BLACK");
    
    add(window, paddle);
    
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel label = newGLabel("50");
    setFont(label, "SansSerif-36");
    add(window, label);
    
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
    
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
