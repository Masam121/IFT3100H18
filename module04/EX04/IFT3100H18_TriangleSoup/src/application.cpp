// IFT3100H18_TriangleSoup/application.cpp
// Classe principale de l'application.

#include "application.h"

void Application::setup()
{
  ofSetWindowTitle("soupe au triangles (↑ ↓ ← → z x)");

  is_key_press_up    = false;
  is_key_press_down  = false;
  is_key_press_left  = false;
  is_key_press_right = false;
  is_key_press_z     = false;
  is_key_press_x     = false;

  renderer.setup();
}

void Application::update()
{
  time_current = ofGetElapsedTimef();
  time_elapsed = time_current - time_last;
  time_last = time_current;

  if(is_key_press_up)
    renderer.offset_z += renderer.delta_z * time_elapsed;
  if(is_key_press_down)
    renderer.offset_z -= renderer.delta_z * time_elapsed;
  if(is_key_press_left)
    renderer.offset_x += renderer.delta_x * time_elapsed;
  if(is_key_press_right)
    renderer.offset_x -= renderer.delta_x * time_elapsed;

  if(is_key_press_z)
    renderer.offset_y += renderer.delta_y * time_elapsed;
  if(is_key_press_x)
    renderer.offset_y -= renderer.delta_y * time_elapsed;
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
  switch(key)
  {
    case 120: // touche x
      is_key_press_x = true;
      break;

    case 122: // touche z
      is_key_press_z = true;
      break;

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
  switch(key)
  {
    case 120: // touche x
      is_key_press_x = false;
      break;

    case 122: // touche z
      is_key_press_z = false;
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
      renderer.reset();
      break;
  }
}

void Application::exit()
{
  ofLog() << "<app::exit>";
}
