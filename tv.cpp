#include <GL/glut.h>
#include <math.h>

#define TV_COLOR_BOX    glColor3f(0.5, 0.5, 0.5)
#define TV_COLOR_SCREEN glColor3f(0.2, 0.4, 0.8)

typedef struct v {
  float x;
  float y;
  float z;
}vertex_t;

void normalize (vertex_t *v)
{
    // calculate the length of the vector
    float len = (float)(sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z)));

    // avoid division by 0
    if (len == 0.0f)
        len = 1.0f;

    // reduce to unit size
    v->x /= len;
    v->y /= len;
    v->z /= len;
}

// normal(); - finds a normal vector and normalizes it
void normal (vertex_t v[3], vertex_t *v_normal)
{
    vertex_t a, b;

    // calculate the vectors A and B
    // note that v[3] is defined with counterclockwise winding in mind
    // a
    a.x = v[0].x - v[1].x;
    a.y = v[0].y - v[1].y;
    a.z = v[0].z - v[1].z;
    // b
    b.x = v[2].x - v[1].x;
    b.y = v[2].y - v[1].y;
    b.z = v[2].z - v[1].z;

    // calculate the cross product and place the resulting vector
    // into the address specified by vertex_t *normal
    v_normal->x = (a.y * b.z) - (a.z * b.y);
    v_normal->y = (a.z * b.x) - (a.x * b.z);
    v_normal->z = (a.x * b.y) - (a.y * b.x);

    // normalize
    normalize(v_normal);
}

