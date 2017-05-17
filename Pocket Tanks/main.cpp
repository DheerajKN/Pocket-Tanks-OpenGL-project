#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <GL/freeglut.h>

using namespace std;

#define pi 3.141592654
#define g 9.8
#define START  999
#define MOVE_R 998
#define MOVE_L 997
#define TURRET_UP 996
#define TURRET_DOWN 995
#define POWER_UP 994
#define POWER_DOWN 993
#define FIRE  992
#define IDLE 9999
#define MIRROR_Y 100
#define TRANSLATE 101
#define ROTATE 102
#define PLAYER_1 0
#define PLAYER_2 1
#define ARROW_HEIGHT 20
#define ARROW_WIDTH 5
#define WINDOW_MAX_WIDTH 500
#define WINDOW_MIN_WIDTH -500
#define WINDOW_MAX_HEIGTH 350
#define WINDOW_MIN_HEIGTH -350


void display();
void display_game();
void mouseClicks(int,int,int,int);
void longClicks(int,int,int,int);
void setArrow();
void displayArrow();
void final_display();

int turn=PLAYER_2;
int idle=-1;
int window;
int arrow_x=0,arrow_y=0,arrow_down=1,arrowpos=10,disparrow=0;
float p1_Score=50,p2_Score=50;

void G(int x, int y){
glBegin(GL_QUADS);
glVertex2i(x,y);
glVertex2i(x+40,y);
glVertex2i(x+40,y-10);
glVertex2i(x,y-10);

glVertex2i(x,y-10);
glVertex2i(x+10,y-10);
glVertex2i(x+10,y-50);
glVertex2i(x,y-50);

glVertex2i(x+10,y-40);
glVertex2i(x+10,y-50);
glVertex2i(x+40,y-50);
glVertex2i(x+40,y-40);

glVertex2i(x+30,y-40);
glVertex2i(x+40,y-40);
glVertex2i(x+40,y-20);
glVertex2i(x+30,y-20);

glVertex2i(x+30,y-30);
glVertex2i(x+20,y-30);
glVertex2i(x+20,y-20);
glVertex2i(x+30,y-20);
glEnd();
}

void S(int x,int y)
{
  glBegin(GL_QUADS);
  glVertex2i(x,y);
  glVertex2i(x+40,y);
  glVertex2i(x+40,y-10);
  glVertex2i(x,y-10);

  glVertex2i(x,y-10);
  glVertex2i(x+10,y-10);
  glVertex2i(x+10,y-20);
  glVertex2i(x,y-20);

  glVertex2i(x,y-20);
  glVertex2i(x+40,y-20);
  glVertex2i(x+40,y-30);
  glVertex2i(x,y-30);

  glVertex2i(x+30,y-30);
  glVertex2i(x+40,y-30);
  glVertex2i(x+40,y-40);
  glVertex2i(x+30,y-40);

  glVertex2i(x,y-40);
  glVertex2i(x+40,y-40);
  glVertex2i(x+40,y-50);
  glVertex2i(x,y-50);

  glEnd();  
}

void M(int x, int y){
glBegin(GL_QUADS);
glVertex2i(x,y);
glVertex2i(x+10,y);
glVertex2i(x+10,y-50);
glVertex2i(x,y-50);

glVertex2i(x+10,y);
glVertex2i(x+20,y-10);
glVertex2i(x+20,y-30);
glVertex2i(x+10,y-20);

glVertex2i(x+20,y-10);
glVertex2i(x+20,y-30);
glVertex2i(x+30,y-20);
glVertex2i(x+30,y);

glVertex2i(x+30,y);
glVertex2i(x+40,y);
glVertex2i(x+40,y-50);
glVertex2i(x+30,y-50);
glEnd();
}

void W(int x, int y){
glBegin(GL_QUADS);
glVertex2i(x,y);
glVertex2i(x+10,y);
glVertex2i(x+10,y-50);
glVertex2i(x,y-50);

glVertex2i(x+10,y-50);
glVertex2i(x+10,y-30);
glVertex2i(x+20,y-20);
glVertex2i(x+20,y-40);

glVertex2i(x+20,y-20);
glVertex2i(x+20,y-40);
glVertex2i(x+30,y-50);
glVertex2i(x+30,y-30);

glVertex2i(x+30,y-50);
glVertex2i(x+40,y-50);
glVertex2i(x+40,y);
glVertex2i(x+30,y);
glEnd();
}

void I(int x, int y){
glBegin(GL_QUADS);
glVertex2i(x+15,y);
glVertex2i(x+25,y);
glVertex2i(x+25,y-50);
glVertex2i(x+15,y-50);
glEnd();
}

void N(int x, int y){
glBegin(GL_QUADS);
glVertex2i(x,y);
glVertex2i(x,y-50);
glVertex2i(x+10,y-50);
glVertex2i(x+10,y);

glVertex2i(x+10,y);
glVertex2i(x+30,y-20);
glVertex2i(x+30,y-40);
glVertex2i(x+10,y-20);

glVertex2i(x+30,y);
glVertex2i(x+40,y);
glVertex2i(x+40,y-50);
glVertex2i(x+30,y-50);
glEnd();
}
void O(int x, int y){
glBegin(GL_QUADS);
glVertex2i(x+10,y);
glVertex2i(x+30,y);
glVertex2i(x+30,y-10);
glVertex2i(x+10,y-10);

glVertex2i(x,y-10);
glVertex2i(x+10,y-10);
glVertex2i(x+10,y-40);
glVertex2i(x,y-40);

glVertex2i(x+10,y-50);
glVertex2i(x+10,y-40);
glVertex2i(x+30,y-40);
glVertex2i(x+30,y-50);

glVertex2i(x+30,y-40);
glVertex2i(x+40,y-40);
glVertex2i(x+40,y-10);
glVertex2i(x+30,y-10);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2i(x,y-10);
glVertex2i(x+10,y);
glVertex2i(x+10,y-10);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2i(x+10,y-50);
glVertex2i(x+10,y-40);
glVertex2i(x,y-40);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2i(x+30,y-50);
glVertex2i(x+30,y-40);
glVertex2i(x+40,y-40);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2i(x+30,y-10);
glVertex2i(x+30,y);
glVertex2i(x+40,y-10);
glEnd();
}

void V(int x, int y){
glBegin(GL_QUADS);
glVertex2i(x,y);
glVertex2i(x+10,y);
glVertex2i(x+20,y-25);
glVertex2i(x+20,y-50);

glVertex2i(x+20,y-25);
glVertex2i(x+20,y-50);
glVertex2i(x+40,y);
glVertex2i(x+30,y);
glEnd();
}

void P(int x,int y)
{ 
  glBegin(GL_QUADS);
  glVertex2i(x,y);
  glVertex2i(x+10,y);
  glVertex2i(x+10,y-50);
  glVertex2i(x,y-50);

  glVertex2i(x+10,y);
  glVertex2i(x+40,y);
  glVertex2i(x+40,y-10);
  glVertex2i(x+10,y-10);

  glVertex2i(x+40,y-10);
  glVertex2i(x+40,y-30);
  glVertex2i(x+30,y-30);
  glVertex2i(x+30,y-10);

  glVertex2i(x+30,y-20);
  glVertex2i(x+30,y-30);
  glVertex2i(x+10,y-30);
  glVertex2i(x+10,y-20);

  glEnd();
}

