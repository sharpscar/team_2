#include "./all_made_structed.c"


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


int get_index_for_inven_sword_array(struct inven inven_);
int get_index_for_inven_amor_array(struct inven inven_);
void to_store();
int ask_what_to_store();
int select_sword_index(int index_);
int select_amor_index(int index_);
void store_sword_to_bank(int sword_index); // 보관소 저장하는 함수
void store_amor_to_bank(int amor_index);
void remove_sw_from_user_inven(int index_);
void remove_amor_from_user_inven(int index_);
void show_stored_sword(int index_);
void show_stored_amor(int index_);
int select_amount();
int main()
{

    sword1_basic = set_sword(sword1_basic,"기본검",1,-1, 2,0,0,50,0,0);              // 기본검
    yongbok_status = set_status(yongbok_status,"용복이",1,100,20,10,0,2,5,10,10,10); 
    sword1_basic = set_sword(sword1_basic,"기본검",1,-1, 2,0,0,50,0,0);
    sword3_japanese= set_sword(sword3_japanese,"일본도",3, -1,20,0,0,1000,0,0);
    sword6_world_Best= set_sword(sword6_world_Best,"천상천하제일무쌍도",5,-1, 100,0,0,0,0,0);

    struct amor amor1_leather_gloves;

    amor1_leather_gloves= set_amor(
        amor1_leather_gloves,"가죽장갑",1,-1,0,0,0,50,0,0,0,0);
    struct amor amor1_leather_cloak;
    amor1_leather_cloak= set_amor(
        amor1_leather_cloak,"천망토",1,-1,0,0,0,50,0,0,0,0);
    struct amor amor4_magic_cloack;
    amor4_magic_cloack= set_amor(
        amor4_magic_cloack,"마법망토",1,-8,0,0,0,0,0,0,0,0);


    my_inven.am[0]=amor1_leather_gloves;
    my_inven.am[1]=amor1_leather_cloak;
    my_inven.am[2]=amor4_magic_cloack;
    
    my_inven.sw[0] = sword1_basic; // 내인벤은 칼[0],[1],[2],[3],[4]
    my_inven.sw[1] = sword3_japanese;
    my_inven.sw[2] = sword6_world_Best;
    
    invens[0] = my_inven;
               // 인벤들은 용[0],잡[1],보[2],제[3]
 
    
    yongbok_inven.money=100;      

// 예상되는 함수는
// 1. user_inven의 내용을 출력하는 함수
// 2. 저장할 아이템을 shop_inven에 넣고 
// 3. 변수에 있는 아이템을 찾아서 user_inven에서 제거하는 함수
// 
// 4 .인벤에 저장된 목록을 출력하는 함수

// -- 
// 5 저장한 아이템을 꺼내는 함수 
int answer = ask_what_to_store();

if (answer==1)
{
    // 유저 -> 뱅크
    int sword_index;
    sword_index = select_sword_index(0);
    store_sword_to_bank(sword_index);
    remove_sw_from_user_inven(sword_index);
    show_stored_sword(1);//저장된 물품을 보여준다.

}else if(answer ==2)
{ 
    int amor_index;
    amor_index = select_amor_index(0);
    store_amor_to_bank(amor_index);
    remove_amor_from_user_inven(amor_index);
    show_stored_amor(1);


}else if(answer == 3)
{
    int amount = select_amount();


}


    return 0;
}

