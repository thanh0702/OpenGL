#include <GL/glut.h>
#include <cmath>
#include <cstdlib>
#include <iostream> 

// Camera and lighting variables
float angleX = 0.0f, angleY = 0.0f, cameraDistance = 3.0f;
float camX = 0.0f, camY = 2.5f, camZ = 8.0f;
// Light control variables (add these)
bool light0On = true; // GL_LIGHT0 (Spotlight)
bool light1On = true; // GL_LIGHT1
bool light2On = true; // GL_LIGHT2
bool light3On = true; // GL_LIGHT3
bool light4On = true; // GL_LIGHT4

// Spotlight (GL_LIGHT0) properties
GLfloat light0_pos[] = { 0.0f, 3.85f, 0.0f, 1.0f }; // Position (center of ceiling)
GLfloat light0_dir[] = { 0.0f, -1.0f, 0.0f };       // Default: downward direction
GLfloat light0_cutoff = 45.0f;                      // Spotlight cutoff angle (degrees)
GLfloat light0_exponent = 10.0f;                    // Spotlight exponent (focus)

// Control for light components (Ambient, Diffuse, Specular)
bool light1AmbientOn = true, light1DiffuseOn = true, light1SpecularOn = true; // GL_LIGHT1
bool light2AmbientOn = true, light2DiffuseOn = true, light2SpecularOn = true; // GL_LIGHT2
bool light3AmbientOn = true, light3DiffuseOn = true, light3SpecularOn = true; // GL_LIGHT3
bool light4AmbientOn = true, light4DiffuseOn = true, light4SpecularOn = true; // GL_LIGHT4





void initLighting() {
    // Light positions (matching lamp positions)
    GLfloat light1_pos[] = { 4.6f, 3.85f, 4.6f, 1.0f };       // Top-right corner
    GLfloat light2_pos[] = { 4.6f, 3.85f, -4.6f, 1.0f };      // Bottom-right corner
    GLfloat light3_pos[] = { -4.6f, 3.85f, 4.6f, 1.0f };      // Top-left corner
    GLfloat light4_pos[] = { -4.6f, 3.85f, -4.6f, 1.0f };     // Bottom-left corner

    // Light properties (increased intensity for spotlight)
    GLfloat diffuse_light[] = { 1.5f, 1.5f, 1.2f, 1.0f };     // Diffuse: brighter light yellow (increased from 1.0, 1.0, 0.8)
    GLfloat ambient_light[] = { 0.3f, 0.3f, 0.24f, 1.0f };    // Ambient: 20% of diffuse (increased from 0.2, 0.2, 0.16)
    GLfloat specular_light[] = { 1.2f, 1.2f, 1.2f, 1.0f };    // Specular: brighter white (increased from 1.0, 1.0, 1.0)
    GLfloat zero_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };        // Zero light for disabling components
    GLfloat global_ambient[] = { 0.3f, 0.3f, 0.3f, 1.0f };    // Global ambient light

    // Enable lighting
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

    // Light 0 (Spotlight at center)
    if (light0On) {
        glEnable(GL_LIGHT0);
        glLightfv(GL_LIGHT0, GL_POSITION, light0_pos); // Position of the spotlight
        glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light0_dir); // Direction of the spotlight
        glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, light0_cutoff); // Spotlight cutoff angle
        glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, light0_exponent); // Spotlight exponent
        glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
        glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
        glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0f);
        glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.1f);
        glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.01f);
    } else {
        glDisable(GL_LIGHT0);
    }

    // Light 1 (Top-right corner)
    if (light1On) {
        glEnable(GL_LIGHT1);
        glLightfv(GL_LIGHT1, GL_POSITION, light1_pos);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, light1DiffuseOn ? diffuse_light : zero_light);
        glLightfv(GL_LIGHT1, GL_AMBIENT, light1AmbientOn ? ambient_light : zero_light);
        glLightfv(GL_LIGHT1, GL_SPECULAR, light1SpecularOn ? specular_light : zero_light);
        glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0f);
        glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.1f);
        glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.01f);
    } else {
        glDisable(GL_LIGHT1);
    }

    // Light 2 (Bottom-right corner)
    if (light2On) {
        glEnable(GL_LIGHT2);
        glLightfv(GL_LIGHT2, GL_POSITION, light2_pos);
        glLightfv(GL_LIGHT2, GL_DIFFUSE, light2DiffuseOn ? diffuse_light : zero_light);
        glLightfv(GL_LIGHT2, GL_AMBIENT, light2AmbientOn ? ambient_light : zero_light);
        glLightfv(GL_LIGHT2, GL_SPECULAR, light2SpecularOn ? specular_light : zero_light);
        glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 1.0f);
        glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.1f);
        glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.01f);
    } else {
        glDisable(GL_LIGHT2);
    }

    // Light 3 (Top-left corner)
    if (light3On) {
        glEnable(GL_LIGHT3);
        glLightfv(GL_LIGHT3, GL_POSITION, light3_pos);
        glLightfv(GL_LIGHT3, GL_DIFFUSE, light3DiffuseOn ? diffuse_light : zero_light);
        glLightfv(GL_LIGHT3, GL_AMBIENT, light3AmbientOn ? ambient_light : zero_light);
        glLightfv(GL_LIGHT3, GL_SPECULAR, light3SpecularOn ? specular_light : zero_light);
        glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 1.0f);
        glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 0.1f);
        glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, 0.01f);
    } else {
        glDisable(GL_LIGHT3);
    }

    // Light 4 (Bottom-left corner)
    if (light4On) {
        glEnable(GL_LIGHT4);
        glLightfv(GL_LIGHT4, GL_POSITION, light4_pos);
        glLightfv(GL_LIGHT4, GL_DIFFUSE, light4DiffuseOn ? diffuse_light : zero_light);
        glLightfv(GL_LIGHT4, GL_AMBIENT, light4AmbientOn ? ambient_light : zero_light);
        glLightfv(GL_LIGHT4, GL_SPECULAR, light4SpecularOn ? specular_light : zero_light);
        glLightf(GL_LIGHT4, GL_CONSTANT_ATTENUATION, 1.0f);
        glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION, 0.1f);
        glLightf(GL_LIGHT4, GL_QUADRATIC_ATTENUATION, 0.01f);
    } else {
        glDisable(GL_LIGHT4);
    }
}


