#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>

// 堅偌 薑爾 掘褻羹
typedef struct _customer {
    char id[20];                        //堅偌 ID
    char name[30];                      //堅偌檜葷
    char phone[20];                     //瞪�食醽�
    char address[60];                   //輿模
}CUSTOMER;

// 紫憮 薑爾 掘褻羹
typedef struct _book{
    char ISBN[100];                     // ISBN
    char title[200];                    // 紫憮薯跡
    char author[200];                   // 盪濠
    char publishing[200];               // 轎っ餌
    int is_rented;                     //1: 渠罹醞, 0: 渠罹醞檜 嬴椒
}BOOK;

//渠罹 薑爾 掘褻羹
typedef struct _rent_info{
    int id;                             // 渠罹 廓��
    int book_ISBN;                      // ISBN
    int customer_id;                    // �蛾纗醽�
    int rent_date;                      // 渠罹 陳瞼
    int ret_date;                       // 奩陶 陳瞼
    int ret_due_date;                   // 奩陶蕨薑 橾濠
    int is_returned;                    //1: 奩陶 諫猿, 0: 渠罹
}RENT_INFO;

void input_customer(void);              // �蛾讔內裟釋狨� 檗橫憮 掘褻羹縑 氬朝л熱
void input_book(void);                  // 疇 薑爾だ橾擊 檗橫憮 掘褻羹縑 氬朝л熱
void new_customer(void);                // 褐敘 堅偌
void new_book(void);                    // 褐敘 疇
int searchname_customer(void);          // 檜葷戲煎 堅偌匐儀
int searchphone_customer(void);         // 翱塊籀煎 堅偌匐儀
int searchtitle_book(void);             // 薯跡戲煎 紫憮匐儀
int searchauthor_book(void);            // 盪濠煎 紫憮匐儀
void modify_customer(void);             // �蛾讔內� 熱薑
void delete_customer(void);             // �蛾讔內� 餉薯
void modify_book(void);                 // 疇薑爾 熱薑
void delete_book(void);                 // 疇薑爾 餉薯
void rent_book(void);                   // 疇 渠罹
void return_book(void);                 // 疇 奩陶
void rent_information(void);            // 渠罹 薑爾


CUSTOMER customer_info[200];             // �蛾讔內虜� 氬晦嬪и 掘褻羹
int c_idx = 0;                          // �蛾讔內虜� 賃偃 氬懊朝雖 蘋遴お
BOOK book_info[200];                    // 疇薑爾蒂 氬晦嬪и 掘褻羹
int b_idx = 0;                          // 疇薑爾蒂 賃偃 氬懊朝雖 蘋遴お
int idx;
RENT_INFO rent;                          //и 偃曖 綠蛤螃 渠罹/奩陶
int rent_id = 1;                        //渠罹廓��



