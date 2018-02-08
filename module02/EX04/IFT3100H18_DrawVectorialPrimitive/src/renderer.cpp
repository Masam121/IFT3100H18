// IFT3100H18_DrawVectorialPrimitive/renderer.cpp
// Classe responsable du rendu de l'application.

#include "renderer.h"

void Renderer::setup()
{
  ofSetFrameRate(60);
  ofSetBackgroundColor(191);

  // nombre maximale de primitives vectorielles dans le tableau
  count = 100;

  // position de la prochaine primitive
  head = 0;

  // calculer la taille de la structure générique commune à toutes les primitives vectorielles
  stride = sizeof(VectorialPrimitive);

  // calculer le nombre d'octets à allouer en mémoire pour contenir le tableau de primitives vectorielles
  size = count * stride;

  // allocation d'un espace mémoire suffisament grand pour contenir les données de l'ensemble des primitives vectorielles
  shapes = (VectorialPrimitive*) std::malloc(size * stride);

  // mode de dessin par défaut
  draw_mode = VectorialPrimitiveType::rectangle;

  // largeur de la ligne de contour
  stroke_width_default = 2;

  // couleur de la ligne de contour
  random_color_stroke();

  // couleur de la zone de remplissage
  random_color_fill();

  mouse_press_x = mouse_press_y = mouse_current_x = mouse_current_y = 0;

  is_mouse_button_pressed = false;
}

void Renderer::draw()
{
  for (index = 0; index < count; ++index)
  {
    switch (shapes[index].type)
    {
      case VectorialPrimitiveType::pixel:

        ofFill();
        ofSetLineWidth(0);
        ofSetColor(
          shapes[index].stroke_color[0],
          shapes[index].stroke_color[1],
          shapes[index].stroke_color[2]);
        draw_pixel(
          shapes[index].position2[0],
          shapes[index].position2[1]);
        break;

      case VectorialPrimitiveType::point:

        ofFill();
        ofSetLineWidth(0);
        ofSetColor(
          shapes[index].stroke_color[0],
          shapes[index].stroke_color[1],
          shapes[index].stroke_color[2]);
        draw_point(
          shapes[index].position2[0],
          shapes[index].position2[1],
          shapes[index].stroke_width);
        break;

      case VectorialPrimitiveType::line:

        ofNoFill();
        ofSetLineWidth(shapes[index].stroke_width);
        ofSetColor(
          shapes[index].stroke_color[0],
          shapes[index].stroke_color[1],
          shapes[index].stroke_color[2]);
        draw_line(
          shapes[index].position1[0],
          shapes[index].position1[1],
          shapes[index].position2[0],
          shapes[index].position2[1]);
        break;

      case VectorialPrimitiveType::rectangle:

        ofFill();
        ofSetLineWidth(0);
        ofSetColor(
          shapes[index].fill_color[0],
          shapes[index].fill_color[1],
          shapes[index].fill_color[2]);
        draw_rectangle(
          shapes[index].position1[0],
          shapes[index].position1[1],
          shapes[index].position2[0],
          shapes[index].position2[1]);
        ofNoFill();
        ofSetLineWidth(shapes[index].stroke_width);
        ofSetColor(
          shapes[index].stroke_color[0],
          shapes[index].stroke_color[1],
          shapes[index].stroke_color[2]);
        draw_rectangle(
          shapes[index].position1[0],
          shapes[index].position1[1],
          shapes[index].position2[0],
          shapes[index].position2[1]);
        break;

      case VectorialPrimitiveType::ellipse:

        ofFill();
        ofSetLineWidth(0);
        ofSetCircleResolution(48);
        ofSetColor(
          shapes[index].fill_color[0],
          shapes[index].fill_color[1],
          shapes[index].fill_color[2]);
        draw_ellipse(
          shapes[index].position1[0],
          shapes[index].position1[1],
          shapes[index].position2[0],
          shapes[index].position2[1]);
        ofNoFill();
        ofSetLineWidth(shapes[index].stroke_width);
        ofSetColor(
          shapes[index].stroke_color[0],
          shapes[index].stroke_color[1],
          shapes[index].stroke_color[2]);
        draw_ellipse(
          shapes[index].position1[0],
          shapes[index].position1[1],
          shapes[index].position2[0],
          shapes[index].position2[1]);
        break;

      default:
        break;
    }
  }

  // afficher la zone de sélection
  if (is_mouse_button_pressed)
  {
    ofSetColor(255);
    ofSetLineWidth(3);
    ofNoFill();

    draw_zone(
      mouse_press_x,
      mouse_press_y,
      mouse_current_x,
      mouse_current_y);
  }

  // afficher le curseur
  ofSetLineWidth(2);
  ofSetColor(31);

  draw_cursor(mouse_current_x, mouse_current_y);
}

