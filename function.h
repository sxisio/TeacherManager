//
// Created by 21961 on 2023/1/17.
//
#include "trigger.h"
#ifndef UNTITLED_FUNCTION_H
#define UNTITLED_FUNCTION_H
#define N 100
#endif //UNTITLED_FUNCTION_H

void search();//������ɾ��
void modify();//�޸���ʾ���������ֵ����С����
void save(int n);//����
int load();//���ж��ٸ�����
void del();//ɾ��
int modify_data(int i);//���޸���Ϣ
void input(int i);//���δ������ʾ���������ֵ����
void enter();//search���ܵ�С�����������ʾ��ֵ�Ĵ���
void browse(int m);//��ӡ
void add();//�������
void menu();//�˵�
void CheckMenu(int n);//����ѡ��˵�
void CheckMenudo(int n, int f);//ѡ���ܲ˵�ִ��
void errorSwitch();//Ԥ���˵�����Ƿ�
void printf_back(int m);
void chack_No(int i);//�ж������Ƿ��ظ�
void printf_one(int i);//�����и�ʽ����
void printf_face();//�����и�ʽ����

void input(int i) {
    //no_input(i,i);
    int pf=0;
    printf("ְ����:");
    scanf("%s", people[i].num);
    chack_No(i);
    printf("����:");
    scanf("%s", people[i].name);
    verify_name(i,pf);
    printf("�Ա�:");
    scanf("%s", people[i].sex);
    verify_sex(i,pf);
    printf("����:");
    scanf("%s", people[i].age);
    verify_age(i,pf);
    printf("ѧ��:");
    scanf("%s", people[i].education);
    printf("����:");
    scanf("%s", people[i].wage);
    printf("סַ:");
    scanf("%s", people[i].address);
    printf("�绰:");
    scanf("%s", people[i].telephone);
    verify_telephone(i,pf);
}

