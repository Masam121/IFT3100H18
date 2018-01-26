// IFT3100H18_ImageExport/renderer.h
// Classe responsable du rendu de l'application.

#pragma once

#include "ofMain.h"

class Renderer
{
public:

  ofImage image;

  void setup();
  void draw();

  void image_export(const string name, const string extension) const;
};
