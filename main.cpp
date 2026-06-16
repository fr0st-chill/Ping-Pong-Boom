#include <SDL2/SDL.h>

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

int main() {
  // Init SDL Graphic Components to Main Function
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window* window = SDL_CreateWindow("Pong", 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

  // Main Game Logic
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
      // Present the backbuffer
      SDL_RenderPresent(renderer);
    }
  }

  // Clean-up the Runtime Environment
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
