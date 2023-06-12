#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

#define Sin(x) sin(x * acos(-1.0)/ 180)
#define Cos(x) cos(x * acos(-1.0)/180)

int xPivot,yPivot,vertices;
int x[50],y[50];
double rotationAngle;

void polygonDrawing()
{
    for(int i = 0; i < vertices; i++)
    {
        line(x[i],y[i],x[(i + 1) % vertices],y[(i + 1) % vertices]);
    }
}



void Rotate()
{
    for(int i = 0; i < vertices; i++)
    {
        x[i] = xPivot + ((x[i] - xPivot) * Cos(rotationAngle)) - ((y[i] - yPivot) * Sin(rotationAngle));
        y[i] = yPivot + ((x[i] - xPivot) * Sin(rotationAngle)) + ((y[i] - yPivot) * Cos(rotationAngle));
    }
}
int main()
{
    int gd = DETECT;
    int gm ;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    printf("Enter the number of vertices:");
    scanf("%d",&vertices);

   printf("Enter the points(x,y) of vertices clockwise :\n");

    for(int i = 0; i < vertices; i++)
    {
        scanf("%d %d",&x[i],&y[i]);
    }

    printf("Enter the Pivot points: ");
    scanf("%d %d",&xPivot,&yPivot);

    printf("Enter the Rotation angle: ");
    scanf("%lf",&rotationAngle);


    polygonDrawing();
    setcolor(RED);


    Rotate();

    polygonDrawing();
    setcolor(WHITE);

    getch();
    closegraph();
    return 0;
}
