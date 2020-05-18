#include<stdio.h>
#include<time.h>
#include<stdlib.h>
struct DATA {
	char name[20];
	struct ability {
		int STR;//力量
		int DEX;//敏捷
		int CON;//体质
		int INT;//智力
		int WIS;//感知
		int CHA;//魅力
	 };
	char alignment[12];//阵营
	char race[10];//种族
	int level;//等级
	char class[8];//职业
	int HP;
	struct AC {
		int usual;//AC
		int touch;//接触
		int unknow;//措手不及
	};
	int skillpoint;//技能点数

};
char AllAli[][9]={ {"守序善良"},{"守序中立"},{"守序邪恶"},{"中立善良"},{"绝对中立"},{"中立邪恶"},{"混乱善良"},{"混乱中立"},{"混乱邪恶"} };
char AllClass[11][9] = { {"野蛮人"},{"吟游诗人"},{"牧师"},{"德鲁伊"},{"战士"},{"武僧"},{"圣骑士"},{"游侠"},{"盗贼"},{"术士"},{"法师"} };
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
	puts("选择你要增加的属性 1.力量 2.敏捷 3.体质 4.智力 5.感知 6.魅力");
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
	printf("力量%d\t敏捷%d\t体质%d\t智力%d\t感知%d\t魅力%d", a->STR, a->DEX, a->CON, a->INT, a->WIS, a->CHA);
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
	puts("请输入购点点数，默认25");
	scanf("%d", &point);
	while (point != 0) {
		done = 0;
		printf("剩余购点数%d", point);
		showAbility(a);
		printf("\nbuytable\n原始属性  消耗购点\n7\t–4\n8\t–2\n9\t–1\n10\t 0\n11\t 1\n12\t 2\n13\t 3\n14\t 5\n15\t 7\n16\t 10\n17\t 13\n18\t 17\n请输入消耗点数");
		scanf("%d", &reduce);
		while (done == 0){
			if (reduce <= point) {
				point = point - reduce;
				done = 1;
			}
			else {
				printf("\nbuytable\n原始属性  消耗购点\n7\t–4\n8\t–2\n9\t–1\n10\t 0\n11\t 1\n12\t 2\n13\t 3\n14\t 5\n15\t 7\n16\t 10\n17\t 13\n18\t 17\n请输入消耗点数");
				scanf("%d", &reduce);
			}
		}
		puts("请选择所购属性1.力量2.敏捷3.体质4.智力5.感知6.魅力");
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
		puts("\n是否重roll 0.是 1.结束\n");
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
	puts("选择生成角色属性点的方式 1.购点 2.4d6h3");
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
	puts("请选择你要的种族\n1.人类 任意属性+2 一个额外专长\n2.矮人 体质|感知+2 魅力-2\n3.精灵 敏捷|智力+2 体质-2\n4.侏儒 体质|魅力 +2 力量 -2\n5.半精灵 任意属性+2\n6.半身人 敏捷|魅力+2 力量-2\n7.半兽人 任意属性+2");
	scanf("%s", &a);
	switch (a[0]) {
	case '1':
		chooseAdd(p);
		strcpy(p->race, "人类");
		break;
	case '2':
		strcpy(p->race, "矮人");
		p->CON += 2;
		p->WIS += 2;
		p->CHA -= 2;
		break;
	case '3':
		strcpy(p->race, "精灵");
		p->DEX += 2;
		p->INT += 2;
		p->CON -= 2;
		break;
	case '4':
		strcpy(p->race, "侏儒");
		p->CON += 2;
		p->CHA += 2;
		p->STR -= 2;
		break;
	case '5':
		strcpy(p->race, "半精灵");
		chooseAdd(p);
		break;
	case '6':
		strcpy(p->race, "半身人");
		p->DEX += 2;
		p->CHA += 2;
		p->STR -= 2;
		break;
	case '7':
		strcpy(p->race, "半兽人");
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
		strcpy(p->race, "人类");
		break;
	case 2:
		strcpy(p->race, "矮人");
		p->CON += 2;
		p->WIS += 2;
		p->CHA -= 2;
		break;
	case 3:
		strcpy(p->race, "精灵");
		p->DEX += 2;
		p->INT += 2;
		p->CON -= 2;
		break;
	case 4:
		strcpy(p->race, "侏儒");
		p->CON += 2;
		p->CHA += 2;
		p->STR -= 2;
		break;
	case 5:
		strcpy(p->race, "半精灵");
		AutoAdd(p);
		break;
	case 6:
		strcpy(p->race, "半身人");
		p->DEX += 2;
		p->CHA += 2;
		p->STR -= 2;
		break;
	case 7:
		strcpy(p->race, "半兽人");
		AutoAdd(p);
		break;
	}
}
void getClass(struct DATA* p) {
	int i, get;
	puts("选择你的职业 ");
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
	puts("选择你的阵营 1.守序善良 2.守序中立 3.守序邪恶 4.中立善良 5.绝对中立 6.中立邪恶 7.混乱善良 8.混乱中立 9.混乱邪恶\n");
	scanf("%d", &a);
	strcpy(p->alignment, AllAli[a - 1]);
	puts("\n输入你角色的等级\n");
	scanf("%d",&level);
	p->level = level;
	puts("\n输入角色名字\n");
	char name[20];
	scanf("%s", &name);
	strcpy(p->name, name);
}
void Autobase(struct DATA* p) {
	int a = 0, level;
	puts("选择随机人物的阵营 1.守序善良 2.守序中立 3.守序邪恶 4.中立善良 5.绝对中立 6.中立邪恶 7.混乱善良 8.混乱中立 9.混乱邪恶\n");
	scanf("%d", &a);
	strcpy(p->alignment, AllAli[a - 1]);
	puts("\n输入随机角色的等级\n");
	scanf("%d", &level);
	puts("\n输入角色名字\n");
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
		printf("欢迎使用pf角色卡制作器，请选择你想要的服务\n1.自定义角色卡\n2.自动生成npc\n输入0退出\n");
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