void enter() {
    int i, n;
    printf("����������(0-%d) :", N - 1);
    scanf("%d", &n);
    int pf=0;
    do{
        if(n%1==0&&n<100&&n>=0){
            pf=0-pf;
        }else{
            pf=pf-1;
            printf("������������������ [ ]");
            scanf("%d", &n);
        }
    }while(pf<0);
    switch(n){
        case 0:
        {
            printf("¼����Ϣ����");
            printf("�����������ѡ��˵�");
            printf_back(1);
        }
        default:
        {
            printf("\n ¼����Ϣ\n");
            for (i = 0; i < n; i++) {
                printf("\n �������%d���˵���Ϣ.", i + 1);
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
            printf("\n\n�����������....");
            getch();
            puts("\n\n");
        }
        printf_one(i);
    }
    printf("\t����%d����¼.\n", n);
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
        printf("\nѡ����Ҫ��ѯ�ķ�ʽ \n\t1).��ѧ�� 2).��ְ���� [ ]\b\b");
        scanf("%d", &m);
        int pf=0;
        do{
            if(m==1||m==2){
                pf=0-pf;
            }else{
                pf=pf-1;
                printf("������������������ [ ]");
                scanf("%d", &m);
            }
        }while(pf<0);
        switch (m) {
            case 1:
            {
                do {
                    k = -1;
                    printf("\n\n��������Ҫ��ѯ��ѧ����");
                    scanf("%s", p.education);
                    printf_face();
                    for (i = 0; i < n; i++)
                        if (strcmp(p.education, people[i].education) == 0) {
                            k = i;
                            printf_one(k);
                            break;
                        }
                    if (k == -1) {
                        printf("\n\n�������ѧ�������ڣ�");
                        printf("\n\n���������ѯ��\n\t 1).�� 2).�� [ ]\b\b");
                        scanf("%d", &w1);
                        int pf=0;
                        do{
                            if(w1==1||w1==2){
                                pf=0-pf;
                            }else{
                                pf=pf-1;
                                printf("������������������ [ ]");
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
                    printf("\n\n��������Ҫ��ѯ��ְ���ţ�");
                    scanf("%s", p.num);
                    printf_face();
                    for (i = 0; i < n; i++)
                        if (strcmp(p.num, people[i].num) == 0) {
                            k = i;
                            printf_one(k);
                            break;
                        }
                    if (k == -1) {
                        printf("\n\n�������ְ���Ų����ڣ�");
                        printf("\n\n���������ѯ��\n\t1).�� 2).�� [ ]\b\b");
                        scanf("%d", &w1);
                        int pf=0;
                        do{
                            if(w1==1||w1==2){
                                pf=0-pf;
                            }else{
                                pf=pf-1;
                                printf("������������������ [ ]");
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
            printf("\n\n��ѡ����Ҫ���еĲ���:\n\t 1).��ѯ 2).�޸� 3).ɾ�� 4).���ع��ܲ˵� [ ]\b\b");
            scanf("%d", &w2);
            int pf=0;
            do{
                if(w2%1==0&&w2<5&&w2>0){
                    pf=0-pf;
                }else{
                    pf=pf-1;
                    printf("������������������ [ ]");
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
                    printf("\n��ȷ��Ҫɾ����?\n\t 1).�� 2).�� [ ]\b\b");
                    scanf("%d", &w4);
                    int pf=0;
                    do{
                        if(w4==1||w4==2){
                            pf=0-pf;
                        }else{
                            pf=pf-1;
                            printf("������������������ [ ]");
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
                printf("\n\n�����ɹ�! ^_^ ");
                printf("\n\n��������Ҫ���еĲ����� \n\t 1).������ѯ 2).������һ�� [ ]\b\b");
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
                printf("\n\n�������Ҫ�޸ĵ�ְ���š������������ ...");
                getch();
                puts("\n\n");
            };
            printf_one(i);
        }
        do {
            printf("\n\n��������Ҫ�޸ĵ�ְ����Ϣ��ְ����:");
            scanf("%s", p.num);
            for (i = 0; i < n; i++)
                if (strcmp(p.num, people[i].num) == 0) {
                    k = i;
                    p = people[i];
                }
            if (k == -1)printf("\n\n��������������������");
        } while (k == -1);
        printf_face();
        printf_one(k);
        w1 = modify_data(k);
        if (w1 == 1) {
            printf("\n�����ɹ�! ^_^.\n�Ƿ�����޸ģ�\n\n\t 1).�� 2).��\t[ ]\b\b");
            scanf("%d", &w0);
            int pf=0;
            do{
                if(w0==1||w0==2){
                    pf=0-pf;
                }else{
                    pf=pf-1;
                    printf("������������������ [ ]");
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
        printf("\n�ļ���ʧ�ܣ�\n");
        //return NULL;
    }
    for (i = 0; i < n; i++)
        if (people[i].num != 0)
            if (fwrite(&people[i], sizeof(struct people), 1, fp) != 1)
                printf("�ļ�д��ʧ�ܣ�\n");
    fclose(fp);
}

int load() {
    FILE *fp;//�����ļ�ָ��
    int i;
    if ((fp = fopen("infor.txt", "rb")) == NULL) {
        printf("\n�ļ���ʧ��!\n");
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
                printf("\n\n�����������....");
                getch();
                puts("\n\n");
            }
            printf_one(i);
        }
        printf("\t����%d����¼.\n", n);

        printf("\n��ȷ��Ҫɾ����?\n\t 1).�� 2).�� [ ]\b\b");
        scanf("%d", &w4);
        int pf=0;
        do {
            if (w4 == 1 || w4 == 2) {
                pf = 0 - pf;
                printf("\n\n�����ɹ�! ^_^ ");
            } else {
                pf = pf - 1;
                printf("\n\n������������������ ^_^ ");
                printf("\n��ȷ��Ҫɾ����?\n\t 1).�� 2).�� [ ]\b\b");
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
                printf("\n\n��������Ҫ���еĲ����� \n\t 1).����ɾ�� 2).���ܲ˵� [ ]\b\b");
                scanf("%d", &w2);
                int pf = 0;
                do {
                    if (w2 == 1 || w2 == 2) {
                        pf = 0 - pf;
                        printf("\n\n�����ɹ�! ^_^ ");
                    } else {
                        pf = pf- 1;
                        printf("\n\n������������������ ^_^ ");
                        printf("\n\n��������Ҫ���еĲ����� \n\t 1).����ɾ�� 2).���ܲ˵� [ ]\b\b");
                        scanf("%d", &w2);
                    }
                } while (pf < 0);
                break;
            }
            case 2:
            {
                int pf=0;
                printf("\n\n��������Ҫ���еĲ����� \n\t 1).����ɾ�� 2).���ܲ˵� [ ]\b\b");
                scanf("%d", &w2);
                do {
                    if (w2 == 1 || w2 == 2) {
                        pf = 0 - pf;
                        printf("\n\n�����ɹ�! ^_^ ");
                    } else {
                        pf = pf- 1;
                        printf("\n\n������������������ ^_^ ");
                        printf("\n\n��������Ҫ���еĲ����� \n\t 1).����ɾ�� 2).���ܲ˵� [ ]\b\b");
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
        puts("\n��ѡ����Ҫ�޸ĵ�ѡ��\n\n 1).ְ���� 2).���� 3).�Ա� 4).���� 5).ѧ�� 6)���� 7)סַ 8)�绰 ");
        printf("����ѡ����:[ ]\b\b");
        scanf("%d", &c);
        if (c > 8 || c < 1) {
            puts("\n�����������������!");
            getchar();
        }
    } while ((c > 8 || c < 1) && c % 1 != 0);

    do {
        switch (c) {
            case 1:
                printf("ְ����:");
                scanf("%s", people[i].num);
                break;
            case 2:
                printf("����:");
                scanf("%s", people[i].name);
                break;
            case 3:
                printf("�Ա�:");
                scanf("%s", people[i].sex);
                break;
            case 4:
                printf("����:");
                scanf("%s", people[i].age);
                break;
            case 5:
                printf("ѧ��:");
                scanf("%s", people[i].education);
                break;
            case 6:
                printf("����:");
                scanf("%s", people[i].wage);
                break;
            case 7:
                printf("סַ:");
                scanf("%s", people[i].address);
                break;
            case 8:
                printf("�绰:");
                scanf("%s", people[i].telephone);
                break;
        }
        puts("\n������Ϣ:\n");
        printf_face();
        printf_one(i);
        printf("\n��ȷ����\n\n\t 1).�� 2).�� 3).�����Ҳ����� [ ]\b\b");
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
        system("cls");//��
        printf("\t\t\t\t\t\tְ �� �� Ϣ �� �� ϵ ͳ          \n");
        printf("\t\t\t\t\t==================�� ��==================\n");
        printf("\t\t\t\t\t             1.����ְ����Ϣ              \n");
        printf("\t\t\t\t\t                                       \n");
        printf("\t\t\t\t\t             2.�޸�ְ����Ϣ              \n");
        printf("\t\t\t\t\t                                       \n");
        printf("\t\t\t\t\t             3.���ְ����Ϣ              \n");
        printf("\t\t\t\t\t                                       \n");
        printf("\t\t\t\t\t             4.��ѯְ����Ϣ              \n");
        printf("\t\t\t\t\t                                       \n");
        printf("\t\t\t\t\t             5.ɾ��ְ����Ϣ              \n");
        printf("\t\t\t\t\t                                       \n");
        printf("\t\t\t\t\t             6.��ȡְ����Ϣ              \n");
        printf("\t\t\t\t\t                                       \n");
        printf("\t\t\t\t\t             0.   �˳�                  \n");
        printf("\t\t\t\t\t                                       \n");
        printf("\t\t\t\t\t=========================================\n");
        printf("\t\t\t��ѡ��(1-6):[ ]\b\b");
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
    printf("\nѡ��˵�! ^_^.\n\n\t 1).���ص�ǰ���� 2).�������˵� 3)�˳�����\t[ ]\b\b");
    int f;
    int pf=0;
    scanf("%d", &f);
    do{
        if(f%1==0){
            pf=0-pf;
        }else{
            pf=pf-1;
            printf("������������������ [ ]");
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
            printf("������������������ [ ]");
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
                    printf("��������,����������!!");
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
            printf("��������,����������!!");
            CheckMenu(n);
            break;
    }
}

void errorSwitch(){
    printf("����������������룡��");
    _sleep(1*1000);
    system("cls");
    menu();
}
void printf_face() {//������
    std::string title[8]={"ְ����","����","�Ա�","����","ѧ��","����","סַ","�绰"};
    printf("%9s%12s%10s%9s%9s%11s%10s%22s\n",title[0].c_str(),title[1].c_str(),title[2].c_str(),title[3].c_str(),title[4].c_str(),title[5].c_str(),title[6].c_str(),title[7].c_str());
}

void printf_one(int i) {//������
    printf("%9s%9s%9s%9s%9s%10s%9s%30s\n", people[i].num, people[i].name, people[i].sex, people[i].age, people
    [i].education, people[i].wage, people[i].address, people[i].telephone);
}

void printf_back(int m) {
    int w;
    printf("\n\t�����ɹ�!.^_^\n\n");
    printf("��ѡ��\n\n\t1).���������Ϣ \t2).���� : [ ]\b\b");
    scanf("%d", &w);
    int pf=0;
    do {
        if (w == 1 || w == 2) {
            pf = 0 - pf;
            printf("\n\n�����ɹ�! ^_^ ");
        } else {
            pf = pf - 1;
            printf("\n\n������������������ ^_^ ");
            scanf("%d", &w);
        }
    } while (pf < 0);
    if (w == 1) {
        browse(2);
        CheckMenu(m);
    } else CheckMenu(m);
}

