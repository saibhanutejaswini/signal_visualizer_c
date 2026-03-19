#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

int main() {
    FILE *file;
    file = fopen("signal.csv", "w");

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    double t, sine, cosine, square;
    double frequency;

    printf("Enter frequency (e.g., 1, 2, 5): ");
    scanf("%lf", &frequency);

    fprintf(file, "time,sine,cosine,square\n");

    for (t = 0; t <= 1; t += 0.01) {
        sine = sin(2 * PI * frequency * t);
        cosine = cos(2 * PI * frequency * t);

        if (sine >= 0)
            square = 1;
        else
            square = -1;

        fprintf(file, "%lf,%lf,%lf,%lf\n", t, sine, cosine, square);
    }

    fclose(file);

    printf("Signal saved with frequency = %.2lf\n", frequency);

    return 0;
}