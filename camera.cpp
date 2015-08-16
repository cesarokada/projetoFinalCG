// Funciona com eixo X na horizontal, eixo Y na vertical e Z na profundidade.
// Fontes:
// http://www.swiftless.com/tutorials/opengl/camera2.html
// http://nehe.gamedev.net/article/camera_class_tutorial/18010/
#include <GL/glut.h>
#include <math.h>
#include "camera.h"

float moveStep = 0.5;  // passo do movimento da camera
float rotStep  = 2.0;  // passo da rotacao da camera
float mouseSensitivy = 10.0; // fator de sensibilidade do mouse

float xpos, ypos = 5, zpos = 10, // indica a posicao x, y e z da camera na cena
      xrot = 25, yrot = 0;   // indica a rotacao em x e em y sofrida pela camera.
float lastx, lasty;
float xrotrad, yrotrad;

// MOVIMENTO *******************************************************************
/*******************************************************************************
 * camMoveFront
 * Mover a camera para frente, considerando o angulo de rotacao determinado.
*******************************************************************************/
void camMoveFront() {
  // converter o angulo de rotacao para radianos
  yrotrad = (yrot / 180 * 3.141592654f);
  xrotrad = (xrot / 180 * 3.141592654f);
  // alterar a posicao da camera
  xpos += (float)(sin(yrotrad)) * moveStep; // acrescentar em X o seno do angulo com eixo Y
  zpos -= (float)(cos(yrotrad)) * moveStep; // acrescentar em Z o coss do angulo com eixo X
  ypos -= (float)(sin(xrotrad)) * moveStep; // acrescentar em Y o coss do angulo com eixo X
}
/*******************************************************************************
 * camMoveBack
 * Mover a camera para tras, considerando o angulo de rotacao determinado.
*******************************************************************************/
void camMoveBack() {
  // converter o angulo de rotacao para radianos
  yrotrad = (yrot / 180 * 3.141592654f);
  xrotrad = (xrot / 180 * 3.141592654f);
  // alterar a posicao da camera
  xpos -= (float)(sin(yrotrad)); // operacoes inversas as operacoes que movem a
  zpos += (float)(cos(yrotrad)); // camera para frente
  ypos += (float)(sin(xrotrad));
}
/*******************************************************************************
 * camMoveRight
 * Mover a camera para a direita, considerando o angulo de rotacao determinado.
*******************************************************************************/
void camMoveRight() {
  // converter o angulo de rotacao em relacao a Y para radianos
  yrotrad = (yrot / 180 * 3.141592654f);
  // alterar a posicao da camera
  xpos += (float)(cos(yrotrad)) * moveStep; // acrescentar em X, o cosseno do angulo
                                            // com eixo Y, escalado por moveStep
  zpos += (float)(sin(yrotrad)) * moveStep; // acrescentar em X, o seno do angulo
                                            // com eixo Y, escalado por moveStep
}
/*******************************************************************************
 * camMoveLeft
 * Mover a camera para a esquerda, considerando o angulo de rotacao determinado.
*******************************************************************************/
void camMoveLeft() {
  // converter o angulo de rotacao em relacao a Y para radianos
  yrotrad = (yrot / 180 * 3.141592654f);
  // alterar a posicao da camera
  xpos -= (float)(cos(yrotrad)) * moveStep; // operacoes inversas a funcao
                                            //que move a direita
  zpos -= (float)(sin(yrotrad)) * moveStep;
}

// ROTACAO *********************************************************************
/*******************************************************************************
 * camRotateUp
 * Rotacionar a camera para cima.
*******************************************************************************/
void camRotateUp() {
  xrot -= rotStep;  // diminuir o angulo em relacao ao eixo X
}
/*******************************************************************************
 * camRotateDown
 * Rotacionar a camera para baixo.
*******************************************************************************/
void camRotateDown() {
  xrot += rotStep;  // aumentar o angulo em relacao ao eixo X
}
/*******************************************************************************
 * camRotateRight
 * Rotacionar a camera para a direita.
*******************************************************************************/
void camRotateRight() {
  yrot += rotStep; // diminuir o angulo em relacao ao eixo Y
}
/*******************************************************************************
 * camRotateLeft
 * Rotacionar a camera para a esquerda.
*******************************************************************************/
void camRotateLeft() {
  yrot -= rotStep; // aumentar o angulo em relacao ao eixo Y
}

// AUXILIARES ******************************************************************
/*******************************************************************************
 * camRender
 * Posicionar a camera no local determinado.
 * Utilizar na funcao utilzada em glutDisplayFunc, antes de fazer qualquer desenho.
*******************************************************************************/
void camRender() {
 // glRotatef(xrot,1.0,0.0,0.0);      // rotacao no eixo x (esquerda e direita)
 // glRotatef(yrot,0.0,1.0,0.0);      // rotacao no eixo y (esquerda e direita)
  glRotatef(xrot,1.0,0.0,0.0);      // rotacao no eixo x (esquerda e direita)
  glRotatef(yrot,0.0,1.0,0.0);      // rotacao no eixo y (esquerda e direita)
//  glTranslated(-xpos,-ypos,-zpos);  // transladar a tela para a posicao da camera
  glTranslated(-xpos, -ypos - 2, -zpos - 8);  // transladar a tela para a posicao da camera
  //12 atras //4 esquerda
}

/*******************************************************************************
 * camMouseMove
 * Mover a camera conforme o mouse se mexe.
 * Utilizar com glutPassiveMotionFunc.
*******************************************************************************/
void camMouseMove(int x, int y) {
  // obter a diferenca entre a posicao xy do mouse,
  // e a ultima posicao do mouse armazenada
  int diffx=x-lastx;
  int diffy=y-lasty;
  // atualizar a ultima posicao obtida
  lastx=x;
  lasty=y;
  // setar a diferenca como a rotacao em x e y
  // (dividir para diminuir a sensibilidade do mouse)
  xrot += (float) diffy / mouseSensitivy;
  yrot += (float) diffx / mouseSensitivy;

//  xrot += (float) y / mouseSensitivy;
//  yrot += (float) x / mouseSensitivy;
}

/*******************************************************************************
 * camMouseMove2
 * Mover a camera, somente quando estiver com o botao esquerdo do mouse pressionado.
 * Utilizar com glutMouseFunc.
*******************************************************************************/
void camMouseMove2(int button, int state, int x, int y) {
  // se pressionou botao esquerdo do mouse
  if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {
    // executar o mouse move
    camMouseMove(x, y);
  }
}

void specialkey(int key,int x,int y)
{
    switch(key) {
        case GLUT_KEY_UP:
          camRotateUp();
          break;
        case GLUT_KEY_DOWN:
          camRotateDown();
          break;
        case GLUT_KEY_LEFT:
          camRotateLeft();
          break;
        case GLUT_KEY_RIGHT:
          camRotateRight();
          break;
    }
}
