 // IFT3100H18_ImageFilter/main.cpp
// Exemples d'application d'un filtre sur une image avec un shader de fragment.
// Le filtre inverse la couleur de la texture et applique une teinte.

#include "ofMain.h"
#include "application.h"

int main()
{
  // paramètres du contexte de rendu OpenGL
  ofGLFWWindowSettings windowSettings;

  // option de redimentionnement de la fenêtre d'affichage
  windowSettings.resizable = false;

  // sélection de la version de OpenGL
  windowSettings.setGLVersion(3, 3);

  // création de la fenêtre
  ofCreateWindow(windowSettings);

  // démarrer l'exécution de l'application
  ofRunApp(new Application());
}
