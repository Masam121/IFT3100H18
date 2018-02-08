// IFT3100H18_Origin/renderer.h
// Classe responsable du rendu de l'application.

#pragma once

#include "ofMain.h"

class Renderer
{
public:

  ofNode node;

  float center_x;
  float center_y;

  int framebuffer_width;
  int framebuffer_height;

  void setup();

  void draw();

  void reset();

  void draw_scene();

  void draw_locator(float scale);
};
