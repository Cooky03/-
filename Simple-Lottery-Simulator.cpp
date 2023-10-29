#include <bits/stdc++.h>

using namespace std;

#define P 60     // 中奖概率的分子
#define tt 10000 // 中奖概率的分母，增减0调整精度
#define U 600    // 如果在一定抽数后概率逐渐提升，请修改此项
#define LEVEL 74 // 概率逐渐提升的阈值

int main()
{
    int pickUp = 0;     // 抽中想要的奖品的次数
    int notPickUp = 0;  // 抽中另一个奖品，或者其他奖品的次数
    int x = 0;          // 中奖前的累计抽数
    int tries = 0;      // 总抽数
    int totalTries = 0; // 当前抽数
    int mustUp = 0;     // 保底情况，0为小保底，1为大保底

    int p = P; // 当前抽奖情况
    int get, isUp;

    scanf("%d", &tries);
    srand(time(nullptr));
    for (x = 1; x <= 90; x++)
    {
        totalTries++;
        get = rand() % tt;

        if (x >= LEVEL)
        {
            p += U;
        }

        if (totalTries > tries)
            break;
        printf("%d\t%d\t%d\t", p, get, x);
        printf("第%d次抽取结果:", totalTries);
        if (x == 90)
        {
            if (mustUp == 0)
            {
                isUp = rand() % 2;
                if (isUp == 0)
                {
                    pickUp++;
                    printf("小保底，抽中up*\n");
                }
                else
                {
                    notPickUp++;
                    mustUp = 1;
                    printf("小保底，未抽中up*\n");
                }
            }
            else
            {
                pickUp++;
                mustUp = 0;
                printf("大保底，抽中up*\n");
            }
            p = P;
            x = 0;
            continue;
        }

        if (get < p)
        {
            if (mustUp == 0)
            {
                isUp = rand() % 2;
                if (isUp == 0)
                {
                    pickUp++;
                    printf("小保底，抽中up\n");
                    x = 0;
                    p = P;
                    continue;
                }
                else
                {
                    notPickUp++;
                    mustUp = 1;
                    printf("小保底，未抽中up\n");
                    x = 0;
                    p = P;
                    continue;
                }
            }
            else
            {
                pickUp++;
                mustUp = 0;
                printf("大保底，抽中up\n");
                x = 0;
                p = P;
                continue;
            }
        }
        else
            printf("未中奖\n");
    }

    printf("总共中奖%d次，其中想要的奖品抽中%d次，不想要的奖品抽中%d次。总共抽了%d抽，平均%d抽中奖一次，平均%d抽抽出自己想要的奖品.", pickUp + notPickUp, pickUp, notPickUp, tries, tries / (pickUp + notPickUp), tries / pickUp);
    system("pause");
    return 0;
}