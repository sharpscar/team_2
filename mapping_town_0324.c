#include<stdio.h>
#include<stdlib.h>
#include <time.h> //time 함수를 사용하기 위한 헤더파일
#include "./all_made_structed.c"

#define SIZE 50


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
struct equip yong_equip;



int get_index_for_inven_sword_array(struct inven inven_); //보관소에 칼 저장소 인덱스 가져오기
int get_index_for_inven_amor_array(struct inven inven_);  //보관소에 방어구 저장소 인덱스 가져오기
int ask_what_to_store();                            // 뭘 보관할지 물어보는 기능
int select_sword_index(int index_);                 // 인벤의 몇번째 칼인지 인덱스를 받아서 리턴
int select_amor_index();                  // 인벤의 몇번째 방어구인지 인덱스를 받아서 리턴
void store_sword_to_bank(int sword_index);          // 보관소 칼 저장하는 함수
void widthraw_sword_to_user(int sword_index);       // 보관소 칼을 인벤으로 가져오는 함수
void store_amor_to_bank(int amor_index);            // 보관소에 방어구를 저장하는 함수
void remove_sw_from_user_inven(int index_);         // 유저의 인벤에서 칼을 제거
void remove_sw_from_store_inven(int index_);        // 보관소의 인벤에서 칼을 제거
void remove_amor_from_user_inven(int index_);       // 유저의 인벤에서 방어구를 제거
void show_stored_sword();                 // 보관 칼을 보여줌
void show_stored_amor(int index_);                  // 보관 방어구를 보여줌
int select_amount();                                // 입금액을 선택
int show_me_the_money();                            // 돈달라는 기능
void save_money_to_bank(int amount);     
int select_amount_to_bank();                                // 입금액을 선택
int select_amount_to_user();
void widthraw_money_to_bank(int amount);
void print_yongandbanks_inven();

void bank_shop();

int map[SIZE][SIZE] = {
    0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,6  //던전하고 제련소 연결 아직 안됨
};


int me[2] = { 1,  1}; //
char input = ' ';

int inven[4][100]; 
int quit_shop;
int shop_list_choice;
int item_choice;
int item_count;
int user_money = 1000;

char shop_list[] [40] = {"기본검","장검","일본도","가죽갑옷","철갑옷","가죽신발","철신발","가죽장갑","철장갑","천망토","면망토","가죽투구","철투구","빨간물약","주황물약","맑은물약","파란물약","하얀물약","무지개물약","해독제","축복주문서","마을이동주문서","순간이동주문서"};

int shop_price[23] = {50,500,10000,50,600,50,600,50,600,50,600,50,600,30,200,1000,50,300,1500,500,2000,200,1000};


void draw()
{
    system("clear");
    for (int y = 0; y < SIZE; y++)
    {
        for(int x = 0; x < SIZE; x++)
        {
            // printf("%d,", map[i][j]);
            if(me[1]==y && (me[0]==x))
            {
                printf("🦸");
            } else if(map[y][x]==1)
            {
                printf("🌲 ");     //벽
            } else if(map[y][x]==0)
            {
                printf("〰️ ");    //공백
            } else if(map[y][x]==2)
            {
                printf("🏪");    // 상가1 a -5,36               잡화점
            } else if(map[y][x]==3) 
            {
                printf("⛲");    // 상가2  b -15624 -15624      성소
            } else if(map[y][x]==4) 
            {
                printf("🏤");    // 상가3   c -12024 -11224      인챈트
            } else if(map[y][x]==5) 
            {
                printf("🏭");    // 상가4  d -12824 -17224       ??제련?(맞습니다.)
            } else if(map[y][x]==6) 
            {
                printf("⛰️");   // 던젼  e -9424 -9224      
            }
            else if(map[y][x]==7) 
            {
                printf("💰");   // 보관소  e -5 -17224      31 36        보관
            }
        }
        // printf("%d",i);//테스트
        printf("\n");
    }
}

