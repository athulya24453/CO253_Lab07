#include <stdio.h>
#include <stdlib.h>

int* create_array(char* s){
    int len = strlen(s);
    int* p = (int*)malloc(len*sizeof(int));

    for (int i=0; i<len; i++){
        *(p+i) = s[i]-'0';
    }

    return p;
}

int find_i(int* arr, int num){
    int index = 0;
    int x = 0;

    while (arr[x] != num){
        index++;
        x++;
    }

    int i = index/3;

    return i;
}

int find_j(int* arr, int num){
    int index = 0;
    int x = 0;

    while (arr[x] != num){
        index++;
        x++;
    }

    int j = index%3;

    return j;
}

int sol(char* s, char* keypad){
    int* key_int = create_array(keypad);
    int* s_int = create_array(s);

    int size_s = strlen(s);

    int cost = 0;

    for (int i=0; i<size_s; i++){
        int cur_i = find_i(key_int, s_int[i]);
        int cur_j = find_j(key_int, s_int[i]);

        if (i == size_s-1){
            return cost;
        }
        int n_i = find_i(key_int, s_int[i+1]);
        int n_j = find_j(key_int, s_int[i+1]);

        int diff_i = abs(n_i - cur_i);
        int diff_j = abs(n_j - cur_j);

        if (diff_i == 0){
            cost += diff_j;
        }

        else if (diff_j == 0){
            cost += diff_i;
        }

        else if (diff_i == diff_j){
            cost += diff_i;
        }

        else{
            cost += 2;
        }

    }

    return cost;
}

int main()
{
    char key[9] = "639485712";
    char pw[6] = "91566165";

    int ans = sol(pw, key, 8);

    printf("%d", ans);

    return 0;
}
