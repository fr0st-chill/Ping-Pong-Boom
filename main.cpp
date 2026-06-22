#include "main.h"

int main() {
  // Init SDL Graphic Components to Main Function
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();

  SDL_Window* window = SDL_CreateWindow("Pong", 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

  // Init fonr
  TTF_Font* scoreFont = TTF_OpenFont("DejaVuSansMono.ttf", 40);

  // Create player score text fields
  PlayerScore playerOneScoreText(Vec2(WINDOW_WIDTH / 4, 20), renderer, scoreFont, scoreColor);
  PlayerScore playerTwoScoreText(Vec2(3 * WINDOW_WIDTH / 4, 20), renderer, scoreFont, scoreColor);

  Paddle paddleOne(
	Vec2(50.0f, (WINDOW_HEIGHT / 2.0f) - (PADDLE_HEIGHT / 2.0f))
  );

  Paddle paddleTwo(
	Vec2(WINDOW_WIDTH - 50.0f, (WINDOW_HEIGHT / 2.0f) - (PADDLE_HEIGHT / 2.0f))
  );

  // Create the ball
  Ball ball(
	Vec2((WINDOW_WIDTH / 2.0f) - (BALL_WIDTH / 2.0f),
	(WINDOW_HEIGHT / 2.0f) - (BALL_WIDTH / 2.0f)));

  // Draw the ball
  ball.Draw(renderer);

  // Present the backbuffer
  SDL_RenderPresent(renderer);

  // ## Main Game Execution ##

  {
    bool running = true;

    // Loop and process events until user exits
    while (running)
    {
      SDL_Event event;
      while (SDL_PollEvent(&event))
      {
        if (event.type == SDL_QUIT)
        {
          running =  false;
        }
        else if (event.type == SDL_KEYDOWN)
        {
          if (event.key.keysym.sym == SDLK_ESCAPE)
          {
            running = false;
          }
        }
      }
      // Clear to Black
      SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0xFF);
      SDL_RenderClear(renderer);

      // Set draw color to White
      SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

      for (int y = 0; y < WINDOW_HEIGHT; ++y)
      {
        if (y % 5)
        {
          SDL_RenderDrawPoint(renderer, WINDOW_WIDTH / 2, y);
        }
      }
      // Draw the ball
      ball.Draw(renderer);

      // Draw the paddles
      paddleOne.Draw(renderer);
      paddleTwo.Draw(renderer);

      // Present the backbuffer
      SDL_RenderPresent(renderer);
    }
  }

  // Clean-up the Runtime Environment
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_CloseFont(scoreFont);
  TTF_Quit();
  SDL_Quit();

  return 0;
}