void setMaterial(float r, float g, float b, float alpha = 1.0f) {
    GLfloat mat_diffuse[] = { r, g, b, alpha };
    GLfloat mat_ambient[] = { r * 0.5f, g * 0.5f, b * 0.5f, alpha };
    GLfloat mat_specular[] = { 0.5f, 0.5f, 0.5f, alpha };
    GLfloat mat_shininess[] = { 50.0f };

    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void drawRoom() {
    // Floor (unchanged)
    setMaterial(0.6f, 0.4f, 0.2f);
    glBegin(GL_QUADS);
        glNormal3f(0, 1, 0);
        glVertex3f(-5, 0, -5);
        glVertex3f(5, 0, -5);
        glVertex3f(5, 0, 5);
        glVertex3f(-5, 0, 5);
    glEnd();

    // Ceiling (changed to light yellow)
    setMaterial(1.0f, 1.0f, 0.6f);
    glBegin(GL_QUADS);
        glNormal3f(0, -1, 0);
        glVertex3f(-5, 4, -5);
        glVertex3f(5, 4, -5);
        glVertex3f(5, 4, 5);
        glVertex3f(-5, 4, 5);
    glEnd();

    // Back Wall (z = -5, changed to light yellow)
    setMaterial(1.0f, 1.0f, 0.6f);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);
        glVertex3f(-5, 0, -5);
        glVertex3f(5, 0, -5);
        glVertex3f(5, 4, -5);
        glVertex3f(-5, 4, -5);
    glEnd();

    // Left Wall (x = -5, changed to light yellow)
    setMaterial(1.0f, 1.0f, 0.6f);
    glBegin(GL_QUADS);
        glNormal3f(1, 0, 0);
        glVertex3f(-5, 0, -5);
        glVertex3f(-5, 0, 5);
        glVertex3f(-5, 4, 5);
        glVertex3f(-5, 4, -5);
    glEnd();

  // Right Wall (x = 5, changed to a single quad like Left Wall, light yellow)
setMaterial(1.0f, 1.0f, 0.6f);
glBegin(GL_QUADS);
    glNormal3f(-1, 0, 0); // Normal pointing into the room (negative x direction)
    glVertex3f(5, 0, -5);
    glVertex3f(5, 0, 5);
    glVertex3f(5, 4, 5);
    glVertex3f(5, 4, -5);
glEnd();


    
    

  // Window on Right Wall with cross design (four panes), piercing through the wall
setMaterial(0.5f, 0.7f, 0.9f, 0.7f);
glBegin(GL_QUADS);
    glNormal3f(-1, 0, 0);
    glVertex3f(4.9f, 2.25, -1.5);  // From z=0.5
    glVertex3f(4.9f, 2.25, 0.46);  // From z=2.46
    glVertex3f(4.9f, 3.1, 0.46);
    glVertex3f(4.9f, 3.1, -1.5);
    glVertex3f(4.9f, 2.25, 0.51);  // From z=2.51
    glVertex3f(4.9f, 2.25, 2.42);  // From z=4.42
    glVertex3f(4.9f, 3.1, 2.42);
    glVertex3f(4.9f, 3.1, 0.51);
    glVertex3f(4.9f, 1.3, -1.5);
    glVertex3f(4.9f, 1.3, 0.46);
    glVertex3f(4.9f, 2.15, 0.46);
    glVertex3f(4.9f, 2.15, -1.5);
    glVertex3f(4.9f, 1.3, 0.51);
    glVertex3f(4.9f, 1.3, 2.42);
    glVertex3f(4.9f, 2.15, 2.42);
    glVertex3f(4.9f, 2.15, 0.51);
    glNormal3f(1, 0, 0);
    glVertex3f(5.1f, 3.1, -1.5);
    glVertex3f(5.1f, 3.1, 0.46);
    glVertex3f(5.1f, 2.25, 0.46);
    glVertex3f(5.1f, 2.25, -1.5);
    glVertex3f(5.1f, 3.1, 0.51);
    glVertex3f(5.1f, 3.1, 2.42);
    glVertex3f(5.1f, 2.25, 2.42);
    glVertex3f(5.1f, 2.25, 0.51);
    glVertex3f(5.1f, 2.15, -1.5);
    glVertex3f(5.1f, 2.15, 0.46);
    glVertex3f(5.1f, 1.3, 0.46);
    glVertex3f(5.1f, 1.3, -1.5);
    glVertex3f(5.1f, 2.15, 0.51);
    glVertex3f(5.1f, 2.15, 2.42);
    glVertex3f(5.1f, 1.3, 2.42);
    glVertex3f(5.1f, 1.3, 0.51);
    glNormal3f(0, 0, -1);
    glVertex3f(4.9f, 2.25, -1.5);
    glVertex3f(5.1f, 2.25, -1.5);
    glVertex3f(5.1f, 3.1, -1.5);
    glVertex3f(4.9f, 3.1, -1.5);
    glNormal3f(0, 0, 1);
    glVertex3f(4.9f, 2.25, 0.46);
    glVertex3f(5.1f, 2.25, 0.46);
    glVertex3f(5.1f, 3.1, 0.46);
    glVertex3f(4.9f, 3.1, 0.46);
    glNormal3f(0, 1, 0);
    glVertex3f(4.9f, 3.1, -1.5);
    glVertex3f(5.1f, 3.1, -1.5);
    glVertex3f(5.1f, 3.1, 0.46);
    glVertex3f(4.9f, 3.1, 0.46);
    glNormal3f(0, -1, 0);
    glVertex3f(4.9f, 2.25, -1.5);
    glVertex3f(5.1f, 2.25, -1.5);
    glVertex3f(5.1f, 2.25, 0.46);
    glVertex3f(4.9f, 2.25, 0.46);
    glNormal3f(0, 0, -1);
    glVertex3f(4.9f, 2.25, 0.51);
    glVertex3f(5.1f, 2.25, 0.51);
    glVertex3f(5.1f, 3.1, 0.51);
    glVertex3f(4.9f, 3.1, 0.51);
    glNormal3f(0, 0, 1);
    glVertex3f(4.9f, 2.25, 2.42);
    glVertex3f(5.1f, 2.25, 2.42);
    glVertex3f(5.1f, 3.1, 2.42);
    glVertex3f(4.9f, 3.1, 2.42);
    glNormal3f(0, 1, 0);
    glVertex3f(4.9f, 3.1, 0.51);
    glVertex3f(5.1f, 3.1, 0.51);
    glVertex3f(5.1f, 3.1, 2.42);
    glVertex3f(4.9f, 3.1, 2.42);
    glNormal3f(0, -1, 0);
    glVertex3f(4.9f, 2.25, 0.51);
    glVertex3f(5.1f, 2.25, 0.51);
    glVertex3f(5.1f, 2.25, 2.42);
    glVertex3f(4.9f, 2.25, 2.42);
    glNormal3f(0, 0, -1);
    glVertex3f(4.9f, 1.3, -1.5);
    glVertex3f(5.1f, 1.3, -1.5);
    glVertex3f(5.1f, 2.15, -1.5);
    glVertex3f(4.9f, 2.15, -1.5);
    glNormal3f(0, 0, 1);
    glVertex3f(4.9f, 1.3, 0.46);
    glVertex3f(5.1f, 1.3, 0.46);
    glVertex3f(5.1f, 2.15, 0.46);
    glVertex3f(4.9f, 2.15, 0.46);
    glNormal3f(0, 1, 0);
    glVertex3f(4.9f, 2.15, -1.5);
    glVertex3f(5.1f, 2.15, -1.5);
    glVertex3f(5.1f, 2.15, 0.46);
    glVertex3f(4.9f, 2.15, 0.46);
    glNormal3f(0, -1, 0);
    glVertex3f(4.9f, 1.3, -1.5);
    glVertex3f(5.1f, 1.3, -1.5);
    glVertex3f(5.1f, 1.3, 0.46);
    glVertex3f(4.9f, 1.3, 0.46);
    glNormal3f(0, 0, -1);
    glVertex3f(4.9f, 1.3, 0.51);
    glVertex3f(5.1f, 1.3, 0.51);
    glVertex3f(5.1f, 2.15, 0.51);
    glVertex3f(4.9f, 2.15, 0.51);
    glNormal3f(0, 0, 1);
    glVertex3f(4.9f, 1.3, 2.42);
    glVertex3f(5.1f, 1.3, 2.42);
    glVertex3f(5.1f, 2.15, 2.42);
    glVertex3f(4.9f, 2.15, 2.42);
    glNormal3f(0, 1, 0);
    glVertex3f(4.9f, 2.15, 0.51);
    glVertex3f(5.1f, 2.15, 0.51);
    glVertex3f(5.1f, 2.15, 2.42);
    glVertex3f(4.9f, 2.15, 2.42);
    glNormal3f(0, -1, 0);
    glVertex3f(4.9f, 1.3, 0.51);
    glVertex3f(5.1f, 1.3, 0.51);
    glVertex3f(5.1f, 1.3, 2.42);
    glVertex3f(4.9f, 1.3, 2.42);
glEnd();

// Draw the crossbars for Window
setMaterial(0.3f, 0.3f, 0.3f, 1.0f);
glBegin(GL_QUADS);
    glNormal3f(-1, 0, 0);
    glVertex3f(4.9f, 1.3, 0.41);  // From z=2.41
    glVertex3f(4.9f, 1.3, 0.51);  // From z=2.51
    glVertex3f(4.9f, 3.1, 0.51);
    glVertex3f(4.9f, 3.1, 0.41);
    glVertex3f(4.9f, 2.15, -1.5);  // From z=0.5
    glVertex3f(4.9f, 2.15, 2.42);  // From z=4.42
    glVertex3f(4.9f, 2.25, 2.42);
    glVertex3f(4.9f, 2.25, -1.5);
    glNormal3f(1, 0, 0);
    glVertex3f(5.1f, 3.1, 0.41);
    glVertex3f(5.1f, 3.1, 0.51);
    glVertex3f(5.1f, 1.3, 0.51);
    glVertex3f(5.1f, 1.3, 0.41);
    glVertex3f(5.1f, 2.25, -1.5);
    glVertex3f(5.1f, 2.25, 2.42);
    glVertex3f(5.1f, 2.15, 2.42);
    glVertex3f(5.1f, 2.15, -1.5);
    glNormal3f(0, 0, -1);
    glVertex3f(4.9f, 1.3, 0.41);
    glVertex3f(5.1f, 1.3, 0.41);
    glVertex3f(5.1f, 3.1, 0.41);
    glVertex3f(4.9f, 3.1, 0.41);
    glNormal3f(0, 0, 1);
    glVertex3f(4.9f, 1.3, 0.51);
    glVertex3f(5.1f, 1.3, 0.51);
    glVertex3f(5.1f, 3.1, 0.51);
    glVertex3f(4.9f, 3.1, 0.51);
    glNormal3f(0, 1, 0);
    glVertex3f(4.9f, 3.1, 0.41);
    glVertex3f(5.1f, 3.1, 0.41);
    glVertex3f(5.1f, 3.1, 0.51);
    glVertex3f(4.9f, 3.1, 0.51);
    glNormal3f(0, -1, 0);
    glVertex3f(4.9f, 1.3, 0.41);
    glVertex3f(5.1f, 1.3, 0.41);
    glVertex3f(5.1f, 1.3, 0.51);
    glVertex3f(4.9f, 1.3, 0.51);
    glNormal3f(0, 0, -1);
    glVertex3f(4.9f, 2.15, -1.5);
    glVertex3f(5.1f, 2.15, -1.5);
    glVertex3f(5.1f, 2.25, -1.5);
    glVertex3f(4.9f, 2.25, -1.5);
    glNormal3f(0, 0, 1);
    glVertex3f(4.9f, 2.15, 2.42);
    glVertex3f(5.1f, 2.15, 2.42);
    glVertex3f(5.1f, 2.25, 2.42);
    glVertex3f(4.9f, 2.25, 2.42);
    glNormal3f(0, 1, 0);
    glVertex3f(4.9f, 2.25, -1.5);
    glVertex3f(5.1f, 2.25, -1.5);
    glVertex3f(5.1f, 2.25, 2.42);
    glVertex3f(4.9f, 2.25, 2.42);
    glNormal3f(0, -1, 0);
    glVertex3f(4.9f, 2.15, -1.5);
    glVertex3f(5.1f, 2.15, -1.5);
    glVertex3f(5.1f, 2.15, 2.42);
    glVertex3f(4.9f, 2.15, 2.42);
glEnd();

// Draw the frame for Window as a solid rectangle 
setMaterial(0.3f, 0.3f, 0.3f, 1.0f);
glBegin(GL_QUADS);
    glNormal3f(-1, 0, 0);
    glVertex3f(4.9f, 3.1, -1.65);  // From z=0.35
    glVertex3f(4.9f, 3.1, 2.57);   // From z=4.57
    glVertex3f(4.9f, 3.25, 2.57);
    glVertex3f(4.9f, 3.25, -1.65);
    glVertex3f(4.9f, 1.15, -1.65);
    glVertex3f(4.9f, 1.15, 2.57);
    glVertex3f(4.9f, 1.3, 2.57);
    glVertex3f(4.9f, 1.3, -1.65);
    glVertex3f(4.9f, 1.15, -1.65);
    glVertex3f(4.9f, 1.15, -1.5);
    glVertex3f(4.9f, 3.25, -1.5);
    glVertex3f(4.9f, 3.25, -1.65);
    glVertex3f(4.9f, 1.15, 2.42);
    glVertex3f(4.9f, 1.15, 2.57);
    glVertex3f(4.9f, 3.25, 2.57);
    glVertex3f(4.9f, 3.25, 2.42);
    glNormal3f(1, 0, 0);
    glVertex3f(5.1f, 3.25, -1.65);
    glVertex3f(5.1f, 3.25, 2.57);
    glVertex3f(5.1f, 3.1, 2.57);
    glVertex3f(5.1f, 3.1, -1.65);
    glVertex3f(5.1f, 1.3, -1.65);
    glVertex3f(5.1f, 1.3, 2.57);
    glVertex3f(5.1f, 1.15, 2.57);
    glVertex3f(5.1f, 1.15, -1.65);
    glVertex3f(5.1f, 3.25, -1.65);
    glVertex3f(5.1f, 3.25, -1.5);
    glVertex3f(5.1f, 1.15, -1.5);
    glVertex3f(5.1f, 1.15, -1.65);
    glVertex3f(5.1f, 3.25, 2.42);
    glVertex3f(5.1f, 3.25, 2.57);
    glVertex3f(5.1f, 1.15, 2.57);
    glVertex3f(5.1f, 1.15, 2.42);
    glNormal3f(0, 0, -1);
    glVertex3f(4.9f, 1.15, -1.65);
    glVertex3f(5.1f, 1.15, -1.65);
    glVertex3f(5.1f, 3.25, -1.65);
    glVertex3f(4.9f, 3.25, -1.65);
    glNormal3f(0, 0, 1);
    glVertex3f(4.9f, 1.15, 2.57);
    glVertex3f(5.1f, 1.15, 2.57);
    glVertex3f(5.1f, 3.25, 2.57);
    glVertex3f(4.9f, 3.25, 2.57);
    glNormal3f(0, 1, 0);
    glVertex3f(4.9f, 3.25, -1.65);
    glVertex3f(5.1f, 3.25, -1.65);
    glVertex3f(5.1f, 3.25, 2.57);
    glVertex3f(4.9f, 3.25, 2.57);
    glNormal3f(0, -1, 0);
    glVertex3f(4.9f, 1.15, -1.65);
    glVertex3f(5.1f, 1.15, -1.65);
    glVertex3f(5.1f, 1.15, 2.57);
    glVertex3f(4.9f, 1.15, 2.57);
    glNormal3f(0, 0, 1);
    glVertex3f(4.9f, 1.3, -1.5);
    glVertex3f(5.1f, 1.3, -1.5);
    glVertex3f(5.1f, 3.1, -1.5);
    glVertex3f(4.9f, 3.1, -1.5);
    glNormal3f(0, 0, -1);
    glVertex3f(4.9f, 1.3, 2.42);
    glVertex3f(5.1f, 1.3, 2.42);
    glVertex3f(5.1f, 3.1, 2.42);
    glVertex3f(4.9f, 3.1, 2.42);
    glNormal3f(0, -1, 0);
    glVertex3f(4.9f, 3.1, -1.5);
    glVertex3f(5.1f, 3.1, -1.5);
    glVertex3f(5.1f, 3.1, 2.42);
    glVertex3f(4.9f, 3.1, 2.42);
    glNormal3f(0, 1, 0);
    glVertex3f(4.9f, 1.3, -1.5);
    glVertex3f(5.1f, 1.3, -1.5);
    glVertex3f(5.1f, 1.3, 2.42);
    glVertex3f(4.9f, 1.3, 2.42);
glEnd();
   


}

