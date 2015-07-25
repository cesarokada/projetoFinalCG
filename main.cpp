#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "camera.h"
#include "tv.h"
#include "ventilador.h"


#define GL_COLOR_GROUND glColor3f( 0.74, 0.51, 0.36 )
#define GL_COLOR_WALL   glColor3f( 0.99, 0.95, 0.8 )
#define CHAO "chao.jpg"


/* GLUT callback Handlers */

void drawAxis()
{
    // desehar eixos
    glDisable(GL_LIGHTING);
    glBegin(GL_LINES);
      int i, n=100;

      // desenhar a grade do plano X-Z
      // (apenas colorir quando desenhar o eixo origem)
      for(i = 0; i < n; i++) {
        // (cinza)
        glColor3f(0.8, 0.8, 0.8);

        // x (vermelho)
        if (!(-50 + i*(100/n))) glColor3f(1, 0, 0);
        glVertex3f(-50, -2, -50 + i*(100/n));
        glVertex3f(50, -2, -50 + i*(100/n));

        // z (azul)
        if (!(-50 + i*(100/n))) glColor3f(0, 0, 1);
        glVertex3f(-50 + i*(100/n), -2, -50);
        glVertex3f(-50 + i*(100/n), -2, 50);
      }

      // y (verde)
      glColor3f(0, 1, 0);
      glVertex3f(0, -50, 0);
      glVertex3f(0, 50, 0);

    glEnd();
    glEnable(GL_LIGHTING);
}


int lAmbient = 35;
int lDiffuse = 65;
int lSpecular = 50;

void drawLight() {

  GLfloat lightPos[] = { 0.0, 14.5, 0.0, 1.0 };

  glDisable(GL_LIGHTING);

    // desenhar esfera
  glPushMatrix();
    glNormal3f(0.0, -1.0, 0.0);
    glColor3f( 1.0, 1.0, 1.0 );
        glTranslated(lightPos[0], lightPos[1], lightPos[2]);    // posicao da luz
    glutSolidSphere(0.25, 24, 24);
  glPopMatrix();

  glEnable(GL_NORMALIZE);

  glEnable(GL_LIGHTING);

  glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);
  glEnable(GL_COLOR_MATERIAL);

  glNormal3f(0.0, 1.0, 0.0);
  glEnable(GL_LIGHT0);
  glShadeModel(GL_SMOOTH);

  GLfloat Ambient[]   = {0.01*lAmbient ,0.01*lAmbient ,0.01*lAmbient ,0.0};
  GLfloat Diffuse[]   = {0.01*lDiffuse ,0.01*lDiffuse ,0.01*lDiffuse ,1.0};
  GLfloat Specular[]  = {0.01*lSpecular,0.01*lSpecular,0.01*lSpecular,1.0};

  glLightfv(GL_LIGHT0, GL_AMBIENT, Ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, Diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, Specular);
  glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

}


void drawWalls()
{
  int h=15; // tamanho da parede
  int hx2=h*2; // dimensão do chão

  glPushMatrix();

  GLfloat Ambient[]   = {0.01*lAmbient ,0.01*lAmbient ,0.01*lAmbient ,1.0};
  GLfloat Diffuse[]   = {0.01*lDiffuse ,0.01*lDiffuse ,0.01*lDiffuse ,1.0};
  GLfloat Specular[]  = {0.01*lSpecular,0.01*lSpecular,0.01*lSpecular,1.0};
  GLfloat shi[]  = {10.0};
  GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };

  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Ambient);
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Diffuse);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, Specular);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shi);
  glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, no_mat);

  // CHAO
  GL_COLOR_GROUND;
  glBegin(GL_POLYGON);
    glNormal3f(0.0, 1.0, 0.0);

//    glNormal3f(1.0, 1.0, 1.0);
    glVertex3f(  -hx2, -2, -hx2 );

//    glNormal3f(1.0, 1.0, -1.0);
    glVertex3f(  -hx2, -2, hx2 );

