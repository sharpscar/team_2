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

 

int main()
{   
    srand(time(NULL));
    setting();

    // 일단 인벤에 칼 2자루와 갑옷 1개를 임의로 넣어보자
    struct inven my_inven;
    struct sword sword1_basic;
    struct sword sword3_japanese;
    struct sword sword6_world_Best;


    sword1_basic = set_sword(sword1_basic,"기본검", 2,0,0,50,0,0);
    sword3_japanese= set_sword(sword3_japanese,"일본도", 20,0,0,1000,0,0);
    sword6_world_Best= set_sword(sword6_world_Best,"천상천하제일무쌍도", 100,0,0,0,0,0);    

    my_inven.sw[0] = sword1_basic;
    my_inven.sw[1] = sword3_japanese;
    my_inven.sw[2] = sword6_world_Best;
    // 가방의 더 넣을수 있는 인덱스 (5- index가 1보다 클때 구매가능)
    int inven_space_index_sword,answer;
    int sw_cnt  = sizeof(my_inven.sw) /sizeof(struct sword);
    int index=0;
    while(index<20)
    {
        if(my_inven.sw[index].uid <=0)
        {
            inven_space_index_sword = index;
            break;
        }
        index++;

    }
    //쓰고 있는 크기를 가져와서 칼의 경우는 5- inven_space_index = 더 넣을수 있는 공간입니다.


    /**
     * 세터 함수를 못씀 ㅋㅋㅋㅋㅋ 
struct inven 인벤 자료형이다.
{   my_inven.sw[i].uid <0
    int money;
    struct sword sw[5];
    struct amor am[15];
    struct consume con[1200];    
    struct refinery_material rm[100];
};
    strlen

sizeof(my_inven.sw) 의 크기만큼 반복문을 돌려서 uid가 -1 을 찾아본다. 그리고 그 인덱스를 찾아서 배열의 크기를 가늠할


     */
    //inven_space_index 칼의 남은공간을 
    // 현재 칼이 있는지 체크 해서 배열크기를 가져오고 넣을수 있는 인덱스를 가져와야함 .
    printf("현재 내 가방에는 칼이 %d개 있다.\n",inven_space_index_sword);
    for(int i=0; i<inven_space_index_sword; i++)
    {
        // 출력한다.칼의 이름을 출력한다.
        printf("%s  칼이 있습니다. 꺼내실 장비를 선택해줘요 %d 번\n", my_inven.sw[i].name, i );

    }
    
    scanf("몇번을 꺼내시겠습니까? %d ", &answer);
    /**7: void deleteStudent( student* aryStudent, int nStudentCount )  // 학생 정보 삭제
 {
         int nDelStudent; //사용자 입력값

         printf( "몇번째 학생을 삭제하실 건가요?\n" );
         scanf( "%d", &nDelStudent );

         // for 반복문의 i는 구조체 배열의 인덱스로 사용됨을 상기하시기 바랍니다^^
         for( int i=nDelStudent-1; i<nStudentCount-1; i++ )
         {
                 memcpy( &aryStudent[i], &aryStudent[i+1], sizeof( student ) );
                 // memcpy()함수는 두번째 인자에서 첫번째 인자의 주소로
                 // 세번째 인자의 크기만큼
                 // 메모리를 복사하는 함수입니다.
                 // 즉, 학생의 정보를 뒤에서 앞으로 복사하는 것이지요.
                 // 자세한 사항은 MSDN을 참고하시기 바랍니다^^;
         }
 }


     * 
     * 
     * 
     */


    



    // 그리고 그것들 모두를 출력

    // 그것들중 갑옷 1개를 맡겨보자



    // 돈은 우선 10000원으로 초기화하자 

    // 맡겨뒀던 갑옷1개를 찾아보자





    return 0;
}

struct inven bank_main(struct inven user_inven)
{
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
        
        //이중에서보관하실 물건을 골라주세요

        //1,2,3,4,5,6,7,8,9

        //1,2,3,4,5,6,7,8,9


    }else if(answer == 2)
    {
        // 화폐다.

    }

    // 은행은 돈을 저장한다.
return user_inven;
    
    // 우선 유저의 인벤토리를 불러온다.
}