#include <stdio.h>
#include <leptonica/allheaders.h>
#include <tesseract/capi.h>





int main(int argc, char *argv[]) {
    PIX *im,*r,*g,*b;
    im = pixRead("./images/1.png");
    // printf("%d\n", im->w);//width
    // printf("%d\n", im->h);//height
    // printf("%d\n", im->d);//?
    // printf("%d\n", im->wpl);//?
    // printf("%d\n", im->refcount);//?
    // printf("%d\n", im->xres);
    // printf("%d\n", im->yres);
    // printf("%d\n", im->informat);
    // printf("%d\n", im->data[1]);
    // printf("%d\n", im->data[2]);
    // r = pixGetRGBComponent(im,COLOR_RED);
    // g = pixGetRGBComponent(im,COLOR_GREEN);
    // b = pixGetRGBComponent(im,COLOR_BLUE);
    // pixWrite("temp.png",im,IFF_PNG);
    // pixWrite("tempr.png",r,IFF_PNG);
    // pixWrite("tempg.png",g,IFF_PNG);
    // pixWrite("tempb.png",b,IFF_PNG);
    /*int i=0,j=0;
    for(i=0;i<(im->w)/2;i++)
    {
    	for(j=0;j<im->h;j++)
    	{
    		pixClearPixel(im,i,j);
    	}
    }
    pixWrite("temp.png",im,IFF_PNG);*/

    l_int32 pval,x,y,red,green,blue;
    pixGetRandomPixel(im,&pval,&x,&y);
    pixGetRGBPixel(im,600,600,&red,&green,&blue);
    printf("%d %d %d\n", red,green,blue);
    return 0;
}