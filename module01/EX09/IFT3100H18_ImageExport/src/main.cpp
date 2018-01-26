// IFT3100H18_ImageExport/main.cpp
// Exemple d'exportation du contenu de la fenêtre d'affichage dans un fichier image situé dans le répertoire ./bin/data.
// L'exportation est déclanchée lorsque la barre d'espacement est relachée.

#include "ofMain.h"
#include "application.h"

int main()
{
  ofSetupOpenGL(512, 512, OF_WINDOW);
  ofRunApp(new Application());
}
