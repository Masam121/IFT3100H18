// IFT3100H18_Triptyque/renderer.h
// Classe responsable du rendu de l'application.

#pragma once

#include "ofMain.h"

class Renderer
{
public:

  ofImage image_source;

  ofImage image_left;
  ofImage image_center;
  ofImage image_right;

  int image_width;
  int image_height;

  int offset_vertical;
  int offset_horizontal;

  void setup();
  void draw();
};
