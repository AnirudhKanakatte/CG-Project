#include<stdio.h>
#include<math.h>
#include<time.h>
#include<GL/glut.h>
#include<string.h>
void update();
void animate();
void display();
void setFont();
void frontscreen();
int m,then=0;
int p,q,r;
int count=0;
float g=0;
GLint x=800,y=200,xx=0,theta=0,theta1[3]={0,0,0},traffic_regulator=1,control_keyl,control_keyr,flag=0;
int i,j;
int s=0;
void test();
void *currentfont;

GLfloat p1=0,q1=0,r1=0;

void setFont(void *font)
{
	currentfont=font;
}

void drawstring(float x,float y,float z,char *string)
{
	char *c;
	glRasterPos3f(x,y,z);
 
	for(c=string;*c!='\0';c++)
	{	glColor3f(0.0,0.0,0.0);
		glutBitmapCharacter(currentfont,*c);
	}
}

void starter()											
{	
	glColor3f(0.0,0.0,0.0);
	glRectf(0,0,700,700);
	glFlush();
    
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0.99,0.4,0.0);
	drawstring(130,450,0.0,"K S INSTITUTE OF TECHNOLOGY, BANGALORE");
	glColor3f(0.99,0.3,0.0);
	drawstring(110,430,1.0,"DEPARTMENT OF COMPUTER SCIENCE & ENGINEERING");

	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(0.2,0.6,0.9);
	drawstring(170,380,1.0,"      COMPUTER GRAPHICS PROJECT");
	glColor3f(0.2,0.6,0.9);
	drawstring(210,360,1.0," LEVEL CROSSING ");

	setFont(GLUT_BITMAP_HELVETICA_18);

	glColor3f(1.0,1.0,1.0);
	drawstring(220,300,1.0,"SUBMITTED   BY");				
	
	glColor3f(0.0,1.0,1.0);
	drawstring(125,280,1.0,"                                      ANIRUDH.K.R  (1KS13CS012)");

	
	glColor3f(1.0,1.0,1.0);
	drawstring(200,200,1.0,"UNDER THE GUIDANCE OF");
	
	glColor3f(0.0,1.0,1.0);
	drawstring(85,180,1.0,"  Mrs.RENUKA DEVI.S. ");

	setFont(GLUT_BITMAP_HELVETICA_12);

	glColor3f(0.0,1.0,1.0);
	drawstring(130,180,1.0,"                       B.E.,M.Tech");		
	
	glColor3f(0.0,1.0,1.0);
	drawstring(85,170,1.0,"  Asst. Professor, Department of CS&E,");

	glColor3f(0.0,1.0,1.0);
	drawstring(85,160,1.0,"  KSIT, BANGALORE.");

	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(0.0,1.0,1.0);
	drawstring(300,180,1.0,"        Ms.SIDDU TUSHARA.M.S ");
	setFont(GLUT_BITMAP_HELVETICA_12);

	glColor3f(0.0,1.0,1.0);
	drawstring(380,180,1.0,"                 B.E.,M.Tech");		
	
	glColor3f(0.0,1.0,1.0);
	drawstring(300,170,1.0,"          Asst. Professor, Department of CS&E,");

	glColor3f(0.0,1.0,1.0);
	drawstring(300,160,1.0,"          KSIT, BANGALORE.");

	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(0.0,1.0,1.0);
	drawstring(275,60,1.0,"          CLICK LEFT BUTTON TO CONTINUE.....");

    glFlush();
}

void text(int x,int y,char *s)
{
	int len,i;
	glRasterPos2f(x,y);
	len=(int)strlen(s);
	for(i=0;i<len;i++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);
}



void draw_pixel(GLint cx,GLint cy)
{
	glColor3f(0.45,0.45,0.45);
	glBegin(GL_POINTS);
	glVertex2i(cx,cy);
	glEnd();
}
void plotpixels(GLint h,GLint k,GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}
void circle_draw(GLint h,GLint k,GLint r)
{
	GLint d=1-r,x=0,y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0)
			d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}

