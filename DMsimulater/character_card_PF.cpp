#include "character_card_PF.h"
#include"tools.h"
#include<fstream>
using namespace std;
string AllAli [9] = { {"守序善良"},{"守序中立"},{"守序邪恶"},{"中立善良"},{"绝对中立"},{"中立邪恶"},{"混乱善良"},{"混乱中立"},{"混乱邪恶"} };
string AllClass[11] = { {"野蛮人  "},{"吟游诗人"},{"牧师    "},{"德鲁伊  "},{"战士    "},{"武僧    "},{"圣骑士  "},{"游侠     "},{"盗贼    "},{"术士    "},{"法师    "} };
template <class T> T checkIn(T type) {
	T inTemp;
	cin >> inTemp;
	if (cin.good()) {
		return inTemp;
	}
	else {
		cin.clear();//将cin重新标记为正确，以达到重新输入的目的
		while (cin.get() != '\n')	//这里清空之前cin缓冲区的数据
			continue;
		cout << "输入有误，请重新输入";
		return checkIn(type);
	}
}

items::items() {
	value[0] = 0;
	value[1] = 0;
	value[2] = 0;
	weight = 0;
	itemname = "无";
}
equipment::equipment() {
	SA[0] = 0;
	SA[1] = 0;
	abilities = "无";
}
weapon::weapon() {
	dice[0] = 0;
	dice[1] = 0;
	dmg_type[0] = 0;
	dmg_type[1] = 0;
	dmg_type[2] = 0;
	criticalTimes[0] = 0;
	criticalTimes[1] = 0;
	criticalTimes[2] = 0;
}
armor::armor() {
	bouns = 0;
	max_dex_bouns = 0;
	check_penalty = 0;
	spell_failure_chance = 0;
	speed = 0;
}
void character_card_pf::AC(int type)
{
	switch (type) {
	case 0:
		armor = armors[0].bouns;
		shield = armors[1].bouns;
		if (DEX[1] > armors[0].max_dex_bouns) {
			DEX_mod = armors[0].max_dex_bouns;
		}
		else {
			DEX_mod = DEX[1];
		}
		all = 10 + armor + shield + DEX_mod + eb + defb + na + dogb + temporary;
		touch = 10 + DEX_mod + eb + defb + na + dogb + temporary;
		flat = 10 + armor + shield + eb + defb + na + temporary;
		return;
	case 1:
		armor = armors[0].bouns;
		shield = armors[1].bouns;
		if (DEX[1] > armors[0].max_dex_bouns) {
			DEX_mod = armors[0].max_dex_bouns;
		}
		else {
			DEX_mod = DEX[1];
		}
		eb = 0;
		defb = 0;
		na = 0;
		dogb = 0;
		temporary = 0;
		all = 10 + armor + shield + DEX_mod + eb + defb + na + dogb + temporary;
		touch = 10 + DEX_mod + eb + defb + na + dogb + temporary;
		flat = 10 + armor + shield + eb + defb + na + temporary;
		return;
	case 2:
		armor = armors[0].bouns;
		shield = armors[1].bouns;
		if (DEX[1] > armors[0].max_dex_bouns) {
			DEX_mod = armors[0].max_dex_bouns;
		}
		else {
			DEX_mod = DEX[1];
		}
		cout << "设置增强加值";
		eb = checkIn(0);
		cout << "设置偏斜加值";
		defb = checkIn(0);
		cout << "设置天生护甲加值";
		na = checkIn(0);
		cout << "设置闪避加值";
		dogb = checkIn(0);
		cout << "设置临时调整值";
		temporary = checkIn(0);
		all = 10 + armor + shield + DEX_mod + eb + defb + na + dogb + temporary;
		touch = 10 + DEX_mod + eb + defb + na + dogb + temporary;
		flat = 10 + armor + shield + eb + defb + na + temporary;
		return;
	}
}

void character_card_pf::AC_change_all()
{
	/*
	cout << "设置护甲加值";
	armor = checkIn(0);
	cout << "设置盾牌加值";
	shield = checkIn(0);
	cout << "设置敏捷调整值";
	DEX_mod = checkIn(0);
	*/
	cout << "设置增强加值";
	eb = checkIn(0);
	cout << "设置偏斜加值";
	defb = checkIn(0);
	cout << "设置天生护甲加值";
	na = checkIn(0);
	cout << "设置闪避加值";
	dogb = checkIn(0);
	cout << "设置临时调整值";
	temporary = checkIn(0);
	AC(0);
	return;
}

int character_card_pf::AC_get_all()
{
	system("cls");
	cout << "\n————AC总体————";
	cout << "\n总AC all:\t" << all << "\n接触AC touch:\t" << touch << "\n措手不及 flat:\t" << flat;
	cout << "\n————AC明细————";
	cout << "\n护甲加值 armor:\t\t"<<armor;
	cout << "\n盾牌加值 shield:\t"<<shield;
	cout << "\n敏捷调整值 DEX_mod:\t" << DEX_mod;
	cout << "\n增强加值 eb:\t\t"<<eb;
	cout << "\n偏斜加值 defb:\t\t"<<	defb;
	cout << "\n天生护甲加值 na:\t"<<na;
	cout << "\n闪避加值 dogb:\t\t"<<dogb;
	cout << "\n临时调整值 temporary:\t" << temporary;
	cout << endl;
	pause();
	return 0;
}

