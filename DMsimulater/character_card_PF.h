#include <string>
#include<iostream>
#include"tools.h"
using namespace std;
#ifndef CHARACTER_CARD_PF
#define CHARACTER_CARD_PF
class class_mod {
public:
	string class_name;//职业名称
	int level=0;//等级
	int class_BAB=0;//基础攻击加值
	int save_bouns[3];//豁免加值 0.强韧 1.反射 2.意志
	int HPD=0;//生命骰大小
	int HP = 0;//生命值
	int skill_point=0;//技能点
	int magics[2][9] = { {0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0} };//魔法使用次数
};
class items {
public:
	items();
	string itemname;//物品名称
	int value[3];//价值 金币/银币/铜币
	int weight;//重量
};
class equipment :public items {
public:
	equipment();
	int SA[2];//附魔等级 0加值 1等效加值
	string abilities;//额外能力
};
class weapon : public equipment {
public:
	weapon();
	int dice[2];//0.骰子数量 1.骰子大小
	int dmg_type[3];//0表示无1表示有 0.穿刺 1.钝击 2.挥砍
};
class armor : public equipment {
public:
	armor();
	int bouns;//护甲加值
	int max_dex_bouns;//最大敏捷加值
	int check_penalty;//检定减值
	float spell_failure_chance;//法术失败率 小数
	int speed;//移动速度
};
class character_card_pf {
public:
	character_card_pf();//默认构造函数
	void creat_character();//创造人物
	void Rcreat_character();//随机创造人物
	void read_character(string filename);//读取人物
	void check_character();//检查数据计算是否合格

	string getName();//返回名字
	void changeName(string newName);//修改名字
	string getGender();//返回性别
	void changeGender(string newGender);//修改性别
	string getRace();//返回种族
	void changeRace(string newRace);//修改种族
	string getAli();//返回阵营
	void changeAli(string newAli);//修改阵营
	void add_class();//添加职业
	void show_class(int i = 4);//展示职业信息
	void alter_class();//修改职业
	void alter_class(int classId);//修改职业
	void del_class();//删除职业
	void del_class(int classId);//删除职业
	void reset_spell();//重置法术次数

	void AC(int type = 1); //1.默认值 2.依次输入
	void AC_change_all();//修改所有属性
	int AC_get_all();//展示所有的属性
	int AC_find_one(int type);//展示特定的属性并返回值
	int AC_find_one();//手动输入
	int AC_change_one();//修改特定属性

	void ability_scores(int str = 10, int dex = 10, int con = 10, int int_ = 10, int wis = 10, int cha = 10);
	void ability_get_modifier();
	int ability_get_all();//展示所有的属性
	int ability_find_one(int type, int datatype = 1);//展示特定的属性并返回值
	//type 1.str 2. dex 3. con 4.int 5.wis 6.cha
	//datatype 1.原值 2.调整值
	int ability_find_one();//手动输入
	void ability_change_one(int type);//修改特定属性 
	//type 1.str 2. dex 3. con 4.int 5.wis 6.cha
	//datatype 1.原值
	//调整值不允许修改
	void buyIt();//购点属性值
	void rollIt();//roll属性值
	void chooseRace();//选择种族

	
	

	void show_armor(int No);//展示护甲属性
	int change_armor(int No);//修改护甲属性
	void show_weapon(int No);//展示武器属性
	int change_weapon(int No);//修改武器属性

	void save_get_modifier();//规范化数据
protected:
	void chooseAdd();//选择属性加值
	string name;//名字
	string ali;//阵营
	string race;//种族
	string gender;//性别
	int level;//人物等级
	class class_mod CLASS[3];//职业

	int hp;//生命值
	string Feat[10];//专长
	int STR[2];//力量 0为原值 1为调整值
	int DEX[2];//敏捷 0为原值 1为调整值
	int CON[2];//体质 0为原值 1为调整值
	int INT[2];//智力 0为原值 1为调整值
	int WIS[2];//感知 0为原值 1为调整值
	int CHA[2];//魅力 0为原值 1为调整值

	int fortitude;//强韧
	int reflex;//反射
	int will;//意志

	int all;//护甲 = 10+armor+shield+dex+eb+defb+na+dogb+temporary
	int touch;//接触护甲 = 10+dex+eb+defb+na+dogb+temporary
	int flat;//措手不及 = 10+armor+shield+eb+defb+na+temporary
	int armor;//护甲加值
	int shield;//盾牌加值
	int DEX_mod;//敏捷加值
	int eb;//增强加值
	int defb;//偏斜加值
	int na;//天生护甲
	int dogb;//闪避加值
	int temporary;//临时调整

	class armor armors[2];//0 护甲 1 盾牌
	weapon weapons[3];//武器123
};

#endif