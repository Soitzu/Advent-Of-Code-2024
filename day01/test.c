#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 2000 // Maximale Zeilenanzahl
#define MAX_VALUE 1000000 // Annahme: Maximale Werte in l2 (anpassen bei Bedarf)

// Hilfsfunktion zum Vergleich für qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void day01(const char *filename, int *diff, int *similarity) {
    int l1[MAX_SIZE], l2[MAX_SIZE];
    int ctr[MAX_VALUE] = {0}; // Zähler für Werte in l2
    int count = 0;

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Datei konnte nicht geöffnet werden");
        exit(EXIT_FAILURE);
    }

    // Daten aus der Datei lesen
    while (fscanf(file, "%d %d", &l1[count], &l2[count]) == 2) {
        count++;
        if (count >= MAX_SIZE) {
            fprintf(stderr, "Zu viele Daten in der Datei\n");
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }
    fclose(file);

    // Listen sortieren
    qsort(l1, count, sizeof(int), compare);
    qsort(l2, count, sizeof(int), compare);

    *diff = 0;
    *similarity = 0;

    // Häufigkeit von Werten in l2 berechnen
    for (int i = 0; i < count; i++) {
        if (l2[i] >= 0 && l2[i] < MAX_VALUE) {
            ctr[l2[i]]++;
        } else {
            fprintf(stderr, "Wert in l2 außerhalb des erlaubten Bereichs: %d\n", l2[i]);
            exit(EXIT_FAILURE);
        }
    }

    // Differenz und Ähnlichkeit berechnen
    for (int i = 0; i < count; i++) {
        *diff += abs(l1[i] - l2[i]);
        if (l1[i] >= 0 && l1[i] < MAX_VALUE) {
            *similarity += l1[i] * ctr[l1[i]];
        }
    }
}

int main() {
    const char *filename = "./input.txt";
    int diff, similarity;

    day01(filename, &diff, &similarity);

    printf("Diff: %d\n", diff);
    printf("Similarity: %d\n", similarity);

    return 0;
}

