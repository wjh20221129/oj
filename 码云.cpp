#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct sugar
{
	double price;
	int count;
}SUGAR;

int main() {
	int n;
	int m, shengyu;
	double ret = 0;
	SUGAR buf[10], temp;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		scanf("%lf%d", &buf[i].price, &buf[i].count);
	}

	for (int i = 0; i < m; i++)  //对价格排序
	{
		for (int j = i + 1; j < m; j++) {
			if (buf[j].price < buf[i].price)
			{
				temp = buf[j];
				buf[j] = buf[i];
				buf[i] = temp;
			}
		}
	}

	for (int i = 0; i < m; i++) //购买
	{
		//	printf("%lf %d \n",buf[i].price,buf[i].count);
		if (n - buf[i].count >= 0)
		{
			ret += buf[i].price * buf[i].count;
			n -= buf[i].count;
		}
		else if (n != 0)
		{
			ret += buf[i].price * n;
			n -= n; //需要让需要购买的糖果数量为0
		}

	}
	printf("%.2lf", ret);

}
