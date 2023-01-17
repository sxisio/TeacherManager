//
// Created by 21961 on 2023/1/17.
//
#include "trigger.h"
#ifndef UNTITLED_FUNCTION_H
#define UNTITLED_FUNCTION_H
#define N 100
#endif //UNTITLED_FUNCTION_H

void search();//搜索和删除
void modify();//修改提示、保存和数值传输小界面
void save(int n);//保存
int load();//求有多少个数据
void del();//删除
int modify_data(int i);//真修改信息
void input(int i);//依次存入的提示、保存和数值传输
void enter();//search功能的小组件：输入提示和值的传输
void browse(int m);//打印
void add();//添加命令
void menu();//菜单
void CheckMenu(int n);//功能选择菜单
void CheckMenudo(int n, int f);//选择功能菜单执行
void errorSwitch();//预防菜单输入非法
void printf_back(int m);
void chack_No(int i);//判断数据是否重复
void printf_one(int i);//数据行格式控制
void printf_face();//标题行格式控制

void input(int i) {
    //no_input(i,i);
    int pf=0;
    printf("职工号:");
    scanf("%s", people[i].num);
    chack_No(i);
    printf("姓名:");
    scanf("%s", people[i].name);
    verify_name(i,pf);
    printf("性别:");
    scanf("%s", people[i].sex);
    verify_sex(i,pf);
    printf("年龄:");
    scanf("%s", people[i].age);
    verify_age(i,pf);
    printf("学历:");
    scanf("%s", people[i].education);
    printf("工资:");
    scanf("%s", people[i].wage);
    printf("住址:");
    scanf("%s", people[i].address);
    printf("电话:");
    scanf("%s", people[i].telephone);
    verify_telephone(i,pf);
}

void enter() {
    int i, n;
    printf("请输入人数(0-%d) :", N - 1);
    scanf("%d", &n);
    int pf=0;
    do{
        if(n%1==0&&n<100&&n>=0){
            pf=0-pf;
        }else{
            pf=pf-1;
            printf("输入有误！请重新输入 [ ]");
            scanf("%d", &n);
        }
    }while(pf<0);
    switch(n){
        case 0:
        {
            printf("录入信息结束");
            printf("放弃输入进入选择菜单");
            printf_back(1);
        }
        default:
        {
            printf("\n 录入信息\n");
            for (i = 0; i < n; i++) {
                printf("\n 请输入第%d个人的信息.", i + 1);
                input(i);
            }
            if (i != 0)save(n);
            printf_back(1);
        }
    }
}

void browse(int m) {
    int i, n;
    n = load();
    printf_face();
    for (i = 0; i < n; i++) {
        if ((i != 0) && (i % 10 == 0)) {
            printf("\n\n按任意键继续....");
            getch();
            puts("\n\n");
        }
        printf_one(i);
    }
    printf("\t共有%d条记录.\n", n);
//    getch();
    if (m == 1) {
        CheckMenu(3);
    } else {
    }
}