void dongho() {
	// Wall Clock on Right Wall (centered at x = 2.79, y = 3.5, z = 0)

    const float clockRadius = 0.4f; // Radius of the clock face
    const float frameThickness = 0.05f; // Thickness of the frame
    const float clockDepth = 0.03f; // Depth of the clock face
    const int segments = 64; // Number of segments for smooth circle
    const float PI = 3.14159265359f;
    const float minuteAngle = -30.0f; // Fixed at 30 degrees (e.g., pointing at 6)
    const float secondAngle = -90.0f; // Fixed at 90 degrees (e.g., pointing at 3)

    glPushMatrix();
    glTranslatef(-4.95f, 3.0f, 3.95f); // Center of the clock, 2.21 units from right wall (x = 5)
    glRotatef(90.0f, 0, 1, 0); // Rotate 90 degrees around y-axis to face into room (normal along -x)
    glRotatef(45.0f, 0, 0, 1); // Rotate clock 45 degrees counterclockwise around local z-axis

    // Clock Frame (black torus, aligned with clock face)
    setMaterial(0.1f, 0.1f, 0.1f, 1.0f); // Black
    glPushMatrix();
    // No additional rotation; torus is in xy-plane after transformations
    glutSolidTorus(frameThickness / 2, clockRadius + frameThickness / 2, 16, segments); // Adjusted outer radius
    glPopMatrix();

    // Clock Face (white, circular, solid)
    setMaterial(1.0f, 1.0f, 1.0f, 1.0f); // White
    glBegin(GL_TRIANGLE_FAN); // Solid circular face
    glNormal3f(1, 0, 0); // Normal facing into room (along -x)
    glVertex3f(0.0f, 0.0f, 0.0f); // Center of the front face
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * PI * i / segments;
        float x = clockRadius * cosf(angle);
        float y = clockRadius * sinf(angle);
        glVertex3f(x, y, 0.0f); // Front face vertices
    }
    glEnd();

    // Clock Face Back (optional, to close the solid)
    glBegin(GL_TRIANGLE_FAN);
    glNormal3f(-1, 0, 0); // Normal facing toward wall (along +x)
    glVertex3f(0.0f, 0.0f, -clockDepth); // Center of the back face
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * PI * (segments - i) / segments; // Reverse order
        float x = clockRadius * cosf(angle);
        float y = clockRadius * sinf(angle);
        glVertex3f(x, y, -clockDepth); // Back face vertices
    }
    glEnd();

    // Clock Face Side (to make it a solid cylinder)
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * PI * i / segments;
        float x = clockRadius * cosf(angle);
        float y = clockRadius * sinf(angle);
        glNormal3f(cosf(angle), sinf(angle), 0); // Normal pointing outward radially
        glVertex3f(x, y, 0.0f); // Front edge
        glVertex3f(x, y, -clockDepth); // Back edge
    }
    glEnd();

    // Minute Hand (black, 0.8 * clockRadius long, 0.02 wide)
    setMaterial(0.1f, 0.1f, 0.1f, 1.0f); // Black
    glPushMatrix();
    glRotatef(minuteAngle, 0, 0, 1); // Fixed rotation
    glBegin(GL_QUADS);
    glNormal3f(-1, 0, 0); // Normal facing into room
    glVertex3f(-0.01f, 0.0f, 0.01f); // Slightly above face
    glVertex3f(0.01f, 0.0f, 0.01f);
    glVertex3f(0.01f, 0.8f * clockRadius, 0.01f);
    glVertex3f(-0.01f, 0.8f * clockRadius, 0.01f);
    glEnd();
    glPopMatrix();

    // Second Hand (black, 0.9 * clockRadius long, 0.01 wide)
    glPushMatrix();
    glRotatef(secondAngle, 0, 0, 1); // Fixed rotation
    glBegin(GL_QUADS);
    glNormal3f(-1, 0, 0); // Normal facing into room
    glVertex3f(-0.005f, 0.0f, 0.02f); // Slightly above minute hand
    glVertex3f(0.005f, 0.0f, 0.02f);
    glVertex3f(0.005f, 0.9f * clockRadius, 0.02f);
    glVertex3f(-0.005f, 0.9f * clockRadius, 0.02f);
    glEnd();
    glPopMatrix();

    glPopMatrix();

}

