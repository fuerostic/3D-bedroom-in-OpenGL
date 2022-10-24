#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include<math.h>
#include<iostream>
#include "BmpLoader.h"


#define PI 3.14159265


using namespace std;

double Txval=0,Tyval=0,Tzval=0;
double windowHeight=1080, windowWidth=720;
GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0;
GLfloat upDown=3, leftRight = 10, farNear= 10;
GLfloat gscale=1,cdist=0,fdist=0; //zooming constant
GLfloat lpan=0,rpan=0;  //panning constant
GLboolean  bulb_switch = false, tube_switch=false, lamp_switch=false, bulb_ambient_light=true, bulb_diffusion_light=true, bulb_specular_light=true, tube_ambient_light=true, tube_diffusion_light=true, tube_specular_light=true, lamp_ambient_light=true, lamp_diffusion_light=true, lamp_specular_light=true;
GLboolean birds_eye =false;
GLfloat initialEyex= 130,initialEyey=55,initialEyez= 75,initialxaxis=0,initialyaxis=1,initialzaxis=0,initialx=40,initialy=40,initialz=0;
GLfloat x=40,y=40,z=0,roll=0,pitch=0, yaw=0,eyex= 130,eyey=55,eyez=75,dx=0,dy=0,dz=0,xaxis=0,yaxis=1,zaxis=0; //for pitch , yaw, roll
GLboolean bRotate = false, uRotate = false;

GLuint ID[]={1,3,4,5,6,7,8,9,10,11,12,13,15,17,18,19,20,21,22,23,24,25,27,29,30,31};

string dir= "C:\\Users\\EON\\Documents\\Codes\\Graphics lab\\3D-bedroom-in-OpenGL"; //change this to your own directory

float color1[] = {1,1,1};
float color2[] = {.8,.2,.2};
float color3[] = {.8,.2,.7};
float color4[] = {0,1,.7};


//colors
float red[] = {1.0 ,0.0 ,0.0};
float green[] = {0.0 ,1.0 ,0.0};
float blue[] = {0.0, 0.0 ,1.0};
float yellow[] = {1.0 ,1.0, 0.0};
float purple[] = {1.0 ,0.0,1.0};
float cyan[] = {0.0 ,1.0, 1.0};
float white[] = {1.0 ,1.0 ,1.0};
float orange[] = {1.0 ,0.5, 0.0};
float greenish_yellow[] = {0.5, 1.0 ,0.0};
float light_green[] = {0.5, 1.0 ,0.5};
float dark_green[] = {0.0, 0.5, 0.0};
float magenta[] = {1,0,1};
float violet[] = {0.5f, 0.5f, 0.5f};
float baby_blue[]= {0.0f, 0.5f, 1.0f};
float lilac[] ={2.0f, 0.5f, 1.0f};
float dark_grey[] = {0.1f, 0.1f, 0.1f};
float dark_purple[] = {0.1f, 0.0f, 0.1f};
float bronze[] ={0.1f, 0.1f, 0.0f};
float dark_blue[] = {0.0f, 0.1f, 0.1f};
float forest_green[] = {0.0f, 0.1f, 0.0f};
float brown[] = {0.1f, 0.0f, 0.0f};
float light_blue[] = {0.0f, 1.0f, 1.0f, 1.0f};
float chair_wood[] = {.20,.14,.14};
float table_wood[] = {.30,.14,.14};
float bed_wood[] = {.568,.318,.004};
float pillow_color[] = {0,1,.7};
float closet_wood[] = {1,.5,0};
float plastic_black[] = {.2,.2,.2};
float tiles_white[] = {.7,.7,.7};
float grey[] = {.4,.4,.4};



using namespace std;

static void getNormal3p(GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(Nx,Ny,Nz);
}


