

#include <string.h>

// #include "./test_bank.c"


struct statu {                 // 여기서만 써보기 위해 statu로
    int lv;
    char name[30];
    int exp;
    int hp;
    int mp;
    int atk;              // 6
    int matk;             // 7
    int def;              // 8
    int ac;
    int cri;
    int str;
    int int_; 
    int dex;
    int poison;
    //좌표 ()()(마을)()()
};

                                                                      //크리
struct statu yb_status  = {80, "용복", 50, 10000, 1000, 50, 10, 5, 50, 30, 50, 50, 30, 0};                       //  원래는 yongbok_status.hp 이런식으로 가야함 


struct skil {                          // 여기서만 써보기 위해 skil로
    char name[30];
    int get_level;
    int type; // 1 불 2 물 3자연
    int magic_rate;
    int use_mp;
};

struct skil fireball = {"파이어볼", 0, 1, 2, 10};
struct skil iceball = {"아이스볼", 0, 1, 6, 50};
struct skil meteo = {"메테오", 0, 1, 100, 100};




struct monste {                         // 여기서만 써보기 위해 monste로
    char name[30];       // 1
    int num;             // 2
    int hp_min;
    int hp_max;
    int hp;
    int atk_min;        // 6
    int atk_max;        // 7
    int atk;            // 8
    int def_min;       // 9
    int def_max;
    int def;
    int weak_attr;         //0,1,2,3  불/물/자연
    int strong_attr;       //0,1,2,3  불/물/자연
    int poison;
    int curse;
    int gold_min;
    int gold_max;
    int gold;
    int exp;
    };

struct monste orc = {"오크전사",0,50,100,0,10,20,0,5,10,0,2,1,0,0,1,5,0,50};
struct monste name_orc = {"네임드오크전사",1,60,160,0,10,20,0,0,0,0,2,1,0,0,5,25,0,50};
struct monste zombi = {"좀비",2,150,200,0,25,40,0,1,3,0,1,3,20,0,5,20,0,50};
struct monste name_zombi = {"네임드좀비",3,160,240,0,50,80,0,1,3,0,1,3,40,0,25,100,0,50};
struct monste guul = {"구울",4,120,200,0,50,80,0,5,10,0,1,3,40,0,20,50,0,50};
struct monste name_guul = {"네임드구울",5,240,400,0,100,160,0,10,20,0,1,3,80,0,20,50,0,50};
struct monste skeleton = {"해골",6,250,400,0,70,110,0,15,30,0,3,0,0,20,50,200,0,50};
struct monste name_skeleton = {"네임드해골",7,500,800,0,140,220,0,30,60,0,3,0,0,40,250,1000,0,50};
struct monste richi = {"리치",8,300,350,0,230,300,0,10,15,0,3,0,0,0,100,400,0,50};
struct monste name_richi = {"네임드리치",9,600,700,0,460,600,0,20,30,0,3,0,0,0,500,2000,0,50};
struct monste basillisk = {"바실리스크",10,600,900,0,100,130,0,30,50,0,2,0,0,0,100,400,0,50};
struct monste name_basillisk = {"네임드바실리스크",11,1200,1800,0,200,260,0,60,100,0,2,0,0,0,500,2000,0,50};
struct monste boss = {"이동녀크",11,2000,2000,0,200,260,0,20,20,0,2,0,0,0,500,2000,0,50};




int input_action(void);                          // 입력하는 함수

void battle_setting(int x);
void battle_start(int x);

void player_turn_call(int x);                    // battle_start안에 들어가서 구분하여 player_turn_orc 등 호출

void player_turn_orc(void);
void player_turn_zombi(void);
void player_turn_basillisk(void);
void player_turn_boss(void);

// void player_turn_name_orc(void);                 // 미구현
// void player_turn_name_zombi(void);               // 미구현
// void player_turn_guul(void);                     // 미구현
// void player_turn_skeleton(void);                 // 미구현
// void player_turn_name_skeleton (void);           // 미구현
// void player_turn_richi(void);                    // 미구현
// void player_turn_name_richi(void);               // 미구현
// void player_turn_name_basillisk(void);           // 미구현


int attack_call(int x);                          // 몬스터 종류에 따른 어택장면 부르고 적 hp 줄이고 죽었으면 0 살았으면 1나오게

void attack_orc(int x);
void attack_zombi(int x);
void attack_basillisk(int x);                      // 미구현   
void attack_boss(int x);

// void attack_name_orc(void);                       // 미구현 
// void attack_name_zombi(void);                     // 미구현   
// void attack_guul(void);                           // 미구현
// void attack_skeleton(void);                       // 미구현
// void attack_name_skeleton (void);                 // 미구현
// void attack_richi(void);                          // 미구현
// void attack_name_richi(void);                     // 미구현
// void attack_name_basillisk(void);  

int player_magicturn(int x);               

void player_magicturn_orc(void);
void player_magicturn_zombi(void);
void player_magicturn_basillisk(void); 
void player_magicturn_boss(void); 

int monster_attack(int x);

void monster_attack_scene(int x);        
void cri_scene(void);


void lv_up_scene(void);                   // 레벨업시 화면이 나옴
void poison_scene(int x); 

void fireball_act(int x);                 // 마법 나오고 데미지 표시
void iceball_act(int x);
void meteo_act(int x);


// int main(){

    // srand(time(0));

    // int appear_num = 3;     
    // // appear_num = rand() % 4;             // 원래는 숫자 더 높아야 하지만 몬스터 3마리만 구현예정

    // battle_setting(3);          // 몬스터 hp등 세팅 함수 실행
    // battle_start(3);            // 배틀 시작 while로 시작해 돔

//     return 0;

// }







