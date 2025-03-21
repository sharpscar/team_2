#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <time.h>
#define UNIQUE_SIZE 1000
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
int make_unique_number();

struct sword  set_sword(struct sword p, char s_name[],int damage,int enforce, int attribute, int price, int mage_rate, int cri_rate);
struct amor set_amor(struct amor a, char a_name[],int damage_reduction,int damage_reduction_rate, int additional_damge_rate, int price, int mage_rage);
struct potion set_potion(struct potion p, char p_name[],int healing_hp_rate,int healing_mp_rate,int price,int quantity,int anti_posion,int blessing, int all_cure, int potal_scroll, int teleport_scroll);
struct refinery_material set_refinery_material(struct refinery_material r, char r_name[],int refinery_tier, int is_MTS, int quantity);
struct monster set_monster(struct monster m, char m_name[],int tier_info ,int hp,int atk,int def, int type, char drop_items[10][50] ,char special_effect[10][50]);
struct swordman set_swordman(struct swordman s, char s_name[],int lv ,int hp,int atk,int matk, int def, int ac,int cri, int str, int int_, int dex);
struct inven set_inven(struct inven i,int wallet, char bag[20][20], struct potion);

struct sword
{
    int tier;
    int uid;
    char name[30]; //칼의 이름
    int damage;
    int enforce; //강화
    int attribute; //속성 0 1 2 3 4
    int price;
    int cri_rate;
    int magic_rate; //마법배율? 뭐에쓰는 녀석인고?

};

struct sword  set_sword(struct sword s, 
    char s_name[],
    int damage,
    int enforce,
    int attribute, 
    int price,
    int cri_rate, 
    int magic_rate)
{
    strcpy(s.name, s_name);
    s.uid = make_unique_number();
    s.damage = damage;
    s.enforce= enforce;
    s.attribute = attribute;
    s.price = price;
    s.cri_rate = cri_rate;
    s.magic_rate = magic_rate;    
    return s;
}




// 갑옷/신발/장갑/망토/투구 공통이다.
struct amor
{
    int uid;
    int enforce;
    int attribute; //속성 0 1 2 3 4   갑옷에 속성을 넣은 이유는 몬스터가 속성공격 할수 도 있게 미리 미리!!
    char name[30]; //방어구의 이름
    int price;
    int damage_reduction; //뎀감
    int damage_reduction_rate; //뎀감률 
    int additional_damge_rate; //추가 데미지 비율
    int additional_ac_rate;    //추가 회피율
    int additional_cri_rate;   //추가 치명타율
    int is_debuff; // 거의 모든 템은 상태이상을 제어할수 없지만 템1개는 ㅠ

};


struct amor  set_amor(struct amor a, char a_name[],int damage_reduction,
        int damage_reduction_rate,int enforce,int price, int additional_damge_rate , 
        int additional_ac_rate,int additional_cri_rate, int is_debuff)
    {
    strcpy(a.name, a_name);
    a.uid = make_unique_number();
    a.enforce = enforce;
    a.damage_reduction = damage_reduction;
    a.damage_reduction_rate= damage_reduction_rate;    
    a.price = price;
    a.additional_damge_rate = additional_damge_rate;
    a.additional_ac_rate = additional_ac_rate;    //추가 회피율
    a.additional_cri_rate = additional_cri_rate;   //추가 치명타율
    a.is_debuff = is_debuff;// 거의 모든 템은 상태이상을 제어할수 없지만 템1개는 ㅠ
    return a;
}

struct consume
{
    char name[30]; //방어구의 이름
    int healing_hp_rate; //회복율
    int healing_mp_rate; //회복율
    int price;
    int quantity;   //수량99개 제한
    // char special[5][30];
    int anti_posion;    //해독제
    int is_blessing;        //축복
    int is_all_cure;        //만병통치약
    int is_potal_scroll;    // 마을로감
    int is_teleport_scroll; // 지정된 던전으로감

};


struct consume set_consume(
    struct consume c, char c_name[],int healing_hp_rate,int healing_mp_rate,int price,int quantity,
    int anti_posion,int is_blessing, int is_all_cure, int is_potal_scroll, int is_teleport_scroll)
{
    strcpy(c.name, c_name);
    c.healing_hp_rate = healing_hp_rate;
    c.healing_mp_rate= healing_mp_rate;
    c.price = price;
    c.quantity = quantity;
    c.anti_posion = anti_posion;
    c.is_blessing = is_blessing;
    c.is_all_cure = is_all_cure;
    c.is_potal_scroll = is_potal_scroll;
    c.is_teleport_scroll =is_teleport_scroll;
    // strcpy(p.special[5][30], special[5][30]);

    return c;
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


struct status
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
    //좌표 ()()(마을)()()
};