void L(int x,int y)
{
  glBegin(GL_QUADS);
  glVertex2i(x,y);
  glVertex2i(x+10,y);
  glVertex2i(x+10,y-50);
  glVertex2i(x,y-50);

  glVertex2i(x+10,y-40);
  glVertex2i(x+40,y-40);
  glVertex2i(x+40,y-50);
  glVertex2i(x+10,y-50);

  glEnd();  
}

void A(int x,int y)
{
  glBegin(GL_QUADS);
  glVertex2i(x,y-50);
  glVertex2i(x+15,y);
  glVertex2i(x+25,y);
  glVertex2i(x+10,y-50);

  glVertex2i(x+40,y-50);
  glVertex2i(x+30,y-50);
  glVertex2i(x+20,y-10);
  glVertex2i(x+25,y);

  glVertex2i(x+15,y-25);
  glVertex2i(x+25,y-25);
  glVertex2i(x+30,y-35);
  glVertex2i(x+10,y-35);

  glEnd();  
}

void Y(int x,int y)
{
  glBegin(GL_QUADS);
  glVertex2i(x+15,y-50);
  glVertex2i(x+15,y-25);
  glVertex2i(x+25,y-25);
  glVertex2i(x+25,y-50);

  glVertex2i(x+15,y-25);
  glVertex2i(x+30,y);
  glVertex2i(x+40,y);
  glVertex2i(x+25,y-25);

  glVertex2i(x+15,y-25);
  glVertex2i(x+20,y-18);
  glVertex2i(x+10,y);
  glVertex2i(x,y);

  glEnd();  
}

void E(int x,int y)
{
  glBegin(GL_QUADS);
  glVertex2i(x,y);
  glVertex2i(x+10,y);
  glVertex2i(x+10,y-50);
  glVertex2i(x,y-50);

  glVertex2i(x+10,y);
  glVertex2i(x+40,y);
  glVertex2i(x+40,y-10);
  glVertex2i(x+10,y-10);

  glVertex2i(x+10,y-20);
  glVertex2i(x+30,y-20);
  glVertex2i(x+30,y-30);
  glVertex2i(x+10,y-30);

  glVertex2i(x+10,y-40);
  glVertex2i(x+40,y-40);
  glVertex2i(x+40,y-50);
  glVertex2i(x+10,y-50);

  glEnd();  
}


void R(int x,int y)
{
  glBegin(GL_QUADS);
  glVertex2i(x,y);
  glVertex2i(x+10,y);
  glVertex2i(x+10,y-50);
  glVertex2i(x,y-50);

  glVertex2i(x+10,y);
  glVertex2i(x+40,y);
  glVertex2i(x+40,y-10);
  glVertex2i(x+10,y-10);

  glVertex2i(x+40,y-10);
  glVertex2i(x+40,y-30);
  glVertex2i(x+30,y-30);
  glVertex2i(x+30,y-10);

  glVertex2i(x+30,y-20);
  glVertex2i(x+30,y-30);
  glVertex2i(x+10,y-30);
  glVertex2i(x+10,y-20);

  glVertex2i(x+10,y-30);
  glVertex2i(x+20,y-30);
  glVertex2i(x+40,y-50);
  glVertex2i(x+30,y-50);

  glEnd();  
}

void One(int x,int y)
{
  glBegin(GL_QUADS);
  glVertex2i(x,y-10);
  glVertex2i(x+15,y);
  glVertex2i(x+15,y-10);
  glVertex2i(x,y-20);

  glVertex2i(x+15,y);
  glVertex2i(x+25,y);
  glVertex2i(x+25,y-40);
  glVertex2i(x+15,y-40);

  glVertex2i(x,y-40);
  glVertex2i(x+40,y-40);
  glVertex2i(x+40,y-50);
  glVertex2i(x,y-50);

  glEnd();  
}

void Two(int x,int y)
{
  glBegin(GL_QUADS);
  glVertex2i(x,y);
  glVertex2i(x+40,y);
  glVertex2i(x+40,y-10);
  glVertex2i(x,y-10);

  glVertex2i(x+30,y-10);
  glVertex2i(x+40,y-10);
  glVertex2i(x+40,y-20);
  glVertex2i(x+30,y-20);

  glVertex2i(x,y-20);
  glVertex2i(x+40,y-20);
  glVertex2i(x+40,y-30);
  glVertex2i(x,y-30);

  glVertex2i(x,y-30);
  glVertex2i(x+10,y-30);
  glVertex2i(x+10,y-40);
  glVertex2i(x,y-40);


  glVertex2i(x,y-40);
  glVertex2i(x+40,y-40);
  glVertex2i(x+40,y-50);
  glVertex2i(x,y-50);

  glEnd();  
}

class terrain
{
  int terrain_y[1100];

public:
  
  void createfreshterrain()
  {
    int y=0;

    for(int i=0;i<=1000;i++) 
    { y=50*(sin((float)(i)*3.14*0.6/360));
      this->terrain_y[i]=y;
    }

  }

  void displayterrain()
  {
    glColor3ub(20,155,80);
    glBegin(GL_LINES);
    for(int i=-500;i<=500;i++)
     {
       glVertex2i(i,-150);
       glVertex2i(i,this->terrain_y[i+500]);
     }  
     glEnd();
  }

  int getcoord(int x)
  {
    return terrain_y[x];
  }


};

terrain global_terrain;



class image
{
   unsigned short int type;                
   unsigned int h_size;                       
   unsigned short int reserved1, reserved2;
   unsigned int offset;
   unsigned int size;               
   int width,height;                
   unsigned short int planes;  
   unsigned short int bits;    
   unsigned int compression;        
   unsigned int imagesize;         
   int xresolution,yresolution;    
   unsigned int ncolours;
   unsigned int importantcolours;
   unsigned char blue,green,red;
   FILE *fp_read;
   unsigned char *matrix;
   string name;

public:

 image(string n)
 {
   name=n;
   matrix=NULL;
 }

 int getImageWidth()
 {
  return width;
 }

 int getImageHight()
 {
  return height;
 }

void getHeader()
{
    type=0;
    fp_read=fopen(reinterpret_cast<const char*>(name.c_str()),"rb+");   
    fread(&type,sizeof(type),1,fp_read);
    if(type!=19778)
    {cout<<"Not a BMP Image\n"<<type;
     exit(0);}
    fread(&h_size,sizeof(h_size),1,fp_read);
    fread(&reserved1,sizeof(reserved1),1,fp_read);
    fread(&reserved2,sizeof(reserved2),1,fp_read);
    fread(&offset,sizeof(offset),1,fp_read);
}

void getInfoHeader()
{
    fread(&size,sizeof(size),1,fp_read);
    fread(&width,sizeof(width),1,fp_read);
    fread(&height,sizeof(height),1,fp_read);
    fread(&planes,sizeof(planes),1,fp_read);
    fread(&bits,sizeof(bits),1,fp_read);
    if(bits!=24)
    {cout<<"Not a 24 bit Image\n";
     exit(0);}
    fread(&compression,sizeof(compression),1,fp_read);
    fread(&imagesize,sizeof(imagesize),1,fp_read);
    fread(&xresolution,sizeof(xresolution),1,fp_read);
    fread(&yresolution,sizeof(yresolution),1,fp_read);
    fread(&ncolours,sizeof(ncolours),1,fp_read);
    fread(&importantcolours,sizeof(importantcolours),1,fp_read);
}

unsigned char* read_matrix()
{
    unsigned char temp;
    int count_row=0,count_col=0;
    int count=0,i,j;
    int mat_size=(width*3)*height;
 
    if(matrix!=NULL)
    {
      free(matrix);
    }
     matrix=(unsigned char*)calloc(mat_size,sizeof(unsigned char));

     while (count_row<height)
      {
        while(count_col<width)
        {
    	    fread(&blue,sizeof(unsigned char),1,fp_read);
            matrix[count]=blue;
            count++;
      	    fread(&green,sizeof(unsigned char),1,fp_read);
	    matrix[count]=green;
            count++;
    	    fread(&red,sizeof(unsigned char),1,fp_read);
	    matrix[count]=red;
            count_col++;
            count++;
        }

            for(i=1;i<=((width)%4);i++)
               {
 	    	        fread(&temp,sizeof(unsigned char),1,fp_read);
               }

        count_row++;
        count_col=0;
      }

      return matrix;
}

unsigned char* getImgMatrix()
{
  return matrix;
}	
   	
}fireimg("fire.bmp"),startimg("start.bmp");