void tranhtreotuong() {
	 // Painting 3 on Front Wall (z = 5, right of the door), moved inside, adjusted height, and rotated
glPushMatrix();
glTranslatef(4.95f, 2.5f, 3.99f);  // Di chuy?n g?c đ?n tâm tranh (gi?a x=3 và 4, y=2 và 3)
glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // Xoay 30 đ? quanh tr?c Y
glTranslatef(-3.5f, -2.5f, -4.99f); // D?ch ngư?c l?i đ? v? t? góc dư?i trái

// Main painting surface (x = 3 to 4, y = 2 to 3, z = 4.99)
setMaterial(1.0f, 1.0f, 1.0f, 1.0f); // White
glBegin(GL_QUADS);
    glNormal3f(0, 0, -1);
    glVertex3f(3.0f, 2.0f, 4.99f);
    glVertex3f(4.0f, 2.0f, 4.99f);
    glVertex3f(4.0f, 3.0f, 4.99f);
    glVertex3f(3.0f, 3.0f, 4.99f);
glEnd();

// Frame for Painting 3 (0.05 units thick, dark gray)
setMaterial(0.2f, 0.2f, 0.2f, 1.0f);
glBegin(GL_QUADS);
    glNormal3f(0, 0, -1);
    // Top frame
    glVertex3f(2.95f, 3.0f, 4.99f);
    glVertex3f(4.05f, 3.0f, 4.99f);
    glVertex3f(4.05f, 3.05f, 4.99f);
    glVertex3f(2.95f, 3.05f, 4.99f);
    // Bottom frame
    glVertex3f(2.95f, 1.95f, 4.99f);
    glVertex3f(4.05f, 1.95f, 4.99f);
    glVertex3f(4.05f, 2.0f, 4.99f);
    glVertex3f(2.95f, 2.0f, 4.99f);
    // Left frame
    glVertex3f(2.95f, 1.95f, 4.99f);
    glVertex3f(3.0f, 1.95f, 4.99f);
    glVertex3f(3.0f, 3.05f, 4.99f);
    glVertex3f(2.95f, 3.05f, 4.99f);
    // Right frame
    glVertex3f(4.0f, 1.95f, 4.99f);
    glVertex3f(4.05f, 1.95f, 4.99f);
    glVertex3f(4.05f, 3.05f, 4.99f);
    glVertex3f(4.0f, 3.05f, 4.99f);
glEnd();

glPopMatrix();


// Painting 2 on Left Wall (x = -5, shifted left by 1 unit, shifted up by 0.5 units)
// Main painting surface (z = -2.5 to 2.5, y = 1.5 to 3.5, x = -4.99)
setMaterial(1.0f, 1.0f, 1.0f, 1.0f); // White
glBegin(GL_QUADS);
    glNormal3f(1, 0, 0);
    glVertex3f(-4.99f, 1.5f, -2.5f);
    glVertex3f(-4.99f, 1.5f, 2.5f);
    glVertex3f(-4.99f, 3.5f, 2.5f);
    glVertex3f(-4.99f, 3.5f, -2.5f);
glEnd();

// Frame for Painting 2 (0.05 units thick, dark gray)
setMaterial(0.2f, 0.2f, 0.2f, 1.0f);
glBegin(GL_QUADS);
    glNormal3f(1, 0, 0);
    // Top frame (y = 3.5 to 3.55, z = -2.55 to 2.55)
    glVertex3f(-4.99f, 3.5f, -2.55f);
    glVertex3f(-4.99f, 3.5f, 2.55f);
    glVertex3f(-4.99f, 3.55f, 2.55f);
    glVertex3f(-4.99f, 3.55f, -2.55f);
    // Bottom frame (y = 1.45 to 1.5, z = -2.55 to 2.55)
    glVertex3f(-4.99f, 1.45f, -2.55f);
    glVertex3f(-4.99f, 1.45f, 2.55f);
    glVertex3f(-4.99f, 1.5f, 2.55f);
    glVertex3f(-4.99f, 1.5f, -2.55f);
    // Left frame (z = -2.55 to -2.5, y = 1.45 to 3.55)
    glVertex3f(-4.99f, 1.45f, -2.55f);
    glVertex3f(-4.99f, 1.45f, -2.5f);
    glVertex3f(-4.99f, 3.55f, -2.5f);
    glVertex3f(-4.99f, 3.55f, -2.55f);
    // Right frame (z = 2.5 to 2.55, y = 1.45 to 3.55)
    glVertex3f(-4.99f, 1.45f, 2.5f);
    glVertex3f(-4.99f, 1.45f, 2.55f);
    glVertex3f(-4.99f, 3.55f, 2.55f);
    glVertex3f(-4.99f, 3.55f, 2.5f);
glEnd();
}

void dentran() {
	// Ceiling Lamp at the center of the ceiling (x = 0, z = 0, y = 3.9, hanging down to 3.7)
setMaterial(1.0f, 1.0f, 0.8f, 1.0f); // Light yellow to simulate a glowing light

const float radius = 0.3f; // Radius of the circular lamp
const float height_top = 3.99f; // Top of the lamp (attached to ceiling)
const float height_bottom = 3.99f; // Bottom of the lamp
const int segments = 32; // Number of segments for smooth circle approximation
const float PI = 3.14159265359f;

glBegin(GL_TRIANGLE_FAN); // Bottom face (y = 3.7, facing downward)
glNormal3f(0, -1, 0); // Normal pointing downward
glVertex3f(0.0f, height_bottom, 0.0f); // Center of the bottom face
for (int i = 0; i <= segments; i++) {
    float angle = 2.0f * PI * i / segments;
    glVertex3f(radius * cosf(angle), height_bottom, radius * sinf(angle));
}
glEnd();

glBegin(GL_TRIANGLE_FAN); // Top face (y = 3.9, attached to the ceiling)
glNormal3f(0, 1, 0); // Normal pointing upward
glVertex3f(0.0f, height_top, 0.0f); // Center of the top face
for (int i = 0; i <= segments; i++) {
    float angle = 2.0f * PI * i / segments;
    glVertex3f(radius * cosf(angle), height_top, radius * sinf(angle));
}
glEnd();

glBegin(GL_QUAD_STRIP); // Side surface (curved surface connecting top and bottom)
for (int i = 0; i <= segments; i++) {
    float angle = 2.0f * PI * i / segments;
    float x = radius * cosf(angle);
    float z = radius * sinf(angle);
    // Compute normal for the side (pointing outward radially)
    glNormal3f(cosf(angle), 0, sinf(angle));
    // Vertices for top and bottom edges
    glVertex3f(x, height_top, z);
    glVertex3f(x, height_bottom, z);
}
glEnd();

  // Four Corner Ceiling Lamps
    float cornerPositions[4][2] = {
        {4.6f, 4.6f},   // Top-right corner
        {4.6f, -4.6f},  // Bottom-right corner
        {-4.6f, 4.6f},  // Top-left corner
        {-4.6f, -4.6f}  // Bottom-left corner
    };

    for (int i = 0; i < 4; i++) {
        glPushMatrix();
        glTranslatef(cornerPositions[i][0], 0.0f, cornerPositions[i][1]); // Apply translation for each corner

        glBegin(GL_TRIANGLE_FAN); // Bottom face
        glNormal3f(0, -1, 0);
        glVertex3f(0.0f, height_bottom, 0.0f);
        for (int j = 0; j <= segments; j++) {
            float angle = 2.0f * PI * j / segments;
            glVertex3f(radius * cosf(angle), height_bottom, radius * sinf(angle));
        }
        glEnd();

        glBegin(GL_TRIANGLE_FAN); // Top face
        glNormal3f(0, 1, 0);
        glVertex3f(0.0f, height_top, 0.0f);
        for (int j = 0; j <= segments; j++) {
            float angle = 2.0f * PI * j / segments;
            glVertex3f(radius * cosf(angle), height_top, radius * sinf(angle));
        }
        glEnd();

        glBegin(GL_QUAD_STRIP); // Side surface
        for (int j = 0; j <= segments; j++) {
            float angle = 2.0f * PI * j / segments;
            float x = radius * cosf(angle);
            float z = radius * sinf(angle);
            glNormal3f(cosf(angle), 0, sinf(angle));
            glVertex3f(x, height_top, z);
            glVertex3f(x, height_bottom, z);
        }
        glEnd();

        glPopMatrix();
    }

}


void tuhosonho() {
	// ---------------- Small Cabinet with Drawers ----------------
// Main Body
glPushMatrix();
glTranslatef(1.5f, 0.35f, 0.0f);
glScalef(0.6f, 0.7f, 0.5f);
setMaterial(0.5f, 0.3f, 0.2f);
glutSolidCube(1);
glPopMatrix();
// Drawers (2 stacked vertically)
for (int i = 0; i < 2; i++) {
    float yPos = 0.25f + i * 0.25f;
    // M?t ngăn kéo
    glPushMatrix();
    glTranslatef(1.5f, yPos, -0.25f);
    glScalef(0.55f, 0.15f, 0.02f);
    setMaterial(0.45f, 0.25f, 0.15f);
    glutSolidCube(1);
    glPopMatrix();
    // Vi?n
    float w = 0.55f, h = 0.15f, d = 0.021f, border = 0.01f;
    setMaterial(0.3f, 0.15f, 0.1f);
    // Vi?n trái
    glPushMatrix();
    glTranslatef(1.5f - (w / 2 - border / 2), yPos, -0.25f);
    glScalef(border, h, d);
    glutSolidCube(1);
    glPopMatrix();
    // Vi?n ph?i
    glPushMatrix();
    glTranslatef(1.5f + (w / 2 - border / 2), yPos, -0.25f);
    glScalef(border, h, d);
    glutSolidCube(1);
    glPopMatrix();
    // Vi?n trên
    glPushMatrix();
    glTranslatef(1.5f, yPos + (h / 2 - border / 2), -0.25f);
    glScalef(w, border, d);
    glutSolidCube(1);
    glPopMatrix();
    // Vi?n dư?i
    glPushMatrix();
    glTranslatef(1.5f, yPos - (h / 2 - border / 2), -0.25f);
    glScalef(w, border, d);
    glutSolidCube(1);
    glPopMatrix();
    // Tay n?m
    setMaterial(0.1f, 0.1f, 0.1f);
    float knobOffset = 0.1f;
    float knobRadius = 0.015f;
    // Tay n?m trái
    glPushMatrix();
    glTranslatef(1.5f - knobOffset, yPos, -0.28f);
    glutSolidSphere(knobRadius, 20, 20);
    glPopMatrix();
    // Tay n?m ph?i
    glPushMatrix();
    glTranslatef(1.5f + knobOffset, yPos, -0.28f);
    glutSolidSphere(knobRadius, 20, 20);
    glPopMatrix();
}
// Vi?n chân và n?p t?
setMaterial(0.35f, 0.17f, 0.1f);
float bodyW = 0.6f, bodyH = 0.7f, bodyD = 0.5f;
// Vi?n dư?i
glPushMatrix();
glTranslatef(1.5f, 0.0f, 0.0f);
glScalef(bodyW, 0.02f, bodyD);
glutSolidCube(1);
glPopMatrix();
// Vi?n trên
glPushMatrix();
glTranslatef(1.5f, 0.70f, 0.0f);
glScalef(bodyW, 0.02f, bodyD);
glutSolidCube(1);
glPopMatrix();
}

