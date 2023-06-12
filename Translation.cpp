#include<graphics.h>
#include<stdio.h>
#include<conio.h>


int Tx,Ty,vertices;
int x[50],y[50];
void polygonDrawing()
{
    for(int i = 0; i < vertices; i++)
    {
        line(x[i],y[i],x[(i + 1) % vertices],y[(i + 1) % vertices]);
    }
}



void Translate()
{
    for(int i = 0; i < vertices; i++)
    {
        x[i] += Tx;
        y[i] += Ty;
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

    printf("Enter the Translator factor: ");

    scanf("%d %d",&Tx,&Ty);

    cleardevice();
    polygonDrawing();
    setcolor(YELLOW);


    Translate();

    polygonDrawing();
    setcolor(RED);

    getch();
    closegraph();
    return 0;
}
