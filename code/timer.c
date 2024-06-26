#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/ioctl.h>
#include<sys/stat.h>
#include<string.h>
#include<time.h>

#define fnd "/dev/fnd"

unsigned char fnd_num[4] = {0,};
int fnds;
unsigned char Time_Table[]={~0x3f,~0x06,~0x5b,~0x4f,~0x66,~0x6d,~0x7d,~0x07,~0x7f,~0x67,~0x00};

void update_display(int m, int s);

int main(){
    fnds = open(fnd, O_RDWR);
    if(fnds < 0){
        printf("Can't open FND.\n");
        exit(0);
    }

    int m = 3;  // 시작 분 설정 (3분)
    int s = 0;  // 시작 초 설정 (0초)

    while(m >= 0 && s >= 0){
        update_display(m, s);
        sleep(1);

        if(s == 0){
            if(m == 0){
                break;
            }
            m--;
            s = 59;
        } else {
            s--;
        }
    }

    // 시간 종료 후 00:00 표시
    update_display(0, 0);
    close(fnds);
    return 0;
}

void update_display(int m, int s){
    fnd_num[0] = Time_Table[m / 10]; // 분의 10의 자리
    fnd_num[1] = Time_Table[m % 10]; // 분의 1의 자리
    fnd_num[2] = Time_Table[s / 10]; // 초의 10의 자리
    fnd_num[3] = Time_Table[s % 10]; // 초의 1의 자리

    write(fnds, &fnd_num, sizeof(fnd_num));
}