void move() {
    if((input == 'w') && (me[1] > 0))   // w를 입력받고 내 y좌표(반복문에서 i)가 0보다 클때
    {
        me[1]--;
    }
    else if((input == 's') && (me[0] < SIZE-1))  // s를 입력받고 내 y좌표(반복문에서 i)가 9보다 클때
    {
        me[1]++;
    }
    else if((input == 'a') && (me[1] > 0))  // a를 입력받고 내 x좌표(반복문에서 j)가 0보다 클때
    {
        me[0]--;
    }
    else if((input == 'd') && (me[1] < SIZE-1))  // d를 입력받고 내 x좌표(반복문에서 j)가 9보다 클때
    {
        me[0]++;
    }
    input = ' ';
}
        
void shop() {

    // system("clear");
    printf("\t\t\t현재 보유금액: %d\n",invens[0].money=1000000);
    printf("구매하실 물건의 카테고리를 선택하세요\n\n");
    printf("1. 무기\n2. 갑옷\n3. 신발\n4. 장갑\n5. 망토\n6. 투구\n7. 물약\n8. 귀환서\n**이동 키 눌러 나가기**\n");
    scanf("%d",&shop_list_choice);
    system("clear");


    struct sword sword1_basic;
    struct sword sword2_longsword;
    struct sword sword3_japanese;

    struct inven shop_inven;

    shop_inven = invens[1];

    sword1_basic =set_sword(sword1_basic,"기본검",1,-2,2,0,0,50,0,0);    
    sword2_longsword= set_sword(sword2_longsword,"장검",2,-2, 10,0,0,500,0,0);
    sword3_japanese= set_sword(sword3_japanese,"일본도",3,-2, 20,0,0,1000,0,0);
    struct amor amor1_leather_amor;
    struct amor amor2_iron;    
    amor1_leather_amor=set_amor(amor1_leather_amor,"가죽갑옷",1,-2,0,0,0,50,0,0,0,0);
    amor2_iron=set_amor(amor2_iron,"철갑옷",1,-6,0,0,0,50,0,0,0,0);
    

    

    
    



    struct amor amor1_leather_shoes;
    struct amor amor2_iron_shoes;
    amor1_leather_shoes= set_amor(amor1_leather_shoes,"가죽신발",-2,-1,0,0,0,50,0,0,0,0);
    amor2_iron_shoes= set_amor(amor2_iron_shoes,"철신발",-2,-3,0,0,0,600,0,0,0,0);

    struct amor amor1_leather_gloves;
    struct amor amor2_iron_gloves;

    amor1_leather_gloves= set_amor(amor1_leather_gloves,"가죽장갑",-2,-1,0,0,0,50,0,0,0,0);
    amor2_iron_gloves   = set_amor(amor2_iron_gloves,"철장갑",-2,-3,0,0,0,600,0,0,0,0);



    struct amor amor1_leather_cloak;
    struct amor amor2_cotton_cloack;

    amor1_leather_cloak= set_amor(
        amor1_leather_cloak,"천망토",-2,-1,0,0,0,50,0,0,0,0);
    amor2_cotton_cloack= set_amor(
        amor2_cotton_cloack,"면망토",-2,-3,0,0,0,600,0,0,0,0);

    

    struct amor amor1_leather_helmet;
    struct amor amor2_iron_helmet;

    amor1_leather_helmet= set_amor(
        amor1_leather_helmet,"가죽투구",-2,-1,0,0,0,50,0,0,0,0);
    amor2_iron_helmet= set_amor(
        amor2_iron_helmet,"철투구",-2,-3,0,0,0,600,0,0,0,0);
    
    struct consume red_potion;
    struct consume orange_potion;
    struct consume clean_potion;
    struct consume blue_potion;
    struct consume white_potion;
    struct consume rainbow_potion;
    red_potion = set_consume(red_potion,"레드포션",30,0,30,0,0,0,0,0,0);
    orange_potion = set_consume(orange_potion,"주황물약",60,0,200,0,0,0,0,0,0);
    clean_potion = set_consume(clean_potion,"맑은물약",80,0,1000,0,0,0,0,0,0);
    blue_potion = set_consume(blue_potion,"파란물약",0,30,50,0,0,0,0,0,0);
    white_potion = set_consume(white_potion,"하얀물약",0,60,300,0,0,0,0,0,0);
    rainbow_potion = set_consume(rainbow_potion,"무지개물약",0,80,1500,0,0,0,0,0,0);
     
    shop_inven.con[0]=red_potion;
    shop_inven.con[1]=orange_potion;
    shop_inven.con[2]=clean_potion;
    shop_inven.con[3]=blue_potion;
    shop_inven.con[4]=white_potion;
    shop_inven.con[5]=rainbow_potion;

    
    struct consume anti_toxic;
    struct consume blessing_scroll;    
    struct consume potal_scroll;
    struct consume teleport_scroll;
    anti_toxic = set_consume(anti_toxic,"해독제",0,0,500,0,0,0,0,0,0);
    blessing_scroll = set_consume(blessing_scroll,"축복주문서",0,0,2000,0,1,0,0,0,0);
    potal_scroll = set_consume(potal_scroll,"마을이동주문서",0,0,200,0,0,0,0,1,0);
    teleport_scroll = set_consume(teleport_scroll,"순간이동주문서",0,0,1000,0,0,0,0,0,0);
    shop_inven.con[6] =anti_toxic;
    shop_inven.con[7] =blessing_scroll;
    shop_inven.con[8] =potal_scroll;
    shop_inven.con[9] =teleport_scroll;



    int cnt = 0;

    while(1)
    {
        if (shop_list_choice == 1){  //무기
            for (int i = 0; i< 3; i++){
                printf("%d. %s:\t\t(%d GOLD)\n",i,shop_list[i],shop_price[i]);
            }
        }
        else if (shop_list_choice == 2){ //갑옷
            for (int i = 3; i< 5; i++){
                printf("%d. %s:\t\t(%d GOLD)\n",i,shop_list[i],shop_price[i]);
            }
        }
        else if (shop_list_choice == 3){
            for (int i = 5; i< 7; i++){
                printf("%d. %s:\t\t(%d GOLD)\n",i,shop_list[i],shop_price[i]);
            }
        }
        else if (shop_list_choice == 4){
            for (int i = 7; i< 9; i++){
                printf("%d. %s:\t\t(%d GOLD)\n",i,shop_list[i],shop_price[i]);
            }
        }
        else if (shop_list_choice == 5){
            for (int i = 9; i< 11; i++){
                printf("%d. %s:\t\t(%d GOLD)\n",i,shop_list[i],shop_price[i]);
            }
        }
        else if (shop_list_choice == 6){
            for (int i = 11; i< 13; i++){
                printf("%d. %s:\t\t(%d GOLD)\n",i,shop_list[i],shop_price[i]);
            }
        }        
        else if (shop_list_choice == 7){
            for (int i = 13; i< 21; i++){
                printf("%d. %s:\t\t(%d GOLD)\n",i,shop_list[i],shop_price[i]);
            }
        }
        else if (shop_list_choice == 8){
            for (int i = 21; i< 23; i++){
                printf("%d. %s:\t\t(%d GOLD)\n",i,shop_list[i],shop_price[i]);
            }
        }
        else
            break;
        printf("\n구매하실 상품의 번호를 입력하세요: (나가기: 23)");
        scanf("%d",&item_choice);
        
        if (item_choice ==23){
            break;
        }
        if (item_choice < 0 || item_choice >= 23) {
            printf("유효하지 않은 번호입니다.\n");
            continue;
        }

        printf("수량을 입력하세요: ");
        scanf("%d",&item_count);


        if ((shop_price[item_choice])*item_count > invens[0].money)
            printf("잔액이 부족합니다.\n");
        else{
            printf("%s %d개 구매하였습니다.\n\n",shop_list[item_choice],item_count);
            invens[0].money -= (shop_price[item_choice])*item_count;
            printf("현재 보유금액: %d\n",invens[0].money);

            
            
            
            if(item_choice ==0)
            {
                invens[0].sw[cnt] = sword1_basic;
            }else if(item_choice ==1)
            {
                invens[0].sw[cnt]= sword2_longsword;
            }else if(item_choice ==2)
            {
                invens[0].sw[cnt]= sword3_japanese;

            }else if(item_choice ==3)
            {
                invens[0].am[cnt] = amor1_leather_amor;
            }else if(item_choice ==4)
            {
                invens[0].am[cnt] = amor2_iron;
            }else if(item_choice ==5)
            {
                invens[0].am[cnt] = amor1_leather_shoes;
            }
            else if(item_choice ==6)
            {
                invens[0].am[cnt] = amor2_iron_shoes;
            }
            else if(item_choice ==7)
            {
                invens[0].am[cnt] = amor2_iron_gloves;
            }else if(item_choice ==8)
            {
                invens[0].am[cnt] = amor1_leather_cloak;
            }else if(item_choice ==9)
            {
                invens[0].am[cnt] = amor2_iron_gloves;
            }else if(item_choice ==10)
            {
                invens[0].am[cnt] = amor2_cotton_cloack;
            }
            else if(item_choice ==11)
            {
                invens[0].am[cnt] = amor1_leather_helmet;
            }else if(item_choice ==12)
            {
                invens[0].am[cnt] = amor2_iron_helmet;
            }else if(item_choice ==13)
            {
                invens[0].con[cnt] = red_potion;
            }else if(item_choice ==13)
            {
                invens[0].con[cnt] = orange_potion;
            }else if(item_choice ==14)
            {
                invens[0].con[cnt] = clean_potion;
            }else if(item_choice ==15)
            {
                invens[0].con[cnt] = blue_potion;
            }else if(item_choice ==16)
            {
                invens[0].con[cnt] = white_potion;
            }else if(item_choice ==17)
            {
                invens[0].con[cnt] = rainbow_potion;
            }else if(item_choice ==18)
            {
                invens[0].con[cnt] = anti_toxic;
            }else if(item_choice ==19)
            {
                invens[0].con[cnt] = blessing_scroll;
            }else if(item_choice ==20)
            {
                invens[0].con[cnt] = potal_scroll;
            }else if(item_choice ==21)
            {
                invens[0].con[cnt] = teleport_scroll;
            }

            // test_code
            // printf("구매한거         %s\n", shop_list[item_choice]);

            // printf("인벤에 sw, am 나눠서 배열의 2개씩만 보여주자\n");
            // printf("%s  %s", invens[0].sw[0].name,invens[0].sw[1].name);
            // printf("%s  %s", invens[0].am[0].name,invens[0].am[1].name);

        }

        printf("더 구매 하시겠습니까?: \n0.예\n1.아니오\n");
        scanf("%d",&quit_shop);
        if (quit_shop == 1)
        {
            break;
        }  
        cnt ++;             
    }
}

