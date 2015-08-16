#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

#include "camera.h"
#include "planetas.h"

int lAmbient = 35;
int lDiffuse = 65;
int lSpecular = 50;
float ar;

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

void specificVisualParameter(GLdouble fAspect)
{
     glMatrixMode( GL_PROJECTION );
     glLoadIdentity();

     gluPerspective( 45, fAspect, 0.1, 500 );

     glMatrixMode( GL_MODELVIEW );
     glLoadIdentity();
}

static void resize(int width, int height)
{
    ar = (float) (width) / (float) (height);

    glViewport(0, 0, width, height);

    specificVisualParameter(ar);
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    camRender();
    drawLight();
    drawSun();
    drawMercurio();
    drawVenus();
    drawTerra();
    drawMarte();
    drawJupiter();
    drawSaturno();
    drawUrano();
    drawNetuno();
    drawPlutao();

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

static void idle(void){

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
  switch (button) {
      case GLUT_LEFT_BUTTON:
           if (state == GLUT_DOWN)
              glutIdleFunc(idle);
           break;
      case GLUT_RIGHT_BUTTON:
           if (state == GLUT_DOWN)
              glutIdleFunc(NULL);
           break;
      default:
           break;
  }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);             // inicializa o GLUT
    glutInitWindowSize(640,480);       // tamanho da tela
    glutInitWindowPosition(10,10);     // posição da tela
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // modo de visualização

    glutCreateWindow("Sistema Solar");    // cria uma janela com o titulo

    glutReshapeFunc(resize);           // redimensiona
    glutDisplayFunc(display);          // exibe os objetos
    glutSpecialFunc(specialkey);       // teclas especiais
    glutMouseFunc(mouse);
    glutKeyboardFunc(key);             // teclas

    glutIdleFunc(idle);                // atualiza a tela (display)

    glClearColor(0.0,0.0,0.0,1);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glutMainLoop();

    return EXIT_SUCCESS;
}
