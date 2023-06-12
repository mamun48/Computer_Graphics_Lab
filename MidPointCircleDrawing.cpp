#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<utility>

int xc, yc, r;

void pixelPlot(int x, int y)
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);

    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);

}

void drawCircle()
{
    int x,y,p;
    x = 0, y = r;
    p = 1 - r;

    while(x < y)
    {
        x++;
        if(p < 0)
        {
            p += 2 * x + 1;
        }else
        {
            y--;
            p += 2 * x + 1 - 2 * y;
        }
        pixelPlot(x,y);
        delay(100);
    }

}

int main()
{
    int gd = DETECT;
    int gm;
    initgraph(&gd,&gm,"");
    printf("Enter the circle center(x,y) and  radius: \n");
    scanf("%d%d%d",&xc,&yc,&r);
    drawCircle();
    getch();
    return 0;
}
