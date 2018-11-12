//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************								*****************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"


int w = 500, h = 500;
int frame=0,time,timebase=0;
int deltaTime = 0;




CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha

CFiguras f_edificio;
CFiguras f_base;
CFiguras f_silla;
CTexture concreto;
CTexture pasto;
CTexture noComer;
CTexture nofumar;
CTexture silencio;
CTexture noCelular;
CTexture pizarron;
CTexture piso;
CTexture pared;
CTexture piso2;
CTexture techo;
CTexture sillaTextura;
CTexture metal;
CTexture mesa1;


CTexture tree;

CFiguras sky;

void arbol()
{
	glPushMatrix();
					glDisable(GL_LIGHTING);
					glEnable( GL_ALPHA_TEST );
					//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
					glAlphaFunc( GL_GREATER, 0.1 );
					//glEnable(GL_BLEND);     // Turn Blending On
					//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
					glBindTexture(GL_TEXTURE_2D, tree.GLindex);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(5.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(5.0, 10.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.0, 10.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.5, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(2.5, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(2.5, 5.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.5, 5.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(-45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.5, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(2.5, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(2.5, 5.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.5, 5.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(90, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.5, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(2.5, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(2.5, 5.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.5, 5.0, 0.0);
					glEnd();
					glDisable( GL_ALPHA_TEST );
					//glDisable(GL_BLEND);        // Turn Blending Off
					//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
					glEnable(GL_LIGHTING);
				
			glPopMatrix();
}

			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
    
   
	concreto.LoadTGA("texturas/concreto.tga");
	concreto.BuildGLTexture();
	concreto.ReleaseImage();

	
	noComer.LoadTGA("texturas/noComer.tga");
	noComer.BuildGLTexture();
	noComer.ReleaseImage();

	nofumar.LoadTGA("texturas/noFumar.tga");
	nofumar.BuildGLTexture();
	nofumar.ReleaseImage();

	silencio.LoadTGA("texturas/silencio.tga");
	silencio.BuildGLTexture();
	silencio.ReleaseImage();

	noCelular.LoadTGA("texturas/noCelular.tga");
	noCelular.BuildGLTexture();
	noCelular.ReleaseImage();

	pizarron.LoadTGA("texturas/pizarron.tga");
	pizarron.BuildGLTexture();
	pizarron.ReleaseImage();

	piso.LoadTGA("texturas/piso.tga");
	piso.BuildGLTexture();
	piso.ReleaseImage();

	pared.LoadTGA("texturas/pared.tga");
	pared.BuildGLTexture();
	pared.ReleaseImage();

	piso2.LoadTGA("texturas/piso2.tga");
	piso2.BuildGLTexture();
	piso2.ReleaseImage();

	metal.LoadTGA("texturas/metal.tga");
	metal.BuildGLTexture();
	metal.ReleaseImage();

	sillaTextura.LoadTGA("texturas/sillaTextura.tga");
	sillaTextura.BuildGLTexture();
	sillaTextura.ReleaseImage();

	techo.LoadTGA("texturas/techo.tga");
	techo.BuildGLTexture();
	techo.ReleaseImage();

	mesa1.LoadTGA("texturas/madera.tga");
	mesa1.BuildGLTexture();
	mesa1.ReleaseImage();






	//END NEW//////////////////////////////

	objCamera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);

}

void silla()
{
	glScalef(2.0, 2.0, 2.0);
	f_silla.prisma(0.40, 0.10, 0.50, sillaTextura.GLindex);
	glTranslatef(-0.15, -0.20, 0.15);
	f_silla.prisma(0.05, 0.30, 0.05, metal.GLindex);
	glTranslatef(0.3, 0.0, 0.0);
	f_silla.prisma(0.05, 0.30, 0.05, metal.GLindex);
	glTranslatef(-0.05, 0.0, -0.15);
	f_silla.prisma(0.05, 0.3, 0.05, metal.GLindex);
	glTranslatef(-0.20, 0.0, 0.0);
	f_silla.prisma(0.05, 0.3, 0.05, metal.GLindex);
	glTranslatef(0.10, 0.45, 0.25);
	f_silla.prisma(0.40, 0.50, 0.1, sillaTextura.GLindex);

}
void mesa()
{
	f_silla.prisma(3.0, 0.15, 1.5, mesa1.GLindex);
	glTranslatef(1.3, -0.6, 0.0);
	glColor3f(0.5,0.5,0.5);
	f_silla.prisma(0.05, 1.2, 0.5, 0.0);
	glTranslatef(-1.3, 0.0, 0.0);
	f_silla.prisma(0.05, 1.2, 0.5, 0.0);
	glTranslatef(-1.3, 0.0, 0.0);
	f_silla.prisma(0.05, 1.2, 0.5, 0.0);
	glTranslatef(0.0, -0.6, 0.0);
	f_silla.prisma(0.1, 0.1, 1.0, 0.0);
	glTranslatef(1.3, 0.0, 0.0);
	f_silla.prisma(0.1, 0.1, 1.0, 0.0);
	glTranslatef(1.3, 0.0, 0.0);
	f_silla.prisma(0.1, 0.1, 1.0, 0.0);
	glTranslatef(-1.3, 0.5, 0.0);
	f_silla.prisma(2.6, 0.05, 0.05, 0.0);
}
void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
		
	glPushMatrix();
		glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	

		glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				sky.skybox(130.0, 130.0, 130.0,text1.GLindex);
				glEnable(GL_LIGHTING);
				glColor3f(1.0,1.0,1.0);
			glPopMatrix();
			
			
				
				
				//Construccion del Laboratorio
				glPushMatrix();
					glPushMatrix();
						glTranslatef(7.0, 3.0, -4.0);
						f_edificio.prisma(10.0, 7.0, 0.0, 0.0);				//Pared Trasera
					glPopMatrix();
					glPushMatrix();
						glTranslatef(2.5, 3.0, 0.0);
						f_edificio.prisma(0.0, 6.50, 8.0, pared.GLindex);					//Pared Derecha
					glPopMatrix();
					glPushMatrix();
						glTranslatef(11.5, 3.0, 0.0);
						f_edificio.prisma(0.0, 7.0, 8.0, 0.0);					//Pared Izquierda
					glPopMatrix();
					glPushMatrix();
						glTranslatef(7.0, 3.0, 3.90);
						f_edificio.prisma(-9.5, 7.0, 0.0, 0.0);					//Pared delantera
					glPopMatrix();
					glPushMatrix();
						glTranslatef(7.0, 0.60, 0.0);
						f_edificio.prisma(-9.5, 0.0, 8.0, piso.GLindex);					//Piso
						f_edificio.prisma(1.0, 0.0, 8.0, piso2.GLindex);
					glPopMatrix();

					//Salon de clase
					//glPushMatrix();
					//glTranslatef(7.0, 3.0, -4.0);
					glPushMatrix();
						glPushMatrix();
							glTranslatef(-7.0, 3.0, -4.0);
							f_edificio.prisma(10.0, 7.0, 0.0001, pared.GLindex);				//Pared Trasera
						glPopMatrix();
						glPushMatrix();
							glTranslatef(2.5, 3.0, 0.0);
					f_edificio.prisma(0.0, 6.50, 8.0, pared.GLindex);					//Pared Derecha
					glPopMatrix();
					glPushMatrix();
					glTranslatef(11.5, 3.0, 0.0);
					f_edificio.prisma(0.0, 7.0, 8.0, pared.GLindex);					//Pared Izquierda
					glPopMatrix();
					glPushMatrix();
					glTranslatef(7.0, 3.0, 3.90);
					f_edificio.prisma(-9.5, 7.0, 0.0001, pared.GLindex);					//Pared delantera
					glPopMatrix();
					glPushMatrix();
					glTranslatef(7.0, 0.60, 0.0);
					f_edificio.prisma(-9.5, 0.0, 8.0, piso.GLindex);					//Piso
					f_edificio.prisma(1.0, 0.0, 8.0, piso2.GLindex);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(7.0, 6.0, 0.0);
					f_edificio.prisma(-9.5, 0.0, 8.0, 0.0);					//Piso
					
					glPopMatrix();
					//Termina creación de salon

						glTranslatef(7.0,2.70,-3.95);
						f_edificio.prisma(3.0, 2.5, 0.0, pizarron.GLindex);	 //Pizarron
						glTranslatef(-1.0, 1.50, 0.0);
						f_edificio.prisma(0.5, 0.5, 0.0, noComer.GLindex);		//No comer
						glTranslatef(0.5, 0.0, 0.0);
						f_edificio.prisma(0.5, 0.5, 0.0, nofumar.GLindex);	//No fumar
						glTranslatef(1.0, 0.0, 0.0);
						f_edificio.prisma(0.5, 0.5, 0.0, silencio.GLindex);	//No silencio
						glTranslatef(0.5, 0.0, 0.0);
						f_edificio.prisma(0.5,0.5,0.0,noCelular.GLindex);		//No celular	
					glPopMatrix();
				//Mesas
				glPushMatrix();
					glTranslatef(4.0,1.9,-3.0);
					mesa();
					glTranslatef(0.0, 0.7, 2.0);
					mesa();
					glTranslatef(0.0, 0.7, 2.0);
					mesa();
					glTranslatef(6.0, 0.7, 0.0);
					mesa();
					glTranslatef(0.0, 0.7, -2.0);
					mesa();
					glTranslatef(0.0, 0.7, -2.0);
					mesa();
				glPopMatrix();
				//Sillas
					glPushMatrix();
						glTranslatef(0.0, 1.8, 15.0);
						silla();	
					glPopMatrix();

					
				glPopMatrix();


				
				

				
				
	glPopMatrix();
			glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();
	glutSwapBuffers ( );

}


void animacion()
{

	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {

		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.03 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.03));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

int main ( int argc, char** argv )   // Main Function
{

  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (2000, 2000);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Salon"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );


  glutMainLoop        ( );          // 

  return 0;
}
