// IFT3100H18_Origin/renderer.cpp
// Classe responsable du rendu de l'application.

#include "renderer.h"

void Renderer::setup()
{
  ofSetFrameRate(60);
  ofSetBackgroundColor(63);

  reset();
}

void Renderer::draw()
{
  ofSetLineWidth(4);
  ofSetColor(127);

  draw_scene();
}

// fonction qui initialise la scène
void Renderer::reset()
{
  // extraire la résolution du framebuffer
  framebuffer_width = ofGetWidth();
  framebuffer_height = ofGetHeight();

  // calculer les coordonnées du centre du framebuffer
  center_x = framebuffer_width / 2.0f;
  center_y = framebuffer_height / 2.0f;

  ofLog() << "<reset>";
}

// fonction qui fait le rendu des entités géométriques de la scène
void Renderer::draw_scene()
{
  // rendre l'origine de la scène avant transformation du système de coordonnées
  draw_locator(10);

  // copier la matrice de transformation courante sur le dessus de la pile
  ofPushMatrix();

  // transformer l'origine de la scène au milieu de la fenêtre d'affichage
  ofTranslate(center_x, center_y, 0);

  // rendre l'origine de la scène après transformation du système de coordonnées
  draw_locator(10);

  // revenir à la matrice de transformation précédente dans la pile
  ofPopMatrix();
}

// fonction qui dessine un localisateur à l'origine de la scène
void Renderer::draw_locator(float scale)
{
  ofFill();
  ofPushMatrix();
  ofScale(scale, scale);
  node.setPosition(0, 0, 0);
  node.draw();
  ofPopMatrix();
}
