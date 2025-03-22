#include <stdio.h>
#include <stdlib.h> //rand함수 사용하기 위한 헤더파일
#include <time.h> //time 함수를 사용하기 위한 헤더파일

// void show_village_menu(){  //마을 메뉴 출력 함수 안에 들어갈 내용을 받아서 나오면 참 좋을 것 같음
//     printf("┏━━━━━━━━━━━━━━━━━┓\n");
//     printf(" ------마을------\n");
//     printf("1. 잡화상\n2. 제련소\n3. 마법상점\n4. 은행\n");
//     printf("┗━━━━━━━━━━━━━━━━━┛\n");
// }
int inven[50];
* shop_main();

// 잡화상
int main(){
    shop_main();

    
    return inven[];
}


int * shop_main()
{
    int quit_shop;
    int shop_list_choice;
    int item_choice;
    /**
     * inven  은  유저의 가방입니다. 
     * 0 돈주머니
     * 1 스텟 
     * 2 가방 <inven>
     * 3 소모품 
     * 
     */
    int inven[4][100]; 
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
        
        //이건 넘어가자
        //현재  for문으로 배열에 넣을수있는 공간이 있는지 체크! 
        //20개 공간중에 남는게 없으면 구매 불가
        
            if ((shop_price[item_choice])*item_count > user_money)
                printf("잔액이 부족합니다.\n");
            else{
                //구매완료
                printf("%s %d개 구매하였습니다.\n",shop_list[item_choice],item_count);
                
                user_money -= (shop_price[item_choice])*item_count;
                
                inven[0][0] = user_money;
                inven[1][0] = shop_list[item_choice]; //20 개만들어간다 
                // int cnt = sizeof(inven[1][?] ) /sizeof(int); 
                


                printf("현재 보유금액: %d]\n",user_money);}

        printf("더 구매 하시겠습니까?: \n0.예\n1.아니오\n");
        scanf("%d",&quit_shop);
            if (quit_shop == 1)
                break;
    }
    /*
     개발시 일단 숫자형 배열에 리턴한다고 생각하고 개발해뒀다.
     
     */
    return *inven; 
}

// int * church_main()
// {
//     int status[4][100]; // [2][0] hp  [2][1] mp [2][0]
//     int stats [3] = {1,4,2};  //임의값
//     int stats_sum = stats[0] + stats[1] + stats[2];
//     char stats_name [] [3] = {"STR","INT","DEX"};
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
    

    
 

}
//church
// int main(){
//     int stats [3] = {1,4,2};  //임의값
//     int stats_sum = stats[0] + stats[1] + stats[2];
//     char stats_name [] [3] = {"STR","INT","DEX"};
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