void tuhosogo() {
	// T?A Đ? G?C C?A T?
float closetX = 4.39f;
float closetY = 1.01f;
float closetZ = -4.60f;

// ----------- THÂN Tu -----------
glPushMatrix();
glTranslatef(closetX, closetY, closetZ); // v? trí trung tâm t?
glScalef(1.2f, 2.0f, 0.6f); // chi?u r?ng, cao, sâu
setMaterial(0.3f, 0.15f, 0.1f); // màu nâu đ?m
glutSolidCube(1.0f);
glPopMatrix();// ----------- CÁNH Tu TRÁI -----------
glPushMatrix();
glTranslatef(closetX - 0.3f, closetY + 0.25f, closetZ + 0.31f);
glScalef(0.58f, 1.4f, 0.02f);
setMaterial(0.35f, 0.2f, 0.1f);
glutSolidCube(1.0f);
glPopMatrix();// ----------- CÁNH Tu PH?I -----------
glPushMatrix();
glTranslatef(closetX + 0.3f, closetY + 0.25f, closetZ + 0.31f);
glScalef(0.58f, 1.4f, 0.02f);
setMaterial(0.35f, 0.2f, 0.1f);
glutSolidCube(1.0f);
glPopMatrix();// ----------- TAY NaM CÁNH Tu -----------
for (float x = -0.3f; x <= 0.3f; x += 0.6f) {
    glPushMatrix();
    glTranslatef(closetX + x, closetY + 0.1f, closetZ + 0.35f);
    glScalef(0.03f, 0.03f, 0.03f);
    setMaterial(0.1f, 0.1f, 0.1f);
    glutSolidSphere(1.0f, 16, 16);
    glPopMatrix();
}// ----------- NGĂN KÉO DƯ?I (2 cái) -----------
for (int i = 0; i < 2; i++) {
    glPushMatrix();
    glTranslatef(closetX, closetY - 0.60f + i * -0.25f, closetZ + 0.31f);
    glScalef(1.1f, 0.2f, 0.02f);
    setMaterial(0.35f, 0.2f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

// tay n?m ngăn kéo
glPushMatrix();
glTranslatef(closetX, closetY - 0.6f + i * -0.25f, closetZ + 0.34f);
glScalef(0.3f, 0.03f, 0.02f);
setMaterial(0.1f, 0.1f, 0.1f);
glutSolidCube(1.0f);
glPopMatrix();

}
}

void tusach() {
// Bookshelf on Back Wall near the Cabinet
setMaterial(0.3f, 0.15f, 0.1f); // màu nâu đ?m
glBegin(GL_QUADS);
    // Back face (z = -4.99) - unchanged
    glNormal3f(0, 0, -1);
    glVertex3f(0.5f, 0.01f, -4.99f);
    glVertex3f(0.5f, 2.51f, -4.99f);
    glVertex3f(2.5f, 2.51f, -4.99f);
    glVertex3f(2.5f, 0.01f, -4.99f);

    // Left face (outer at x = 0.5, inner at x = 0.6)
    glNormal3f(-1, 0, 0); // Outer face (x = 0.5)
    glVertex3f(0.5f, 0.01f, -4.99f);
    glVertex3f(0.5f, 0.01f, -4.36f); // Depth adjusted to -4.36
    glVertex3f(0.5f, 2.51f, -4.36f);
    glVertex3f(0.5f, 2.51f, -4.99f);
    glNormal3f(1, 0, 0); // Inner face (x = 0.6)
    glVertex3f(0.6f, 0.01f, -4.99f);
    glVertex3f(0.6f, 2.51f, -4.99f);
    glVertex3f(0.6f, 2.51f, -4.36f);
    glVertex3f(0.6f, 0.01f, -4.36f);
    glNormal3f(0, 1, 0); // Top edge of left face
    glVertex3f(0.5f, 2.51f, -4.99f);
    glVertex3f(0.5f, 2.51f, -4.36f);
    glVertex3f(0.6f, 2.51f, -4.36f);
    glVertex3f(0.6f, 2.51f, -4.99f);
    glNormal3f(0, -1, 0); // Bottom edge of left face
    glVertex3f(0.5f, 0.01f, -4.99f);
    glVertex3f(0.6f, 0.01f, -4.99f);
    glVertex3f(0.6f, 0.01f, -4.36f);
    glVertex3f(0.5f, 0.01f, -4.36f);
    glNormal3f(0, 0, 1); // Front edge of left face
    glVertex3f(0.5f, 0.01f, -4.36f);
    glVertex3f(0.6f, 0.01f, -4.36f);
    glVertex3f(0.6f, 2.51f, -4.36f);
    glVertex3f(0.5f, 2.51f, -4.36f);

    // Right face (outer at x = 2.5, inner at x = 2.4)
    glNormal3f(1, 0, 0); // Outer face (x = 2.5)
    glVertex3f(2.5f, 0.01f, -4.99f);
    glVertex3f(2.5f, 2.51f, -4.99f);
    glVertex3f(2.5f, 2.51f, -4.36f); // Depth adjusted to -4.36
    glVertex3f(2.5f, 0.01f, -4.36f);
    glNormal3f(-1, 0, 0); // Inner face (x = 2.4)
    glVertex3f(2.4f, 0.01f, -4.99f);
    glVertex3f(2.4f, 0.01f, -4.36f);
    glVertex3f(2.4f, 2.51f, -4.36f);
    glVertex3f(2.4f, 2.51f, -4.99f);
    glNormal3f(0, 1, 0); // Top edge of right face
    glVertex3f(2.4f, 2.51f, -4.99f);
    glVertex3f(2.4f, 2.51f, -4.36f);
    glVertex3f(2.5f, 2.51f, -4.36f);
    glVertex3f(2.5f, 2.51f, -4.99f);
    glNormal3f(0, -1, 0); // Bottom edge of right face
    glVertex3f(2.4f, 0.01f, -4.99f);
    glVertex3f(2.5f, 0.01f, -4.99f);
    glVertex3f(2.5f, 0.01f, -4.36f);
    glVertex3f(2.4f, 0.01f, -4.36f);
    glNormal3f(0, 0, 1); // Front edge of right face
    glVertex3f(2.4f, 0.01f, -4.36f);
    glVertex3f(2.5f, 0.01f, -4.36f);
    glVertex3f(2.5f, 2.51f, -4.36f);
    glVertex3f(2.4f, 2.51f, -4.36f);

    // Top face (outer at y = 2.51, inner at y = 2.41)
    glNormal3f(0, 1, 0); // Outer face (y = 2.51)
    glVertex3f(0.5f, 2.51f, -4.99f);
    glVertex3f(0.5f, 2.51f, -4.36f); // Depth adjusted to -4.36
    glVertex3f(2.5f, 2.51f, -4.36f);
    glVertex3f(2.5f, 2.51f, -4.99f);
    glNormal3f(0, -1, 0); // Inner face (y = 2.41)
    glVertex3f(0.5f, 2.41f, -4.99f);
    glVertex3f(2.5f, 2.41f, -4.99f);
    glVertex3f(2.5f, 2.41f, -4.36f);
    glVertex3f(0.5f, 2.41f, -4.36f);
    glNormal3f(-1, 0, 0); // Left edge of top face
    glVertex3f(0.5f, 2.51f, -4.99f);
    glVertex3f(0.5f, 2.51f, -4.36f);
    glVertex3f(0.5f, 2.41f, -4.36f);
    glVertex3f(0.5f, 2.41f, -4.99f);
    glNormal3f(1, 0, 0); // Right edge of top face
    glVertex3f(2.5f, 2.51f, -4.99f);
    glVertex3f(2.5f, 2.41f, -4.99f);
    glVertex3f(2.5f, 2.41f, -4.36f);
    glVertex3f(2.5f, 2.51f, -4.36f);
    glNormal3f(0, 0, 1); // Front edge of top face
    glVertex3f(0.5f, 2.51f, -4.36f);
    glVertex3f(2.5f, 2.51f, -4.36f);
    glVertex3f(2.5f, 2.41f, -4.36f);
    glVertex3f(0.5f, 2.41f, -4.36f);

    // Bottom face (outer at y = 0.01, inner at y = 0.11)
    glNormal3f(0, -1, 0); // Outer face (y = 0.01)
    glVertex3f(0.5f, 0.01f, -4.99f);
    glVertex3f(2.5f, 0.01f, -4.99f);
    glVertex3f(2.5f, 0.01f, -4.36f); // Depth adjusted to -4.36
    glVertex3f(0.5f, 0.01f, -4.36f);
    glNormal3f(0, 1, 0); // Inner face (y = 0.11)
    glVertex3f(0.5f, 0.11f, -4.99f);
    glVertex3f(0.5f, 0.11f, -4.36f);
    glVertex3f(2.5f, 0.11f, -4.36f);
    glVertex3f(2.5f, 0.11f, -4.99f);
    glNormal3f(-1, 0, 0); // Left edge of bottom face
    glVertex3f(0.5f, 0.01f, -4.99f);
    glVertex3f(0.5f, 0.11f, -4.99f);
    glVertex3f(0.5f, 0.11f, -4.36f);
    glVertex3f(0.5f, 0.01f, -4.36f);
    glNormal3f(1, 0, 0); // Right edge of bottom face
    glVertex3f(2.5f, 0.01f, -4.99f);
    glVertex3f(2.5f, 0.01f, -4.36f);
    glVertex3f(2.5f, 0.11f, -4.36f);
    glVertex3f(2.5f, 0.11f, -4.99f);
    glNormal3f(0, 0, 1); // Front edge of bottom face
    glVertex3f(0.5f, 0.01f, -4.36f);
    glVertex3f(2.5f, 0.01f, -4.36f);
    glVertex3f(2.5f, 0.11f, -4.36f);
    glVertex3f(0.5f, 0.11f, -4.36f);

    // Middle shelf (top face at y = 1.31, bottom face at y = 1.21)
    glNormal3f(0, 1, 0); // Top face of the shelf (y = 1.31)
    glVertex3f(0.6f, 1.31f, -4.99f); // Adjusted x from 0.5 to 0.6
    glVertex3f(0.6f, 1.31f, -4.36f); // Depth adjusted to -4.36
    glVertex3f(2.4f, 1.31f, -4.36f); // Adjusted x from 2.5 to 2.4
    glVertex3f(2.4f, 1.31f, -4.99f);
    glNormal3f(0, -1, 0); // Bottom face of the shelf (y = 1.21)
    glVertex3f(0.6f, 1.21f, -4.99f);
    glVertex3f(2.4f, 1.21f, -4.99f);
    glVertex3f(2.4f, 1.21f, -4.36f);
    glVertex3f(0.6f, 1.21f, -4.36f);
    glNormal3f(-1, 0, 0); // Left edge of middle shelf
    glVertex3f(0.6f, 1.31f, -4.99f);
    glVertex3f(0.6f, 1.31f, -4.36f);
    glVertex3f(0.6f, 1.21f, -4.36f);
    glVertex3f(0.6f, 1.21f, -4.99f);
    glNormal3f(1, 0, 0); // Right edge of middle shelf
    glVertex3f(2.4f, 1.31f, -4.99f);
    glVertex3f(2.4f, 1.21f, -4.99f);
    glVertex3f(2.4f, 1.21f, -4.36f);
    glVertex3f(2.4f, 1.31f, -4.36f);
    glNormal3f(0, 0, 1); // Front edge of middle shelf
    glVertex3f(0.6f, 1.31f, -4.36f);
    glVertex3f(2.4f, 1.31f, -4.36f);
    glVertex3f(2.4f, 1.21f, -4.36f);
    glVertex3f(0.6f, 1.21f, -4.36f);
glEnd();

// Books on the Bottom Shelf (y = 0.01 to 0.61, filling x = 0.6 to 2.5)
float bookColors[4][3] = {
    {0.8f, 0.2f, 0.2f}, // Red
    {0.2f, 0.2f, 0.8f}, // Blue
    {0.2f, 0.8f, 0.2f}, // Green
    {0.8f, 0.8f, 0.2f}  // Yellow
};for (int i = 0; i < 19; i++) { // 19 books to fill x = 0.6 to 2.5 (1.9 units / 0.1 = 19)
    float x_start = 0.56f + i * 0.1f;
    float x_end = x_start + 0.1f;
    setMaterial(bookColors[i % 4][0], bookColors[i % 4][1], bookColors[i % 4][2], 1.0f);
    glBegin(GL_QUADS);
        // Front face (z = -4.69)
        glNormal3f(0, 0, 1);
        glVertex3f(x_start, 0.01f, -4.69f);
        glVertex3f(x_end, 0.01f, -4.69f);
        glVertex3f(x_end, 0.61f, -4.69f);
        glVertex3f(x_start, 0.61f, -4.69f);
        // Back face (z = -4.99)
        glNormal3f(0, 0, -1);
        glVertex3f(x_start, 0.01f, -4.99f);
        glVertex3f(x_start, 0.61f, -4.99f);
        glVertex3f(x_end, 0.61f, -4.99f);
        glVertex3f(x_end, 0.01f, -4.99f);
        // Left face
        glNormal3f(-1, 0, 0);
        glVertex3f(x_start, 0.01f, -4.99f);
        glVertex3f(x_start, 0.01f, -4.69f);
        glVertex3f(x_start, 0.61f, -4.69f);
        glVertex3f(x_start, 0.61f, -4.99f);
        // Right face
        glNormal3f(1, 0, 0);
        glVertex3f(x_end, 0.01f, -4.99f);
        glVertex3f(x_end, 0.61f, -4.99f);
        glVertex3f(x_end, 0.61f, -4.69f);
        glVertex3f(x_end, 0.01f, -4.69f);
        // Top face (y = 0.61)
        glNormal3f(0, 1, 0);
        glVertex3f(x_start, 0.61f, -4.99f);
        glVertex3f(x_start, 0.61f, -4.69f);
        glVertex3f(x_end, 0.61f, -4.69f);
        glVertex3f(x_end, 0.61f, -4.99f);
        // Bottom face (y = 0.01)
        glNormal3f(0, -1, 0);
        glVertex3f(x_start, 0.01f, -4.99f);
        glVertex3f(x_end, 0.01f, -4.99f);
        glVertex3f(x_end, 0.01f, -4.69f);
        glVertex3f(x_start, 0.01f, -4.69f);
    glEnd();
}
	
}

void banghesofa() {
	
// Sofa along Left Wall
glPushMatrix();
glTranslatef(-4.55f, 0.6f, 0.0f); // Center at x=-4.55, y=0.6, z=0.0
glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

// Seat (cushion)
glPushMatrix();
glTranslatef(0.0f, -0.2f, 0.0f); // y=0.4 (seat top)
glScalef(0.8f, 0.4f, 3.0f); // Width=0.8 (x), height=0.4, length=3.0 (z)
setMaterial(0.3f, 0.3f, 0.3f); // Dark gray fabric
glutSolidCube(1);
glPopMatrix();

// Backrest (cushion)
glPushMatrix();
glTranslatef(0.3f, 0.2f, 0.0f); // x=-4.25 (back), y=1.0 (top), z=0.0
glScalef(0.2f, 0.8f, 3.0f); // Width=0.2 (x), height=0.8, length=3.0 (z)
setMaterial(0.3f, 0.3f, 0.3f); // Dark gray fabric
glutSolidCube(1);
glPopMatrix();

// Left Armrest (now at z=-1.5)
glPushMatrix();
glTranslatef(0.0f, -0.1f, -1.4f); // z=-1.4, y=0.5, x=-4.55
glScalef(0.8f, 0.6f, 0.2f); // Width=0.8 (x), height=0.6, length=0.2 (z)
setMaterial(0.5f, 0.3f, 0.2f); // Wood-like
glutSolidCube(1);
glPopMatrix();

// Right Armrest (now at z=1.5)
glPushMatrix();
glTranslatef(0.0f, -0.1f, 1.4f); // z=1.4, y=0.5, x=-4.55
glScalef(0.8f, 0.6f, 0.2f); // Width=0.8 (x), height=0.6, length=0.2 (z)
setMaterial(0.5f, 0.3f, 0.2f); // Wood-like
glutSolidCube(1);
glPopMatrix();

// Four Legs
float sofaLegOffsetX = 0.35f; // Along x-axis (depth)
float sofaLegOffsetZ = 1.4f;  // Along z-axis (length)
float sofaLegHeight = 0.2f;
for (int dx = -1; dx <= 1; dx += 2) {
    for (int dz = -1; dz <= 1; dz += 2) {
        glPushMatrix();
        glTranslatef(dx * sofaLegOffsetX, -0.5f, dz * sofaLegOffsetZ); // y=0.1 (leg top)
        glScalef(0.1f, sofaLegHeight, 0.1f); // 0.1x0.1 cross-section
        setMaterial(0.5f, 0.3f, 0.2f); // Wood-like
        glutSolidCube(1);
        glPopMatrix();
    }
}

glPopMatrix();

glPushMatrix();
glTranslatef(-3.6f, 0.35f, 0.0f); // Đ?t bàn vào v? trí
glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // Xoay 90 đ? quanh tr?c Y

// Glass Top (dark)
glPushMatrix();
glTranslatef(0.0f, 0.1f, 0.0f); 
glScalef(2.2f, 0.05f, 1.0f); 
setMaterial(0.1f, 0.1f, 0.1f);
glutSolidCube(1);
glPopMatrix();

// Left Side Panel
glPushMatrix();
glTranslatef(-0.75f, -0.1f, 0.0f); 
glScalef(0.7f, 0.4f, 1.0f); 
setMaterial(1.0f, 1.0f, 1.0f);
glutSolidCube(1);
glPopMatrix();

// Right Side Panel
glPushMatrix();
glTranslatef(0.75f, -0.1f, 0.0f); 
glScalef(0.7f, 0.4f, 1.0f);
setMaterial(1.0f, 1.0f, 1.0f);
glutSolidCube(1);
glPopMatrix();

// Bottom Panel
glPushMatrix();
glTranslatef(0.0f, -0.30f, 0.0f);
glScalef(2.2f, 0.02f, 1.0f);
setMaterial(1.0f, 1.0f, 1.0f);
glutSolidCube(1);
glPopMatrix();

glPopMatrix();

// Small Sofa 1 (at z>0.5, facing table)
glPushMatrix();
glTranslatef(-3.60f, 0.32f, 1.7f); // Center at x=-3.55, y=0.5, z=0.8
glRotatef(-45.0f, 0.0f, 0.0f, 0.0f); // Rotate 90° CW to face z-negative

// Seat (cushion)
glPushMatrix();
glTranslatef(0.0f, -0.15f, 0.0f); // y=0.35 (seat top)
glScalef(0.8f, 0.3f, 0.6f); // Width=0.8 (x), height=0.3, depth=0.6 (z)
setMaterial(0.3f, 0.3f, 0.3f); // Dark gray fabric
glutSolidCube(1);
glPopMatrix();

// Backrest (cushion)
glPushMatrix();
glTranslatef(0.0f, 0.15f, 0.225f); // y=0.65 (top), z=1.025 (back)
glScalef(0.8f, 0.6f, 0.15f); // Width=0.8 (x), height=0.6, depth=0.15 (z)
setMaterial(0.3f, 0.3f, 0.3f); // Dark gray fabric
glutSolidCube(1);
glPopMatrix();

// Left Armrest
glPushMatrix();
glTranslatef(-0.325f, 0.0f, 0.0f); // x=-3.875, y=0.5, z=0.8
glScalef(0.15f, 0.45f, 0.6f); // Width=0.15 (x), height=0.45, depth=0.6 (z)
setMaterial(0.5f, 0.3f, 0.2f); // Wood-like
glutSolidCube(1);
glPopMatrix();

// Right Armrest
glPushMatrix();
glTranslatef(0.325f, 0.0f, 0.0f); // x=-3.225, y=0.5, z=0.8
glScalef(0.15f, 0.45f, 0.6f); // Width=0.15 (x), height=0.45, depth=0.6 (z)
setMaterial(0.5f, 0.3f, 0.2f); // Wood-like
glutSolidCube(1);
glPopMatrix();

// Four Legs
float smallSofa1LegOffsetX = 0.35f; // Along x-axis (width)
float smallSofa1LegOffsetZ = 0.26f; // Along z-axis (depth)
float smallSofa1LegHeight = 0.2f;
for (int dx = -1; dx <= 1; dx += 2) {
    for (int dz = -1; dz <= 1; dz += 2) {
        glPushMatrix();
        glTranslatef(dx * smallSofa1LegOffsetX, -0.35f, dz * smallSofa1LegOffsetZ); // y=0.15 (leg top)
        glScalef(0.08f, smallSofa1LegHeight, 0.08f); // 0.08x0.08 cross-section
        setMaterial(0.5f, 0.3f, 0.2f); // Wood-like
        glutSolidCube(1);
        glPopMatrix();
    }
}

glPopMatrix();

// Small Sofa 2 (at z<-0.5, facing table)
glPushMatrix();
glTranslatef(-3.60f, 0.32f, -1.7f); // Center at x=-3.55, y=0.5, z=-0.8
glRotatef(45.0f, 0.0f, 0.0f, 0.0f); // Rotate 90° CCW to face z-positive

// Seat (cushion)
glPushMatrix();
glTranslatef(0.0f, -0.15f, 0.0f); // y=0.35 (seat top)
glScalef(0.8f, 0.3f, 0.6f); // Width=0.8 (x), height=0.3, depth=0.6 (z)
setMaterial(0.3f, 0.3f, 0.3f); // Dark gray fabric
glutSolidCube(1);
glPopMatrix();

// Backrest (cushion)
glPushMatrix();
glTranslatef(0.0f, 0.15f, -0.225f); // y=0.65 (top), z=-1.025 (back)
glScalef(0.8f, 0.6f, 0.15f); // Width=0.8 (x), height=0.6, depth=0.15 (z)
setMaterial(0.3f, 0.3f, 0.3f); // Dark gray fabric
glutSolidCube(1);
glPopMatrix();

// Left Armrest
glPushMatrix();
glTranslatef(-0.325f, 0.0f, 0.0f); // x=-3.875, y=0.5, z=-0.8
glScalef(0.15f, 0.45f, 0.6f); // Width=0.15 (x), height=0.45, depth=0.6 (z)
setMaterial(0.5f, 0.3f, 0.2f); // Wood-like
glutSolidCube(1);
glPopMatrix();

// Right Armrest
glPushMatrix();
glTranslatef(0.325f, 0.0f, 0.0f); // x=-3.225, y=0.5, z=-0.8
glScalef(0.15f, 0.45f, 0.6f); // Width=0.15 (x), height=0.45, depth=0.6 (z)
setMaterial(0.5f, 0.3f, 0.2f); // Wood-like
glutSolidCube(1);
glPopMatrix();

// Four Legs
float smallSofa2LegOffsetX = 0.35f; // Along x-axis (width)
float smallSofa2LegOffsetZ = 0.26f; // Along z-axis (depth)
float smallSofa2LegHeight = 0.2f;
for (int dx = -1; dx <= 1; dx += 2) {
    for (int dz = -1; dz <= 1; dz += 2) {
        glPushMatrix();
        glTranslatef(dx * smallSofa2LegOffsetX, -0.35f, dz * smallSofa2LegOffsetZ); // y=0.15 (leg top)
        glScalef(0.08f, smallSofa2LegHeight, 0.08f); // 0.08x0.08 cross-section
        setMaterial(0.5f, 0.3f, 0.2f); // Wood-like
        glutSolidCube(1);
        glPopMatrix();
    }
}

glPopMatrix();
}













void tuhoso() {


// Filing Cabinet near Left Wall (Updated Design)
glPushMatrix();
glTranslatef(-4.4f, 0.75f, -4.79f); // Center at x=-4.4, y=0.625, z=-4.79

// Frame (outer structure)
glPushMatrix();
glTranslatef(0.0f, 0.0f, 0.0f); // y=0.625 (center of frame)
glScalef(1.0f, 1.5f, 0.4f); // Width=1.0 (x), height=1.5 (y), depth=0.4 (z)
setMaterial(0.6f, 0.6f, 0.6f); // Silver-gray
glutSolidCube(1);
glPopMatrix();

// Four Drawers (stacked vertically)
for (int i = 0; i < 4; i++) {
    // Drawer Body (inset slightly)
    glPushMatrix();
    glTranslatef(0.0f, 0.525f - i * 0.375f, 0.0f); // y positions: 1.225, 0.85, 0.475, 0.1
    glScalef(0.9f, 0.3f, 0.38f); // Width=0.9 (x), height=0.3 (y), depth=0.38 (z)
    setMaterial(0.6f, 0.6f, 0.6f); // Silver-gray (same as frame)
    glutSolidCube(1);
    glPopMatrix();

    // Drawer Front (protrudes slightly)
    glPushMatrix();
    glTranslatef(0.0f, 0.6f - i * 0.375f, 0.21f); // z=0.21 (protrudes 0.02 beyond frame)
    glScalef(0.9f, 0.3f, 0.02f); // Width=0.9 (x), height=0.3 (y), depth=0.02 (z)
    setMaterial(0.5f, 0.5f, 0.5f); // Slightly darker silver-gray for contrast
    glutSolidCube(1);
    glPopMatrix();

    // Drawer Handle
    glPushMatrix();
    glTranslatef(0.0f, 0.6f - i * 0.375f, 0.22f); // z=0.22 (on drawer front)
    glScalef(0.4f, 0.05f, 0.01f); // Width=0.4 (x), height=0.05 (y), depth=0.01 (z)
    setMaterial(0.7f, 0.7f, 0.7f); // Metallic handle (unchanged)
    glutSolidCube(1);
    glPopMatrix();
}

// Top Panel
glPushMatrix();
glTranslatef(0.0f, 0.775f, 0.0f); // y=1.4 (top of cabinet)
glScalef(1.0f, 0.05f, 0.4f); // Width=1.0 (x), height=0.05 (y), depth=0.4 (z)
setMaterial(0.6f, 0.6f, 0.6f); // Silver-gray
glutSolidCube(1);
glPopMatrix();

// Four Legs
float cabinetLegOffsetX = 0.47f; // Along x-axis (width)
float cabinetLegOffsetZ = 0.17f; // Along z-axis (depth)
float cabinetLegHeight = 0.1f;
for (int dx = -1; dx <= 1; dx += 2) {
    for (int dz = -1; dz <= 1; dz += 2) {
        glPushMatrix();
        glTranslatef(dx * cabinetLegOffsetX, -0.6f, dz * cabinetLegOffsetZ); // y=0.05 (leg center)
        glScalef(0.06f, cabinetLegHeight, 0.06f); // 0.06x0.06 cross-section
        setMaterial(0.6f, 0.6f, 0.6f); // Silver-gray
        glutSolidCube(1);
        glPopMatrix();
    }
}

glPopMatrix();



}

void banlamviec() {
	// ---------------- Desk ----------------
// M?t bàn
glPushMatrix();
glTranslatef(0.0f, 0.8f, 0.0f);
glScalef(2.1f, 0.1f, 1.0f); 
setMaterial(0.5f, 0.3f, 0.2f);
glutSolidCube(1);
glPopMatrix();

// 4 chân bàn
float legHeight = 0.8f;
float legOffsetX = 0.84f; // From 0.72f to 0.84f (80% of new half-width 1.05)
float legOffsetZ = 0.45f;
for (int dx = -1; dx <= 1; dx += 2) {
    for (int dz = -1; dz <= 1; dz += 2) {
        glPushMatrix();
        glTranslatef(0.0f + dx * legOffsetX, legHeight / 2, 0.0f + dz * legOffsetZ);
        glScalef(0.1f, legHeight, 0.1f);
        setMaterial(0.5f, 0.3f, 0.2f);
        glutSolidCube(1);
        glPopMatrix();
    }
}

// ---------------- Chair ----------------
glPushMatrix();
glTranslatef(0.0f, 0.4f, -1.0f);

// M?t gh?
glPushMatrix();
glScalef(0.5f, 0.1f, 0.5f);
setMaterial(0.3f, 0.3f, 0.3f);
glutSolidCube(1);
glPopMatrix();

// T?a lưng
glPushMatrix();
glTranslatef(0.0f, 0.3f, -0.25f);
glScalef(0.5f, 0.5f, 0.05f);
setMaterial(0.3f, 0.3f, 0.3f);
glutSolidCube(1);
glPopMatrix();

// 4 chân gh?
float chairLegH = 0.4f;
float chairOffset = 0.2f;
for (int dx = -1; dx <= 1; dx += 2) {
    for (int dz = -1; dz <= 1; dz += 2) {
        glPushMatrix();
        glTranslatef(dx * chairOffset, -chairLegH / 2, dz * chairOffset);
        glScalef(0.05f, chairLegH, 0.05f);
        setMaterial(0.3f, 0.3f, 0.3f);
        glutSolidCube(1);
        glPopMatrix();
    }
}
glPopMatrix();

// ---------------- Computer ----------------
// Màn h?nh
glPushMatrix();
glTranslatef(0.0f, 1.12f, 0.4f);
glRotatef(180.0f, 0, 1, 0);
glScalef(0.7f, 0.45f, 0.05f);
setMaterial(0.1f, 0.1f, 0.1f);
glutSolidCube(1);
glPopMatrix();

// Đ? mân h?nh
glPushMatrix();
glTranslatef(0.0f, 0.85f, 0.4f);
glScalef(0.2f, 0.1f, 0.1f);
setMaterial(0.1f, 0.1f, 0.1f);
glutSolidCube(1);
glPopMatrix();

// than may 
glPushMatrix();
glTranslatef(-0.80f, 1.1f, 0.0f);
glScalef(0.3f, 0.6f, 0.75f);
setMaterial(0.1f, 0.1f, 0.1f);
glutSolidCube(1);
glPopMatrix();

// Bàn phím
glPushMatrix();
glTranslatef(0.0f, 0.88f, -0.1f);
glScalef(0.5f, 0.05f, 0.2f);
setMaterial(0.2f, 0.2f, 0.2f);
glutSolidCube(1);
glPopMatrix();

// chu?t 
glPushMatrix();
glTranslatef(0.5f, 0.88f, -0.1f);
glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // Xoay 90 đ? quanh tr?c Y
glScalef(0.1f, 0.05f, 0.05f);
setMaterial(0.2f, 0.2f, 0.2f);
glutSolidSphere(1, 10, 10);
glPopMatrix();
} 

void becacanh() {
	// Aquarium on Cabinet
glPushMatrix();
glTranslatef(-4.38f, -0.145f, 4.75f); // Góc ph?ng

// --- Cabinet (White base) ---
glPushMatrix();
glTranslatef(0.0f, 0.4f, 0.0f); // Gi?a chi?u cao t?
glScalef(1.2f, 0.5f, 0.4f); // R?ng x, Cao y, Sâu z
setMaterial(1.0f, 1.0f, 1.0f); // Màu tr?ng
glutSolidCube(1.0f);
glPopMatrix();

// --- Aquarium Glass Tank ---
glPushMatrix();
glTranslatef(0.0f, 0.92f, 0.0f); // Trên nóc t?
glScalef(1.2f, 0.6f, 0.4f); // Kích thư?c b?
setMaterial(0.6f, 0.8f, 1.0f, 0.4f); // Kính xanh nh?t trong
glutSolidCube(1.0f);
glPopMatrix();

// --- Top Frame of Aquarium (black lid) ---
glPushMatrix();
glTranslatef(0.0f, 1.25f, 0.0f); // Nóc b?
glScalef(1.2f, 0.05f, 0.4f);
setMaterial(0.1f, 0.1f, 0.1f); // Đen
glutSolidCube(1.0f);
glPopMatrix();
glPopMatrix(); 
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    float radX = angleX * 3.14159265f / 180.0f;
    float radY = angleY * 3.14159265f / 180.0f;
    float eyeX = camX + cameraDistance * sin(radY) * cos(radX);
    float eyeY = camY + cameraDistance * sin(radX);
    float eyeZ = camZ + cameraDistance * cos(radY) * cos(radX);

    gluLookAt(eyeX, eyeY, eyeZ,
              camX, camY, camZ,
              0, 1, 0);

    initLighting();
    drawRoom();
    banlamviec();
    tranhtreotuong();
    becacanh();
    dongho();
    dentran();
    tuhosonho();
    tuhosogo();
    tusach();
    banghesofa();
    tuhoso();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)w / (float)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}



