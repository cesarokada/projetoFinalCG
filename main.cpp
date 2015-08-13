#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

#include "camera.h"

#define DEG2RAD 3.14159/180.0

float ano = 0;

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

void DrawEllipse(float radiusX, float radiusZ)
{
   int i;

   glBegin(GL_LINE_LOOP);

   for(i=0;i<360;i++)
   {
      float rad = i*DEG2RAD;
      glVertex3f(cos(rad)*radiusX,
                  0,sin(rad)*radiusZ);
   }

   glEnd();
}


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

     //gluLookAt( lx, ly, lz, ax, ay, az, ux, uy, uz);

}

static void resize(int width, int height)
{
    ar = (float) (width) / (float) (height);

    glViewport(0, 0, width, height);

    specificVisualParameter(ar);
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    int year = 365;
    int day = 24;

    char title [100];
    sprintf(title,  "Ambient %d | Diffuse: %d | Specular: %d", lAmbient, lDiffuse, lSpecular);
    glutSetWindowTitle(title);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    camRender();

    drawLight();

    //drawAxis();  // desenhar eixos


    glColor3f (1.0, 0.60, 0.09);
    glPushMatrix();
      glTranslated(0.0, 0.0, 0.0); //MATRIZ DE TRANSLAÇÃO COM A MATRIZ IDENTIDADE!!!
                                  //SOL NO CENTRO DA IMAGEM, É SÓ ALTERAR OS PARÂMETROS PRA MUDAR A POSIÇÃO
      glutSolidSphere(0.5, 24, 24); //DESENHA A ESFERA, ALTERA O PRIMEIRO PARÂMETRO PRA AUMENTAR O RAIO
    glPopMatrix();

    //MERCURIO
    glPushMatrix();
      glRotatef (ano * 1.3, 0.0, 1.0, 0.0); //PARA ROTACIONAR
      glTranslated(0.55, 0.0, 0.0);
      glColor3f (1.0, 0.0, 0.0);
      glutSolidSphere(0.05, 10, 8);
    glPopMatrix();

    //VENUS
    glPushMatrix();
      glRotatef (ano * 1.1, 0.0, 1.0, 0.0);
      glTranslated(1.5, 0.0, 0.0);
      glColor3f (0.8, 0.4, 0.2);
      glutSolidSphere(0.068, 10, 8);
    glPopMatrix();
    DrawEllipse(1.5,0.7);

      //TERRA
    glPushMatrix();
      glTranslated(2.0, 0.0, 0.0);
      glColor3f (0.2, 0.2, 1.0);
      glutSolidSphere(0.08, 10, 8);
    glPopMatrix();
    DrawEllipse(2.0,0.9);


    //LUA
    glPushMatrix();
     glTranslated(2.0, 0.0, 0.0);
     glColor3f(1.0, 1.0, 1.0);
     glutSolidSphere(0.0216, 10, 8);
    glPopMatrix();

    //MARTE
    glPushMatrix();
      glTranslated (2.5, 0.0, 0.0);
      glColor3f (0.6, 0.0, 0.0);
      glutSolidSphere(0.08, 10, 8);
    glPopMatrix();
    DrawEllipse(2.5,1.1);

    //JUPITER
    glPushMatrix();
      glTranslated (3.0, 0.0, 0.0);
      glColor3f (0.5, 0.0, 0.0);
      glutSolidSphere(0.1, 10, 8);
    glPopMatrix();
    DrawEllipse(3.0,1.3);

    //SATURNO
    glPushMatrix();
      glTranslated (3.5, 0.0, 0.0);
      glColor3f (0.5, 0.3, 0.0);
      glutSolidSphere(0.091, 10, 8);
    glPopMatrix();
    DrawEllipse(3.5,1.5);

    //URANO
    glPushMatrix();
      glTranslated (3.7, 0.0, 0.0);
      glColor3f (0.1, 0.3, 0.6);
      glutSolidSphere(0.061, 10, 8);
    glPopMatrix();
    DrawEllipse(3.7,1.7);

    //NETUNO
    glPushMatrix();
      glTranslated (4.2, 0.0, 0.0);
      glColor3f (0.1, 0.1, 0.6);
      glutSolidSphere(0.051, 10, 8);
    glPopMatrix();
    DrawEllipse(4.2,1.9);

    //PLUTAO
    glPushMatrix();
      glTranslated (4.6, 0.0, 0.0);
      glColor3f (0.1, 0.5, 0.8);
      glutSolidSphere(0.031, 10, 8);
    glPopMatrix();
    DrawEllipse(4.6,2.1);

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

void spinDisplay(void)
{
  ano = (ano + 0.1) /*% 360*/;
  //day  = (day + 2 ) /*% 360*/;
  glutPostRedisplay();
}


/*
  Esta função irá controlar os botões do mouse.
  Se pressionado o botão da esquerda ela define
  a função spinDisplay como a função de "idle" do GLUT
  o comando glutIdelFunc, executa uma determinada função quando
  nenhum evento estiver ocorrendo. (pressionamento de botões etc.)
  Quando o botão do meio é pressionado a função de Idle recebe NULL
  desabilitando a animação
*/
void mouse(int button, int state, int x, int y)
{
  switch (button) {
      case GLUT_LEFT_BUTTON:
           if (state == GLUT_DOWN)
              glutIdleFunc(spinDisplay);
           break;
      case GLUT_MIDDLE_BUTTON:
           if (state == GLUT_DOWN)
              glutIdleFunc(NULL);
           break;
      default:
           break;
  }
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
    glutMouseFunc(mouse);
    glutKeyboardFunc(key);             // teclas

    //glutIdleFunc(idle);                // atualiza a tela (display)

    glClearColor(0.0,0.0,0.0,1);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glutMainLoop();

    return EXIT_SUCCESS;
}
