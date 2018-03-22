// IFT3100H18_ShaderClassic/renderer.cpp
// Classe responsable du rendu de l'application.

#include "renderer.h"

void Renderer::setup()
{
  ofSetFrameRate(60);
  ofSetSphereResolution(32);
  ofSetBackgroundColor(0);
  ofEnableDepthTest();

  // paramètres
  oscillation_amplitude = 32.0f;
  oscillation_frequency = 7500.0f;
  speed_motion = 150.0f;
  initial_x = 0.0f;
  initial_y = -100.0f;
  scale_cube = 100.0f;
  scale_sphere = 80.0f;
  scale_teapot = 0.618f;

  // initialisation des variables
  offset_x = initial_x;
  offset_z = initial_y;

  delta_x = speed_motion;
  delta_z = speed_motion;

  is_flip_axis_y = false;

  // chargement d'un modèle 3D
  teapot.loadModel("teapot.obj");

  // désactiver le matériau par défaut du modèle
  teapot.disableMaterials();

  // paramétrer la version des shaders en GLSL
  switch (gl_version_major)
  {
    case 3:
      shader_version = "330";
      break;

    default:
      shader_version = "120";
  }

  // charger, compiler et linker les sources des shaders
  shader_color_fill.load(
    "shader/color_fill_" + shader_version + "_vs.glsl",
    "shader/color_fill_" + shader_version + "_fs.glsl");

  shader_lambert.load(
    "shader/lambert_" + shader_version + "_vs.glsl",
    "shader/lambert_" + shader_version + "_fs.glsl");

  shader_gouraud.load(
    "shader/gouraud_" + shader_version + "_vs.glsl",
    "shader/gouraud_" + shader_version + "_fs.glsl");

  shader_phong.load(
    "shader/phong_" + shader_version + "_vs.glsl",
    "shader/phong_" + shader_version + "_fs.glsl");

  shader_blinn_phong.load(
    "shader/blinn_phong_" + shader_version + "_vs.glsl",
    "shader/blinn_phong_" + shader_version + "_fs.glsl");

  // shader actif au lancement de la scène
  shader_active = ShaderType::blinn_phong;

  // initialisation de la scène
  reset();
}

void Renderer::reset()
{
  // initialisation des variables
  framebuffer_width = ofGetWidth();
  framebuffer_height = ofGetHeight();

  // centre du framebuffer
  center_x = framebuffer_width / 2.0f;
  center_y = framebuffer_height / 2.0f;

  // caméra à sa position initiale
  offset_x = initial_x;
  offset_z = initial_y;

  // déterminer la position des géométries
  position_cube.set(-framebuffer_width * (1.0f / 4.0f), 0.0f, 0.0f);
  position_sphere.set(0.0f, 0.0f, 0.0f);
  position_teapot.set(framebuffer_width * (1.0f / 4.0f), 50.0f, 0.0f);

  ofLog() << "<reset>";
}