void train()
{
	int y=200;
	glBegin(GL_POLYGON); // ENGINE //
	glColor3f(0,0,1);
	glVertex2f(x,y);
	glVertex2f(x+165,y);
	glVertex2f(x+165,y+100);
	glVertex2f(x+25,y+100);
	glVertex2f(x,y+50);
	glEnd();

	glBegin(GL_POLYGON);  //COACH 1//
	glColor3f(0.0,0.0,1.0);
	glVertex2f(x+175,y);
	glVertex2f(x+282,y);
	glVertex2f(x+282,y+100);
	glVertex2f(x+175,y+100);
	glEnd();

	glBegin(GL_POLYGON); //COACH 1 WINDOW //
	glColor3f(0,1,1);
	glVertex2f(x+245,y+60);
	glVertex2f(x+270,y+60);
	glVertex2f(x+270,y+85);
	glVertex2f(x+245,y+85);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,1,1);
	glVertex2f(x+215,y+60);
	glVertex2f(x+240,y+60);
	glVertex2f(x+240,y+85);
	glVertex2f(x+215,y+85);
	glEnd();

	glBegin(GL_POLYGON); //ENGINE WINDOW //
	glColor3f(0,1,1);
	glVertex2f(x+25,y+50);
	glVertex2f(x+50,y+50);
	glVertex2f(x+50,y+85);
	glVertex2f(x+25,y+85);
	glEnd();
	glLineWidth(4);
	glBegin(GL_LINES);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(x+165,y+25);
	glVertex2f(x+175,y+25);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(x+165,y+75);
	glVertex2f(x+175,y+75);
	glEnd();
	glBegin(GL_POLYGON);  //COACH 2
	glColor3f(0.0,0.0,1.0);
	glVertex2f(x+293,y);
	glVertex2f(x+400,y);
	glVertex2f(x+400,y+100);
	glVertex2f(x+293,y+100);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(x+282,y+25);
	glVertex2f(x+293,y+25);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(x+282,y+75);
	glVertex2f(x+293,y+75);
	glEnd();

