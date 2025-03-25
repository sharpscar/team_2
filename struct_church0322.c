#include<stdio.h>
#include"./all_made_struted.c"

void church(){
    struct status yongboks_s;
    yongboks_s = set_status(yongboks_s," 용복이",1,100,10,20,10,10,0,10,10,20,10);  //맨 뒤 3개가 10,10,10이나 초기화 되는지 확인 위해 10,20,10으로 바꿈요
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


int main(){

    church();

}