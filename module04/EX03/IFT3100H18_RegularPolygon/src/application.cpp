// IFT3100H18_RegularPolygon/application.cpp
// Classe principale de l'application.

#include "application.h"

void Application::setup()
{
  ofSetWindowTitle("polygones réguliers (0-9)");

  renderer.setup();
}

void Application::update()
{
  renderer.update();
}

void Application::draw()
{
  renderer.draw();
}

void Application::keyReleased(int key)
{
  switch (key)
  {
    case 48:  // touche 0
      renderer.side = 12;
      ofLog() << "<draw mode: DODÉCAGONE>";
      break;

    case 49:  // touche 1
      renderer.side = 3;
      ofLog() << "<draw mode: TRIANGLE>";
      break;

    case 50:  // touche 2
      renderer.side = 4;
      ofLog() << "<draw mode: CARRÉ>";
      break;

    case 51:  // touche 3
      renderer.side = 5;
      ofLog() << "<draw mode: PENTAGONE>";
      break;

    case 52:  // touche 4
      renderer.side = 6;
      ofLog() << "<draw mode: HEXAGONE>";
      break;

    case 53:  // touche 5
      renderer.side = 7;
      ofLog() << "<draw mode: HEPTAGONE>";
      break;

    case 54:  // touche 6
      renderer.side = 8;
      ofLog() << "<draw mode: OCTOGONE>";
      break;

    case 55:  // touche 7
      renderer.side = 9;
      ofLog() << "<draw mode: NONAGONE>";
      break;

    case 56:  // touche 8
      renderer.side = 10;
      ofLog() << "<draw mode: DÉCAGONE>";
      break;

    case 57:  // touche 9
      renderer.side = 11;
      ofLog() << "<draw mode: HENDÉCAGONE>";
      break;

  default:
      break;
  }
}

void Application::exit()
{
  ofLog() << "<app::exit>";
}
