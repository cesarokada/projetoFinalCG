#include <GL/glut.h>

#define GL_COLOR_VENTILADOR  glColor3f( 0.1, 0.2, 0.2 )

float theta = 0.0f;

void drawVentilador(float size, float height, float theta_var){

    GL_COLOR_VENTILADOR;

    glPushMatrix ();

        glScalef(size, size, size);

        glRotatef (theta, 0.0f, 1.0f, 0.0f);
        glBegin (GL_POLYGON);
            glNormal3f(0.0, -1.0, 0.0);
            glVertex3f (-1.0f, height,-0.10f);
            glVertex3f (1.0f, height,-0.10f);
            glVertex3f (1.0f, height,0.10f);
            glVertex3f (-1.0f, height,0.10f);
        glEnd ();
        //glPopMatrix ();

        //glPushMatrix ();
//                glRotatef (theta, 0.0f, 1.0f, 0.0f);
        glBegin (GL_POLYGON);
            glNormal3f(0.0, -1.0, 0.0);
            glVertex3f (-0.10f,height,-1.0f);
            glVertex3f (-0.10f,height,1.0f);
            glVertex3f (0.10f,height,1.0f);
            glVertex3f (0.10f,height,-1.0f);
        glEnd ();

    glPopMatrix ();

    //SwapBuffers (hDC);

    theta += theta_var;

    //Sleep (1);
}