int onMouse=0,mx=0,my=0;

class tank
{
  int moves;
  int power;
//  int angle;
  int weapons[10];
  float pos_x1,pos_y1;
  float pos_x2,pos_y2;
  int initposx,initposy;
  unsigned char* mat;
  int player;
  int h,w;
  float theta;
  float t_mat[3][3];
  float turret_mat[3][3];
  float turret[9][2];
  float tposx,tposy,tfireposx,tfireposy;
  float tAngle;
  public:
	tank()
	{}

    tank(int p)
    {
      moves=8;
      power=50;
      theta=0.0;
      h=34;
      w=75;
      weapons[10];
      player=p;
      tAngle=50-14;
      pos_x1=(250+rand()%150)*(1-2*player);
      // pos_x1=300*(1-2*player);
      pos_y1=20+rand()%100;
      // pos_y1=90;
      pos_x2=pos_x1+w;
      pos_y2=pos_y1;
      initposx=pos_x1;
      initposy=pos_y1;
	  float fact=0.34;
    tposx=pos_x1+35;
	  tposy=pos_y1+20;
    //  turret[9][2]={{310,312},{300,330},{240,345},{240,342},{200,352},{200,340},{240,330},{240,327},{300,312}};  //front view
	  turret[0][0]=(10*fact)+tposx;turret[0][1]=(12*fact)+tposy;
	  turret[1][0]=(00*fact)+tposx;turret[1][1]=(30*fact)+tposy;	
	  turret[2][0]=(-60*fact)+tposx;turret[2][1]=(45*fact)+tposy;
	  turret[3][0]=(-60*fact)+tposx;turret[3][1]=(42*fact)+tposy;
	  turret[4][0]=(-100*fact)+tposx;turret[4][1]=(52*fact)+tposy;
	  turret[5][0]=(-100*fact)+tposx;turret[5][1]=(40*fact)+tposy;
	  turret[6][0]=(-60*fact)+tposx;turret[6][1]=(30*fact)+tposy;
	  turret[7][0]=(-60*fact)+tposx;turret[7][1]=(27*fact)+tposy;
	  turret[8][0]=(00*fact)+tposx;turret[8][1]=(12*fact)+tposy;  
    tfireposx=(turret[4][0]+turret[5][0])/2;
    tfireposy=(turret[4][1]+turret[5][1])/2;
    }

    int getmoves()
	{return moves;}

  int getTankHeight()
  {return h;}

  int getplayer()
  {
    return player;
  }

  void setmoves(int m)
	{moves=m;}

    float getAngle()
	{return (int)(tAngle+14)%360;}

    void setAngle(float a)
	{tAngle=a-14;
    if(tAngle<0)
      tAngle=360+tAngle;}

	float gettposx()
	{return tposx;}
	
	float gettposy()
	{return tposy;}

    int getTankx1()
    {return pos_x1;}

    int getTankx2()
    {return pos_x2;}

    int getTanky1()
    {return pos_y1;}

    int getTanky2()
    {return pos_y2;}

    int getPower()
    {return power;}


    float gettfireposx()
    {return tfireposx;}


    float gettfireposy()
    {return tfireposy;}

    void setPower(int p)
    {power=p;}


    void setTank()
    {
      int tx=pos_x1;
      int ty=pos_y1;
      int sx1=tx;
      int sy1=global_terrain.getcoord(sx1+500);
      int sx2=pos_x2;
      int sy2=global_terrain.getcoord(sx2+500);
      float sm=(float)(sy2-sy1)/(sx2-sx1);
      float tm=(float)(pos_y2-ty)/(pos_x2-tx);
      float stheta=atan(sm)*180/3.14;
      theta=atan(tm)*180/3.14;
      float rot=stheta-theta;
      get_trans_matrix(ROTATE,pos_x1,pos_y1,rot);
      get_trans_matrix(TRANSLATE,0,(sy1-ty-h/3),0);
     // cout<<initposx<<"  "<<initposy<<" player: "<<player<<endl;
    //   cout<<sin(rot*3.14/180)<<"  "<<rot<<" player: "<<player<<endl;
    //    cout<<pos_x2<<"  "<<pos_y2<<"  "<<sx2<<"  "<<sy2<<" player: "<<player<<endl;
    }

  void setTurret(float tx,float ty,float theta)
  {
    float arr[3][3];
    float newtposx,newtposy;
  for (int i = 0; i <3; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      arr[i][j]=(i==j)?1.0:0.0;
    }
  }
    theta=(theta*3.14/180);
    theta=player*theta+(1-player)*(-1*theta);
	  arr[0][0]=cos(theta);
    arr[0][1]=sin(theta);
    arr[1][0]=-1*sin(theta);
    arr[1][1]=cos(theta);
    arr[2][0]=tx*(1-cos(theta))+ty*sin(theta);
    arr[2][1]=ty*(1-cos(theta))-tx*sin(theta);   
    newtposx=tfireposx*arr[0][0]+tfireposy*arr[1][0]+arr[2][0];
    newtposy=tfireposx*arr[0][1]+tfireposy*arr[1][1]+arr[2][1];
    tfireposx=newtposx;
    tfireposy=newtposy;
    turret_mat_mul(arr);
  }

    void createtank()
    {
       image i("tank1.bmp");
       i.getHeader();
       i.getInfoHeader();
       mat=i.read_matrix();

       if(mat==NULL)
        return;

      w=i.getImageWidth();
      h=i.getImageHight();
    for(int k=0;k<3;k++)
      for (int j = 0; j < 3; j++)
      {
        if(j==k)
         { t_mat[k][j]=1;
		   turret_mat[k][j]=1;		
		 }
        else
         { t_mat[k][j]=0;
		   turret_mat[k][j]=0;		 	
		 }      
	}

      if(player)
         {get_trans_matrix(TRANSLATE,-1*initposx,-1*initposy,0);
          get_trans_matrix(MIRROR_Y,initposx,initposy,0);
          get_trans_matrix(TRANSLATE,initposx,initposy,0);
          setTank();
	        setTurret(tposx,tposy,tAngle);
          }
      else
      { setTank();
	      setTurret(tposx,tposy,tAngle);
			}

   glEnd();    
   }


