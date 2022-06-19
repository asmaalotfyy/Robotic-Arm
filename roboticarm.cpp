/*
 * Copyright (c) 1993-1997, Silicon Graphics, Inc.
 * ALL RIGHTS RESERVED
 * Permission to use, copy, modify, and distribute this software for
 * any purpose and without fee is hereby granted, provided that the above
 * copyright notice appear in all copies and that both the copyright notice
 * and this permission notice appear in supporting documentation, and that
 * the name of Silicon Graphics, Inc. not be used in advertising
 * or publicity pertaining to distribution of the software without specific,
 * written prior permission.
 *
 * THE MATERIAL EMBODIED ON THIS SOFTWARE IS PROVIDED TO YOU "AS-IS"
 * AND WITHOUT WARRANTY OF ANY KIND, EXPRESS, IMPLIED OR OTHERWISE,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY OR
 * FITNESS FOR A PARTICULAR PURPOSE.  IN NO EVENT SHALL SILICON
 * GRAPHICS, INC.  BE LIABLE TO YOU OR ANYONE ELSE FOR ANY DIRECT,
 * SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY
 * KIND, OR ANY DAMAGES WHATSOEVER, INCLUDING WITHOUT LIMITATION,
 * LOSS OF PROFIT, LOSS OF USE, SAVINGS OR REVENUE, OR THE CLAIMS OF
 * THIRD PARTIES, WHETHER OR NOT SILICON GRAPHICS, INC.  HAS BEEN
 * ADVISED OF THE POSSIBILITY OF SUCH LOSS, HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE
 * POSSESSION, USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * US Government Users Restricted Rights
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions set forth in FAR 52.227.19(c)(2) or subparagraph
 * (c)(1)(ii) of the Rights in Technical Data and Computer Software
 * clause at DFARS 252.227-7013 and/or in similar or successor
 * clauses in the FAR or the DOD or NASA FAR Supplement.
 * Unpublished-- rights reserved under the copyright laws of the
 * United States.  Contractor/manufacturer is Silicon Graphics,
 * Inc., 2011 N.  Shoreline Blvd., Mountain View, CA 94039-7311.
 *
 * OpenGL(R) is a registered trademark of Silicon Graphics, Inc.
 */

 /*
  * robot.c
  * This program shows how to composite modeling transformations
  * to draw translated and rotated hierarchical models.
  * Interaction:  pressing the s and e keys (shoulder and elbow)
  * alters the rotation of the robot arm.
  */
#include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0,hand=0, thumb = 0, point = 0, middle = 0, ring = 0, tiny = 0, thumbup = 0, pointup = 0, middleup = 0, ringup = 0, tinyup = 0; ;
int moving, startx, starty;


GLfloat angle = 0.0;   /* in degrees */
GLfloat angle2 = 0.0;   /* in degrees */


void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.6, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.6, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    //Hand
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)hand, 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.5, 0.5, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    //Thumb1
    glPushMatrix();
    glTranslatef(0.0, 0.125, -0.2);
    glRotatef((GLfloat)thumb, 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0.8);
    glPushMatrix();
    glScalef(0.5, 0.2, 0.2);
    glutWireCube(0.8);
    glPopMatrix();

    glTranslatef(0.15, 0.0, -0.8);
    glRotatef((GLfloat)thumbup, 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0.8);
    glPushMatrix();
    glScalef(0.5, 0.2, 0.2);
    glutWireCube(0.8);
    glPopMatrix();
    glPopMatrix();


    //Pointer Finger
    glPushMatrix();
    glTranslatef(0.5, 0.1, 0.0);
    glRotatef((GLfloat)point, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, 0.4);
    glPushMatrix();
    glScalef(0.6, 0.2, 0.2);
    glutWireCube(0.8);
    glPopMatrix();

    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)pointup, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.6, 0.2, 0.2);
    glutWireCube(0.8);
    glPopMatrix();
    glPopMatrix();

    //Middle Finger
    glPushMatrix();
    glTranslatef(0.5, 0.10, 0.0);
    glRotatef((GLfloat)middle, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.6, 0.2, 0.2);
    glutWireCube(0.8);
    glPopMatrix();

    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)middleup, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.6, 0.2, 0.2);
    glutWireCube(0.8);
    glPopMatrix();
    glPopMatrix();


    //Ring Finger
    glPushMatrix();
    glTranslatef(0.5, 0.1, 0.0);
    glRotatef((GLfloat)ring, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, -0.4);
    glPushMatrix();
    glScalef(0.6, 0.2, 0.2);
    glutWireCube(0.8);
    glPopMatrix();

    glTranslatef(0.5, 0.1, 0.0);
    glRotatef((GLfloat)ringup, 0.0, 0.0, 1.0);
    glTranslatef(0.0, -0.1, 0.0);
    glPushMatrix();
    glScalef(0.6, 0.2, 0.2);
    glutWireCube(0.8);
    glPopMatrix();
    glPopMatrix();


    //Pinky Finger
    glPushMatrix();
    glTranslatef(0.2, 0.1, 0.0);
    glRotatef((GLfloat)tiny, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, -0.6);
    glPushMatrix();
    glScalef(0.5, 0.2, 0.2);
    glutWireCube(0.8);
    glPopMatrix();

    glTranslatef(0.4, 0.1, 0.0);
    glRotatef((GLfloat)tinyup, 0.0, 0.0, 1.0);
    glTranslatef(0.0, -0.1, 0.0);
    glPushMatrix();
    glScalef(0.6, 0.2, 0.2);
    glutWireCube(0.8);
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(85.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}