//COACH2 WINDOW

	glBegin(GL_POLYGON);
	glColor3f(0,1,1);
	glVertex2f(x+340,y+60);
	glVertex2f(x+365,y+60);
	glVertex2f(x+365,y+85);
	glVertex2f(x+340,y+85);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,1,1);
	glVertex2f(x+370,y+60);
	glVertex2f(x+395,y+60);
	glVertex2f(x+395,y+85);
	glVertex2f(x+370,y+85);
	glEnd();

	glBegin(GL_POLYGON); //DOOR 1//
	glColor3f(1,1,1);
	glVertex2f(x+180,y+20);
	glVertex2f(x+200,y+20);
	glVertex2f(x+200,y+70);
	glVertex2f(x+180,y+70);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.8,0.78,0.78);
	glVertex2f(x+180,y+20);
	glVertex2f(x+190,y+25);
	glVertex2f(x+190,y+60);
	glVertex2f(x+180,y+70);
	glEnd();

	glBegin(GL_POLYGON); //DOOR 2//
	glColor3f(1,1,1);
	glVertex2f(x+300,y+20);
	glVertex2f(x+320,y+20);
	glVertex2f(x+320,y+70);
	glVertex2f(x+300,y+70);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.78,0.78,0.78);
	glVertex2f(x+300,y+20);
	glVertex2f(x+310,y+25);
	glVertex2f(x+310,y+60);
	glVertex2f(x+300,y+70);
	glEnd();

	glLineWidth(2.5);
	glBegin(GL_LINES);//FRONT
	glColor3f(0,0,0);
	glVertex2f(x,y+20);
	glVertex2f(x-10,y+20);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex2f(x,y+35);
	glVertex2f(x-10,y+35);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex2f(x-10,y+20);
	glVertex2f(x-10,y+40);
	glEnd();

	// ELECTRIC
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(x+50,y+100);
	glVertex2f(x+60,y+110);
	glVertex2f(x+90,y+110);
	glVertex2f(x+100,y+100);
	glEnd();
	glFlush();


	 glLineWidth(2);
	 glBegin(GL_LINE_LOOP);
	 glColor3f(0,0,0);
	 glVertex2f(x+75,y+110);
	 glVertex2f(x+75,y+130);
	 glVertex2f(x+130,y+180);
	 glVertex2f(x+125,y+150);
	 glVertex2f(x+75,y+130);
	 glEnd();

	glLineWidth(2.0); //wheel
 	glPushMatrix();
 	glTranslatef(x+25,y,0);
 	glRotatef(theta,0,0,1);
	glTranslatef(-x-25,-y,0);
	
	glPushMatrix();
 	glBegin(GL_LINES);//wheel spokes//
 	glColor3f(0.0,0.0,0.0);
 	glVertex2f(x+25,y+15);
 	glVertex2f(x+25,y-15);
 	glEnd();
	glPopMatrix();
 	glLineWidth(3.0);
 	glPushMatrix();
  	glTranslatef(x+25,y,0);
 	glRotatef(theta,0,0,1);
 	glTranslatef(-x-25,-y,0);
 	glBegin(GL_LINES);
 	glColor3f(0.0,0.0,0.0);
 	glVertex2f(x+40,y);
 	glVertex2f(x+10,y);
 	glEnd();
 	glPopMatrix();

	 glLineWidth(3.0);
	 glPushMatrix();
	 glTranslatef(x+25,y,0);
	 glRotatef(theta,0,0,1);
	 glTranslatef(-x-25,-y,0);
	 glBegin(GL_LINES);
	 glColor3f(0.0,0.0,0.0);
	 glVertex2f(x+16,y-12);
	 glVertex2f(x+33,y+12);
	 glEnd();
	 glPopMatrix();

	 glLineWidth(2.0);//2nd wheel spokes
	 glPushMatrix();
	 glTranslatef(x+82,y,0);
	 glRotatef(theta,0,0,1);
	 glTranslatef(-x-82,-y,0);
	 glBegin(GL_LINES);
	 glColor3f(0.0,0.0,0.0);
	 glVertex2f(x+82,y+15);
	 glVertex2f(x+82,y-15);
	 glEnd();
	 glPopMatrix();
	
	 glLineWidth(3.0);
	 glPushMatrix();
	   glTranslatef(x+82,y,0);
	   glRotatef(theta,0,0,1);
	  glTranslatef(-x-82,-y,0);
	 glBegin(GL_LINES);
	 glColor3f(0.0,0.0,0.0);
	 glVertex2f(x+97,y);
	 glVertex2f(x+67,y);
	 glEnd();
	 glPopMatrix();

	 glLineWidth(3.0);
	 glPushMatrix();
	   glTranslatef(x+82,y,0);
	   glRotatef(theta,0,0,1);
	  glTranslatef(-x-82,-y,0);
	 glBegin(GL_LINES);
	 glColor3f(0.0,0.0,0.0);
	 glVertex2f(x+90,y-12);
	 glVertex2f(x+72,y+12);
	 glEnd();
	 glPopMatrix();
	
	 glLineWidth(2.0);
	 glPushMatrix();
	    glTranslatef(x+140,y,0);
	    glRotatef(theta,0,0,1);
	   glTranslatef(-x-140,-y,0);//3rd wheel spokes
	 glBegin(GL_LINES);
	 glColor3f(0.0,0.0,0.0);
	 glVertex2f(x+140,y+15);
	 glVertex2f(x+140,y-15);
	 glEnd();
	 glPopMatrix();

	 glLineWidth(3.0);
	 glPushMatrix();
	     glTranslatef(x+140,y,0);
	     glRotatef(theta,0,0,1);
	    glTranslatef(-x-140,-y,0);
	  glBegin(GL_LINES);
	 glColor3f(0.0,0.0,0.0);
 	glVertex2f(x+125,y);
 	glVertex2f(x+155,y);
 	glEnd();
 	glPopMatrix();
	
 	glLineWidth(3.0);
 	glPushMatrix();
 	    glTranslatef(x+140,y,0);
 	    glRotatef(theta,0,0,1);
 	   glTranslatef(-x-140,-y,0);
 	 glBegin(GL_LINES);
 	glColor3f(0.0,0.0,0.0);
 	glVertex2f(x+132,y-12);
 	glVertex2f(x+148,y+12);
 	glEnd();
 	glPopMatrix();

 	glLineWidth(2.0); //coach1 wheel spokes
 	glPushMatrix();
 	    glTranslatef(x+210,y,0);
 	    glRotatef(theta,0,0,1);
 	   glTranslatef(-x-210,-y,0);
 	  glBegin(GL_LINES);
 	glColor3f(0.0,0.0,0.0);
 	glVertex2f(x+210,y+15);
 	glVertex2f(x+210,y-15);
 	glEnd();
 	glPopMatrix();
	
 	glLineWidth(3.0);
 	glPushMatrix();
 	     glTranslatef(x+210,y,0);
 	     glRotatef(theta,0,0,1);
 	    glTranslatef(-x-210,-y,0);
 	glBegin(GL_LINES);
 	glColor3f(0.0,0.0,0.0);
 	glVertex2f(x+225,y);
 	glVertex2f(x+195,y);
 	glEnd();
 	glPopMatrix();
	
 	glLineWidth(3.0);
 	glPushMatrix();
 	     glTranslatef(x+210,y,0);
 	     glRotatef(theta,0,0,1);
 	    glTranslatef(-x-210,-y,0);
 	glBegin(GL_LINES);
 	glColor3f(0.0,0.0,0.0);
 	glVertex2f(x+217,y-12);
 	glVertex2f(x+202,y+12);
 	glEnd();
 	glPopMatrix();

 	glLineWidth(2.0);//coach1 2nd wheel
 	glPushMatrix();
 	      glTranslatef(x+250,y,0);
 	      glRotatef(theta,0,0,1);
 	     glTranslatef(-x-250,-y,0);
 	glBegin(GL_LINES);
 	glColor3f(0.0,0.0,0.0);
 	glVertex2f(x+250,y+15);
 	glVertex2f(x+250,y-15);
 	glEnd();
 	glPopMatrix();
	
 	glLineWidth(3.0);
 	glPushMatrix();
 	      glTranslatef(x+250,y,0);
 	      glRotatef(theta,0,0,1);
 	     glTranslatef(-x-250,-y,0);
 	glBegin(GL_LINES);
 	glColor3f(0.0,0.0,0.0);
 	glVertex2f(x+265,y);
 	glVertex2f(x+235,y);
 	glEnd();
	glPopMatrix();
 	glLineWidth(3.0);
 	glPushMatrix();
 	      glTranslatef(x+250,y,0);
 	      glRotatef(theta,0,0,1);
 	     glTranslatef(-x-250,-y,0);
 	glBegin(GL_LINES);
 	glColor3f(0.0,0.0,0.0);
 	glVertex2f(x+240,y-12);
 	glVertex2f(x+257,y+12);
 	glEnd();
 	glPopMatrix();
	
 	 glLineWidth(2.0);
 	 glPushMatrix();
          glTranslatef(x+335,y,0);//coach2 wheel spokes
          glRotatef(theta,0,0,1);
         glTranslatef(-x-335,-y,0);
 	 glBegin(GL_LINES);
 	  glColor3f(0.0,0.0,0.0);
 	 glVertex2f(x+335,y+15);
 	 glVertex2f(x+335,y-15);
 	 glEnd();
 	 glPopMatrix();
 	 glLineWidth(3.0);
 	 glPushMatrix();
 	         glTranslatef(x+335,y,0);
 	         glRotatef(theta,0,0,1);
 	        glTranslatef(-x-335,-y,0);
 	 glBegin(GL_LINES);
 	 glColor3f(0.0,0.0,0.0);
 	 glVertex2f(x+320,y);
 	 glVertex2f(x+350,y);
 	 glEnd();
 	 glPopMatrix();
	
 	 glLineWidth(3.0);
 	 glPushMatrix();
 	         glTranslatef(x+335,y,0);
 	         glRotatef(theta,0,0,1);
 	        glTranslatef(-x-335,-y,0);
 	 glBegin(GL_LINES);
 	 glColor3f(0.0,0.0,0.0);
 	 glVertex2f(x+340,y-12);
 	 glVertex2f(x+325,y+12);
 	 glEnd();
  	glPopMatrix();

  	glLineWidth(2.0);//coach 2nd
 	 glPushMatrix();
           glTranslatef(x+375,y,0);
           glRotatef(theta,0,0,1);
           glTranslatef(-x-375,-y,0);
           glBegin(GL_LINES);
  	  glColor3f(0.0,0.0,0.0);
  	  glVertex2f(x+375,y+15);
  	  glVertex2f(x+375,y-15);
  	  glEnd();
  	  glPopMatrix();

  	  glLineWidth(3.0);
  	  glPushMatrix();
               glTranslatef(x+375,y,0);
               glRotatef(theta,0,0,1);
              glTranslatef(-x-375,-y,0);
  	  glBegin(GL_LINES);
  	  glColor3f(0.0,0.0,0.0);
  	  glVertex2f(x+360,y);
  	  glVertex2f(x+390,y);
  	  glEnd();
  	  glPopMatrix();

  	  glLineWidth(3.0);
  	  glPushMatrix();
  	             glTranslatef(x+375,y,0);
  	             glRotatef(theta,0,0,1);
  	            glTranslatef(-x-375,-y,0);
  	  glBegin(GL_LINES);
  	  glColor3f(0.0,0.0,0.0);
  	  glVertex2f(x+365,y-12);
  	  glVertex2f(x+380,y+12);
  	  glEnd();
  	  glPopMatrix();
  	  glPopMatrix();
  	  glFlush();
  	  
  	  
  	  GLint r=15,yc=200;
		circle_draw(x+25,yc,r);
		circle_draw(x+140,yc,r);
		circle_draw(x+210,yc,r);
		circle_draw(x+250,yc,r);
		circle_draw(x+335,yc,r);
		circle_draw(x+375,yc,r);
		circle_draw(x+82,yc,r);
}

