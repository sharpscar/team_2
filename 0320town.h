#include <stdio.h>
#include <stdlib.h> //rand함수 사용하기 위한 헤더파일
#include <time.h> //time 함수를 사용하기 위한 헤더파일

// void show_village_menu(){  //마을 메뉴 출력 함수 안에 들어갈 내용을 받아서 나오면 참 좋을 것 같음
//     printf("┏━━━━━━━━━━━━━━━━━┓\n");
//     printf(" ------마을------\n");
//     printf("1. 잡화상\n2. 제련소\n3. 마법상점\n4. 은행\n");
//     printf("┗━━━━━━━━━━━━━━━━━┛\n");
// }

// 잡화상
int* variety_store_main(struct inven *p){
    /*
     
     * 구조체를 쓰겠당!
     * 
    struct inven
    {
        int wallet;
        int stat[11];
        char bag[20][20]; //캐릭터의 배낭이다.
        char consume[100][30] // 열에는 '' 이런식으로 숫자를 표기한다 더좋은방식 있으면 알려주시면 적극 수용

    };
     *   struct inven my_visitor ={ 
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
     */
    // struct inven
    // {
    //     int wallet;
    //     int stat[11];
    //     char bag[20][20]; //캐릭터의 배낭이다.
    //     char consume[100][30] // 열에는 '' 이런식으로 숫자를 표기한다 더좋은방식 있으면 알려주시면 적극 수용

    // };

    // printf("이녀석의 소지금은 %d", p->wallet);
    // printf("이녀석의 hp는 %d", p->stat[2]); 
    // for (int i=0; i<4;i++)
    // {
    //     printf("이녀석의 가방에는 %s", p->bag[i]); 
    // }
    
    
    

    int property[4][100];  // 상점이라 유저의 재산이 변동됩니다.
    int quit_shop;
    int shop_list_choice;
    int item_choice;
    int item_count;
    int user_money = 1000;
    char shop_list[] [40] ={"기본검","장검","일본도","가죽갑옷","철갑옷","가죽신발","철신발","가죽장갑","철장갑","천망토","면망토","가죽투구","철투구","빨간물약","주황물약","맑은물약","파란물약","하얀물약","무지개물약","해독제","축복주문서","마을이동주문서","순간이동주문서"};

    int shop_price[23] = {50,500,10000,50,600,50,600,50,600,50,600,50,600,30,200,1000,50,300,1500,500,2000,200,1000};



    while(1){
    system("clear");
    printf("\t\t\t현재 보유금액: %d\n",user_money);
    printf("구매하실 물건의 카테고리를 선택하세요\n");
    printf("1. 무기\n2. 갑옷\n3. 신발\n4. 장갑\n5. 망토\n6. 투구\n7. 물약\n8. 귀환서\n");
    scanf("%d",&shop_list_choice);
    system("clear");
    
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
    
        printf("\n구매하실 상품의 번호를 입력하세요: ");
        scanf("%d",&item_choice);
        // printf("수량을 입력하세요: ");
        // scanf("%d",&item_count);
        item_count=1; //수량은 아직 .. 그저 구매만할꺼야! 0320 
        
            if ((shop_price[item_choice])*item_count > user_money)
                printf("잔액이 부족합니다.\n");
            else{
                printf("%s %d개 구매하였습니다.\n",shop_list[item_choice],item_count);
                user_money -= (shop_price[item_choice])*item_count;

                // property의 변동이 생겼습니다.
                property[0][0]=user_money;
                property[1][0] = item_choice;// shoplist에 기반한 내용이기 때문에 앞으로 shoplist는 2차원 배열인데 그 정보를 항상 댈고다녀야할까
                printf("현재 보유금액: %d]\n",user_money);
                //set_inven();
            }
        

        //추매기능은 아직 추매 ㄴㄴ ㅠ

        // printf("더 구매 하시겠습니까?: \n0.예\n1.아니오\n");
        // scanf("%d",&quit_shop);
        //     if (quit_shop == 1)
        //         break;
    }
    // return property;
    return 0;
}

// // church
// int main(){
//     int stats [3] = {1,4,2};  //임의값
//     int stats_sum = stats[0] + stats[1] + stats[2];
//     // char stats_name [] [3] = {"STR","INT","DEX"};
//     int church_choice;
//     int church_stats_yn;
//     int level =5;  //임의값
//     int user_hp = 30; //임의값
//     int user_mp = 5; //임의값
//     int max_user_hp = 100;  //임의값
//     int max_user_mp = 10; //임의값

//     printf("성소에 도착했습니다.\n");
//     printf("치유: 0\n스탯초기화: 1\n");
//     scanf("%d",&church_choice);
//     system("clear");

//     if (church_choice == 0){
//         user_hp = max_user_hp;
//         user_mp = max_user_mp;
//         printf("치유되었습니다.\n");
//         printf("hp: %d mp: %d\n",user_hp,user_mp);
//     }
//     if (church_choice == 1){
//         printf("스탯:\n");
//         printf("스탯의 합계: %d\n",stats_sum);
//         printf("STR: %d INT: %d DEX: %d\n",stats[0],stats[1],stats[2]);
//         printf("스탯을 초기화?\n1.네\n2.아니오\n");
//         scanf("%d",&church_stats_yn);
//         if (church_stats_yn == 1){
//             for (int i=0;i<3;i++){
//                 stats[i] = 0;
//             }
//             printf("초기화되었습니다.\n");
//             printf("스탯의 합계: %d\n",stats_sum);
//             printf("STR: %d INT: %d DEX: %d\n",stats[0],stats[1],stats[2]);
//         }
        
//     }
// }