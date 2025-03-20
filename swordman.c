
#include <stdio.h>

void set_game();     //초깃값 설정 게임의 모든 준비사항이 여기서 출발합니다.   
void event_main();   // 유저가 워프스크롤,상태창확인, 어디서 뭘하든 호출가능해야하는 UI를 보여주는 함수입니다.
void town_main();    
void dungeon_main();

int main()
{

    set_game();     //초깃값 설정 게임의 모든 준비사항이 여기서 출발합니다.   
    event_main();   // 유저가 워프스크롤,상태창확인, 어디서 뭘하든 호출가능해야하는 UI를 보여주는 함수입니다.
    town_main();    
    dungeon_main();


    return 0;
}


void set_game(){

}    
void event_main(){

}   
void town_main(){

}    
void dungeon_main(){

}