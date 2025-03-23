#include "./all_made_structed.c"

// #define UNIQUE_SIZE 1000

// struct sword
// {
//     int tier;
//     int uid;
//     char name[30]; //칼의 이름
//     int damage;
//     int enforce; //강화
//     int attribute; //속성 0 1 2 3 4
//     int price;
//     int cri_rate;
//     int magic_rate; //마법배율? 뭐에쓰는 녀석인고?

// };
// // 갑옷/신발/장갑/망토/투구 공통이다.
// struct amor
// {
//     int uid;
//     int enforce;
//     int attribute; //속성 0 1 2 3 4   갑옷에 속성을 넣은 이유는 몬스터가 속성공격 할수 도 있게 미리 미리!!
//     char name[30]; //방어구의 이름
//     int tier;
//     int price;
//     int damage_reduction; //뎀감
//     int damage_reduction_rate; //뎀감률 
//     int additional_damge_rate; //추가 데미지 비율
//     int additional_ac_rate;    //추가 회피율
//     int additional_cri_rate;   //추가 치명타율
//     int is_debuff; // 거의 모든 템은 상태이상을 제어할수 없지만 템1개는 ㅠ

// };

// // unique number 생성기
// int make_unique_number()
// {    
//     // int rotto[SIZE];
//     int r_number;
//     int flag;
//     int unique_number_list[UNIQUE_SIZE];
  
//     srand((unsigned)time(NULL));

//     r_number = (rand()% UNIQUE_SIZE) +1; 

//     // is_in 을 호출해야함 
//     for (int i=0; i<=sizeof(unique_number_list)/sizeof(int) ;i++)
//     {
//         if (r_number!= unique_number_list[i])
//         {    
//             unique_number_list[i] = r_number;            
//         }
        
//     }
//     return r_number;
// }


// struct consume
// {
//     char name[30]; //방어구의 이름
//     int healing_hp_rate; //회복율
//     int healing_mp_rate; //회복율
//     int price;
//     int quantity;   //수량99개 제한
//     // char special[5][30];
//     int anti_posion;    //해독제
//     int is_blessing;        //축복
//     int is_all_cure;        //만병통치약
//     int is_potal_scroll;    // 마을로감
//     int is_teleport_scroll; // 지정된 던전으로감

// };

// struct refinery_material
// {
//     char name[30];
//     int refinery_tier;
//     int is_MTS; //마력응축석 Magic Condensate Stone
//     int quantity;
// };



// struct sword  set_sword(struct sword s, 
//     char s_name[],
//     int damage,
//     int enforce,
//     int attribute, 
//     int price,
//     int cri_rate, 
//     int magic_rate)
// {
//     strcpy(s.name, s_name);
//     s.uid = make_unique_number();
//     s.damage = damage;
//     s.enforce= enforce;
//     s.attribute = attribute;
//     s.price = price;
//     s.cri_rate = cri_rate;
//     s.magic_rate = magic_rate;    
//     return s;
// }

// struct inven
// {
//     int money;
//     struct sword sw[5];
//     struct amor am[15];
//     struct consume con;    
//     struct refinery_material rm;
// };

void  sword_store_to_bank(struct inven, struct inven);
int get_index_for_inven_sword_array(struct inven inven_);
struct inven test_set_item();
int main()
{   
    srand(time(NULL));
    // setting();
    

    // 일단 인벤에 칼 2자루와 갑옷 1개를 임의로 넣어보자
    struct inven bank_inven;
    struct inven my_inven;
    struct sword sword1_basic;
    struct sword sword3_japanese;
    struct sword sword6_world_Best;
/**
 * struct sword
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
 */

    sword1_basic = set_sword(sword1_basic,"기본검",1,-1, 2,0,0,50,0,0);
    sword3_japanese= set_sword(sword3_japanese,"일본도",3, -1,20,0,0,1000,0,0);
    sword6_world_Best= set_sword(sword6_world_Best,"천상천하제일무쌍도",5,-1, 100,0,0,0,0,0);    

    //임의로 가짜데이터를 넣어봄 - uid는 잡아야할 버그: 중복된 유니크키?
    my_inven.sw[0] = sword1_basic;
    my_inven.sw[1] = sword3_japanese;
    my_inven.sw[2] = sword6_world_Best;
    // 가방의 더 넣을수 있는 인덱스 (5- index가 1보다 클때 구매가능)

    sword_store_to_bank(bank_inven,my_inven);
    
    
    
return 0;
}


