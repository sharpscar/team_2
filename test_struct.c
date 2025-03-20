#include <stdio.h>
#include <string.h> 
/**
 * 게임에 대한 모든 아이템과 몬스터들을 객체화? 구조체화 했다.
 * 
 * usage 
 * struct sword basic_sword;  선언 
 *  
 *  set_sword(basic_sword, '기본검', 10, 4, 1, 50, 0); 호출
 * 
 * 호출되어 리턴된 값으로 기본검이 생성됩니다. 
 * 
 */


struct sword  set_sword(struct sword p, char s_name[],int damage,int enforce, int attribute, int price, int mage_rage);


struct sword
{
    int tier;
    char name[30]; //칼의 이름
    int damage;
    int enforce; //강화
    int attribute; //속성 0 1 2 3 4
    int price;
    int magic_rage; //마법배율? 뭐에쓰는 녀석인고?

};

struct sword  set_sword(struct sword s, char s_name[],int damage,int enforce, int attribute, int price, int mage_rage)
{
    strcpy(s.name, s_name);
    s.damage = damage;
    s.enforce= enforce;
    s.attribute = attribute;
    s.price = price;
    s.magic_rage = mage_rage;

    return s;
}




// 갑옷/신발/장갑/망토/투구 공통이다.
struct amor
{
    int damage_reduction; //뎀감
    int damage_reduction_rate; //뎀감률 
    char name[30]; //방어구의 이름
    int price;
    int additional_damge_rate; //추뎀
};

struct amor set_amor(struct amor a, char a_name[],int damage_reduction,int damage_reduction_rate, int additional_damge_rate, int price, int mage_rage)
{
    strcpy(a.name, a_name);
    a.damage_reduction = damage_reduction;
    a.damage_reduction_rate= damage_reduction_rate;
    a.price = price;
    a.additional_damge_rate = additional_damge_rate;

    return a;
}


struct potion
{
    char name[30]; //방어구의 이름
    int healing_hp_rate; //회복율
    int healing_mp_rate; //회복율
    int price;
    int quantity;   //수량99개 제한
    char special[5][30];
    // int anti_posion;    //해독제
    // int blessing;        //축복
    // int all_cure;        //만병통치약
    // int potal_scroll;    // 마을로감
    // int teleport_scroll; // 지정된 던전으로감

};

struct potion set_potion(struct potion p, char p_name[],int healing_hp_rate,int healing_mp_rate,int price,int quantity,char special[5][30])
{
    strcpy(p.name, p_name);
    p.healing_hp_rate = healing_hp_rate;
    p.healing_mp_rate= healing_mp_rate;
    p.price = price;
    p.quantity = quantity;
    strcpy(p.special, special);

    return p;
}

struct refinery_material
{
    char name[30];
    int refinery_tier;
    int is_MTS; //마력응축석 Magic Condensate Stone
    int quantity;
};

struct refinery_material set_refinery_material(struct refinery_material r, char r_name[],int refinery_tier, int is_MTS, int quantity)
{
    strcpy(r.name, r_name);
    r.refinery_tier = refinery_tier;
    r.is_MTS= is_MTS;    
    r.quantity = quantity;
    return r;
}
struct skill
{
    char name[30];
    int get_level;
    int type; // 1 불 2 물 3자연
    int magic_rate;
    int use_mp;
};

struct skill set_skill(struct skill s, char s_name[],int get_level ,int type,int magic_rate,int use_mp)
{
    strcpy(s.name, s_name);
    s.get_level = get_level;
    s.type= type;    
    s.magic_rate = magic_rate;
    s.use_mp= use_mp;
    return s;
}

struct monster
{
    char name[30];
    int tier_info;
    int hp;
    int atk;
    int def;
    int type; //  불은 물에 약하고 물은 자연에 약하고 자연은 불에 약함
    char drop_items[10][50];    // 드랍아이템
    char special_effect[10][50]; //특수효과
};  
struct monster set_monster(struct monster m, char m_name[],int tier_info ,int hp,int atk,int def, int type, char drop_items[10][50] ,char special_effect[10][50])
{
    strcpy(m.name, m_name);
    m.tier_info = tier_info;
    m.hp= hp;    
    m.atk = atk;
    m.def= def;
    m.type= type;
    m.drop_items[10][50]= drop_items[10][50];
    m.special_effect[10][50] = special_effect[10][50];
    return m;
}


struct swordman
{
    int lv;
    char name[30];
    int exp;
    int hp;
    int mp;
    int atk;
    int matk;
    int def;
    int ac;
    int cri;
    int str;
    int int_;
    int dex;
};

struct swordman set_swordman(struct swordman s, char s_name[],int lv ,int hp,int atk,int matk, int def, int ac,int cri, int str, int int_, int dex)
{
    strcpy(s.name, s_name);
    s.lv = lv;
    s.hp= hp;    
    s.atk = atk;
    s.def= def;
    s.ac =ac;
    s.cri =cri;
    s.str =str;
    s.int_ = int_;
    s.dex = dex;
    return s;
}


struct inven
{
    int wallet;
    int stat[11];
    char bag[20][20]; //캐릭터의 배낭이다.
    char consume[100][30] // 열에는 '' 이런식으로 숫자를 표기한다 더좋은방식 있으면 알려주시면 적극 수용

};

int main()
{
    /* 
    구조체에대한 설명https://dojang.io/mod/page/view.php?id=571
    주영님의 설명 https://cafe.naver.com/f-e/cafes/28969626/articles/54579?boardtype=L&menuid=777&referrerAllArticles=false
    책 712
    */
    

        // 해독, 저주회복, 만병통치약, 포탈스크롤(집), 텔포스크롤(저장워프) 
}




    


   