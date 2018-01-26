// IFT3100H18_ImageExport/renderer.cpp
// Classe responsable du rendu de l'application.

#include "renderer.h"

void Renderer::setup()
{
  ofSetFrameRate(60);

  image.load("field.jpg");

  ofSetWindowShape(image.getWidth(), image.getHeight());
}

void Renderer::draw()
{
  ofClear(0);

  image.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
}

// fonction qui exporte une image à partir de son nom et de son extension, à partir du répertoire ./bin/data ou d'un chemin absolue
void Renderer::image_export(const string name, const string extension) const
{
  ofImage image;

  // extraire des données temporelles formatées
  string time_stamp = ofGetTimestampString("-%y%m%d-%H%M%S-%i");

  // générer un nom de fichier unique et ordonné
  string file_name = name + time_stamp + "." + extension;

  // capturer le contenu du framebuffer actif
  image.grabScreen(0, 0, ofGetWindowWidth(), ofGetWindowHeight());

  // sauvegarder le fichier image
  image.save(file_name);

  ofLog() << "<export image: " << file_name << ">";
}
