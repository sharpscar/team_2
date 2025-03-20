#include <stdio.h>
#include "0320town.h"



int main()
{
    /* 
    구조체에대한 설명https://dojang.io/mod/page/view.php?id=571
    주영님의 설명 https://cafe.naver.com/f-e/cafes/28969626/articles/54579?boardtype=L&menuid=777&referrerAllArticles=false
    책 712
    */
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
    

    // 갑옷/신발/장갑/망토/투구 공통이다.
    struct amor
    {
        int damage_reduction; //뎀감
        int damage_reduction_rage; //뎀감률 
        char name[30]; //방어구의 이름
        int price;
        int additional_damge_rate; //추뎀
    };

    struct potion
    {
        char name[30]; //방어구의 이름
        int healing_hp_rate; //회복율
        int healing_mp_rate; //회복율
        int price;
        int quantity;   //수량99개 제한
        int is_anti_posion;
        int is_blessing;
        int all_cure;
        int is_potal_scroll;        // 마을로감
        int is_teleport_scroll;     // 지정된 던전으로감

    };
    struct refinery_material
    {
        char name[30];
        int refinery_tier;
        int is_MTS; //마력응축석 Magic Condensate Stone
    };
    struct skill
    {
        char name[30];
        int get_level;
        int type; // 1 불 2 물 3자연
        int magic_rate;
        int use_mp;
    };

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
        

    }

        // 해독, 저주회복, 만병통치약, 포탈스크롤(집), 텔포스크롤(저장워프) 
        
     


    }

    

    struct inven
    {
        int wallet;
        int stat[11];
        char bag[20][20]; //캐릭터의 배낭이다.
        char consume[100][30] // 열에는 '' 이런식으로 숫자를 표기한다 더좋은방식 있으면 알려주시면 적극 수용

    };


    struct potion_inven
    {
        
        char tem[6][20];
        int quentity;
    };

    struct potion_invenmy_item = {"빨간물약","파란물약","소주","맥주","막걸리","위스키"};
    
    void set_potion(struct potion *p)

    {
        strcpy(p->tem,'')
    }



    struct inven my_visitor ={ 
        100000,
        {11,50,80,50,100,150,10,1,5,10,100,10},
        {"헤드셋","작은가방","손난로","손수건"},
        {
            {"빨간물약","11"},
            {"파란물약","51"},
            {"소주","14"},
            {"맥주","12"},
            {"막걸리","41"},
            {"위스키","1"}
        }

    
    };



    variety_store_main( &my_visitor);

}