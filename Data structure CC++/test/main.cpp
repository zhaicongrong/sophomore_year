#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n, m;
double r;
double a, b, c, p, s, h;
double aa, bb, cc;
double angleC, alpha, beta, delta;
double dot[2010][110];
double sq[2010][2010], si[2010][2010], dis[2010][2010];
double ans[2010];
int main(){
    scanf("%d%d%lf",&n, &m, &r);
    for(int i=0;i<=m;i++){
        for(int j=0;j<n;j++){
            scanf("%lf", &dot[i][j]); //����˫���ȸ�������Ҫ��lf
        }
    }
    for(int i=0;i<=m;i++){
        sq[i][i] = 0, si[i][i] = 0;
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<i;j++){ //ֻ����������
            sq[i][j]=0;
            for(int k=0;k<n;k++){
                sq[i][j] += ((dot[i][k]-dot[j][k])*(dot[i][k]-dot[j][k])); //Ԥ����m+1����֮��ľ���;����ƽ��
            }
            si[i][j] = sqrt(sq[i][j]);
        }
    }
    for(int i=2;i<=m;i++){
        for(int j=1;j<i;j++){
            a = si[i][0]; //����-�ؾ��ع�ʽ
            b = si[j][0];
            c = si[i][j];
            p = (a+b+c)/2;
            printf("%lf %lf %lf %lf ", a, b, c, p);
            s = sqrt(p*(p-a)*(p-b)*(p-c));
            printf("%lf\n", s);
            h = 2*s/c;
            if(h>=r){
                dis[i][j] = si[i][j]; //ֱ�߾���
                dis[j][i] = si[i][j];
            }
            else{  //�����Բ�Ľ�֮��������Ƕ�
                aa = sq[i][0];
                bb = sq[j][0];
                cc = sq[i][j];
                if(bb+cc<=aa||aa+cc<=bb){ //�򻯣�ʹ�����ҹ�ʽ�жϽ��ǲ��Ƕۣ�ֱ����
                    printf("!\n");
                    dis[i][j] = si[i][j]; //ֱ�߾���
                    dis[j][i] = si[i][j];
                }
                else{
                    angleC = acos(fmax(fmin((aa+bb-cc)/2/a/b, 1), -1)); //��ֹ���������ʹacos����Խ��
                    alpha = acos(r/a);
                    beta = acos(r/b);
                    delta = angleC-alpha-beta;
                    dis[i][j] = sqrt(aa-r*r)+sqrt(bb-r*r)+delta*r; //����ƴ�ɵľ���
                    dis[j][i] = dis[i][j];

                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        ans[i]=0;
        for(int j=1;j<=m;j++){
            ans[i] += dis[i][j];
        }
        printf("%.15f\n", ans[i]);
    }
}
