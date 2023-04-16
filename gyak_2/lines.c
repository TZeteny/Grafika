#include <GL/gl.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <stdbool.h>
#include <stdio.h>

#define MAX_LINE_COUNT 5

struct line {
	float str_x;
	float str_y;
	float end_x;
	float end_y;
	int color[3];
};
typedef struct line Line;

int main(int argc, char* argv[])
{
  int error_code;
  SDL_Window* window;
  bool need_run;
  SDL_Event event;
  SDL_GLContext gl_context;
  int i;
  Line line;
  int color[3] = {0, 255, 0};
  int x, y; //Coordinates for mouse position
  int points = 0; //to determine wheter it's a starting or end point
  int line_count = 0;

  //ERROR
  error_code = SDL_Init(SDL_INIT_EVERYTHING);
  if (error_code != 0) {
    printf("[ERROR] SDL initialization error: %s\n", SDL_GetError());
    return error_code;
  }

  //Create window
  window = SDL_CreateWindow(
    "Draw lines",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    800, 600,
    SDL_WINDOW_OPENGL);

    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

  gl_context = SDL_GL_CreateContext(window);

  //need run
  need_run = true;
  while (need_run) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_KEYDOWN:
        //change colors to red and green
        case SDL_SCANCODE_R:
            line.color[0] = 255;
            line.color[1] = 0;
            line.color[2] = 0;
            break;
        case SDL_SCANCODE_R:
            line.color[0] = 0;
            line.color[1] = 255;
            line.color[2] = 0;
            break;
        case SDL_SCANCODE_Q:
            need_run = false;
            break;
        case SDL_QUIT:
            need_run = false;
            break;
      case SDL_MOUSEBUTTONDOWN:
        if (SDL_BUTTON_LEFT == event.button.button) {
        SDL_GetMouseState(&x, &y);

        if(points == 0 && line_count < MAX_LINE_COUNT) {
            SDL_Log("Starting point: %d , %d", x, y);
            line.str_x = (float)x;
            line.str_y = (float)y;
            points++;
        }
        else if(line_count >= MAX_LINE_COUNT) {
            SDL_Log("Reached max line count!");
        }
        else if(points == 1) {
            SDL_Log("End point:  %d , %d", x, y);
            line.end_x = (float)x;
            line.end_y = (float)y;
            points = 0;
            line_count++;
        }

        SDL_SetRenderDrawColor(renderer, line.color[0], line.color[1], line.color[2], SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLine(renderer, line.str_x, line.str_y, line.end_x, line.end_y);

        }
      }
    }

    SDL_RenderPresent(renderer);

  }

  SDL_GL_DeleteContext(gl_context);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}























