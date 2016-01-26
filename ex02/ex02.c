/*
 *  NDC RGB Example
 *
 *  Map NDC [-1,+1] to RGB [0,1]
 *
 *  Key bindings:
 *  m/M        Cycle through shaders
 *  c/C        Jump to corners (orthogonal only)
 *  o/O        Cycle through objects
 *  s/S        Toggle size between small and large
 *  p/P        Toggle between orthogonal & perspective projection
 *  a          Toggle axes
 *  arrows     Change view angle
 *  PgDn/PgUp  Zoom in and out
 *  0          Reset view angle
 *  ESC        Exit
 */
#include "CSCIx239.h"
int axes=1;       //  Display axes
int mode=0;       //  Shader mode
int move=1;       //  Move light
int proj=0;       //  Projection type
int obj=0;        //  Object
int loc=0;        //  Corner locations
int th=0;         //  Azimuth of view angle
int ph=0;         //  Elevation of view angle
int fov=55;       //  Field of view (for perspective)
double size=1;    //  Size of object
double asp=1;     //  Aspect ratio
double dim=3.0;   //  Size of world
double x,y,z;     //  Location
int model;        //  Model display list
int shader[] = {0,0,0,0}; //  Shader program
char* text[] = {"None","Vertex and Fragment","Vertex Only","Fragment Only"};

/*
 *  Set projection (override library to tighten front and back planes)
 */
void Project(double fov,double asp,double dim)
{
   //  Tell OpenGL we want to manipulate the projection matrix
   glMatrixMode(GL_PROJECTION);
   //  Undo previous transformations
   glLoadIdentity();
   //  Perspective transformation
   if (fov)
      gluPerspective(fov,asp,dim/2,3*dim);
   //  Orthogonal transformation
   else
      glOrtho(-asp*dim,asp*dim,-dim,+dim,-dim,+dim);
   //  Switch to manipulating the model matrix
   glMatrixMode(GL_MODELVIEW);
   //  Undo previous transformations
   glLoadIdentity();
}

/*
 *  Draw a cube
 *  Note w=10 just to make this interesting
 */
static void Cube(void)
{
   glBegin(GL_QUADS);
   //  Front
   glColor3f(1,0,0);
   glVertex4f(-10,-10,+10,10);
   glVertex4f(+10,-10,+10,10);
   glVertex4f(+10,+10,+10,10);
   glVertex4f(-10,+10,+10,10);
   //  Back
   glColor3f(0,0,1);
   glVertex4f(+10,-10,-10,10);
   glVertex4f(-10,-10,-10,10);
   glVertex4f(-10,+10,-10,10);
   glVertex4f(+10,+10,-10,10);
   //  Right
   glColor3f(1,1,0);
   glVertex4f(+10,-10,+10,10);
   glVertex4f(+10,-10,-10,10);
   glVertex4f(+10,+10,-10,10);
   glVertex4f(+10,+10,+10,10);
   //  Left
   glColor3f(0,1,0);
   glVertex4f(-10,-10,-10,10);
   glVertex4f(-10,-10,+10,10);
   glVertex4f(-10,+10,+10,10);
   glVertex4f(-10,+10,-10,10);
   //  Top
   glColor3f(0,1,1);
   glVertex4f(-10,+10,+10,10);
   glVertex4f(+10,+10,+10,10);
   glVertex4f(+10,+10,-10,10);
   glVertex4f(-10,+10,-10,10);
   //  Bottom
   glColor3f(1,0,1);
   glVertex4f(-10,-10,-10,10);
   glVertex4f(+10,-10,-10,10);
   glVertex4f(+10,-10,+10,10);
   glVertex4f(-10,-10,+10,10);
   glEnd();
}

/*
 *  OpenGL (GLUT) calls this routine to display the scene
 */
void display()
{
   const double len=2.0;  //  Length of axes

   //  Erase the window and the depth buffer
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   //  Enable Z-buffering in OpenGL
   glEnable(GL_DEPTH_TEST);

   //  Undo previous transformations
   glLoadIdentity();
   //  Perspective - set eye position
   if (proj)
   {
      double Ex = -2*dim*Sin(th)*Cos(ph);
      double Ey = +2*dim        *Sin(ph);
      double Ez = +2*dim*Cos(th)*Cos(ph);
      gluLookAt(Ex,Ey,Ez , 0,0,0 , 0,Cos(ph),0);
   }
   //  Orthogonal - set world orientation
   else
   {
      glRotatef(ph,1,0,0);
      glRotatef(th,0,1,0);
   }

   //  Select shader (0 => no shader)
   glUseProgram(shader[mode]);
   if (mode>0)
   {
      int id = glGetUniformLocation(shader[mode],"dim");
      if (id>=0) glUniform3f(id,glutGet(GLUT_WINDOW_WIDTH),glutGet(GLUT_WINDOW_HEIGHT),1.0);
   }

   //  Draw the model, teapot or cube
   glPushMatrix();
   glTranslated(x,y,z);
   glColor3f(1,1,0);
   glScaled(size,size,size);
   if (obj==2)
      glCallList(model);
   else if (obj==1)
      glutSolidTeapot(1.0);
   else
      Cube();
   glPopMatrix();

   //  No shader for what follows
   glUseProgram(0);

   //  Draw axes - no lighting from here on
   glColor3f(1,1,1);
   if (axes)
   {
      glBegin(GL_LINES);
      glVertex3d(0.0,0.0,0.0);
      glVertex3d(len,0.0,0.0);
      glVertex3d(0.0,0.0,0.0);
      glVertex3d(0.0,len,0.0);
      glVertex3d(0.0,0.0,0.0);
      glVertex3d(0.0,0.0,len);
      glEnd();
      //  Label axes
      glRasterPos3d(len,0.0,0.0);
      Print("X");
      glRasterPos3d(0.0,len,0.0);
      Print("Y");
      glRasterPos3d(0.0,0.0,len);
      Print("Z");
   }

   //  Display parameters
   glWindowPos2i(5,25);
   Print("Angle=%d,%d  Off=%.1f,%.1f,%.1f Dim=%.1f Projection=%s Shader=%s",
     th,ph,x,y,z,dim,proj?"Perpective":"Orthogonal",text[mode]);

   //  Render the scene and make it visible
   ErrCheck("display");
   glFlush();
   glutSwapBuffers();
}

