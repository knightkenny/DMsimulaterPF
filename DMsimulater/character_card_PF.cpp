#include "character_card_PF.h"
#include"tools.h"
#include<fstream>
using namespace std;
string AllAli [9] = { {"��������"},{"��������"},{"����а��"},{"��������"},{"��������"},{"����а��"},{"��������"},{"��������"},{"����а��"} };
string AllClass[11] = { {"Ұ����  "},{"����ʫ��"},{"��ʦ    "},{"��³��  "},{"սʿ    "},{"��ɮ    "},{"ʥ��ʿ  "},{"����     "},{"����    "},{"��ʿ    "},{"��ʦ    "} };
template <class T> T checkIn(T type) {
	T inTemp;
	cin >> inTemp;
	if (cin.good()) {
		return inTemp;
	}
	else {
		cin.clear();//��cin���±��Ϊ��ȷ���Դﵽ���������Ŀ��
		while (cin.get() != '\n')	//�������֮ǰcin������������
			continue;
		cout << "������������������";
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
		cout << "������ǿ��ֵ";
		eb = checkIn(0);
		cout << "����ƫб��ֵ";
		defb = checkIn(0);
		cout << "�����������׼�ֵ";
		na = checkIn(0);
		cout << "�������ܼ�ֵ";
		dogb = checkIn(0);
		cout << "������ʱ����ֵ";
		temporary = checkIn(0);
		all = 10 + armor + shield + DEX_mod + eb + defb + na + dogb + temporary;
		touch = 10 + DEX_mod + eb + defb + na + dogb + temporary;
		flat = 10 + armor + shield + eb + defb + na + temporary;
		return;
	}
}

void character_card_pf::AC_change_all()
{
	cout << "���û��׼�ֵ";
	armor = checkIn(0);
	cout << "���ö��Ƽ�ֵ";
	shield = checkIn(0);
	cout << "�������ݵ���ֵ";
	DEX_mod = checkIn(0);
	cout << "������ǿ��ֵ";
	eb = checkIn(0);
	cout << "����ƫб��ֵ";
	defb = checkIn(0);
	cout << "�����������׼�ֵ";
	na = checkIn(0);
	cout << "�������ܼ�ֵ";
	dogb = checkIn(0);
	cout << "������ʱ����ֵ";
	temporary = checkIn(0);
	all = 10 + armor + shield + DEX_mod + eb + defb + na + dogb + temporary;
	touch = 10 + DEX_mod + eb + defb + na + dogb + temporary;
	flat = 10 + armor + shield + eb + defb + na + temporary;
	return;
}

int character_card_pf::AC_get_all()
{
	system("cls");
	cout << "\n��������AC���塪������";
	cout << "\n��AC all:\t" << all << "\n�Ӵ�AC touch:\t" << touch << "\n���ֲ��� flat:\t" << flat;
	cout << "\n��������AC��ϸ��������";
	cout << "\n���׼�ֵ armor:\t\t"<<armor;
	cout << "\n���Ƽ�ֵ shield:\t"<<shield;
	cout << "\n���ݵ���ֵ DEX_mod:\t" << DEX_mod;
	cout << "\n��ǿ��ֵ eb:\t\t"<<eb;
	cout << "\nƫб��ֵ defb:\t\t"<<	defb;
	cout << "\n�������׼�ֵ na:\t"<<na;
	cout << "\n���ܼ�ֵ dogb:\t\t"<<dogb;
	cout << "\n��ʱ����ֵ temporary:\t" << temporary;
	cout << endl;
	system("pause");
	system("cls");
	return 0;
}

int character_card_pf::AC_find_one(int type)
{
	switch (type) {
	case 0:
		cout << "\n��AC all:\t" << all;
		pause();
		return all;
	case 1:
		cout << "\n�Ӵ�AC touch:\t" << touch;
		pause();
		return touch;
	case 2:
		cout << "\n���ֲ��� flat:\t" << flat;
		pause();
		return flat;
	case 3:
		cout << "\n���׼�ֵ armor:\t\t" << armor;
		pause();
		return armor;
	case 4:
		cout << "\n���Ƽ�ֵ shield:\t" << shield;
		pause();
		return shield;
	case 5:
		pause();
		cout << "\n���ݵ���ֵ DEX_mod:\t" << DEX_mod;
		return DEX_mod;
	case 6:
		pause();
		cout << "\n��ǿ��ֵ eb:\t\t" << eb;
		return eb;
	case 7:
		pause();
		cout << "\nƫб��ֵ defb:\t\t" << defb;
		return defb;
	case 8:
		pause();
		cout << "\n�������׼�ֵ na:\t" << na;
		return na;
	case 9:
		cout << "\n���ܼ�ֵ dogb:\t\t" << dogb;
		pause();
		return dogb;
	case 10:
		cout << "\n��ʱ����ֵ temporary:\t" << temporary;
		pause();
		return temporary;
	}
}