void electricwire()
{
	glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex2f(-1000,350);
	glVertex2f(5000,350);
	glEnd();
	glBegin(GL_LINES);
		glColor3f(0,0,0);
		glVertex2f(-1000,380);
		glVertex2f(5000,380);
		glEnd();
		//glBegin(GL_LINES);
		//glVertex2f(750,300);
		//glVertex2f(1000,300);
		//glEnd();

	    glFlush();
}


void track()
{
	glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex2f(-1000,185);
	glVertex2f(5000,185);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex2f(-1000,195);
	glVertex2f(5000,195);
	glEnd();
	
	int i;
	glPointSize(8);
	glBegin(GL_LINES);
	glColor3f(0,0,0);
	for(i=-3000;i<=5000;i=i+10)
	{
		glVertex2f(i,185);
		glVertex2f(i,195);
	}
	glEnd();
}


void sky()
{
		glBegin(GL_POLYGON);
		glColor3f(0,1,1);
		glVertex2f(0,380);
		glVertex2f(0,700);
	    	glVertex2f(700,700);
		glVertex2f(700,380);
		glEnd();

}

void road()
{
	glColor3f(0.7,0.7,0.7);
    	glBegin(GL_QUADS);
	   glVertex2f(130,-1000);
	   glVertex2f(130,185);
	   glVertex2f(400,185);
	   glVertex2f(400,-1000);
	glEnd();

	//car
	glPushMatrix();
	glTranslatef(0,g,0);
	glColor3f(0.03349282,0.11483254,1.0);
    	glBegin(GL_QUADS);
	   glVertex2f(180,50);
	   glVertex2f(180,90);
	   glVertex2f(250,90);
	   glVertex2f(250,50);
	glEnd();
	
	glColor3f(1.0,0.0,0.0);//lights1
    	glBegin(GL_QUADS);
	   glVertex2f(180,75);
	   glVertex2f(180,90);
	   glVertex2f(200,90);
	   glVertex2f(200,75);
	glEnd();
	
	glColor3f(1.0,0.0,0.0);//lights2
    	glBegin(GL_QUADS);
	   glVertex2f(230,75);
	   glVertex2f(230,90);
	   glVertex2f(250,90);
	   glVertex2f(250,75);
	glEnd();
	
	glColor3f(1.0,1.0,1.0);//nameplate
    	glBegin(GL_QUADS);
	   glVertex2f(205,55);
	   glVertex2f(205,70);
	   glVertex2f(225,70);
	   glVertex2f(225,55);
	glEnd();
	
	glColor3f(0.2,0.2,0.2);//wheel
    	glBegin(GL_QUADS);
	   glVertex2f(187,35);
	   glVertex2f(187,50);
	   glVertex2f(202,50);
	   glVertex2f(202,35);
	glEnd();
	
	glColor3f(0.2,0.2,0.2);//wheel
    	glBegin(GL_QUADS);
	   glVertex2f(228,35);
	   glVertex2f(228,50);
	   glVertex2f(243,50);
	   glVertex2f(243,35);
	glEnd();

	glColor3f(0.03349282,0.11483254,1.0);//car body(top)
    	glBegin(GL_QUADS);
	   glVertex2f(180,90);
	   glVertex2f(190,130);
	   glVertex2f(240,130);
	   glVertex2f(250,90);
	glEnd();
	
	glColor3f(0.2,0.2,0.2);//car glass(top)
    	glBegin(GL_QUADS);
	   glVertex2f(187,95);
	   glVertex2f(195,125);
	   glVertex2f(235,125);
	   glVertex2f(242,95);
	glEnd();
	glPopMatrix();
}

