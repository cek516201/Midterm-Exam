#include "TextureManager.h"
#include "SDL_image.h"

TextureManager* TextureManager::s_pInstance = 0;

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer)
{
  SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
  if(pTempSurface == 0)
  {
    return false;
  }

  SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
  if(pTexture == 0)
  {
    return false;
  }

  SDL_FreeSurface(pTempSurface);

  m_textureMap[id] = pTexture;

  return true;
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
  SDL_Rect srcRect;
  SDL_Rect destRect;

  srcRect.x = width * currentFrame;
  srcRect.y = height * currentRow;
  srcRect.w = destRect.w = width;
  srcRect.h = destRect.h = height;
  destRect.x = x;
  destRect.y = y;

  SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}