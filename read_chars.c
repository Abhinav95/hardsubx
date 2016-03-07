#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <leptonica/allheaders.h>
#include <tesseract/capi.h>

void die(const char *errstr) {
    fputs(errstr, stderr);
    exit(1);
}

char *getTesseractText(char *image_path)
{
    TessBaseAPI *handle;
    PIX *img;
    char *text;

    if((img = pixRead(image_path)) == NULL)
        die("Error reading image\n");

    handle = TessBaseAPICreate();
    if(TessBaseAPIInit3(handle, NULL, "eng") != 0)
        die("Error initialising tesseract\n");

    TessBaseAPISetImage2(handle, img);
    if(TessBaseAPIRecognize(handle, NULL) != 0)
        die("Error in Tesseract recognition\n");

    if((text = TessBaseAPIGetUTF8Text(handle)) == NULL)
        die("Error getting text\n");

    TessBaseAPIEnd(handle);
    TessBaseAPIDelete(handle);
    pixDestroy(&img);
    return text;

}

int main(int argc, char *argv[]) {
    char *s = getTesseractText("./thresholded/2_a.jpg");
    printf("%s\n", s);
    return 0;
}