///    glNormal3f(-1.0, 1.0, -1.0);
    glVertex3f(   hx2, -2, hx2 );

//    glNormal3f(-1.0, 1.0, 1.0);
    glVertex3f(   hx2, -2, -hx2 );
  glEnd();

  GL_COLOR_WALL;  // cor das paredes

  // ESQUERDA
  glBegin(GL_POLYGON);
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f(  -h, -2, -h );      // P1 is red
    glVertex3f(  -h, -2, h );      // P2 is green
    glVertex3f(  -h, h, h );      // P3 is blue
    glVertex3f(  -h, h, -h );      // P4 is purple

  glEnd();

  // DIREITA
  glBegin(GL_POLYGON);
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f(  h, -2,-h );      // P1 is red
    glVertex3f(  h, -2, h );      // P2 is green
    glVertex3f(  h,  h, h );      // P3 is blue
    glVertex3f(  h,  h,-h );      // P4 is purple
  glEnd();

  // ATRAS
  glBegin(GL_POLYGON);
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3f(  -h, -2, -h );      // P1 is red
    glVertex3f(  h, -2, -h );      // P2 is green
    glVertex3f(  h, h, -h );      // P3 is blue
    glVertex3f(  -h, h, -h );      // P4 is purple
  glEnd();

  // FRENTE
/*  glBegin(GL_POLYGON);
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f(  -h, -2, h );      // P1 is red
    glVertex3f(  h, -2, h );      // P2 is green
    glVertex3f(  h, h, h );      // P3 is blue
    glVertex3f(  -h, h, h );      // P4 is purple
  glEnd();  */
  glBegin(GL_POLYGON);
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f(  -h, -2, h );
    glVertex3f(  -(h/4) , -2, h );
    glVertex3f(  -(h/4) , h, h );
    glVertex3f(  -h, h, h );
  glEnd();
  glBegin(GL_POLYGON);
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f(  (h/4) , -2, h );
    glVertex3f(  h , -2, h );
    glVertex3f(  h , h, h );
    glVertex3f(  (h/4), h, h );
  glEnd();
  glBegin(GL_POLYGON);
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f(  -(h/4) , (h/2), h );
    glVertex3f(   (h/4) , (h/2), h );
    glVertex3f(   (h/4), h, h );
    glVertex3f(   -(h/4), h, h );
  glEnd();


  // TETO
  glBegin(GL_POLYGON);
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3f(  -h, h, -h );      // P1 is red
    glVertex3f(  -h, h, h );      // P2 is green
    glVertex3f(   h, h, h );      // P3 is blue
    glVertex3f(   h, h, -h );      // P4 is purple
  glEnd();

  // Telhado
  glBegin(GL_POLYGON);
  glColor3f( 0.74, 0.51, 0.36 );
    //glVertex3f(5, 30, 20);
    glVertex3f( -h/20, h+5, -h );      // P1 is red
    glVertex3f( -h/20, h+5,  h );      // P2 is green
    glVertex3f(  h+3,  h-1, h );      // P3 is blue
    glVertex3f(  h+3,  h-1, -h );      // P3 is blue
  glEnd();

  glBegin(GL_POLYGON);
    glVertex3f( h/20, h+5, -h );      // P1 is red
    glVertex3f( h/20, h+5,  h );      // P2 is green
    glVertex3f(  -h-3,  h-1, h );      // P3 is blue
    glVertex3f(  -h-3,  h-1, -h );      // P3 is blue
  glEnd();

  glBegin(GL_POLYGON);
    glVertex3f( h/20, h+5, h );      // P1 is red
    glVertex3f( h/20, h-1, h+5 );      // P2 is green
    glVertex3f(  -h-3,  h-1, h+5 );      // P3 is blue
    glVertex3f(  -h-3,  h-1, h );      // P3 is blue
  glEnd();

  glBegin(GL_POLYGON);
    glVertex3f( h/20, h+5, h );      // P1 is red
    glVertex3f( h/20, h-1, h+5 );      // P2 is green
    glVertex3f(  h+3,  h-1, h+5 );      // P3 is blue
    glVertex3f(  h+3,  h-1, h );      // P3 is blue
  glEnd();

  // PORTA

  glBegin(GL_POLYGON);
    GL_COLOR_GROUND;
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f(  -(h/4) , (h/2), h );
    glVertex3f(   (h/4) , (h/2), h );
    glVertex3f(   (h/4), -2.0, h );
    glVertex3f(   -(h/4), -2.0, h );
  glEnd();

  glColor3f(0.8, 0.8, 0.8);
  glTranslatef( (h/4) - 0.5, (h/6) ,h);
  glutSolidSphere(0.2, 24, 24);


  glPopMatrix();

}

