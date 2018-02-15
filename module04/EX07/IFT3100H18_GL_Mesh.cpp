// IFT3100H18_Mesh.cpp
// Exemple d'une classe minimaliste pour stocker les données des sommets d'un maillage triangulaire.

// entrée
// • Une structure de sommet, une structure de triangle et données initiales du maillage triangulaire.
// sortie
// • Classe qui contient des triangles indexés par leurs sommets.

// déclarer la structure de sommet
struct VertexStructure
{
  GLfloat position[3]; // 3 * 4 = 12 octets
  GLfloat normal  [3]; // 3 * 4 = 12 octets
  GLfloat texcoord[2]; // 2 * 4 = 8  octets
  GLubyte color   [4]; // 4 * 1 = 4  octets
};                     //       = 36 octets

// structure d'un sommet
struct Vertex
{
  // structure interne d'un sommet
  VertexStructure vs;
};

// structure d'un triangle
struct Triangle
{
  // indices des 3 sommets
  int vertex_index[3];
};

// classe d'un maillage géométrique
class Mesh
{
  // nombre de sommets
  int vertex_count;

  // séquence des sommets
  Vertex* vertex_array;

  // nombre des triangles
  int triangle_count;

  // séquence des triangles
  Triangle* triangle_array;

  mesh()
  {
    // allocation d'une séquence de sommets
    vertex_array = (Vertex*) std::malloc(vertex_count * sizeof(Vertex));

    // allocation du tableau de triangles
    triangle_array = (Triangle*) std::malloc(triangle_count * sizeof(Triangle));

    // initialisation
    // ...
  }

  ~Mesh()
  {
    std::delete vertex_array;
    std::delete triangle_array;
  }
};
