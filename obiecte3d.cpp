#include <GL/glut.h>
#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

GLfloat latura = 0.0;
GLfloat xglob = 0.0;
GLfloat yglob = 0.0;
GLfloat xtor = 0.0;
GLfloat ytor = 0.0;
GLfloat xbonus = 0.0;
GLfloat ybonus = 0.0;
GLfloat xcon = 0.0;
GLfloat ycon = 0.0;
 GLfloat  conadv=0.0;
GLfloat  unitcub=0.0;
GLfloat  toradv=0.0;
GLfloat  bonusadv=0.0;
GLfloat  globadv=0.0;
const int step1=1, step2=2, hold=3, conv1=4,linie1=10, linie2=11,linie3=12,linie4=13,lat1=9,lat2=10,lat3=11,conv2=12,conv3=13,conv4=14,elips1=15,elips2=16,elips3=17,elips4=18;
int mainmenu,submenu1,submenu2,submenu3,submenu4,submenu5;
int movglob, movecub,tormove, bonusmove,conmove; 


void MouseEvent(void)
{
	switch (conmove)
	{
	case elips1:
		xcon+=conadv;ycon=sqrt(4.0-xcon*xcon/2.0);
		if (ycon< 2.0+conadv) {conmove=elips2;ycon=0.0;}
		break;
	case elips2:
		xcon-=conadv;ycon=-sqrt(4.0-xcon*xcon/2.0);
		if (xcon< 0.0+conadv) {conmove=elips3;xcon=0.0;}
		break;
	case elips3:
		xcon-=conadv;ycon=-sqrt(4.0-xcon*xcon/2.0);
		if (ycon >0.0-conadv) {conmove=elips4;ycon=0.0;}
		break;
	case elips4:
		xcon+=conadv;ycon=sqrt(4.0-xcon*xcon/2.0);
		if (xcon>0.0-conadv) {conmove=elips1;xcon=0.0;}
		break;
	default:
		break;
	}

	switch (movecub)
	{

	case step1:
		latura += unitcub;
		if (latura > 2.0 - unitcub)
			movecub = step2;
		break;
	case step2:
		latura -= unitcub;
		if (latura < -2.0 + unitcub)
			movecub= step1;
		break;
	default:
		break;
	}



 switch (tormove)
	{
	case linie1: 
		
				
		xtor+=toradv;
		  if (xtor>4.0-toradv) tormove=linie2;

		break;
	case linie2:
		ytor+=toradv;
		if (ytor> 4.0-toradv) tormove=linie3;
		break;
	case linie3:
		xtor-=toradv;
		if (xtor <0.0+toradv) tormove=linie4;
		break;
	case linie4:
		ytor-=toradv;
		if (ytor <0.0+toradv) tormove=linie1;
		break;
	default: break;
	}


	switch (bonusmove)
	{
	case lat1:
		xbonus+=bonusadv;ybonus+=bonusadv;
		if (xbonus> 3.0-bonusadv) bonusmove=lat2;
		break;
	case lat2:
		xbonus+=bonusadv;ybonus-=bonusadv;
		if (xbonus> 6.0-bonusadv) bonusmove=lat3;
		break;
	case lat3:
		xbonus-=bonusadv;
		if (xbonus< 0.0 +bonusadv) bonusmove=lat1;
		break;
	default:break;
	}

	switch (movglob)
	{
	case conv1:
		 xglob+=globadv;yglob=sqrt(4.0-xglob*xglob);
		if (yglob< 0.0+globadv) {movglob=conv2;yglob=0.0;}
		break;
	case conv2:
		xglob-=globadv;yglob=-sqrt(-xglob*xglob+4.0);
		if (xglob< 0.0+globadv) {movglob=conv3;xglob=0.0;}
		break;
	case conv3:
		xglob-=globadv;yglob=-sqrt(-xglob*xglob+4.0);
		if (yglob >0.0-globadv) {movglob=conv4;yglob=0.0;}
		break;
	case conv4:
		xglob+=globadv;yglob=sqrt(4.0-xglob*xglob);
		if (xglob>0.0-globadv) {movglob=conv1;xglob=0.0;}
		break;
	default:
		break;
	}

	glutPostRedisplay();
	SleepEx(10, FALSE);
}

	 void menuEvent(int event){
	switch(event){
		case 1: movecub=step1;unitcub=0.02;break;
		case 2: movecub=step1;unitcub=0.1;break;
		case 3: movecub=hold;unitcub=0.0;break;
		case 4: conmove=elips1;xcon=0.0;ycon=0.0;conadv=0.02;break;
		case 5: conmove=elips1;xcon=0.0;ycon=0.0;conadv=0.1;break;
		case 6: conmove=hold;xcon=0.0;ycon=0.0;conadv=0.0;break;
		case 7: bonusmove=lat1;bonusadv=0.02;break;
		case 8: bonusmove=lat1;bonusadv=0.1;break;
		case 9: bonusmove=hold;toradv=0.0;break;
		case 10: tormove=linie1;toradv=0.02;break;
		case 11: tormove=linie1;toradv=0.1;break;
		case 12: tormove=hold;toradv=0.0;break;
		case 13: movglob=conv1;xglob=0.0;yglob=0.0;globadv=0.02;break;
		case 14: movglob=conv1;xglob=0.0;yglob=0.0;globadv=0.05;break;
		case 15: movglob=hold;xglob=0.0;yglob=0.0;globadv=0.0;break;

	default:break;
	}
	glutIdleFunc(MouseEvent);
}

