#ifndef _Game_H_
#define _Game_H_

#include "SDL.h"
#include "TextureManager.h"
#include "vector"
#include "GameObject.h"

class Game;

typedef Game TheGame;

class Game
{
private:
  Game() {}
  static Game* s_pInstance;

public:
  static Game* Instance()
  {
    if(s_pInstance == 0)
      s_pInstance = new Game();

    return s_pInstance;
  }

  SDL_Renderer* getRenderer() const { return m_pRenderer; }

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

  int m_currentFrame;

  std::vector<GameObject*> m_gameObjects;
};

#endif