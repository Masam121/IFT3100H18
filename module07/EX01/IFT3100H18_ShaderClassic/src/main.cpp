// IFT3100H18_ShaderClassic/main.cpp
// Exemple de projet qui supporte une version moderne (3.3) et une version de base (2.1)
// du pipeline programmable de OpenGL, avec shaders en version 330 et 120 respectivement.
// Dans chaque cas, 5 shaders sont disponibles (touches 1-5), soit :
// un shader avec une couleur de remplissage uniforme sur toute la surface,
// un shader avec modèle d'illumination de Lambert,
// un shader avec modèle d'illumination de Gouraud,
// un shader avec modèle d'illumination de Phong et
// un shader avec modèle d'illumination de Blinn-Phong.
// Le facteur de brillance spéculaire est animé par oscillation.
// La position de la source de lumière est interactive.

#include "ofMain.h"
#include "application.h"

int main()
{
  // paramètres du contexte de rendu OpenGL
  ofGLWindowSettings windowSettings;

  // résolution de la fenêtre d'affichage
  windowSettings.width  = 1024;
  windowSettings.height = 512;

  // sélection de la version (OpenGL 2.1 / GLSL 120)
  //windowSettings.setGLVersion(2, 1);

  // sélection de la version (OpenGL 3.3 / GLSL 330)
  windowSettings.setGLVersion(3, 3);

  // création de la fenêtre
  ofCreateWindow(windowSettings);

  // démarrer l'exécution de l'application
  ofRunApp(new Application());
}