void contextMenu(){
	submenu1=glutCreateMenu(menuEvent);
	glutAddMenuEntry("Lent",1);
	glutAddMenuEntry("Rapid",2);
	glutAddMenuEntry("Reset",3);
	
	submenu2=glutCreateMenu(menuEvent);
	glutAddMenuEntry("Lent",4);
	glutAddMenuEntry("Rapid",5);
	glutAddMenuEntry("Reset",6);

	submenu3=glutCreateMenu(menuEvent);
	glutAddMenuEntry("Lent",7);
	glutAddMenuEntry("Rapid",8);
	glutAddMenuEntry("Reset",9);

	submenu4=glutCreateMenu(menuEvent);
	glutAddMenuEntry("Lent",10);
	glutAddMenuEntry("Rapid",11);
	glutAddMenuEntry("Reset",12);

	submenu5=glutCreateMenu(menuEvent);
	glutAddMenuEntry("Lent",13);
	glutAddMenuEntry("Rapid",14);
	glutAddMenuEntry("Reset",15);

	mainmenu=glutCreateMenu(menuEvent);
	glutAddSubMenu("Cub",submenu1);
	glutAddSubMenu("Con",submenu2);
	glutAddSubMenu("Crate",submenu3);
	glutAddSubMenu("Farfurie",submenu4);
	glutAddSubMenu("Glob pamantesc",submenu5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void init()
{
	glClearColor(1.0,1.0,1.0,0);
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT );
	glColor3f(0.0, 0.0, 0.0);
	glLoadIdentity();
	
	glTranslatef(latura+0.5, latura,0.0);
	glutWireCube(1.5);
	glLoadIdentity();

	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(xcon,ycon,0.0);
	glutWireCone(2.0, 3.0, 25, 15 );
	glLoadIdentity();
	
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(3.0,-7.0,1.0);
	glTranslatef(xbonus,ybonus,0.0);
	glutWireDodecahedron();
	glLoadIdentity();
	
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(-15.0,-8.0,-4.0);
	glTranslatef(xtor,ytor,xtor);
	glutWireTorus(1.0,2.0,5,10); 
	glLoadIdentity();
	
	glColor3f(0.0, 2.0, 1.0);
	glTranslatef(7.0,0.0,0.0);
	glTranslatef(xglob,yglob,0.0);
	glutWireSphere(1.0, 20, 10);
	glLoadIdentity();


	glutSwapBuffers();
}

void Reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w/h, 0.1, 1000.0);
	gluLookAt(10.0, 10.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("5 obiecte");
	init();
	contextMenu();
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutMainLoop();
}