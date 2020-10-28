#include <stdio.h>
float hourDeg(int hour, int minute){
    return hour*30 + minute/2.0;
}
float minuteDeg(int minute){
    return minute*6.0;
}
float deltaDeg(float deg1, float deg2){
    if (deg1 > deg2){
        return 360 - deg1 + deg2;
    }else{
        return deg2 - deg1;
    }
}

int main(){
    int hour1,minute1,hour2,minute2;
    scanf("%d:%d %d:%d", &hour1, &minute1, &hour2, &minute2);
    printf("%.0f %.0f", deltaDeg(hourDeg(hour1,minute1),hourDeg(hour2,minute2)), deltaDeg(minuteDeg(minute1),minuteDeg(minute2)));
}