void keyboard(unsigned char key, int, int) {
    float moveStep = 0.5f;
    float rotateStep = 5.0f;

    float radY = angleY * 3.14159265f / 180.0f;

    switch (key) {
        case '1': light0On = !light0On; break; // Toggle directional light (GL_LIGHT0)
        case '2': light1On = !light1On; break; // Toggle top-right lamp (GL_LIGHT1)
        case '3': light2On = !light2On; break; // Toggle bottom-right lamp (GL_LIGHT2)
        case '4': light3On = !light3On; break; // Toggle top-left lamp (GL_LIGHT3)
        case '5': light4On = !light4On; break; // Toggle bottom-left lamp (GL_LIGHT4)

        // GL_LIGHT1 controls
        case 'f': case 'F': light1AmbientOn = !light1AmbientOn; break;  // Toggle Ambient
        case 'g': case 'G': light1DiffuseOn = !light1DiffuseOn; break;  // Toggle Diffuse
        case 'h': case 'H': light1SpecularOn = !light1SpecularOn; break; // Toggle Specular

        // GL_LIGHT2 controls
        case 'j': case 'J': light2AmbientOn = !light2AmbientOn; break;
        case 'k': case 'K': light2DiffuseOn = !light2DiffuseOn; break;
        case 'l': case 'L': light2SpecularOn = !light2SpecularOn; break;

        // GL_LIGHT3 controls
        case 'c': case 'C': light3AmbientOn = !light3AmbientOn; break;
        case 'v': case 'V': light3DiffuseOn = !light3DiffuseOn; break;
        case 'b': case 'B': light3SpecularOn = !light3SpecularOn; break;

        // GL_LIGHT4 controls
        case '6': light4AmbientOn = !light4AmbientOn; break;
        case '7': light4DiffuseOn = !light4DiffuseOn; break;
        case '8': light4SpecularOn = !light4SpecularOn; break;

        // Directional light (GL_LIGHT0) direction controls
       // Trong hàm keyboard()
case 'e': case 'E': light0_dir[0] += 0.1f; break; // Increase x direction
case 'r': case 'R': light0_dir[0] -= 0.1f; break; // Decrease x direction
case 't': case 'T': light0_dir[1] += 0.1f; break; // Increase y direction
case 'y': case 'Y': light0_dir[1] -= 0.1f; break; // Decrease y direction
case 'u': case 'U': light0_dir[2] += 0.1f; break; // Increase z direction
case 'i': case 'I': light0_dir[2] -= 0.1f; break; // Decrease z direction

        case 'a': angleY -= rotateStep; break;
        case 'd': angleY += rotateStep; break;
    

       case 'w':
    camY += moveStep; // Di chuy?n camera lên trên
    break;
        case 's':
    camY -= moveStep; // Di chuy?n camera xu?ng dư?i
    break;
            break;
        case 'x':
            camX += moveStep * sin(radY);
            camZ += moveStep * cos(radY);
            break;
        case 'z':
            camX -= moveStep * sin(radY);
            camZ -= moveStep * cos(radY);
            break;

    

        case 27: exit(0); break;
    }
    if (angleX > 89) angleX = 89;
    if (angleX < -89) angleX = -89;

    glutPostRedisplay();
}

