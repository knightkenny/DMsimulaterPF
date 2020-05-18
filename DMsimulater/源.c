#include<stdio.h>
#include<time.h>
#include<stdlib.h>
struct DATA {
	char name[20];
	struct ability {
		int STR;//����
		int DEX;//����
		int CON;//����
		int INT;//����
		int WIS;//��֪
		int CHA;//����
	 };
	char alignment[12];//��Ӫ
	char race[10];//����
	int level;//�ȼ�
	char class[8];//ְҵ
	int HP;
	struct AC {
		int usual;//AC
		int touch;//�Ӵ�
		int unknow;//���ֲ���
	};
	int skillpoint;//���ܵ���

};
char AllAli[][9]={ {"��������"},{"��������"},{"����а��"},{"��������"},{"��������"},{"����а��"},{"��������"},{"��������"},{"����а��"} };
char AllClass[11][9] = { {"Ұ����"},{"����ʫ��"},{"��ʦ"},{"��³��"},{"սʿ"},{"��ɮ"},{"ʥ��ʿ"},{"����"},{"����"},{"��ʿ"},{"��ʦ"} };
int roll4d6h3() {
	int a, b, c, d, add=0,count=0, i = 6;
	a = rand() % 6 + 1;
	b = rand() % 6 + 1;
	c = rand() % 6 + 1;
	d = rand() % 6 + 1;
	for (; i > 0; i--) {
		if (a >= i) {
			add = add + a;
			a = a-100;
			count++;
			if (count == 3) {
				return add;
			}
		}
		if (b >= i) {
			add = add + b;
			b = -100;
			count++;			
			if (count == 3) {
				return add;
			}
		}
		if (c >= i) {
			add = add + c;
			c = -100;
			count++;
			if (count == 3) {
				return add;
			}
		}
		if (d >= i) {
			add = add + d;
			d = -100;
			count++;
			if (count == 3) {
				return add;
			}
		}
	}
}
void chooseAdd(struct DATA* a) {
	char get[2];
	puts("ѡ����Ҫ���ӵ����� 1.���� 2.���� 3.���� 4.���� 5.��֪ 6.����");
	scanf("%s", &get);
	switch (get[0]) {
	case'1':
		a->STR += 2;
		break;
	case'2':
		a->DEX += 2;
		break;
	case'3':
		a->CON += 2;
		break;
	case'4':
		a->INT += 2;
		break;
	case'5':
		a->WIS += 2;
		break;
	case'6':
		a->CHA += 2;
		break;
	}
	return;
}
void AutoAdd(struct DATA* a) {
	int get;
	get = rand() % 5 + 1;
	switch (get) {
	case 1:
		a->STR += 2;
		break;
	case 2 :
		a->DEX += 2;
		break;
	case 3 :
		a->CON += 2;
		break;
	case 4 :
		a->INT += 2;
		break;
	case 5 :
		a->WIS += 2;
		break;
	case 6 :
		a->CHA += 2;
		break;
	}
	return;
}
void preSet(struct DATA* a) {
	a->STR = 10;
	a->DEX = 10;
	a->CON = 10;
	a->INT = 10;
	a->WIS = 10;
	a->CHA = 10;
}
void showAbility(struct DATA* a) {
	printf("����%d\t����%d\t����%d\t����%d\t��֪%d\t����%d", a->STR, a->DEX, a->CON, a->INT, a->WIS, a->CHA);
}
int pay(int ability,int *point,int reduce) {
		if (reduce == -4) {
			ability = 7;
			return ability;
		}
		else if (reduce == -2) {
			ability = 8;
			return ability;
		}
		else if (reduce == -1) {
			ability = 9;
			return ability;
		}
		else if (reduce == 0) {
			ability = 10;
			return ability;
		}
		else if (reduce == 1) {
			ability = 11;
			return ability;
		}
		else if (reduce == 2) {
			ability = 12;
			return ability;
		}
		else if (reduce == 3) {
			ability = 13;
			return ability;
		}
		else if (reduce == 5) {
			ability = 14;
			return ability;
		}
		else if (reduce == 7) {
			ability = 15;
			return ability;
		}
		else if (reduce == 10) {
			ability = 16;
			return ability;
		}
		else if (reduce == 13) {
			ability = 17;
			return ability;
		}
		else if (reduce == 17) {
			ability = 18;
			return ability;
		}
		else {
			return ability;
		}
	}