void battle_setting(int x){                             // 몬스터 hp등 세팅          // 0~2만 구현

    switch(x){                                             
                                      
        case 0:                                         
            orc.hp = rand() % orc.hp_max + orc.hp_min;
            orc.atk = rand() % orc.atk_max + orc.atk_min;
            orc.def = rand() % orc.def_max + orc.def_min;
            orc.gold = rand() % orc.gold_max + orc.gold_min;      
            break;

        case 1:
            zombi.hp = rand() % zombi.hp_max + zombi.hp_min;
            zombi.atk = rand() % zombi.atk_max + zombi.atk_min;
            zombi.def = rand() % zombi.def_max + zombi.def_min;
            zombi.gold = rand() % zombi.gold_max + zombi.gold_min;     
            break;

        case 2:
            basillisk.hp = rand() % basillisk.hp_max + basillisk.hp_min;
            basillisk.atk = rand() % basillisk.atk_max + basillisk.atk_min;
            basillisk.def = rand() % basillisk.def_max + basillisk.def_min;
            basillisk.gold = rand() % basillisk.gold_max + basillisk.gold_min;    
            break;

        case 3:
            boss.hp = rand() % boss.hp_max + boss.hp_min;
            boss.atk = rand() % boss.atk_max + boss.atk_min;
            boss.def = rand() % boss.def_max + boss.def_min;
            boss.gold = rand() % boss.gold_max + boss.gold_min;   
            break;

        case 4:
            guul.hp = rand() % guul.hp_max + guul.hp_min;
            guul.atk = rand() % guul.atk_max + guul.atk_min;
            guul.def = rand() % guul.def_max + guul.def_min;
            guul.gold = rand() % guul.gold_max + guul.gold_min;   
            break;

        case 5:
            name_guul.hp = rand() % name_guul.hp_max + name_guul.hp_min;
            name_guul.atk = rand() % name_guul.atk_max + name_guul.atk_min;
            name_guul.def = rand() % name_guul.def_max + name_guul.def_min;
            name_guul.gold = rand() % name_guul.gold_max + name_guul.gold_min;          
            break;

        case 6:
            skeleton.hp = rand() % skeleton.hp_max + skeleton.hp_min;
            skeleton.atk = rand() % skeleton.atk_max + skeleton.atk_min;
            skeleton.def = rand() % skeleton.def_max + skeleton.def_min;
            skeleton.gold = rand() % skeleton.gold_max + skeleton.gold_min;          
            break;

        case 7:
            name_skeleton.hp = rand() % name_skeleton.hp_max + name_skeleton.hp_min;
            name_skeleton.atk = rand() % name_skeleton.atk_max + name_skeleton.atk_min;
            name_skeleton.def = rand() % name_skeleton.def_max + name_skeleton.def_min;
            name_skeleton.gold = rand() % name_skeleton.gold_max + name_skeleton.gold_min;       
            break;

        case 8:
            richi.hp = rand() % richi.hp_max + richi.hp_min;
            richi.atk = rand() % richi.atk_max + richi.atk_min;
            richi.def = rand() % richi.def_max + richi.def_min;
            richi.gold = rand() % richi.gold_max + richi.gold_min;       
            break;
        
        case 9:
            name_richi.hp = rand() % name_richi.hp_max + name_richi.hp_min;
            name_richi.atk = rand() % name_richi.atk_max + name_richi.atk_min;
            name_richi.def = rand() % name_richi.def_max + name_richi.def_min;
            name_richi.gold = rand() % name_richi.gold_max + name_richi.gold_min;       
            break;

        case 10:                                     
            name_basillisk.hp = rand() % name_basillisk.hp_max + name_basillisk.hp_min;
            name_basillisk.atk = rand() % name_basillisk.atk_max + name_basillisk.atk_min;
            name_basillisk.def = rand() % name_basillisk.def_max + name_basillisk.def_min;
            name_basillisk.gold = rand() % name_basillisk.gold_max + name_basillisk.gold_min;
            break;

        case 11:
            name_orc.hp = rand() % name_orc.hp_max + name_orc.hp_min;
            name_orc.atk = rand() % name_orc.atk_max + name_orc.atk_min;
            name_orc.def = rand() % name_orc.def_max + name_orc.def_min;
            name_orc.gold = rand() % name_orc.gold_max + name_orc.gold_min;        
            break;

        case 12:                              
            name_zombi.hp = rand() % name_zombi.hp_max + name_zombi.hp_min;
            name_zombi.atk = rand() % name_zombi.atk_max + name_zombi.atk_min;
            name_zombi.def = rand() % name_zombi.def_max + name_zombi.def_min;
            name_zombi.gold = rand() % name_zombi.gold_max + name_zombi.gold_min;   
            break;
    }

    return;
}


void battle_start(int x){

    while(1){
                 
        int action;
        int result;
        int get_exp;    // 아직 안함
        int get_gold;   // 아직 안함
        int poison_damage; 
        poison_damage = yb_status.hp * 0.02;       // 포이즌 데미지 남은 에너지의 2%
      
        if (yb_status.poison == 1)                 // 포이즌 걸리면 용복 상태에서 .poison이 1이 됨
            poison_scene(poison_damage);
            


        player_turn_call(x);               // 이 함수로 한번 더 들어가서 x에 따라 몬스터와의 첫장면을 부른뒤 화면 멈춤 (player_turn_orc 등등등
        action = input_action();           // 입력하는 함수 1 일반공격 2 마법공격 3 아이템사용 4 도망간다

        if (action == 1){
            result = attack_call(x);       // x인수로 몹 종류에 따른 어택장면이 나오 적 hp가 깎임.  죽었으면 0 살았으면 1  
            if (result == 0) {              // 적이 죽으면 경험 break로 나가고 안죽으면 쭉   
                yb_status.exp += 50;       // 적 잡으면 경험치 상승이나 일단 레벨업만 확인 할 수 있게 그냥 50 고정값 50 넣음
                if (yb_status.exp >= 100)
                // 레벨업 합수 
                    yb_status.exp = 0;                               //  아이템 증가 돈 증가 등 추가 해야함 // 적이 죽었습니다 ~~를 얻었습니다. 나와야함
                break;}
        }    
            
        else if (action == 2){
            result = player_magicturn(x);             // x에 따라 첫장면 비슷한 장면이나 마법선택을 고른다 
            if (result == 0){                       
                yb_status.exp += 50;                                      //  아이템 증가 돈 증가 등 추가 해야함 // 적이 죽었습니다 ~~를 얻었습니다. 나와야함    
                if (yb_status.exp >= 100)
                   // 레벨업 합수
                   yb_status.exp = 0;                  // 레벨업하고 다시 0으로
                   


                break;
            }
            else if (result == 2)
                continue;                             // 마법을 그만두니 continue로 다시 올라간다
        }

        else if (action == 3){                        // 미구현
                // 아이템 사용 함수 붙여 쓰기
        }

        else if (action == 4)
            break;
    
        result = monster_attack(x);                           // 앞에서 종료되지 않고 여기까지 오면 몬스터가 공격한다           
            if (result == 0)                                  // 죽으면 마을로 돌아가고 경험치가 반으로 등등 너야함 그러나  주인공 죽는거 미구현
            break;                                            // 일단 break로 끝냄
        
        


    }
            
    return;
}


void player_turn_orc(void);
void player_turn_zombi(void);
void player_turn_basillisk(void);
void player_turn_boss(void);

// void player_turn_name_orc(void);               미구현
// void player_turn_guul(void);
// void player_turn_skeleton(void);
// void player_turn_name_skeleton(void);
// void player_turn_richi(void);
// void player_turn_name_richi(void);

void player_turn_name_basillisk(void);