void signal()
{
	static float a=0.f;
	glMatrixMode(GL_MODELVIEW);
	//a+=1.f;	
	glColor3f(0.858824,0.858824,0.439216);
		
	glBegin(GL_QUADS);
	glVertex2f(0,100); //1
	glVertex2f(0,210);
	glVertex2f(30,210);
	glVertex2f(30,100);
	glVertex2f(35,100); //2
	glVertex2f(35,210);
	glVertex2f(65,210);
	glVertex2f(65,100);
	glVertex2f(70,100); //3
	glVertex2f(70,210);
	glVertex2f(100,210);
	glVertex2f(100,100);
	glVertex2f(105,100); //4
	glVertex2f(105,210);
	glVertex2f(130,210);
	glVertex2f(130,100);	
	glEnd();	
	
	glBegin(GL_QUADS);
	glVertex2f(400,100); //1
	glVertex2f(400,210);
	glVertex2f(420,210);
	glVertex2f(420,100);
	glVertex2f(425,100); //2
	glVertex2f(425,210);
	glVertex2f(445,210);
	glVertex2f(445,100);
	glVertex2f(450,100); //3
	glVertex2f(450,210);
	glVertex2f(470,210);
	glVertex2f(470,100);
	glVertex2f(475,100); //4
	glVertex2f(475,210);
	glVertex2f(500,210);
	glVertex2f(500,100);	
	glEnd();

	
	
	
	glPushMatrix();
	glTranslatef(a,0,0);
	glRotatef(theta,0,0,0);
	//glTranslatef(,0,0);
	
	
	
	
	
	glColor3f(1.0,0.0,0.0);	
	glBegin(GL_QUADS);
	glVertex2f(130,140);
	glVertex2f(130,175);
	glVertex2f(400,175);
	glVertex2f(400,140);
	glEnd();
	int i;
	glPointSize(15);
	glBegin(GL_LINES);
	glColor3f(1,1,1);
	for(i=130;i<=400;i=i+10)
	{
		glVertex2f(i,140);
		glVertex2f(i,175);
	}
	glEnd();
	
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_QUADS);
	glVertex2f(245,158);
	glVertex2f(265,185);
	glVertex2f(285,158);
	glVertex2f(265,130);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	glVertex2f(245,158);
	glVertex2f(265,185);
	glVertex2f(265,185);
	glVertex2f(285,158);
	glVertex2f(285,158);
	glVertex2f(265,130);	
	glVertex2f(265,130);
	glVertex2f(245,158);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	glRasterPos2i(255,158);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'S');
	glRasterPos2i(259,158);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'T');
	glRasterPos2i(263,158);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'O');
	glRasterPos2i(268,158);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'P');
	glPopMatrix();
	
	glFlush();
	
	
	/*glColor3f(0.0,0.0,0.0);
	glBegin(GL_QUADS);
	glVertex2f(200,250);
	glVertex2f(200,550);
	glVertex2f(250,550);
	glVertex2f(250,250);
	glEnd();
		
	
	glBegin(GL_QUADS);
	glVertex2f(750,250);
	glVertex2f(750,550);
	glVertex2f(800,550);
	glVertex2f(800,250);
	glEnd();*/
	
	
}

