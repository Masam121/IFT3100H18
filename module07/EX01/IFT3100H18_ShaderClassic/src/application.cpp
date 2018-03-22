// IFT3100H18_ShaderClassic/application.cpp
// Classe principale de l'application.

#include "application.h"

void Application::setup()
{
  ofLog() << "<app::setup>";

  is_key_press_up = false;
  is_key_press_down = false;
  is_key_press_left = false;
  is_key_press_right = false;

  if (ofIsGLProgrammableRenderer())
  {
    renderer.gl_version_major = 3;
    renderer.gl_version_minor = 3;
  }
  else
  {
    renderer.gl_version_major = 2;
    renderer.gl_version_minor = 1;
  }

  renderer.setup();
}

void Application::update()
{
  ofSetWindowTitle("modèle d'illumination : " + renderer.shader_name + " (" + renderer.shader_version + ") (1-5 ↑↓←→ f r)");

  time_current = ofGetElapsedTimef();
  time_elapsed = time_current - time_last;
  time_last = time_current;

  if (is_key_press_up)
    renderer.offset_z += renderer.delta_z * time_elapsed;
  if (is_key_press_down)
    renderer.offset_z -= renderer.delta_z * time_elapsed;
  if (is_key_press_left)
    renderer.offset_x += renderer.delta_x * time_elapsed;
  if (is_key_press_right)
    renderer.offset_x -= renderer.delta_x * time_elapsed;

  renderer.update();
}

void Application::draw()
{
  renderer.draw();
}

void Application::mouseReleased(int x, int y, int button)
{
  renderer.reset();
}

void Application::keyPressed(int key)
{
  switch (key)
  {
    case 356: // touche ←
      is_key_press_left = true;
      break;

    case 357: // touche ↑
      is_key_press_up = true;
      break;

    case 358: // touche →
      is_key_press_right = true;
      break;

    case 359: // touche ↓
      is_key_press_down = true;
      break;

    default:
      break;
  }
}

void Application::keyReleased(int key)
{
  switch (key)
  {
    case 49: // touche 1
      renderer.shader_active = ShaderType::color_fill;
      ofLog() << "<shader: color fill>";
      break;

    case 50: // touche 2
      renderer.shader_active = ShaderType::lambert;
      ofLog() << "<shader: lambert>";
      break;

    case 51: // touche 3
      renderer.shader_active = ShaderType::gouraud;
      ofLog() << "<shader: gouraud>";
      break;

    case 52: // touche 4
      renderer.shader_active = ShaderType::phong;
      ofLog() << "<shader: phong>";
      break;

    case 53: // touche 5
      renderer.shader_active = ShaderType::blinn_phong;
      ofLog() << "<shader: blinn-phong>";
      break;

    case 102: // touche f
      renderer.is_flip_axis_y = !renderer.is_flip_axis_y;
      ofLog() << "<axis Y is flipped: " << renderer.is_flip_axis_y << ">";
      break;

    case 114: // touche r
      renderer.reset();
      break;

    case 356: // touche ←
      is_key_press_left = false;
      break;

    case 357: // touche ↑
      is_key_press_up = false;
      break;

    case 358: // touche →
      is_key_press_right = false;
      break;

    case 359: // touche ↓
      is_key_press_down = false;
      break;

    default:
      break;
  }
}

void Application::windowResized(int w, int h)
{
  renderer.reset();

  ofLog() << "<app::windowResized: (" << w << ", " << h << ")>";
}

void Application::exit()
{
  ofLog() << "<app::exit>";
}
