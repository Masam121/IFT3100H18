// IFT3100H18_GL_ImageExport.cpp
// Exemple d'une section de code pour exporter une image à partir du contenu d'un framebuffer avec OpenGL.

// entrée
// • Identifiant du framebuffer à copier.
// sortie
// • Un fichier image qui contient une copie du contenu du framebuffer.

GLuint framebuffer = ...;

int image_width;
int image_height;
int image_component;
int image_pixel_count;
int image_size;

// 1. Extraction des propriétés du framebuffer

// sélectionner le framebuffer à échantillonner
glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);

// extraire les propriétés de largeur et de hauteur du framebuffer
glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_WIDTH,  &image_width);
glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_HEIGHT, &image_height);

// déterminer le nombre de composantes de couleur selon le format de l'image
image_component = 4; // 4 composantes de couleur pour du RGBA


// 2. allocation de l'espace mémoire pour les pixels de l'image

image_pixel_count = image_width * image_height;
image_size = image_pixel_count * image_component;
GLubyte* pixels = (GLubyte*) calloc(image_size, sizeof(GLubyte));


// 3. copier le contenu du framebuffer

// lire le contenu du framebuffer et copier les pixels en mémoire RAM
glReadPixels(0, 0, image_width, image_height, GL_RGBA, GL_UNSIGNED_BYTE, pixels);


// 4. sauvegarde dans un fichier image

// ouvrir un nouveau fichier image en mode écriture
// ...

// écrire les données de l'image dans le fichier image
// ...

// fermer le fichier image
// ...