void player_turn_call(int x){                                // 몬스터와 만나 일반공격 마법공격 등 결정하는 첫장면 호출하고 그냥 나감  // 4개만 구현

    switch(x){  
                                               
        case 0:                                         
            player_turn_orc();    
            break;

        case 1:
            player_turn_zombi();
            break;            

        case 2:
            player_turn_basillisk();
            break;
        
        case 3:
            player_turn_boss();         
            break;               
        
        // case 4:
        //     player_turn_name_orc();         
        //     break;

        // case 5:
        //     player_turn_name_zombi();
        //     break;

        // case 6:
        //     player_turn_guul();
        //     break;

        // case 7:
        //     player_turn_guul();
        //     break;

        // case 8:
        //     player_turn_skeleton();     
        //     break;      

        // case 9:
        //     player_turn_name_skeleton();
        //     break;

        // case 10:
        //     player_turn_richi();
        //     break;

        // case 11:
        //     player_turn_name_richi();
        //     break;
        
        // case 12:
        //     player_turn_name_basillisk();
        //     break;

    }

    return;
}



// void attack_orc(int x);
// void attack_zombi(void);
// void attack_basillisk(void);
void attack_name_orc(void);
void attack_name_zombi(void);
void attack_guul(void);
void attack_skeleton(void);
void attack_name_skeleton(void);
void attack_richi(void);
void attack_name_richi(void);
void attack_name_basillisk(void);



int attack_call(int x){                                // 몬스터 종류에 따른 어택장면 부르고 적 hp 줄이고 죽었으면 0 살았으면 1나오게
    
    int result;
    int cri = yb_status.cri;
    int damage; 

    switch(x){  
                                               
        case 0:        
            damage = yb_status.atk - orc.def;                              
            attack_orc(damage);              
            orc.hp -= damage;
            if (rand() % 100 <= cri){                            // 100중 나온값이 cri(용복이 치명타율) 보다 작으면 
                cri_scene();
                attack_orc(damage);
                orc.hp -= damage;
            }

            result = (orc.hp <= 0) ? 0 : 1 ;
            return result;
            break;

        case 1:
            damage = yb_status.atk - zombi.def;
            attack_zombi(damage);
            zombi.hp -= yb_status.atk - zombi.def;
            if (rand() % 100 < cri){
                cri_scene();
                attack_zombi(damage);
                zombi.hp -= damage;
            }

            result = (zombi.hp <= 0) ? 0 : 1 ;
            return result;
            break;

        case 2:
            damage = yb_status.atk - basillisk.def;        
            attack_basillisk(damage);
            basillisk.hp -= damage;
            if (rand() % 100 < cri){
                cri_scene();
                attack_basillisk(damage);
                basillisk.hp -= damage;
            }  

            result = (basillisk.hp <= 0) ? 0 : 1 ;
            return result;
            break;     

        case 3:
            damage = yb_status.atk - boss.def;
            attack_boss(damage);
            
            boss.hp -= damage;
            if (rand() % 100 < cri){
                cri_scene();
                attack_boss(damage);
                boss.hp -= damage;
            }  

            result = (boss.hp <= 0) ? 0 : 1 ;
            return result;
            break;     
        }
   
}
 
    //     case 4:
    //         attack_name_zombi();
    // //        orc.hp = ap - dp            
    //         result = (name_zombi.hp <= 0) ? 0 : 1 ;
    //         return result;
    //         break;

    //     case 5:
    //         attack_guul();
    // //        orc.hp = ap - dp            
    //         result = (guul.hp <= 0) ? 0 : 1 ;
    //         return result;
    //         break;

    //     case 6:
    //         attack_name_guul();
    // //        orc.hp = ap - dp            
    //         result = (name_guul.hp <= 0) ? 0 : 1 ;
    //         return result;
    //         break;

    //     case 7:
    //         attack_skeleton();
    // //        orc.hp = ap - dp            
    //         result = (skeleton.hp <= 0) ? 0 : 1 ;
    //         return result;
    //         break;

    //     case 8:
    //         attack_name_skeleton();     
    // //        orc.hp = ap - dp            
    //         result = (name_skeleton.hp <= 0) ? 0 : 1 ;
    //         return result;
    //         break;     

    //     case 9:
    //         attack_richi();
    // //        orc.hp = ap - dp            
    //         result = (richi.hp <= 0) ? 0 : 1 ;
    //         return result;
    //         break;     

    //     case 10:
    //         attack_name_richi();
    // //        orc.hp = ap - dp            
    //         result = (name_richi.hp <= 0) ? 0 : 1 ;
    //         return result;
    //         break;     
    
    //     case 11:
    //         attack_name_basillisk();
    // //        orc.hp = ap - dp            
    //         result = (name_basillisk.hp <= 0) ? 0 : 1 ;
    //         return result;
    //         break;
        
        
    //     case 12:
    //         attack_name_orc();         
    // //        orc.hp = ap - dp            
    //         result = (name_orc.hp <= 0) ? 0 : 1 ;
    //         return result;
    //         break;
 

 
int monster_attack(int x) {                // 몬스터가 공격하는 함수 4개만 하고 일단 생략     <완>

    int monster_damage;
    int result;
    int poison_damage;

    switch(x){

        case 0:                                             // 오크 공격
            monster_damage = orc.atk - yb_status.def; 
            monster_attack_scene(monster_damage);           // 오크 공격 및 데미지표시 출력
            yb_status.hp -= monster_damage;                 // 용복 hp 감소                
            result = (yb_status.hp  <= 0) ? 0 : 1 ;         // 죽으면 0 살면 1

            return result; 


        case 1:                                             // 좀비 공격 
            poison_damage = yb_status.hp * 0.02;
            monster_damage = zombi.atk - yb_status.def; 
            monster_attack_scene(monster_damage);           // 좀비 공격 및 데미지표시 출력
            poison_scene(poison_damage); 
            yb_status.poison = 1;                          // 스탯에 poisosn

            yb_status.hp -= monster_damage;                 // 용복 hp 감소                
            result = (yb_status.hp  <= 0) ? 0 : 1 ;         // 죽으면 0 살면 1

            return result; 

            
        case 2:                                             // 바실리스크 공격   
            monster_damage = basillisk.atk - yb_status.def; 
            monster_attack_scene(monster_damage);           // 바실 공격 및 데미지표시 출력
            yb_status.hp -= monster_damage;                 // 용복 hp 감소                
            result = (yb_status.hp  <= 0) ? 0 : 1 ;         // 죽으면 0 살면 1

            return result; 


        case 3:                                             // 보스 공격   
            monster_damage = boss.atk - yb_status.def; 
            monster_attack_scene(monster_damage);           // 보스 공격 및 데미지표시 출력
            yb_status.hp -= monster_damage;                 // 용복 hp 감소                
            result = (yb_status.hp  <= 0) ? 0 : 1 ;         // 죽으면 0 살면 1

            return result;             
    }

}