int character_card_pf::AC_find_one(int type)
{
	switch (type) {
	case 0:
		cout << "\n总AC all:\t" << all;
		pause();
		return all;
	case 1:
		cout << "\n接触AC touch:\t" << touch;
		pause();
		return touch;
	case 2:
		cout << "\n措手不及 flat:\t" << flat;
		pause();
		return flat;
	case 3:
		cout << "\n护甲加值 armor:\t\t" << armor;
		pause();
		return armor;
	case 4:
		cout << "\n盾牌加值 shield:\t" << shield;
		pause();
		return shield;
	case 5:
		pause();
		cout << "\n敏捷调整值 DEX_mod:\t" << DEX_mod;
		return DEX_mod;
	case 6:
		pause();
		cout << "\n增强加值 eb:\t\t" << eb;
		return eb;
	case 7:
		pause();
		cout << "\n偏斜加值 defb:\t\t" << defb;
		return defb;
	case 8:
		pause();
		cout << "\n天生护甲加值 na:\t" << na;
		return na;
	case 9:
		cout << "\n闪避加值 dogb:\t\t" << dogb;
		pause();
		return dogb;
	case 10:
		cout << "\n临时调整值 temporary:\t" << temporary;
		pause();
		return temporary;
	}
}

int character_card_pf::AC_find_one()
{
	cout << "\n————AC名词表————";
	cout << "\n总AC all\t\t0"<< "\n接触AC touch\t\t1"<< "\n措手不及 flat\t\t2";
	cout << "\n护甲加值 armor\t\t3";
	cout << "\n盾牌加值 shield\t\t4";
	cout << "\n敏捷调整值 DEX_mod\t5";
	cout << "\n增强加值 eb\t\t6";
	cout << "\n偏斜加值 defb\t\t7";
	cout << "\n天生护甲加值 na\t\t8";
	cout << "\n闪避加值 dogb\t\t9";
	cout << "\n临时调整值 temporary\t10";
	cout << "\n 输入你要查询的属性的对应数字\n";
	int type;
	type = checkIn(0);
	return AC_find_one(type);
}

int character_card_pf::AC_change_one()
{
	cout << "\n————AC名词表————";
	cout << "\n总AC all\t\t" << "接触AC touch\t\t" << "措手不及 flat\t\t";
	cout << "\n护甲加值 armor ";
	cout << "\n盾牌加值 shield ";
	cout << "\n敏捷调整值 DEX_mod";
	cout << "\n增强加值 eb\t\t6";
	cout << "\n偏斜加值 defb\t\t7";
	cout << "\n天生护甲加值 na\t\t8";
	cout << "\n闪避加值 dogb\t\t9";
	cout << "\n临时调整值 temporary\t10";
	cout << "\n 输入你要更改的属性的对应数字\n";
	int choice;
	choice = checkIn(0);
	switch (choice) {
	case 6:
		cout << "\n增强加值 eb:\t\t" << eb;
		if (confirm() == 1) {
			cout << "\n输入更改后的数值";
			eb = checkIn(0);
		}
		break;
	case 7:
		cout << "\n偏斜加值 defb:\t\t" << defb;
		if (confirm() == 1) {
			cout << "\n输入更改后的数值";
			defb = checkIn(0);
		}
		break;
	case 8:
		cout << "\n天生护甲加值 na:\t" << na;
		if (confirm() == 1) {
			cout << "\n输入更改后的数值";
			na = checkIn(0);
		}
		break;
	case 9:
		cout << "\n闪避加值 dogb:\t\t" << dogb;
		if (confirm() == 1) {
			cout << "\n输入更改后的数值";
			dogb = checkIn(0);
		}
		break;
	case 10:
		cout << "\n临时调整值 temporary:\t" << temporary;
		if (confirm() == 1) {
			cout << "\n输入更改后的数值";
			temporary = checkIn(0);
		}
		break;
	}
	cout << endl;
	system("pause");
	system("cls");
	AC(0);
	return 0;
}

void character_card_pf::ability_scores(int str , int dex , int con , int int_ , int wis , int cha )
{
	STR[0] = str;
	DEX[0] = dex;
	CON[0] = con;
	INT[0] = int_;
	WIS[0] = wis;
	CHA[0] = cha;
	ability_get_modifier();
}

void character_card_pf::ability_get_modifier()
{
	int temp = 0;//调整值
	temp = (STR[0] - 10) / 2;
	if (temp <= 0&&STR[0]%2==1&& STR[0]!=11)temp -= 1;
	STR[1] = temp;
	temp = (DEX[0] - 10) / 2;
	if (temp <= 0 && DEX[0] % 2 == 1 && DEX[0] != 11)temp -= 1;
	DEX[1] = temp;
	temp = (CON[0] - 10) / 2;
	if (temp <= 0 && CON[0] % 2 == 1 && CON[0] != 11)temp -= 1;
	CON[1] = temp;
	temp = (INT[0] - 10) / 2;
	if (temp <= 0 && INT[0] % 2 == 1 && INT[0] != 11)temp -= 1;
	INT[1] = temp;
	temp = (WIS[0] - 10) / 2;
	if (temp <= 0 && WIS[0] % 2 == 1 && WIS[0] != 11)temp -= 1;
	WIS[1] = temp;
	temp = (CHA[0] - 10) / 2;
	if (temp <= 0 && CHA[0] % 2 == 1 && CHA[0] != 11)temp -= 1;
	CHA[1]= temp;
}

int character_card_pf::ability_get_all()
{
	cout << "name\tnumber\tmodifier\n";
	cout << "属性名\t数值\t调整值\n";
	cout << "STR\t" << STR[0] << "\t" << STR[1]<<endl;
	cout << "DEX\t" << DEX[0] << "\t" << DEX[1] << endl;
	cout << "CON\t" << CON[0] << "\t" << CON[1] << endl;
	cout << "INT\t" << INT[0] << "\t" << INT[1] << endl;
	cout << "WIS\t" << WIS[0] << "\t" << WIS[1] << endl;
	cout << "CHA\t" << CHA[0] << "\t" << CHA[1] << endl;
	return 0;
}