void signal1()
{
	//glPushMatrix();
	//glScaled(40.0,40.0,0.0);
	//stand
	glColor3f(0.1,0.2,0.1);
	//glBegin(GL_POLYGON);
	//glVertex2f(15,7);
	//glVertex2f(15,8);
	//glVertex2f(18,8);
	//glVertex2f(18,7);
	//glEnd();
	//pole
	glBegin(GL_QUADS);
	glVertex2f(85,90);
	glVertex2f(85,220);
	glVertex2f(103,220);
	glVertex2f(103,90);
	glEnd();
	//board
	glBegin(GL_POLYGON);
	glVertex2f(60,220);
	glVertex2f(60,295);
	glVertex2f(118,295);
	glVertex2f(118,220);
	glEnd();
	//red
	glColor3f(p1,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(80,272);
	glVertex2f(80,287);
	glVertex2f(98,287);
	glVertex2f(98,272);
	glEnd();
	//yellow
	glColor3f(q1,q1,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(80,250);
	glVertex2f(80,265);
	glVertex2f(98,265);
	glVertex2f(98,250);
	glEnd();
	//green
	glColor3f(0.0,r1,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(80,228);
	glVertex2f(80,243);
	glVertex2f(98,243);
	glVertex2f(98,228);
	glEnd();
	//glPopMatrix();
}

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0);
	glLoadIdentity();
	gluOrtho2D(0,499,0,499);
}


void mykey(unsigned char key,int x,int y)
{
	int i;

	if(key=='k'|| key=='K')
	{		
		for(i=0;i<1000000000;i++)
			;
      		glutPostRedisplay();
	}
}

void mouse(int button,int state,int x,int y)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		then=1;
	}
	
	if(button==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN)
	{			
		traffic_regulator=0;
		p1=0;
		q1=0;
		r1=1;
	}
	
	if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
	{
		glutIdleFunc(animate);
		traffic_regulator=0;
		p1=0;
		q1=1;
		r1=0;
	}
	if(button==GLUT_RIGHT_BUTTON && state==GLUT_UP)
	{	
		traffic_regulator=1;
		p1=1;
		q1=0;
		r1=0;
	}
	glutPostRedisplay();
}

