typedef unsigned char	byte;
#define BUFFERSIZE 4096
#define OFFSIZE 0x0E

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
	char rgbBlue; /*��ɫ����*/
	char rgbGreen; /*��ɫ����*/
	char rgbRed; /*��ɫ����*/
	char rgbReserved; /*����*/
} RGBQUAD;