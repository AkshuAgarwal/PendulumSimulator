#include <SDL2/SDL.h>
#include <array>
#include <iostream>
#include <vector>

#define SDL_INIT_FLAG SDL_INIT_VIDEO
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define WINDOW_TITLE "Pendulum"
#define PI 3.141592653589793238

void DrawCircle(SDL_Renderer *renderer, float c_x, float c_y, float r) {
  float pres = 0.01;
  float th = 0;
  float s_x, s_y, e_x, e_y;

  while (th < PI) {
    s_x = c_x + (r * cos(PI + th));
    s_y = c_y + (r * sin(PI + th));
    e_x = c_x + (r * cos(th));
    e_y = c_y + (r * sin(th));

    SDL_RenderDrawLine(renderer, s_x, s_y, e_x, e_y);
    th += pres;
  }
}

int main(int argc, char *argv[]) {
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;

  // Pendulum Parameters
  float c_x = (float)SCREEN_WIDTH / 2, c_y = (float)SCREEN_HEIGHT / 2;
  float g = 9.81;
  float x = 0, y = 0, th = PI / 3, w = 0, al = 0;
  float l = 150;
  float dt = 0.001;

  bool show_trails = true;
  std::vector<std::array<float, 2>> trail_points;

  // SDL Initialization
  if (SDL_Init(SDL_INIT_FLAG) < 0) {
    std::cerr << "SDL_Init Failed! Error: " << SDL_GetError() << '\n';
    return EXIT_FAILURE;
  }

  window =
      SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
  if (!window) {
    std::cerr << "SDL_CreateWindow failed! Error in window creation\n ";
    return EXIT_FAILURE;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer) {
    std::cerr << "SDL_CreateRenderer failed! Error in renderer creation\n";
    return EXIT_FAILURE;
  }

  // Game loop
  bool quit = false;
  SDL_Event e;

  while (!quit) {
    while (SDL_PollEvent(&e) != 0) {
      switch (e.type) {
      case SDL_QUIT:
        quit = true;
        break;
      }
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    al = dt * (-1 * g * sin(th)) / l;

    w += al;
    th += w;

    x = c_x + (l * sin(th));
    y = c_y + (l * cos(th));

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer, c_x, c_y, x, y);
    DrawCircle(renderer, x, y, 10);

    if (show_trails) {
      trail_points.push_back({x, y});

      SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
      for (auto i = trail_points.begin(); i != trail_points.end(); i++) {
        SDL_RenderDrawPoint(renderer, (*i)[0], (*i)[1]);
      }
    }

    SDL_RenderPresent(renderer);
    SDL_Delay(2);
  }

  // Cleanup
  SDL_DestroyRenderer(renderer);
  renderer = NULL;

  SDL_DestroyWindow(window);
  window = NULL;

  SDL_Quit();
  return EXIT_SUCCESS;
}