int character_card_pf::ability_find_one(int type, int datatype)
{
	switch (datatype)
	{
	case 1:
		switch (type) {
		case 1:
			cout << STR[0];
			pause();
			return STR[0];
		case 2:
			cout << DEX[0];
			pause();
			return DEX[0];
		case 3:
			cout << CON[0];
			pause();
			return CON[0];
		case 4:
			cout << INT[0];
			pause();
			return INT[0];
		case 5:
			cout << WIS[0];
			pause();
			return WIS[0];
		case 6:
			cout << CHA[0];
			pause();
			return CHA[0];
		}
	case 2:
		switch (type)
		{
		case 1:
			cout << STR[1];
			pause();
			return STR[1];
		case 2:
			cout << DEX[1];
			pause();
			return DEX[1];
		case 3:
			cout << CON[1];
			pause();
			return CON[1];
		case 4:
			cout << INT[1];
			pause();
			return INT[1];
		case 5:
			cout << WIS[1];
			pause();
			return WIS[1];
		case 6:
			cout << CHA[1];
			pause();
			return CHA[1];
		}
	}
}

int character_card_pf::ability_find_one()
{
	system("cls");
	cout << "属性表\n1.str \n2.dex \n3.con \n4.int \n5.wis \n6.cha";
	int type = 0;
	do {
		cout << "\n输入你要搜索的属性(1~6)";
		type = checkIn(type);
	} while (type < 1 || type > 6);
system("cls");
cout << "1.原值 \n2.调整值";
int datatype=0;
do {
	cout << "\n输入你要查询的类型(1~2)";
	datatype = checkIn(datatype);
	} while (datatype < 1 || datatype > 2);
return ability_find_one(type, datatype);
}

void character_card_pf::ability_change_one(int type)
{

		switch (type) {
		case 1:
			STR[0]=checkIn(0);
			break;
		case 2:
			DEX[0] = checkIn(0);
			break;
		case 3:
			 CON[0] = checkIn(0);
			 break;
		case 4:
			INT[0] = checkIn(0);
			break;
		case 5:
			WIS[0] = checkIn(0);
			break;
		case 6:
			CHA[0] = checkIn(0);
			break;
		}
		check_character();
	return ;
}

void character_card_pf::buyIt()
{
	int point = 25, * Point, reduce=0, done = 0, get=0;
	Point = &point;
	cout<<"请输入购点点数，默认25"<<endl;
	point = checkIn(point);
	while (point != 0) {
		done = 0;
		ability_get_all();
		cout<<"\nbuytable\n原始属性  消耗购点\n7\t–4\n8\t–2\n9\t–1\n10\t 0\n11\t 1\n12\t 2\n13\t 3\n14\t 5\n15\t 7\n16\t 10\n17\t 13\n18\t 17\n"<< "剩余购点数" << point << endl<<"请输入消耗点数";
		reduce=checkIn(reduce);
		while (done == 0) {
			if (reduce <= point) {
				point = point - reduce;
				done = 1;
			}
			else {
				system("cls");
				ability_get_all();
				cout << "\nbuytable\n原始属性  消耗购点\n7\t–4\n8\t–2\n9\t–1\n10\t 0\n11\t 1\n12\t 2\n13\t 3\n14\t 5\n15\t 7\n16\t 10\n17\t 13\n18\t 17\n" << "剩余购点数" << point << endl << "请输入消耗点数";
				reduce = checkIn(reduce);
			}
		}
		cout<<"请选择所购属性1.力量2.敏捷3.体质4.智力5.感知6.魅力";
		get = checkIn(get);
		switch (get) {
		case 1:
			STR[0] = pay(STR[0], Point, reduce);
			break;
		case 2:
			DEX[0] = pay(DEX[0], Point, reduce);
			break;
		case 3:
			CON[0] = pay(CON[0], Point, reduce);
			break;
		case 4:
			INT[0] = pay(INT[0], Point, reduce);
			break;
		case 5:
			WIS[0] = pay(WIS[0], Point, reduce);
			break;
		case 6:
			CHA[0] = pay(CHA[0], Point, reduce);
			break;
		case 0:
			return;
		}
		check_character();
		system("cls");
	}
}

void character_card_pf::rollIt()
{
	system("cls");
	bool done = false;
	while (done == false) {
		STR[0] = rollxdyhz(4,6,3);
		cout << endl;
		DEX[0] = rollxdyhz(4, 6, 3);
		cout << endl;
		CON[0] = rollxdyhz(4, 6, 3);
		cout << endl;
		INT[0] = rollxdyhz(4, 6, 3);
		cout << endl;
		WIS[0] = rollxdyhz(4, 6, 3);
		cout << endl;
		CHA[0] = rollxdyhz(4, 6, 3);
		cout << endl;
		check_character();
		done = stopYes();
		system("cls");
	}
	system("cls");
	bool switchdone = false;
	int* p[6] = { &STR[0],&DEX[0],&CON[0],&INT[0] ,&WIS[0] ,&CHA[0] };
	int switchChoice[2] = { 7,7 };
	cout << "改变属性分配";
	switchdone = stopYes();
	while (switchdone==false) {
		switchChoice[0] = 7;
		switchChoice[1] = 7;
		ability_get_all();
		cout << "选择两个属性交换(从上到下为1-6)";
		while(switchChoice[0]>=7|| switchChoice[0] < 0)	switchChoice[0] = checkIn(1) - 1;
		cout << "输入成功" << endl;
		while (switchChoice[1] >= 7 || switchChoice[1] < 0)switchChoice[1] = checkIn(1) - 1;
		cout << "输入成功" << endl;
		switchit(p[switchChoice[0]], p[switchChoice[1]]);
		check_character();
		ability_get_all();
		switchdone = stopYes();
		system("cls");
	}
}

