#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int distinct_a = 0;
    int distinct_b = 0;
    int count[26] = {0};    // frequency of 26 alphabet
    
    // count # of distinct alphabets for a
    for(int i=0; a[i]!='\0'; i++){
        if(count[a[i]-'a'] == 0){
            distinct_a ++;
        }
        count[a[i]-'a'] ++;
    }
    // reset count;
    memset(count, 0, sizeof(count));
    
    // count # of distinct alphabets for b
    for(int i=0; b[i]!='\0'; i++){
        if(count[b[i]-'a']==0){
            distinct_b ++;
        }
        count[b[i]-'a'] ++;
    }
    
    if(distinct_a != distinct_b)
        return distinct_a - distinct_b;
    return strcmp(a, b);
}

int sort_by_length(const char* a, const char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    if(len_a != len_b)
        return len_a - len_b;
    return strcmp(a, b);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for(int i=0; i<len-1; i++){
        for(int j=i+1; j<len; j++){
            if(cmp_func(arr[i], arr[j])> 0){
                char *temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}