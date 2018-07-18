typedef unsigned char	byte;

/*文件头结构*/
typedef struct tagBITMAPFILEHEADER
{
	int bfType; /* 通常是 'BM' 。现在来看似乎判断OS/2的标识已无什么意义*/
	long   bfSize; /* 文件大小，以字节为单位*/
	int bfReserved1; /*保留，必须设置为0*/
	int bfReserved2; /*保留，必须设置为0*/
	long bfOffBits; /*从文件头开始到实际的图象数据之间的字节的偏移量。
					这个参数是非常有用的，因为位图信息头和调色板的长度会根据不同情况而变化，
					可以用这个偏移值迅速的从文件中读取到位数据。 */
} BITMAPFILEHEADER;

/*信息头结构*/
typedef struct tagBITMAPINFOHEADER
{
	long biSize; /* 信息头大小 */
	long biWidth; /* 图像宽度 */
	long biHeight; /* 图像高度 */
	int biPlanes; /* 必须为1 */
	int biBitCount; /* 每像素位数，必须是1, 4, 8或24 */
	long biCompression; /* 压缩方法 */
	long biSizeImage; /* 实际图像大小，必须是4的倍数 */
	long biXPelsPerMeter; /* 水平方向每米像素数 */
	long biYPelsPerMeter; /* 垂直方向每米像素数*/
	long biClrUsed; /* 所用颜色数*/
	long biClrImportant; /* 重要的颜色数 */
} BITMAPINFOHEADER;

/*调色板*/
typedef struct tagRGBQUAD
{
	char rgbBlue; /*蓝色分量*/
	char rgbGreen; /*绿色分量*/
	char rgbRed; /*红色分量*/
	char rgbReserved; /*保留*/
} RGBQUAD;