void get_trans_matrix(int type,float tx,float ty,float theta)
{
  float arr[3][3];
  for (int i = 0; i <3; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      arr[i][j]=(i==j)?1.0:0.0;
    }
  }
	theta=theta*3.14/180;
  float newtposx;
  float newtposy;
  switch(type)
  {
    case MIRROR_Y:
    arr[0][0]=-1;
    pos_x1=-1*pos_x1;
    pos_x2=-1*pos_x2;
    mat_mul(arr);
    newtposx=tposx*arr[0][0]+tposy*arr[1][0]+arr[2][0];
    newtposy=tposx*arr[0][1]+tposy*arr[1][1]+arr[2][1];
    tposx=newtposx;
    tposy=newtposy;
    newtposx=tfireposx*arr[0][0]+tfireposy*arr[1][0]+arr[2][0];
    newtposy=tfireposx*arr[0][1]+tfireposy*arr[1][1]+arr[2][1];
    tfireposx=newtposx;
    tfireposy=newtposy;
    turret_mat_mul(arr);
    break;
    case TRANSLATE:
    arr[2][0]=tx;
    arr[2][1]=ty;
    pos_x1=pos_x1+tx;
    pos_x2=pos_x2+tx;
    pos_y1=pos_y1+ty;
    pos_y2=pos_y2+ty;
    mat_mul(arr);
    newtposx=tposx*arr[0][0]+tposy*arr[1][0]+arr[2][0];
    newtposy=tposx*arr[0][1]+tposy*arr[1][1]+arr[2][1];
    tposx=newtposx;
    tposy=newtposy;
    newtposx=tfireposx*arr[0][0]+tfireposy*arr[1][0]+arr[2][0];
    newtposy=tfireposx*arr[0][1]+tfireposy*arr[1][1]+arr[2][1];
    tfireposx=newtposx;
    tfireposy=newtposy; 
    turret_mat_mul(arr);
    break;
    case ROTATE:
    arr[0][0]=cos(theta);
    arr[0][1]=sin(theta);
    arr[1][0]=-1*sin(theta);
    arr[1][1]=cos(theta);
    arr[2][0]=tx*(1-cos(theta))+ty*sin(theta);
    arr[2][1]=ty*(1-cos(theta))-tx*sin(theta);   
	  float x1=(pos_x1-tx)*cos(theta)+(ty-pos_y1)*sin(theta)+tx;
	  float y1=(pos_x1-tx)*sin(theta)+(pos_y1-ty)*cos(theta)+ty;
	  pos_x1=x1;
	  pos_y1=y1;
	  float x2=(pos_x2-tx)*cos(theta)+(ty-pos_y2)*sin(theta)+tx;
	  float y2=(pos_x2-tx)*sin(theta)+(pos_y2-ty)*cos(theta)+ty;
    pos_x2=x2;
	  pos_y2=y2;
    mat_mul(arr);
    newtposx=tposx*arr[0][0]+tposy*arr[1][0]+arr[2][0];
    newtposy=tposx*arr[0][1]+tposy*arr[1][1]+arr[2][1];
    arr[0][0]=1;
    arr[0][1]=0;
    arr[0][2]=0;
    arr[1][0]=0;
    arr[1][1]=1;
    arr[1][2]=0;
    arr[2][0]=-1*(tposx-newtposx);
    arr[2][1]=-1*(tposy-newtposy);
    arr[2][2]=1;
    tposx=newtposx;
    tposy=newtposy;
    newtposx=tfireposx*arr[0][0]+tfireposy*arr[1][0]+arr[2][0];
    newtposy=tfireposx*arr[0][1]+tfireposy*arr[1][1]+arr[2][1];
    tfireposx=newtposx;
    tfireposy=newtposy; 
    turret_mat_mul(arr);
    break;
  }
}


void mat_mul(float a1[][3])
{
  float temp[3][3];
 for(int i = 0; i < 3; i++)
 {
    for (int j = 0; j < 3; j++)
    {
      temp[i][j]=0.0;    
    }
 }

  for(int i=0;i<3;i++)
    for (int j=0; j<3; j++)
      for (int k=0; k<3; k++)
      {
        temp[i][j]=temp[i][j]+t_mat[i][k]*a1[k][j];
      }

 for(int i = 0; i < 3; i++)
  {
     for (int j = 0; j < 3; j++)
      {
       t_mat[i][j]=temp[i][j];
      }
  }
}

void turret_mat_mul(float a1[][3])
{
  float temp[3][3];
 for(int i = 0; i < 3; i++)
 {
    for (int j = 0; j < 3; j++)
    {
      temp[i][j]=0.0;    
    }
 }

  for(int i=0;i<3;i++)
    for (int j=0; j<3; j++)
      for (int k=0; k<3; k++)
      {
        temp[i][j]=temp[i][j]+turret_mat[i][k]*a1[k][j];
      }

 for(int i = 0; i < 3; i++)
  {
     for (int j = 0; j < 3; j++)
      {
       turret_mat[i][j]=temp[i][j];
      }
  }
}

void setTurretVertex(int x,int y)
{
  int a[3],b[3];
  a[0]=x;
  a[1]=y;
  a[2]=1;
  b[0]=0;
  b[1]=0;
  b[2]=0;
  for(int i=0;i<1;i++)
    for(int j=0;j<3;j++)
      for(int k=0;k<3;k++)
        b[j]=b[j]+a[k]*turret_mat[k][j];

//	cout<<b[0]<<" "<<b[1]<<" "<<tposx<<" "<<tposy<<endl;
    glVertex2i(b[0],b[1]);
}

void setVertex(int x,int y)
{
  int a[3],b[3];
  a[0]=x;
  a[1]=y;
  a[2]=1;
  b[0]=0;
  b[1]=0;
  b[2]=0;
  for(int i=0;i<1;i++)
    for(int j=0;j<3;j++)
      for(int k=0;k<3;k++)
        b[j]=b[j]+a[k]*t_mat[k][j];

    glVertex2i(b[0],b[1]);
}

void displayTank()
{ 
 glColor3ub((105+player*110)%255,(105+player*30)%255,(55+player*30)%255);
	glBegin(GL_POLYGON);
	for(int j=0;j<9;j++)
	{     
	setTurretVertex(turret[j][0],turret[j][1]);
//	glVertex2fv(turret[j]);
	}	
	glEnd();
 glColor3ub(255,255,255);
 glBegin(GL_LINE_LOOP);
	for(int j=0;j<9;j++)
	{
	 setTurretVertex(turret[j][0],turret[j][1]);
    // glVertex2fv(turret[j]);
	}	
	glEnd();
 int count=0;
  glBegin(GL_POINTS);
   for(int j=0;j<w*h;j++)
    { 
      if(static_cast<int>(mat[count+2])!=255 && static_cast<int>(mat[count+1])!=255 && static_cast<int>(mat[count])!=255)
       {glColor3ub(static_cast<int>((mat[count+2]+player*100)%255),static_cast<int>((mat[count+1]+player*10)%255),static_cast<int>(mat[count]));
        setVertex(initposx+j%w,initposy+j/w);
       }
     count+=3;
    }
    glEnd();
	
}

}tank1,tank2;

class physics{
  int draw_endpoint ;
  int draw_endpoint1;
  int n_points ;
  float x,y  ;
  float theta;
  float v_0; //meters per second
  float tof ;
  std::vector<std::vector<float> > mat_p;
  std::vector<float> row;
  int pos;
  int radius;
  float xn1min,xn1max,xn2min,xn2max,yn1min,yn1max,yn2min,yn2max,gamma,alpha;
  float cxn1min,cxn1max,cxn2min,cxn2max,cyn1min,cyn1max,cyn2min,cyn2max;

  public:

  std::vector<std::vector<float> > matrix_multiply(std::vector<std::vector<float> > p,float t[][3],int n,int m,int o)
{
  std::vector<std::vector<float> > temp(n,std::vector<float>(o));
  int i,j,k;
 for( i = 0; i < 3; i++)
 {
    for ( j = 0; j < 3; j++)
    {
      temp[i][j]=0.0;    
    }
 }

  for( i=0;i<n;i++)
    for (j=0; j<o; j++)
      for ( k=0; k<m; k++)
      {
        temp[i][j]=temp[i][j]+p[i][k]*t[k][j];
       }

 return temp;
}

  void translate(float tx,float ty)
{
  float arr[3][3];
  int i,j;
 for ( i = 0; i <3; ++i)
  {
    for (j = 0; j < 3; ++j)
    {
      arr[i][j]=(i==j)?1.0:0.0;
    }
  }
  arr[2][0]=tx;
  arr[2][1]=ty;
  mat_p=matrix_multiply(mat_p,arr,3,3,3);

}

void rotate(float tx,float ty,float theta)
{
  float arr[3][3];
  int i,j;
  theta=theta*3.14/180;
 for ( i = 0; i <3; ++i)
  {
    for (j = 0; j < 3; ++j)
    {
      arr[i][j]=(i==j)?1.0:0.0;
    }
  }

    arr[0][0]=cos(theta);
    arr[0][1]=sin(theta);
    arr[1][0]=-1*sin(theta);
    arr[1][1]=cos(theta);
    arr[2][0]=tx*(1-cos(theta))+ty*sin(theta);
    arr[2][1]=ty*(1-cos(theta))-tx*sin(theta);   
    mat_p=matrix_multiply(mat_p,arr,3,3,3);

}
  

  void d_circle(int h,int k, int r, float c1,float c2,float c3,float c4) {
    glColor4f(c1,c2,c3,c4);
    int x,y;

    glBegin(GL_POLYGON);
      for (int i = 0; i < 180; i++)
      {
      x = r * cos(i);
      y = r * sin(i);
      glVertex2f(x+h,y+k);
    
      x = r * cos(i + 0.1);
      y = r * sin(i + 0.1);
      glVertex2f(x+h,y+k);
      }

    glEnd();
  }

 void explosion()
 {
   for(int i=0;i<150;i++)
   {
    d_circle(mat_p[0][0],mat_p[0][1],(int)i/2,0.6+(float)(rand()%3)/10,0.3+float(rand()%3)/10,0,(float)(100-i)/1000);  

    if((int)mat_p[0][0]+i/2>=(int)xn1min && (int)mat_p[0][0]-i/2<=(int)xn1max && (int)mat_p[0][1]+i/2>=(int)yn1min && (int)mat_p[0][1]-i/2<=(int)yn1max)
    {
        if(turn==PLAYER_1)
        {
          p1_Score-=0.5;
        }
        else if(turn==PLAYER_2)
        {  p2_Score-=0.5; }
    }
    glutSwapBuffers();

        for(int j=0;j<5000000;j++); 
   }

 }

  void calc1(float initx,float inity,float v_0,float theta)
    {   
        theta=theta*pi/180;
        radius=10;
        tank* currtank;
        if(turn==PLAYER_1)
          currtank=&tank2;
        else
          {currtank=&tank1;
          }

        int i,h;
        int collision=0;
        float m1,k;
        float x1,y1,x2,y2,x3,y3,x4,y4;

        h=currtank->getTankHeight();
        x1=currtank->getTankx1();
        x2=currtank->getTankx2();
        y1=currtank->getTanky1();
        y2=currtank->getTanky2();
        m1=(y2-y1)/(x2-x1);

        k=(pow((x1-x2),2)/(pow(y2-y1,2)))+1;

        if(m1>0)
          {x3=x1-sqrt(h*h/k);
          y3=y1+sqrt((k-1)*h*h/k);}
        else if(m1<0)
          {x3=x1+sqrt(h*h/k);
          y3=y1+sqrt((k-1)*h*h/k);}
        else
        {x3=x1;
          y3=y1+h;}

        x4=x3+(x2-x1);
        y4=y3+(y2-y1);

        alpha=atan2(y2-y1,x2-x1);
        gamma=atan2(y3-y1,x3-x1);

        if(currtank->getplayer()==PLAYER_2)
        {
          alpha=pi-alpha;
          gamma=pi-gamma;
        }

        float nt=90*pi/180;

        xn1max=x1*cos(alpha);
        xn1max=(x2*cos(alpha)>xn1max?x2*cos(alpha):xn1max);
        xn1max=(x3*cos(alpha)>xn1max?x3*cos(alpha):xn1max);
        xn1max=(x4*cos(alpha)>xn1max?x4*cos(alpha):xn1max);

        xn1min=x1*cos(alpha);
        xn1min=(x2*cos(alpha)<xn1min?x2*cos(alpha):xn1min);
        xn1min=(x3*cos(alpha)<xn1min?x3*cos(alpha):xn1min);
        xn1min=(x4*cos(alpha)<xn1min?x4*cos(alpha):xn1min);

        yn1max=y1*cos(nt+alpha);
        yn1max=(y2*cos(nt+alpha)>yn1max?y2*cos(nt+alpha):yn1max);
        yn1max=(y3*cos(nt+alpha)>yn1max?y3*cos(nt+alpha):yn1max);
        yn1max=(y4*cos(nt+alpha)>yn1max?y4*cos(nt+alpha):yn1max);
  
        yn1min=y1*cos(nt+alpha);
        yn1min=(y2*cos(nt+alpha)<yn1min?y2*cos(nt+alpha):yn1min);
        yn1min=(y3*cos(nt+alpha)<yn1min?y3*cos(nt+alpha):yn1min);
        yn1min=(y4*cos(nt+alpha)<yn1min?y4*cos(nt+alpha):yn1min);

        xn2max=x1*cos(gamma);
        xn2max=(x2*cos(gamma)>xn2max?x2*cos(gamma):xn2max);
        xn2max=(x3*cos(gamma)>xn2max?x3*cos(gamma):xn2max);
        xn2max=(x4*cos(gamma)>xn2max?x4*cos(gamma):xn2max);
  
        xn2min=x1*cos(gamma);
        xn2min=(x2*cos(gamma)<xn2min?x2*cos(gamma):xn2min);
        xn2min=(x3*cos(gamma)<xn2min?x3*cos(gamma):xn2min);
        xn2min=(x4*cos(gamma)<xn2min?x4*cos(gamma):xn2min);

        yn2max=y1*cos(nt+gamma);
        yn2max=(y2*cos(nt+gamma)>yn2max?y2*cos(nt+gamma):yn2max);
        yn2max=(y3*cos(nt+gamma)>yn2max?y3*cos(nt+gamma):yn2max);
        yn2max=(y4*cos(nt+gamma)>yn2max?y4*cos(nt+gamma):yn2max);
  
        yn2min=y1*cos(nt+gamma);
        yn2min=(y2*cos(nt+gamma)<yn2min?y2*cos(nt+gamma):yn2min);
        yn2min=(y3*cos(nt+gamma)<yn2min?y3*cos(nt+gamma):yn2min);
        yn2min=(y4*cos(nt+gamma)<yn2min?y4*cos(nt+gamma):yn2min);

        cxn1min=(initx-radius)*cos(alpha);
        cxn1max=(initx+radius)*cos(alpha);
        cyn1min=(inity-radius)*cos(nt+alpha);
        cyn1max=(inity+radius)*cos(nt+alpha);
       
        cxn2min=(initx-radius)*cos(gamma);
        cxn2max=(initx+radius)*cos(gamma);
        cyn2min=(inity-radius)*cos(nt+gamma);
        cyn2max=(inity+radius)*cos(nt+gamma);

        v_0=v_0*1.75;
        tof=15;
      if(turn==PLAYER_1)
        tof=-1*15;
    
        float del_t = tof/400;
        float temp=0;
        float x,y;

        row.resize(3);
        mat_p.resize(3,row);

        mat_p[0][0]=0; mat_p[0][1]=0; mat_p[0][2]=1;
        mat_p[1][0]=0;mat_p[1][1]=0,mat_p[1][2]=1;
        mat_p[2][0]=radius/4;mat_p[2][1]=radius/2,mat_p[2][2]=1;
        translate(initx,inity);

        for(i=1;i<500;i++)
        {
         x = v_0*cos(theta)*temp;
         y = v_0*sin(theta)*temp - ((g*temp*temp)/2);
   
         display_game();
         collision=0;

        if(mat_p[0][0]+radius<-500-70 || mat_p[0][0]-radius>500+70)
         {break;}
          
        if(global_terrain.getcoord(500+(int)mat_p[0][0])>=(int)(mat_p[0][1]-radius))
        { explosion();
          break;
        } 

        if((int)cxn1max>=(int)xn1min && (int)cxn1min<=(int)xn1max && (int)cyn1max>=(int)yn1min && (int)cyn1min<=(int)yn1max)
         {
          ++collision;
         }

         if((int)cxn2max>=(int)xn2min && (int)cxn2min<=(int)xn2max && (int)cyn2max>=(int)yn2min && (int)cyn2min<=(int)yn2max)
         {
          ++collision;
         }

         if(collision==2)
          { 
            explosion();
            break;}

        cxn1min=(mat_p[0][0]-radius)*cos(alpha);
        cxn1max=(mat_p[0][0]+radius)*cos(alpha);
        cyn1min=(mat_p[0][1]-radius)*cos(nt+alpha);
        cyn1max=(mat_p[0][1]+radius)*cos(nt+alpha);

        cxn2min=(mat_p[0][0]-radius)*cos(gamma);
        cxn2max=(mat_p[0][0]+radius)*cos(gamma);
        cyn2min=(mat_p[0][1]-radius)*cos(nt+gamma);
        cyn2max=(mat_p[0][1]+radius)*cos(nt+gamma);

        d_circle(mat_p[0][0],mat_p[0][1],radius,0.8,0.8,0.8,0.3);
        d_circle(mat_p[1][0],mat_p[1][1],radius-2,0,0,0,0.3);
        d_circle(mat_p[2][0],mat_p[2][1],((radius-2)/5)+1,0.5,0.5,0.5,0.3);
        temp += del_t;
        float xf=v_0*cos(theta)*temp;
        float yf=v_0*sin(theta)*temp - ((g*temp*temp)/2);
        translate(xf-x,yf-y);
        rotate(mat_p[0][0],mat_p[0][1],-4);

         glutSwapBuffers();
        }
    }

};