int input_action(void) {    // 키 입력하는 함수

    int action;
    printf("\n원하시는 행동을 입력해주세요 : ");
    scanf("%d", &action);
    getchar();

    return action;
    
}



int player_magicturn(int x){
   
    int action;
    int result;
    int map;
    
    switch(x){                              // 적 변수 가져와서 해당 화면 띄우고 멈춤
                                                
        case 0:                                         
            player_magicturn_orc();           
            break;

        case 1:
            player_magicturn_zombi();         
            break;

        case 2:
            player_magicturn_basillisk();
            break;  

        case 3:
            player_magicturn_boss();
            break;  



    }

    action = input_action();            // 입력하는 함수
    
    switch(x){

        case 0:                           // 0 오크전사
            if (action == 1){             // 1 파이어볼     
                map = yb_status.matk * fireball.magic_rate;
                orc.hp -= map;
                fireball_act(map);               // 파이어볼 나오는 화면(화면 1 뒤에서  2 앞으로 나오고 데미지 표시)   
                yb_status.mp -= fireball.use_mp;   
                result = (orc.hp <= 0) ? 0 : 1 ;  // 0 죽음 1 삼
                return result;
            }
                     
            else if (action == 2){       //  2. 아이스볼
                map = yb_status.matk * iceball.magic_rate;
                orc.hp -= map;
                iceball_act(map);               // 아이스볼 나오는 화면(화면 1 뒤에서  2 앞으로 나오고 데미지 표시)
                yb_status.mp -= iceball.use_mp;        
                result = (orc.hp <= 0) ? 0 : 1 ;  // 0 죽음 1 삼
                return result;
            }

            else if (action == 3){
                map = yb_status.matk * meteo.magic_rate;
                orc.hp -= map;
                meteo_act(map);                   // 메테오 나오는 화면(화면 1 뒤에서  2 앞으로 나오고 데미지 표시) 
                yb_status.mp -= meteo.use_mp;     
                result = (orc.hp <= 0) ? 0 : 1 ;  // 0 죽음 1 삼
                return result;
            }

            else if (action == 4){
                result = 2;
                return result;                // 2 마법 그만두기
            }                 

        case 1:
            if (action == 1){
                map = yb_status.matk * fireball.magic_rate;
                zombi.hp -= map;
                fireball_act(map);               // 파이어볼 나오는 화면(화면 1 뒤에서  2 앞으로 나오고 데미지 표시) 
                yb_status.mp -= fireball.use_mp;      
                result = (zombi.hp <= 0) ? 0 : 1 ;  // 0 죽음 1 삼
                return result;
            }
                     
            else if (action == 2){            
                map = yb_status.matk * iceball.magic_rate;
                zombi.hp -= map;
                iceball_act(map);               // 아이스볼 나오는 화면(화면 1 뒤에서  2 앞으로 나오고 데미지 표시) 
                yb_status.mp -= iceball.use_mp;      
                result = (zombi.hp <= 0) ? 0 : 1 ;  // 0 죽음 1 삼
                return result;
            }

            else if (action == 3){
                map = yb_status.matk * meteo.magic_rate;
                zombi.hp -= map;
                meteo_act(map);                   // 메테오 나오는 화면(화면 1 뒤에서  2 앞으로 나오고 데미지 표시)   
                yb_status.mp -= meteo.use_mp;   
                result = (zombi.hp <= 0) ? 0 : 1 ;  // 0 죽음 1 삼
                return result;
            }

            else if (action == 4){
                result = 2;
                return result;
            }                      

        case 2:
            if (action == 1){
                map = yb_status.matk * fireball.magic_rate;
                basillisk.hp -= map;
                fireball_act(map);               // 파이어볼 나오는 화면(화면 1 뒤에서  2 앞으로 나오고 데미지 표시)   
                yb_status.mp -= fireball.use_mp;   
                result = (basillisk.hp <= 0) ? 0 : 1 ;  // 0 죽음 1 삼
                return result;
            }

                        
            else if (action == 2){            
                map = yb_status.matk * iceball.magic_rate;
                basillisk.hp -= map;
                iceball_act(map);               // 아이스볼 나오는 화면(화면 1 뒤에서  2 앞으로 나오고 데미지 표시)     
                yb_status.mp -= iceball.use_mp;  
                result = (basillisk.hp <= 0) ? 0 : 1 ;  // 0 죽음 1 삼
                return result;
            }
            

            else if (action == 3){
                map = yb_status.matk * meteo.magic_rate;
                basillisk.hp -= map;
                meteo_act(map);                   // 메테오 나오는 화면(화면 1 뒤에서  2 앞으로 나오고 데미지 표시)   
                yb_status.mp -= meteo.use_mp;     
                result = (basillisk.hp <= 0) ? 0 : 1 ;  // 0 죽음 1 삼
                return result;
            }

            else if (action == 4){
                result = 2;
                return result;
            }                 

        case 3:
            if (action == 1){
                map = yb_status.matk * fireball.magic_rate;
                boss.hp -= map;
                fireball_act(map);               // 파이어볼 나오는 화면(화면 1 뒤에서  2 앞으로 나오고 데미지 표시)    
                yb_status.mp -= fireball.use_mp;    
                result = (boss.hp <= 0) ? 0 : 1 ;  // 0 죽음 1 삼
                return result;
            }

                        
            else if (action == 2){            
                map = yb_status.matk * iceball.magic_rate;
                boss.hp -= map;
                iceball_act(map);               // 아이스볼 나오는 화면(화면 1 뒤에서  2 앞으로 나오고 데미지 표시) 
                yb_status.mp -= iceball.use_mp;       
                result = (boss.hp <= 0) ? 0 : 1 ;  // 0 죽음 1 삼
                return result;
            }
            

            else if (action == 3){
                map = yb_status.matk * meteo.magic_rate;
                boss.hp -= map;
                meteo_act(map);                   // 메테오 나오는 화면(화면 1 뒤에서  2 앞으로 나오고 데미지 표시)     
                yb_status.mp -= meteo.use_mp;   
                result = (boss.hp <= 0) ? 0 : 1 ;  // 0 죽음 1 삼
                return result;
            }

            else if (action == 4){
                result = 2;
                return result;
            }                 

    }
    

}

    
    