void church(){
    struct status yongboks_s;
    
                     
    yongboks_s = set_status(yongboks_s,    "용복이",1,100,10,20,10,10,5,10,10,10);  //맨 뒤 3개가 10,10,10이나 초기화 되는지 확인 위해 10,20,10으로 바꿈요
    int stats_sum = yongboks_s.str + yongboks_s.int_ + yongboks_s.dex;
    int church_choice;  //치유 or 스탯초기화
    int church_stats_yn; //스탯초기화 여부
    int church_quit_yn; //종료여부 - 종료시 성소 나감, 아닌경우 초기창
    int user_hp = 30; //임의값
    int user_mp = 5; //임의값
    // int max_user_hp = 100;  //임의값
    // int max_user_mp = 10; //임의값
    
    while(1){
        printf("성소에 도착했습니다.\n");
        printf("치유: 0\n스탯초기화: 1\n\n***이동 키 눌러 나가기***\n");  //맵에서는 이동키 눌러 나가기가 작동됩니다.
        scanf("%d",&church_choice);
        system("clear");

        if (church_choice == 0){  //치유를 선택한 경우
            user_hp =  yongboks_s.hp;  //현재 유저의 hp를 용복스의 최대 hp값으로 바꿔줍니다.
            user_mp = yongboks_s.mp;  //현재 유저의 mp를 용복스의 최대 mp값으로 바꿔줍니다.
            printf("치유되었습니다.\n");
            printf("hp: %d mp: %d\n",user_hp,user_mp);
            printf("---------------------------------\n0. 성소 나가기   1. 초기창으로 돌아가기\n");
            scanf("%d",&church_quit_yn);  
                if (church_quit_yn == 0)  //나가는 경우 완전히 종료
                    break;
                else if (church_quit_yn == 1);  // 루프 돌아서 초기창이 나옵니다.
                    continue;
        }
        if (church_choice == 1){
            printf("스탯의 합계: %d\n",stats_sum);  //현재 스탯의 합계를 구합니다.
            printf("STR: %d INT: %d DEX: %d\n",yongboks_s.str,yongboks_s.int_,yongboks_s.dex);  //초기화전 힘인덱을 출력합니다.
            printf("스탯을 초기화하시겠습니까?\n1.네\n2.아니오(초기창으로 돌아갑니다.)\n");
            scanf("%d",&church_stats_yn);  
            if (church_stats_yn == 1){  //초기화를 선택한 경우
                yongboks_s.str = 10;   //레벨업하면서 찍은 추가 스탯은 level-1로 계산하여 추가로 찍을 수 있게 한다는 가정하에
                yongboks_s.int_= 10;  //10,10,10으로 초기화하겠습니다.
                yongboks_s.dex = 10;
                printf("초기화되었습니다.\n");
                printf("추가로 찍을 수 있는 포인트: %d)\n",stats_sum - 30);  //초기화 전 합계 ex총 40스탯이었다고 한다면 초기값 계 30을 빼고 추가로 찍을 수 있는 포인트를 따로 출력함
                printf("STR: %d INT: %d DEX: %d\n",yongboks_s.str,yongboks_s.int_,yongboks_s.dex);
                printf("---------------------------------\n0. 성소 나가기   1. 초기창으로 돌아가기\n");
                scanf("%d",&church_quit_yn);
                    if (church_quit_yn == 0)
                        break;
                    else if (church_quit_yn == 1);
                        continue;
            }
            if (church_stats_yn == 2)
                continue;
        }       
    }
}
//dddddddddddddddddddddddddddddddddddddssssssssssssssssssssssssssssssssss

