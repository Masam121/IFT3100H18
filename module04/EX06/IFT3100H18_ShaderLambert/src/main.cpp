// IFT3100H18_ShaderLambert/main.cpp
// Exemple d'importation et de rendu d'un teapot avec un shader de Lambert.
// Le shader est disponible en deux versions, soit une version de base pour OpenGL 2.1 (GLSL 120) et une version moderne pour OpenGL 3.3 (GLSL 330).
// Le fichier de géométrie du teapot et les shaders sont dans le répertoire ./bin/data.

#include "ofMain.h"
#include "application.h"

int main()
{
  // paramètres du contexte de rendu
  ofGLFWWindowSettings windowSettings;

  // résolution de la fenêtre d'affichage
  windowSettings.width = 512;
  windowSettings.height = 512;

  // sélection de la version de OpenGL
  windowSettings.setGLVersion(2, 1);
  //windowSettings.setGLVersion(3, 3);

  // création de la fenêtre
  ofCreateWindow(windowSettings);

  // démarrer l'exécution de l'application
  ofRunApp(new Application());
}