void player_magicturn_orc(void) {

    system("clear");

    puts("                                                                                            오크전사                ");
    printf("       < HP : %d / MP : %d >                                                       <  HP > : %d\n", yb_status.hp, yb_status.mp, orc.hp); //   플레이어 hp mp,   적 hp 표현  
    
    puts("                                                                                         ( \\ \\   /\\            ");
    puts("              /~~\\                                                                       / /   | `  \\           ");
    puts("            / ==== \\                                                                   O O   )       |           ");
    puts("           / ~~o o  \\                                                                   ' ^          '           ");
    puts("             _\\ -/_                                                                    (_.)  _ )    /            ");
    puts("            /  \\ / \\                                                                     `.___/`   /            ");
    puts("           //|  | | \\                                                                     `-----' /               "); 
    puts("          || |  | | ||                                                    &lt;----.     __ / __   \\              ");       
    puts("          || |  | | ||                                                    &lt;----|====O)))==) \\) /============= ");
    puts("          (' |====| ')                                                    &lt;----'    `--' `.__,' \\             "); 
    puts("             | || |                                                                      |         |             ");
    puts("             (_)(_)                                                                      \\       /              ");
    puts("             |_||_|                                                                   ____( (_   /               ");
    puts("             |_||_|                                                                 ,'  ,----'   |               ");
    puts("            /__][__\\                                                                 `--{__________)             ");
    puts("=================================================================================================================");    
    puts(" 1.파이어볼 2.아이스볼 3.메테오 4.그만둔다");                                   

    return;
}


void player_magicturn_zombi(void) {  

    system("clear");

    puts("                                                                             좀비                     ");
    printf("       < HP : %d / MP : %d >                                             < HP > : %d\n", yb_status.hp, yb_status.mp, zombi.hp); //   플레이어 hp mp,   적 hp 표현  
    puts("                                                                                                                     ");
    puts("              /~~\\                                                                                                  ");
    puts("            / ==== \\                                                      ㅡ  ㅡ                                     ");
    puts("           / ~~o o  \\                                                   / @   #   \\                                ");
    puts("             _\\ -/_                                                    (    ^     ,)                                ");
    puts("            /  \\ / \\                                                   \\         /-._                             ");
    puts("           //|  | | \\                                                    `._____.'\\   `--.__                        "); 
    puts("          || |  | | ||                                                          \\/         `/``\"\"\"'-.            ");       
    puts("          || |  | | ||                                                           /    )     /         :              ");
    puts("          (' |====| ')                                                           |   /\\    |  .--.     :            "); 
    puts("             | || |                                                              /  /\1`\\   \\/    `.__.:.____.-.   ");
    puts("             (_)(_)                                                             /  / /`\\ `\\`/    .-\"..____.-.     ");
    puts("             |_||_|                                                        _.-'  /_/   `\\ `\\                \\-.   ");
    puts("             |_||_|                                                       `=----'        `\\ `\\--------\'\"\"`-. \\ ");
    puts("            /__][__\\                                                                      `-./             `\"      ");
    puts("=================================================================================================================");    
    puts(" 1.파이어볼 2.아이스볼 3.메테오 4.그만둔다            ");                                   

    return;
}


void player_magicturn_basillisk(void) {

    system("clear");

    puts("                                                                                            바실리스크                ");
    printf("       < HP : %d / MP : %d >                                                       < HP > : %d\n", yb_status.hp, yb_status.mp, basillisk.hp); //   플레이어 hp mp,   적 hp 표현  
    puts("                                                                                                       _..-=~=-._   ");
    puts("                                                                                                  _.-~'          ~. ");
    puts("              /~~\\                                                                   __..---~~~~~                 ~. ");
    puts("            / ==== \\                                                               _.-~~                      _.._     ~. ");
    puts("           / ~~o o  \\                                                          _ -~_                         /    \\      ; ");
    puts("             _\\ -/_                                                           ( ` '@)                       {      |      : ");
    puts("            /  \\ / \\                                                          /                             |      |      : ");
    puts("           //|  | | \\                                                        /     /}         (  )          |      |     .- "); 
    puts("          || |  | | ||                                                      /     //-=-~-_-_  |  |          \\      ;    .' ");       
    puts("          || |  | | ||                                                     /     //     | =._-|  }/ / / /_.==\\     ; _.' ");
    puts("          (' |====| ')                                                    ( oo  //|     = )  ~| /.__..-='|    \\    :' "); 
    puts("             | || |                                                           |*| *   / /    / /      \\  |     ([ ]) ");
    puts("             (_)(_)                                                           |*| *   / /    / /      \\  |     ([ ]) ");
    puts("             |_||_|                                                            |*    /_/    / /       (  ]     `/ \' ");
    puts("             |_||_|                                                             |   (((|   /_/      __/_/__    -| |-- ");
    puts("            /__][__\\                                                                     (((|      -----     __|_|__ ");
    puts("=================================================================================================================");    
    puts("    1.파이어볼 2.아이스볼 3.메테오 4.그만둔다            ");     

    return;
}


void player_magicturn_boss(void) {

    system("clear");

    puts("                                                                                           이동녀크                ");
    printf("       < HP : %d / MP : %d >                                                       < HP > : %d\n", yb_status.hp, yb_status.mp, boss.hp); //   플레이어 hp mp,   적 hp 표현  
    puts("                                                                                          ,.-" "-.,                 ");
    puts("                                                                                         /   ===   \\                ");
    puts("                                                                                        /  ======= \\               ");
    puts("                                                                                     __|  (o)   (0)  |__            ");
    puts("                                                                                    / _|    .---.    |_ \\           ");
    puts("                                                                                   | /.----/ O O \\----.\\           ");
    puts("                                                                                    \\/     |     |     \\/         ");
    puts("                                                                                    |                   |           ");
    puts("                                                                                    _\\   -.,_____,.-   /_           ");
    puts("              /~~\\                                                             .-"  "-.,_________,.-"  "-.,        ");
    puts("            / ==== \\                                                         /          |       |          \\       ");
    puts("           / ~~o o  \\                                                       |           l.     .l           |      ");
    puts("             _\\ -/_                                                         l.           |     |           .l      ");
    puts("            /  \\ / \\                                                       |           l.   .l           |\\,     "); 
    puts("          || |  | | ||                                                      l.           |   |           .l  \\,    ");       
    puts("          || |  | | ||                                                      |           |   |           |     \\,   ");
    puts("          (' |====| ')                                                      l.          |   |          .l        |  "); 
    puts("             | || |                                                         |          |---|          |         |   ");
    puts("             '_''_'                                                         / -_,__,.- /   / -.,__,.- \\ -.,_,.- \\   ");
    puts("             |_||_|                                                        |            \\ /            |         |   ");
    puts("             |_||_|                                                        |             |             |         |    ");
    puts("            /__][__\\                                                      \\__|__|__|__/ \\__|__|__|__/ \\_|__|__/   ");
    puts("=================================================================================================================   ");    
    puts("    1.파이어볼 2.아이스볼 3.메테오 4.그만둔다                                                                                 ");     

    return;
}