void Renderer::update()
{
  // transformer la lumière
  light.setGlobalPosition(
    ofMap(ofGetMouseX()/ (float) framebuffer_width, 0.0f, 1.0f, -framebuffer_width / 2.0f, framebuffer_width / 2.0f),
    ofMap(ofGetMouseY()/ (float) framebuffer_height, 0.0f, 1.0f, -framebuffer_height / 2.0f, framebuffer_height / 2.0f),
    -offset_z * 1.5f);

  // mise à jour d'une valeur numérique animée par un oscillateur
  float oscillation = oscillation_amplitude * std::sin(ofGetElapsedTimeMillis() * 2.0f * PI / oscillation_frequency) + oscillation_amplitude;

  // passer les attributs uniformes au shader de sommets
  switch (shader_active)
  {
    case ShaderType::color_fill:
      shader_name = "Color Fill";
      shader = shader_color_fill;
      shader.begin();
      shader.setUniform3f("color", 1.0f, 1.0f, 0.0f);
      shader.end();
      break;

    case ShaderType::lambert:
      shader_name = "Lambert";
      shader = shader_lambert;
      shader.begin();
      shader.setUniform3f("colorAmbient",  0.1f, 0.1f, 0.1f);
      shader.setUniform3f("colorDiffuse",  0.6f, 0.6f, 0.6f);
      shader.end();
      break;

    case ShaderType::gouraud:
      shader_name = "Gouraud";
      shader = shader_gouraud;
      shader.begin();
      shader.setUniform3f("colorAmbient",  0.1f, 0.1f, 0.1f);
      shader.setUniform3f("colorDiffuse",  0.6f, 0.6f, 0.0f);
      shader.setUniform3f("colorSpecular", 1.0f, 1.0f, 0.0f);
      shader.setUniform1f("brightness", oscillation);
      shader.end();
      break;

    case ShaderType::phong:
      shader_name = "Phong";
      shader = shader_phong;
      shader.begin();
      shader.setUniform3f("colorAmbient",  0.1f, 0.1f, 0.1f);
      shader.setUniform3f("colorDiffuse",  0.6f, 0.0f, 0.6f);
      shader.setUniform3f("colorSpecular", 1.0f, 1.0f, 0.0f);
      shader.setUniform1f("brightness", oscillation);
      shader.end();
      break;

    case ShaderType::blinn_phong:
      shader_name = "Blinn-Phong";
      shader = shader_blinn_phong;
      shader.begin();
      shader.setUniform3f("colorAmbient",  0.1f, 0.1f, 0.1f);
      shader.setUniform3f("colorDiffuse",  0.0f, 0.6f, 0.6f);
      shader.setUniform3f("colorSpecular", 1.0f, 1.0f, 0.0f);
      shader.setUniform1f("brightness", oscillation);
      shader.end();
      break;

    default:
      break;
  }
}

void Renderer::draw()
{
  // activer l'éclairage dynamique
  ofEnableLighting();

  // activer la lumière dynamique
  light.enable();

  ofPushMatrix();

    // inverser l'axe Y pour qu'il pointe vers le haut
    ofScale(1, is_flip_axis_y ? -1.0f : 1.0f);

    // transformer l'origine de la scène au milieu de la fenêtre d'affichage
    ofTranslate(center_x + offset_x, is_flip_axis_y ? -center_y : center_y, offset_z);

    ofPushMatrix();

      // positionnner le cube
      ofTranslate(
        position_cube.x,
        position_cube.y,
        position_cube.z);

      // rotation locale
      ofRotate(45.0f, 1.0f, 0.0f, 0.0f);

      // activer le shader
      shader.begin();

      // passer la position de la lumière au shader
      shader.setUniform3f("lightPosition", light.getGlobalPosition() * ofGetCurrentMatrix(OF_MATRIX_MODELVIEW));

      // dessiner un cube
      ofDrawBox(0.0f, 0.0f, 0.0f, scale_cube);

    ofPopMatrix();

    ofPushMatrix();

      // positionner la sphère
      ofTranslate(
        position_sphere.x,
        position_sphere.y,
        position_sphere.z);

      // passer la position de la lumière au shader
      shader.setUniform3f("lightPosition", light.getGlobalPosition() * ofGetCurrentMatrix(OF_MATRIX_MODELVIEW));

      // dessiner une sphère
      ofDrawSphere(0.0f, 0.0f, 0.0f, scale_sphere);

    ofPopMatrix();

    ofPushMatrix();

      // positionner le teapot
      teapot.setPosition(
        position_teapot.x,
        position_teapot.y + 15.0f, // un léger décalage pour l'alignement avec autres modèles
        position_teapot.z);

      // dimension du teapot
      teapot.setScale(
        scale_teapot,
        scale_teapot,
        scale_teapot);

      // passer la position de la lumière au shader
      shader.setUniform3f("lightPosition", light.getGlobalPosition() * ofGetCurrentMatrix(OF_MATRIX_MODELVIEW));

      // dessiner un teapot
      teapot.draw(OF_MESH_FILL);

    ofPopMatrix();

  ofPopMatrix();

  // désactiver le shader
  shader.end();

  // désactiver la lumière
  light.disable();

  // désactiver l'éclairage dynamique
  ofDisableLighting();
}
