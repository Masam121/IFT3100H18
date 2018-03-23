// IFT3100H18_Camera/main.cpp
// Exemple d'une scène avec différentes caméras interactives.

#include "ofMain.h"
#include "application.h"

int main()
{
  ofGLWindowSettings windowSettings;

  windowSettings.width = 512;
  windowSettings.height = 512;

  windowSettings.setGLVersion(2, 1);

  ofCreateWindow(windowSettings);

  ofRunApp(new Application());
}
