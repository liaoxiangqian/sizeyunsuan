#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	//ȷ����������
	int PersonNum;
	printf("���������������");
	scanf_s("%d", &PersonNum);
	//��¼����������
	int point[9999] = { 0 };
	//��¼ÿ��ѡ�����������
	int num[9999];
	//��ֵ
	float substract[9999];
	//����or�˳�
	int fuck;

	while (1) {
		int index_s;
		int index_b;
		int min = 10000;
		int max = 0;

		//���ִ���num[]
		for (int i = 0; i < PersonNum; i++) {
			printf("��%d��ѡ���������֣�", i + 1);
			scanf_s("%d", &num[i]);
		}
		//���岢��ʼ���ƽ��
		float gold = 0.0;
		//���ܺ�
		for (int j = 0; j < PersonNum; j++) {
			gold += num[j];
		}
		//����ƽ��
		gold = gold / PersonNum * 0.618;
		//�����ֵ������������substract[]��
		for (int k = 0; k < PersonNum; k++) {
			//fabs()ȡС���ľ���ֵ
			substract[k] = fabs(num[k] - gold);
		}
		//�ҳ�����ֵ��Ӧ������
		for (int m = 0; m < PersonNum; m++) {
			if (substract[m] >= max) {
				max = substract[m];
				index_b = m;
			}
		}
		//�ҳ���С��ֵ��Ӧ������
		for (int n = 0; n <PersonNum; n++) {
			if (substract[n] <= min) {
				min = substract[n];
				index_s = n;
			}
		}
		//��ֵ���Ŀ�2��
		point[index_b] = point[index_b] - 2;
		//��ֵ��С�ļ�2��
		point[index_s] = point[index_s] + 2;

		//������е÷����
		for (int a = 0; a < PersonNum; a++) {
			printf("%d��ѡ�ֵ÷֣�%d", a + 1, point[a]);
		}

		//��һ��or�˳�
		printf("1-��һ��\n");
		printf("����������˳�");
		printf("���ѡ���ǣ�");
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
			printf("��ϲ%d����һ�ʤ������", point_index);
			exit(0);
		}
	}
}