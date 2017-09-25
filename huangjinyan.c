#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	//确定参赛人数
	int PersonNum;
	printf("请输入参赛人数：");
	scanf_s("%d", &PersonNum);
	//记录分数的数组
	int point[9999] = { 0 };
	//记录每个选手输入的数字
	int num[9999];
	//差值
	float substract[9999];
	//继续or退出
	int fuck;

	while (1) {
		int index_s;
		int index_b;
		int min = 10000;
		int max = 0;

		//数字存入num[]
		for (int i = 0; i < PersonNum; i++) {
			printf("请%d号选手输入数字：", i + 1);
			scanf_s("%d", &num[i]);
		}
		//定义并初始化黄金点
		float gold = 0.0;
		//求总和
		for (int j = 0; j < PersonNum; j++) {
			gold += num[j];
		}
		//算出黄金点
		gold = gold / PersonNum * 0.618;
		//计算差值，并存入数组substract[]中
		for (int k = 0; k < PersonNum; k++) {
			//fabs()取小数的绝对值
			substract[k] = fabs(num[k] - gold);
		}
		//找出最大差值对应的索引
		for (int m = 0; m < PersonNum; m++) {
			if (substract[m] >= max) {
				max = substract[m];
				index_b = m;
			}
		}
		//找出最小差值对应的索引
		for (int n = 0; n <PersonNum; n++) {
			if (substract[n] <= min) {
				min = substract[n];
				index_s = n;
			}
		}
		//差值最大的扣2分
		point[index_b] = point[index_b] - 2;
		//差值最小的加2分
		point[index_s] = point[index_s] + 2;

		//输出所有得分情况
		for (int a = 0; a < PersonNum; a++) {
			printf("%d号选手得分：%d", a + 1, point[a]);
		}

		//下一轮or退出
		printf("1-下一轮\n");
		printf("其他任意键退出");
		printf("你的选择是：");
		scanf_s("%d", &fuck);
		if (fuck == 1) {

		}
		else {
			int point_max = -10000;
			int point_index;
			for (int b = 0; b < PersonNum; b++) {
				if (point[b] >= point_max) {
					point_max = point[b];
					point_index = b;
				}
			}
			printf("恭喜%d号玩家获胜！！！", point_index);
			exit(0);
		}
	}
}