// yjjy_3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"yjjy_3.h"

int main()
{
	FILE* fp;
	if ((fp = fopen("k398a.bmp", "rb")) == NULL) {
		printf("file error!\n");
		exit(0);
	}


	return 0;
}

