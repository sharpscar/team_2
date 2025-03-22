#include <stdio.h>


//아이템창 만들기 최대 99개
// {아이템}
// [소비]
// 1. 빨간물약 체력 회복(30%) 30원
// 2. 주황물약 체력 회복(60%) 200원
// 3. 맑은물약 체력 회복(80%) 1000원
// 1. 파란물약 마나 회복(30%) 50원
// 2. 하얀물약 마나 회복(60%) 300원
// 3. 무지개물약 마나 회복(80%) 1500원
// ​​4. 엘릭서 모든 HP와 MP를 완전 회복한다.
// 2. 해독제 중독상태 회복 500원
// 3. 축복 주문서 저주상태 회복 2000원
// 4. 만병통치약 모든 상태이상 회복 
// 1. 마을이동주문서 마을로 이동함 200원
// 2. 순간이동주문서 지정한 위치로 이동함 1000원
// >> 하나를 사용하면 갯수에서 하나씩 차감된다. 
//test 방금내가 쓴거 
// aaa
//----------------------변수-------------------------

char put_q; //확인창
int check_box; // 확인창에서 번호선택


//용복이상태창 변수
char status[10][20] = {"체력","마력","공격력","마법공격력","회피율","힘","지능","손재주","방어력","치명타율"};
int status_info[20] = {100,10,20,10,0,2,5,10,10,10};

//아이템창 변수
char potion[12][30] = {"빨간물약","주황물약","맑은물약","파란물약","하얀물약","무지개물약","엘릭서","해독제","축복주문서","만병통치약","마을이동주문서","순간이동주문서"};
int count = 0;
int potion_count[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
int potion_total = 99;

//강화재료창 변수
char fire_piece[5][30] = {"작은화염조각","푸른화염조각","강렬한화염조각","미친화염조각","마력응축석"};
int fire_up_grade[5] = {3,6,9,10,0}; //장비 강화하는 최대수 적어놓음.




//-----------------------함수선언-----------------------

int yongbok_status(); // 용복이 상태창
int consume(); // 아이템창
int refinery_material(); // 강화재료창




//-----------------------함수호출------------------------

int main()
{
    while(1){
        printf("확인창을 여시려면 'q'를 눌러주세요.\n>>");
        scanf("%s",&put_q);
        if (put_q != 'q'){
            continue;
        }
        printf("번호를 입력해주세요.\n 1. 상태창 2. 인벤토리 3. 아이템사용 4. 강화재료 5.나가기\n>>");
        scanf("%d",&check_box);

        if((check_box>5)||(check_box < 1)){
            printf("유효한 입력이 아닙니다. 초기화면으로 돌아갑니다.\n\n");
            continue;
        }
        if((check_box<=5)&&(check_box >= 1)){
            if(check_box == 1)
            {
                yongbok_status();
            }
            else if(check_box == 2)
            {
                printf("인벤토리 나오게하기.\n");
            }
            else if(check_box == 3)
            {
                consume();
            }
            else if(check_box == 4)
            {
                refinery_material();
            }
            else if(check_box == 5)
            {
                break;
            }
        }    
    }
}
    


//-----------------------함수호출------------------------

int yongbok_status() // 용복이 상태창
{

    // 용사복이 상태창 만들기
    printf("============================================================\n");
    printf("               \t    용복이상태창  LV.2 \t\t    \n");
    printf("============================================================\n");
    printf("| 기본능력치 |\t\t\t| 전투능력치 |");
    printf("\n");
    printf("\n");
    printf("HP(체력)\t%d\t\tATK(공격력)\t\t%d\n",status_info[0],status_info[2]);
    printf("MP(마력)\t%d\t\tMATK(마법공격력)\t%d\n",status_info[1],status_info[3]);
    printf("STR(힘)\t\t%d\t\tDEF(방어력)\t\t%d\n",status_info[7],status_info[4]);
    printf("INT(지능)\t%d\t\tAC(회피율)\t\t%d%%\n",status_info[8],status_info[5]);
    printf("DEX(손재주)\t%d\t\tCRI(치명타율)\t\t%d%%\n",status_info[9],status_info[6]);
    printf("\n");

    return 0;
}
int consume() //아이템창
{

    printf("=========================================\n");
    printf("                아이템    \n");
    printf("=========================================\n");

    //물약조건
    for(int i=0; i<12; i++)
    {  
        printf("%d. %s(%d / %d)\n",i, potion[i],potion_count[0],potion_total);// 번호, 물약이름, 현재갯수, 총갯수  
        
    }

    printf("\n");

    return 0;
}
int refinery_material() // 강화재료창
{
    printf("=========================================\n");
    printf("                강화재료    \n");
    printf("=========================================\n");

    for(int i=0; i<5; i++)
    {
        printf("%d. %s(0 / 999)\n",i,fire_piece[i]);
    }

    return 0;
}
    
