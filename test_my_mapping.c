#include <stdio.h>
#include "./all_setting.c"
// #include "./mapping_town_0321.c"
struct inven setting_shop(struct inven shop_inven);
int main()
{
    struct inven shop_inven;
    setting_shop(shop_inven);


    


    return 0;
}


// 인벤을 가져오자
struct inven setting_shop(struct inven shop_inven)
{
    
    struct sword sword1_basic;
    struct sword sword2_longsword;
    struct sword sword3_japanese;
    // 장비 이름 뒤에는 index_ -1:보관소, -2:상점 , -3: 몹드랍


    sword1_basic =set_sword(sword1_basic,"기본검",1,-2,2,0,0,50,0,0);    
    sword2_longsword= set_sword(sword2_longsword,"장검",2,-2, 10,0,0,500,0,0);
    sword3_japanese= set_sword(sword3_japanese,"일본도",3,-2, 20,0,0,1000,0,0);
    
    shop_inven.sw[0] =sword1_basic;
    shop_inven.sw[1] =sword2_longsword;
    shop_inven.sw[2] =sword3_japanese;

    struct amor amor1_leather;
    struct amor amor2_iron;

    amor1_leather=set_amor(amor1_leather,"가죽갑옷",-2,-2,0,0,0,50,0,0,0,0);
    amor2_iron=set_amor(amor2_iron,"철갑옷",-2,-6,0,0,0,50,0,0,0,0);
    shop_inven.am[0]=amor1_leather;
    shop_inven.am[1]=amor2_iron;


    struct amor amor1_leather_shoes;
    struct amor amor2_iron_shoes;
    amor1_leather_shoes= set_amor(amor1_leather_shoes,"가죽신발",-2,-1,0,0,0,50,0,0,0,0);
    amor2_iron_shoes= set_amor(amor2_iron_shoes,"철신발",-2,-3,0,0,0,600,0,0,0,0);

    shop_inven.am[2]=amor1_leather_shoes;
    shop_inven.am[3]=amor2_iron_shoes;

    struct amor amor1_leather_gloves;
    struct amor amor2_iron_gloves;

    amor1_leather_gloves= set_amor(amor1_leather_gloves,"가죽장갑",-2,-1,0,0,0,50,0,0,0,0);
    amor2_iron_gloves   = set_amor(amor2_iron_gloves,"철장갑",-2,-3,0,0,0,600,0,0,0,0);

    shop_inven.am[2]=amor1_leather_gloves;
    shop_inven.am[3]=amor2_iron_gloves;

    struct amor amor1_leather_cloak;
    struct amor amor2_cotton_cloack;

    amor1_leather_cloak= set_amor(
        amor1_leather_cloak,"천망토",-2,-1,0,0,0,50,0,0,0,0);
    amor2_cotton_cloack= set_amor(
        amor2_cotton_cloack,"면망토",-2,-3,0,0,0,600,0,0,0,0);
    shop_inven.am[4]=amor1_leather_cloak;
    shop_inven.am[5]=amor2_cotton_cloack;

    struct amor amor1_leather_helmet;
    struct amor amor2_iron_helmet;

    amor1_leather_helmet= set_amor(
        amor1_leather_helmet,"가죽투구",-2,-1,0,0,0,50,0,0,0,0);
    amor2_iron_helmet= set_amor(
        amor2_iron_helmet,"철투구",-2,-3,0,0,0,600,0,0,0,0);
    
    shop_inven.am[6] =amor1_leather_helmet;
    shop_inven.am[7]= amor2_iron_helmet;


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

    struct inven user_inven;
    user_inven.money = 100000;

    int shop_list_choice;

    // printf("\t\t\t현재 보유금액: %d\n",user_inven.money);
    // printf("구매하실 물건의 카테고리를 선택하세요\n\n");
    // printf("1. 무기\n2. 갑옷\n3. 신발\n4. 장갑\n5. 망토\n6. 투구\n7. 물약\n8. 귀환서\n**이동 키 눌러 나가기**\n");
    // scanf("%d",&shop_list_choice);
    // system("clear");

    
     
