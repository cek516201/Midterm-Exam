#ifndef _Game_H_
#define _Game_H_

#include "SDL.h"

class Game
{
public:
  Game() {}
  ~Game() {}
  
  bool init(const char *title, int xpos, int ypos, int width, int height, int flags);
  void render();
  void update();
  bool running();
  void handleEvents();
  void clean();

private:
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  bool m_bRunning;

  SDL_Texture* m_pTexture;
  SDL_Rect m_sourceRectangle; // 원본상자
  SDL_Rect m_destinationRectangle; // 대상상자
};

#endif