void drawCube(float x, float y, float z, float xheight, float yheight, float zheight, float color[],float shine=60)
{

    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { color[0]*.3, color[1]*.3, color[2]*.3,1.0 };
    GLfloat mat_diffuse[] = { color[0], color[1], color[2], 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {shine};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

//    static GLfloat v_cube[8][3] =
//    {
//        {x,y,z},
//        {x,y,z+zheight},
//        {x+xheight,y,z+zheight},
//        {x+xheight,y,z},
//        {x, y+yheight, z},
//        {x,y+yheight,z + zheight},
//        {x+xheight,y+yheight,z+zheight},
//        {x+xheight,y+yheight,z}
//
//    };
//
//    static GLubyte quadIndices[2][8] =
//    {
//        {1,5,2,6,3,7,0,4},
//        {7,6,4,5,0,1,3,2}
//    };


    static GLfloat v_cube[8][3] =
{
    {0.0, 0.0, 0.0}, //0
    {0.0, 0.0, 1.0}, //1
    {1.0, 0.0, 1.0}, //2
    {1.0, 0.0, 0.0}, //3
    {0.0, 1.0, 0.0}, //4
    {0.0, 1.0, 1.0}, //5
    {1.0, 1.0, 1.0}, //6
    {1.0, 1.0, 0.0}  //7
};

    static GLubyte quadIndices[6][4] =
    {
        {0, 1, 2, 3}, //bottom
        {4, 5, 6, 7}, //top
        {5, 1, 2, 6}, //front
        {0, 4, 7, 3}, // back is clockwise
        {2, 3, 7, 6}, //right
        {1, 5, 4, 0}  //left is clockwise
    };


//    glBegin(GL_QUAD_STRIP);
//    for (GLint i = 0; i <2; i++)
//    {
//
//        //glColor3f(color[0],color[1],color[2]);
//        getNormal3p(v_cube[quadIndices[i][0]][0], v_cube[quadIndices[i][0]][1], v_cube[quadIndices[i][0]][2],
//                    v_cube[quadIndices[i][1]][0], v_cube[quadIndices[i][1]][1], v_cube[quadIndices[i][1]][2],
//                    v_cube[quadIndices[i][2]][0], v_cube[quadIndices[i][2]][1], v_cube[quadIndices[i][2]][2]);
//
//        glVertex3fv(&v_cube[quadIndices[i][0]][0]);
//        glVertex3fv(&v_cube[quadIndices[i][1]][0]);
//        glVertex3fv(&v_cube[quadIndices[i][2]][0]);
//        glVertex3fv(&v_cube[quadIndices[i][3]][0]);
//        glVertex3fv(&v_cube[quadIndices[i][4]][0]);
//        glVertex3fv(&v_cube[quadIndices[i][5]][0]);
//        glVertex3fv(&v_cube[quadIndices[i][6]][0]);
//        glVertex3fv(&v_cube[quadIndices[i][7]][0]);
//    }
//    glEnd();

    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {
        getNormal3p(v_cube[quadIndices[i][0]][0], v_cube[quadIndices[i][0]][1], v_cube[quadIndices[i][0]][2],
                    v_cube[quadIndices[i][1]][0], v_cube[quadIndices[i][1]][1], v_cube[quadIndices[i][1]][2],
                    v_cube[quadIndices[i][2]][0], v_cube[quadIndices[i][2]][1], v_cube[quadIndices[i][2]][2]);
//        glVertex3fv(&v_cube[quadIndices[i][0]][0]);
//        glVertex3fv(&v_cube[quadIndices[i][1]][0]);
//        glVertex3fv(&v_cube[quadIndices[i][2]][0]);
//        glVertex3fv(&v_cube[quadIndices[i][3]][0]);

        glVertex3fv(&v_cube[quadIndices[i][0]][0]);glTexCoord2f(0,1);
        glVertex3fv(&v_cube[quadIndices[i][1]][0]);glTexCoord2f(0,0);
        glVertex3fv(&v_cube[quadIndices[i][2]][0]);glTexCoord2f(1,0);
        glVertex3fv(&v_cube[quadIndices[i][3]][0]);glTexCoord2f(1,1);
    }
    glEnd();

//    glPushMatrix();
//    glTranslatef(.5,.5,.5);
//    glutSolidCube(1);
//    glPopMatrix();


}


void chair(int basex, int basey,float legsize, float topsize, float px, float py, float pz )
{


    glPushMatrix();
    glTranslatef(px,py,pz);


    //base
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,3);

    glPushMatrix();
    glScalef(basex, 1, basey);
    glTranslatef(-0.5,0,-0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();


    //legs
    glPushMatrix();
    glTranslatef(3,-2.5,3);
    glScalef(1,legsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3,-2.5,3);
    glScalef(1,legsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3,-2.5,-3);
    glScalef(1,legsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3,-2.5,-3);
    glScalef(1,legsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();

    //leg top

    glPushMatrix();
    glTranslatef(3,3,-3);
    glScalef(1,topsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3,3,-3);
    glScalef(1,topsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();


    //top leg connector
    glPushMatrix();
    glTranslatef(0,4.5,-3);
    glScalef(5,3,1);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    glPopMatrix();


}


void table(int basex, int basey,float legsize, float px, float py, float pz )
{

    glPushMatrix();
    glTranslatef(px,py,pz);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,3);

    //base
    glPushMatrix();
    glScalef(basex, 1, basey);
    glTranslatef(-0.55,0,-0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();


    //legs
    glPushMatrix();
    glTranslatef(5,-2.5,3);
    glScalef(.5,legsize,.5);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6,-2.5,3);
    glScalef(.5,legsize,.5);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,-2.5,-3);
    glScalef(.5,legsize,.5);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6,-2.5,-3);
    glScalef(.5,legsize,.5);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();


    glDisable(GL_TEXTURE_2D);

    glPopMatrix();


}



void bed(int basex, int basey,float legsize, float topsize, float px, float py, float pz )
{


    glPushMatrix();
    glTranslatef(px,py,pz);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,13);
    //matress

    glPushMatrix();
    glScalef(basex-1, 1, basey-1);
    glTranslatef(-0.55,0,-0.56);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    //blanket
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,15);
    glPushMatrix();
    glScalef(basex-.5, 1.5, basey-9.5);
    glTranslatef(-0.55,0,-.3);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    //pillow
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,14);
    glPushMatrix();
    glScalef(basex-5, 2.5, basey-19);
    glTranslatef(-0.55,0,-2.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,3);
    //base
    glPushMatrix();
    glScalef(basex, 4, basey);
    glTranslatef(-0.55,-1,-0.56);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();


    //legs
    glPushMatrix();
    glTranslatef(5,-2.5,10);
    glScalef(1,legsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6,-2.5,10);
    glScalef(1,legsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,-2.5,-13);
    glScalef(1,legsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6,-2.5,-13);
    glScalef(1,legsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(5,0,-13);
    glScalef(1,topsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6,0,-13);
    glScalef(1,topsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();


    //top leg connector
    glPushMatrix();
    glTranslatef(-0.55,1.5,-13);
    glScalef(10,6,1);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();



    //leg down top

    glPushMatrix();
    glTranslatef(5,-1,10);
    glScalef(1,legsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6,-1,10);
    glScalef(1,legsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();

    //down leg connector

    glPushMatrix();
    glTranslatef(-0.55,0.75,10);
    glScalef(10,5,1);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPopMatrix();


}

void closet(int basex, int basey,float topsize, float px, float py, float pz)
{

    glPushMatrix();
    glTranslatef(px,py,pz);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,5);

    //basebottom
    glPushMatrix();
    glScalef(basex, 1, basey);
    glTranslatef(-0.5,-12,-0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();

    //basetop
    glPushMatrix();
    glScalef(basex, 1, basey);
    glTranslatef(-0.5,8,-0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();


    //legs
    glPushMatrix();
    glTranslatef(8.5,-2.5,3);
    glScalef(1,topsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-8.5,-2.5,3);
    glScalef(1,topsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(8.5,-2.5,-3);
    glScalef(1,topsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-8.5,-2.5,-3);
    glScalef(1,topsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();

    //side connector

    glPushMatrix();
    glTranslatef(7,-2,0);
    glScalef(1,topsize-3,basey-2);
    glTranslatef(-0.1, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-7.5,-2,.5);
    glScalef(1,topsize-3,basey-2);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white,20);
    glPopMatrix();



    //top leg connector


    glPushMatrix();
    glTranslatef(0,-2,-3);
    glScalef(basex-2,23,2.5);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-2,2.5);
    glScalef(basex-2,23,2.5);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white,20);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    //door

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,6);

    glPushMatrix();
    glTranslatef(4.5,-2,3);
    glScalef(basex-12,20,2);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.5,-2,3);
    glScalef(basex-12,20,2);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    //handle

    glPushMatrix();
    glTranslatef(2.5,1.75,4);
    glScalef(.5,2,1);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white ,100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.5,1.75,4);
    glScalef(.5,2,1);
    glTranslatef(-0.5, -0.5, -0.5);
    drawCube(0,0,0,1,1,1,white,100);
    glPopMatrix();


    glPopMatrix();


}