void player_turn_orc(void) {

    system("clear");

    puts("                                                                                            오크전사                ");
    printf("       < HP : %d / MP : %d >                                                       < HP > : %d\n", yb_status.hp, yb_status.mp, orc.hp); //   플레이어 hp mp,   적 hp 표현  
    puts("                                                                                         ( \\ \\   /\\            ");
    puts("              /~~\\                                                                       / /   | `  \\           ");
    puts("            / ==== \\                                                                   O O   )       |           ");
    puts("           / ~~o o  \\                                                                   ' ^          '           ");
    puts("             _\\ -/_                                                                    (_.)  _ )    /            ");
    puts("            /  \\ / \\                                                                     `.___/`   /            ");
    puts("           //|  | | \\                                                                     `-----' /               "); 
    puts("          || |  | | ||                                                    &lt;----.     __ / __   \\              ");       
    puts("          || |  | | ||                                                    &lt;----|====O)))==) \\) /============= ");
    puts("          (' |====| ')                                                    &lt;----'    `--' `.__,' \\             "); 
    puts("             | || |                                                                      |         |             ");
    puts("             (_)(_)                                                                      \\       /              ");
    puts("             |_||_|                                                                   ____( (_   /               ");
    puts("             |_||_|                                                                 ,'  ,----'   |               ");
    puts("            /__][__\\                                                                 `--{__________)             ");
    puts("=================================================================================================================");    
    puts("    1.일반공격 2.마법공격 3.아이템사용 4.도망가기            ");                                   

    return;
}


void player_turn_zombi(void) {  

    system("clear");

    puts("                                                                             좀비                     ");
    printf("       < HP : %d / MP : %d >                                            < HP > : %d\n", yb_status.hp, yb_status.mp, zombi.hp); //   플레이어 hp mp,   적 hp 표현  
    puts("                                                                                                                     ");
    puts("              /~~\\                                                                                                  ");
    puts("            / ==== \\                                                      ㅡ  ㅡ                                     ");
    puts("           / ~~o o  \\                                                   / @   #   \\                                ");
    puts("             _\\ -/_                                                    (    ^     ,)                                ");
    puts("            /  \\ / \\                                                   \\         /-._                             ");
    puts("           //|  | | \\                                                    `._____.'\\   `--.__                        "); 
    puts("          || |  | | ||                                                          \\/         `/``\"\"\"'-.            ");       
    puts("          || |  | | ||                                                           /    )     /         :              ");
    puts("          (' |====| ')                                                           |   /\\    |  .--.     :            "); 
    puts("             | || |                                                              /  /\1`\\   \\/    `.__.:.____.-.   ");
    puts("             (_)(_)                                                             /  / /`\\ `\\`/    .-\"..____.-.     ");
    puts("             |_||_|                                                        _.-'  /_/   `\\ `\\                \\-.   ");
    puts("             |_||_|                                                       `=----'        `\\ `\\--------\'\"\"`-. \\ ");
    puts("            /__][__\\                                                                      `-./             `\"      ");
    puts("=================================================================================================================");    
    puts("    1.일반공격 2.마법공격 3.아이템사용 4.도망가기            ");                                   

    
    return;
}

void player_turn_basillisk(void) {

    system("clear");

    puts("                                                                                            바실리스크                ");
    printf("       < HP : %d / MP : %d >                                                       < HP > : %d\n", yb_status.hp, yb_status.mp, basillisk.hp); //   플레이어 hp mp,   적 hp 표현 
    puts("                                                                                                       _..-=~=-._   ");
    puts("                                                                                                  _.-~'          ~. ");
    puts("              /~~\\                                                                   __..---~~~~~                 ~. ");
    puts("            / ==== \\                                                               _.-~~                      _.._     ~. ");
    puts("           / ~~o o  \\                                                          _ -~_                         /    \\      ; ");
    puts("             _\\ -/_                                                           ( ` '@)                       {      |      : ");
    puts("            /  \\ / \\                                                         /                             |      |      : ");
    puts("           //|  | | \\                                                       /     /}         (  )          |      |     .- "); 
    puts("          || |  | | ||                                                      /     //-=-~-_-_  |  |          \\      ;    .' ");       
    puts("          || |  | | ||                                                     /     //     | =._-|  }/ / / /_.==\\     ; _.' ");
    puts("          (' |====| ')                                                    ( oo  //|     = )  ~| /.__..-='|    \\    :' "); 
    puts("             | || |                                                           |*| *   / /    / /      \\  |     ([ ]) ");
    puts("             (_)(_)                                                           |*| *   / /    / /      \\  |     ([ ]) ");
    puts("             |_||_|                                                            |*    /_/    / /       (  ]     `/ \' ");
    puts("             |_||_|                                                             |   (((|   /_/      __/_/__    -| |-- ");
    puts("            /__][__\\                                                                     (((|      -----     __|_|__ ");
    puts("=================================================================================================================");    
    puts("    1.일반공격 2.마법공격 3.아이템사용 4.도망가기            ");     

   

    return;
}

void player_turn_boss(void) {

    system("clear");

    puts("                                                                                           이동녀크                  ");
    printf("       < HP : %d / MP : %d >                                                       < HP > : %d\n", yb_status.hp, yb_status.mp, boss.hp); //   플레이어 hp mp,   적 hp 표현  
    puts("                                                                                         /   ===   \\                ");
    puts("                                                                                        /  =======  \\               ");
    puts("                                                                                     __|  (o)   (0)  |__            ");
    puts("                                                                                    / _|    .---.    |_ \\           ");
    puts("                                                                                   | /.----/ O O \\----.\\ |          ");
    puts("                                                                                    \\/     |     |     \\/           ");
    puts("                                                                                    |                   |           ");
    puts("                                                                                    _\\   -.,_____,.-   /_           ");
    puts("              /~~\\                                                             .-"  "-.,_________,.-"  "-.,        ");
    puts("            / ==== \\                                                         /          |       |         \\       ");
    puts("           / ~~o o  \\                                                       |           l.     .l           |      ");
    puts("             _\\ -/_                                                         l.           |     |           .l      ");
    puts("            /  \\ / \\                                                       |           l.   .l           | \\,     "); 
    puts("          || |  | | ||                                                      l.           |   |           .l   \\,    ");       
    puts("          || |  | | ||                                                      |           |   |           |      \\,   ");
    puts("          (' |====| ')                                                      l.          |   |          .l        |  "); 
    puts("             | || |                                                         |          |---|          |         |   ");
    puts("             (_)(_)                                                         / -        \\   /-.,__,.-\\-.,_,.- \\   ");
    puts("             |_||_|                                                        |            \\ /            |         |  ");
    puts("             |_||_|                                                        |             |             |         |  ");
    puts("            /__][__\\                                                      \\__|__|__|__\\__|__|__|__/\\_|__|__/   ");
    puts("=================================================================================================================   ");    
    puts("    1.일반공격 2.마법공격 3.아이템사용 4.도망가기                                                                          ");                                   

   

    return;
}





