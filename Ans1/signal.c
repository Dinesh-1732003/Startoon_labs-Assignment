#include <stdio.h>
#include <stdlib.h>

void find_peaks(float signal[], int length, int maxima[], int *maxima_count, int minima[], int *minima_count) {
    *maxima_count = 0;
    *minima_count = 0;
    
    for (int i = 1; i < length - 1; i++) {
        if (signal[i] > signal[i-1] && signal[i] > signal[i+1]) {
            maxima[(*maxima_count)++] = i;
        } else if (signal[i] < signal[i-1] && signal[i] < signal[i+1]) {
            minima[(*minima_count)++] = i;
        }
    }
}

int read_signal_from_file(const char *filename, float **signal, int *length) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    int count = 0;
    float temp;
    while (fscanf(file, "%f", &temp) == 1) {
        count++;
    }

    *signal = malloc(count * sizeof(float));
    if (*signal == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return -1;
    }

    fseek(file, 0, SEEK_SET); 
    for (int i = 0; i < count; i++) {
        fscanf(file, "%f", &(*signal)[i]);
    }

    *length = count;
    fclose(file);
    return 0;
}

int main() {
    float *signal_1;
    int length_1;
    if (read_signal_from_file("./Data_1.txt", &signal_1, &length_1) != 0) {
        return 1;
    }

    int maxima_1[100], minima_1[100];
    int maxima_count_1, minima_count_1;

    find_peaks(signal_1, length_1, maxima_1, &maxima_count_1, minima_1, &minima_count_1);

    printf("Data_1 Maxima Indices: ");
    for (int i = 0; i < maxima_count_1; i++) {
        printf("%d ", maxima_1[i]);
    }
    printf("\n");

    printf("Data_1 Minima Indices: ");
    for (int i = 0; i < minima_count_1; i++) {
        printf("%d ", minima_1[i]);
    }
    printf("\n");

    free(signal_1);

    float *signal_2;
    int length_2;
    if (read_signal_from_file("./Data_2.txt", &signal_2, &length_2) != 0) {
        return 1;
    }

    int maxima_2[100], minima_2[100];
    int maxima_count_2, minima_count_2;

    find_peaks(signal_2, length_2, maxima_2, &maxima_count_2, minima_2, &minima_count_2);

    printf("Data_2 Maxima Indices: ");
    for (int i = 0; i < maxima_count_2; i++) {
        printf("%d ", maxima_2[i]);
    }
    printf("\n");

    printf("Data_2 Minima Indices: ");
    for (int i = 0; i < minima_count_2; i++) {
        printf("%d ", minima_2[i]);
    }
    printf("\n");

    free(signal_2);

    return 0;
}