void buyIT(struct DATA *a) {
	int point = 25,*Point,reduce,done=0;
	char get[2];
	Point = &point;
	puts("�����빺�������Ĭ��25");
	scanf("%d", &point);
	while (point != 0) {
		done = 0;
		printf("ʣ�๺����%d", point);
		showAbility(a);
		printf("\nbuytable\nԭʼ����  ���Ĺ���\n7\t�C4\n8\t�C2\n9\t�C1\n10\t 0\n11\t 1\n12\t 2\n13\t 3\n14\t 5\n15\t 7\n16\t 10\n17\t 13\n18\t 17\n���������ĵ���");
		scanf("%d", &reduce);
		while (done == 0){
			if (reduce <= point) {
				point = point - reduce;
				done = 1;
			}
			else {
				printf("\nbuytable\nԭʼ����  ���Ĺ���\n7\t�C4\n8\t�C2\n9\t�C1\n10\t 0\n11\t 1\n12\t 2\n13\t 3\n14\t 5\n15\t 7\n16\t 10\n17\t 13\n18\t 17\n���������ĵ���");
				scanf("%d", &reduce);
			}
		}
		puts("��ѡ����������1.����2.����3.����4.����5.��֪6.����");
		scanf("%s", get);
		switch (get[0]) {
		case'1':
			a->STR=pay(a->STR, Point, reduce);
			break;
		case'2':
			a->DEX = pay(a->DEX, Point, reduce);
			break;
		case'3':
			a->CON = pay(a->CON, Point, reduce);
			break;
		case'4':
			a->INT = pay(a->INT, Point, reduce);
			break;
		case'5':
			a->WIS = pay(a->WIS, Point, reduce);
			break;
		case'6':
			a->CHA = pay(a->CHA, Point, reduce);
			break;
		case'0':
			return;
		}
	}
}
void rollIT(struct DATA* p) {
	system("cls");
	int done = 0;
	while (done == 0) {
		p->STR  = roll4d6h3();
		p->DEX =  roll4d6h3();
		p->CON = roll4d6h3();
		p->INT =  roll4d6h3();
		p->WIS =  roll4d6h3();
		p->CHA = roll4d6h3();
		system("cls");
		showAbility(p);
		puts("\n�Ƿ���roll 0.�� 1.����\n");
		scanf("%d", &done);
	}
}
void AutoRollIT(struct DATA* p) {
		p->STR = roll4d6h3();
		p->DEX = roll4d6h3();
		p->CON = roll4d6h3();
		p->INT = roll4d6h3();
		p->WIS = roll4d6h3();
		p->CHA = roll4d6h3();
}
void GetAbilityTable(struct DATA* p) {
	system("cls");
	int a, b, c, d, e, f;
	char get[2];
	puts("ѡ�����ɽ�ɫ���Ե�ķ�ʽ 1.���� 2.4d6h3");
	scanf("%s", &get);
	switch (get[0]) {
	case '1':
		buyIT(p);
		break;
	case'2':
		rollIT(p);
		break;
	}
}
int addpoint(int num) {
	if (num > 10) {
		return (num - 10) / 2;
	}
	else {
		return -((10 - num) / 2);
	}
}
void getRace(struct DATA* p) {
	char a[2];
	puts("��ѡ����Ҫ������\n1.���� ��������+2 һ������ר��\n2.���� ����|��֪+2 ����-2\n3.���� ����|����+2 ����-2\n4.٪�� ����|���� +2 ���� -2\n5.�뾫�� ��������+2\n6.������ ����|����+2 ����-2\n7.������ ��������+2");
	scanf("%s", &a);
	switch (a[0]) {
	case '1':
		chooseAdd(p);
		strcpy(p->race, "����");
		break;
	case '2':
		strcpy(p->race, "����");
		p->CON += 2;
		p->WIS += 2;
		p->CHA -= 2;
		break;
	case '3':
		strcpy(p->race, "����");
		p->DEX += 2;
		p->INT += 2;
		p->CON -= 2;
		break;
	case '4':
		strcpy(p->race, "٪��");
		p->CON += 2;
		p->CHA += 2;
		p->STR -= 2;
		break;
	case '5':
		strcpy(p->race, "�뾫��");
		chooseAdd(p);
		break;
	case '6':
		strcpy(p->race, "������");
		p->DEX += 2;
		p->CHA += 2;
		p->STR -= 2;
		break;
	case '7':
		strcpy(p->race, "������");
		chooseAdd(p);
		break;
	}
}
void AutoGetRace(struct DATA* p) {
	int a;
	a = rand() % 7 + 1;
	switch (a) {
	case 1:
		AutoAdd(p);
		strcpy(p->race, "����");
		break;
	case 2:
		strcpy(p->race, "����");
		p->CON += 2;
		p->WIS += 2;
		p->CHA -= 2;
		break;
	case 3:
		strcpy(p->race, "����");
		p->DEX += 2;
		p->INT += 2;
		p->CON -= 2;
		break;
	case 4:
		strcpy(p->race, "٪��");
		p->CON += 2;
		p->CHA += 2;
		p->STR -= 2;
		break;
	case 5:
		strcpy(p->race, "�뾫��");
		AutoAdd(p);
		break;
	case 6:
		strcpy(p->race, "������");
		p->DEX += 2;
		p->CHA += 2;
		p->STR -= 2;
		break;
	case 7:
		strcpy(p->race, "������");
		AutoAdd(p);
		break;
	}
}
void getClass(struct DATA* p) {
	int i, get;
	puts("ѡ�����ְҵ ");
	for (i = 0; i < 11; i++) {
		printf("%d.%s", i, AllClass[i]);
	}
	scanf("%d", &get);
	strcpy(p->class, AllClass[get]);
}
void AutoGetClass(struct DATA* p) {
	int get;
	get = rand() % 11;
	strcpy(p->class, AllClass[get]);
}
void base(struct DATA* p) {
	int a = 0,level;
	puts("ѡ�������Ӫ 1.�������� 2.�������� 3.����а�� 4.�������� 5.�������� 6.����а�� 7.�������� 8.�������� 9.����а��\n");
	scanf("%d", &a);
	strcpy(p->alignment, AllAli[a - 1]);
	puts("\n�������ɫ�ĵȼ�\n");
	scanf("%d",&level);
	p->level = level;
	puts("\n�����ɫ����\n");
	char name[20];
	scanf("%s", &name);
	strcpy(p->name, name);
}
void Autobase(struct DATA* p) {
	int a = 0, level;
	puts("ѡ������������Ӫ 1.�������� 2.�������� 3.����а�� 4.�������� 5.�������� 6.����а�� 7.�������� 8.�������� 9.����а��\n");
	scanf("%d", &a);
	strcpy(p->alignment, AllAli[a - 1]);
	puts("\n���������ɫ�ĵȼ�\n");
	scanf("%d", &level);
	puts("\n�����ɫ����\n");
	char name[20];
	scanf("%s", &name);
}
int main1(void) {
	srand((unsigned)time(NULL));
	struct DATA *p,data;
	char a[2];
	p = &data;
	preSet(p);
	while (1) {
		system("cls");
		printf("��ӭʹ��pf��ɫ������������ѡ������Ҫ�ķ���\n1.�Զ����ɫ��\n2.�Զ�����npc\n����0�˳�\n");
		scanf("%s", &a);
		switch (a[0]) {
		case '1':
			base(p);
			GetAbilityTable(p);
			getRace(p);
			getClass(p);
			break;
		case '2':
			Autobase(p);
			AutoRollIT(p);
			AutoGetRace(p);
			AutoGetClass(p);
			break;
		case '0':
			return 0;
		}
	}
}