void character_card_pf::chooseRace() {
	cout<<"请选择你要的种族\n1.人类  \t任意属性+2\t一个额外专长\n2.矮人  \t体质|感知+2\t魅力-2\n3.精灵  \t敏捷|智力+2\t体质-2\n4.侏儒  \t体质|魅力 +2\t力量-2\n5.半精灵\t任意属性+2\n6.半身人\t敏捷|魅力+2\t力量-2\n7.半兽人\t任意属性+2"<<endl;
	int a = 0;
	a=checkIn(a);
	switch (a) {
	case 1:
		chooseAdd();
		race = "人类";
		break;
	case 2:
		race = "矮人";
		CON[0] += 2;
		WIS[0] += 2;
		CHA[0] -= 2;
		break;
	case 3:
		race = "精灵";
		DEX[0] += 2;
		INT[0] += 2;
		CON[0] -= 2;
		break;
	case 4:
		race = "侏儒";
		CON[0] += 2;
		CHA[0] += 2;
		STR[0] -= 2;
		break;
	case 5:
		race = "半精灵";
		chooseAdd();
		break;
	case 6:
		race = "半身人";
		DEX[0] += 2;
		CHA[0] += 2;
		STR[0] -= 2;
		break;
	case 7:
		race = "半兽人";
		chooseAdd();
		break;
	}
	check_character();
	ability_get_all();
}

void character_card_pf::chooseAdd() {
	cout<<"选择你要增加的属性 1.力量 2.敏捷 3.体质 4.智力 5.感知 6.魅力"<<endl;
	int get = 0;
	get=checkIn(get);
	switch (get) {
	case 1:
		STR[0] += 2;
		break;
	case 2:
		DEX[0] += 2;
		break;
	case 3:
		CON[0] += 2;
		break;
	case 4:
		INT[0] += 2;
		break;
	case 5:
		WIS[0] += 2;
		break;
	case 6:
		CHA[0] += 2;
		break;
	}
	return;
}

void character_card_pf::show_armor(int No)
{
	system("cls");
	cout << "物品名称  " << armors[No].itemname << "+" << armors[No].SA[0]
		<< "\t价值  " << armors[No].value[0] << " 金币 " << armors[No].value[1] << " 银币 " << armors[No].value[2] << " 铜币" << endl
		<< "重量\t" << armors[No].weight 
		<< "\t移动速度    " << armors[No].speed<<endl
		<< "护甲加值" << armors[No].bouns
		<< "\t护甲检定减值  " << armors[No].check_penalty
		<< "\t最大敏捷加值" << armors[No].max_dex_bouns << endl
		<< "额外能力：" << armors[No].abilities;
	system("pause");
}

int character_card_pf::change_armor(int No)
{
	cout << "物品名称  ";
	armors[No].itemname = checkIn(armors[No].itemname);
	cout << "加值  ";
	armors[No].SA[0] = checkIn(armors[No].SA[0]);
	cout << "等效加值";
	armors[No].SA[1] = checkIn(armors[No].SA[1]);
	cout << "价值\n"<< "金币  ";
	armors[No].value[0] = checkIn(armors[No].value[0]);
	cout << "银币  ";
	armors[No].value[1] = checkIn(armors[No].value[1]);
	cout << "铜币  ";
	armors[No].value[2] = checkIn(armors[No].value[2]);
	cout << "重量  ";
	armors[No].weight = checkIn(armors[No].weight);
	cout << "移动速度    ";
	armors[No].speed = checkIn(armors[No].speed);
	cout << "护甲加值";
	armors[No].bouns = checkIn(armors[No].bouns);
	cout << "护甲检定减值  ";
	armors[No].check_penalty = checkIn(armors[No].check_penalty);
	cout << "最大敏捷加值  "; 
	armors[No].max_dex_bouns = checkIn(armors[No].max_dex_bouns);
	cout << "额外能力";
	armors[No].abilities = checkIn(armors[No].abilities);
	return 0;
}

void character_card_pf::show_weapon(int No)
{
	cout << "物品名称  " << weapons[No].itemname << "+" << weapons[No].SA[0]
		<< "\t价值  " << weapons[No].value[0] << " 金币 " << weapons[No].value[1] << " 银币 " << weapons[No].value[2] << " 铜币" << endl
		<< "重量\t" << weapons[No].weight << endl
		<< "伤害\t" << weapons[No].dice[0] << "d" << weapons[No].dice[1] << "+" << weapons[No].SA[0] <<"   *"<< weapons[No].criticalTimes[0]
		<<"("<< weapons[No].criticalTimes[1]<<"~"<< weapons[No].criticalTimes[2] <<")"<< endl
		<< "额外能力：" << weapons[No].abilities<<endl
		<< "伤害类型\n0 表示无 1 表示有 \n穿刺\t钝击\t挥砍" << endl;
	for (int i = 0; i < 3; i++)	cout << weapons[No].dmg_type[i] << "\t";
}

