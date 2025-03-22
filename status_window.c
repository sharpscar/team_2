#include <stdio.h>


int yongbok_status();

int main(){

    yongbok_status();

    return 0;
}


int yongbok_status(){

    char status[10][20] = {"체력","마력","공격력","마법공격력","회피율","힘","지능","손재주","방어력","치명타율"};
    int status_info[20] = {100,10,20,10,0,2,5,10,10,10};

    // 용사복이 상태창 만들기
    printf("┌──────────────────────────────────────────────────────────┐\n");
    printf("│\t             용복이상태창 LV.2 \t\t\t   │\n");
    printf("└──────────────────────────────────────────────────────────┘\n");
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

    //뭔가를 수정했어요
}