void myKeyboard( unsigned char key, int x, int y )
{
	switch(key)
	{
		case 13: if(flag==1)
			 {
			 	flag=2;
			 	display();
			 }
			 if(flag==0) //Ascii of 'enter' key is 13
		 	 {
				flag=1;
				display();
			 }		
			break;	
		default: break;
	}
}

void mydisplay(void)
{	
	if(traffic_regulator)
		glutTimerFunc(50,update,0);	
	signal();
	signal1();
	glFlush();
}
	
void control()
{
	if(control_keyl!='l'||control_keyr!='r')
	{
	if(control_keyl=='l')
	{
      		//x=x+6;
      		//theta+=1;
      	}
	//if(control_keyr=='r')
	 //b=b-6;
	}
	
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	if(then==0)
	{
		starter();
	}
	else if(then==1)
	{
		glPushMatrix();		
		sky();
		road();	
		track();
		electricwire();	 
	  	glColor3f(1.0,0.0,0.0);
		glPointSize(3.0);    	
		train();    
		glPopMatrix();
		mydisplay();
	}
	else
		exit(0);
	glFlush();	
  	glutSwapBuffers();
}

void update(int value)
{	
	control();
	glutPostRedisplay();
}

void animate()
{	
	x=x-3;
	theta+=0.5;
	g=g+0.1;
	if(x>0)
		g=0;
	
	glutPostRedisplay();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(700,700);
	glutInitWindowPosition(0,0);
	glutCreateWindow("LEVEL CROSSING");
	glutDisplayFunc(display);
	glutKeyboardFunc(mykey);
	glutMouseFunc(mouse);
	glutKeyboardFunc(myKeyboard); 
	myinit();
	glutMainLoop();
	return 0;
}