void laptop(int basex, int basey, float px, float py, float pz,float color[] )
{
    glPushMatrix();
    glTranslatef(px,py,pz);


    //base
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,17);
    glPushMatrix();
    glTranslatef(0,4.5,-3);
    glScalef(5,.5,3);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    //monitor
    glPushMatrix();
    glTranslatef(0,4.5,-3);
    glScalef(5,3,.5);
    drawCube(0,0,0,1,1,1,plastic_black);
    glPopMatrix();

    //display
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,12);
    glPushMatrix();
    glTranslatef(0.5,5,-2.5);
    glScalef(4.2,2.2,.1);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPopMatrix();


}


void interior(int basex, int basey, float px, float py, float pz )
{

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();


    glTranslatef(px,py,pz);


    //base
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,1);
    glTranslatef(0,4.5,-3);
    glScalef(basex,.5,basey);
    drawCube(0,0,0,1,1,1,tiles_white,110);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);



    //wall1
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D,9);
    glPushMatrix();
    glTranslatef(0,4.5,-3);
    glScalef(basex,basey+10,1);
    drawCube(0,0,0,1,1,1,baby_blue,100);
    glPopMatrix();

    //wall2
    glPushMatrix();
    glTranslatef(0,4.5,-3);
    glScalef(1,basey+10,basey);
    drawCube(0,0,0,1,1,1,baby_blue,100);
    glPopMatrix();

    ////wall3.left
    glPushMatrix();
    glTranslatef(100,4.5,-3);
    glScalef(1,basey+10,basey-(basey*.6));
    drawCube(0,0,0,1,1,1,baby_blue,100);
    glPopMatrix();

    //////wall3 right
    glPushMatrix();
    glTranslatef(100,4.5,51);
    glScalef(1,basey+10,basey-(basey*.6));
    drawCube(0,0,0,1,1,1,baby_blue,100);
    glPopMatrix();

    //wall 3 down
    glPushMatrix();
    glTranslatef(100,4.5,-3);
    glScalef(1,basey-(basey*.7),basey);
    drawCube(0,0,0,1,1,1,baby_blue,10);
    glPopMatrix();

    //wall3 up
    glPushMatrix();
    glTranslatef(100,68,-3);
    glScalef(1,basey-(basey*.7)+10,basey);
    drawCube(0,0,0,1,1,1,baby_blue,100);
    glPopMatrix();

    //outside
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,25);
    glPushMatrix();
    glTranslatef(110,23,-3);
    glScalef(1,basey-(basey*.7)+25,basey-20);
    drawCube(0,0,0,1,1,1,white,10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //ceiling
    glPushMatrix();
    glTranslatef(0,100,-3);
    glScalef(basex,.5,basey);
    drawCube(0,0,0,1,1,1,grey,100);
    glPopMatrix();


    glDisable(GL_TEXTURE_2D);

    //curtain base
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,3);
    glPushMatrix();
    glTranslatef(98,70,30);
    glScalef(1,5,25);
    drawCube(0,0,0,1,1,1,white,100);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    //curtain1

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,4);
    glPushMatrix();
    glTranslatef(99,20,40);
    glRotatef(180,0,1,0);
    glScalef(.5,52,8);
    drawCube(0,0,0,1,1,1,tiles_white,100);
    glPopMatrix();

    //curtain2
    glPushMatrix();
    glTranslatef(99,20,54);
    glRotatef(180,0,1,0);
    glScalef(.5,52,3);
    drawCube(0,0,0,1,1,1,tiles_white,100);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);



    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


}
void book(float px, float py, float pz ,float color[]=dark_blue,int ID=19)
{


    glPushMatrix();
    glTranslatef(px,py,pz);


    //base

    glPushMatrix();
    glTranslatef(0,10,-3);
    glScalef(5,.5,1);
    drawCube(0,0,0,1,1,1,color);
    glPopMatrix();


    //cover1
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,ID);
    glPushMatrix();
    glTranslatef(0,4.5,-3);
    glScalef(5,6,.2);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //cover2
    glPushMatrix();
    glTranslatef(0,4.5,-2.1);
    glScalef(5,6,.2);
    drawCube(0,0,0,1,1,1,color);
    glPopMatrix();


    //page
    glPushMatrix();
    glTranslatef(0,5,-2.8);
    glScalef(5,5,.7);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();


    glPopMatrix();
}

