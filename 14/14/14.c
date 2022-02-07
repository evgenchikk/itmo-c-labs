#include <stdio.h>
#include <GLUT/GLUT.h>
#include <OpenGL/OpenGL.h>
#include "14.h"

static byte Frame1[H][W][3];
static byte Frame2[H][W][3];

int run = 0;

void Display( void )
{
  glClearColor(0.0, 0.0, 0.0, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  
  run++;
  if (run % 2 == 0)
  {
    CalcNextStep(Frame1, Frame2);
    glDrawPixels(W, H, GL_BGR_EXT, GL_UNSIGNED_BYTE, Frame2);
  }
  else
  {
    CalcNextStep(Frame2, Frame1);
    glDrawPixels(W, H, GL_BGR_EXT, GL_UNSIGNED_BYTE, Frame1);
  }
  
  glFinish();
  glutSwapBuffers();
  glutPostRedisplay();
}

void Keyboard( unsigned char Key, int x, int y )
{
  if (Key == 27)
    exit(0);
  if (Key == 'f')
    glutFullScreen();
}

int main( int argc, char *argv[] )
{
  int i;
  
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(W, H);
  glutCreateWindow("Life");
  
  for (i = 0; i < 500000; i++)
    PutPixel(Frame2, rand() % W, rand() % H, 255, 0, 0);
  
  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);
  
  glutMainLoop();
  return 0;
}

