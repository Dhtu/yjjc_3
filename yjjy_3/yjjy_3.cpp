// yjjy_3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"yjjy_3.h"
void Show_Bmpif(FILE* fp)
{
	BITMAPFILEHEADER fh;
	BITMAPINFOHEADER ih;
	fseek(fp, 0, SEEK_SET);
	fread(&fh, 1, sizeof(BITMAPFILEHEADER), fp);
	fseek(fp, OFFSIZE, SEEK_SET);//神奇的字节对齐
	fread(&ih, 1, sizeof(BITMAPINFOHEADER), fp);
	printf("%d, %d\n", sizeof(BITMAPFILEHEADER), sizeof(BITMAPINFOHEADER));
	printf("实际图像大小: %ld\n图像宽度: %ld\n图像高度: %ld\n每像素位数: %d\n",
		ih.biSize, ih.biWidth, ih.biHeight, ih.biBitCount);
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
void Write_String(FILE* fp,int offset ,int x,int y)
{
	int i, j, k, m, q, w, ofs;
	unsigned char s[80] = "丁汉都", u[32];
	FILE *cfp;
	char pencil;
	char *pen = &pencil;
	*pen = PENCOLOR;

	for (k = 0; s[k] != 0; k = k + 2)
	{
		q = s[k] - 0xA1;
		w = s[k + 1] - 0xA1;
		ofs = (q * 94 + w) * 32 + ERROR;

		cfp = fopen("mhzk16c.txt", "rb");
		fseek(cfp, ofs, SEEK_SET);
		fread(u, 1, 32, cfp);
		
		for (i = 0; i < 16; i++)
		{
			m = 0x80;
			
			for (i = 0; i < 16; i++)
			{
				m = 0x80;
				for (j = 0; j < 8; j++)
				{
					if (u[2 * i] & m)
					{
						fseek(fp, offset + (400-(i+y)) * 300 + (k*16+j + x), SEEK_SET);
						fwrite(pen, 1, 1, fp);
					}
					
					m >>= 1;
				}
				m = 0x80;
				for (j = 0; j < 8; j++)
				{
					if (u[2 * i + 1] & m)
					{
						fseek(fp, offset + (400-(i + y)) * 300 + (k*16+j + 8 + x), SEEK_SET);
						fwrite(pen, 1, 1, fp);
						
					}
					
					m >>= 1;
				}
				
			}
			
		}

	}


}


int main()

{
	FILE* fp,*nfp;
	long dataoff;
	if ((fp = fopen("k398a.bmp", "rb")) == NULL) {
		printf("file error!\n");
		exit(0);
	}
	
	//Show_Bmpif(fp);
	nfp=Copy_Bmp(fp);
	fseek(nfp, 0xA, SEEK_SET);
	fread(&dataoff, 1, sizeof(dataoff), nfp);
	
	Write_String(nfp, dataoff, 100, 100);
	return 0;
}