void fan( float px, float py, float pz)
{


    float shine = 60;

    glPushMatrix();
    glTranslatef(px,py,pz);

    //fan base
    glPushMatrix();
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient1[] = { orange[0]*.3, orange[1]*.3, orange[2]*.3,1.0 };
    GLfloat mat_diffuse1[] = { orange[0], orange[1], orange[2], 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess1[] = {shine};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient1);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse1);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess1);
    glScalef(1,1,1);
    gluCylinder(gluNewQuadric(), 5, 5, 2,100, 100);


    glPopMatrix();

    //back

    glPushMatrix();


    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient1);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse1);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess1);
    gluDisk(gluNewQuadric(),1,5,32,32);
    glPopMatrix();



    //front

    glPushMatrix();
    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient1);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse1);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess1);
    glTranslatef(0,0,2);
    gluDisk(gluNewQuadric(),0,5,32,32);
    glPopMatrix();

    //cone1

    glPushMatrix();

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient1);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse1);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess1);
    glTranslatef(0,0,-3);
    gluCylinder(gluNewQuadric(),1,4,3,32,32);

    glPopMatrix();


    //rod
    glPushMatrix();


    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient1);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse1);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess1);
    glTranslatef(0,0,-12);
    gluCylinder(gluNewQuadric(),1,1,10,32,32);
    glPopMatrix();


    //cone2
    glPushMatrix();

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient1);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse1);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess1);
    glTranslatef(0,0,-15);
    gluCylinder(gluNewQuadric(),2.5,1,3,32,32);
    glPopMatrix();

    //connector1
    glPushMatrix();
    glRotatef(5,0,1,0);
    glTranslatef(-1,5,0.5);
    glScalef(2,4,.7);
    drawCube(0,0,0,1,1,1,tiles_white);

    glPopMatrix();

    //connector2
    glPushMatrix();
    glRotatef(5,0,1,0);
    glTranslatef(5,-5,0.5);
    glRotatef(45,0,0,1);

    glScalef(2,4,.7);
    drawCube(0,0,0,1,1,1,tiles_white);
    glPopMatrix();

    //connector3
    glPushMatrix();
    glRotatef(5,0,1,0);
    glTranslatef(-6,-4,0.5);
    glRotatef(-45,0,0,1);

    glScalef(2,4,.7);
    drawCube(0,0,0,1,1,1,tiles_white);
    glPopMatrix();

    //blade 1

    glPushMatrix();
    glRotatef(5,0,1,0);
    glTranslatef(-1.8,6,0.5);
    glScalef(3.5,25,.5);
    drawCube(0,0,0,1,1,1,orange);
    glPopMatrix();

    //blade2
    glPushMatrix();
    glRotatef(5,0,1,0);
    glTranslatef(20,-21,0.5);
    glRotatef(45,0,0,1);
    glScalef(3.5,25,.5);
    drawCube(0,0,0,1,1,1,orange);
    glPopMatrix();

    //blade3
    glPushMatrix();
    glRotatef(5,0,1,0);
    glTranslatef(-23,-20,0.5);
    glRotatef(-45,0,0,1);

    glScalef(3.5,25,.5);
    drawCube(0,0,0,1,1,1,orange);
    glPopMatrix();


    glPopMatrix();

}
void lamp(float px, float py, float pz,float lamp_bulb_color[])
{


    glPushMatrix();
    glTranslatef(px,py,pz);


    //base
    glPushMatrix();
    glTranslatef(0,4.5,-3);
    glScalef(6,3,2);
    drawCube(0,0,0,1,1,1,cyan);
    glPopMatrix();

    //base decorator

    glPushMatrix();
    glTranslatef(0,5,-3.1);
    glScalef(6.2,2,2.2);
    drawCube(0,0,0,1,1,1,dark_blue);
    glPopMatrix();

    //first arm

    glPushMatrix();
    glTranslatef(0,5,-3);
    glScalef(.5,15,.5);
    drawCube(0,0,0,1,1,1,grey);
    glPopMatrix();


    //second arm

    glPushMatrix();

    glTranslatef(0,5,-1.5);
    glScalef(.5,15,.5);
    drawCube(0,0,0,1,1,1,grey);
    glPopMatrix();


    //lamp site

    glPushMatrix();
    glRotatef(15,0,0,1);
    glTranslatef(5,19,-3);
    glScalef(7,1,2);
    drawCube(0,0,0,1,1,1,cyan);
    glPopMatrix();


    //light area

    glPushMatrix();

    glRotatef(15,0,0,1);
    glTranslatef(5.5,18.7,-2.8);
    glScalef(6.5,.5,1.5);
    drawCube(0,0,0,1,1,1,lamp_bulb_color);

    glPopMatrix();




    glPopMatrix();
}

void bulb(float px, float py, float pz,float bulb_color[])
{


    glPushMatrix();
    glTranslatef(px,py,pz);

    //base cone

    glPushMatrix();
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient1[] = { orange[0]*.3, orange[1]*.3, orange[2]*.3, 1.0 };
    GLfloat mat_diffuse1[] = { orange[0], orange[1], orange[2], 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess1[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient1);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse1);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess1);
    glTranslatef(0,0,-15);
    gluCylinder(gluNewQuadric(),2.5,1,1,32,32);
    glPopMatrix();

    //extension

    glPushMatrix();
    GLfloat mat_ambient2[] = { orange[0]*.3, orange[1]*.3, orange[2]*.3, 1.0 };
    GLfloat mat_diffuse2[] = { orange[0], orange[1],orange[2], 1.0 };
    GLfloat mat_shininess2[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient2);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse2);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess2);
    glTranslatef(0,0,-14);
    gluCylinder(gluNewQuadric(),1,1,1,32,32);
    glPopMatrix();


    //bulb head

    glPushMatrix();
    GLfloat mat_ambient3[] = { bulb_color[0]*.3, bulb_color[1]*.3, bulb_color[2]*.3, 1.0 };
    GLfloat mat_diffuse3[] = { bulb_color[0], bulb_color[1], bulb_color[2], 1.0 };
    GLfloat mat_shininess3[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient3);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse3);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess3);
    glTranslatef(0,0,-12);
    gluSphere(gluNewQuadric(),2,32,32);

    glPopMatrix();



    glPopMatrix();
}

void tubelight(float px, float py, float pz,float tubelight_bulb_color[])
{


    glPushMatrix();
    glTranslatef(px,py,pz);


    //base
    glPushMatrix();
    glScalef(6.5,.5,.7);
    drawCube(0,0,0,1,1,1,orange);
    glPopMatrix();

    //left connector
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(.5,1.5,.7);
    drawCube(0,0,0,1,1,1,orange);

    glPopMatrix();

    //right connector
    glPushMatrix();
    glTranslatef(6,0,0);
    glScalef(.5,1.5,.7);
    drawCube(0,0,0,1,1,1,orange);

    glPopMatrix();

    //tube
    glPushMatrix();
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient1[] = { tubelight_bulb_color[0]*.3, tubelight_bulb_color[1]*.3,tubelight_bulb_color[2]*.3, 1.0 };
    GLfloat mat_diffuse1[] = { tubelight_bulb_color[0], tubelight_bulb_color[1], tubelight_bulb_color[2], 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess1[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient1);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse1);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess1);
    glTranslatef(0,1,.3);
    glRotatef(90,0,1,0);
    gluCylinder(gluNewQuadric(),.3,.3,6,32,32);
    glPopMatrix();



    glPopMatrix();
}

