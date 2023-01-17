//
// Created by 21961 on 2023/1/17.
//

#ifndef UNTITLED_TRIGGER_H
#define UNTITLED_TRIGGER_H
#endif //UNTITLED_TRIGGER_H
#include "verify.h"

void chack_No(int i) {
    if (i > 0) {
        string str=people[i].num;
        for (int k = 0; k < i; k++) {
            if (strcmp(people[k].num, people[i].num) == 0) {
                printf("您输入的职工号已存在，请更换号码!");
                printf("职工号：");
                scanf("&d", people[i].num);
                chack_No(i);
                break;
            }else if(str.size()>11){
                printf("您输入的职工号位数不正确，请更换号码!");
                printf("职工号：");
                scanf("&d", people[i].num);
                chack_No(i);
                break;
            }
        }
    }
}


void exitcx(){
    system("cls");
    printf("Bye!");
    _sleep(1*1000);
    HANDLE hself = GetCurrentProcess();
    TerminateProcess(hself, 0);
}