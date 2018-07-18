// yjjy_3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"yjjy_3.h"
void Show_Bmpif(FILE* fp)
{
	BITMAPFILEHEADER fh;
	BITMAPINFOHEADER ih;
	fread(&fh, 1, sizeof(BITMAPFILEHEADER), fp);
	fseek(fp, OFFSIZE, SEEK_SET);//神奇的字节对齐
	fread(&ih, 1, sizeof(BITMAPINFOHEADER), fp);
	printf("%d, %d\n", sizeof(BITMAPFILEHEADER), sizeof(BITMAPINFOHEADER));
	printf("实际图像大小: %ld\n图像宽度: %ld\n图像高度: %ld\n每像素位数: %d\n",
		ih.biSizeImage, ih.biWidth, ih.biHeight, ih.biBitCount);
}
FILE* Copy_Bmp(FILE* fp)
{
	FILE* nfp;
	char* buffer = (char*)malloc(BUFFERSIZE);
	int readbit;
	nfp = fopen("newzzy.bmp", "wb+T");
	fseek(fp, 0, SEEK_SET);
	while ((readbit=fread(buffer,1,BUFFERSIZE,fp))>0)
	{
		fwrite(buffer, readbit, 1, nfp);
	}
	fseek(nfp, 0, SEEK_SET);
	Show_Bmpif(nfp);
	free(buffer);
	return nfp;

}

int main()

{
	FILE* fp,*nfp;
	if ((fp = fopen("k398a.bmp", "rb")) == NULL) {
		printf("file error!\n");
		exit(0);
	}
	
	Show_Bmpif(fp);
	nfp=Copy_Bmp(fp);

	return 0;
}