void enchant_shop()  
{

    int my_stone = 11;
    int rand_,result;
    int enchant_yn;
    int require_stone = 10;
    char enchant_rand[][10] = {"물","불","자연"}; 
    printf("인챈트 가게 입니다.\n인챈트기 마력응축석 10개가 소모됩니다\n\n");
    
    printf("보유 마력 응축석: %d\n강화를 진행하시겠습니까?: \n0.아니오  1. 네\n", my_stone);

    scanf("%d",&enchant_yn);
    
    while(getchar() != '\n');
    if (enchant_yn)
    {
        if(my_stone < 10) printf("재료가 부족합니다.\n");
        else if (my_stone >= 10)
        {
            rand_ = (rand() % 3);
            printf("무기에 %s 속성이 인챈트 되었습니다.\n",enchant_rand[rand_]);
            my_stone -= 10;
            printf("남은 마력응축석:%d",my_stone);
        }
        getchar();

    }
}

void event() {
    if ((me[0] == 36) && (me[1] == 5)) 
    {
        // printf("🏪");    // 상가1 a -5,36               잡화점
        system("clear");
        shop();
        me[0] = 35;
    }
    if ((me[0] == 17) && (me[1] == 17))
    {
        system("clear");
        church(); // -15624 -15624      성소
        me[0] = 16;
    }
    if ((me[0] == 39) && (me[1] == 35))   //인챈트
    {
       system("clear");
        enchant_shop();
        me[0] = 38;
    }

    if ((me[0] == 36) && (me[1] == 31))
    {
        yongbok.character_status=set_status(yongbok_status,"용복이",1,100,20,10,0,2,5,10,10,10); 
        // sword1_basic = set_sword(sword1_basic,"기본검",1,-1, 2,0,0,50,0,0);
        // yongbok_inven.sw[0] = sword1_basic;
        
        yongbok.character_inven=invens[0];
        // - 기본상태
        yong_equip.sw = sword1_basic;
    
        yongbok_inven.money = 1000000;
        invens[0].sw[0] = sword1_basic; // 내인벤은 칼[0],[1],[2],[3],[4]

        // system("clear");
        // enchant_shop();
        bank_shop();

        me[0] = 34;
    }
}