void attack_orc(int x){

    system("clear");
    printf("                                                                                       < 데미지 : %d>\n", x           );
    printf("                                                                                        ( / \\ \\   /\\           \n");
    printf("                                              /~~\\                                      / /   | `   \\           \n");
    printf("                                             /==== \\                                    O O   )      |           \n");
    printf("                                            / ~~o o \\              .*                   ' ^                      \n");
    printf("                                             _\\ -/_             .*'                     (_.)  _ )    /           \n");
    printf("                                            / \\ / \\          .*'                       `.___/`    /             \n");
    printf("                                           //|  | |\\       .*'                          `-----' /                \n");
    printf("                                          || |  | | \\    .*'             &lt;----.     __ / __   \\              \n");
    printf("                                          || |  | |  \\ /''               &lt;----|====O)))==) \\) /============= \n");
    printf("                                          (' |====|   /)/                 &lt;----'    `--' `.__,' \\             \n");
    printf("                                             | || |  </                                  |         |              \n");
    printf("                                             (_)(_)                                      \\       /               \n");
    printf("                                             |_||_|                                   ____( (_   /                \n");
    printf("                                             |_||_|                                 ,'  ,----'   |                \n");
    printf("                                            /__][__\\                                `--u__________y              \n");
    printf("=================================================================================================================\n");

    usleep(1100000);

    return;

}



void attack_zombi(int x){


    system("clear");

    printf("                                                                                       < 데미지 : %d>\n", x           );
    puts("                                                                                                                      ");
    puts("                                              /~~\\                                                                   ");
    puts("                                             /==== \\                       ㅡ  ㅡ                                     ");
    puts("                                            / ~^ ^ \\              .*     / @   #   \\                                ");
    puts("                                             _\\ - /_             .*'    (    ^     ,)                                ");
    puts("                                            / \\ / \\          .*'        \\         /-._                             ");
    puts("                                           '/|  | |\\       .''           `._____.'\\   `--.__                        ");
    puts("                                          || |  | | \\    .*'                    \\/         `/``\"\"\"'-.            ");
    puts("                                          || |  | |  \\ /''                       /    )     /         :              ");
    puts("                                          (' |====|   /)/                         |   /\\    |  .--.     :            ");
    puts("                                             | || |  </                           /  /\1`\\   \\/    `.__.:.____.-.   ");
    puts("                                             (_)(_)                              /  / /`\\ `\\`/    .-\"..____.-.     ");
    puts("                                             |_||_|                          _.-'  /_/   `\\ `\\                \\-.  ");
    puts("                                             |_||_|                         `=----'        `\\ `\\--------\'\"\"`-. \\");
    puts("                                            /__][__\\                                        `-./             `\"     ");
    puts("=================================================================================================================");

    usleep(1100000);
    return;

}

void attack_basillisk(int x){

    system("clear");

    printf("                                                                                       < 데미지 : %d>\n", x           );
    puts("                                                                                                       _..-=~=-._   ");
    puts("                                                                                                  _.-~'          ~. ");
    puts("                                              /~~\\                                   __..---~~~~~                 ~. ");
    puts("                                             /==== \\                               _.-~~                      _.._     ~. ");
    puts("                                            / ~^ ^ \\              .*           _ -~_                         /    \\      ; ");
    puts("                                             _\\ - /_             .*'          ( ` '@)                       {      |      : ");
    puts("                                            / \\ / \\          .*'              /                             |      |      : ");
    puts("                                           //|  | |\\       .*'               /     /}         (  )          |      |     .- ");
    puts("                                          || |  | | \\    .*'                /     //-=-~-_-_  |  |          \\      ;    .' ");
    puts("                                          || |  | |  \\ /;'                 /     //     | =._-|  }/ / / /_.==\\     ; _.' ");
    puts("                                          (' |====|   /)/                 ( oo  //|     = )  ~| /.__..-='|    \\    :' ");
    puts("                                             | || |  </                      |*| *   / /    / /      \\  |     ([ ]) ");
    puts("                                             (_)(_)                          |*| *   / /    / /      \\  |     ([ ]) ");
    puts("                                             |_||_|                            |*    /_/    / /       (  ]     `/ \' ");
    puts("                                             |_||_|                             |   (((|   /_/      __/_/__    -| |-- ");
    puts("                                            /__][__\\                                     (((|      -----     __|_|__ ");
    puts("=================================================================================================================");

    usleep(1100000);

    return ;

}

void attack_boss(int x){

    system("clear");

    printf("                                                                                       < 데미지 : %d>\n", x           );
    puts("                                                                                          ,.-" "-.,                 ");
    puts("                                                                                         /   ===   \\                ");
    puts("                                                                                        /  =======  \\               ");
    puts("                                                                                     __|  (o)   (0)  |__            ");
    puts("                                                                                    / _|    .---.    |_ \\           ");
    puts("                                                                                   | /.----/ O O \\----\\ |          ");
    puts("                                                                                     \\/     |     |     \\/           ");             
    puts("                                                                                     |                   |           ");         
    puts("                                              /~~\\                                 _\\   -.,_____,.-   /_           ");  
    puts("                                             /==== \\                            .-"  "-.,_________,.-"  "-.,        ");   
    puts("                                            / ~^ ^ \\              .*          /          |       |          \\       ");
    puts("                                             _\\ - /_             .*'          |           l.     .l           |      ");
    puts("                                            / \\ / \\          .*'             l.           |     |           .l      ");  
    puts("                                           //|  | |\\       .*'               |           l.   .l           | \\,     "); 
    puts("                                          || |  | | \\    .*'                 l.           |   |           .l   \\,    "); 
    puts("                                          || |  | |  \\ /*'                  |           |   |           |      \\,   ");
    puts("                                          (' |====|   /)/                      l.          |   |          .l    |    "); 
    puts("                                             | || |  </                     |          |---|          |         |   ");
    puts("                                             (_)(_)                        /-.,__,.-\\    / -.,__,.- \\-.,_,.-\\     ");
    puts("                                             |_||_|                       |            \\ /            |        |     ");    
    puts("                                             |_||_|                       |             |             |         |    ");     
    puts("                                            /__][__\\                     \\__|__|__|__/ \\__|____|__/ \\_|__|__/   ");            
    puts("=================================================================================================================     ");



    usleep(1100000);

    return ;

}