    int my_int =sizeof(shop_inven.sw)/sizeof(struct sword);
     //이런식으로 크기 가져와서 뿌려주면 된다.
 
    int sw_cnt=0;
    int am_cnt=0;
    // 칼의 갯수
    for(int i=0; i<my_int; i++)
    {
        if(shop_inven.sw[i].index_==-2)
        {
            sw_cnt++;
        }
        
    }
    // 아머의 갯수
    for(int i=0; i<my_int; i++)
    {
        if(shop_inven.am[i].index_==-2)
        {
            am_cnt++;
        }
        
    }

    

    
    // while(1)
    // {
        // if (shop_list_choice == 1){  //무기
        //     // shop_inven.sw[i].name , shop_inve.sw[i].price shop_inven.sw[0]
        //     for (int i = 0; i< sizeof(shop_inven.sw)/sizeof(struct sword); i++){
        //         printf("%d. %s:\t\t(%d GOLD)\n",i,shop_list[i],shop_price[i]);
        //     }
        // }
        // else if (shop_list_choice == 2){ //갑옷
        //     // shop_inven.am[i].name , shop_inve.am[i].price
        //     for (int i = 3; i< 5; i++){
        //         printf("%d. %s:\t\t(%d GOLD)\n",i,shop_list[i],shop_price[i]);
        //     }
        // }
        // else if (shop_list_choice == 3){
        //     for (int i = 5; i< 7; i++){
        //         printf("%d. %s:\t\t(%d GOLD)\n",i,shop_list[i],shop_price[i]);
        //     }
        // }
        // else if (shop_list_choice == 4){
        //     for (int i = 7; i< 9; i++){
        //         printf("%d. %s:\t\t(%d GOLD)\n",i,shop_list[i],shop_price[i]);
        //     }
        // }
        // else if (shop_list_choice == 5){
        //     for (int i = 9; i< 11; i++){
        //         printf("%d. %s:\t\t(%d GOLD)\n",i,shop_list[i],shop_price[i]);
        //     }
        // }
        // else if (shop_list_choice == 6){
        //     for (int i = 11; i< 13; i++){
        //         printf("%d. %s:\t\t(%d GOLD)\n",i,shop_list[i],shop_price[i]);
        //     }
        // }        
        // else if (shop_list_choice == 7){
        //     for (int i = 13; i< 21; i++){
        //         printf("%d. %s:\t\t(%d GOLD)\n",i,shop_list[i],shop_price[i]);
        //     }
        // }
        // else if (shop_list_choice == 8){
        //     for (int i = 21; i< 23; i++){
        //         printf("%d. %s:\t\t(%d GOLD)\n",i,shop_list[i],shop_price[i]);
        //     }
        // }
        // else
        //     // break;
        // printf("\n구매하실 상품의 번호를 입력하세요: (나가기: 23)");
        // scanf("%d",&item_choice);
        
        // if (item_choice ==23){
        //     // break;
        // }
        // if (item_choice < 0 || item_choice >= 23) {
        //     printf("유효하지 않은 번호입니다.\n");
        //     // continue;
        // }

        // printf("수량을 입력하세요: ");
        // scanf("%d",&item_count);


        // if ((shop_price[item_choice])*item_count > user_money)
        //     printf("잔액이 부족합니다.\n");
        // else{
        //     printf("%s %d개 구매하였습니다.\n\n",shop_list[item_choice],item_count);
        //     user_money -= (shop_price[item_choice])*item_count;
        //     printf("현재 보유금액: %d\n",user_money);
        // }

        // printf("더 구매 하시겠습니까?: \n0.예\n1.아니오\n");
        // scanf("%d",&quit_shop);
        // if (quit_shop == 1)
        {
            // break;
        }               
    // } while문의 끝
}