void clock(float px, float py, float pz)
{


    glPushMatrix();
    glTranslatef(px,py,pz);

    //base circle

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,26);
    glPushMatrix();
    glTranslatef(-4,-4,0);
    glScalef(8,8,.2);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    glEnable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
    glEnable(GL_TEXTURE_GEN_T);
    glBindTexture(GL_TEXTURE_2D,6);

    //surround circle

    glPushMatrix();
    GLfloat no_mat1[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient1[] = { white[0]*.3, white[1]*.3, white[2]*.3, 1.0 };
    GLfloat mat_diffuse1[] = { white[0], white[1], white[2], 1.0 };
    GLfloat mat_specular1[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess1[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient1);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse1);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular1);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess1);

    gluCylinder(gluNewQuadric(), 5, 6, .5,100, 100);
    glPopMatrix();


    //outer circle
    glPushMatrix();
    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient1);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse1);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular1);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess1);
    glTranslatef(0,0,.5);
    gluDisk(gluNewQuadric(),4,6,32,32);
    glPopMatrix();

    glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D);


    glPopMatrix();
}

void calender(float px, float py, float pz)
{

    glPushMatrix();
    glTranslatef(px,py,pz);

    //page
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,8);
    glPushMatrix();
    glTranslatef(0,-1,0);
    glScalef(5,11,.2);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
//    //pic
//
//    glPushMatrix();
//    glTranslatef(0.1,6,0.15);
//    glScalef(4.7,3.5,.1);
//    drawCube(0,0,0,1,1,1,white);
//    glPopMatrix();
//
//
//
//    //month 1
//    glPushMatrix();
//
//    glTranslatef(.2,3,0.15);
//    glScalef(2,2.5,.1);
//    drawCube(0,0,0,1,1,1,grey);
//    glPopMatrix();
//
//    //month 2
//    glPushMatrix();
//    glTranslatef(2.7,3,0.15);
//    glScalef(2,2.5,.1);
//    drawCube(0,0,0,1,1,1,grey);
//    glPopMatrix();
//
//    //month 3
//    glPushMatrix();
//
//    glTranslatef(.2,0,0.15);
//    glScalef(2,2.5,.1);
//    drawCube(0,0,0,1,1,1,grey);
//    glPopMatrix();
//
//    //month 4
//    glPushMatrix();
//    glTranslatef(2.7,0,0.15);
//    glScalef(2,2.5,.1);
//    drawCube(0,0,0,1,1,1,grey);
//    glPopMatrix();
//


    glPopMatrix();
}

void monitor(float px, float py, float pz,   float monitor_screen[])
{

    glPushMatrix();
    glTranslatef(px,py,pz);

    //monitor
    glPushMatrix();
    glTranslatef(0,-1,0);
    glScalef(4,3.5,.2);
    drawCube(0,0,0,1,1,1,plastic_black);
    glPopMatrix();

    //display
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,11);

    glPushMatrix();

    glTranslatef(.2,-.8,0.1);
    glScalef(3.7,3.2,.11);
    drawCube(0,0,0,1,1,1,monitor_screen);

    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    //stand vertical
    glPushMatrix();
    glTranslatef(1.5,-2,-.2);
    glScalef(1,3,.2);
    drawCube(0,0,0,1,1,1,plastic_black);
    glPopMatrix();


    //stand base
    glPushMatrix();
    glTranslatef(1.25,-2,-.5);
    glScalef(1.5,.2,1);
    drawCube(0,0,0,1,1,1,plastic_black);
    glPopMatrix();



    glPopMatrix();
}

void keyboard(float px, float py, float pz)
{

    glPushMatrix();
    glTranslatef(px,py,pz);

    //base

//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D,16);
//    glPushMatrix();
//
//    glScalef(1.5,.2,.7);
//    drawCube(0,0,0,1,1,1,white);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);


    //keys part 1

//    glPushMatrix();
//    glTranslatef(1.1,0.2,0.1);
//    glScalef(.3,.1,.5);
//    drawCube(0,0,0,1,1,1,white);
//    glPopMatrix();



    //keys part2
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,16);
    glPushMatrix();
    glTranslatef(0.07,0.2,0.1);
    glScalef(1.5,.1,.5);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);



    glPopMatrix();
}

void matress(float px, float py, float pz)
{


    glPushMatrix();
    glTranslatef(px,py,pz);

    //base

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,10);
    glPushMatrix();

    glScalef(1.5,.2,.7);
    drawCube(0,0,0,1,1,1,white);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    //design 1



//    glPushMatrix();
//
//    glTranslatef(.5,0.1,0.35);
//    glRotatef(45,0,1,0);
//    glScalef(.3,.2,.3);
//    drawCube(0,0,0,1,1,1,orange);
//    glPopMatrix();
//
//    //design 2
//    glPushMatrix();
//    glTranslatef(0.22,0.12,0.1);
//    glScalef(1,.1,.5);
//    drawCube(0,0,0,1,1,1,light_blue);
//    glPopMatrix();



    glPopMatrix();
}