struct inven bank_main(struct inven user_inven)
{
/*
    
    이전에 sturct inven 이라는 구조체를 만들었습니다.

보관소를 만들던중에 함수는 한번에 2개 이상의 변수를 리턴할수 없다 라는 문제에 부딫혔는데요

해결방안으로 떠오른걸 작성합니다.

1. user_inven 에 저장되어 있는 아이템들을 출력한다.
2.아이템들 중에 보관할 아이템을 고른다. (유저 입력)
3. 해당 아이템을 임시 저장 변수에 저장
4. 임시저장한 아이템을 shop_inven에 넣는다.
5. 임시저장한 아이템을 user_inven에서 제거한다.
6 저장된 아이템을 출력한다.



예상되는 함수는
1. user_inven의 내용을 출력하는 함수
2. 저장할 아이템을 shop_inven에 넣고 shop_inven을 리턴하는 함수
3. 변수에 있는 아이템을 찾아서 user_inven에서 제거하는 함수
4 .인벤에 저장된 목록을 출력하는 함수
    */


    int answer;
    
    struct inven bank_stored_inven;
    //은행에 관한 업무를 하는 함수다.

    // 짧막하게 인사한다. 
    printf("용사님 안녕하세요. 보관소에 오신걸 환영합니다.\n");
    printf("보관하실것이 1.물품입니까? 2.화폐입니까?\n");

    scanf("%d", &answer);
    
    
    if (answer == 1)
    {   
        // 만약 보관소의 물품의 크기가 100개가 넘으면 더이상 보관이 안된다는 메시지를 한다.
        
        // 유저의 인벤에서 물건들을 뿌려준다. 
        // 물품 보관함수 call


    }else if(answer == 2)
    {
        // 화폐다.

    }

    // 은행은 돈을 저장한다.
return user_inven;
    
    // 우선 유저의 인벤토리를 불러온다.
}


struct inven store_sword_to_banks_inven(struct inven user_inven, struct inven bank_inven)
{
    //유저 인벤을 매개변수로 받아서 선택한 칼의 인덱스를
    //이용해서 해당 칼 정보를 가져온다
    // 가져온 정보를 은행의 인벤에 삽입
    // 은행 인벤의 sw배열_마지막 빈배열 위치를 조회  
    //  삽입  << 여기까지 저장
    

    // 유저의 인벤 구조체안의 칼(구조체) 배열에서 삭제 ㅎㅎ
    // 삭제하는 코드
    /*
    i는 삭제해야할 인덱스다 cnt는 해당 배열의 크기
    for(int j=i; j<cnt-1; j++)
    {
        list[j] = list[j+1];
    }
    */

return bank_inven;

}

    void sword_store_to_bank(struct inven bank_inven, struct inven user_inven)
    {
        int inven_space_index_sword;
        int sw_cnt  = sizeof(user_inven.sw) /sizeof(struct sword);
        int index=0;
        int bank_last_index=0;
        int select;

        printf("%d 귀신곡하겠네1 \n ",user_inven.sw[0].uid);
        printf("%d 귀신곡하겠네1\n ",user_inven.sw[1].uid);
        printf("%d 귀신곡하겠네1 \n ",user_inven.sw[2].uid);

        // get_index_for_inven_sword_array :끝 인덱스를 가져오는 함수 없으면 0 꽉차면 5겠지? 5  15
        //이 함수는 칼을 보관소에 넣기위한 함수이지 받아올 함수가 아니다.
        inven_space_index_sword = get_index_for_inven_sword_array(user_inven);
        
        printf("현재 내 가방에는 칼이 %d개 있다.\n",inven_space_index_sword);
        for(int i=0; i<inven_space_index_sword; i++)
        {
            // 출력한다.칼의 이름을 출력한다.
            printf("%s  칼이 있습니다. 꺼내실 장비를 선택해줘요 %d 번\n", user_inven.sw[i].name, i+1 );

        }
        printf("몇번을 꺼내시겠습니까?\n");
        
        scanf(" %d", &select);
        getchar();
        select-=1; // 인덱스는 0부터'
        // select=1; 
        // answer = 2;
        printf("=====================> %d\n" , select);
        // struct sword selected_sword = user_inven.sw[answer]; //정보를 넣는다.

        printf("%s를 선택 하셨습니다.\n", user_inven.sw[select].name);
        //은행 인벤에 sw 리스트의 인덱스를 가져온다. 
        bank_last_index = get_index_for_inven_sword_array(bank_inven);

        printf("%d", bank_last_index);
        bank_inven.sw[bank_last_index] = user_inven.sw[select];

        //유저 인벤에서 특정 인덱스의 sw를 제거하는 함수
       
        

        // return bank_inven; //bank_inven;
    }

    //유저 인벤에서 특정 인덱스의 칼을 제거 
    struct inven get_rid_of_sword_from_user_inven(user_inven, select)
    {
        
    }
   int get_index_for_inven_sword_array(struct inven inven_)
    {
        int index= 0 ;
        int inven_space_index_sword=0;
        while(index<20)
        {
            // 빈배열 찾는방식 안되면 index_를 비교하거나 스위치문으로 교체 (-2상점발, -1보관소물건,1몹물건)
            if(inven_.sw[index].uid <=0)
            {
                inven_space_index_sword = index;
                break;
            }
            index++;

        }
        return inven_space_index_sword;
    }