class button
{
   int width,height,st,id;
   int x1,y1,x2,y2,x3,y3,x4,y4;
   unsigned char co[3];
public:
   button()
	{}
   button(int name,int x,int y,int w,int h)
	{
	   id=name;
	   x1=x;
	   y1=y;
	   x2=x1+w;
           y2=y1;
	   x3=x1+w;
           y3=y1-h;
	   x4=x1;
	   y4=y1-h;
	   co[0]=static_cast<int>(100);
	   co[1]=static_cast<int>(100);
       co[2]=static_cast<int>(100);
        }


   unsigned char* getColor()
   {
    return co;
   }
        
  void setColor(unsigned char c[])
  {
   co[0]=c[0];
   co[1]=c[1];
   co[2]=c[2];	
   }

  void bshow()
  {
    glBegin(GL_QUADS);
    glColor3ubv(co);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glVertex2i(x3,y3);
    glVertex2i(x4,y4);
    glEnd();
  }

 void getImage(string n)
{
  unsigned char* mat;
  int count=0;

  image *currimg;

  if(n=="start.bmp")
    {mat=startimg.getImgMatrix();
      currimg=&startimg;}
  else if(n=="fire.bmp")
  {mat=fireimg.getImgMatrix();
    currimg=&fireimg;
  }
  if(mat==NULL)
    return;
  glBegin(GL_POINTS);
  for(int j=0;j<5000;j++)
   { 
     if(static_cast<int>(mat[count+2])!=255 && static_cast<int>(mat[count+1])!=255 && static_cast<int>(mat[count])!=255)
     {glColor3ub(static_cast<int>(mat[count+2]),static_cast<int>(mat[count+1]),static_cast<int>(mat[count]));
      glVertex2i(x4+j%currimg->getImageWidth(),y4+j/currimg->getImageWidth());
     }
      count+=3;
     
  }
   glEnd();

}

int getId()
{
  return id;
}

bool ifClicked(int x,int y)
{
	if(mx<x2+500 && mx>x1+500 && my>350-y1 && my<350-y4)
		return true;
	else
	 return false;
}

void onClick()
  {

   if(onMouse)
   { 
    tank *currtank;
    if(turn==PLAYER_1)
	 	currtank=&tank1;
	else
		currtank=&tank2;
	int move=35;
	int dist;

	switch(id)
	{
	 case START:
	     getImage("start.bmp");
	     glClear(GL_COLOR_BUFFER_BIT);
       disparrow=1;
       setArrow();
	     glutDisplayFunc(display_game);
	 break;
   case FIRE:
      { getImage("fire.bmp");
       physics phy;
       disparrow=2;
     //  display_game();
       phy.calc1(currtank->gettfireposx(),currtank->gettfireposy(),currtank->getPower(),currtank->getAngle()*(1-2*currtank->getplayer())*-1);
       turn=(turn+1)%2;
       setArrow();
       disparrow=1;
       break;
     }
	 case MOVE_R:
         disparrow=0;
				 glutIdleFunc(NULL);  
        if(currtank->getmoves()<=0)
					break;			
				currtank->setmoves(currtank->getmoves()-1);
			   dist=currtank->getTankx2();
				if(495-dist<35)
					move=495-dist;
				if(move>0)			
				{
				 for(int i=0;i<move;i++)
	             { currtank->get_trans_matrix(TRANSLATE,1,0,0);
				   currtank->setTank();
				   currtank->setTurret(currtank->gettposx(),currtank->gettposy(),0);	
				   display_game();		
         for(int j=0;j<4000000;j++);
				 }
			 }		
	 break;
	 case MOVE_L:
      disparrow=0;
      glutIdleFunc(NULL); 
			if(currtank->getmoves()<=0)
					break;			
				currtank->setmoves(currtank->getmoves()-1);
			   dist=currtank->getTankx2();
				if(abs(-500-dist)<35)
					move=abs(-495-dist);
				if(move>0)			
				{
				 for(int i=0;i<move;i++)
	             { currtank->get_trans_matrix(TRANSLATE,-1,0,0);
				   currtank->setTank();
				   currtank->setTurret(currtank->gettposx(),currtank->gettposy(),0);	
				   display_game();		
					for(int j=0;j<4000000;j++);
				 }
			 }
	 break;
   case TURRET_UP:
            disparrow=0;
            currtank->setAngle((int)(currtank->getAngle()+1)%360);
            currtank->setTurret(currtank->gettposx(),currtank->gettposy(),1);  
            display_game();
            for(int j=0;j<70000000;j++);                   
   break;    
   case TURRET_DOWN:
         disparrow=0;
         currtank->setAngle((int)(currtank->getAngle()-1)%360);
         currtank->setTurret(currtank->gettposx(),currtank->gettposy(),-1);  
         display_game();
         for(int j=0;j<70000000;j++);                    
   break;    
   case POWER_UP:
         disparrow=0;
        if(currtank->getPower()<100)
         {  currtank->setPower(currtank->getPower()+1);
            glutPostRedisplay();
            for(int j=0;j<70000000;j++);}
   break;
   case POWER_DOWN:
        disparrow=0;
        if(currtank->getPower()>0)
         {  currtank->setPower(currtank->getPower()-1);
            glutPostRedisplay();
            for(int j=0;j<70000000;j++);}
   break;
    }	
  } 
   else  
     {
		     glutPostRedisplay();
    }	
  }
}buttonAction[8];