int character_card_pf::change_weapon(int No)
{
	cout << "物品名称  ";
	weapons[No].itemname = checkIn(weapons[No].itemname);
	cout << "加值  ";
	weapons[No].SA[0] = checkIn(weapons[No].SA[0]);
	cout << "等效加值";
	weapons[No].SA[1] = checkIn(weapons[No].SA[1]);
	cout << "价值\n" << "金币  ";
	weapons[No].value[0] = checkIn(weapons[No].value[0]);
	cout << "银币  ";
	weapons[No].value[1] = checkIn(weapons[No].value[1]);
	cout << "铜币  ";
	weapons[No].value[2] = checkIn(weapons[No].value[2]);
	cout << "重量  ";
	weapons[No].weight = checkIn(weapons[No].weight);
	cout << "伤害骰子数  ";
	weapons[No].dice[0] = checkIn(1);
	cout << "伤害骰子点数  ";
	weapons[No].dice[1] = checkIn(1);
	cout << "暴击倍率";
	weapons[No].criticalTimes[0] = checkIn(1);
	cout << "暴击范围下限";
	weapons[No].criticalTimes[1] = checkIn(1);
	cout << "暴击范围上限";
	weapons[No].criticalTimes[2] = checkIn(1);
	cout<< "伤害类型\n0 表示无 1 表示有 \n穿刺\t钝击\t挥砍" << endl;
	for (int i = 0; i < 3; i++) weapons[No].dmg_type[i]=checkIn(0);
	cout << "额外能力";
	weapons[No].abilities = checkIn(weapons[No].abilities);
	return 0;
}

void character_card_pf::save_get_modifier()
{
	fortitude = CON[1] + CLASS[0].save_bouns[0] + CLASS[1].save_bouns[0] + CLASS[2].save_bouns[0];
	reflex=DEX[1]+ CLASS[0].save_bouns[1] + CLASS[1].save_bouns[1] + CLASS[2].save_bouns[1];
	will=WIS[1]+ CLASS[0].save_bouns[2] + CLASS[1].save_bouns[2] + CLASS[2].save_bouns[3];
}

character_card_pf::character_card_pf()
{
	name = "unknown";
	for (int i = 0; i < 10; i++)Feat[i] = "无";
	AC(1);
	ability_scores();
	check_character();
	return;
}

void character_card_pf::main_borad()
{
	if (name == "unknown") {
		int choice=-1;
		cout << "1.创建角色\n2.读取本地角色" << endl;
		while (choice != 1 && choice != 2)choice = checkIn(choice);
		switch (choice)
		{
		case 1:
			creat_character();
			break;
		case 2:
			string filename;
			filename = checkIn(filename);
			read_character(filename);
		}
		main_borad();
		return;
	}
	bool stop = false;
	bool substop;
	int Mchoice;
	int Inchoice;
	while(!stop){
		system("cls");
		substop = false;
		Mchoice = -1;
		cout << "\t\t" << name << "管理面板" << endl
			<< "1.基础数据管理\n2.AC管理\n3.属性值管理\n4.职业管理\n5.物品管理\n6.角色导出\n0.返回主程序";
		while(Mchoice<0||Mchoice>6)Mchoice = checkIn(1);
		switch (Mchoice) {
			system("cls");
		case 1://普通管理面板
			while(!substop){
				system("cls");
				cout << "基础数据管理界面" << endl
					<< "1.姓名\t" << name << "\t2.性别\t" << gender << endl
					<< "3.种族\t" << race << "\t4.阵营\t" << ali << endl
					<< "输入对应数字进行修改，输入0返回" << endl;
				string temp;
				Inchoice = -1;
				while (Inchoice < 0 || Inchoice>4)Inchoice = checkIn(Inchoice);
				switch (Inchoice) {
				case 1:
					cout << "输入姓名" << endl;
					temp = checkIn(temp);
					changeName(temp);
					break;
				case 2:
					cout << "输入性别" << endl;
					temp = checkIn(temp);
					changeGender(temp);
					break;
				case 3:
					cout << "输入种族（修改种族不会修改种族加值，请自行修改）" << endl;
					temp = checkIn(temp);
					changeRace(temp);
					break;
				case 4:
					cout << "输入阵营" << endl;
					temp = checkIn(temp);
					changeAli(temp);
					break;
				case 0:
					substop = stopYes();
					break;
				}
			}
			break;
		case 2://AC管理面板
			while (!substop) {
				system("cls");
				cout << "AC管理面板\n1.查看AC\n2.修改全部AC\n3.修改某项AC\n输入0返回"<<endl;
				Inchoice = -1;
				while (Inchoice < 0 || Inchoice>3)Inchoice = checkIn(Inchoice);
				switch (Inchoice) {
				case 1:
					AC_get_all();
					break;
				case 2:
					AC_change_all();
					break;
				case 3:
					AC_change_one();
					break;
				case 0:
					substop = stopYes();
					break;
				}
			}
			break;
		case 3://属性管理面板
			while (!substop) {
				system("cls");
				cout << "属性管理面板\n1.查看所有属性\n2.修改所有属性\n3.修改某项属性输入\n输入0返回";
				Inchoice = -1;
				int temp = -1;
				while (Inchoice < 0 || Inchoice>3)Inchoice = checkIn(Inchoice);
				switch (Inchoice)
				{
				case 1:
					ability_get_all();
					break;
				case 2:
					cout << "输入STR"<<endl;
					ability_change_one(1);
					cout << "输入DEX" << endl;
					ability_change_one(1);
					cout << "输入CON" << endl;
					ability_change_one(1);
					cout << "输入INT" << endl;
					ability_change_one(1);
					cout << "输入WIS" << endl;
					ability_change_one(1);
					cout << "输入CHA" << endl;
					ability_change_one(1);
					break;
				case 3:
					cout << "输入你要修改的属性编号" << endl;
					cout << "1.STR\t"<<endl;
					cout << "2.DEX\t"<< endl;
					cout << "3.CON\t"<< endl;
					cout << "4.INT\t" << endl;
					cout << "5.WIS\t"<< endl;
					cout << "6.CHA\t"  << endl;
					temp = checkIn(1);
					break;
				case 0:
					substop = stopYes();
					break;
				}
			}
			break;
		case 4://职业管理面板
			while (!substop) {
				system("cls");
				int temp = -1;
				Inchoice = -1;
				cout << "职业管理面板\n1.展示所有职业信息\n2.展示特定职业信息\n3.添加新职业\n4.修改职业信息\n5.删除职业\n输入0退出" << endl;
				while (Inchoice < 0 || Inchoice>5)Inchoice = checkIn(Inchoice);
				switch (Inchoice) {
				case 1:
					show_class();
					break;
				case 2:
					cout << "输入你要查看的职业序号" << endl;
					for (int i = 0; i < 3; i++)if (CLASS[i].class_name != "无")cout << i+1 << ". " << CLASS[i].class_name;
					temp = checkIn(1);
					show_class(temp);
					break;
				case 3:
					add_class();
					break;
				case 4:
					cout << "输入你要更改的职业序号" << endl;
					for (int i = 0; i < 3; i++)if (CLASS[i].class_name != "无")cout << i+1 << ". " << CLASS[i].class_name;
					temp = checkIn(1);
					alter_class(temp);
					break;
				case 5:
					cout << "输入你要删除的职业序号" << endl;
					for (int i = 0; i < 3; i++)if (CLASS[i].class_name != "无")cout << i+1 << ". " << CLASS[i].class_name;
					temp = checkIn(1);
					del_class(temp);
					break;
				case 0:
					substop = stopYes();
					break;
				}
			}
			break;
		case 5://物品管理面板
			while (!substop) {
				system("cls");
				int temp = -1;
				Inchoice = -1;
				int Itemchoice = -1;
				cout << "物品管理面板\n1.护甲相关\n2.武器相关\n3.道具相关\n输入0退出"<<endl;
				while (Inchoice < 0 || Inchoice>3)Inchoice = checkIn(Inchoice);
				switch (Inchoice) {
				case 1:
					cout << "1.查看护甲 2.修改护甲 3.删除护甲";
					while (Itemchoice < 0 || Itemchoice>3)Itemchoice = checkIn(1);
						switch (Itemchoice) {
							cout << "1.护甲\t2.盾牌\n请输入你要操作的对象" << endl;
							while (temp < 0 || temp>2)temp = checkIn(temp);
						case 1:
							show_armor(temp);
							break;
						case 2:
							change_armor(temp);
							break;
						case 3:
							armors[temp].itemname = "无";
					}
						break;
				}
			}
			break;
		case 6:
			save_character();
			break;
		case 0:
			stop = stopYes();
			break;
		}
		
	}
	return;
}