static void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            moving = 1;
            startx = x;
            starty = y;
        }
        if (state == GLUT_UP) {
            moving = 0;
        }
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        //Shoulder
    case 's':
        shoulder = (shoulder + 5) % 360;
        glutPostRedisplay();
        break;
    case 'S':
        shoulder = (shoulder - 5) % 360;
        glutPostRedisplay();
        break;
        //Elbow
    case 'e':
        if (elbow < 180)
            elbow = (elbow + 5) % 360;
        glutPostRedisplay();
        break;
    case 'E':
        if (elbow > 0)
            elbow = (elbow - 5) % 360;
        glutPostRedisplay();
        break;
        //Hand
    case 'h':
        if (hand < 90)
            hand = (hand + 5) % 360;
        glutPostRedisplay();
        break;
    case 'H':
        if (hand > 0)
            hand = (hand - 5) % 360;
        glutPostRedisplay();
        break;

        //Thumb 
    case 'f':
        if (thumb< 90)
            thumb= (thumb + 5) % 360;
        glutPostRedisplay();
        break;
    case 'F':
        if (thumb > 0)
            thumb = (thumb - 5) % 360;
        glutPostRedisplay();
        break;

        //Pointer Finger
    case 'p':
        if (point < 90)
            point = (point + 5) % 360;
        glutPostRedisplay();
        break;
    case 'P':
        if (point > 0)
            point = (point - 5) % 360;
        glutPostRedisplay();
        break;

        //Middle Finger
    case 'm':
        if (middle < 90)
            middle = (middle + 5) % 360;
        glutPostRedisplay();
        break;
    case 'M':
        if (middle > 0)
            middle = (middle - 5) % 360;
        glutPostRedisplay();
        break;

        //Ring Finger
    case 'r':
        if (ring < 90)
            ring = (ring + 5) % 360;
        glutPostRedisplay();
        break;
    case 'R':
        if (ring > 0)
            ring = (ring - 5) % 360;
        glutPostRedisplay();
        break;

        //Pinky Finger
    case 't':
        if (tiny < 90)
            tiny = (tiny + 5) % 360;
        glutPostRedisplay();
        break;
    case 'T':
        if (tiny > 0)
            tiny = (tiny - 5) % 360;
        glutPostRedisplay();
        break;

        //Entire Fingers
    case 'c':
        if (thumb < 90)
            thumb = (thumb + 5) % 360;
        if (point < 90)
            point = (point + 5) % 360;
        if (middle < 90)
            middle = (middle + 5) % 360;
        if (ring < 90)
            ring = (ring + 5) % 360;
        if (tiny < 90)
            tiny = (tiny + 5) % 360;
        glutPostRedisplay();
        break;
    case 'C':
        if (thumb > 0)
            thumb = (thumb - 5) % 360;
        if (point > 0)
            point = (point - 5) % 360;
        if (middle > 0)
            middle = (middle - 5) % 360;
        if (ring > 0)
            ring = (ring - 5) % 360;
        if (tiny > 0)
            tiny = (tiny - 5) % 360;
        glutPostRedisplay();
        break;

        //Entire Fingers'joints
    case 'b':
        if (thumbup < 90)
            thumbup = (thumbup + 5) % 360;
        if (pointup < 90)
            pointup = (pointup + 5) % 360;
        if (middleup < 90)
            middleup = (middleup + 5) % 360;
        if (ringup < 90)
            ringup = (ringup + 5) % 360;
        if (tinyup < 90)
            tinyup = (tinyup + 5) % 360;
        glutPostRedisplay();
        break;
    case 'B':
        if (thumbup > 0)
            thumbup = (thumbup - 5) % 360;
        if (pointup > 0)
            pointup = (pointup - 5) % 360;
        if (middleup > 0)
            middleup = (middleup - 5) % 360;
        if (ringup > 0)
            ringup = (ringup - 5) % 360;
        if (tinyup > 0)
            tinyup = (tinyup - 5) % 360;
        glutPostRedisplay();
        break;

    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

static void motion(int x, int y)
{
    if (moving) {
        angle = angle + (x - startx);
        angle2 = angle2 + (y - starty);
        startx = x;
        starty = y;
        glutPostRedisplay();
    }
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
