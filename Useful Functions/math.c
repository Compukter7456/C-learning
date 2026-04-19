
float calculate_sqrt(float number) {
    if (number <= 0) {
        return 0;
    }

    float result = number/3;

    for (int i = 0; i < 10; i++) {
        result = (result + number / result) / 2;
    }

    return result;
}

int main(void) {
    return 0;
}