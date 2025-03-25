#include<stdio.h>
#include"./all_made_struted.c"


struct character yongbok;       //용복이 캐릭터 변수
struct status yongbok_status;   // 용복이 상태 변수
struct sword sword1_basic;      //용복이 무기 변수 1티어

struct inven invens[4];    // 용잡보제   0용복이 1잡화소 2보관소 3제련소

struct sword sword3_japanese;
struct sword sword6_world_Best;

struct inven my_inven;


void enchant_shop()  
{
    struct inven yongbok_inven;


struct sword sword1_basic;      //용복이 무기 변수 1티어
sword1_basic = set_sword(sword1_basic,"기본검",-2,-1, 2,0,0,50,0,0);
my_inven.sw[0] = sword1_basic; // 내인벤은 칼[0],[1],[2],[3],

invens[0]=my_inven;

    //===========================================================

    struct refinery_material stone;
    stone = set_refinery_material(stone,"마력응축석",3,1,11);
    int rand_,result;
    int enchant_yn;
    char enchant_rand[][20] = {"속성 없음","물","불","자연"}; 
    printf("인챈트 가게 입니다.\n인챈트시 마력응축석 10개가 소모됩니다\n\n");
    printf("-----보유 무기 -----\n");
    printf("1번 무기: %s ", my_inven.sw[0].name);
    if (my_inven.sw[0].attribute == 0){
        printf("(속성: 무속성)\n");
    }
    else if (my_inven.sw[0].attribute == 1){
    printf("(속성: 물)\n");
    }
    else if (my_inven.sw[0].attribute == 2){
        printf("(속성: 불)\n");
    }
    else if (my_inven.sw[0].attribute == 3){
        printf("(속성: 자연)\n");
        }

    printf("보유 마력 응축석: %d\n강화를 진행하시겠습니까?: \n0.아니오  1. 네\n", stone.quantity);
    scanf("%d",&enchant_yn);  //강화진행여부 물어봄
    while(getchar() != '\n');  // 버퍼
    if (enchant_yn)  //한다구 하면~
    {
        if(stone.quantity < 10) printf("재료가 부족합니다.\n");  
        else if (stone.quantity >= 10)
        {
            rand_ = (rand() % 3);
            stone.quantity -= 10;
            my_inven.sw[0].attribute = rand_;
            printf("무기에 %s 속성이 인챈트 되었습니다.\n",enchant_rand[rand_]);
            printf("남은 마력응축석:%d\n",stone.quantity);
            printf("-----보유 무기 -----\n");
            printf("1번 무기: %s ", my_inven.sw[0].name);
                if (my_inven.sw[0].attribute == 0){
                    printf("(속성: 무속성)\n");
                }
                else if (my_inven.sw[0].attribute == 1){
                printf("(속성: 물)\n");
                }
                else if (my_inven.sw[0].attribute == 2){
                    printf("(속성: 불)\n");
                }
                else if (my_inven.sw[0].attribute == 3){
                    printf("(속성: 자연)\n");
                }
        
        }
        getchar();
  //무기 가져오기. 구조체에서 못찾겠어요 ㅠㅠ
    }
    
}

int main(){
    enchant_shop();
}