void character_card_pf::creat_character()
{
	system("cls");
	cout << "新建角色开始" << endl
		<< "选择属性获取方式"<<endl<<"1.购点 2.roll点"<<endl;
	int choice = checkIn(1);
	switch (choice) {
	case 1:
		buyIt();
		break;
	case 2:
		rollIt();
		break;
	}
	cout << "输入名字"<<endl;
	name = checkIn(name);
	cout << "输入性别"<<endl;
	gender = checkIn(gender);
	cout << "输入阵营" << endl;
	ali = checkIn(ali);
	cout << "选择种族" << endl;
	chooseRace();
	cout << endl;
	add_class();
	bool done = false;
	int i = 0;
	while (done==false) {
		cout << "输入专长名" << endl;
		Feat[i] = checkIn(Feat[0]);
		done = stopYes();
	}
	cout << "输入护甲数据" << endl;
	change_armor(0);
	cout << "输入武器数据" << endl;
	change_weapon(0);
}

void character_card_pf::Rcreat_character()
{

}

void character_card_pf::read_character(string filename)
{
	ifstream pin;
	pin.open(filename);
	if (!pin.is_open()) {
		cout << "打开失败";
		bool stop;
		stop = stopYes();
		if (!stop) {
			cout << "输入文件名" << endl;
			filename = checkIn(filename);
			read_character(filename);
		}
		return;
	}
	pin >> name >> ali >> race >> gender >> level;
	for (int i = 0; i < 3; i++) {
		pin >> CLASS[i].class_name >> CLASS[i].level >> CLASS[i].class_BAB >> CLASS[i].save_bouns[0] >> CLASS[i].save_bouns[1] >> CLASS[i].save_bouns[2]
			>> CLASS[i].HPD >> CLASS[i].HP >> CLASS[i].skill_point;
		for (int j = 0; j < 9; j++) pin >> CLASS[i].magics[0][j];
	}
	pin >> hp;
		for (int i = 0; i < 10; i++)pin >> Feat[i];
		for (int j = 0; j < 2; j++) {
			pin >> STR[j];
		}
		for (int j = 0; j < 2; j++) {
			pin >> DEX[j];
		}
		for (int j = 0; j < 2; j++) {
			pin >> CON[j];
		}
		for (int j = 0; j < 2; j++) {
			pin >> INT[j];
		}		
		for (int j = 0; j < 2; j++) {
			pin >> WIS[j];
		}
		for (int j = 0; j < 2; j++) {
			pin >> CHA[j];
		}
		pin >> fortitude >> reflex >> will;
		pin >> eb >> defb >> na >> dogb >> temporary;
		for (int i = 0; i < 2;i++) {
			pin >> armors[i].itemname;
			for (int k = 0; k < 3; k++)pin >> armors[i].value[k];
			pin >> armors[i].weight >> armors[i].SA[0] >> armors[i].SA[1]
				>> armors[i].abilities >> armors[i].bouns >> armors[i].max_dex_bouns
				>> armors[i].check_penalty >> armors[i].spell_failure_chance
				>> armors[i].speed;
		}
		for (int i = 0; i < 3; i++) {
			pin >> weapons[i].itemname;
			for (int k = 0; k < 3; k++)pin >> weapons[i].value[k];
			pin >> weapons[i].weight >> weapons[i].SA[0] >> weapons[i].SA[1]
				>> weapons[i].abilities;
			for (int j = 0; j < 2; j++)pin >> weapons[i].dice[j];
			for (int j = 0; j < 3; j++)pin >> weapons[i].criticalTimes[j];
			for (int j = 0; j < 3; j++)pin >> weapons[i].dmg_type[j];
		}
		AC(0);

		pin.close();
}

