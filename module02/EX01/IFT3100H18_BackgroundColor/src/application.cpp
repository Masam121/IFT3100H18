// IFT3100H18_BackgroundColor/application.cpp
// Classe principale de l'application.

#include "application.h"

void Application::setup()
{
  ofSetWindowTitle("couleur d'arrière-plan (1-6 ou hasard)");

  ofLog() << "<app::setup>";

  renderer.setup();
}

void Application::draw()
{
  renderer.draw();
}

void Application::keyReleased(int key)
{
  switch(key)
  {
    case 49: // touche 1
      renderer.clear_mode = ClearMode::none;
      ofLog() << "<clear mode: NONE>";
      break;

    case 50: // touche 2
      renderer.clear_mode = ClearMode::black;
      ofLog() << "<clear mode: BLACK>";
      break;

    case 51: // touche 3
      renderer.clear_mode = ClearMode::white;
      ofLog() << "<clear mode: WHITE>";
      break;

    case 52: // touche 4
      renderer.clear_mode = ClearMode::gray;
      ofLog() << "<clear mode: GRAY>";
      break;

    case 53: // touche 5
      renderer.clear_mode = ClearMode::color;
      ofLog() << "<clear mode: COLOR>";
      break;

    case 54: // touche 6 et autre
    default:
      renderer.clear_mode = ClearMode::random;
      ofLog() << "<clear mode: RANDOM>";
      break;
  }

  renderer.has_changed = true;
}

void Application::exit()
{
  ofLog() << "<app::exit>";
}
