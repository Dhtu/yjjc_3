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

	//Print_Bmp2(nfp);
	
	Write_String(nfp, 100, 300);

	return 0;
}