float ar;

void specificVisualParameter(GLdouble fAspect)
{
     glMatrixMode( GL_PROJECTION );
     glLoadIdentity();

     gluPerspective( 45, fAspect, 0.1, 500 );

     glMatrixMode( GL_MODELVIEW );
     glLoadIdentity();

     //gluLookAt( lx, ly, lz, ax, ay, az, ux, uy, uz);

}

static void resize(int width, int height)
{
    ar = (float) width / (float) height;

    glViewport(0, 0, width, height);

    specificVisualParameter(ar);
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    char title [100];
    sprintf(title,  "Ambient %d | Diffuse: %d | Specular: %d", lAmbient, lDiffuse, lSpecular);
    glutSetWindowTitle(title);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    camRender();

    drawLight();

    drawAxis();  // desenhar eixos

    drawWalls();

    drawVentilador(2.0, 6.0, 0.75);

    // teapot
    glPushMatrix();
      glColor3f(0.2, 0.8, 0.0);
      glTranslated(0.0, -1.1, 0.0);
      glutSolidTeapot(1.0);
    glPopMatrix();

    // outra esfera
    glPushMatrix();
      glTranslated(5.0, -1.0, -8.0);    // posicao da luz
      glutSolidSphere(0.7, 24, 24);
    glPopMatrix();

    glPushMatrix();
      glTranslated(-6.0, -1.0, 7.0);    // posicao da luz
      glutSolidCube(2.0);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(-11.0, -2.0, -10.0);
      glRotatef(30, 0.0, 1.0, 0.0);
      drawTV(1.5);
    glPopMatrix();

    glutSwapBuffers();
}

static void key(unsigned char key, int x, int y){

    switch (toupper(key))
    {
        case 'W':
            camMoveFront();
            break;
        case 'S':
            camMoveBack();
            break;
        case 'D':
            camMoveRight();
            break;
        case 'A':
            camMoveLeft();
            break;
        case 'G':
            if (lAmbient < 100) lAmbient++;
            break;
        case 'H':
            if (lDiffuse < 100) lDiffuse++;
            break;
        case 'J':
            if (lSpecular < 100) lSpecular++;
            break;
        case 'B':
            if (lAmbient > 0) lAmbient--;
            break;
        case 'N':
            if (lDiffuse > 0) lDiffuse--;
            break;
        case 'M':
            if (lSpecular > 0) lSpecular--;
            break;
        case 27 : // ESC
        case 'Q':
            exit(0);
            break;
    }

    glutPostRedisplay();
}

static void
idle(void){
    glutPostRedisplay();
}



/* Program entry point */

int
main(int argc, char *argv[])
{
    glutInit(&argc, argv);             // inicializa o GLUT
    glutInitWindowSize(640,480);       // tamanho da tela
    glutInitWindowPosition(10,10);     // posição da tela
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // modo de visualização

    glutCreateWindow("The Sims 4 - A evolução");    // cria uma janela com o titulo

    glutReshapeFunc(resize);           // redimensiona
    glutDisplayFunc(display);          // exibe os objetos
    glutSpecialFunc(specialkey);       // teclas especiais
    glutKeyboardFunc(key);             // teclas
    glutIdleFunc(idle);                // atualiza a tela (display)

    glClearColor(0.45,0.82,0.93,1);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glutMainLoop();

    return EXIT_SUCCESS;
}
