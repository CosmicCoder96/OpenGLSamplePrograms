#include <GL/glut.h>
#include<math.h>
void init2D(float r, float g, float b)
{
// glClearColor sets the colour to clear the buffer
//to.
glClearColor(r, g, b, 0.0);
// used to set up the view volume,
//GL_MODELVIEW can be used to set up viewing
//transformation
glMatrixMode(GL_PROJECTION);
// gluOrtho2D specifies the coordinates to be used
//with the viewport which defaults to the window size.
gluOrtho2D(0.0, 200.0, 0.0, 200.0); }
void display(void)
{
float cx = 100, cy = 100, r = 50;
int num_segments = 100;
// clear the buffers currently enabled for color
//writing.
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0, 0.0, 0.0);
glBegin(GL_TRIANGLE_FAN);
for(int ii = 0; ii < num_segments; ii++)
{
float theta = 2.0f * 3.1415926f * float(ii) /
float(num_segments);//get the current angle
float x = r * cosf(theta);//calculate the x
//component
float y = r * sinf(theta);//calculate the y
//component
glVertex2f(x + cx, y + cy);//output vertex
}
glEnd();
glFlush();
}
int main(int argc, char *argv[])
{
// glutInit will initialize the GLUT library and
//negotiate a session with the window system.
glutInit(&argc,argv);
// Select a display mode with single buffer because
//its a simple application and Red, green, blue
//framebuffer
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500, 500);
glutInitWindowPosition(100, 100);
glutCreateWindow("Circle-Filled");
init2D(0.0, 0.0, 0.0);
// calls the function display everytime the display
//needs to be updated
glutDisplayFunc(display);
glutMainLoop();
}