void search() {
    int i, n, k, w1 = 1, w2, w3, w4, m, a;
    struct people p;
    n = load();
    do {
        printf("\n选择你要查询的方式 \n\t1).按学历 2).按职工号 [ ]\b\b");
        scanf("%d", &m);
        int pf=0;
        do{
            if(m==1||m==2){
                pf=0-pf;
            }else{
                pf=pf-1;
                printf("输入有误！请重新输入 [ ]");
                scanf("%d", &m);
            }
        }while(pf<0);
        switch (m) {
            case 1:
            {
                do {
                    k = -1;
                    printf("\n\n请输入你要查询的学历：");
                    scanf("%s", p.education);
                    printf_face();
                    for (i = 0; i < n; i++)
                        if (strcmp(p.education, people[i].education) == 0) {
                            k = i;
                            printf_one(k);
                            break;
                        }
                    if (k == -1) {
                        printf("\n\n你输入的学历不存在！");
                        printf("\n\n你想继续查询吗？\n\t 1).是 2).否 [ ]\b\b");
                        scanf("%d", &w1);
                        int pf=0;
                        do{
                            if(w1==1||w1==2){
                                pf=0-pf;
                            }else{
                                pf=pf-1;
                                printf("输入有误！请重新输入 [ ]");
                                scanf("%d", &w1);
                            }
                        }while(pf<0);
                        if (w1 == 2)
                            printf_back(4);
                    }
                } while (k == -1 && w1 == 1);
                break;
            }
            case 2:
            {
                do {
                    k = -1;
                    printf("\n\n请输入你要查询的职工号：");
                    scanf("%s", p.num);
                    printf_face();
                    for (i = 0; i < n; i++)
                        if (strcmp(p.num, people[i].num) == 0) {
                            k = i;
                            printf_one(k);
                            break;
                        }
                    if (k == -1) {
                        printf("\n\n你输入的职工号不存在！");
                        printf("\n\n你想继续查询吗？\n\t1).是 2).否 [ ]\b\b");
                        scanf("%d", &w1);
                        int pf=0;
                        do{
                            if(w1==1||w1==2){
                                pf=0-pf;
                            }else{
                                pf=pf-1;
                                printf("输入有误！请重新输入 [ ]");
                                scanf("%d", &w1);
                            }
                        }while(pf<0);
                        if (w1 == 2)
                            printf_back(4);
                    }
                } while (k == -1 && w1 == 1);
                break;
            }
        }

        w4 = 0;
        w3 = 0;
        if (k != -1) {
            printf("\n\n请选择你要进行的操作:\n\t 1).查询 2).修改 3).删除 4).返回功能菜单 [ ]\b\b");
            scanf("%d", &w2);
            int pf=0;
            do{
                if(w2%1==0&&w2<5&&w2>0){
                    pf=0-pf;
                }else{
                    pf=pf-1;
                    printf("输入有误！请重新输入 [ ]");
                    scanf("%d", &w2);
                }
            }while(pf<0);
            switch (w2) {
                case 1:
                    search();
                    break;
                case 2:
                    w3 = modify_data(k);
                    break;
                case 3:
                {
                    printf("\n你确定要删除吗?\n\t 1).是 2).否 [ ]\b\b");
                    scanf("%d", &w4);
                    int pf=0;
                    do{
                        if(w4==1||w4==2){
                            pf=0-pf;
                        }else{
                            pf=pf-1;
                            printf("输入有误！请重新输入 [ ]");
                            scanf("%d", &w4);
                        }
                    }while(pf<0);
                    if (w4 == 1)
                        for (a = k; a < n; a++) {
                            strcpy(people[a].num, people[a + 1].num);
                            strcpy(people[a].name, people[a + 1].name);
                            strcpy(people[a].sex, people[a + 1].sex);
                            strcpy(people[a].age, people[a + 1].age);
                            strcpy(people[a].education, people[a + 1].education);
                            strcpy(people[a].wage, people[a + 1].wage);
                            strcpy(people[a].address, people[a + 1].address);
                            strcpy(people[a].telephone, people[a + 1].telephone);

                        }

                    break;
                }
            }

            if (w3 == 1 || w4 == 1) {
                save(n);
                printf("\n\n操作成功! ^_^ ");
                printf("\n\n请输入你要进行的操作： \n\t 1).继续查询 2).返回上一级 [ ]\b\b");
                scanf("%d", &w2);
            }
        }
    } while (w2 == 1);
    CheckMenu(4);;
}

void modify() {
    struct people p;
    int i, n, k, w0 = 1, w1, w2 = 0;
    n = load();
    do {
        k = -1;
        printf_face();
        for (i = 0; i < n; i++) {
            if ((i != 0) && (i % 10 == 0)) {
                printf("\n\n请记着你要修改的职工号。按任意键继续 ...");
                getch();
                puts("\n\n");
            };
            printf_one(i);
        }
        do {
            printf("\n\n请输入你要修改的职工信息的职工号:");
            scanf("%s", p.num);
            for (i = 0; i < n; i++)
                if (strcmp(p.num, people[i].num) == 0) {
                    k = i;
                    p = people[i];
                }
            if (k == -1)printf("\n\n你的输入有误，请从新输入");
        } while (k == -1);
        printf_face();
        printf_one(k);
        w1 = modify_data(k);
        if (w1 == 1) {
            printf("\n操作成功! ^_^.\n是否继续修改？\n\n\t 1).是 2).否\t[ ]\b\b");
            scanf("%d", &w0);
            int pf=0;
            do{
                if(w0==1||w0==2){
                    pf=0-pf;
                }else{
                    pf=pf-1;
                    printf("输入有误！请重新输入 [ ]");
                    scanf("%d", &w0);
                }
            }while(pf<0);
            w2 = 1;
        } else {
            w0 = 0;
            if (w2 == 1)
                people[k] = p;
        }
        if (w0 != 1 && w2 == 1)
            save(n);
    } while (w0 == 1);
    browse(2);
    printf_back(2);
}
void save(int n) {
    FILE *fp;
    int i;
    if ((fp = fopen("infor.txt", "wb")) == NULL) {
        printf("\n文件打开失败！\n");
        //return NULL;
    }
    for (i = 0; i < n; i++)
        if (people[i].num != 0)
            if (fwrite(&people[i], sizeof(struct people), 1, fp) != 1)
                printf("文件写入失败！\n");
    fclose(fp);
}

int load() {
    FILE *fp;//定义文件指针
    int i;
    if ((fp = fopen("infor.txt", "rb")) == NULL) {
        printf("\n文件打开失败!\n");
        return NULL;
    }
    for (i = 0; !feof(fp); i++)
        fread(&people[i], sizeof(struct people), 1, fp);
    fclose(fp);
    return (i - 1);
}

