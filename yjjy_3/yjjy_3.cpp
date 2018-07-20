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
void Write_String(FILE* fp,int x,int y)
{
	int i, j, k, m, q, w, ofs;
	unsigned char s[80] = "丁汉都", u[32];
	FILE *cfp;
	int offset;
	char pencil;
	char bpen = (char)0x00, wpen = (char)0xFF;
	char *pen = &pencil;
	*pen = PENCOLOR;
	fseek(fp, 0xA, SEEK_SET);
	fread(&offset, 1, sizeof(offset), fp);
	fseek(fp, 0, SEEK_SET);
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
						fseek(fp, offset + (400-(i+y)) * 300 + (k*8+j + x), SEEK_SET);
						fwrite(pen, 1, 1, fp);
					}
					else
					{
						fseek(fp, offset + (400 - (i + y)) * 300 + (k * 8 + j + x), SEEK_SET);
						fwrite(&wpen, 1, 1, fp);
					}
					m >>= 1;
				}
				m = 0x80;
				for (j = 0; j < 8; j++)
				{
					if (u[2 * i + 1] & m)
					{
						fseek(fp, offset + (400-(i + y)) * 300 + (k*8+j + 8 + x), SEEK_SET);
						fwrite(pen, 1, 1, fp);
						
					}
					else
					{
						fseek(fp, offset + (400 - (i + y)) * 300 + (k * 8 + j+8 + x), SEEK_SET);
						fwrite(&wpen, 1, 1, fp);
					}
					m >>= 1;
				}
				
			}
			
		}

	}


}

void print(char ch)
{
	/*_AL = ch;
	_asm {
		sub   dx, dx
		xor   ah, ah
		int   17h
	}*/
}

