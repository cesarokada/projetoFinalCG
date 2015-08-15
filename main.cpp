#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

#include "camera.h"

#define DEG2RAD 3.14159/180.0

float contMercurio = 0, contVenus = 0, contTerra = 0, contMarte = 0,
      contJupiter = 0, contSaturno = 0, contUrano = 0, contNetuno = 0,
      contPlutao = 0;

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
}

static void resize(int width, int height)
{
    ar = (float) (width) / (float) (height);

    glViewport(0, 0, width, height);

    specificVisualParameter(ar);
}

static void drawSun(){

    glColor3f (1.0, 0.60, 0.09);
    glPushMatrix();
      glTranslatef(0.0, 0.0, 0.0);
      glutSolidSphere(0.5, 24, 24);
    glPopMatrix();
}

static void drawMercurio(){

    float xMercurio, yMercurio; //Variáveis para o controle de rotação de Venus!

    if(contMercurio > 359)
        contMercurio = 0; //Completa um ciclo e recomeça outro
    else
        contMercurio += 0.1;

    xMercurio = cos(contMercurio*DEG2RAD)*1.0;
    yMercurio = sin(contMercurio*DEG2RAD)*0.5;

    glPushMatrix();
        glRotatef(1.0,0.0,1.0,0.0);
        glTranslatef(xMercurio,0.0,yMercurio);
        glColor3f(1.0, 0.0, 0.0);
        glutSolidSphere(0.05, 10, 8);
    glPopMatrix();

    DrawEllipse(1.0, 0.5);
}

static void drawVenus(){

    float xVenus, yVenus; //Variáveis para o controle de rotação de Venus!

    if(contVenus > 359)
        contVenus = 0; //Completa um ciclo e recomeça outro
    else
        contVenus += 0.1;

    xVenus = cos(contVenus*DEG2RAD)*1.5;
    yVenus = sin(contVenus*DEG2RAD)*0.7;

    glPushMatrix();
        glRotatef(1.0,0.0,1.0,0.0);
        glTranslatef(xVenus,0.0,yVenus);
        glColor3f (0.8, 0.4, 0.2);
        glutSolidSphere(0.068, 10, 8);
    glPopMatrix();

    DrawEllipse(1.5,0.7);
}

static void drawTerra(){

    float xTerra, yTerra; //Variáveis para o controle de rotação de Venus!

    if(contTerra > 359)
        contTerra = 0; //Completa um ciclo e recomeça outro
    else
        contTerra += 0.365;//o incrimento determina o n

    xTerra = cos(contTerra*DEG2RAD)*2.0;
    yTerra = sin(contTerra*DEG2RAD)*0.9;

    glPushMatrix();
        glRotatef(1.0,0.0,1.0,0.0);
        glTranslatef(xTerra,0.0,yTerra);
        glColor3f (0.2, 0.2, 1.0);
        glutSolidSphere(0.08, 10, 8);
    glPopMatrix();

    DrawEllipse(2.0,0.9);
}

static void drawMarte(){

    float xMarte, yMarte; //Variáveis para o controle de rotação de Venus!

    if(contMarte > 359)
        contMarte = 0; //Completa um ciclo e recomeça outro
    else
        contMarte += 0.01;//o incrimento determina o n

    xMarte = cos(contMarte*DEG2RAD)*2.5;
    yMarte = sin(contMarte*DEG2RAD)*1.1;

    glPushMatrix();
        glRotatef(1.0,0.0,1.0,0.0);
        glTranslatef(xMarte,0.0,yMarte);
        glColor3f (0.6, 0.0, 0.0);
        glutSolidSphere(0.08, 10, 8);
    glPopMatrix();

    DrawEllipse(2.5,1.1);
}

static void drawJupiter(){

    float xJupiter, yJupiter; //Variáveis para o controle de rotação de Venus!

    if(contJupiter > 359)
        contJupiter = 0; //Completa um ciclo e recomeça outro
    else
        contJupiter += 0.02;//o incrimento determina o n

    xJupiter = cos(contJupiter*DEG2RAD)*3.0;
    yJupiter = sin(contJupiter*DEG2RAD)*1.3;

    glPushMatrix();
       glRotatef(1.0,0.0,1.0,0.0);
       glTranslatef(xJupiter,0.0,yJupiter);
       glColor3f (0.5, 0.0, 0.0);
       glutSolidSphere(0.1, 10, 8);
    glPopMatrix();

    DrawEllipse(3.0,1.3);
}

static void drawSaturno(){

    float xSaturno, ySaturno;

    if(contSaturno > 359)
        contSaturno = 0;
    else
        contSaturno += 0.01;

    xSaturno = cos(contSaturno*DEG2RAD)*3.5;
    ySaturno = sin(contSaturno*DEG2RAD)*1.5;

    glPushMatrix();
        glRotatef(1.0, 0.0, 1.0, 0.0);
        glTranslatef(xSaturno, 0.0, ySaturno);
        glColor3f(0.5, 0.3, 0.0);
        glutSolidSphere(0.091, 10, 8);
    glPopMatrix();

    DrawEllipse(3.5,1.5);
}

static void drawUrano(){

    float xUrano, yUrano;

    if(contUrano > 359)
        contUrano = 0;
    else
        contUrano += 0.01;

    xUrano = cos(contUrano*DEG2RAD)*4.0;
    yUrano = sin(contUrano*DEG2RAD)*1.7;

    glPushMatrix();
        glRotatef(1.0, 0.0, 1.0, 0.0);
        glTranslatef(xUrano, 0.0, yUrano);
        glColor3f (0.1, 0.3, 0.6);
        glutSolidSphere(0.061, 10, 8);
    glPopMatrix();

    DrawEllipse(4.0,1.7);
}

static void drawNetuno(){

    float xNetuno, yNetuno;

    if(contNetuno > 359)
        contNetuno = 0;
    else
        contNetuno += 0.5;

    xNetuno = cos(contNetuno*DEG2RAD)*4.5;
    yNetuno = sin(contNetuno*DEG2RAD)*1.9;

    glPushMatrix();
        glRotatef(1.0, 0.0, 1.0, 0.0);
        glTranslatef(xNetuno, 0.0, yNetuno);
        glColor3f(0.1, 0.1, 0.6);
        glutSolidSphere(0.051, 10, 8);
    glPopMatrix();

    DrawEllipse(4.5, 1.9);
}

static void drawPlutao(){

    float xPlutao, yPlutao;

    if(contPlutao > 359)
        contPlutao = 0;
    else
        contPlutao += 0.25;

    xPlutao = cos(contPlutao*DEG2RAD)*5.0;
    yPlutao = sin(contPlutao*DEG2RAD)*2.1;

    glPushMatrix();
    glRotatef(1.0, 0.0, 1.0, 0.0);
      glTranslatef(xPlutao, 0.0, yPlutao);
      glColor3f(0.1, 0.5, 0.8);
      glutSolidSphere(0.031, 10, 8);
    glPopMatrix();

    DrawEllipse(5.0,2.1);
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    camRender();

    drawLight();

    //SOL
    drawSun();

    //MERCURIO
    drawMercurio();

    //VENUS
    drawVenus();

    //TERRA
    drawTerra();

    //MARTE
    drawMarte();

    //JUPITER
    drawJupiter();

    //SATURNO
    drawSaturno();

    //URANO
    drawUrano();

    //NETUNO
    drawNetuno();

    //PLUTAO
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
