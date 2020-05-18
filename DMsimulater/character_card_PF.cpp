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
}
equipment::equipment() {
	SA[0] = 0;
	SA[1] = 0;
}
weapon::weapon() {
	dice[0] = 0;
	dice[1] = 0;
	dmg_type[0] = 0;
	dmg_type[1] = 0;
	dmg_type[2] = 0;
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
	cout << "设置护甲加值";
	armor = checkIn(0);
	cout << "设置盾牌加值";
	shield = checkIn(0);
	cout << "设置敏捷调整值";
	DEX_mod = checkIn(0);
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
	system("pause");
	system("cls");
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
	all = 10 + armor + shield + DEX_mod + eb + defb + na + dogb + temporary;
	touch = 10 + DEX_mod + eb + defb + na + dogb + temporary;
	flat = 10 + armor + shield + eb + defb + na + temporary;
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
	int done = 0;
	while (done == 0) {
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
		pause();
		check_character();
		ability_get_all();
		cout<<"\n是否重roll 0.是 1.结束\n";
		done = checkIn(done);
	}
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
		<< "伤害\t" << weapons[No].dice[0] << "d" << weapons[No].dice[1] << "+" << weapons[No].SA[0] << endl
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
	cout<< "伤害类型\n0 表示无 1 表示有 \n穿刺\t钝击\t挥砍" << endl;
	for (int i = 0; i < 3; i++) weapons[No].dmg_type[i]=checkIn(0);
	pause();
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
	AC(1);
	return;
}

void character_card_pf::creat_character()
{
	

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
		AC(0);
}

void character_card_pf::check_character()
{
	AC(0);
	hp = CLASS[0].HP + CLASS[1].HP + CLASS[2].HP;
	ability_get_modifier();
	save_get_modifier();
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
			cout << "创建成功\n";
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
			for(int k=0;k<9;k++)
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