void del() {
    int w4 = 0, a, k = -1, n, w2 = 0;
    n = load();
    do {
        int i, n;
        n = load();
        printf_face();
        for (i = 0; i < n; i++) {
            if ((i != 0) && (i % 10 == 0)) {
                printf("\n\n按任意键继续....");
                getch();
                puts("\n\n");
            }
            printf_one(i);
        }
        printf("\t共有%d条记录.\n", n);

        printf("\n你确定要删除吗?\n\t 1).是 2).否 [ ]\b\b");
        scanf("%d", &w4);
        int pf=0;
        do {
            if (w4 == 1 || w4 == 2) {
                pf = 0 - pf;
                printf("\n\n操作成功! ^_^ ");
            } else {
                pf = pf - 1;
                printf("\n\n输入有误，请重新输入 ^_^ ");
                printf("\n你确定要删除吗?\n\t 1).是 2).否 [ ]\b\b");
                scanf("%d", &w4);
            }
        } while (pf < 0);
        switch (w4) {
            case 1:
            {
                for (a = k; a <= n; a++) {
                    strcpy(people[a].num, people[a + 1].num);
                    strcpy(people[a].num, people[a + 1].num);
                    strcpy(people[a].name, people[a + 1].name);
                    strcpy(people[a].sex, people[a + 1].sex);
                    strcpy(people[a].age, people[a + 1].age);
                    strcpy(people[a].education, people[a + 1].education);
                    strcpy(people[a].wage, people[a + 1].wage);
                    strcpy(people[a].address, people[a + 1].address);
                    strcpy(people[a].telephone, people[a + 1].telephone);
                }
                n = n - 1;
                save(n);
                printf("\n\n请输入你要进行的操作： \n\t 1).继续删除 2).功能菜单 [ ]\b\b");
                scanf("%d", &w2);
                int pf = 0;
                do {
                    if (w2 == 1 || w2 == 2) {
                        pf = 0 - pf;
                        printf("\n\n操作成功! ^_^ ");
                    } else {
                        pf = pf- 1;
                        printf("\n\n输入有误，请重新输入 ^_^ ");
                        printf("\n\n请输入你要进行的操作： \n\t 1).继续删除 2).功能菜单 [ ]\b\b");
                        scanf("%d", &w2);
                    }
                } while (pf < 0);
                break;
            }
            case 2:
            {
                int pf=0;
                printf("\n\n请输入你要进行的操作： \n\t 1).继续删除 2).功能菜单 [ ]\b\b");
                scanf("%d", &w2);
                do {
                    if (w2 == 1 || w2 == 2) {
                        pf = 0 - pf;
                        printf("\n\n操作成功! ^_^ ");
                    } else {
                        pf = pf- 1;
                        printf("\n\n输入有误，请重新输入 ^_^ ");
                        printf("\n\n请输入你要进行的操作： \n\t 1).继续删除 2).功能菜单 [ ]\b\b");
                        scanf("%d", &w2);
                    }
                } while (pf < 0);
                break;
            }
        }
    }while (w2 == 1);
    CheckMenu(5);
}

int modify_data(int i) {
    int c, w1;
    do {
        puts("\n请选择你要修改的选项\n\n 1).职工号 2).姓名 3).性别 4).年龄 5).学历 6)工资 7)住址 8)电话 ");
        printf("您的选择是:[ ]\b\b");
        scanf("%d", &c);
        if (c > 8 || c < 1) {
            puts("\n输入错误，请重新输入!");
            getchar();
        }
    } while ((c > 8 || c < 1) && c % 1 != 0);

    do {
        switch (c) {
            case 1:
                printf("职工号:");
                scanf("%s", people[i].num);
                break;
            case 2:
                printf("姓名:");
                scanf("%s", people[i].name);
                break;
            case 3:
                printf("性别:");
                scanf("%s", people[i].sex);
                break;
            case 4:
                printf("年龄:");
                scanf("%s", people[i].age);
                break;
            case 5:
                printf("学历:");
                scanf("%s", people[i].education);
                break;
            case 6:
                printf("工资:");
                scanf("%s", people[i].wage);
                break;
            case 7:
                printf("住址:");
                scanf("%s", people[i].address);
                break;
            case 8:
                printf("电话:");
                scanf("%s", people[i].telephone);
                break;
        }
        puts("\n现在信息:\n");
        printf_face();
        printf_one(i);
        printf("\n你确定吗\n\n\t 1).是 2).否 3).返回且不保存 [ ]\b\b");
        scanf("%d", &w1);
        return w1;
    } while (1 == 1);
}
    void open() {
        const char *filename="info.txt";
        fstream fs;
        fs.open(filename, ios::in);
        if(!fs){
            ofstream fout(filename);
            fout.close();
            system("start info.txt");
            system("pause");
        }else{
            system("start info.txt");
            system("pause");
        }
        CheckMenu(6);
    }
