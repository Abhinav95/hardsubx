#include <stdio.h>
#include <math.h>
#include <leptonica/allheaders.h>
#include <tesseract/capi.h>

#define BLACK 20.0
#define YELLOW 70.0

void rgb2lab(float R, float G, float B,float *L, float *a, float *b)
{
	//Conversion to the CIE-LAB color space to get the Luminance
	float X, Y, Z, fX, fY, fZ;

	X = 0.412453*R + 0.357580*G + 0.180423*B;
	Y = 0.212671*R + 0.715160*G + 0.072169*B;
	Z = 0.019334*R + 0.119193*G + 0.950227*B;

	X /= (255 * 0.950456);
	Y /=  255;
	Z /= (255 * 1.088754);

	if (Y > 0.008856)
	{
		fY = pow(Y, 1.0/3.0);
		*L = 116.0*fY - 16.0;
	}
	else
	{
		fY = 7.787*Y + 16.0/116.0;
		*L = 903.3*Y;
	}

	if (X > 0.008856)
		fX = pow(X, 1.0/3.0);
	else
		fX = 7.787*X + 16.0/116.0;

	if (Z > 0.008856)
		fZ = pow(Z, 1.0/3.0);
	else
		fZ = 7.787*Z + 16.0/116.0;

	*a = 500.0*(fX - fY);
	*b = 200.0*(fY - fZ);

	if (*L < BLACK) {
	*a *= exp((*L - BLACK) / (BLACK / 4));
	*b *= exp((*L - BLACK) / (BLACK / 4));
	*L = BLACK;
	}
	if (*b > YELLOW)
	*b = YELLOW;
}

int main(int argc, char *argv[]) {
	PIX *im;
	im = pixRead("./images/4.jpg");
	int i=0,j=0;
	l_int32 r,g,b;
	float L,A,B;
	for(i=0;i<im->w;i++)
	{
		for(j=0;j<im->h;j++)
		{
			pixGetRGBPixel(im,i,j,&r,&g,&b);
			rgb2lab((float)r,(float)g,(float)b,&L,&A,&B);
			if(L>99.3)
				pixSetRGBPixel(im,i,j,255,255,255);
			else
				pixSetRGBPixel(im,i,j,0,0,0);
		}
	}
	pixSetComponentArbitrary(im, L_ALPHA_CHANNEL, 255);
	pixWrite("temp4.png",im,IFF_PNG);
	return 0;
}