void setArrow()
{
  tank* currtank;
   if(turn==PLAYER_1)
    currtank=&tank1;
  else
    currtank=&tank2;
  int x=(currtank->getTankx1()+currtank->getTankx2())/2;
  arrow_x=x;
  int y= (currtank->getTanky1()+currtank->getTanky2())/2+75;
  arrow_y=y;
}

void displayArrow()
{

 if(arrow_down)
 {
  if(arrowpos<0)
    {arrow_down=0;}
  arrowpos=arrowpos-1;
 }
 else
 {
  if(arrowpos>10)
    {arrow_down=1;}
  arrowpos=arrowpos+1;  
 }
 glColor3f(1,1,1);
 glBegin(GL_LINES);
 glVertex2i(arrow_x,arrow_y+ARROW_HEIGHT+arrowpos);
 glVertex2i(arrow_x,arrow_y+arrowpos);
 glVertex2i(arrow_x,arrow_y+arrowpos);
 glVertex2i(arrow_x-ARROW_WIDTH,arrow_y+(ARROW_HEIGHT)/2+arrowpos);
 glVertex2i(arrow_x,arrow_y+arrowpos);
 glVertex2i(arrow_x+ARROW_WIDTH,arrow_y+(ARROW_HEIGHT)/2+arrowpos);
 glEnd();
 for(int i=0;i<8000000;i++);
 glutPostRedisplay();
}

void display()
{
 glClearColor(0.0,0.0,0.0,0.04);
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 startimg.getHeader();
 startimg.getInfoHeader();
 startimg.read_matrix();
 fireimg.getHeader();
 fireimg.getInfoHeader();
 fireimg.read_matrix();
 button start(START,-25,75,100,50);
 unsigned char c[3]={155,155,155};
 start.setColor(c);
 start.bshow();
 start.getImage("start.bmp");
 buttonAction[0]=start;
// start.onClick(START);
 glColor3f(0,1,0);
 glRasterPos2i(-75,300);
 glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,reinterpret_cast<const unsigned char*>("Pocket Tanks "));
 glColor3f(0,0.7,0.7);
 glRasterPos2i(-400,-260);
 glutBitmapString(GLUT_BITMAP_HELVETICA_18,reinterpret_cast<const unsigned char*>("Submitted To:- "));
 glRasterPos2i(-400,-280);
 glutBitmapString(GLUT_BITMAP_HELVETICA_18,reinterpret_cast<const unsigned char*>("Mr. Pankaj Badoni "));
 glRasterPos2i(180,-220);
 glutBitmapString(GLUT_BITMAP_HELVETICA_18,reinterpret_cast<const unsigned char*>("Submitted By:- "));
 glRasterPos2i(180,-240);
 glutBitmapString(GLUT_BITMAP_HELVETICA_18,reinterpret_cast<const unsigned char*>("Chaitanya Subhedar, 24, 500039856 "));
 glRasterPos2i(180,-260);  
 glutBitmapString(GLUT_BITMAP_HELVETICA_18,reinterpret_cast<const unsigned char*>("Piyush Mishra, 45, 500039835"));
 glRasterPos2i(180,-280);
 glutBitmapString(GLUT_BITMAP_HELVETICA_18,reinterpret_cast<const unsigned char*>("K. N. Dheeraj, 80, 500037782"));
 
 glutSwapBuffers();
 terrain t;
 t.createfreshterrain();
 global_terrain=t;
 tank t1(0);
 t1.createtank();
 tank1=t1;
 tank t2(1);
 t2.createtank();
 tank2=t2;
 unsigned char c1[3]={100,100,100};
 button speed_down(MOVE_L,-200,-220,25,25);
 buttonAction[1]=speed_down;
 button speed_up(MOVE_R,-100,-220,25,25);
 buttonAction[2]=speed_up;
 button angle_up(TURRET_UP,75,-200,25,25);
 buttonAction[3]=angle_up;
 button angle_down(TURRET_DOWN,175,-200,25,25);
 buttonAction[4]=angle_down;
 button power_down(POWER_DOWN,75,-270,25,25);
 buttonAction[5]=power_down;
 button power_up(POWER_UP,175,-270,25,25);
 buttonAction[6]=power_up;
 button fire(FIRE,-50,-220,100,50);
 buttonAction[7]=fire;
 setArrow();
}

void final_display()
{
glClearColor(0,0,0,1);
glClear(GL_COLOR_BUFFER_BIT);

glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glLoadIdentity();
glScalef(1.1,1.1,1.1);
glTranslatef(2,2,0);
glColor3f(1,0,0);
G(-200,190);
A(-150,190);
M(-100,190);
E(-50,190);
O(50,190);
V(100,190);
E(150,190);
R(200,190);
glPopMatrix();

glPushMatrix();
glLoadIdentity();
glScalef(0.5,0.5,0.5);
glTranslatef(-48,2,0);
glColor3f(0,1,0);

  P(-250,120);
  L(-200,120);
  A(-150,120);
  Y(-100,120);
  E(-50,120);
  R(0,120);

if(p2_Score<=0){
   One(60,120);
}
else{
Two(60,120);
}

W(150,120);
I(200,120);
N(250,120);
S(300,120);
glPopMatrix();

glPushMatrix();
glLoadIdentity();
glScalef(1.1,1.1,1.1);
glColor3f(1,1,1);
G(-200,190);
A(-150,190);
M(-100,190);
E(-50,190);
O(50,190);
V(100,190);
E(150,190);
R(200,190);
glPopMatrix();

glPushMatrix();
glLoadIdentity();
glScalef(0.5,0.5,0.5);
glTranslatef(-50,0,0);
glColor3f(1,1,1);

  P(-250,120);
  L(-200,120);
  A(-150,120);
  Y(-100,120);
  E(-50,120);
  R(0,120);

if(p2_Score<=0){
   One(60,120);
}
else{
Two(60,120);
}

W(150,120);
I(200,120);
N(250,120);
S(300,120);
glPopMatrix();

glutSwapBuffers();

}