void  drawTV(float size) {

  vertex_t *v_normal;
  vertex_t v[3];

  glPushMatrix();

      glScalef(size, size, size);

      // frente ****************************************
      TV_COLOR_BOX;
      glBegin(GL_POLYGON);
          glNormal3f(0.0, 0.0, 1.0);
          glVertex3f(-2.0, 0.0, 0.0);
          glVertex3f(2.0, 0.0, 0.0);
          glVertex3f(2.0, 3.0, 0.0);
          glVertex3f(-2.0, 3.0, 0.0);
      glEnd();

      // tela ****************************************
      TV_COLOR_SCREEN;
      glBegin(GL_POLYGON);
          glNormal3f(0.0, 0.0, 1.0);
          glVertex3f(-1.5, 0.5, 0.01);
          glVertex3f(1.5, 0.5, 0.01);
          glVertex3f(1.5, 2.5, 0.01);
          glVertex3f(-1.5, 2.5, 0.01);
      glEnd();

      TV_COLOR_BOX;

      // borda lateral - acima ****************************************
      glBegin(GL_POLYGON);
          glNormal3f(0.0, 1.0, 0.0);
          glVertex3f(2.0, 3.0, 0.0);
          glVertex3f(-2.0, 3.0, 0.0);
          glVertex3f(-2.0, 3.0, -1.0);
          glVertex3f(2.0, 3.0, -1.0);
      glEnd();

      // borda lateral - esq ****************************************
      glBegin(GL_POLYGON);
          glNormal3f(-1.0, 0.0, 0.0);
          glVertex3f(-2.0, 3.0, 0.0);
          glVertex3f(-2.0, 3.0, -1.0);
          glVertex3f(-2.0, 0.0, -1.0);
          glVertex3f(-2.0, 0.0, 0.0);
      glEnd();

      // borda lateral - dir ****************************************
      glBegin(GL_POLYGON);
          glNormal3f(1.0, 0.0, 0.0);
          glVertex3f(2.0, 3.0, 0.0);
          glVertex3f(2.0, 3.0, -1.0);
          glVertex3f(2.0, 0.0, -1.0);
          glVertex3f(2.0, 0.0, 0.0);
      glEnd();

      // borda lateral - abaixo ****************************************
      glBegin(GL_POLYGON);
          glNormal3f(0.0, -1.0, 0.0);
          glVertex3f(2.0, 0.0, 0.0);
          glVertex3f(-2.0, 0.0, 0.0);
          glVertex3f(-2.0, 0.0, -1.0);
          glVertex3f(2.0, 0.0, -1.0);
      glEnd();

      // traseira - acima ****************************************
      glBegin(GL_POLYGON);

          // normal
          v[0].x = 2.0;   v[0].y = 3.0;   v[0].z = -1.0;
          v[1].x = 1.0;   v[1].y = 2.0;   v[1].z = -2.0;
          v[2].x = -1.0;   v[2].y = 2.0;   v[2].z = -2.0;

          v_normal = (vertex_t*) malloc(sizeof(vertex_t));
          normal(v, v_normal);

          glNormal3f(v_normal->x, v_normal->y, v_normal->z);

          glVertex3f(2.0, 3.0, -1.0);
          glVertex3f(1.0, 2.0, -2.0);
          glVertex3f(-1.0, 2.0, -2.0);
          glVertex3f(-2.0, 3.0, -1.0);
      glEnd();

      // traseira - esq ****************************************
      glBegin(GL_POLYGON);

          // normal
          v[0].x = -2.0;   v[0].y = 3.0;   v[0].z = -1.0;
          v[1].x = -1.0;   v[1].y = 2.0;   v[1].z = -2.0;
          v[2].x = -1.0;   v[2].y = 1.0;   v[2].z = -2.0;

          v_normal = (vertex_t*) malloc(sizeof(vertex_t));
          normal(v, v_normal);

          glNormal3f(v_normal->x, v_normal->y, v_normal->z);

          glVertex3f(-2.0, 3.0, -1.0);
          glVertex3f(-1.0, 2.0, -2.0);
          glVertex3f(-1.0, 1.0, -2.0);
          glVertex3f(-2.0, 0.0, -1.0);
      glEnd();

      // traseira - dir ****************************************
      glBegin(GL_POLYGON);

          // normal
          v[0].x = 2.0;   v[0].y = 3.0;   v[0].z = -1.0;
          v[1].x = 1.0;   v[1].y = 2.0;   v[1].z = -2.0;
          v[2].x = 1.0;   v[2].y = 1.0;   v[2].z = -2.0;

          v_normal = (vertex_t*) malloc(sizeof(vertex_t));
          normal(v, v_normal);

          glNormal3f(v_normal->x, v_normal->y, v_normal->z);

          glVertex3f(2.0, 3.0, -1.0);
          glVertex3f(1.0, 2.0, -2.0);
          glVertex3f(1.0, 1.0, -2.0);
          glVertex3f(2.0, 0.0, -1.0);
      glEnd();

      // traseira - abaixo ****************************************
      glBegin(GL_POLYGON);

          // normal
          v[0].x = 2.0;   v[0].y = 0.0;   v[0].z = -1.0;
          v[1].x = 1.0;   v[1].y = 1.0;   v[1].z = -2.0;
          v[2].x = -1.0;   v[2].y = 1.0;   v[2].z = -2.0;

          v_normal = (vertex_t*) malloc(sizeof(vertex_t));
          normal(v, v_normal);

          glNormal3f(v_normal->x, v_normal->y, v_normal->z);

          glVertex3f(2.0, 0.0, -1.0);
          glVertex3f(1.0, 1.0, -2.0);
          glVertex3f(-1.0, 1.0, -2.0);
          glVertex3f(-2.0, 0.0, -1.0);
      glEnd();

      // traseira - fundo ****************************************
      glBegin(GL_POLYGON);
          glNormal3f(0.0, 0.0, -1.0);
          glVertex3f(1.0, 2.0, -2.0);
          glVertex3f(-1.0, 2.0, -2.0);
          glVertex3f(-1.0, 1.0, -2.0);
          glVertex3f(1.0, 1.0, -2.0);
      glEnd();

      // antenas ****************************************
      glBegin(GL_LINES);
          glVertex3f(0.0, 3.0, -0.5);
          glVertex3f(-1.5, 4.0, -0.5);
      glEnd();
      glBegin(GL_LINES);
          glVertex3f(0.0, 3.0, -0.5);
          glVertex3f(1.5, 4.0, -0.5);
      glEnd();

  glPopMatrix();

}
