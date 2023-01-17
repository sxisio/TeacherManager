//
// Created by 21961 on 2023/1/17.
//
#include "people.h"
#include "environment.h"

#ifndef UNTITLED_VERIFY_H
#define UNTITLED_VERIFY_H
using namespace std;
#endif //UNTITLED_VERIFY_H


/*校验姓名*/
void verify_name(int i,int pf){
    do{
        /*检验名称是否为中文字符，包括新疆和国外*/
        /*新建有问题*/
//        regex patten("/^[\\u4e00-\\u9fa5]+·[\\u4e00-\\u9fa5]+$/");
        /*暂替校验中文*/regex patten("([\\u4e00-\\\\u9fa5])");
        if(regex_match(people[i].name,patten)){
            pf=pf-1;
            printf("输入有误！请重新输入 [ ]");
            scanf("%s", people[i].name);
        }else{
            /*检验名称字符串长度*/
            string str=people[i].name;
            if (str.size()>20){
                pf=pf-1;
                printf("输入有误！请重新输入 [ ]");
                scanf("%s", people[i].name);
            }else{
                pf=0-pf;
            }
        }
    }while(pf<0);
}

/*校验性别*/
void verify_sex(int i,int pf){
    do{
        const char *Sex_man="男";
        const char *Sex_woman="女";
        if(strcmp(people[i].sex,Sex_man)==0 || strcmp(people[i].sex,Sex_woman)==0){
            pf=0-pf;
        }else{
            pf=pf-1;
            printf("输入有误！请重新输入 [ ]");
            scanf("%s", people[i].sex);
        }
    }while(pf<0);
}

/*校验年龄*/
void verify_age(int i,int pf){
    do{
        /*校验年龄*/
        regex patten("([1-9]\\d*)");
        if(strlen(people[i].age)<3 && !regex_match(people[i].age,patten)){
            pf=0-pf;
        }else{
            pf=pf-1;
            printf("输入有误！请重新输入 [ ]");
            scanf("%s", people[i].age);
        }
    }while(pf<0);
}

/*校验手机号*/
void verify_telephone(int i,int pf){
    do{
        /*校验手机号（国内）*/
        regex patten("(0?(13|14|15|18|17)[0-9]{9})");
        if(strlen(people[i].telephone)==11 && !regex_match(people[i].telephone,patten)){
            pf=0-pf;
        }else{
            pf=pf-1;
            printf("输入有误！请重新输入 [ ]");
            scanf("%s", people[i].telephone);
        }
    }while(pf<0);
}