int character_card_pf::AC_find_one()
{
	cout << "\n��������AC���ʱ���������";
	cout << "\n��AC all\t\t0"<< "\n�Ӵ�AC touch\t\t1"<< "\n���ֲ��� flat\t\t2";
	cout << "\n���׼�ֵ armor\t\t3";
	cout << "\n���Ƽ�ֵ shield\t\t4";
	cout << "\n���ݵ���ֵ DEX_mod\t5";
	cout << "\n��ǿ��ֵ eb\t\t6";
	cout << "\nƫб��ֵ defb\t\t7";
	cout << "\n�������׼�ֵ na\t\t8";
	cout << "\n���ܼ�ֵ dogb\t\t9";
	cout << "\n��ʱ����ֵ temporary\t10";
	cout << "\n ������Ҫ��ѯ�����ԵĶ�Ӧ����\n";
	int type;
	type = checkIn(0);
	return AC_find_one(type);
}

int character_card_pf::AC_change_one()
{
	cout << "\n��������AC���ʱ���������";
	cout << "\n��AC all\t\t" << "�Ӵ�AC touch\t\t" << "���ֲ��� flat\t\t";
	cout << "\n���׼�ֵ armor ";
	cout << "\n���Ƽ�ֵ shield ";
	cout << "\n���ݵ���ֵ DEX_mod";
	cout << "\n��ǿ��ֵ eb\t\t6";
	cout << "\nƫб��ֵ defb\t\t7";
	cout << "\n�������׼�ֵ na\t\t8";
	cout << "\n���ܼ�ֵ dogb\t\t9";
	cout << "\n��ʱ����ֵ temporary\t10";
	cout << "\n ������Ҫ���ĵ����ԵĶ�Ӧ����\n";
	int choice;
	choice = checkIn(0);
	switch (choice) {
	case 6:
		cout << "\n��ǿ��ֵ eb:\t\t" << eb;
		if (confirm() == 1) {
			cout << "\n������ĺ����ֵ";
			eb = checkIn(0);
		}
		break;
	case 7:
		cout << "\nƫб��ֵ defb:\t\t" << defb;
		if (confirm() == 1) {
			cout << "\n������ĺ����ֵ";
			defb = checkIn(0);
		}
		break;
	case 8:
		cout << "\n�������׼�ֵ na:\t" << na;
		if (confirm() == 1) {
			cout << "\n������ĺ����ֵ";
			na = checkIn(0);
		}
		break;
	case 9:
		cout << "\n���ܼ�ֵ dogb:\t\t" << dogb;
		if (confirm() == 1) {
			cout << "\n������ĺ����ֵ";
			dogb = checkIn(0);
		}
		break;
	case 10:
		cout << "\n��ʱ����ֵ temporary:\t" << temporary;
		if (confirm() == 1) {
			cout << "\n������ĺ����ֵ";
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
	int temp = 0;//����ֵ
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
	cout << "������\t��ֵ\t����ֵ\n";
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
	cout << "���Ա�\n1.str \n2.dex \n3.con \n4.int \n5.wis \n6.cha";
	int type = 0;
	do {
		cout << "\n������Ҫ����������(1~6)";
		type = checkIn(type);
	} while (type < 1 || type > 6);
system("cls");
cout << "1.ԭֵ \n2.����ֵ";
int datatype=0;
do {
	cout << "\n������Ҫ��ѯ������(1~2)";
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
	cout<<"�����빺�������Ĭ��25"<<endl;
	point = checkIn(point);
	while (point != 0) {
		done = 0;
		ability_get_all();
		cout<<"\nbuytable\nԭʼ����  ���Ĺ���\n7\t�C4\n8\t�C2\n9\t�C1\n10\t 0\n11\t 1\n12\t 2\n13\t 3\n14\t 5\n15\t 7\n16\t 10\n17\t 13\n18\t 17\n"<< "ʣ�๺����" << point << endl<<"���������ĵ���";
		reduce=checkIn(reduce);
		while (done == 0) {
			if (reduce <= point) {
				point = point - reduce;
				done = 1;
			}
			else {
				system("cls");
				ability_get_all();
				cout << "\nbuytable\nԭʼ����  ���Ĺ���\n7\t�C4\n8\t�C2\n9\t�C1\n10\t 0\n11\t 1\n12\t 2\n13\t 3\n14\t 5\n15\t 7\n16\t 10\n17\t 13\n18\t 17\n" << "ʣ�๺����" << point << endl << "���������ĵ���";
				reduce = checkIn(reduce);
			}
		}
		cout<<"��ѡ����������1.����2.����3.����4.����5.��֪6.����";
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
		cout<<"\n�Ƿ���roll 0.�� 1.����\n";
		done = checkIn(done);
	}
}

void character_card_pf::show_armor(int No)
{
	system("cls");
	cout << "��Ʒ����  " << armors[No].itemname << "+" << armors[No].SA[0]
		<< "\t��ֵ  " << armors[No].value[0] << " ��� " << armors[No].value[1] << " ���� " << armors[No].value[2] << " ͭ��" << endl
		<< "����\t" << armors[No].weight 
		<< "\t�ƶ��ٶ�    " << armors[No].speed<<endl
		<< "���׼�ֵ" << armors[No].bouns
		<< "\t���׼춨��ֵ  " << armors[No].check_penalty
		<< "\t������ݼ�ֵ" << armors[No].max_dex_bouns << endl
		<< "����������" << armors[No].abilities;
}

int character_card_pf::change_armor(int No)
{
	cout << "��Ʒ����  ";
	armors[No].itemname = checkIn(armors[No].itemname);
	cout << "��ֵ  ";
	armors[No].SA[0] = checkIn(armors[No].SA[0]);
	cout << "��Ч��ֵ";
	armors[No].SA[1] = checkIn(armors[No].SA[1]);
	cout << "��ֵ\n"<< "���  ";
	armors[No].value[0] = checkIn(armors[No].value[0]);
	cout << "����  ";
	armors[No].value[1] = checkIn(armors[No].value[1]);
	cout << "ͭ��  ";
	armors[No].value[2] = checkIn(armors[No].value[2]);
	cout << "����  ";
	armors[No].weight = checkIn(armors[No].weight);
	cout << "�ƶ��ٶ�    ";
	armors[No].speed = checkIn(armors[No].speed);
	cout << "���׼�ֵ";
	armors[No].bouns = checkIn(armors[No].bouns);
	cout << "���׼춨��ֵ  ";
	armors[No].check_penalty = checkIn(armors[No].check_penalty);
	cout << "������ݼ�ֵ  "; 
	armors[No].max_dex_bouns = checkIn(armors[No].max_dex_bouns);
	cout << "��������";
	armors[No].abilities = checkIn(armors[No].abilities);
	return 0;
}

void character_card_pf::show_weapon(int No)
{
	cout << "��Ʒ����  " << weapons[No].itemname << "+" << weapons[No].SA[0]
		<< "\t��ֵ  " << weapons[No].value[0] << " ��� " << weapons[No].value[1] << " ���� " << weapons[No].value[2] << " ͭ��" << endl
		<< "����\t" << weapons[No].weight << endl
		<< "�˺�\t" << weapons[No].dice[0] << "d" << weapons[No].dice[1] << "+" << weapons[No].SA[0] << endl
		<< "�˺�����\n0 ��ʾ�� 1 ��ʾ�� \n����\t�ۻ�\t�ӿ�" << endl;
	for (int i = 0; i < 3; i++)	cout << weapons[No].dmg_type[i] << "\t";
}

int character_card_pf::change_weapon(int No)
{
	cout << "��Ʒ����  ";
	weapons[No].itemname = checkIn(weapons[No].itemname);
	cout << "��ֵ  ";
	weapons[No].SA[0] = checkIn(weapons[No].SA[0]);
	cout << "��Ч��ֵ";
	weapons[No].SA[1] = checkIn(weapons[No].SA[1]);
	cout << "��ֵ\n" << "���  ";
	weapons[No].value[0] = checkIn(weapons[No].value[0]);
	cout << "����  ";
	weapons[No].value[1] = checkIn(weapons[No].value[1]);
	cout << "ͭ��  ";
	weapons[No].value[2] = checkIn(weapons[No].value[2]);
	cout << "����  ";
	weapons[No].weight = checkIn(weapons[No].weight);
	cout << "�˺�������  ";
	weapons[No].dice[0] = checkIn(1);
	cout << "�˺����ӵ���  ";
	weapons[No].dice[1] = checkIn(1);
	cout<< "�˺�����\n0 ��ʾ�� 1 ��ʾ�� \n����\t�ۻ�\t�ӿ�" << endl;
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
		cout << "��ʧ��";
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
			cout << "ѡ��ְҵ" << endl;
			for (int j = 0; j < 11; j++) {
				if (j % 3 == 0) cout << endl;
				cout <<j<<"."<< AllClass[j] << "\t";
			}
			int choice = 0;
			choice = checkIn(choice);
			CLASS[i].class_name = AllClass[choice];
			cout << "\n������ְҵ�ȼ���";
			CLASS[i].level = checkIn(1);
			cout << "\n������ְҵBAB";
			CLASS[i].class_BAB = checkIn(1);
			cout << "\n������ְҵ�����ֵ(ǿ�� ���� ��־)";
			CLASS[i].save_bouns[0] = checkIn(1);
			CLASS[i].save_bouns[1] = checkIn(1);
			CLASS[i].save_bouns[2] = checkIn(1);
			cout << "\n������ְҵ��������С";
			CLASS[i].HPD = checkIn(1);
			cout << "\n������ְҵ�ṩ����������(���������ʵ���)";
			CLASS[i].HP = checkIn(1);
			cout << "\n������ְҵ���ܵ�(��������������)";
			CLASS[i].skill_point = checkIn(1);
			cout << "\n������ְҵ���ʩ����������";
			int spell_level = 0;
			spell_level = checkIn(spell_level);
			for (int j = 0; j <= spell_level; j++) {
				cout << "������" << j << "������ÿ���ͷŴ���";
				CLASS[i].magics[0][j] = checkIn(0);
			}
			system("cls");
			cout << "�����ɹ�\n";
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
			cout << "����������������" << j + 1 << "ְҵ��������������" << endl
				<< "ְҵ��  " << CLASS[j].class_name << "\t�ȼ�  " << CLASS[j].level << endl
				<< "������  d" << CLASS[j].HPD << "\t" << "HP    " << CLASS[j].HP << endl
				<< "BAB  " << CLASS[j].class_BAB<<endl
				<< "���� \nǿ��\t����\t��־\n";
			for (int k = 0; k < 3; k++)cout << CLASS[j].save_bouns[k] << "\t";
			cout << endl
				<< "���ܵ�  " << CLASS[j].skill_point<<endl;
			for(int k=0;k<9;k++)
				if (CLASS[j].magics[0][k] != 0) {
					cout << k << "������\t���ͷŴ���" << CLASS[j].magics[0][k] << "\tʣ�����"<< CLASS[j].magics[1][k] <<endl;
				}
		}
		else { j++; }
	}
	else {
		int j = i-1;
			cout<< "ְҵ��  " << CLASS[j].class_name << "\t�ȼ�  " << CLASS[j].level << endl
			<< "������  d" << CLASS[j].HPD << "\t" << "HP    " << CLASS[j].HP << endl
			<< "���� \nǿ��\t����\t��־\n";
		for (int k = 0; k < 3; k++)cout << CLASS[j].save_bouns[k] << "\t";
		cout << endl
			<< "���ܵ�  " << CLASS[j].skill_point << endl;
		for (int k = 0; k < 9; k++)
			if (CLASS[j].magics[0][k] != 0) {
				cout << k << "������\t���ͷŴ���" << CLASS[j].magics[0][k] << "\tʣ�����" << CLASS[j].magics[1][k] << endl;
			}
	}
}

void character_card_pf::alter_class()
{
	show_class();
	int choice = 5;
	while (!(choice >= 1 && choice<=3)) {
		cout << "�����޸���һ��ְҵ(1/2/3)  ";
		choice = checkIn(1);
	}
	choice--;
	alter_class(choice);
}

void character_card_pf::alter_class(int classId)
{
	if (CLASS[classId].level==0)return add_class();
	cout << "ְҵ��  " << CLASS[classId].class_name<<endl;
	if (changeYes())CLASS[classId].class_name=checkIn(CLASS[classId].class_name);
	cout << "�ȼ�  " << CLASS[classId].level << endl;
	if (changeYes())CLASS[classId].level = checkIn(1);
	cout << "BAB  " << CLASS[classId].class_BAB << endl;
	if (changeYes())CLASS[classId].class_BAB = checkIn(1);
	cout << "������  d" << CLASS[classId].HPD<<endl;
	if (changeYes())CLASS[classId].HPD = checkIn(1);
	cout << "HP    " << CLASS[classId].HP << endl;
	if (changeYes())CLASS[classId].HP = checkIn(1);
	cout << "���� \nǿ��\t����\t��־" << endl;
	for (int k = 0; k < 3; k++) { cout << CLASS[classId].save_bouns[k] << "\t";
	if (changeYes())CLASS[classId].save_bouns[k] = checkIn(1);
	}
	cout << "���ܵ�  " << CLASS[classId].skill_point << endl;
	if (changeYes())CLASS[classId].skill_point = checkIn(1);
	for (int k = 0; k < 9; k++)
		if (CLASS[classId].magics[0][k] != 0) {
			cout << k << "������\t���ͷŴ���" << CLASS[classId].magics[0][k] << "\tʣ�����" << CLASS[classId].magics[1][k] << endl;
		}
	if (changeYes()) {
		cout << "\n�����޸ĺ����ʩ����������";
		int spell_level = 0;
		spell_level = checkIn(spell_level);
		int j = 0;
		for (; j <= spell_level; j++) {
			cout << "������" << j << "������ÿ���ͷŴ���";
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
		cout << "����ɾ����һ��ְҵ(1/2/3)  ";
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
