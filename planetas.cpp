#include <GL/glut.h>
#include <math.h>

#include "planetas.h"

#define DEG2RAD 3.14159/180.0

float contMercurio = 0, contVenus = 0, contTerra = 0, contMarte = 0,
      contJupiter = 0, contSaturno = 0, contUrano = 0, contNetuno = 0,
      contPlutao = 0;

void DrawEllipse(float radiusX, float radiusZ)
{
   int i;

   glBegin(GL_LINE_LOOP);
       for(i = 0; i < 360; i++)
       {
          float rad = i * DEG2RAD;
          glVertex3f(cos(rad) * radiusX, 0, sin(rad) * radiusZ);
       }
   glEnd();
}

void drawSun(){

    glColor3f (1.0, 0.60, 0.09);
    glPushMatrix();
      glTranslatef(0.0, 0.0, 0.0);
      glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
}

void drawMercurio(){

    float xMercurio, yMercurio; //Variáveis para o controle de rotação de Venus!

    if(contMercurio > 359)
        contMercurio = 0; //Completa um ciclo e recomeça outro
    else
        contMercurio += 0.2;

    xMercurio = cos(contMercurio*DEG2RAD)*3.2;
    yMercurio = sin(contMercurio*DEG2RAD)*2.8;
    glPushMatrix();
        glRotatef(1.0,0.0,1.0,0.0);
        glTranslatef(xMercurio,0.0,yMercurio);
        glColor3f(1.0, 0.0, 0.0);
        glutSolidSphere(0.05, 100, 100);
    glPopMatrix();

    DrawEllipse(3.2, 2.8);
}

void drawVenus(){

    float xVenus, yVenus; //Variáveis para o controle de rotação de Venus!

    if(contVenus > 359)
        contVenus = 0; //Completa um ciclo e recomeça outro
    else
        contVenus += 0.08;

    xVenus = cos(contVenus*DEG2RAD)*3.7;
    yVenus = sin(contVenus*DEG2RAD)*3.0;

    glPushMatrix();
        glRotatef(1.0,0.0,1.0,0.0);
        glTranslatef(xVenus,0.0,yVenus);
        glColor3f (0.8, 0.4, 0.2);
        glutSolidSphere(0.1, 100, 100);
    glPopMatrix();

    DrawEllipse(3.7, 3.0);
}

void drawTerra(){

    float xTerra, yTerra; //Variáveis para o controle de rotação de Venus!

    if(contTerra > 359)
        contTerra = 0; //Completa um ciclo e recomeça outro
    else
        contTerra += 0.05;//o incrimento determina o n

    xTerra = cos(contTerra*DEG2RAD)*4.2;
    yTerra = sin(contTerra*DEG2RAD)*3.2;

    glPushMatrix();
        glRotatef(1.0,0.0,1.0,0.0);
        glTranslatef(xTerra,0.0,yTerra);
        glColor3f (0.2, 0.2, 1.0);
        glutSolidSphere(0.1, 100, 100);
    glPopMatrix();

    DrawEllipse(4.2, 3.2);
}

void drawMarte(){

    float xMarte, yMarte; //Variáveis para o controle de rotação de Venus!

    if(contMarte > 359)
        contMarte = 0; //Completa um ciclo e recomeça outro
    else
        contMarte += 0.026;//o incrimento determina o n

    xMarte = cos(contMarte*DEG2RAD)*4.7;
    yMarte = sin(contMarte*DEG2RAD)*3.4;

    glPushMatrix();
        glRotatef(1.0,0.0,1.0,0.0);
        glTranslatef(xMarte,0.0,yMarte);
        glColor3f (0.6, 0.0, 0.0);
        glutSolidSphere(0.07, 100, 100);
    glPopMatrix();

    DrawEllipse(4.7, 3.4);
}

void drawJupiter(){

    float xJupiter, yJupiter; //Variáveis para o controle de rotação de Venus!

    if(contJupiter > 359)
        contJupiter = 0; //Completa um ciclo e recomeça outro
    else
        contJupiter += 0.058;//o incrimento determina o n

    xJupiter = cos(contJupiter*DEG2RAD)*5.5;
    yJupiter = sin(contJupiter*DEG2RAD)*4.0;

    glPushMatrix();
       glRotatef(1.0,0.0,1.0,0.0);
       glTranslatef(xJupiter,0.0,yJupiter);
       glColor3f (0.74, 0.74, 0.74);
       glutSolidSphere(0.5, 100, 100);
    glPopMatrix();

    DrawEllipse(5.5, 4.0);
}

void drawSaturno(){

    float xSaturno, ySaturno;

    if(contSaturno > 359)
        contSaturno = 0;
    else
        contSaturno += 0.0017;

    xSaturno = cos(contSaturno*DEG2RAD)*6.5;
    ySaturno = sin(contSaturno*DEG2RAD)*5.0;

    glPushMatrix();
        glRotatef(1.0, 0.0, 1.0, 0.0);
        glTranslatef(xSaturno, 0.0, ySaturno);
        glColor3f(0.92, 0.78, 0.61);
        glutSolidSphere(0.4, 100, 100);
    glPopMatrix();

    DrawEllipse(6.5, 5.0);
}

void drawUrano(){

    float xUrano, yUrano;

    if(contUrano > 359)
        contUrano = 0;
    else
        contUrano += 0.0006;

    xUrano = cos(contUrano*DEG2RAD)*7.5;
    yUrano = sin(contUrano*DEG2RAD)*6.0;

    glPushMatrix();
        glRotatef(1.0, 0.0, 1.0, 0.0);
        glTranslatef(xUrano, 0.0, yUrano);
        glColor3f (0.37, 0.62, 0.62);
        glutSolidSphere(0.2, 100, 100);
    glPopMatrix();

    DrawEllipse(7.5, 6.0);
}

void drawNetuno(){

    float xNetuno, yNetuno;

    if(contNetuno > 359)
        contNetuno = 0;
    else
        contNetuno += 0.0003;

    xNetuno = cos(contNetuno*DEG2RAD)*8.0;
    yNetuno = sin(contNetuno*DEG2RAD)*6.5;

    glPushMatrix();
        glRotatef(1.0, 0.0, 1.0, 0.0);
        glTranslatef(xNetuno, 0.0, yNetuno);
        glColor3f(0.1, 0.1, 0.6);
        glutSolidSphere(0.2, 100, 100);
    glPopMatrix();

    DrawEllipse(8.0, 6.5);
}

void drawPlutao(){

    float xPlutao, yPlutao;

    if(contPlutao > 359)
        contPlutao = 0;
    else
        contPlutao += 0.0002;

    xPlutao = cos(contPlutao*DEG2RAD)*8.5;
    yPlutao = sin(contPlutao*DEG2RAD)*7.5;

    glPushMatrix();
    glRotatef(1.0, 0.0, 1.0, 0.0);
      glTranslatef(xPlutao, 0.0, yPlutao);
      glColor3f(0.1, 0.5, 0.8);
      glutSolidSphere(0.031, 100, 100);
    glPopMatrix();

    DrawEllipse(8.5, 7.5);
}
