
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <time.h>





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

int make_num();
int return_min_max_random(int min_, int max_);
struct sword set_sword(struct sword s, 
    char s_name[],
    int tier,
    int index_,
    int damage,
    int enforce,
    int attribute, 
    int price,
    int cri_rate, 
    int magic_rate);
struct amor  set_amor(struct amor a, char a_name[],int index_,int damage_reduction,
        int damage_reduction_rate,int tier,int enforce,int price, int additional_damge_rate , 
        int ,int additional_cri_rate, int is_debuff);
struct potion set_potion(struct potion p, char p_name[],int healing_hp_rate,int healing_mp_rate,int price,int quantity,int anti_posion,int blessing, int all_cure, int potal_scroll, int teleport_scroll);
struct refinery_material set_refinery_material(struct refinery_material r, char r_name[],int refinery_tier, int is_MTS, int quantity);
struct monster set_monster(
    struct monster m, char m_name[],
    int tier_lv_min, int tier_lv_max, 
    int hp_min, int hp_max,  
    int atk_min, int atk_max, 
    int def_min, int def_max,
    int weak_attr, int strong_attr
    // struct amor da,  struct sword ds,struct consume dc,struct refinery_material drm
);
struct status set_status(struct status s, char s_name[],int lv ,int hp,int atk,int matk, int def, int ac,int cri, int str, int int_, int dex);

struct inven set_inven(struct inven i,int wallet, char bag[20][20], struct potion);

struct sword
{
    int tier;
    int uid;
    char name[30]; //칼의 이름  
    int index_;  
    int damage;
    int enforce; //강화
    int attribute; //속성 0 1 2 3 4
    int price;
    int cri_rate;
    int magic_rate; //마법배율? 뭐에쓰는 녀석인고?

};

struct sword set_sword(struct sword s, 
    char s_name[],
    int tier,
    int index_,
    int damage,
    int enforce,
    int attribute, 
    int price,
    int cri_rate, 
    int magic_rate)  
{
    strcpy(s.name, s_name);
    s.uid = make_num();
    s.index_= index_,
    s.tier = tier;
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
    int tier;
    int index_;
    int price;
    int damage_reduction; //뎀감
    int damage_reduction_rate; //뎀감률 
    int additional_damge_rate; //추가 데미지 비율
    int additional_ac_rate;    //추가 회피율
    int additional_cri_rate;   //추가 치명타율
    int is_debuff; // 거의 모든 템은 상태이상을 제어할수 없지만 템1개는 ㅠ

};


struct amor  set_amor(struct amor a, char a_name[],int index_,int damage_reduction,
        int damage_reduction_rate,int tier,int enforce,int price, int additional_damge_rate , 
        int additional_ac_rate,int additional_cri_rate, int is_debuff)
        {
            strcpy(a.name, a_name);
            a.uid = make_num();
            a.tier = tier;
            a.index_ = index_;
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
    float magic_rate;
    int use_mp;
};