void Print_Bmp(FILE* fp)
{
	BITMAPFILEHEADER    fh;
	BITMAPINFOHEADER    bh;
	RGBQUAD             rgb[256];
	unsigned char bp[8][8] = { 0,32, 8,40, 2,34,10,42,
		48,16,56,24,50,18,58,26,
		12,44, 4,36,14,46, 6,38,
		60,28,52,20,62,30,54,22,
		3,35,11,43, 1,33, 9,41,
		51,19,59,27,49,17,57,25,
		15,47, 7,39,13,45, 5,37,
		63,31,55,23,61,29,53,21
	};
	unsigned char name[100], buffer[8][1000], *real, grey[256];
	unsigned long offset;
	long linebytes;
	int colors, i, j, k, t;
	unsigned char u, m;

	/*printf("Input filename:");
	gets(name);*/

	fseek(fp, 0, SEEK_SET);
	fread(&fh, sizeof(fh), 1, fp);
	fseek(fp, OFFSIZE, SEEK_SET);
	fread(&bh, sizeof(bh), 1, fp);

	printf("%ld %ld\n", bh.biWidth, bh.biHeight);
	printf("%d\n", bh.biBitCount);

	colors = 1 << bh.biBitCount;

	fread(&rgb, sizeof(RGBQUAD), colors, fp);

	for (i = 0; i<colors; i++)

		printf("%3d: %3d, %3d, %3d\n", i, rgb[i].rgbRed, rgb[i].rgbGreen, rgb[i].rgbBlue);


	getchar();
	for (i = 0; i<256; i++)
		grey[i] = (rgb[i].rgbRed*0.30 + rgb[i].rgbGreen*0.59 + rgb[i].rgbBlue*0.11) / 4;

	linebytes = (bh.biWidth*bh.biBitCount + 7) >>8;
	real = (unsigned char*)malloc(linebytes);
	for (k = 0; k<bh.biHeight / 8; k++) {
		for (i = 0; i<8; i++)
			fread(buffer[i], linebytes, 1, fp);
		for (i = 0; i<linebytes; i++) {
			u = 0;
			for (j = 0; j<8; j++) {
				m = (grey[buffer[j][i]] <= bp[j][i % 8]) << (7 - j);
				u = u | m;
			}
			real[i] = u;
		}
		    for(i=0;i<linebytes;i++)printf("%x  ",real[i]);
		     getchar();
		print(27); print(42); print(0);
		print((unsigned char)(linebytes) & 0x0FF);
		print((unsigned char)(linebytes >> 8) & 0x0FF);

		for (i = linebytes - 1; i >= 0; i--)print(real[i]);

		print(13);
		print(27); print(74); print(23);
	}

	if (bh.biHeight % 8) {
		for (i = 0; i<bh.biHeight % 8; i++)
			fread(buffer[i], linebytes, 1, fp);
		for (i = bh.biHeight % 8; i<8; i++)
			for (j = 0; j<linebytes; j++)
				buffer[i][j] = 0;

		for (i = 0; i<linebytes; i++) {
			u = 0;
			for (j = 0; j<8; j++) {
				m = (grey[buffer[j][i]] <= bp[j & 7][i & 7]) << (7 - j);
				u = u | m;
			}
			real[i] = u;
			printf("%x",real[i]);
		}
		  getchar();
		print(27); print(42); print(0);
		print((unsigned char)(linebytes) & 0x0FF);
		print((unsigned char)(linebytes >> 8) & 0x0FF);

		for (i = linebytes - 1; i >= 0; i--)print(real[i]);

		print(13);
		print(27); print(74); print(23);

	}



}
void Print_Bmp2(FILE* fp)
{
	BITMAPFILEHEADER    fh;
	BITMAPINFOHEADER    bh;
	RGBQUAD             rgb[256];
	unsigned char bp[8][8] = { 0,32, 8,40, 2,34,10,42,
		48,16,56,24,50,18,58,26,
		12,44, 4,36,14,46, 6,38,
		60,28,52,20,62,30,54,22,
		3,35,11,43, 1,33, 9,41,
		51,19,59,27,49,17,57,25,
		15,47, 7,39,13,45, 5,37,
		63,31,55,23,61,29,53,21
	};
	unsigned char name[100], buffer[8][1000], *real, grey[256];
	unsigned long offset;
	long linebytes;
	int colors, i, j, k, t;
	unsigned char u, m;
	char bpen=(char)0x00,wpen=(char)0xFF;
	

	
	fseek(fp, 0xA, SEEK_SET);
	fread(&offset, 1, sizeof(offset), fp);
	fseek(fp, 0, SEEK_SET);
	fread(&fh, sizeof(fh), 1, fp);
	fseek(fp, OFFSIZE, SEEK_SET);
	fread(&bh, sizeof(bh), 1, fp);

	printf("%ld %ld\n", bh.biWidth, bh.biHeight);
	printf("%d\n", bh.biBitCount);

	colors = 1 << bh.biBitCount;

	fread(&rgb, sizeof(RGBQUAD), colors, fp);

	/*for (i = 0; i<colors; i++)
		printf("%3d: %3d, %3d, %3d\n", i, rgb[i].rgbRed>>2, rgb[i].rgbGreen>>2, rgb[i].rgbBlue>>2);
*/

	for (i = 0; i < 256; i++) {
		grey[i] = (rgb[i].rgbRed*0.30 + rgb[i].rgbGreen*0.59 + rgb[i].rgbBlue*0.11) / 4;
		//printf("%3d:%3d\n",i, grey[i]);
	}
	
	linebytes = (bh.biWidth*bh.biBitCount + 7) >> 3;
	fseek(fp, offset, SEEK_SET);
	for (k = 0; k<bh.biHeight / 8; k++) {
		//t = 0;
		fseek(fp, offset + 8 * k * 300, SEEK_SET);
		for (i = 0; i < 8; i++) {
			
			fread(buffer[i], linebytes, 1, fp);
		}
		for (i = 0; i<linebytes; i++) {
			for (j = 0; j<8; j++) {
				if (i==0)
				{
					//printf("%3d", buffer[j][i]);
				}
				
				if (grey[buffer[j][i]] <= bp[j][i % 8])
				{
					fseek(fp, offset + (8*k+j)*300+i, SEEK_SET);
					fwrite(&bpen, 1, 1, fp);
				}
				else
				{
					fseek(fp, offset + (8 * k + j) * 300 + i, SEEK_SET);
					fwrite(&wpen, 1, 1, fp);
				}
			}
			if (i==0)
			{
				//printf("\n");
			}
		}
		
	}

	if (bh.biHeight % 8) {
		for (i = 0; i < bh.biHeight % 8; i++)
			fread(buffer[i], linebytes, 1, fp);
		for (i = bh.biHeight % 8; i < 8; i++)
			for (j = 0; j < linebytes; j++)
				//buffer[i][j] = 0;

		for (i = 0; i < linebytes; i++) {
			u = 0;
			for (j = 0; j < 8; j++) {
				if (grey[buffer[j][i]] <= bp[j][i % 8])
				{
					fseek(fp, offset + (8 * (k + 1) + j) * 300 + i, SEEK_SET);
					fwrite(&bpen, 1, 1, fp);
				}
				else
				{
					fseek(fp, offset + (8 * (k + 1) + j) * 300 + i, SEEK_SET);
					fwrite(&wpen, 1, 1, fp);
				}
			}

		}
	}
}