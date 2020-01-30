int main(){
    int sum = 0, min = 100, temp = 0;
    for (int i = 0; i < 7; i++) {
        scanf("%d", &temp);
        if (temp % 2 == 1) {
            sum += temp;
            if (min > temp) { min = temp; }
        }
    }
    if (sum == 0) { printf("-1"); }
    else { printf("%d\n%d", sum, min); }
}