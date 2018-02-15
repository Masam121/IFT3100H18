// IFT3100H18_Teapot/application.cpp
// Classe principale de l'application.

#include "application.h"

void Application::setup()
{
  ofLog() << "<app::setup>";

  ofSetWindowTitle("teapot (↑ ↓ ← → 1 2 3 w e r f)");

  is_key_press_up = false;
  is_key_press_down = false;
  is_key_press_left = false;
  is_key_press_right = false;

  renderer.setup();
}

void Application::update()
{
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
    case 49:  // touche 1
      renderer.mesh_render_mode = MeshRenderMode::fill;
      ofLog() << "<mesh render mode: FILL>";
      break;

    case 50:  // touche 2
      renderer.mesh_render_mode = MeshRenderMode::wireframe;
      ofLog() << "<mesh render mode: WIREFRAME>";
      break;

    case 51:  // touche 3
      renderer.mesh_render_mode = MeshRenderMode::vertex;
      ofLog() << "<mesh render mode: VERTEX>";
      break;

    case 114: // touche r
      renderer.is_active_proportion = !renderer.is_active_proportion;
      ofLog() << "<proportion is active: " << renderer.is_active_proportion << ">";
      break;

    case 101: // touche e
      renderer.is_active_rotation = !renderer.is_active_rotation;
      ofLog() << "<rotation is active: " << renderer.is_active_rotation << ">";
      break;

    case 102: // touche f
      renderer.is_flip_axis_y = !renderer.is_flip_axis_y;
      ofLog() << "<axis Y is flipped: " << renderer.is_flip_axis_y << ">";
      break;

    case 119: // touche w
      renderer.is_active_translation = !renderer.is_active_translation;
      ofLog() << "<translation is active: " << renderer.is_active_translation << ">";
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
