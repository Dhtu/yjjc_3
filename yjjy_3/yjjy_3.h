#ifndef YJJY
#define YJJY
typedef unsigned char	byte;
#define BUFFERSIZE 4096
#define OFFSIZE 0x0E
#define ERROR 8192
#define PENCOLOR (char)0x00
#define BLACK (char)
/*�ļ�ͷ�ṹ*/
typedef struct tagBITMAPFILEHEADER
{
	short bfType; /* ͨ���� 'BM' �����������ƺ��ж�OS/2�ı�ʶ����ʲô����*/
	long  bfSize; /* �ļ���С�����ֽ�Ϊ��λ*/
	short bfReserved1; /*��������������Ϊ0*/
	short bfReserved2; /*��������������Ϊ0*/
	long  bfOffBits; /*���ļ�ͷ��ʼ��ʵ�ʵ�ͼ������֮����ֽڵ�ƫ������*/
} BITMAPFILEHEADER;

/*��Ϣͷ�ṹ*/
typedef struct tagBITMAPINFOHEADER
{
	long biSize; /* ��Ϣͷ��С */
	long biWidth; /* ͼ���� */
	long biHeight; /* ͼ��߶� */
	short biPlanes; /* ����Ϊ1 */
	short biBitCount; /* ÿ����λ����������1, 4, 8��24 */
	long biCompression; /* ѹ������ */
	long biSizeImage; /* ʵ��ͼ���С��������4�ı��� */
	long biXPelsPerMeter; /* ˮƽ����ÿ�������� */
	long biYPelsPerMeter; /* ��ֱ����ÿ��������*/
	long biClrUsed; /* ������ɫ��*/
	long biClrImportant; /* ��Ҫ����ɫ�� */
} BITMAPINFOHEADER;

/*��ɫ��*/
typedef struct tagRGBQUAD
{
	unsigned char rgbBlue; /*��ɫ����*/
	unsigned char rgbGreen; /*��ɫ����*/
	unsigned char rgbRed; /*��ɫ����*/
	unsigned char rgbReserved; /*����*/
} RGBQUAD;
void Show_Bmpif(FILE* fp);
FILE* Copy_Bmp(FILE* fp);
void Write_String(FILE* fp, int x, int y);
void print(char ch);
void Print_Bmp(FILE* fp);
void Print_Bmp2(FILE* fp);
#else
#endif // !YJJY