void bank_shop()
{
    // 기본검
    yongbok_status = set_status(yongbok_status,"용복이",1,100,20,10,0,2,5,10,10,10); 
    int answer = ask_what_to_store();

    if (answer==1)
        {
            // 칼선택
            // 유저 -> 뱅크
            
            int sword_index;
            sword_index = select_sword_index(0); //칼선택

            store_sword_to_bank(sword_index);       //보관함에 선택한 칼을 보관
            remove_sw_from_user_inven(sword_index); // 유저 인벤에서 해당 칼을 제거
            // show_stored_sword();                    //인벤에 저장된 물품을 보여준다.          
            print_yongandbanks_inven();
        
        }else if(answer ==2)
        { 
            int amor_index;
            amor_index = select_amor_index();
            store_amor_to_bank(amor_index);
            remove_amor_from_user_inven(amor_index);
            //유저인벤에서 빼고나서 확인

            // show_stored_amor(1);
            //보관소 인벤에서 빼고나서 확인       

            print_yongandbanks_inven();
        
        }else if(answer == 3)
        {
            // 갖고있는 돈을 보여주자
        
            int visitors_property = show_me_the_money();
            printf("현재 계좌예 $ %d원 있습니다.", visitors_property);        
            int amount = select_amount_to_bank();
            save_money_to_bank(amount);            
        
        }else if(answer ==4 )
        {
            printf("소모품은 미안하지만 구현이 덜되었습니다. 보관말고 일단 마시세요");
        }
        

        else if(answer ==5)
        {
            //보관되어있는 물품을 꺼낸다. 
            int sword_index;

            sword_index = select_sword_index(2);
            widthraw_sword_to_user(sword_index);
            remove_sw_from_store_inven(sword_index);

            print_yongandbanks_inven();
        
        }
        else if(answer ==6)
        {
            //보관되어있는 물품을 꺼낸다. 
            int amor_index;

            amor_index = select_amor_index(2);
            widthraw_sword_to_user(amor_index);
            remove_sw_from_store_inven(amor_index);

            print_yongandbanks_inven();
        
        }else if(answer == 7)
        {
            //은행돈 빼가기
        
            int visitors_property = show_me_the_money();
            printf("현재 계좌예 $ %d원 있습니다.", visitors_property);
        
            int amount = select_amount_to_user();
            widthraw_money_to_bank(amount);
        }

    

}
void widthraw_money_to_bank(int amount)
{
    invens[1].money = invens[1].money - amount;
    invens[0].money = invens[0].money + amount;
}