void specialKeys(int key, int, int) {
    switch (key) {
        case GLUT_KEY_LEFT: angleY -= 5; break;
        case GLUT_KEY_RIGHT: angleY += 5; break;
        case GLUT_KEY_UP: angleX -= 5; break;
        case GLUT_KEY_DOWN: angleX += 5; break;
    }
    if (angleX > 89) angleX = 89;
    if (angleX < -89) angleX = -89;
    glutPostRedisplay();
}

void printInstructions() {
    std::cout << "===== Huong Dan Dieu Khien =====" << std::endl;
    std::cout << "Dieu Khien Camera:" << std::endl;
    std::cout << "  W/S hoac Mui ten Len/Xuong: Xoay camera theo chieu doc" << std::endl;
    std::cout << "  A/D hoac Mui ten Trai/Phai: Xoay camera theo chieu ngang" << std::endl;
    std::cout << "  X: Di chuyen camera tien len" << std::endl;
    std::cout << "  Z: Di chuyen camera lui lai" << std::endl;
    std::cout << "Dieu Khien Cua:" << std::endl;
    std::cout << "Dieu Khien Anh Sang:" << std::endl;
    std::cout << "  1: Bat/tat GL_LIGHT0 (Den spotlight o trung tam)" << std::endl;
    std::cout << "  E/R: Tang/Giam huong X cua spotlight" << std::endl;
    std::cout << "  T/Y: Tang/Giam huong Y cua spotlight" << std::endl;
    std::cout << "  U/I: Tang/Giam huong Z cua spotlight" << std::endl;
    std::cout << "  2: Bat/tat GL_LIGHT1 (Goc tren ben phai)" << std::endl;
    std::cout << "    F: Bat/tat thanh phan Ambient cua GL_LIGHT1" << std::endl;
    std::cout << "    G: Bat/tat thanh phan Diffuse cua GL_LIGHT1" << std::endl;
    std::cout << "    H: Bat/tat thanh phan Specular cua GL_LIGHT1" << std::endl;
    std::cout << "  3: Bat/tat GL_LIGHT2 (Goc duoi ben phai)" << std::endl;
    std::cout << "    J: Bat/tat thanh phan Ambient cua GL_LIGHT2" << std::endl;
    std::cout << "    K: Bat/tat thanh phan Diffuse cua GL_LIGHT2" << std::endl;
    std::cout << "    L: Bat/tat thanh phan Specular cua GL_LIGHT2" << std::endl;
    std::cout << "  4: Bat/tat GL_LIGHT3 (Goc tren ben trai)" << std::endl;
    std::cout << "    C: Bat/tat thanh phan Ambient cua GL_LIGHT3" << std::endl;
    std::cout << "    V: Bat/tat thanh phan Diffuse cua GL_LIGHT3" << std::endl;
    std::cout << "    B: Bat/tat thanh phan Specular cua GL_LIGHT3" << std::endl;
    std::cout << "  5: Bat/tat GL_LIGHT4 (Goc duoi ben trai)" << std::endl;
    std::cout << "    6: Bat/tat thanh phan Ambient cua GL_LIGHT4" << std::endl;
    std::cout << "    7: Bat/tat thanh phan Diffuse cua GL_LIGHT4" << std::endl;
    std::cout << "    8: Bat/tat thanh phan Specular cua GL_LIGHT4" << std::endl;
    std::cout << "Thoat Chuong Trinh:" << std::endl;
    std::cout << "  Esc: Thoat chuong trinh" << std::endl;
    std::cout << "==============================" << std::endl;
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(900, 600);
    glutCreateWindow("Phong lam viec");

    // Print instructions to console
    printInstructions();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);


    glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // Dark gray background

    glutMainLoop();
    return 0;
}
