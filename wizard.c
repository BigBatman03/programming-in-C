#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

const char* number_words[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
const int number_values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

int extract_digits(const char* line) {
    char first = 0, last = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        if (isdigit(line[i])) {
            if (first == 0) first = line[i];
            last = line[i];
        }
    }
    return first && last ? (first - '0') * 10 + (last - '0') : 0;
}

int starts_with_number_word(const char* line, int* value) {
    for (int i = 0; i < 9; i++) {
        if (strncmp(line, number_words[i], strlen(number_words[i])) == 0) {
            *value = number_values[i];
            return 1;
        }
    }
    return 0;
}

int extract_digits_with_words(const char* line) {
    int first = -1, last = -1, num;
    for (int i = 0; line[i] != '\0'; i++) {
        if (isdigit(line[i])) {
            num = line[i] - '0';
        }
        else if (starts_with_number_word(&line[i], &num)) {

        }
        else {
            continue;
        }
        if (first == -1) first = num;
        last = num;
    }
    return (first != -1 && last != -1) ? first * 10 + last : 0;
}

int sum_energy_values(char** lines, int count, int use_words) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += use_words ? extract_digits_with_words(lines[i]) : extract_digits(lines[i]);
    }
    return sum;
}

int read_file(const char* filename, char*** lines) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return 0;
    }

    int count = 0, capacity = 10;
    *lines = malloc(capacity * sizeof(char*));
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), file)) {
        if (count >= capacity) {
            capacity *= 2;
            *lines = realloc(*lines, capacity * sizeof(char*));
        }
        buffer[strcspn(buffer, "\n")] = '\0';
        (*lines)[count] = _strdup(buffer);
        count++;
    }
    fclose(file);
    return count;
}

void free_lines(char** lines, int count) {
    for (int i = 0; i < count; i++) {
        free(lines[i]);
    }
    free(lines);
}

int main() {
    char** data;
    int line_count = read_file("C:\\Users\\micha\\Downloads\\input.txt", &data);

    if (line_count > 0) {
        printf("Part 1 Sum: %d\n", sum_energy_values(data, line_count, 0));
        printf("Part 2 Sum: %d\n", sum_energy_values(data, line_count, 1));
        free_lines(data, line_count);
    }
    else {
        printf("No data found in file.\n");
    }

    return 0;
}