void character_card_pf::check_character()
{
	AC(0);
	hp = CLASS[0].HP + CLASS[1].HP + CLASS[2].HP;
	ability_get_modifier();
	save_get_modifier();
}

void character_card_pf::save_character(int type)
{
	ofstream pout;
	string filename;
	filename = checkIn(filename);
	pout.open(filename);
	switch (type) {
	case 1:
		if (!pout.is_open()) {
			cout << "打开失败";
			return;
		}
		pout << name<<" "<< ali << " " << race << " " << gender << " " << level << " ";
		for (int i = 0; i < 3; i++) {
			pout << CLASS[i].class_name << " " << CLASS[i].level << " " << CLASS[i].class_BAB << " " << CLASS[i].save_bouns[0] << " " << CLASS[i].save_bouns[1] << " " << CLASS[i].save_bouns[2] << " "
				<< CLASS[i].HPD << " " << CLASS[i].HP << " " << CLASS[i].skill_point << " ";
			for (int j = 0; j < 9; j++) pout << CLASS[i].magics[0][j] << " ";
		}
		pout << hp << " ";
		for (int i = 0; i < 10; i++)pout << Feat[i] << " ";
		for (int j = 0; j < 2; j++) {
			pout << STR[j] << " ";
		}
		for (int j = 0; j < 2; j++) {
			pout << DEX[j] << " ";
		}
		for (int j = 0; j < 2; j++) {
			pout << CON[j] << " ";
		}
		for (int j = 0; j < 2; j++) {
			pout << INT[j] << " ";
		}
		for (int j = 0; j < 2; j++) {
			pout << WIS[j] << " ";
		}
		for (int j = 0; j < 2; j++) {
			pout << CHA[j] << " ";
		}
		pout << fortitude << " " << reflex << " " << will << " ";
		pout << eb << " " << defb << " " << na << " " << dogb << " " << temporary << " ";
		for (int i = 0; i < 2; i++) {
			pout << armors[i].itemname << " ";
			for (int k = 0; k < 3; k++)pout << armors[i].value[k] << " ";
			pout << armors[i].weight << " " << armors[i].SA[0] << " " << armors[i].SA[1] << " "
				<< armors[i].abilities << " " << armors[i].bouns << " " << armors[i].max_dex_bouns << " "
				<< armors[i].check_penalty << " " << armors[i].spell_failure_chance << " "
				<< armors[i].speed << " ";
		}
		for (int i = 0; i < 3; i++) {
			pout << weapons[i].itemname << " ";
			for (int k = 0; k < 3; k++)pout << weapons[i].value[k] << " ";
			pout << weapons[i].weight << " " << weapons[i].SA[0] << " " << weapons[i].SA[1] << " "
				<< weapons[i].abilities << " ";
			for (int j = 0; j < 2; j++)pout << weapons[i].dice[j] << " ";
			for (int j = 0; j < 3; j++)pout << weapons[i].criticalTimes[j] << " ";
			for (int j = 0; j < 3; j++)pout << weapons[i].dmg_type[j] << " ";
		}

		break;
	}
	
}

string character_card_pf::getName()
{
	return name;
}

void character_card_pf::changeName(string newName)
{
	name = newName;
}

string character_card_pf::getGender()
{
	return gender;
}

void character_card_pf::changeGender(string newGender)
{
	gender = newGender;
}

string character_card_pf::getRace()
{
	return race;
}

void character_card_pf::changeRace(string newRace)
{
	race = newRace;
}

string character_card_pf::getAli()
{
	return ali;
}

void character_card_pf::changeAli(string newAli)
{
	ali = newAli;
}

void character_card_pf::add_class()
{
	int i = 0;
	while(1){
		if (CLASS[i].level == 0) {
			cout << "选择职业" << endl;
			for (int j = 0; j < 11; j++) {
				if (j % 3 == 0) cout << endl;
				cout <<j<<"."<< AllClass[j] << "\t";
			}
			int choice = 0;
			choice = checkIn(choice);
			CLASS[i].class_name = AllClass[choice];
			cout << "\n输入新职业等级：";
			CLASS[i].level = checkIn(1);
			cout << "\n输入新职业BAB";
			CLASS[i].class_BAB = checkIn(1);
			cout << "\n输入新职业豁免加值(强韧 反射 意志)";
			CLASS[i].save_bouns[0] = checkIn(1);
			CLASS[i].save_bouns[1] = checkIn(1);
			CLASS[i].save_bouns[2] = checkIn(1);
			cout << "\n输入新职业生命骰大小";
			CLASS[i].HPD = checkIn(1);
			cout << "\n输入新职业提供的生命点数(不计算体质调整)";
			CLASS[i].HP = checkIn(1);
			cout << "\n输入新职业技能点(不计算智力调整)";
			CLASS[i].skill_point = checkIn(1);
			cout << "\n输入新职业最高施法能力环数";
			int spell_level = 0;
			spell_level = checkIn(spell_level);
			for (int j = 0; j <= spell_level; j++) {
				cout << "请输入" << j << "环法术每日释放次数";
				CLASS[i].magics[0][j] = checkIn(0);
			}
			system("cls");
			cout << "创建职业成功\n";
			system("pause");
			system("cls");
			return;
		}
		else {
			i++;
		}
		if (i == 4)return;
	}
}

