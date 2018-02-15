// IFT3100H18_Teapot/renderer.h
// Classe responsable du rendu de l'application.

#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

enum class MeshRenderMode{fill, wireframe, vertex};

struct Locator
{
  float position[3];   // 3 * 4 = 12 octets
  float rotation[3];   // 3 * 4 = 12 octets
  float proportion[3]; // 3 * 4 = 12 octets
};                     //       = 36 octets

class Renderer
{
public:

  Locator* locators;

  ofxAssimpModelLoader teapot;

  ofLight light;

  ofNode node;

  ofVec3f vector_position;
  ofVec3f vector_rotation;
  ofVec3f vector_proportion;

  MeshRenderMode mesh_render_mode;

  float center_x;
  float center_y;

  float offset_x;
  float offset_z;

  float delta_x;
  float delta_z;

  float speed;

  int locator_count;

  int locator_buffer_size;
  int locator_buffer_head;

  int framebuffer_width;
  int framebuffer_height;

  bool is_flip_axis_y;

  bool is_active_translation;
  bool is_active_rotation;
  bool is_active_proportion;

  void setup();
  void reset();
  void draw();

  void dispatch_random_locator(int count, float range);

  void draw_locator(float scale);

  ~Renderer();
};
