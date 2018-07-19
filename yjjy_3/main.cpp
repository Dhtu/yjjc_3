#include "stdafx.h"
int main()

{
	int  i, j, k, t;
	FILE* fp, *nfp;
	long dataoff;
	unsigned long offset;
	BITMAPFILEHEADER	fh;
	BITMAPINFOHEADER	ih;
	RGBQUAD				rgb[256];
	if ((fp = fopen("k398a.bmp", "rb")) == NULL) {
		printf("file error!\n");
		exit(0);
	}

	//Show_Bmpif(fp);
	nfp = Copy_Bmp(fp);

	Print_Bmp2(nfp);
	//fseek(nfp, 0xA, SEEK_SET);
	//fread(&dataoff, 1, sizeof(dataoff), nfp);

	//fseek(nfp, 0, SEEK_SET);
	//fread(&fh, 1, sizeof(BITMAPFILEHEADER), nfp);
	//fseek(nfp, OFFSIZE, SEEK_SET);//神奇的字节对齐
	//fread(&ih, 1, sizeof(BITMAPINFOHEADER), nfp);
	//fread(rgb, sizeof(RGBQUAD), 256, nfp);
	

	return 0;
}

