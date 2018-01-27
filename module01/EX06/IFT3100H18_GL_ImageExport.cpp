// IFT3100H18_GL_ImageExport.cpp
// Exemple d'une section de code pour exporter une image à partir du contenu d'un framebuffer avec OpenGL.

// entrée
// • L'identifiant unique du framebuffer à copier.
// sortie
// • Un fichier image qui contient une copie du contenu du framebuffer.

GLuint framebuffer = ...;

int image_width;
int image_height;
int image_component;
int image_pixel_count;
int image_size;

// déclarer un pointeur vers un espace mémoire qui servira à stocker les pixels de l'image
GLubyte* pixels;

// sélectionner le framebuffer à échantillonner
glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);

// extraire les propriétés de largeur et de hauteur du framebuffer
glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_WIDTH,  &image_width);
glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_HEIGHT, &image_height);

// déterminer le nombre de composantes de couleur selon le format de l'image
image_component = 4; // 4 composantes de couleur pour du RGBA

// calculer le nombre total de pixels de l'image
image_pixel_count = image_width * image_height;

// calculer le nombre total d'octets à allouer en mémoire pour contenir l'image
// (largeur x hauteur x nombre de composantes de couleurs)
image_size = image_pixel_count * image_component;

// allocation d'un espace mémoire pouvant contenir tous les pixels de l'image
pixels = (GLubyte*) calloc(image_size, sizeof(GLubyte));

// lire le contenu du framebuffer actif et copier les pixels en mémoire RAM
glReadPixels(0, 0, image_width, image_height, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

// ouvrir un nouveau fichier image en mode écriture
// ...

// écrire le contenu de l'image de la mémoire (RAM) vers le fichier
// ...

// fermer le fichier image
// ...
