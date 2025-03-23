#include "./all_made_structed.c"
int what_do_you_want_to_store();
void store_to_shop_inven(int index_);
int get_index_for_inven_sword_array(struct inven inven_);
// test_set_item();
void bank_main();
void show_sword_what_you_got();
    

// 용복이 스텟 초기값!
struct character yongbok;       //용복이 캐릭터 변수
struct status yongbok_status;   // 용복이 상태 변수
struct sword sword1_basic;      //용복이 무기 변수 1티어
// 상태

// 일단 인벤에 칼 2자루와 갑옷 1개를 임의로 넣어보자
struct inven bank_inven;
struct inven yongbok_inven;      
struct inven invens[4];    // 용잡보제   0용복이 1잡화소 2보관소 3제련소

 //메인에서 이미 가져왔다 상정하고 아래의 값들을 가짜데이터처럼 넣었다 (레벨1짜리 용복이 천하제일? 무쌍도?)
struct sword sword3_japanese;
struct sword sword6_world_Best;
struct inven my_inven;


int main()
{   
    srand(time(NULL));
    // setting();
    //tier, index, 데미지
    sword1_basic = set_sword(sword1_basic,"기본검",1,-1, 2,0,0,50,0,0);              // 기본검
    yongbok_status = set_status(yongbok_status,"용복이",1,100,20,10,0,2,5,10,10,10); 
    sword1_basic = set_sword(sword1_basic,"기본검",1,-1, 2,0,0,50,0,0);
    sword3_japanese= set_sword(sword3_japanese,"일본도",3, -1,20,0,0,1000,0,0);
    sword6_world_Best= set_sword(sword6_world_Best,"천상천하제일무쌍도",5,-1, 100,0,0,0,0,0);
    my_inven.sw[0] = sword1_basic; // 내인벤은 칼[0],[1],[2],[3],[4]
    my_inven.sw[1] = sword3_japanese;
    my_inven.sw[2] = sword6_world_Best;
    
    invens[0] = my_inven;
               // 인벤들은 용[0],잡[1],보[2],제[3]
 
    
    yongbok_inven.money=100;                    // 용복 돈
    // yongbok.char_status = yongbok_status;       // 용복 스텟
    // 이건 마지막에 메인함수에서 수행해야할 용복인벤 <- 템프인벤
    // yongbok.char_inven = yongbok_inven; 
    bank_main();  //처리가 끝난 인벤 배열은 다시 전역변수로 가고 그 invens에서 0번 배열이 용복이 자산이된다.


    // sword_store_to_bank(bank_inven,my_inven);
    
    
    
return 0;
}
// 예상되는 함수는
// 1. user_inven의 내용을 출력하는 함수
// 2. 저장할 아이템을 shop_inven에 넣고 shop_inven을 리턴하는 함수
// 3. 변수에 있는 아이템을 찾아서 user_inven에서 제거하는 함수
// 4 .인벤에 저장된 목록을 출력하는 함수

void bank_main()
{   
    int answer;

    //물어본다 
    answer = what_do_you_want_to_store(); 

    show_sword_what_you_got();

    // 이러면  invens[0].sw[answer] 를 꺼내서 보관하고 싶단 소리다.
    store_to_shop_inven(answer);

}

// 칼 1, 방어구 2, 화폐 3, 소모품 4 리턴값은 각 구조체의 인덱스 화폐나 소모품은 0을 리턴 
void to_store()
{
    int answer_1;
    printf("보관 가능한 물품으로는 1.무기, 2방어구, 3.화폐, 4 소모품 있습니다.\n");
    printf("보관하실 물품을 선택해주세요");
    scanf("%d", &answer_1);

    if(answer_1 ==1)
    {
        struct inven visitors_inven;
        visitors_inven = invens[0];
    
        //인벤을 받아와서 뿌린다. 
        int inven_space_index_sword;
        int sw_cnt  = sizeof(visitors_inven.sw) /sizeof(struct sword);
        int index=0;
        int bank_last_index=0;
        int select;
        // get_index_for_inven_sword_array :끝 인덱스를 가져오는 함수 없으면 0 꽉차면 5겠지? 5  15
        //이 함수는 칼을 보관소에 넣기위한 함수이지 받아올 함수가 아니다.
        inven_space_index_sword = get_index_for_inven_sword_array(visitors_inven);
        
        printf("현재 손님 가방에는 칼이 %d개 있습니다.\n",inven_space_index_sword);
        for(int i=0; i<inven_space_index_sword; i++)
        {
        // 출력한다.칼의 이름을 출력한다.
        printf("%s칼이 있습니다. %d\n ", visitors_inven.sw[i].name,i+1 );
        }
        printf("꺼내실 장비를 선택해줘요");
        // printf("보관하실것이 1.칼 입니까? 2.방어구 입니까 3.화폐입니까 4.소모품 입니까?\n");
    
        int answer_2;
        printf("몇번을 꺼내시겠습니까?\n");
            
        scanf(" %d", &answer_2);
        getchar();
        answer_2-=1; // 인덱스는 0부터'
        // select=1; 
        // answer = 2;
        
        // struct sword selected_sword = user_inven.sw[answer]; //정보를 넣는다.
        
        visitors_inven = invens[0];
        printf("%s를 선택 하셨습니다.\n", visitors_inven.sw[answer_2].name);
        return answer_2;
    }


    // else if(answer_1 ==2)
    // {
        
    // }else if(answer_1 ==3)
    // {

    // }else if(answer_1 ==4)
    // {

    // }

   
//0인 경우는 화폐나 소모품이다.
    return 0;
}
void store_to_shop_inven_sw(int index_)
{

    int empty_index;
    struct inven store_inven;
    struct inven yongs_inven;
    store_inven = invens[2];
    yongs_inven = invens[0];
    empty_index = get_index_for_inven_sword_array(store_inven);
    store_inven.sw[empty_index] =  yongs_inven.sw[index_];
}

    //유저 인벤에서 특정 인덱스의 칼을 제거 
   
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