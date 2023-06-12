
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<utility>


void drawline(int x1, int y1, int x2, int y2)
{
    if(x1 > x2)
    {
        int m = x1;   //Swaping value
        x1 = x2;
        x2 = m;
        m = y1;
        y1 = y2;
        y2 = m;
    }
    int dx = x2 - x1, dy = y2 - y1, p = 2*dy - dx;

    for(int x = x1, y = y1; x <= x2; x++)
    {
        putpixel(x,y,WHITE);
        delay(100);

        if(p > 0)
        {
            y1 > y2 ? y-- : y++;
            p += 2 * (dy - dx);
        }else
        {
            p += 2 * dy;
        }
    }
}

int main()
{
    int gd = DETECT;
    int gm;
    initgraph(&gd,&gm,"");
    int x1,y1,x2,y2;
    printf("Enter the two points(x,y): \n");
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    drawline(x1,y1,x2,y2);
    getch();
    return 0;
}
