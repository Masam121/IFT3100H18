 // IFT3100H18_ImageFilter/renderer.h
// Classe responsable du rendu de l'application.

#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class Renderer
{
public:

  ofImage image;

  ofShader shader;

  ofxPanel gui;

  ofParameter<ofColor> color_picker;

  void setup();
  void draw();
};
