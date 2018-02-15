// IFT3100H18_RandomTriangle/application.cpp
// Classe principale de l'application.

#include "application.h"

void Application::setup()
{
  ofSetWindowTitle("bonjour triangle");

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