int select_amount_to_bank()
{
    int amount;
    printf("얼마를 입금하시겠습니까?");
    scanf("%d", &amount);
    return amount;
}
int select_amount_to_user()
{
    int amount;
    printf("얼마를 출금하시겠습니까?");
    scanf("%d", &amount);
    return amount;
}

void remove_sw_from_user_inven(int index_)
{
    int cnt = 5; //칼 배열의 크기
    //용복이 인벤의 sw 배열 위치에서 선택한 인덱스부터 +1까지 값을 땡겨온다.
    struct inven yongs_inven;
    
    
    for (int i=index_; i<cnt; i++)
    {
        invens[0].sw[i] = invens[0].sw[i+1];
    }

    for (int i=0; i<cnt; i++)
    {
        // printf("현재 용복이 칼 %s\n",yongs_inven.sw[i].name);
    }
    
}

void print_yongandbanks_inven()
{
    printf("용복이의 가방의 칼 목록\n");
    printf("===================\n");
    for(int i=0; i<10; i++)
    {
        printf("%s\n",invens[0].sw[i].name);
    }
    printf("용복이의 가방의 방어구 목록\n");
    printf("===================\n");

    for(int i=0; i<10; i++)
    {
        printf("%s\n",invens[0].am[i].name);
    }

    printf("보관소의 가방의 칼 목록\n");
    printf("===================\n");
    for(int i=0; i<10; i++)
    {
        printf("%s\n",invens[2].sw[i].name);
    }
    printf("보관소의 가방의 방어구 목록\n");
    printf("===================\n");

    for(int i=0; i<10; i++)
    {
        printf("%s\n",invens[2].am[i].name);
    }
    
    
}


