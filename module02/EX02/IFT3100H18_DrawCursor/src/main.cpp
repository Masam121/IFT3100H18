// IFT3100H18_DrawCursor/main.cpp
// Dessiner un curseur en fonction des états et des événements d'un périphérique de pointage et afficher ces informations dans la console.

#include "ofMain.h"
#include "application.h"

int main( )
{
  ofSetupOpenGL(512, 512, OF_WINDOW);
  ofRunApp(new Application());
}
