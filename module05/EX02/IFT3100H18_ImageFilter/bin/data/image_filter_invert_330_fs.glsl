// IFT3100H18 ~ image_filter_invert_330_fs.glsl

#version 330

// attributs uniformes
uniform sampler2D image;
uniform vec4 tint;

// attribut en entrée
in vec2 varyingTexcoord;

// attribut en sortie
out vec4 fragmentColor;

void main()
{
  // couleur après filtrage
  vec4 filteredColor;

  // échantillonner la texture
  vec4 textureSample = texture(image, varyingTexcoord);

  // inverser la valeur de chaque composante de couleur
  vec4 invertedColor;
  invertedColor.r = 1.0 - textureSample.r;
  invertedColor.g = 1.0 - textureSample.g;
  invertedColor.b = 1.0 - textureSample.b;
  invertedColor.a = textureSample.a;

  // mixage avec la teinte de couleur
  filteredColor = mix(invertedColor, tint, 0.5);

  // couleur finale du fragment
  fragmentColor = filteredColor;
}
