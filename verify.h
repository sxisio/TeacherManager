//
// Created by 21961 on 2023/1/17.
//
#include "people.h"
#include "environment.h"

#ifndef UNTITLED_VERIFY_H
#define UNTITLED_VERIFY_H
using namespace std;
#endif //UNTITLED_VERIFY_H


/*У������*/
void verify_name(int i,int pf){
    do{
        /*���������Ƿ�Ϊ�����ַ��������½��͹���*/
        /*�½�������*/
//        regex patten("/^[\\u4e00-\\u9fa5]+��[\\u4e00-\\u9fa5]+$/");
        /*����У������*/regex patten("([\\u4e00-\\\\u9fa5])");
        if(regex_match(people[i].name,patten)){
            pf=pf-1;
            printf("������������������ [ ]");
            scanf("%s", people[i].name);
        }else{
            /*���������ַ�������*/
            string str=people[i].name;
            if (str.size()>20){
                pf=pf-1;
                printf("������������������ [ ]");
                scanf("%s", people[i].name);
            }else{
                pf=0-pf;
            }
        }
    }while(pf<0);
}

/*У���Ա�*/
void verify_sex(int i,int pf){
    do{
        const char *Sex_man="��";
        const char *Sex_woman="Ů";
        if(strcmp(people[i].sex,Sex_man)==0 || strcmp(people[i].sex,Sex_woman)==0){
            pf=0-pf;
        }else{
            pf=pf-1;
            printf("������������������ [ ]");
            scanf("%s", people[i].sex);
        }
    }while(pf<0);
}

/*У������*/
void verify_age(int i,int pf){
    do{
        /*У������*/
        regex patten("([1-9]\\d*)");
        if(strlen(people[i].age)<3 && !regex_match(people[i].age,patten)){
            pf=0-pf;
        }else{
            pf=pf-1;
            printf("������������������ [ ]");
            scanf("%s", people[i].age);
        }
    }while(pf<0);
}

/*У���ֻ���*/
void verify_telephone(int i,int pf){
    do{
        /*У���ֻ��ţ����ڣ�*/
        regex patten("(0?(13|14|15|18|17)[0-9]{9})");
        if(strlen(people[i].telephone)==11 && !regex_match(people[i].telephone,patten)){
            pf=0-pf;
        }else{
            pf=pf-1;
            printf("������������������ [ ]");
            scanf("%s", people[i].telephone);
        }
    }while(pf<0);
}