struct status set_status(struct status s, char s_name[],int lv ,int hp,int atk,int matk, int def, int ac,int cri, int str, int int_, int dex)
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
    int money;
    struct sword sw;
    struct amor am;
    struct consume con;    
    struct refinery_material rm;
};

// struct inven set_inven(struct inven i,int money, struct sword sw,struct amor am, struct potion po)
// {
//     i.money =   money;
//     i.sw = sw;
    
// }

int make_unique_number()
{    
    // int rotto[SIZE];
    int r_number;
    int flag;
    int unique_number_list[UNIQUE_SIZE];
  
    srand((unsigned)time(NULL));

    r_number = (rand()% UNIQUE_SIZE) +1; 

    // is_in 을 호출해야함 
    for (int i=0; i<=sizeof(unique_number_list)/sizeof(int) ;i++)
    {
        if (r_number!= unique_number_list[i])
        {    
            unique_number_list[i] = r_number;            
        }
        
    }
    return r_number;
}


int main()
{
    /* 
    구조체에대한 설명https://dojang.io/mod/page/view.php?id=571
    주영님의 설명 https://cafe.naver.com/f-e/cafes/28969626/articles/54579?boardtype=L&menuid=777&referrerAllArticles=false
    책 712
    */


    struct sword sword1_basic;
    struct sword sword2_longsword;
    struct sword sword3_japanese;
    struct sword sword4_ssaulabi;
    struct sword sword5_sword_Of_Chaos;
    struct sword sword6_world_Best;
    struct sword sword7_s;
    struct sword sword8_operaters;
    // 이름, 공격력, 강화, 속성, 가격, 마법, 치명타 칼을 초기화
    sword1_basic =set_sword(sword1_basic,"기본검", 2,0,0,50,0,0);
    sword2_longsword= set_sword(sword2_longsword,"장검", 10,0,0,500,0,0);
    sword3_japanese= set_sword(sword3_japanese,"일본도", 20,0,0,1000,0,0);
    sword4_ssaulabi= set_sword(sword4_ssaulabi,"싸울아비장검", 40,0,0,0,0,0);
    sword5_sword_Of_Chaos= set_sword(sword5_sword_Of_Chaos,"혼돈의검", 50,0,0,0,0,30);
    sword6_world_Best= set_sword(sword6_world_Best,"천상천하제일무쌍도", 100,0,0,0,0,0);    
    sword7_s= set_sword(sword7_s,"마왕을 멸하는 마검", 50,0,0,0,50,0);
    sword8_operaters=set_sword(sword8_operaters,"운영자검",1111,0,0,0,0,0);


    struct amor amor1_leather;
    struct amor amor2_iron;
    struct amor amor3_strong_iron;
    struct amor amor4_mithril;
    struct amor amor5_advancing; //진격하는
    struct amor amor6_golem;
    struct amor amor7_cleans;
    amor1_leather=set_amor(amor1_leather,"가죽갑옷",-2,0,0,50,0,0,0,0);
        
        
    amor2_iron=set_amor(amor2_iron,"철갑옷",-6,0,0,50,0,0,0,0);
    amor3_strong_iron=set_amor(amor3_strong_iron,"강철갑옷",-12,0,0,50,0,0,0,0);
    amor4_mithril=set_amor(amor4_mithril,"미스릴갑옷",-20,0,0,50,0,0,0,0);
    amor5_advancing=set_amor(amor5_advancing,"진격하는 자의 갑옷",-20,0,0,50,0,0,20,0);
    amor6_golem=set_amor(amor6_golem,"골렘의 갑옷",-20,0,0,50,20,0,0,0);
    amor7_cleans=set_amor(amor7_cleans,"정화의 갑주",-20,0,0,50,0,0,0,0);
// 갑옷

//신발
    struct amor amor1_leather_shoes;
    struct amor amor2_iron_shoes;
    struct amor amor3_strong_iron_shoes;
    struct amor amor4_mithril_shoes;
    struct amor amor5_poseidon_shoes; //진격하는
    struct amor amor6_hermes_shoes;
    struct amor amor7_hades_shoes; 

    amor1_leather_shoes= set_amor(amor1_leather_shoes,"가죽신발",-1,0,0,50,0,0,0,0);
    amor2_iron_shoes= set_amor(amor2_iron_shoes,"철신발",-3,0,0,600,0,0,0,0);
    amor3_strong_iron_shoes= set_amor(amor3_strong_iron_shoes,"강철신발",-6,0,0,0,0,0,0,0);
    amor4_mithril_shoes= set_amor(amor4_mithril_shoes,"미스릴신발",-8,0,0,0,0,0,0,0);
    amor5_poseidon_shoes= set_amor(amor5_poseidon_shoes,"포세이돈의신발",-8,0,0,0,0,0,0,1);
    amor6_hermes_shoes= set_amor(amor6_hermes_shoes,"헤르메스의신발",-3,0,0,0,0,0,20,0);
    amor7_hades_shoes= set_amor(amor7_hades_shoes,"하데스의신발",-3,0,0,0,10,0,0,0);

/*
    struct amor  set_amor(struct amor a, char a_name[],int damage_reduction,
        int damage_reduction_rate,int price, int additional_damge_rate , 
        int additional_ac_rate,int additional_cri_rate)
    {
    strcpy(a.name, a_name);
    a.uid = make_unique_number();
    a.damage_reduction = damage_reduction;
    a.damage_reduction_rate= damage_reduction_rate;    
    a.price = price;
    a.additional_damge_rate = additional_damge_rate;
    a.additional_ac_rate = additional_ac_rate;    //추가 회피율
    a.additional_cri_rate = additional_cri_rate;   //추가 치명타율
    디버프효과 유무 0/1
    return a;
}
    */

    //장갑 
    struct amor amor1_leather_gloves;
    struct amor amor2_iron_gloves;
    struct amor amor3_strong_iron_gloves;
    struct amor amor4_mithril_gloves;
    struct amor amor5_hand_of_sin_gloves; //죄악의마수
    struct amor amor6_fairy_bracelet_gloves;// 요정의 팔찌
    struct amor amor7_chaos_gloves; //

    amor1_leather_gloves= set_amor(
        amor1_leather_gloves,"가죽장갑",-1,0,0,50,0,0,0,0);
    amor2_iron_gloves= set_amor(
        amor2_iron_gloves,"철장갑",-3,0,0,600,0,0,0,0);
    amor3_strong_iron_gloves= set_amor(
        amor3_strong_iron_gloves,"강철장갑",-6,0,0,0,0,0,0,0);
    amor4_mithril_gloves= set_amor(
        amor4_mithril_gloves,"미스릴장갑",-8,0,0,0,0,0,0,0);
    amor5_hand_of_sin_gloves= set_amor(
        amor5_hand_of_sin_gloves,"죄악의마수",-8,0,0,0,10,0,0,0);//모든공격력10퍼
    amor6_fairy_bracelet_gloves= set_amor(
        amor6_fairy_bracelet_gloves,"요정의팔찌",-8,0,0,0,10,0,0,0);
    amor7_chaos_gloves= set_amor(
        amor7_chaos_gloves,"혼돈의 수갑",-8,0,10,0,0,0,20,0);

    //망토
    struct amor amor1_leather_cloak;
    struct amor amor2_cotton_cloack;
    struct amor amor3_silk_cloak;
    struct amor amor4_magic_cloack;
    struct amor amor5_white_cloack; //죄악의마수
    struct amor amor6_brave_cloack;// 요정의 팔찌
    struct amor amor7_red_cloack; //        

    amor1_leather_gloves= set_amor(
        amor1_leather_gloves,"천망토",-1,0,0,50,0,0,0,0);
    amor2_cotton_cloack= set_amor(
        amor2_cotton_cloack,"면망토",-3,0,0,600,0,0,0,0);
    amor3_silk_cloak= set_amor(
        amor3_silk_cloak,"비단망토",-6,0,0,0,0,0,0,0);
    amor4_magic_cloack= set_amor(
        amor4_magic_cloack,"마법망토",-8,0,0,0,0,0,0,0);
    amor5_white_cloack= set_amor(
        amor5_white_cloack,"순백의망토",-20,0,0,0,0,0,0,0);
    amor6_brave_cloack= set_amor(
        amor6_brave_cloack,"용기의망토",-8,0,0,0,10,0,0,0);
    amor7_red_cloack= set_amor(
        amor7_red_cloack,"진홍의망토",-8,0,0,0,0,0,20,0);

    //투구
    struct amor amor1_leather_helmet;
    struct amor amor2_iron_helmet;
    struct amor amor3_strong_iron_helmet;
    struct amor amor4_mithril_helmet;
    struct amor amor5_brave_helmet; //죄악의마수
    struct amor amor6_dragon_knight;// 요정의 팔찌
    struct amor amor7_strange_hood; //        

    amor1_leather_gloves= set_amor(
        amor1_leather_gloves,"가죽투구",-1,0,0,50,0,0,0,0);
    amor2_iron_helmet= set_amor(
        amor2_iron_helmet,"철투구",-3,0,0,600,0,0,0,0);
    amor3_strong_iron_helmet= set_amor(
        amor3_strong_iron_helmet,"강철투구",-6,0,0,0,0,0,0,0);
    amor4_mithril_helmet= set_amor(
        amor4_mithril_helmet,"미스릴투구",-8,0,0,0,0,0,0,0);
    amor5_brave_helmet= set_amor(
        amor5_brave_helmet,"용사의투구",-8,0,0,0,10,0,0,0);
    amor6_dragon_knight= set_amor(
        amor6_dragon_knight,"용기사의투구",-8,0,0,0,10,0,0,0);
    amor7_strange_hood= set_amor(
        amor7_strange_hood,"기묘한두건",-1,0,0,0,0,30,0,0);

    // 포션

    // struct consume set_consume(
    //     struct consume c, char c_name[],int healing_hp_rate,int healing_mp_rate,int price,int quantity,
    //     int anti_posion,int is_blessing, int is_all_cure, int is_potal_scroll, int is_teleport_scroll)
    // {
    //     strcpy(c.name, c_name);
    //     c.healing_hp_rate = healing_hp_rate;
    //     c.healing_mp_rate= healing_mp_rate;
    //     c.price = price;
    //     c.quantity = quantity;
    //     c.anti_posion = anti_posion;
    //     c.is_blessing = is_blessing;
    //     c.is_all_cure = is_all_cure;
    //     c.is_potal_scroll = is_potal_scroll;
    //     c.is_teleport_scroll =is_teleport_scroll;
    //     // strcpy(p.special[5][30], special[5][30]);
    
    //     return c;
    // }
    
    struct consume red_potion;
    struct consume orange_potion;
    struct consume clean_potion;
    struct consume blue_potion;
    struct consume white_potion;
    struct consume rainbow_potion;
    struct consume elixer;
    struct consume anti_toxic;
    struct consume blessing_scroll;
    struct consume all_cure;
    struct consume potal_scroll;
    struct consume teleport_scroll;

    red_potion = set_consume(red_potion,"레드포션",30,0,30,0,0,0,0,0,0);
    orange_potion = set_consume(orange_potion,"주황물약",60,0,200,0,0,0,0,0,0);
    clean_potion = set_consume(clean_potion,"맑은물약",80,0,1000,0,0,0,0,0,0);
    blue_potion = set_consume(blue_potion,"파란물약",0,30,50,0,0,0,0,0,0);
    white_potion = set_consume(white_potion,"하얀물약",0,60,300,0,0,0,0,0,0);
    rainbow_potion = set_consume(rainbow_potion,"무지개물약",0,80,1500,0,0,0,0,0,0);
    elixer = set_consume(elixer,"엘릭서",10000,10000,30,0,0,0,0,0,0); //우선 풀충전을 10000으로 설정 추후 변경요청
    anti_toxic = set_consume(anti_toxic,"해독제",0,0,500,0,0,0,0,0,0);
    blessing_scroll = set_consume(blessing_scroll,"축복주문서",0,0,2000,0,1,0,0,0,0);
    all_cure = set_consume(all_cure,"만병통치약",0,0,0,0,0,0,1,0,0);
    potal_scroll = set_consume(potal_scroll,"마을이동주문서",0,0,200,0,0,0,0,1,0);
    teleport_scroll = set_consume(teleport_scroll,"순간이동주문서",0,0,1000,0,0,0,0,0,0);
    






    // struct inven
    // {
    //     int money;
    //     struct sword sw[5];
    //     struct amor am[15];
    //     struct potion po[99];
    //     //struct potion 을 구현하고 싶었는데 어떻게 하는지 모르겠다.
    // };



    // int tier;
    // char name[30]; //칼의 이름
    // int damage;
    // int enforce; //강화
    // int attribute; //속성 0 1 2 3 4
    // int price;
    // int cri_rate;
    // int magic_rate; //마법배율? 뭐에쓰는 녀석인고?



    struct inven
    {
        int money;
        struct sword sw;
        struct amor am;
        struct consume co;
        //struct potion 을 구현하고 싶었는데 어떻게 하는지 모르겠다.
    };
    struct inven mi;
    


    
    mi.sw = sword1_basic;

    return 0;
    
}




//해야하는것! 칼 , 방어구 id 속성 추가  그리고 세터함수에 unique_id를 넣는다.
    


   