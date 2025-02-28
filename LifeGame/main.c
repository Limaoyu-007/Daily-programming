#define _CRT_SECURE_NO_WARNINGS

/*
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>



typedef struct {
    char name[20];
    int age;
    char sex;
    int intellect;
    int force;
    char keys[7];
}Person;

typedef struct {
    int year;
    int month;
    int day;
}time_Date;

time_Date timer() {
    time_Date redate;
    time_t now = time(NULL);
    struct tm * date = localtime(&now);
    redate.year = date->tm_year + 1900;
    redate.month = date->tm_mon + 1;
    redate.day = date->tm_mday;
    return redate;
}

int everyday( Person *p1, time_Date date)
{
    printf("Today's date is:%d.%d.%d\n", date.year, date.month, date.day);
    printf("What did you do today ?\n");
    printf("1.Study\n");
    printf("2.exercise\n");
    int time1=0;
    int time2=0;
    int choice;
    scanf("%d", &choice);
    switch (choice) {
    case 1:printf("How long you've been studying ?\n");
        scanf("%d", &time1);
        p1->intellect += time1;
        printf("Thank you for your hard work !\n");
        break;

    case 2:printf("How long you've been exercising ?\n");

        scanf("%d", &time2);
        p1->force += time2;
        printf("Thank you for your hard work !\n");
        break;

    }

    return time1;
}

void log_Print(Person p1,time_Date date,int time) {
    printf("--------����ս��---------\n");
    printf("����:%d.%d.%d\n", date.year, date.month, date.day);
    printf("����:%s\n", p1.name);
    if(time>0)
        printf("- ���ˡ�ע������ɢС�֡���%d��רעѧϰ%dСʱ)\n", time);
    printf("��ǰ���ԣ�\n ���� %d \n ���� %d",p1.intellect,p1.force);
}

void save_date(Person p1)
{
    FILE *file;
    file = fopen("log.txt", "w");
    fprintf(file, " %d ", p1.intellect);
    fprintf(file, " %d ", p1.force);
    fclose(file);
    printf("����ɹ���\n");
}

int main() {

    FILE *file;
    char akeys[7];
    time_Date date = timer();

    Person p1;
    Person* p;
    p = &p1;
    p1.intellect;
    p1.force;
    strcpy (p1.keys, "051012");
    p1.age = 19;
    p1.sex = 'm';
    file = fopen("log.txt", "r");
    fscanf(file, "%d", &p1.intellect);
    fscanf(file, "%d", &p1.force);

    strcpy(p1.name, "LiMaoyu");

    printf("Welcome to the game of life\n");
    printf("Please enter your keys:");

    fgets (akeys, 7, stdin);
    akeys[strcspn(akeys, "\n")]='\0';
    printf("\n");
    if (strcmp (p1.keys, akeys)==0) {

        printf("Welcome %s\n", p1.name);
        printf("Your age is %d\n", p1.age);
        printf("Your sex is %c\n", p1.sex);
        printf("Your intellect is %d\n", p1.intellect);
        printf("Your force is %d\n", p1.force);


        int time = everyday(p, date);
        log_Print(p1, date,time);
        save_date(p1);

    }












    else {
        printf("Wrong keys!\n");
        return 0;
    }
    return 0;
}
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>




typedef struct {
    char name[20];
    int age;
    char sex;
    int intellect;
    int force;
    char keys[7];
} Person;

typedef struct {
    int year;
    int month;
    int day;
} time_Date;

time_Date timer() {
    time_Date redate;
    time_t now = time(NULL);
    struct tm* date = localtime(&now);
    redate.year = date->tm_year + 1900;
    redate.month = date->tm_mon + 1;
    redate.day = date->tm_mday;
    return redate;
}

int everyday(Person* p1, time_Date date) {
    printf("Today's date is: %d.%d.%d\n", date.year, date.month, date.day);
    printf("What did you do today?\n");
    printf("1. Study\n");
    printf("2. Exercise\n");
    int time1 = 0;
    int time2 = 0;
    int choice;
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        printf("How long have you been studying?\n");
        scanf("%d", &time1);
        p1->intellect += time1;
        printf("Thank you for your hard work!\n");
        break;
    case 2:
        printf("How long have you been exercising?\n");
        scanf("%d", &time2);
        p1->force += time2;
        printf("Thank you for your hard work!\n");
        break;
    default:
        printf("Invalid choice.\n");
    }
    return time1 + time2;  // ������ʱ��
}

void log_Print(Person p1, time_Date date, int time) {
    printf("--------����ս��---------\n");
    printf("����: %d.%d.%d\n", date.year, date.month, date.day);
    printf("����: %s\n", p1.name);
    if (time > 0)
        printf("- ���ˡ�ע������ɢС�֡���%d��רעѧϰ%dСʱ)\n", time, time);
    printf("��ǰ���ԣ�\n ���� %d \n ���� %d\n", p1.intellect, p1.force);
}

void save_date(Person p1) {
    FILE* file;
    file = fopen("log.txt", "w");
    if (file == NULL) {
        printf("�޷����ļ� log.txt������ʧ�ܡ�\n");
        return;
    }
    fprintf(file, "%d %d", p1.intellect, p1.force);
    fclose(file);
    printf("����ɹ���\n");
}

void ensure_file_exists(const char* filename) {
    FILE* file = fopen(filename, "a");  // ʹ��׷��ģʽȷ���ļ�������
    if (file == NULL) {
        printf("�޷������ļ� %s��\n", filename);
    }
    else {
        fclose(file);  // �ر��ļ�
    }
}

int main() {
    FILE* file;
    char akeys[8];
    time_Date date = timer();

    Person p1 = { "LiMaoyu", 19, 'm', 0, 0, "051012" };  // ��ʼ��Person�ṹ��

    // ȷ���ļ�����
    ensure_file_exists("log.txt");

    // ��ȡlog.txt�ļ��е�����
    file = fopen("log.txt", "r");
    if (file != NULL) {
        fscanf(file, "%d %d", &p1.intellect, &p1.force);
        fclose(file);
    }
    else {
        printf("�޷����ļ� log.txt����ʹ��Ĭ��ֵ��\n");
    }

    printf("Welcome to the game of life\n");
    printf("Please enter your keys:");
    fgets(akeys, sizeof(akeys), stdin);
    akeys[strcspn(akeys, "\n")] = '\0';  // ȥ�����з�

    if (strcmp(p1.keys, akeys) == 0) {
        printf("Welcome %s\n", p1.name);
        printf("Your age is %d\n", p1.age);
        printf("Your sex is %c\n", p1.sex);
        printf("Your intellect is %d\n", p1.intellect);
        printf("Your force is %d\n", p1.force);

        int time = everyday(&p1, date);
        log_Print(p1, date, time);
        save_date(p1);
    }
    else {
        printf("Wrong keys!\n");
        return 0;
    }
    return 0;
}