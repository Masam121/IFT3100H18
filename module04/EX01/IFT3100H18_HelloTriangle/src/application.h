// IFT3100H18_RandomTriangle/application.h
// Classe principale de l'application.

#pragma once

#include "ofMain.h"
#include "renderer.h"

class Application : public ofBaseApp
{
public:

  Renderer renderer;

  void setup();
  void update();
  void draw();
};