void scene( float px, float py, float pz )
{


    glPushMatrix();

    //scene placement
    glTranslatef(px,py,pz);

    glPushMatrix();
    interior(100,90,0,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(22,43,4);
    glScalef(1.5,2.5,1.5);
    closet(18,7,26,0,0,0);
    glPopMatrix();

    glPushMatrix();
    glRotatef(0,0,1,0);
    glTranslatef(85,17.5,21);
    glScalef(2,1.5,1.5);
    bed(12,24,12,14,0,0,0);
    glPopMatrix();


    glPushMatrix();
    glRotatef(90,0,1,0);
    glTranslatef(-60,20,10);
    glScalef(3,3,2);
    table(12,7,7,0,0,0);

    glPopMatrix();


    glPushMatrix();
    glRotatef(0,0,1,0);
    glTranslatef(50,22,10);
    glScalef(1.5,3,2);
    table(12,7,7,0,0,0);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(50,15,25);
    glRotatef(180,0,1,0);
    glScalef(1.5,2,1);
    chair(7,7,6,8,0,0,0);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(20,15,65);
    glRotatef(-90,0,1,0);
    glScalef(1.5,2,1);
    chair(7,7,6,8,0,0,0);

    glPopMatrix();

    glPushMatrix();
    glRotatef(0,0,1,0);
    glTranslatef(50,16,10);
    glScalef(1.5,2,2);
    laptop(2,1,0,0,0,white);

    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(38,30.5,5);
    glRotatef(0,0,1,0);
    glScalef(3,3,1);
    monitor(0,0,0,white);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(42,24,10);
    glRotatef(0,0,1,0);
    glScalef(5,5,5);
    keyboard(0,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4,20,50);
    glRotatef(90,1,0,0);
    glScalef(1,1,2);
    book(0,0,0,red);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4,22,50);
    glRotatef(90,1,0,0);
    glScalef(1,1,2);
    book(0,0,0,red );
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4,24,50);
    glRotatef(90,1,0,0);
    glScalef(1,1,2);
    book(0,0,0,green);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(4,20,56);
    glRotatef(90,1,0,0);
    glScalef(1,1,2);
    book(0,0,0,yellow);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4,22,56);
    glRotatef(90,1,0,0);
    glScalef(1,1,2);
    book(0,0,0,blue);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4,24,56);
    glRotatef(90,1,0,0);
    glScalef(1,1,2);
    book(0,0,0,red);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4,26,56);
    glRotatef(90,1,0,0);
    glScalef(1,1,2);
    book(0,0,0,yellow,20);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(4,18,62);
    glRotatef(90,1,0,0);
    glScalef(1,1,3);
    book(0,0,0,cyan);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4,23,62);
    glRotatef(90,1,0,0);
    glScalef(1,1,2);
    book(0,0,0,blue,18);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4,25,62);
    glRotatef(90,1,0,0);
    glScalef(1,1,1.5);
    book(0,0,0,tiles_white,22);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4,20,68);
    glRotatef(90,1,0,0);
    glScalef(1,1,2);
    book(0,0,0,blue);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4,22,68);
    glRotatef(90,1,0,0);
    glScalef(1,1,2);
    book(0,0,0,yellow,18);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4,24,68);
    glRotatef(90,1,0,0);
    glScalef(1,1,2);
    book(0,0,0,dark_blue,24);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,20,68);
    glRotatef(90,1,0,0);
    glScalef(1,1,1.2);
    book(0,0,0,tiles_white,21);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(10,20,61);
    glRotatef(90,1,0,0);
    glScalef(1.2,1,1.2);
    book(0,0,0,yellow,23);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(45,91,28);
    glRotatef( alpha,axis_x, axis_y, 0.0 );
    glRotatef( theta, axis_x, axis_y, 0.0 );
    glRotatef(90,1,0,0);
    glScalef(.6,.6,.6);
    fan(0,0,0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(10,19,52);
    glRotatef(-45,0,1,0);
    glScalef(1,1,1);
    lamp(0,0,0,white);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(50,79,0);
    glRotatef(0,0,1,0);
    glScalef(1,1,1);
    clock(0,0,0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(1,49,52);
    glRotatef(90,0,1,0);
    glScalef(3,3,1);
    calender(0,0,0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(60,5,30);
    glRotatef(90,0,1,0);
    glScalef(15,1,15);
    matress(0,0,0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(70,80,7);
    glRotatef(0,0,1,0);
    glScalef(.5,.5,.5);
    bulb(0,0,0,white);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(1,90,70);
    glRotatef(-90,0,0,1);
    glRotatef(90,0,1,0);
    glScalef(3,1,3);
    tubelight(0,0,0,white);
    glPopMatrix();

    glPushMatrix();

    glPushMatrix();
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { red[0]*.3, red[1]*.3, red[2]*.3, 1.0 };
    GLfloat mat_diffuse[] = { red[0], red[1], red[2], 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

    glTranslatef(90,10,70);
    gluSphere(gluNewQuadric(),5,32,32);
    glPopMatrix();



    glPopMatrix();


}



void bulbLight() //light for bulb
{
    glPushMatrix();
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {0.3, 0.3, 0.3, 1.0};
    GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 70,80,-40,1.0};

    if(bulb_ambient_light == true){glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient);}
    else{glLightfv( GL_LIGHT0, GL_AMBIENT, no_light);}

    if(bulb_diffusion_light == true){glLightfv( GL_LIGHT0, GL_DIFFUSE, light_diffuse);}
    else{glLightfv( GL_LIGHT0, GL_DIFFUSE, no_light);}

    if(bulb_specular_light == true){glLightfv( GL_LIGHT0, GL_SPECULAR, light_specular);}
    else{glLightfv( GL_LIGHT0, GL_SPECULAR, no_light);}

    glLightfv( GL_LIGHT0, GL_POSITION, light_position);
    glPopMatrix();
}

void tubeLight()
{
    glPushMatrix();
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {0.5, 0.5, 0.5, 1.0};
    GLfloat light_diffuse[]  = { 1.0, 1.0, 0.9, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 60,90,30, 1.0 };

    if(tube_ambient_light == true){glLightfv( GL_LIGHT1, GL_AMBIENT, light_ambient);}
    else{glLightfv( GL_LIGHT1, GL_AMBIENT, no_light);}

    if(tube_diffusion_light == true){glLightfv( GL_LIGHT1, GL_DIFFUSE, light_diffuse);}
    else{glLightfv( GL_LIGHT1, GL_DIFFUSE, no_light);}

    if(tube_specular_light == true){glLightfv( GL_LIGHT1, GL_SPECULAR, light_specular);}
    else{glLightfv( GL_LIGHT1, GL_SPECULAR, no_light);}

    glLightfv( GL_LIGHT1, GL_POSITION, light_position);
    glPopMatrix();
}

void lampLight()
{
    glPushMatrix();
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {0.5, 0.5, 0.5, 1.0};
    GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 20,43,72, 1.0 };

    //glEnable( GL_LIGHT2);

    if(lamp_ambient_light == true){glLightfv( GL_LIGHT2, GL_AMBIENT, light_ambient);}
    else{glLightfv( GL_LIGHT2, GL_AMBIENT, no_light);}

    if(lamp_diffusion_light == true){glLightfv( GL_LIGHT2, GL_DIFFUSE, light_diffuse);}
    else{glLightfv( GL_LIGHT2, GL_DIFFUSE, no_light);}

    if(lamp_specular_light == true){glLightfv( GL_LIGHT2, GL_SPECULAR, light_specular);}
    else{glLightfv( GL_LIGHT2, GL_SPECULAR, no_light);}

    glLightfv( GL_LIGHT2, GL_POSITION, light_position);
    GLfloat spot_direction[] = { .5, -1, -0.2  };
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_direction);
    glLightf( GL_LIGHT2, GL_SPOT_CUTOFF, 65.0);
    glPopMatrix();
}


