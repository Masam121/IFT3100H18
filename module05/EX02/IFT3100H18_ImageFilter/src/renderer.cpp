 // IFT3100H18_ImageFilter/renderer.cpp
// Classe responsable du rendu de l'application.

#include "renderer.h"

void Renderer::setup()
{
  ofSetFrameRate(60);
  ofSetBackgroundColor(0);
  ofSetColor(255);
  ofSetLogLevel(OF_LOG_VERBOSE);
  ofDisableArbTex();

  // importer une image située dans ./bin/data
  image.load("field.jpg");

  // redimensionner la fenêtre selon la résolution de l'image
  ofSetWindowShape(image.getWidth() * 2, image.getHeight());

  // chargement des sources du shader
  shader.load(
    "image_filter_invert_330_vs.glsl",
    "image_filter_invert_330_fs.glsl");

  // initialisation de l'interface graphique
  gui.setup();
  gui.add(color_picker.set("tint color", ofColor(191, 191, 191), ofColor(0, 0), ofColor(255, 255)));
}

void Renderer::draw()
{
  // dessiner l'image sur la première moitié de la surface de la fenêtre
  image.draw(0, 0, image.getWidth(), image.getHeight());

  // sélectionner le shader
  shader.begin();

  // passer les attributs uniformes au shader
  shader.setUniformTexture("image", image.getTexture(), 1);
  shader.setUniform4f("tint",
    color_picker->r / 255.0f,
    color_picker->g / 255.0f,
    color_picker->b / 255.0f,
    color_picker->a / 255.0f);

  // dessiner l'image sur la seconde moitié de la surface de la fenêtre
  image.draw(ofGetWindowWidth() / 2.0f, 0.0f, image.getWidth(), image.getHeight());

  // désélectionner le shader
  shader.end();

  // dessiner l'interface graphique
  gui.draw();
}