int main(void)
{
    SetConsoleTextAttribute( GetStdHandle ( STD_OUTPUT_HANDLE), 3); //printf僥曖 臢蝶お 儀擊 夥紱橫塭.
    int i, sel = 1;
    input_customer();                   // 堅偌 薑爾 殮溘
    input_book();                       // 疇 薑爾 殮溘

    while (sel != 0)
    {
        system("cls");                // �飛� 雖辦晦 孺紫辦朝 cls 裟擎 clear
        //詭檣詭景

        printf("                                     旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
        printf("                                     早        < 紫憮婦 薑爾 衛蝶蠱>        早\n");
        printf("                                     曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
        printf("                                     早             1. 堅偌 婦葬            早\n");
        printf("                                     早             2. 紫憮 婦葬            早\n");
        printf("                                     早             3. 渠罹 婦葬            早\n");
        printf("                                     早               0. 謙猿               早\n");
        printf("                                     曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
        printf("                                      廓�ㄧ� 摹鷗ж撮蹂: ");
        scanf("%d", &sel);
        r:;
        switch (sel)   //sel檜 馨檜蝶縑 蜃朝 璋濠檜賊 п渡璋濠 馨檜蝶煎 檜翕и棻.
        {
            //堅偌 婦葬 詭景
            case 1:
            while (sel != 0)
            {
                system("cls");            //�飛� 雖辦晦  .. 孺紫辦朝 cls 裟擎 clear
                printf("                                     旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
                printf("                                     早            < 堅偌 婦葬 >            早\n");
                printf("                                     曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
                printf("                                     早        1. 褐敘 �蛾� 蛔煙            早\n");
                printf("                                     早        2. �蛾� 薑爾 熱薑            早\n");
                printf("                                     早        3. �蛾� 薑爾 餉薯            早\n");
                printf("                                     早        4. 瞪羹 �蛾� 葬蝶お 轎溘     早\n");
                printf("                                     早        5. �蛾� 檜葷戲煎 匐儀        早\n");
                printf("                                     早        6. �蛾� 翱塊籀煎 匐儀        早\n");
                printf("                                     曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
                printf("                                     早        9. 詭檣詭景煎 檜翕           早\n");
                printf("                                     早        0. Щ煎斜極 謙猿             早\n");
                printf("                                     曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");;
                printf("                                       廓�ㄧ� 摹鷗ж撮蹂: ");
                scanf("%d", &sel);

                switch (sel)  //sel檜 馨檜蝶縑 蜃朝 璋濠檜賊 п渡璋濠 馨檜蝶煎 檜翕и棻.
                {
                    case 1:
                        new_customer();
                        break;

                    case 2:
                        modify_customer();
                        break;

                    case 3:
                        delete_customer();
                        break;

                    case 4:
                        for (i = 0; i < c_idx; i++)
                        {
                            printf("                                       %s, %s, %s, %s\n"
                            , customer_info[i].id
                            , customer_info[i].name
                            , customer_info[i].phone
                            , customer_info[i].address);
                        }
                        break;

                    case 5:
                        idx = searchname_customer();
                        if (idx == -1)
                        printf("                                       橾纂ж朝 堅偌檜 橈蝗棲棻.\n");
                        else
                        {
                            printf("                                       %s, %s, %s, %s\n"
                            , customer_info[idx].id
                            , customer_info[idx].name
                            , customer_info[idx].phone
                            , customer_info[idx].address);
                        }
                        break;

                    case 6:
                        idx = searchphone_customer();
                        if (idx == -1)
                            printf("                                       橾纂ж朝 堅偌檜 橈蝗棲棻.\n");
                        else
                        {
                            printf("                                       %s, %s, %s, %s\n"
                            , customer_info[idx].id
                            , customer_info[idx].name
                            , customer_info[idx].phone
                            , customer_info[idx].address);
                        }
                        break;

                    case 9:
                        goto r;

                }
                system("pause");
            }
            break;

            //紫憮 婦葬 詭景
            case 2:
            while (sel != 0)
            {

                system("cls");            //�飛� 雖辦晦  .. 孺紫辦朝 cls 裟擎 clear
                printf("                                     旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
                printf("                                     早            < 紫憮 婦葬 >            早\n");
                printf("                                     曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
                printf("                                     早        1. 褐敘 紫憮 蛔煙            早\n");
                printf("                                     早        2. 紫憮 薑爾 熱薑            早\n");
                printf("                                     早        3. 紫憮 薑爾 餉薯            早\n");
                printf("                                     早        4. 瞪羹 紫憮 葬蝶お 轎溘     早\n");
                printf("                                     早        5. 紫憮 薯跡戲煎 匐儀        早\n");
                printf("                                     早        6. 紫憮 盪濠煎 匐儀          早\n");
                printf("                                     曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
                printf("                                     早        9. 詭檣詭景煎 檜翕           早\n");
                printf("                                     早        0. Щ煎斜極 謙猿             早\n");
                printf("                                     曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");;
                printf("                                       廓�ㄧ� 摹鷗ж撮蹂: ");
                scanf("%d", &sel);
                switch (sel)     //sel檜 馨檜蝶縑 蜃朝 璋濠檜賊 п渡璋濠 馨檜蝶煎 檜翕и棻.
                {
                    case 1:
                        new_book();
                        break;

                    case 2:
                        modify_book();
                        break;

                    case 3:
                        delete_book();
                        break;

                    case 4:
                        for (i = 0; i < b_idx; i++)
                        {
                            printf("                                       %s, %s, %s, %s, %d\n"
                            , book_info[i].ISBN
                            , book_info[i].title
                            , book_info[i].author
                            , book_info[i].publishing
                            , book_info[i].is_rented);
                        }
                    break;

                    case 5:
                        idx = searchtitle_book();
                        if (idx == -1)
                            printf("                                       橾纂ж朝 紫憮陛 橈蝗棲棻.\n");
                        else
                        {
                            printf("                                       %s, %s, %s, %s\n"
                            , book_info[idx].ISBN
                            , book_info[idx].title
                            , book_info[idx].author
                            , book_info[idx].publishing);
                        }
                        break;

                    case 6:
                        idx = searchauthor_book();
                        if (idx == -1)
                            printf("                                       橾纂ж朝 紫憮陛 橈蝗棲棻.\n");
                        else
                        {
                            printf("                                       %s, %s, %s, %s\n"
                            , book_info[idx].ISBN
                            , book_info[idx].title
                            , book_info[idx].author
                            , book_info[idx].publishing);
                        }
                        break;

                    case 9:
                        goto r;
                }
                system("pause");
            }
            //渠罹 婦葬 詭景
            case 3:
            while (sel != 0)
            {

                system("cls");            //�飛� 雖辦晦
                printf("                                     旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
                printf("                                     早            < 紫憮 婦葬 >            早\n");
                printf("                                     曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
                printf("                                     早        1. 紫憮 渠罹                 早\n");
                printf("                                     早                                     早\n");
                printf("                                     早        2. 紫憮 奩陶                 早\n");
                printf("                                     早                                     早\n");
                printf("                                     早        3. 渠罹 薑爾                 早\n");
                printf("                                     早                                     早\n");
                printf("                                     曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
                printf("                                     早        9. 詭檣詭景煎 檜翕           早\n");
                printf("                                     早        0. Щ煎斜極 謙猿             早\n");
                printf("                                     曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");;
                printf("                                       廓�ㄧ� 摹鷗ж撮蹂: ");
                scanf("%d", &sel);
                switch (sel)     //sel檜 馨檜蝶縑 蜃朝 璋濠檜賊 п渡璋濠 馨檜蝶煎 檜翕и棻.
                {
                    case 1:
                        rent_book();
                        break;
                    case 2:
                        return_book();
                        break;
                    case 3:
                        rent_information();
                        break;
                    case 9:
                        goto r;

                }
            }
        }
    }
}




// 疇 渠罹
void rent_book()
{
    int i, book_ISBN, customer_id, check;
    time_t timer;
    struct tm * t;

    for (i = 0; i < b_idx; i++)
    {
        if (book_info[i].is_rented == 0)
            printf("%s,%s,%s,%s,%d \n"
                , book_info[i].ISBN
                , book_info[i].title
                , book_info[i].author
                , book_info[i].publishing
                , book_info[i].is_rented);
    }
    idx = searchtitle_book();    //疇薯跡擊 匐儀п憮釭螞 還

                if (idx == -1){
                    printf("                                       橾纂ж朝 紫憮陛 橈蝗棲棻.\n");
                    main();
                }
                else
                {
                    printf("                                       %s,%s,%s,%s,%d\n"
                        , book_info[idx].ISBN
                        , book_info[idx].title
                        , book_info[idx].author
                        , book_info[idx].publishing
                        , book_info[idx].is_rented);
                }

    printf("                                       ===== 渠罹ж溥賊 1, 嬴棲賊 2蒂 殮溘п輿撮蹂! =====\n");
    printf("\n                                       殮溘 : "); scanf("%d", &check);


        if (check == 1){
            book_info[idx].is_rented = 1;
            FILE *fp = fopen("modfiybook.txt","wb");
            for(i = 0; i < b_idx; i++){
                fprintf(fp,                                        "%s,%s,%s,%s,%d\n"
                , book_info[i].ISBN
                , book_info[i].title
                , book_info[i].author
                , book_info[i].publishing
                , book_info[idx].is_rented = 1);
            }
            fclose(fp);
            remove("book_info.txt");
            char oldname[80] = "modfiybook.txt";
            char newname[80] = "book_info.txt";
            rename(oldname, newname);     //oldname 諦 newname 曖 檜葷擊 夥羞棻.
            remove("modfiybook.txt");
        }
        else
        {
            printf("                                       籀擠戲煎 腎給嬴 骨棲棻.");
            main();
          //  system("pause");
        }

    for (i = 0; i < c_idx; i++)
    {
        printf("\n%s,%s,%s,%s\n"
            , customer_info[i].id
            , customer_info[i].name
            , customer_info[i].phone
            , customer_info[i].address);
    }

    printf("堅偌 ID蒂 殮溘ж撮蹂: ");
    scanf("%d", &customer_id);

    printf("紫憮 渠罹陛 諫猿腎歷蝗棲棻.");
    system("pause");
}




// 賅萇 紫憮  奩陶
void return_book()
{
    time_t timer;
    struct tm * t;
    int ret_sec;
    int late_pay, late_day;
    int check;
    int i;

    printf("                                      ===== 賅萇 紫憮蒂 奩陶ж溥賊 1, 嬴棲賊 2蒂 殮溘п輿撮蹂! =====\n");
    printf("\n                                       殮溘 : "); scanf("%d", &check);


        if (check == 1){
            FILE *fp = fopen("modfiybook.txt","wb");
            for(i = 0; i < b_idx; i++){
                fprintf(fp,                                        "%s,%s,%s,%s,%d\n"
                , book_info[i].ISBN
                , book_info[i].title
                , book_info[i].author
                , book_info[i].publishing
                , book_info[i].is_rented = 0);
            }
            fclose(fp);
            remove("book_info.txt");
            char oldname[80] = "modfiybook.txt";
            char newname[80] = "book_info.txt";
            rename(oldname, newname);     //oldname 諦 newname 曖 檜葷擊 夥羞棻.
            remove("modfiybook.txt");
        }
        else
        {
            printf("                                       籀擠戲煎 腎給嬴 骨棲棻.");
            main();
          //  system("pause");
        }

    printf("紫憮 奩陶檜 諫猿腎歷蝗棲棻.\n");
    system("pause");
}




//渠罹 薑爾
void rent_information()
{
    int i, book_ISBN, customer_id;
    time_t timer;
    struct tm * t;
    int check;

    for (i = 0; i < b_idx; i++)
    {
        if (book_info[i].is_rented == 1)
            printf("\nISBN: %s, 疇 薯跡: %s, 盪濠: %s, 轎っ餌: %s, 渠罹醞, 奩陶橾濠 0喇 0錯 0橾 \n"
                , book_info[i].ISBN
                , book_info[i].title
                , book_info[i].author
                , book_info[i].publishing);
    }

    printf("\n渠罹 薑爾蒂 熱薑ж溥賊 1, 嬴棲賊 2蒂 殮溘п輿撮蹂!\n");
    printf("\n                                       殮溘 : ");
    scanf("%d", &check);

    if (check == 1){
        printf("\n熱薑й 紫憮蒂 摹鷗п輿撮蹂.\n");

        idx = searchtitle_book();    //疇薯跡擊 匐儀п憮釭螞 還
        if (book_info[idx].is_rented == !1){
            printf("                                     п渡紫憮朝 渠罹腎雖 彊懊蝗棲棻.\n");
            main();
        }
        else
        {
            printf("                                    ISBN: %s, 薯跡: %s, 盪濠: %s, 轎っ餌: %s, 渠罹薑爾: %d\n"
                        , book_info[idx].ISBN
                        , book_info[idx].title
                        , book_info[idx].author
                        , book_info[idx].publishing
                        , book_info[idx].is_rented);
        }

        printf("                                  ===== п渡 紫憮蒂 奩陶 ж溥賊 1, 嬴棲賊 2蒂 殮溘п輿撮蹂! =====\n");
        printf("\n                                       殮溘 : "); scanf("%d", &check);


        if (check == 1){
            FILE *fp = fopen("modfiybook.txt","wb");
            for(i = 0; i < b_idx; i++){
                fprintf(fp,                                        "%s,%s,%s,%s,%d\n"
                , book_info[i].ISBN
                , book_info[i].title
                , book_info[i].author
                , book_info[i].publishing
                , book_info[idx].is_rented = 0);
            }
            fclose(fp);
            remove("book_info.txt");
            char oldname[80] = "modfiybook.txt";
            char newname[80] = "book_info.txt";
            rename(oldname, newname);     //oldname 諦 newname 曖 檜葷擊 夥羞棻.
            remove("modfiybook.txt");
        }
        else
        {
            printf("                                       籀擠戲煎 腎給嬴 骨棲棻.");
            main();
          //  system("pause");
        }

    }

    else
        {
            printf("                                       籀擠戲煎 腎給嬴 骨棲棻.");
          //  system("pause");
        }
    system("pause");

}




// 薯跡戲煎 紫憮 薑爾 匐儀
int searchtitle_book(void)
{
    int i;
    char title[200], Ctitle[200];
    printf("                                       薯跡: ");
    scanf("%s", title);
    //strcpy(Ctitle, title);

    for (i = 0; i < b_idx; i++)
    {
        if (strcmp(Ctitle, book_info[i].title) == 0)
        return i;
    }
    return -1;
}

// 盪濠煎 紫憮 薑爾 匐儀
int searchauthor_book(void)
{
    int i;
    char author[30];
    printf("                                       盪濠: ");
    scanf("%s", author);

    for (i = 0; i < b_idx; i++)
    {
        if (strcmp(author, book_info[i].author) == 0)
        return i;
    }
    return -1;
}

// 檜葷戲煎 堅偌 薑爾 匐儀
int searchname_customer(void)
{
    int i;
    char name[30];
    printf("                                       檜葷: ");
    scanf("%s", name);

    for (i = 0; i < c_idx; i++)
    {
        if (strcmp(name, customer_info[i].name) == 0)
        return i;
    }
    return -1;
}

// 翱塊籀煎 堅偌 薑爾 匐儀
int searchphone_customer(void)
{
    int i;
    char phone[30];
    printf("                                       翱塊籀: ");
    scanf("%s", phone);
    for (i = 0; i < c_idx; i++)
    {
        if (strcmp(phone, customer_info[i].phone) == 0)
        return i;
    }
    return -1;
}

// 褐敘 疇 薑爾
void new_book(void)
{
    FILE* b_fp = fopen("book_info.txt", "a");
    //掘褻羹 寡翮縑 疇 薑爾蒂 殮溘嫡擠
    printf("                                       ISBN: ");
    scanf("%s", book_info[b_idx].ISBN);
    printf("                                       疇 薯跡: ");
    scanf("%s", book_info[b_idx].title);
    printf("                                       疇 盪濠: ");
    scanf("%s", book_info[b_idx].author);
    printf("                                       轎っ餌: ");
    scanf("%s", book_info[b_idx].publishing);
    book_info[b_idx].is_rented = 0;
    fprintf(b_fp, "%s,%s,%s,%s,%d\n"
        , book_info[b_idx].ISBN
        , book_info[b_idx].title
        , book_info[b_idx].author
        , book_info[b_idx].publishing
        , book_info[b_idx].is_rented);

    b_idx++;
    fclose(b_fp);
}

// 褐敘 堅偌 薑爾
void new_customer(void)
{
    FILE* m_fp = fopen("customer_info.txt", "a");
    //掘褻羹 寡翮縑 堅偌 薑爾蒂 殮溘 嫡擠
    printf("                                       蕨衛 -> samuelLee17, Seongdallor, Mookimchi89\n ");
    printf("                                       �蛾� ID: ");
    scanf("%s", customer_info [c_idx].id);
    printf("                                       蕨衛 -> LeeSangKon, EunSeongWon, KimTaeMoo\n ");
    printf("                                       檜葷: ");
    scanf("%s", customer_info [c_idx].name);
    printf("                                       蕨衛 -> 010-2323-3434, 010-2323-3443, 010-2332-2424\n ");
    printf("                                       翱塊籀: ");
    scanf("%s", customer_info [c_idx].phone);
    printf("                                       蕨衛 -> Seoul, JeonJu, KwangJu, KyeongKi\n ");
    printf("                                       輿模: ");
    scanf("%s", customer_info [c_idx].address);

    fprintf(m_fp, "%s,%s,%s,%s\n"
        , customer_info [c_idx].id
        , customer_info [c_idx].name
        , customer_info [c_idx].phone
        , customer_info [c_idx].address);
    c_idx++;
    fclose(m_fp);
}

// 堅偌 薑爾蒂 だ橾縑憮 殮溘嫡朝棻.
void input_customer(void)
{
    FILE* c_fp = fopen("customer_info.txt", "r");
    char line[150];   // и塭檣噶 檗橫螞棻.
    char* ptr;
    int word_cnt;  //錶萄蘋遴お

    //堅偌 薑爾 殮溘
    while (fscanf(c_fp, "%s", line) > 0)  //0爾棻 贖翕寰虜 等檜攪蒂 檗橫諦塭
    {
        word_cnt = 0;
        ptr = strtok(line, ",");  //檗橫螞 等檜攪蒂 , 欽嬪煎 穢塭頂塭
        while (ptr != NULL)
        {
            word_cnt++;
            switch (word_cnt)
            {
            case 1:  //int id
                //customer_info[c_idx].id = atoi(ptr);
                strcpy(customer_info[c_idx].id, ptr);
                break;
            case 2: //char name
                strcpy(customer_info[c_idx].name, ptr); //蝶お葭 蘋Я蒂 餌辨п憮 僥濠翮 犒餌
                break;
            case 3:  //char phone
                strcpy(customer_info[c_idx].phone, ptr);
                break;
            case 4:  //char address
                strcpy(customer_info[c_idx].address, ptr);
                break;

            }
            ptr = strtok(NULL, ",");
        }
        c_idx++;
    }

    fclose(c_fp);// だ橾ん檣攪 謙猿
}

// 疇薑爾蒂 だ橾縑憮 殮溘嫡朝棻.
void input_book(void)
{

    FILE* b_fp = fopen("book_info.txt", "r");
    char line[150];   //и塭檣噶 檗橫螞棻
    char* ptr;
    int word_cnt;  //錶萄蘋遴お

    //疇 薑爾 殮溘
    while (fscanf(b_fp, "%s", line) > 0) // 0爾棻 贖翕寰虜 等檜攪蒂 檗橫諦塭
    {
        word_cnt = 0;
        ptr = strtok(line, ","); // 檗橫螞 等檜攪蒂 , 欽嬪煎 穢塭頂塭
        while (ptr != NULL)
        {
            word_cnt++;
            switch (word_cnt)
            {
            case 1:  //int ISBn
                strcpy(book_info[b_idx].ISBN, ptr);
                break;
            case 2: //char title
                strcpy(book_info[b_idx].title, ptr);//蝶お葭 蘋Я蒂 餌辨п憮 僥濠翮 犒餌
                break;
            case 3:  //char author
                strcpy(book_info[b_idx].author, ptr);
                break;
            case 4:  //char publishing
                strcpy(book_info[b_idx].publishing, ptr);
                break;
            case 5:  //int is_rented
                book_info[b_idx].is_rented = atoi(ptr);
            }
            ptr = strtok(NULL, ",");
        }
        b_idx++;
    }
    fclose(b_fp); //だ橾ん檣攪 謙猿
}

// �蛾� 薑爾 熱薑
void modify_customer(void)
{
    idx = searchname_customer(); //�蛾� 檜葷擊 匐儀п憮釭螞 還

                if (idx == -1){
                    printf("                                       橾纂ж朝 堅偌檜 橈蝗棲棻.\n");
                    main();
                }
                else
                {
                    printf("                                       %s,%s,%s,%s\n"
                        , customer_info[idx].id
                        , customer_info[idx].name
                        , customer_info[idx].phone
                        , customer_info[idx].address);
                }
    //熱薑й 頂辨 薑曖
    char new_user_number[100];
    char new_user_name[100];
    char new_user_phone_number[100];
    char new_user_address[100];
    int check;
    int i;

    printf("\n                                       滲唳擊 衛濛м棲棻. \n\n");
    printf("                                       億煎遴 堅偌 ID蒂 殮溘ж罹 輿撮蹂 : "); scanf("%s", &new_user_number);
    printf("                                       億煎遴 檜葷擊 殮溘ж罹 輿撮蹂 : "); scanf("%s", new_user_name);
    printf("                                       億煎遴 瞪�食醽ㄧ� 殮溘ж罹 輿撮蹂 : "); scanf("%s", new_user_phone_number);
    printf("                                       億煎遴 輿模蒂 殮溘ж罹 輿撮蹂 : "); scanf("%s", new_user_address);

    printf("                                       收收收收 億煎遴 薑爾蒂 �挫恉桭炴�.收收收收 \n\n");
    printf("                                       億煎遴 堅偌 ID : %s\n", new_user_number);
    printf("                                       億煎遴 檜葷 : %s\n", new_user_name);
    printf("                                       億煎遴 瞪�食醽� : %s\n", new_user_phone_number);
    printf("                                       億煎遴 輿模 : %s\n", new_user_address);
    printf("                                       收收收收 蜃戲賊 1, ぎ葬賊 2蒂 殮溘п輿撮蹂! 收收收收\n");
    printf("\n                                       殮溘 : "); scanf("%d", &check);

        if (check == 1){
            strcpy(customer_info[idx].id, new_user_number);
            strcpy(customer_info[idx].name, new_user_name);
            strcpy(customer_info[idx].phone, new_user_phone_number);
            strcpy(customer_info[idx].address, new_user_address);
            FILE *fp = fopen("modfiy.txt","wb");
            for(i = 0; i < c_idx; i++){
                fprintf(fp, "%s,%s,%s,%s\n"
                , customer_info[i].id
                , customer_info[i].name
                , customer_info[i].phone
                , customer_info[i].address);
            }
            fclose(fp);
            remove("customer_info.txt");
            char oldname[80] = "modfiy.txt";
            char newname[80] = "customer_info.txt";
            rename(oldname, newname); //oldname 諦 newname 曖 檜葷擊 夥羞棻.
            remove("modfiy.txt");
            printf("                                       薑鼻瞳戲煎 籀葬腎歷蝗棲棻.\n");
            printf("                                       籀擠戲煎 腎給嬴 骨棲棻.");
          //  system("pause");
        }
        else
        {
            printf("                                       \n籀擠戲煎 腎給嬴 骨棲棻.");
          //  system("pause");
        }

}

// �蛾讔內� 餉薯
void delete_customer(void)
{
    int i;
    printf("\n\n                                       餉薯蒂 霞чм棲棻.\n\n");
    idx = searchname_customer();

                if (idx == -1)
                    printf("                                       橾纂ж朝 堅偌檜 橈蝗棲棻.\n");
                else
                {
                    printf("%s,%s, %s, %s\n"
                        , customer_info[idx].id
                        , customer_info[idx].name
                        , customer_info[idx].phone
                        , customer_info[idx].address);
                }
         FILE *fp;
         fp = fopen("modfiy.txt", "wb");
//         printf("======= 雖錶撿 ж朝還  : %d =====\n", temp);
//         printf("======= 識 塭檣 : %d =====\n", idx);

         for(i = 0; i < idx; i++)
         {
            fprintf(fp, "%s,%s,%s,%s\n"
               ,&customer_info[i].id
               ,&customer_info[i].name
               ,&customer_info[i].phone
               ,&customer_info[i].address);
         }

         for(i = idx + 1; i < c_idx; i++)
         {
            fprintf(fp, "%s,%s,%s,%s\n"
               ,&customer_info[i].id
               ,&customer_info[i].name
               ,&customer_info[i].phone
               ,&customer_info[i].address);
         }

         fclose(fp);
            remove("customer_info.txt");
            char oldname[80] = "modfiy.txt";
            char newname[80] = "customer_info.txt";
            rename(oldname, newname);
            remove("modfiy.txt");
            printf("                                       薑鼻瞳戲煎 籀葬腎歷蝗棲棻.\n");
            printf("                                       籀擠戲煎 腎給嬴 骨棲棻.");
            system("pause");
           //fflush(stdin);
            c_idx = 0;
            main();
}

// 紫憮 薑爾 熱薑
void modify_book(void)
{
    idx = searchtitle_book();    //疇薯跡擊 匐儀п憮釭螞 還

                if (idx == -1){
                    printf("                                       橾纂ж朝 紫憮陛 橈蝗棲棻.\n");
                    main();
                }
                else
                {
                    printf("                                       %s,%s,%s,%s\n"
                        , book_info[idx].ISBN
                        , book_info[idx].title
                        , book_info[idx].author
                        , book_info[idx].publishing);
                }
    //熱薑й 頂辨 薑曖
    char new_book_ISBN[100];
    char new_book_title[100];
    char new_book_author[100];
    char new_book_publishing[100];
    int check;
    int i;
    printf("\n\n                                        滲唳擊 衛濛м棲棻. \n\n");
    printf("                                       億煎遴 ISBN蒂 殮溘ж罹 輿撮蹂 : "); scanf("%s", new_book_ISBN);
    printf("                                       億煎遴 薯跡擊 殮溘ж罹 輿撮蹂 : "); scanf("%s",new_book_title);
    printf("                                       億煎遴 盪濠蒂 殮溘ж罹 輿撮蹂 : "); scanf("%s", new_book_author);
    printf("                                       億煎遴 轎っ餌蒂 殮溘ж罹 輿撮蹂 : "); scanf("%s", new_book_publishing);


    printf("                                       ===== 億煎遴 薑爾蒂 �挫恉桭炴�. ===== \n\n");
    printf("                                       億煎遴 ISBN : %s\n", new_book_ISBN);
    printf("                                       億煎遴 薯跡 : %s\n", new_book_title);
    printf("                                       億煎遴 盪濠 : %s\n", new_book_author);
    printf("                                       億煎遴 轎っ餌 : %s\n",new_book_publishing);


    printf("                                       ===== 蜃戲賊 1, ぎ葬賊 2蒂 殮溘п輿撮蹂! =====\n");
    printf("\n                                       殮溘 : "); scanf("%d", &check);


        if (check == 1){
            strcpy(book_info[idx].ISBN, new_book_ISBN);
            strcpy(book_info[idx].title, new_book_title);
            strcpy(book_info[idx].author, new_book_author);
            strcpy(book_info[idx].publishing, new_book_publishing);
            FILE *fp = fopen("modfiybook.txt","wb");
            for(i = 0; i < b_idx; i++){
                fprintf(fp,                                        "%s,%s,%s,%s\n"
                , book_info[i].ISBN
                , book_info[i].title
                , book_info[i].author
                , book_info[i].publishing);
            }
            fclose(fp);
            remove("book_info.txt");
            char oldname[80] = "modfiybook.txt";
            char newname[80] = "book_info.txt";
            rename(oldname, newname);     //oldname 諦 newname 曖 檜葷擊 夥羞棻.
            remove("modfiybook.txt");
            printf("                                       薑鼻瞳戲煎 籀葬腎歷蝗棲棻.\n");
            printf("                                       籀擠戲煎 腎給嬴 骨棲棻.");
          //  system("pause");
        }
        else
        {
            printf("                                       籀擠戲煎 腎給嬴 骨棲棻.");
          //  system("pause");
        }

}

// 紫憮 薑爾 餉薯
void delete_book(void)
{
    int i;
    printf("\n                                       餉薯蒂 霞чм棲棻.\n\n");
    idx = searchtitle_book();

                if (idx == -1)
                    printf("                                       橾纂ж朝 堅偌檜 橈蝗棲棻.\n");
                else
                {
                    printf("                                       %s,%s,%s,%s\n"
                        , book_info[idx].ISBN
                        , book_info[idx].title
                        , book_info[idx].author
                        , book_info[idx].publishing);
                }
         FILE *fp = fopen("modfiybook.txt","wb");;
//         printf("======= 雖錶撿 ж朝還  : %d =====\n", temp);
//         printf("======= 識 塭檣 : %d =====\n", idx);

         for(i = 0; i < idx; i++)
         {
            fprintf(fp, "%s,%s,%s,%s\n"
                ,&book_info[i].ISBN
                ,&book_info[i].title
                ,&book_info[i].author
                ,&book_info[i].publishing);
         }

         for(i = idx + 1; i < b_idx; i++)
         {
            fprintf(fp, "%s,%s,%s,%s\n"
                ,&book_info[i].ISBN
                ,&book_info[i].title
                ,&book_info[i].author
                ,&book_info[i].publishing);
         }

            fclose(fp);
            remove("book_info.txt");
            char oldname[80] = "modfiybook.txt";
            char newname[80] = "book_info.txt";
            rename(oldname, newname);     //oldname 諦 newname 曖 檜葷擊 夥羞棻.
            remove("modfiybook.txt");
            printf("                                       薑鼻瞳戲煎 籀葬腎歷蝗棲棻.\n");
            printf("                                       籀擠戲煎 腎給嬴 骨棲棻.");
            system("pause");
           //fflush(stdin);
            b_idx = 0;
            main();
}