void display_game()
{
 glClearColor(0.0,0.0,0.0,0.04);
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

 glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glLoadIdentity();
 glScalef(0.5f,0.5f,0);
 glTranslatef(-550,360,0);
 glColor3f(1,1,1);
 P(-400,300);
 L(-350,300);
 A(-300,300);
 Y(-250,300);
 E(-200,300);
 R(-150,300);
 One(-90,300);
 glPopMatrix();

 glPushMatrix();
 glLoadIdentity();
 glScalef(0.5f,0.5f,0);
 glTranslatef(1000,360,0);
 glColor3f(1,1,1);
 P(-400,300);
 L(-350,300);
 A(-300,300);
 Y(-250,300);
 E(-200,300);
 R(-150,300);
 Two(-90,300);
 glPopMatrix();

 stringstream sstr5;
 glRasterPos2i(-475,280);
 glutBitmapString(GLUT_BITMAP_HELVETICA_18,reinterpret_cast<const unsigned char*>("Health: "));
 sstr5<<(int)p1_Score;
 string ps=sstr5.str();
 glRasterPos2i(-400,280);
 glutBitmapString(GLUT_BITMAP_HELVETICA_18,reinterpret_cast<const unsigned char*>(ps.c_str()));
 glRasterPos2i(300,280);
 glutBitmapString(GLUT_BITMAP_HELVETICA_18,reinterpret_cast<const unsigned char*>("Health: "));
 sstr5.str("");
 sstr5<<(int)p2_Score;
 ps=sstr5.str();
 glRasterPos2i(375,280);
 glutBitmapString(GLUT_BITMAP_HELVETICA_18,reinterpret_cast<const unsigned char*>(ps.c_str()));
 
if(p1_Score<=0 || p2_Score<=0)
{
   glutDisplayFunc(final_display);
   glutPostRedisplay();
}

 global_terrain.displayterrain();

 unsigned char c[3]={100,100,100};

 glColor3ub(150,150,150);
 glBegin(GL_QUADS);
 glVertex2i(-500,-350);
 glVertex2i(500,-350);
 glVertex2i(500,-150);
 glVertex2i(-500,-150);
 glEnd();

 buttonAction[1].bshow();
 glColor3ub(255,255,255);
 glBegin(GL_QUADS);
 glVertex2i(-174,-220);
 glVertex2i(-94,-220);
 glVertex2i(-94,-245);
 glVertex2i(-174,-245);
 glEnd();
 glColor3ub(0,0,0);
 glBegin(GL_LINE_LOOP);
 glVertex2i(-174,-220);
 glVertex2i(-102,-220);
 glVertex2i(-102,-245);
 glVertex2i(-174,-245);
 glEnd();
 glColor3ub(255,0,0);
 char s[2];
 
 tank currtank;
 stringstream sstr;
 if(turn==PLAYER_1)
   currtank=tank1;
 else
   currtank=tank2;

 sstr<<currtank.getmoves();
 string str1= sstr.str();
 glRasterPos2i(-150,-240);
 glutBitmapString(GLUT_BITMAP_HELVETICA_18,reinterpret_cast<const unsigned char*>(str1.c_str()));
 buttonAction[2].bshow();
 
 
 buttonAction[3].bshow();
 glColor3ub(255,255,255);
 glBegin(GL_QUADS);
 glVertex2i(100,-200);
 glVertex2i(175,-200);
 glVertex2i(175,-225);
 glVertex2i(100,-225);
 glEnd();
 glColor3ub(0,0,0);
 glBegin(GL_LINE_LOOP);
 glVertex2i(100,-200);
 glVertex2i(173,-200);
 glVertex2i(173,-225);
 glVertex2i(100,-225);
 glEnd();
 stringstream sstr1;
 sstr1<<currtank.getAngle();
 string str2= sstr1.str();
 glColor3ub(255,0,0);
 glRasterPos2i(140,-220);
 glutBitmapString(GLUT_BITMAP_HELVETICA_18,reinterpret_cast<const unsigned char*>(str2.c_str()));
 buttonAction[4].bshow();


 
 buttonAction[5].bshow();
 glColor3ub(255,255,255);
 glBegin(GL_QUADS);
 glVertex2i(100,-270);
 glVertex2i(175,-270);
 glVertex2i(175,-295);
 glVertex2i(100,-295);
 glEnd();
 glColor3ub(0,0,0);
 glBegin(GL_LINE_LOOP);
 glVertex2i(100,-270);
 glVertex2i(173,-270);
 glVertex2i(173,-295);
 glVertex2i(100,-295);
 glEnd();
 stringstream sstr2;
 sstr2<<currtank.getPower();
 string str3= sstr2.str(); 
 glColor3ub(255,0,0);
 glRasterPos2i(140,-290);
 glutBitmapString(GLUT_BITMAP_HELVETICA_18,reinterpret_cast<const unsigned char*>(str3.c_str()));
 button power_down(MOVE_L,175,-270,25,25);
 buttonAction[6].bshow();
 
 buttonAction[7].bshow();
 buttonAction[7].getImage("fire.bmp");
 
 tank1.displayTank();
 tank2.displayTank();

 if(disparrow== 1)
 displayArrow();

 glColor3ub(0,0,0);
 glRasterPos2i(-170,-210);
 glutBitmapString(GLUT_BITMAP_HELVETICA_18,reinterpret_cast<const unsigned char*>("Moves"));
 glRasterPos2i(110,-190);
 glutBitmapString(GLUT_BITMAP_HELVETICA_18,reinterpret_cast<const unsigned char*>("Angle"));
 glRasterPos2i(110,-260);
 glutBitmapString(GLUT_BITMAP_HELVETICA_18,reinterpret_cast<const unsigned char*>("Power"));
            
 glutSwapBuffers(); 
}

void idle_func()
{
  switch(idle)
  {case 3:
    buttonAction[idle].onClick();
   break;
   case 4:
    buttonAction[idle].onClick();
   break;
   case 5:
    buttonAction[idle].onClick();
   break;
   case 6:
    buttonAction[idle].onClick();
   break;
   
 }

}

void mouseClicks(int button, int state, int x, int y)
{
   mx=x;
   my=y;    
 if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    onMouse = 1;

	 for(int i=0;i<8;i++)
		{
			if(buttonAction[i].ifClicked(x,y))
				{
          if(buttonAction[i].getId()==TURRET_UP || buttonAction[i].getId()==TURRET_DOWN || buttonAction[i].getId()==POWER_UP || buttonAction[i].getId()==POWER_DOWN)
            {idle=i;
             glutIdleFunc(idle_func);}

             unsigned char* c=buttonAction[i].getColor();  
					for(int j=0;j<3;j++)
           {  c[j]=static_cast<int>(c[j])-50; }
              buttonAction[i].setColor(c);
              buttonAction[i].bshow();
              buttonAction[i].onClick();
        	break;
				}
		 }	
       glutPostRedisplay();
    }
    else if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
   { onMouse=0;
     idle=-1;
     // glutIdleFunc(NULL);
	   for(int i=0;i<8;i++)
	   	{
		  	if(buttonAction[i].ifClicked(x,y))
		 	  	{
            unsigned char* c=buttonAction[i].getColor();
           for(int j=0;j<3;j++)
           {  c[j]=static_cast<int>(c[j])+50; }
              buttonAction[i].setColor(c);
              buttonAction[i].bshow();
           
				  	buttonAction[i].onClick();			
      	  	break;
				  }
		 }	
      glutPostRedisplay();
   }
}

void myinit()
{
 glLoadIdentity();
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-500,500,-350,350);
 glEnable(GL_BLEND);
 glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

void keypress(unsigned char key,int x,int y)
{
  if(key==27)
    {glutDestroyWindow(window);}

}

int main(int argc,char** argv)
{
glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB); 
 glutInitWindowSize(1000,700);
 glutInitWindowPosition(100,10);
 window=glutCreateWindow("Pocket Tanks");
 myinit();
 glutDisplayFunc(display);
 glutMouseFunc(mouseClicks);
 glutKeyboardFunc(keypress);
 glutIdleFunc(NULL);
 glutMainLoop();
return 0;
}