void poison_scene(int x) {       

    system("clear");

    puts("=================================================================================================================   ");             
    puts("                                            ( )                    ( )_                                              ");
    puts("                                            (_, |        __ __      | ,_)                                             ");
    puts("                                               \'\\     /  ^  \\    /'/                                                ");
    puts("                                                '\'\\, /       \\,/'/'                                                 ");
    puts("                                                   '\\| []   [] |/'                                                  ");
    puts("                                                     (_  /^\\  _)                                                    ");
    puts("                                                       \\  ~  /                                                      ");
    puts("                                                       /HHHHH\\                                                      ");
    puts("                                                     /'/{^^^}\'\\                                                    ");
    puts("                                                _,/'/'   ^^^  '\'\\,_                                                ");
    puts("                                                (_, |           | ,_)                                               ");
    puts("                                                  (_)           (_)                                                 ");
    puts("                                                    중독 되었습니다.                                                  ");
    printf("                                                     <HP %d 감소>\n", x                                                   );
    puts("=================================================================================================================   ");

    usleep(700000);
    return;
}






void monster_attack_scene(int x) {       
    
    int damage = x;

    system("clear");
   
    puts("                                                      적 공격 ");

    // puts("=================================================================================================================   ");             
    // puts("                                                                                                                    "); 
    // puts("                                                                                                                    "); 
    // puts("                                                                                "); 
    // puts("                                                                                                                    "); 
    // puts("                                             ▂▃▅▇█▓▒░ ENEMY TURN ░▒▓█▇▅▃▂                                                                             "); 
    // puts("                                                                                                                    "); 
    // puts("                                                                                                                    "); 
    // puts("                                                                                                                    "); 
    // puts("                                                                                                                    ");
    // puts("                                                                                                                    ");
    // puts("                                                                                                                    ");
    // printf("                                                                                                                  ");
    // puts("=================================================================================================================   ");
  
 
    usleep(500000);

    puts("=================================================================================================================  ");             
    puts("                                                                                                                   "); 
    puts("                                            ▂▃▅▇█▓▒░ ENEMY TURN ░▒▓█▇▅▃▂                                           "); 
    puts("                                                                                                                   "); 
    puts("                                                      ⚡                                                            "); 
    puts("                                                                                                                   "); 
    printf("                                              < 플레이어 HP %d 감소>", damage                                        );
    puts("                                                                                                                   "); 
    puts("                                                                                                                   "); 
    puts("                                                             ⚡                                                     ");
    puts("                                                                                                                   ");
    puts("=================================================================================================================  ");
    usleep(1400000);

    return;
}



void cri_scene(void){

    system("clear");
    puts("=================================================================================================================  ");             
    puts("                                                                                                                   "); 
    puts("                                                                 🔥    🔥                                                "); 
    puts("                            🔥🔥🔥🔥🔥🔥🔥🔥   🔥                🔥    🔥                               ");
    puts("                            🔥                  🔥                🔥🔥🔥🔥                               "); 
    puts("                            🔥                  🔥                🔥    🔥                                   "); 
    puts("                            🔥            🔥🔥🔥🔥                🔥🔥🔥🔥                                  "); 
    puts("                            🔥                  🔥                                               "); 
    puts("                            🔥                  🔥          🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥                                                   "); 
    puts("                            🔥🔥🔥🔥🔥🔥🔥      🔥                                                                          "); 
    puts("                                                                   🔥🔥🔥🔥🔥                       ");
    puts("                                                                           🔥                                            ");
    puts("                                                                   🔥🔥🔥🔥🔥                            ");
    puts("                                                                   🔥                                                ");
    puts("                                                                   🔥🔥🔥🔥🔥                                                ");
    puts("=================================================================================================================  ");
    usleep(600000);
    return;
}



void fireball_act(int x){

    system("clear");

    puts("=================================================================================================================     ");
    puts("");
    puts("");
    puts("");
    puts("");
    puts("");
    puts("                     🔥 🔥 🔥 🔥 🔥");
    puts("");
    puts("");
    puts("");
    puts("");
    puts("");
    puts("=================================================================================================================     ");

    usleep(400000);
    system("clear");

    puts("=================================================================================================================   ");
    puts("                                                                                                                     ");
    printf("                                                                                  < 데미지 : %d >\n", x                    );
    puts("                                                                                                                     ");
    puts("                                                                                        🔥🔥🔥                       ");
    puts("                                                                                       🔥🔥🔥🔥                      ");
    puts("                                                                                      🔥🔥🔥🔥🔥                     ");
    puts("                                                                                      🔥🔥🔥🔥🔥                     ");
    puts("                                                                                       🔥🔥🔥🔥                      ");
    puts("                                                                                        🔥🔥🔥                       ");
    puts("                                                                                                                     ");
    puts("                                                                                                                     ");
    puts("=================================================================================================================    ");

    
    usleep(700000);

    return;

}

void iceball_act(int x){
    
    system("clear");

    puts("=================================================================================================================     ");
    puts("");
    puts("");
    puts("");
    puts("");
    puts("");
    puts("                     ❄️ ❄️ ❄️ ❄️ ❄️");
    puts("");
    puts("");
    puts("");
    puts("");
    puts("");
    puts("=================================================================================================================     ");
    

    usleep(400000);
    system("clear");

    puts("=================================================================================================================    ");
    puts("                                                                                                                     ");
    printf("                                                                           < 데미지 : %d >\n", x                     );
    puts("                                                                                                                     ");
    puts("                                                                                   ❄️ ❄️ ❄️                       ");
    puts("                                                                                  ❄️ ❄️ ❄️ ❄️                      ");
    puts("                                                                                 ❄️ ❄️ ❄️ ❄️ ❄️                     ");
    puts("                                                                                 ❄️ ❄️ ❄️ ❄️ ❄️                     ");
    puts("                                                                                  ❄️ ❄️ ❄️ ❄️                      ");
    puts("                                                                                   ❄️ ❄️ ❄️                       ");
    puts("                                                                                                                     ");
    puts("                                                                                                                     ");
    puts("=================================================================================================================    ");

    
    usleep(700000);

    return;

}


void meteo_act(int x){

    system("clear");

    puts("=================================================================================================================     ");
    puts("");
    puts("");
    puts("");
    puts("");
    puts("");
    puts("                     ☄️ ☄️ ☄️ ☄️ ☄️                                     ");
    puts("");
    puts("");
    puts("");
    puts("");
    puts("");
    puts("=================================================================================================================     ");
    

    usleep(400000);
    system("clear");

    puts("=================================================================================================================    ");
    puts("                                                                                                                     ");
    printf("                                                                                  < 데미지 : %d >\n", x                     );
    puts("                                                                                                                     ");
    puts("                                                                                  ☄️  ☄️  ☄️                         ");
    puts("                                                                                       ☄️     ☄️                     ");
    puts("                                                                                     ☄️     ☄️                       ");
    puts("                                                                                       ☄️         ☄️                 ");
    puts("                                                                                       ☄️                            ");
    puts("                                                                                      ☄️      ☄️                     ");
    puts("                                                                                                                     ");
    puts("                                                                                                                     ");
    puts("=================================================================================================================    ");

    
    usleep(700000);

    return;

}