/*
 *  GLUT calls this routine when an arrow key is pressed
 */
void special(int key,int xch,int ych)
{
   //  Right arrow key - increase angle by 5 degrees
   if (key == GLUT_KEY_RIGHT)
      th += 5;
   //  Left arrow key - decrease angle by 5 degrees
   else if (key == GLUT_KEY_LEFT)
      th -= 5;
   //  Up arrow key - increase elevation by 5 degrees
   else if (key == GLUT_KEY_UP)
      ph += 5;
   //  Down arrow key - decrease elevation by 5 degrees
   else if (key == GLUT_KEY_DOWN)
      ph -= 5;
   //  PageUp key - increase dim
   else if (key == GLUT_KEY_PAGE_DOWN)
      dim += 0.1;
   //  PageDown key - decrease dim
   else if (key == GLUT_KEY_PAGE_UP && dim>1)
      dim -= 0.1;
   //  Keep angles to +/-360 degrees
   th %= 360;
   ph %= 360;
   //  Update projection
   Project(proj?fov:0,asp,dim);
   //  Tell GLUT it is necessary to redisplay the scene
   glutPostRedisplay();
}

/*
 *  GLUT calls this routine when a key is pressed
 */
void key(unsigned char ch,int xch,int ych)
{
   //  Exit on ESC
   if (ch == 27)
      exit(0);
   //  Reset view angle
   else if (ch == '0')
      x = y = z = th = ph = 0;
   //  Toggle axes
   else if (ch == 'a' || ch == 'A')
      axes = 1-axes;
   //  Toggle projection type
   else if (ch == 'p' || ch == 'P')
      proj = 1-proj;
   //  Toggle objects
   else if (ch == 'o' || ch == 'O')
      obj = (obj+1)%3;
   //  Cycle modes
   else if (ch == 'm' || ch == 'M')
      mode = (mode+1)%4;
   //  Change size
   else if (ch == 's' || ch == 'S')
      size = 0.05/size;
   //  Change location
   else if (ch == 'x')
      x -= 0.1;
   else if (ch == 'X')
      x += 0.1;
   else if (ch == 'y')
      y -= 0.1;
   else if (ch == 'Y')
      y += 0.1;
   else if (ch == 'z')
      z -= 0.1;
   else if (ch == 'Z')
      z += 0.1;
   //  Corner locations
   else if (ch == 'c' || ch == 'C')
   {
      loc = (loc+1)%8;
      x = (loc&1 ? +1 : -1)*0.95*dim;
      y = (loc&2 ? +1 : -1)*0.95*dim;
      z = (loc&4 ? +1 : -1)*0.95*dim;
   }
   //  Reproject
   Project(proj?fov:0,asp,dim);
   //  Tell GLUT it is necessary to redisplay the scene
   glutPostRedisplay();
}

/*
 *  GLUT calls this routine when the window is resized
 */
void reshape(int width,int height)
{
   //  Ratio of the width to the height of the window
   asp = (height>0) ? (double)width/height : 1;
   //  Set the viewport to the entire window
   glViewport(0,0, width,height);
   //  Set projection
   Project(proj?fov:0,asp,dim);
}

/*
 *  Start up GLUT and tell it what to do
 */
int main(int argc,char* argv[])
{
   //  Initialize GLUT
   glutInit(&argc,argv);
   //  Request double buffered, true color window with Z buffering at 600x600
   glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
   glutInitWindowSize(600,600);
   glutCreateWindow("NDC RGB Shader");
#ifdef USEGLEW
   //  Initialize GLEW
   if (glewInit()!=GLEW_OK) Fatal("Error initializing GLEW\n");
   if (!GLEW_VERSION_2_0) Fatal("OpenGL 2.0 not supported\n");
#endif
   //  Set callbacks
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutSpecialFunc(special);
   glutKeyboardFunc(key);
   //  Load object
   model = LoadOBJ("tyra.obj");
   //  Create Shader Programs
   shader[1] = CreateShaderProg("ndcrgb.vert","ndcrgb.frag");
   shader[2] = CreateShaderProg("ndcrgb.vert",NULL);
   shader[3] = CreateShaderProg(NULL,"ndcrgb2.frag");
   //  Initialize location
   x = y = z = 0;
   //  Pass control to GLUT so it can interact with the user
   ErrCheck("init");
   glutMainLoop();
   return 0;
}