struct skill set_skill(struct skill s, char s_name[],int get_level ,int type,float magic_rate,int use_mp)
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
    int tier_lv_max;
    int tier_lv_min;
    int tier;
    int hp_min;    
    int hp_max;    
    int hp;
    int atk_min;
    int atk_max;    
    int atk;
    int def_min;
    int def_max;    
    int def;
    int weak_attr;   //1,2,3  불/물/자연
    int strong_attr; //1,2,3  불/물/자연
    
    // int type; //  불은 물에 약하고 물은 자연에 약하고 자연은 불에 약함
    struct amor drop_amor;
    struct sword drop_sword;
    struct consume drop_consume_item;
    struct refinery_material drop_rm_item;
                //int drop_item_tier;   // 드랍아이템
                //int drop_item_material;
};  
struct monster set_monster(
    struct monster m, char m_name[],
    int tier_lv_min, int tier_lv_max, 
    int hp_min, int hp_max,  
    int atk_min, int atk_max, 
    int def_min, int def_max,
    int weak_attr, int strong_attr
    // struct amor da,  struct sword ds,struct consume dc,struct refinery_material drm
    )
{
    strcpy(m.name, m_name);
    m.tier_lv_max = tier_lv_max;
    m.tier_lv_min = tier_lv_min;
    m.tier = return_min_max_random(tier_lv_min, tier_lv_max);
    m.hp_min= hp_min;    
    m.hp_max= hp_max;    
    m.hp = return_min_max_random(hp_min, hp_max);
    m.atk_min = atk_min;
    m.atk_max = atk_max;
    m.atk = return_min_max_random(atk_min,atk_max);
    m.def_min = def_min;
    m.def_max = def_max;
    m.def= return_min_max_random(def_min,def_max);
    m.weak_attr=weak_attr;   //1,2,3  불/물/자연
    m.strong_attr=strong_attr;     
    
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
/*용복이의 최초스탯은 hp 100 mp 10, 공격 20 , 마공 10, 방어 0 회피 2, 치명 5
힘 인덱 10씩
*/


struct inven
{
    int money;
    struct sword sw[5];
    struct amor am[15];
    struct consume con[13];    
    struct refinery_material rm[5];
};

struct character
{
    struct inven;
    struct status;
};



//최대값 최소값 랜덤 리턴하는 함수
int return_min_max_random(int min_, int max_)
{

    
    int r_number;
    int flag;

    r_number = (rand()% (max_-min_+1)+min_); 

    

    return r_number;
}

// unique number 생성기
int make_num()
{    
    
    int time_num = (unsigned int)time(NULL);
    
    
    
   
    return time_num;
}


int setting()
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
   
//     // 포션

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
    
        // 재련 소비템 
    struct refinery_material small_fire_piece;
    struct refinery_material blue_fire_piece;
    struct refinery_material strong_fire_piece;
    struct refinery_material crazy_fire_piece;
    struct refinery_material magic_condensation_stone;
    
    small_fire_piece = set_refinery_material(small_fire_piece,"작은화염조각",3,0,0);
    blue_fire_piece = set_refinery_material(small_fire_piece,"푸른화염조각",6,0,0);
    strong_fire_piece = set_refinery_material(small_fire_piece,"강렬한화염조각",9,0,0);
    crazy_fire_piece = set_refinery_material(small_fire_piece,"미친화염조각",10,0,0);
    magic_condensation_stone = set_refinery_material(small_fire_piece,"마력응축석",3,1,0);

   struct skill fire_ball;
   struct skill water_spear;
   struct skill thunder_bolt;
   struct skill stone_shower;
   struct skill water_bomb;
   struct skill fire_spear;
   struct skill ice_ball;
   struct skill wind_cutter;
   struct skill blizard;
   struct skill blast;
   struct skill meteor;
   struct skill tornado;

   //type 1,2,3 불 물 자연   1 명칭 2획득레벨 3타입 4마법배율 5소모
   fire_ball = set_skill(fire_ball, "파이어볼",0,1,2,2);
   water_spear = set_skill(water_spear, "워터스피어",5,2,2.5,10);
   thunder_bolt = set_skill(thunder_bolt, "썬더볼트",10,3,3,15);
   stone_shower = set_skill(stone_shower, "스톤샤워",15,3,4,20);
   water_bomb = set_skill(water_bomb, "워터밤",20,2,5,30);
   fire_spear = set_skill(fire_spear, "파이어스피어",25,1,6,50);
   ice_ball = set_skill(ice_ball, "아이스볼",30,2,6,50);
   wind_cutter = set_skill(wind_cutter, "윈드커터",40,3,8,100);
   blast = set_skill(blast, "블래스트",50,1,10,150);
   blizard = set_skill(blizard, "블리자드",60,2,15,200);
   meteor = set_skill(meteor, "메테오",65,1,15,200);
   tornado = set_skill(tornado, "토네이도",70,3,15,200);
   
    struct monster orc_warrior;
    struct monster zombie;
    struct monster ghoul;
    struct monster skeleton;
    struct monster rich;
    struct monster basilisk;
    struct monster demon_Lord;

    // 0 1 2 3  무 <불< 물< 자연
    // 몹객체, 몬이름, 층 최소, 층최대, hp최소, hp최대 , 최소공격, 최대공격, 
    //방어최소, 방어최대,  약속성, 강속성, 
    orc_warrior = set_monster(orc_warrior,"오크워리어",1,2,30,80,10,20,0,0,1,2); // 강속성까지 완
    zombie = set_monster(zombie,"좀비",2,3,80,120,25,40,1,3,2,3); 
    ghoul = set_monster(ghoul,"구울",3,4,120,200,50,80,5,10,1,2); 
    skeleton = set_monster(skeleton,"해골",4,5,250,400,70,110,15,30,3,1); 
    rich = set_monster(rich,"리치",5,5,300,350,230,300,10,15,3,1); 
    basilisk = set_monster(basilisk,"바실리스크",5,5,600,900,100,130,30,50,1,2); 

    /*
마왕 방어력이 0? 그리고 용복이의 체력 *300% 추가체력이있고 중독 저주가 20% 확율

*/ 
    demon_Lord = set_monster(demon_Lord,"마왕",5,5,500,500,250,350,0,0,3,1); 



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








    struct inven
    {
        int money;
        struct sword sw[5];
        struct amor am[15];
        struct consume con[13];    
        struct refinery_material rm[5];
    };
    
    struct character
    {
        struct inven char_inven;
        struct status char_status;
    };
    /*

struct Phone {    // 휴대전화 구조체
    int areacode;                 // 국가번호
    unsigned long long number;    // 휴대전화 번호
};

struct Person {    // 사람 구조체
    char name[20];         // 이름
    int age;               // 나이
    struct Phone phone;    // 휴대전화. 구조체를 멤버로 가짐
};

    struct Person p1;

    p1.phone.areacode = 82;          // 변수.멤버.멤버 순으로 접근하여 값 할당
    p1.phone.number = 3045671234;    // 변수.멤버.멤버 순으로 접근하여 값 할당
    printf("%d %llu\n", p1.phone.areacode, p1.phone.number);    // 82 3045671234 
    */



    // 용복이 스텟 초기값!
    struct character yongbok;       //용복이 캐릭터 변수
    struct status yongbok_status;   // 용복이 상태 변수
    struct sword sword1_basic;      //용복이 무기 변수 1티어
    sword1_basic = set_sword(sword1_basic,"기본검",1,-1, 2,0,0,50,0,0);              // 기본검
    yongbok_status = set_status(yongbok_status,"용복이",1,100,20,10,0,2,5,10,10,10); // 상태
    
    struct inven invens[4];           // 용잡보제   0용복이 1잡화소 2보관소 3제련소
    invens[0].sw = sword1_basic;      
    struct inven yongbok_inven;       
    yongbok_inven.money=100;                    // 용복 돈
    yongbok.char_status = yongbok_status;       // 용복 스텟
    yongbok_inven.sw = sword1_basic;            // 용복무기 
    return 0;
    
}