void save_money_to_bank(int amount)
{
    invens[1].money = invens[1].money + amount;
    invens[0].money = invens[0].money - amount;
}
void remove_amor_from_user_inven(int index_)
{
    int cnt = 15; //방어구 배열의 크기
    //용복이 인벤의 sw 배열 위치에서 선택한 인덱스부터 +1까지 값을 땡겨온다.
    struct inven yongs_inven;
    
    printf("저장해야할 인덱스%d\n", index_);
    // 지정된 인덱스 뒤에 전부 앞으로 끌어옴  그러니까 뒤에가 다날아가는게 아니고 덮어쓴다 ^^
    for (int i=index_; i<cnt; i++)
    {
        invens[0].am[i] = invens[0].am[i+1];
    }

    for (int i=index_; i<cnt; i++)
    {
        printf("현재 용복이 방어구 %s\n",yongs_inven.am[i].name);
    }
    
}

void remove_sw_from_store_inven(int index_)
{
    
    int cnt = 5; //칼 배열의 크기
    //용복이 인벤의 sw 배열 위치에서 선택한 인덱스부터 +1까지 값을 땡겨온다.
    struct inven store_inven;
    store_inven=invens[2];

   
    // 지정된 인덱스 뒤에 전부 앞으로 끌어옴  그러니까 뒤에가 다날아가는게 아니고 덮어쓴다 ^^
    for (int i=index_; i<cnt; i++)
    {
        invens[2].sw[i] = invens[2].sw[i+1];
    }

}
//용인벤에서 선택한 인덱스의 칼을 보관함에 넣는코드
void store_sword_to_bank(int index_)
{   
    
    int empty_index;
    struct inven store_inven;
    empty_index = get_index_for_inven_sword_array(store_inven);
    invens[2].sw[empty_index] =  invens[0].sw[index_];

    // printf("상점 보관소에 보관된 칼 %s", store_inven.sw[0].name );
}

