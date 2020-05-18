#include"character_card_PF.h"
#include"tools.h"
#include"map.h"
using namespace std;
struct card {
	character_card_pf temp;
	struct card* next;
};
void creatNew(card* head, card* pCur, card* pEnd) {
	system("cls");
	if (head == NULL) {
		pCur = new card;
		pCur->temp.AC_change_all();
		head = pCur;
		pEnd = pCur;
	}//创建头结点
	else {
		pCur = new card;
		pCur->temp.AC_change_all();
		if (pEnd != NULL) {
			pEnd->next = pCur;
			pEnd = pCur;
		}
		else {
			pEnd = pCur;
		}
	}
	pEnd->next = NULL;
	system("pause");
}
int main() {
    int KillPorgram = 0;
    card* head, * pEnd, * pCur;
	head = NULL;
    pEnd = NULL;
	pCur = new card;
	/*
	for (int i = 0; i < 2; i++) {
		system("cls");
		if (head == NULL) {
			pCur = new card;
			pCur->temp.AC_change_all();
			head = pCur;
			pEnd = pCur;
		}//创建头结点
		else {
			pCur = new card;
			pCur->temp.AC_change_all();
			if (pEnd != NULL) {
				pEnd->next = pCur;
				pEnd = pCur;
			}
			else {
				pEnd = pCur;
			}
		}
		pEnd->next = NULL;
		system("pause");
	}
	*/
//	pCur->temp.add_class();
//	pCur->temp.read_character("test2.txt");
//	pCur->temp.check_character();
//	pCur->temp.rollIt();
//	pCur->temp.ability_change_one(1);
	pCur->temp.ability_scores(11,20,21,22,23,24);
	pCur->temp.ability_get_all();
//	pCur->temp.show_class();
//	pCur->temp.change_weapon(0);
//	pCur->temp.show_weapon(0);
	return 0;

}