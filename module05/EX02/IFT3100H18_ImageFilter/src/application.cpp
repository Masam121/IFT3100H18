// IFT3100H18_ImageFilter/application.cpp
// Classe principale de l'application.

#include "application.h"

void Application::setup()
{
  ofSetWindowTitle("filtre d'image");

  ofLog() << "<app::setup>";

  renderer.setup();
}

void Application::draw()
{
  renderer.draw();
}

void Application::dragEvent(ofDragInfo dragInfo)
{
  ofLog() << "<app::ofDragInfo file[0]: " << dragInfo.files.at(0)
          << " at : " << dragInfo.position << ">";

  renderer.image.load(dragInfo.files.at(0));

  if (renderer.image.getWidth() > 0 && renderer.image.getHeight() > 0)
    ofSetWindowShape(renderer.image.getWidth() * 2, renderer.image.getHeight());
}

void Application::exit()
{
  ofLog() << "<app::exit>";
}
