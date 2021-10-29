#ifndef _Enemy_H_
#define _Enemy_H_

#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:
  Enemy(const LoaderParams* pParams);
  virtual void draw();
  virtual void update();
  virtual void clean();
};

#endif