void light()
{
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {0.3, 0.3, 0.3, 1.0};
    GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 0, 50.0, 0, 1.0 };

    glEnable( GL_LIGHT1);
    glLightfv( GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv( GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    glLightfv( GL_LIGHT1, GL_SPECULAR, light_specular);
    glLightfv( GL_LIGHT1, GL_POSITION, light_position);

  /*  GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
    glLightf( GL_LIGHT0, GL_SPOT_CUTOFF, 10.0); */
}

void display(void)
{

    glClearColor(0.75,0.78,0.815,0.7);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glFrustum(-3+lpan, 6+rpan, -4, 6, 6+fdist, 200);

    //gluPerspective(60,1,5,100);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(eyex+cdist,eyey+cdist,eyez+cdist, x+dx,y+dy,z+dz, xaxis,yaxis,zaxis);

    glViewport(0, 0, windowHeight, windowWidth);

    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);

    bulbLight();
    tubeLight();
    lampLight();

    glPushMatrix();

    glRotatef(45+ Tzval,0,1,0);
    glRotatef(Tyval,1,0,0);
    glScalef(gscale,gscale,gscale);
    scene(0,0,0);
    //book(0,0,0);
    //fan(0,0,0);
    //lamp(0,0,0);
    //bulb(0,0,0);
    //tubelight(0,0,0);
    //clock(0,0,0,color2,color3,color1);
    //calender(0,0,0);
    //monitor(0,0,0);
    //keyboard(0,0,0);
    //matress(0,0,0);
    //drawCube(0,0,0,1,1,1,color2);
    //chair(7,7,6,8,0,0,0);
    //closet(18,7,26,0,0,0);
    //interior(100,90,0,0,0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);

    glFlush();
    glutSwapBuffers();
}