// fonction qui vide le tableau de primitives vectorielles
void Renderer::reset()
{
  for (index = 0; index < count; ++index)
    shapes[index].type = VectorialPrimitiveType::none;

  head = 0;

  ofLog() << "<reset>";
}

// fonction qui ajoute une primitive vectorielle au tableau
void Renderer::add_vector_shape(VectorialPrimitiveType type)
{
  shapes[head].type = type;

  shapes[head].position1[0] = mouse_press_x;
  shapes[head].position1[1] = mouse_press_y;

  shapes[head].position2[0] = mouse_current_x;
  shapes[head].position2[1] = mouse_current_y;

  shapes[head].stroke_color[0] = stroke_color_r;
  shapes[head].stroke_color[1] = stroke_color_g;
  shapes[head].stroke_color[2] = stroke_color_b;
  shapes[head].stroke_color[3] = stroke_color_a;

  shapes[head].fill_color[0] = fill_color_r;
  shapes[head].fill_color[1] = fill_color_g;
  shapes[head].fill_color[2] = fill_color_b;
  shapes[head].fill_color[3] = fill_color_a;

  switch (shapes[head].type)
  {
    case VectorialPrimitiveType::point:
      shapes[head].stroke_width = ofRandom(1, 64);
      break;

    case VectorialPrimitiveType::line:
      shapes[head].stroke_width = ofRandom(1, 16);
      break;

    case VectorialPrimitiveType::rectangle:
      shapes[head].stroke_width = stroke_width_default;
      break;

    case VectorialPrimitiveType::ellipse:
      shapes[head].stroke_width = stroke_width_default;
      break;

    default:
      shapes[head].stroke_width = stroke_width_default;
      break;
  }

  ofLog() << "<add a vectorial primitive to collection at index: " << head << ">";

  head = ++head >= count ? 0: head; // boucler sur le tableau si plein
}

// fonction qui dessine un pixel
void Renderer::draw_pixel(float x, float y) const
{
  int pixel_x = floorf(x);
  int pixel_y = floorf(y);

  ofDrawRectangle(pixel_x, pixel_y, 1, 1);
}

// fonction qui dessine un point
void Renderer::draw_point(float x, float y, float radius) const
{
  ofDrawEllipse(x, y, radius, radius);
}

// fonction qui dessine une ligne
void Renderer::draw_line(float x1, float y1, float x2, float y2) const
{
  ofDrawLine(x1, y1, x2, y2);
}

// fonction qui dessine un rectangle
void Renderer::draw_rectangle(float x1, float y1, float x2, float y2) const
{
  ofDrawRectangle(x1, y1, x2 - x1, y2 - y1);
}

// fonction qui dessine une ellipse
void Renderer::draw_ellipse(float x1, float y1, float x2, float y2) const
{
  float diameter_x = x2 - x1;
  float diameter_y = y2 - y1;

  ofDrawEllipse(x1 + diameter_x / 2.0f, y1 + diameter_y / 2.0f, diameter_x, diameter_y);
}

// fonction qui détermine une couleur aléatoire pour les lignes de contour
void Renderer::random_color_stroke()
{
  stroke_color_r = (int) ofRandom(0, 256);
  stroke_color_g = (int) ofRandom(0, 256);
  stroke_color_b = (int) ofRandom(0, 256);
  stroke_color_a = 255;

  ofLog() << "<random color stroke>";
}

// fonction qui détermine une couleur aléatoire pour les zones de remplissage
void Renderer::random_color_fill()
{
  fill_color_r = (int) ofRandom(0, 256);
  fill_color_g = (int) ofRandom(0, 256);
  fill_color_b = (int) ofRandom(0, 256);
  fill_color_a = 255;

  ofLog() << "<random color fill>";
}

void Renderer::draw_zone(float x1, float y1, float x2, float y2) const
{
  float x2_clamp = min(max(0.0f, x2), (float) ofGetWidth());
  float y2_clamp = min(max(0.0f, y2), (float) ofGetHeight());

  ofDrawRectangle(x1, y1, x2_clamp - x1, y2_clamp - y1);
}

void Renderer::draw_cursor(float x, float y) const
{
  float length = 10.0f;
  float offset = 5.0f;

  ofDrawLine(x + offset, y, x + offset + length, y);
  ofDrawLine(x - offset, y, x - offset - length, y);
  ofDrawLine(x, y + offset, x, y + offset + length);
  ofDrawLine(x, y - offset, x, y - offset - length);
}

Renderer::~Renderer()
{
  std::free(shapes);
}
