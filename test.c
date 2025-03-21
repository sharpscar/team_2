#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <time.h>
#define UNIQUE_SIZE 1000
int return_min_max_random(int min_, int max_);


//최대값 최소값 랜덤 리턴하는 함수
int return_min_max_random(int min_, int max_)
{

    srand((unsigned)time(NULL));
    int r_number;
    int flag;

    r_number = (rand()% (max_-min_+1)+min_); 

    printf("%d", r_number);

    return r_number;
}


int make_unique_number();
int main()
{
    // int mynum;
    // mynum = return_min_max_random(0, 0);
    
    // 드랍아이템 함수
    struct reward drop_item
    (consum_item_rate,drop_armor_rate,drop_amor_tier,)
    {        

    }
    struct reward drop_item_boss(sword_rate,consum_item_rate,)
    {
        // 리워드선물세트는 정해지지 않았지만 인벤에 들어갈수 있는 아이템들이다. 
        // 아직 뭐가 뭔지 모르니까 4티어 하나씩 주자 나중에 30%를 구현하자

        //3티어 소비템 한개

        // 순간이동주문서
        // 4티어무기 ? 
        sword : sword4_ssaulabi 
        consume : teleport_scroll


        // 30확률 4티어 소비 (컨슘 ?)
        sword : sword5_sword_Of_Chaos //5티어 무기 ~6티어무기
        consume : white_potion  // 5티어 물약

        cosume :crazy_fire_piece// 4티어 강화재료 미친화염조각
        
        //골드 10000원
        
    }
    struct reward drop_item_real_boss(sword_rate,consum_item_rate,)
    {
        //엔딩크레딧 보여준다.
        
    }
   

    return 0;
}

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
    
