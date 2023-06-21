/*3. Write a program using structures to calculate the difference between two time periods using a user-defined function.*/


#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

struct Time calculateTimeDifference(const struct Time *t1, const struct Time *t2) {
    struct Time diff;
    int t1Seconds = t1->hours * 3600 + t1->minutes * 60 + t1->seconds;
    int t2Seconds = t2->hours * 3600 + t2->minutes * 60 + t2->seconds;

    int diffSeconds = t1Seconds > t2Seconds ? t1Seconds - t2Seconds : t2Seconds - t1Seconds;

    diff.hours = diffSeconds / 3600;
    diffSeconds %= 3600;
    diff.minutes = diffSeconds / 60;
    diff.seconds = diffSeconds % 60;

    return diff;
}

int main() {
    struct Time t1, t2, diff;

    printf("Enter time period 1 (hours minutes seconds): ");
    scanf("%d %d %d", &(t1.hours), &(t1.minutes), &(t1.seconds));

    printf("Enter time period 2 (hours minutes seconds): ");
    scanf("%d %d %d", &(t2.hours), &(t2.minutes), &(t2.seconds));

    diff = calculateTimeDifference(&t1, &t2);

    printf("\nDifference: %d hours %d minutes %d seconds\n", diff.hours, diff.minutes, diff.seconds);

    return 0;
}