void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {

//object zooming
    case 'z':
        gscale+=.2;
        break;

    case 'x':
        gscale-=.2;
        break;

//viewer zooming

    case 'c':
        cdist+=1;
        break;
    case 'v':
        cdist-=1;
        break;

//window zooming

    case 'n':
        fdist+=1;
        break;

    case 'm':
        fdist-=1;
        break;


//panning
    case 'k':
        lpan-=1;
        rpan-=1;

        break;

    case 'l':
        lpan+=1;
        rpan +=1;
        break;


//yaw
    case 'y':

        yaw+=1;

        if( yaw==90 || yaw ==0)
        {
            yaw=0;
            dx=0;
            break;
        }
        dx =  abs(eyez-z)*tan(yaw*PI/180);

        y=y;

        //cout<<yaw<<endl;
        //cout<<"x :"<<x <<"y:"<<y<<"z:"<<z<<endl;

        break;
    case 't':

        yaw-=1;

        if(yaw==-90 || yaw==0)
        {
            yaw = 0;
            dx=0;
            break;
        }

        dx = abs(eyez-z)*tan(yaw*PI/180);

        y=y;

        //cout<<"x :"<<x <<"y:"<<y<<"z:"<<z<<endl;

        break;
//pitch

    case '2':

        pitch+=1;

        if( pitch==90 || pitch ==0)
        {
            pitch=0;
            dy=0;
            break;
        }
        dy =  abs(eyez-z)*tan(pitch*PI/180);

        x=x;

        //cout<<pitch<<endl;
        //cout<<"x :"<<x <<"y:"<<y<<"z:"<<z<<endl;

        break;
    case '1':

        pitch-=1;

        if(pitch==-90 || pitch==0)
        {
            pitch = 0;
            dy=0;
            break;
        }
        //cout<<pitch<<endl;


        dy = abs(eyez-z)*tan(pitch*PI/180);

        x=x;

        //cout<<"x :"<<x <<"y:"<<y<<"z:"<<z<<endl;

        break;

//roll
    case '4':
        roll+=0.5;
        xaxis = cos(roll);
        yaxis= sin(roll);

        // cout<<"x :"<<x <<"y:"<<y<<"z:"<<z<<endl;

        break;
    case '3':
        roll-=0.5;

        xaxis = cos(roll);
        yaxis= sin(roll);

        //cout<<"x :"<<x <<"y:"<<y<<"z:"<<z<<endl;

        break;


    case 'g':
       Tzval+=1;
        break;

    case 'h':
        Tzval-=1;
        break;
    case  'r':
        Tyval+=1;
        break;
    case 'f':
        Tyval-=1;
        break;


//light switches


    case '7': //to turn on and off lamp
            if(lamp_switch == false)
            {
                lamp_switch = true; lamp_ambient_light=true; lamp_diffusion_light=true; lamp_specular_light=true;
                glEnable( GL_LIGHT2); break;
            }
            else if(lamp_switch == true)
            {
                lamp_switch = false; lamp_ambient_light=false; lamp_diffusion_light=false; lamp_specular_light=false;
                glDisable( GL_LIGHT2); break;
            }
        break;


    case '8': //to turn on and off bulb
        if(bulb_switch == false)
        {
            bulb_switch = true; bulb_ambient_light=true; bulb_diffusion_light=true; bulb_specular_light=true;
            glEnable( GL_LIGHT0); break;
        }
        else if(bulb_switch == true)
        {
            bulb_switch = false; bulb_ambient_light=false; bulb_diffusion_light=false; bulb_specular_light=false; glDisable( GL_LIGHT0); break;
        }
       break;


     case '9': //to turn on and off tubelight
        if(tube_switch == false)
        {
            tube_switch = true; tube_ambient_light=true; tube_diffusion_light=true; tube_specular_light=true;
            glEnable( GL_LIGHT1); break;
        }
        else if(tube_switch == true)
        {
            tube_switch = false; tube_ambient_light=false; tube_diffusion_light=false; tube_specular_light=false;
            glDisable( GL_LIGHT1); break;
        }
        break;

     case'!': //turn on/off ambient light 1
        if(bulb_ambient_light == false) {bulb_ambient_light=true; break;}
        else{bulb_ambient_light=false;
        break;}


    case'@':
        if(bulb_diffusion_light == false) {bulb_diffusion_light=true; break;}
        else{bulb_diffusion_light=false;
        break;}

    case'#':
        if(bulb_specular_light == false) {bulb_specular_light=true; break;}
        else{bulb_specular_light=false;
        break;}

    case'$': //turn on/off ambient light 2
        if(tube_ambient_light == false) {tube_ambient_light=true; break;}
        else{tube_ambient_light=false;
        break;}

    case'%':
        if(tube_diffusion_light == false) {tube_diffusion_light=true; break;}
        else{tube_diffusion_light=false;
        break;}

    case'^':
        if(tube_specular_light == false) {tube_specular_light=true; break;}
        else{tube_specular_light=false;
        break;}

    case'&': //turn on/off ambient lamp light
        if(lamp_ambient_light == false) {lamp_ambient_light=true; break;}
        else{lamp_ambient_light=false;
        break;}

    case'*':
        if(lamp_diffusion_light == false) {lamp_diffusion_light=true; break;}
        else{lamp_diffusion_light=false;
        break;}


    case'~':
        if(lamp_specular_light == false) {lamp_specular_light=true; break;}
        else{lamp_specular_light=false;
        break;}


    //fanswitch

    case 's':
    case 'S':
        bRotate = !bRotate;
        uRotate = false;
        axis_x=0.0;
        axis_y=1.0;
        break;

    case 'b':
        birds_eye = !birds_eye;

        if(birds_eye)
        {
            xaxis=-1;
            yaxis=0;
            zaxis =-1;

            eyex= 70;
            eyey = 100;
            eyez = 40;

            x = 40;
            y = 50;
            z = 10;


        }else
        {
            xaxis=initialxaxis;
            yaxis=initialyaxis;
            zaxis =initialzaxis;

            eyex= initialEyex;
            eyey = initialEyey;
            eyez = initialEyez;

            x = initialx;
            y = initialy;
            z = initialz;
        }

        break;
    case '+':
        if(birds_eye)
        {
            eyez--;
            eyex--;

        }
        else
        {
            ;
        }
        break;

    case '-':
        if(birds_eye)
        {
            eyez++;
            eyex++;
        }
        else
        {
            ;
        }
        break;

    case '.':
        if(birds_eye)
        {
            eyez++;
            eyex--;
        }
        else
        {
            ;
        }
        break;

    case '/':
        if(birds_eye)
        {
            eyez--;
            eyex++;
        }
        else
        {
            ;
        }
        break;

    case 27:	// Escape key
        exit(1);
    }
}

void LoadTexture(const char*filename,GLuint ID)
{
    //cout<<filename<<endl;
    //cout<<ID<<endl;
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    glPixelStorei(GL_UNPACK_ALIGNMENT, ID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    BmpLoader bl(filename);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl.iWidth, bl.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl.textureData );
}


void animate()
{
    if (bRotate == true)
    {
        theta += 10.2;
        if(theta > 360.0)
            theta -= 360.0*floor(theta/360.0);
    }

    if (uRotate == true)
    {
        alpha += 10.2;
        if(alpha > 360.0)
            alpha -= 360.0*floor(alpha/360.0);
    }
    glutPostRedisplay();

}


int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);


    cout<<"Loading textures"<<endl;
    glutInitWindowPosition(100,100);
    glutInitWindowSize(windowHeight, windowWidth);
    glutCreateWindow("3D bedroom in OpenGL");

    glEnable(GL_TEXTURE_2D);
    for(int i=0;i<sizeof(ID)/sizeof(ID[0]);i++)
    {
        string tex= dir + "\\textures\\" + to_string(ID[i]) + ".bmp";
        LoadTexture(tex.c_str(),ID[i]);
    }
    cout<<"done"<<endl;

    cout<<"Input Mappings"<<endl;
    cout<<"---------------"<<endl;
    cout<<"Object zooming: z(+) x(-)"<<endl;
    cout<<"Viewer zooming: c(-) v(+)"<<endl;
    cout<<"Window zooming: n(+) m(-)"<<endl;
    cout<<"Panning : l(+) k(-)"<<endl;
    cout<<"Yaw : y(+) t(-)"<<endl;
    cout<<"Pitch: 1(-) 2(+)"<<endl;
    cout<<endl<<endl;
    cout<<"7: Lamp " <<endl;
    cout<<"8: Bulb " <<endl;
    cout<<"9: Tubelight " <<endl;
    cout<<"!: bulb ambient " <<endl;
    cout<<"@: bulb diffusion " <<endl;
    cout<<"#: bulb specular" <<endl;
    cout<<"$: tubelight ambient" <<endl;
    cout<<"%: tubelight diffusion " <<endl;
    cout<<"^: tubelight specular " <<endl;
    cout<<"&: lamp ambient " <<endl;
    cout<<"*: lamp diffusion " <<endl;
    cout<<"~: lamp specular" <<endl;
    cout<<"B: birds eye view " <<endl;
    cout<<"+: birds eye view move forward " <<endl;
    cout<<"-: birds eye view move backward " <<endl;
    cout<<"s: toggle fan switch" <<endl;



    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);

    light();

    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutMainLoop();

    return 0;
}
