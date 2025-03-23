#include <stdio.h>
#define FUNDLEN 50


struct funds{
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;

};

double sum(struct funds moolah);

int main(void)
{
    struct funds stan={
        "국민은행",
        4032.27,
        "동아상호신용금고",
        8543.94
    };
    printf("Stan씨의 총 잔고는 $%.2f입니다.\n", sum(stan));
    return 0;
}

double sum(struct funds moolah)
{
    return (moolah.bankfund+ moolah.savefund);
}
/**
 * 
 * 최신의 c는 한 구조체를 다른 구조체에 대입하는 것을 허용한다. 배열의 경우에는 이것을 할수 없다. n_data와 o_data가 같은 데이터
 * 데이터형의 ㄱ조체라면
 * o_data = n_data; 한 구조체를 다른 구조체에 대입한다. 
 * 
 */