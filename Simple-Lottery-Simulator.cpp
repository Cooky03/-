#include <bits/stdc++.h>

using namespace std;

#define P 60     // �н����ʵķ���
#define tt 10000 // �н����ʵķ�ĸ������0��������
#define U 600    // �����һ����������������������޸Ĵ���
#define LEVEL 74 // ��������������ֵ

int main()
{
    int pickUp = 0;     // ������Ҫ�Ľ�Ʒ�Ĵ���
    int notPickUp = 0;  // ������һ����Ʒ������������Ʒ�Ĵ���
    int x = 0;          // �н�ǰ���ۼƳ���
    int tries = 0;      // �ܳ���
    int totalTries = 0; // ��ǰ����
    int mustUp = 0;     // ���������0ΪС���ף�1Ϊ�󱣵�

    int p = P; // ��ǰ�齱���
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
        printf("��%d�γ�ȡ���:", totalTries);
        if (x == 90)
        {
            if (mustUp == 0)
            {
                isUp = rand() % 2;
                if (isUp == 0)
                {
                    pickUp++;
                    printf("С���ף�����up*\n");
                }
                else
                {
                    notPickUp++;
                    mustUp = 1;
                    printf("С���ף�δ����up*\n");
                }
            }
            else
            {
                pickUp++;
                mustUp = 0;
                printf("�󱣵ף�����up*\n");
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
                    printf("С���ף�����up\n");
                    x = 0;
                    p = P;
                    continue;
                }
                else
                {
                    notPickUp++;
                    mustUp = 1;
                    printf("С���ף�δ����up\n");
                    x = 0;
                    p = P;
                    continue;
                }
            }
            else
            {
                pickUp++;
                mustUp = 0;
                printf("�󱣵ף�����up\n");
                x = 0;
                p = P;
                continue;
            }
        }
        else
            printf("δ�н�\n");
    }

    printf("�ܹ��н�%d�Σ�������Ҫ�Ľ�Ʒ����%d�Σ�����Ҫ�Ľ�Ʒ����%d�Ρ��ܹ�����%d�飬ƽ��%d���н�һ�Σ�ƽ��%d�����Լ���Ҫ�Ľ�Ʒ.", pickUp + notPickUp, pickUp, notPickUp, tries, tries / (pickUp + notPickUp), tries / pickUp);
    system("pause");
    return 0;
}