void character_card_pf::show_class(int i)
{
	if (i == 4) {
			for (int j = 0; j < 3; j++)if (CLASS[j].level != 0) {
			cout << "———————第" << j + 1 << "职业———————" << endl
				<< "职业名  " << CLASS[j].class_name << "\t等级  " << CLASS[j].level << endl
				<< "生命骰  d" << CLASS[j].HPD << "\t" << "HP    " << CLASS[j].HP << endl
				<< "BAB  " << CLASS[j].class_BAB<<endl
				<< "豁免 \n强韧\t反射\t意志\n";
			for (int k = 0; k < 3; k++)cout << CLASS[j].save_bouns[k] << "\t";
			cout << endl
				<< "技能点  " << CLASS[j].skill_point<<endl;
			for(int k=0;k<=9;k++)
				if (CLASS[j].magics[0][k] != 0) {
					cout << k << "环法术\t可释放次数" << CLASS[j].magics[0][k] << "\t剩余次数"<< CLASS[j].magics[1][k] <<endl;
				}
		}
		else { j++; }
	}
	else {
		int j = i-1;
			cout<< "职业名  " << CLASS[j].class_name << "\t等级  " << CLASS[j].level << endl
			<< "生命骰  d" << CLASS[j].HPD << "\t" << "HP    " << CLASS[j].HP << endl
			<< "豁免 \n强韧\t反射\t意志\n";
		for (int k = 0; k < 3; k++)cout << CLASS[j].save_bouns[k] << "\t";
		cout << endl
			<< "技能点  " << CLASS[j].skill_point << endl;
		for (int k = 0; k < 9; k++)
			if (CLASS[j].magics[0][k] != 0) {
				cout << k << "环法术\t可释放次数" << CLASS[j].magics[0][k] << "\t剩余次数" << CLASS[j].magics[1][k] << endl;
			}
	}
	pause();
}

void character_card_pf::alter_class()
{
	show_class();
	int choice = 5;
	while (!(choice >= 1 && choice<=3)) {
		cout << "你想修改哪一个职业(1/2/3)  ";
		choice = checkIn(1);
	}
	choice--;
	alter_class(choice);
}

void character_card_pf::alter_class(int classId)
{
	if (CLASS[classId].level==0)return add_class();
	cout << "职业名  " << CLASS[classId].class_name<<endl;
	if (changeYes())CLASS[classId].class_name=checkIn(CLASS[classId].class_name);
	cout << "等级  " << CLASS[classId].level << endl;
	if (changeYes())CLASS[classId].level = checkIn(1);
	cout << "BAB  " << CLASS[classId].class_BAB << endl;
	if (changeYes())CLASS[classId].class_BAB = checkIn(1);
	cout << "生命骰  d" << CLASS[classId].HPD<<endl;
	if (changeYes())CLASS[classId].HPD = checkIn(1);
	cout << "HP    " << CLASS[classId].HP << endl;
	if (changeYes())CLASS[classId].HP = checkIn(1);
	cout << "豁免 \n强韧\t反射\t意志" << endl;
	for (int k = 0; k < 3; k++) { cout << CLASS[classId].save_bouns[k] << "\t";
	if (changeYes())CLASS[classId].save_bouns[k] = checkIn(1);
	}
	cout << "技能点  " << CLASS[classId].skill_point << endl;
	if (changeYes())CLASS[classId].skill_point = checkIn(1);
	for (int k = 0; k < 9; k++)
		if (CLASS[classId].magics[0][k] != 0) {
			cout << k << "环法术\t可释放次数" << CLASS[classId].magics[0][k] << "\t剩余次数" << CLASS[classId].magics[1][k] << endl;
		}
	if (changeYes()) {
		cout << "\n输入修改后最高施法能力环数";
		int spell_level = 0;
		spell_level = checkIn(spell_level);
		int j = 0;
		for (; j <= spell_level; j++) {
			cout << "请输入" << j << "环法术每日释放次数";
			CLASS[classId].magics[0][j] = checkIn(0);
		}
		for (; j <= 9; j++)CLASS[classId].magics[0][j] = 0;
	}
}

void character_card_pf::del_class()
{
	show_class();
	int choice = 5;
	while (!(choice >= 1 && choice <= 3)) {
		cout << "你想删除哪一个职业(1/2/3)  ";
		choice = checkIn(1);
	}
	choice--;
	del_class(choice);
}

void character_card_pf::del_class(int classId)
{
	CLASS[classId].level = 0;
}

void character_card_pf::reset_spell()
{
	for(int i=0;i<3;i++){
		for(int j=0;j<10;j++){
			CLASS[i].magics[1][j] = CLASS[i].magics[0][j];
		}
	}
}

class_mod::class_mod()
{
	class_name="无";//职业名称
	level = 0;//等级
	class_BAB = 0;//基础攻击加值
	for (int i = 0; i < 3; i++)save_bouns[i] = 0;
	HPD = 0;//生命骰大小
	HP = 0;//生命值
	skill_point = 0;//技能点
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 10; j++)
			magics[i][j] = 0;//魔法使用次数
}
