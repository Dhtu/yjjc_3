typedef unsigned char	byte;

/*�ļ�ͷ�ṹ*/
typedef struct tagBITMAPFILEHEADER
{
	int bfType; /* ͨ���� 'BM' �����������ƺ��ж�OS/2�ı�ʶ����ʲô����*/
	long   bfSize; /* �ļ���С�����ֽ�Ϊ��λ*/
	int bfReserved1; /*��������������Ϊ0*/
	int bfReserved2; /*��������������Ϊ0*/
	long bfOffBits; /*���ļ�ͷ��ʼ��ʵ�ʵ�ͼ������֮����ֽڵ�ƫ������
					��������Ƿǳ����õģ���Ϊλͼ��Ϣͷ�͵�ɫ��ĳ��Ȼ���ݲ�ͬ������仯��
					���������ƫ��ֵѸ�ٵĴ��ļ��ж�ȡ��λ���ݡ� */
} BITMAPFILEHEADER;

/*��Ϣͷ�ṹ*/
typedef struct tagBITMAPINFOHEADER
{
	long biSize; /* ��Ϣͷ��С */
	long biWidth; /* ͼ���� */
	long biHeight; /* ͼ��߶� */
	int biPlanes; /* ����Ϊ1 */
	int biBitCount; /* ÿ����λ����������1, 4, 8��24 */
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