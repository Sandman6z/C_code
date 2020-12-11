#include <stdio.h>
#include <stdlib.h>
#define h 6.626e-34
#define k 1.38e-23
#define c 3.0e+8
float bc;
float T=3000;
double c1=2*3.1415926*h*c*c;
float c2=h*c/(k*T);
float Mb;
DW::OpenGL::DW_BeginLineStrip();
for(float bc1=0.1;bc1<=6;bc1+=0.1
{(bc=bc1*1.0e-6;
Mb¦Ë=c1*pow(bc,-5)/exp(c2/bc);
DW::OpenGL::DW_LineTo(toP(bc1,Mb,0));
}
DW::OpenGL::DW_EndDraw();
system("pause");