int select_amount()
{
    int amount;
    printf("얼마를 입금하시겠습니까?");
    scanf("%d", &amount);
    return amount;
}
void remove_sw_from_user_inven(int index_)
{
    int cnt = 5; //칼 배열의 크기
    //용복이 인벤의 sw 배열 위치에서 선택한 인덱스부터 +1까지 값을 땡겨온다.
    struct inven yongs_inven;
    yongs_inven=invens[0];
    
    for (int i=index_; i<cnt; i++)
    {
        yongs_inven.sw[i] = yongs_inven.sw[i+1];
    }

    for (int i=index_; i<cnt; i++)
    {
        printf("현재 용복이 칼 %s\n",yongs_inven.sw[i].name);
    }
    
}
void remove_amor_from_user_inven(int index_)
{
    int cnt = 15; //방어구 배열의 크기
    //용복이 인벤의 sw 배열 위치에서 선택한 인덱스부터 +1까지 값을 땡겨온다.
    struct inven yongs_inven;
    yongs_inven=invens[0];
    printf("저장해야할 인덱스%d\n", index_);
    // 지정된 인덱스 뒤에 전부 앞으로 끌어옴  그러니까 뒤에가 다날아가는게 아니고 덮어쓴다 ^^
    for (int i=index_; i<cnt; i++)
    {
        yongs_inven.am[i] = yongs_inven.am[i+1];
    }

    for (int i=index_; i<cnt; i++)
    {
        printf("현재 용복이 방어구 %s\n",yongs_inven.am[i].name);
    }
    
}
void store_sword_to_bank(int index_)
{
    int empty_index;
    struct inven store_inven;
    struct inven yongs_inven;
    store_inven = invens[2];
    yongs_inven = invens[0];
    empty_index = get_index_for_inven_sword_array(store_inven);
    store_inven.sw[empty_index] =  yongs_inven.sw[index_];

    printf("상점 보관소에 보관된 칼 %s", store_inven.sw[0].name );
}
void store_amor_to_bank(int index_)
{
    int empty_index;
    struct inven store_inven;
    struct inven yongs_inven;
    store_inven = invens[2];
    yongs_inven = invens[0];
    empty_index = get_index_for_inven_amor_array(store_inven);
    store_inven.am[empty_index] = yongs_inven.am[index_];

    printf("상점 보관소에 보관된 방어구 %s", store_inven.am[0].name );


}
int select_sword_index(int index_)
{
    struct inven visitors_inven;
    visitors_inven = invens[index_];

    show_stored_sword(0); // 방문자의 인벤에서 꺼내는 경우 0  보관소의 인벤에서 꺼내는 경우 1
    printf("유저의 인벤에서 꺼내실 장비를 선택해줘요");
    // printf("보관하실것이 1.칼 입니까? 2.방어구 입니까 3.화폐입니까 4.소모품 입니까?\n");

    int answer_2;
    printf("몇번을 꺼내시겠습니까?\n");
        
    scanf(" %d", &answer_2);
    getchar();
    answer_2-=1; // 인덱스는 0부터'  
    visitors_inven = invens[0];
    printf("%s를 선택 하셨습니다.\n", visitors_inven.sw[answer_2].name);

    return answer_2;
    
}
// 매개변수는  invens의 인덱스 0용복 1잡 2보 3제
int select_amor_index(int index_)
{
    
    struct inven visitors_inven;
    visitors_inven = invens[index_];

    show_stored_amor(0); // 방문자의 인벤에서 꺼내는 경우 0  보관소의 인벤에서 꺼내는 경우 1
    printf("유저의 인벤에서 꺼내실 장비를 선택해줘요");
    // printf("보관하실것이 1.칼 입니까? 2.방어구 입니까 3.화폐입니까 4.소모품 입니까?\n");

    int answer_2; 
    printf("몇번을 꺼내시겠습니까?\n");
        
    scanf(" %d", &answer_2);
    getchar();
    answer_2-=1; // 인덱스는 0부터'  
    visitors_inven = invens[0];
    printf("%s를 선택 하셨습니다.\n", visitors_inven.am[answer_2].name);

    return answer_2;
        
    
}
void show_stored_sword(int index_)
{
    struct inven inven;
    inven = invens[index_];

    //인벤을 받아와서 뿌린다. 
    int inven_space_index_sword;
    int sw_cnt  = sizeof(inven.sw) /sizeof(struct sword);
    int index=0;
    int bank_last_index=0;
    int select;
    // get_index_for_inven_sword_array :끝 인덱스를 가져오는 함수 없으면 0 꽉차면 5겠지? 5  15
    //이 함수는 칼을 보관소에 넣기위한 함수이지 받아올 함수가 아니다.
    inven_space_index_sword = get_index_for_inven_sword_array(inven);
    
    printf("현재 가방에는 칼이 %d개 있습니다.\n",inven_space_index_sword);
    for(int i=0; i<inven_space_index_sword; i++)
    {
    // 출력한다.칼의 이름을 출력한다.
    printf("%s칼이 있습니다. %d\n ", inven.sw[i].name,i+1 );
    }
}
void show_stored_amor(int index_)
{
    struct inven inven;
    inven = invens[index_];

    //인벤을 받아와서 뿌린다. 
    int inven_space_index_amor;
    int amor_cnt  = sizeof(inven.am) /sizeof(struct amor);
    int index=0;
    int bank_last_index=0;
    int select;
    // get_index_for_inven_sword_array :끝 인덱스를 가져오는 함수 없으면 0 꽉차면 5겠지? 5  15
    //이 함수는 칼을 보관소에 넣기위한 함수이지 받아올 함수가 아니다.
    inven_space_index_amor = get_index_for_inven_sword_array(inven);
    
    
    for(int i=0; i<inven_space_index_amor; i++)
    {
    // 출력한다.칼의 이름을 출력한다.
    printf("%s방어구가 있습니다. %d\n ", inven.am[i].name,i+1 );
    }
}

int ask_what_to_store()
{
    int answer_1;
    printf("보관 가능한 물품으로는 1.무기, 2.방어구, 3.화폐, 4 소모품 있습니다.\n");
    printf("보관 물품 가져오기는  5.무기, 6.방어구, 7.화폐, 8 소모품 있습니다.\n");
    printf("======================================================\n");
    printf("선택해주세요 >");
    scanf("%d", &answer_1);
    return answer_1;
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
int get_index_for_inven_amor_array(struct inven inven_)
{
    int index= 0 ;
    int inven_space_index_amor=0;
    while(index<20)
    {
        // 빈배열 찾는방식 안되면 index_를 비교하거나 스위치문으로 교체 (-2상점발, -1보관소물건,1몹물건)
        if(inven_.am[index].uid <=0)
        {
            inven_space_index_amor = index;
            break;
        }
        index++;

    }
    return inven_space_index_amor;
}