void menu() {
    system("cls");
    int n,w1;
    do {
        system("cls");//清
        printf("\t\t\t\t\t\t职 工 信 息 管 理 系 统          \n");
        printf("\t\t\t\t\t==================菜 单==================\n");
        printf("\t\t\t\t\t             1.输入职工信息              \n");
        printf("\t\t\t\t\t                                       \n");
        printf("\t\t\t\t\t             2.修改职工信息              \n");
        printf("\t\t\t\t\t                                       \n");
        printf("\t\t\t\t\t             3.浏览职工信息              \n");
        printf("\t\t\t\t\t                                       \n");
        printf("\t\t\t\t\t             4.查询职工信息              \n");
        printf("\t\t\t\t\t                                       \n");
        printf("\t\t\t\t\t             5.删除职工信息              \n");
        printf("\t\t\t\t\t                                       \n");
        printf("\t\t\t\t\t             6.读取职工信息              \n");
        printf("\t\t\t\t\t                                       \n");
        printf("\t\t\t\t\t             0.   退出                  \n");
        printf("\t\t\t\t\t                                       \n");
        printf("\t\t\t\t\t=========================================\n");
        printf("\t\t\t请选择(1-6):[ ]\b\b");
        scanf("%d", &n);
        if ((n < 0 || n > 6)&& n%1!=0)
            w1 = 0;
        else w1 = 1;
    } while (w1 == 0);
    switch (n) {
        case 0:
            exitcx();
        case 1:
            enter();
            break;
        case 2:
            modify();
            break;
        case 3:
            browse(1);
            break;
        case 4:
            search();
            break;
        case 5:
            del();
            break;
        case 6:
            open();
            break;
        default:
            errorSwitch();
            break;

    }
}


void CheckMenu(int n) {
    printf("\n选择菜单! ^_^.\n\n\t 1).返回当前功能 2).返回主菜单 3)退出程序\t[ ]\b\b");
    int f;
    int pf=0;
    scanf("%d", &f);
    do{
        if(f%1==0){
            pf=0-pf;
        }else{
            pf=pf-1;
            printf("输入有误！请重新输入 [ ]");
            scanf("%d", &f);
        }
    }while(pf<0);
    CheckMenudo(n, f);
}


void CheckMenudo(int n, int f) {
    system("cls");
    int pf=0;
    do{
        if(f>=1&&f<=3){
            pf=0-pf;
        }else{
            pf=pf-1;
            printf("输入有误！请重新输入 [ ]");
            scanf("%d", &f);
        }
    }while(pf<0);
    switch(f){
        case 1:
            switch(n){
                case 1:
                    enter();
                    break;
                case 2:
                    modify();
                    break;
                case 3:
                    browse(1);
                    break;
                case 4:
                    search();
                    break;
                case 5:
                    del();
                    break;
                case 6:
                    open();
                    break;
                default:
                    printf("输入有误,请重新输入!!");
                    CheckMenu(n);
                    break;
            }
        case 2:
            menu();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("输入有误,请重新输入!!");
            CheckMenu(n);
            break;
    }
}

void errorSwitch(){
    printf("输入错误请重新输入！！");
    _sleep(1*1000);
    system("cls");
    menu();
}
void printf_face() {//标题行
    std::string title[8]={"职工号","姓名","性别","年龄","学历","工资","住址","电话"};
    printf("%9s%12s%10s%9s%9s%11s%10s%22s\n",title[0].c_str(),title[1].c_str(),title[2].c_str(),title[3].c_str(),title[4].c_str(),title[5].c_str(),title[6].c_str(),title[7].c_str());
}

void printf_one(int i) {//数据行
    printf("%9s%9s%9s%9s%9s%10s%9s%30s\n", people[i].num, people[i].name, people[i].sex, people[i].age, people
    [i].education, people[i].wage, people[i].address, people[i].telephone);
}

void printf_back(int m) {
    int w;
    printf("\n\t操作成功!.^_^\n\n");
    printf("请选择：\n\n\t1).浏览所有信息 \t2).返回 : [ ]\b\b");
    scanf("%d", &w);
    int pf=0;
    do {
        if (w == 1 || w == 2) {
            pf = 0 - pf;
            printf("\n\n操作成功! ^_^ ");
        } else {
            pf = pf - 1;
            printf("\n\n输入有误，请重新输入 ^_^ ");
            scanf("%d", &w);
        }
    } while (pf < 0);
    if (w == 1) {
        browse(2);
        CheckMenu(m);
    } else CheckMenu(m);
}

