// IFT3100H18_ShaderLambert/application.cpp
// Classe principale de l'application.

#include "application.h"

void Application::setup()
{
  if (ofIsGLProgrammableRenderer())
  {
    renderer.gl_version_major = 3;
    renderer.gl_version_minor = 3;
    ofSetWindowTitle("teapot avec un shader de Lambert (OpenGL 3.3 | GLSL 330)");
  }
  else
  {
    renderer.gl_version_major = 2;
    renderer.gl_version_minor = 1;
    ofSetWindowTitle("teapot avec un shader de Lambert (OpenGL 2.1 | GLSL 120)");
  }

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
  renderer.use_rotation = !renderer.use_rotation;
}

void Application::exit()
{
  ofLog() << "<app::exit>";
}
