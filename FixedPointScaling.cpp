#include<graphics.h>
#include<stdio.h>
#include<conio.h>


int Sx,Sy,vertices;
int x[50],y[50];
int xFixed,yFixed;
void polygonDrawing()
{
    for(int i = 0; i < vertices; i++)
    {
        line(x[i],y[i],x[(i + 1) % vertices],y[(i + 1) % vertices]);
    }
}

void calculateFixedPoint()
{
    for(int i = 0; i < vertices; i++)
    {
        xFixed += x[i];
        yFixed += y[i];
    }
    xFixed /= vertices;
    yFixed /= vertices;
}

void Scaling()
{
    for(int i = 0; i < vertices; i++)
    {
        x[i] = xFixed + (x[i] - xFixed) * Sx;
        y[i] = yFixed + (y[i] - yFixed) * Sy;
    }
}
int main()
{
    int gd = DETECT;
    int gm ;
    initgraph(&gd,&gm,"");
    printf("Enter the number of vertices:");
    scanf("%d",&vertices);

   printf("Enter the points(x,y) of vertices clockwise :\n");

    for(int i = 0; i < vertices; i++)
    {
        scanf("%d %d",&x[i],&y[i]);
    }

    printf("Enter the scaling factor: ");

    scanf("%d %d",&Sx,&Sy);


    polygonDrawing();
    setcolor(YELLOW);

    calculateFixedPoint();
    Scaling();

    polygonDrawing();
    setcolor(RED);

    getch();
    closegraph();
    return 0;
}