// 보관된 칼을 유저에게 되돌려주는코드
void widthraw_sword_to_user(int index_)
{
    int empty_index;
    empty_index = get_index_for_inven_sword_array(invens[0]);
    invens[0].sw[empty_index] =  invens[2].sw[index_];

}
void store_amor_to_bank(int index_)
{
    int empty_index;
    struct inven store_inven;
    struct inven yongs_inven;
    store_inven = invens[2];
    yongs_inven = invens[0];
    empty_index = get_index_for_inven_amor_array(store_inven);
    invens[2].am[empty_index] =  invens[0].am[index_];    
}
int show_me_the_money()
{
    struct inven visitors_inven;
    
    return invens[0].money;
}
int select_sword_index(int index_)
{
    struct inven visitors_inven;
    visitors_inven = invens[index_];

    show_stored_sword(0); // 방문자의 인벤에서 꺼내는 경우 0  보관소의 인벤에서 꺼내는 경우 1
    printf("인벤에서 꺼내실 장비를 선택해줘요");
    // printf("보관하실것이 1.칼 입니까? 2.방어구 입니까 3.화폐입니까 4.소모품 입니까?\n");

    int answer_2;
    printf("몇번을 꺼내시겠습니까?\n");
        
    scanf(" %d", &answer_2);
    getchar();
    answer_2-=1; // 인덱스는 0부터'  
    
    printf("%s를 선택 하셨습니다.\n", invens[0].sw[answer_2].name);

    return answer_2;
    
}
// 매개변수는  invens의 인덱스 0용복 1잡 2보 3제
int select_amor_index()
{
    
    struct inven visitors_inven;
    visitors_inven = invens[2];

    show_stored_amor(0); // 방문자의 인벤에서 꺼내는 경우 0  보관소의 인벤에서 꺼내는 경우 1
    printf("유저의 인벤에서 꺼내실 장비를 선택해줘요");
    // printf("보관하실것이 1.칼 입니까? 2.방어구 입니까 3.화폐입니까 4.소모품 입니까?\n");

    int answer_2; 
    printf("몇번을 꺼내시겠습니까?\n");
        
    scanf(" %d", &answer_2);
    getchar();
    answer_2-=1; // 인덱스는 0부터'  
    
    printf("%s를 선택 하셨습니다.\n", invens[0].am[answer_2].name);

    return answer_2;
        
    
}
void show_stored_sword()
{
    struct inven inven;
    inven = invens[2];

    //인벤을 받아와서 뿌린다. 
    int inven_space_index_sword;
    int sw_cnt  = sizeof(inven.sw) /sizeof(struct sword);
    int index=0;
    int bank_last_index=0;
    int select;
    // get_index_for_inven_sword_array :끝 인덱스를 가져오는 함수 없으면 0 꽉차면 5겠지? 5  15
    //이 함수는 칼을 보관소에 넣기위한 함수이지 받아올 함수가 아니다. 인덱스는 0아니면 2
    inven_space_index_sword = get_index_for_inven_sword_array(inven);
    
    printf("현재 가방에는 칼이 %d개 있습니다.\n",inven_space_index_sword);
    for(int i=0; i<inven_space_index_sword; i++)
    {
    // 출력한다.칼의 이름을 출력한다.
    printf("%s칼이 있습니다. %d\n ", inven.sw[i].name,i+1 );
    }
    print_yongandbanks_inven();
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
        // 빈배열 찾는방식 안되면 index_를 비교하거나 스위치문으로 교체 (최초 전부 -2로 설정 )
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
        if(inven_.am[index].uid<=0)
        {
            inven_space_index_amor = index;
            break;
        }
        index++;

    }
    return inven_space_index_amor;
}

int main()
{
    sword1_basic = set_sword(sword1_basic,"기본검",1,-1, 2,0,0,50,0,0);

    
    invens[0].sw[0] = sword1_basic;
    while (input != 'q') 
    {
        
        draw();
        scanf("%c", &input);
        move();
        event();  // 여기서 참조하는중
    }
    return 0;

}


/* 상점가기
dddddddddddddddddddddddddddddddddddssss
성소가기
ddddddddddddddddssssssssssssssss
인챈트샵
dddddddddddddddddddddddddddddddddddddssssssssssssssssssssssssssssssssss
*/

        
