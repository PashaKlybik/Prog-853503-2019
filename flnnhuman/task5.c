#include <stdio.h>

int main() {
    int x1,y1,x2,y2,x3,y3,r,result=0;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    scanf("%d%d%d",&x3,&y3,&r);


    for (int i = x1; i <= x2; ++i) {
        for (int j = y1; j <=y2 ; ++j) {
            if((i-x3)*(i-x3)+(j-y3)*(j-y3)>r*r)
            {
                result++;
            }
        }

    }
    printf("%d",result);

}