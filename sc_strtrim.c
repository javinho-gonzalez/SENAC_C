#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 1. Função auxiliar para medir o tamanho da string
size_t basic_strlen(const char *s) {
    size_t i = 0;
    while (s && s[i]) i++;
    return i;
}

// 2. Função auxiliar para verificar se um caractere faz parte do "set"
int is_in_set(char c, char const *set) {
    while (*set) {
        if (c == *set) return 1;
        set++;
    }
    return 0;
}

// 3. Função auxiliar para recortar o pedaço final da string
char *sc_substr(char const *s, unsigned int start, size_t len) {
    if (!s) return NULL;
    size_t s_len = basic_strlen(s);
    if (start >= s_len) len = 0;
    if (len > s_len - start) len = s_len - start;
    
    char *sub = (char *)malloc(sizeof(char) * (len + 1));
    if (!sub) return NULL;
    
    size_t i = 0;
    while (i < len) {
        sub[i] = s[start + i];
        i++;
    }
    sub[i] = '\0';
    return sub;
}

char *sc_strtrim(char const *s1, char const *set) {
    if (!s1 || !set) return NULL;
    size_t start = 0;
    size_t end = basic_strlen(s1);
    
    while (s1[start] && is_in_set(s1[start], set)) start++;
    while (end > start && is_in_set(s1[end - 1], set)) end--;
    
    return sc_substr(s1, start, end - start);
}
int main() {
    printf("==================================================\n");
    printf("         EXECUTANDO TESTE C           \n");
    printf("==================================================\n\n");

    // --- TESTE 3: sc_strtrim ---
    char *trim = sc_strtrim("***Alvo***", "*");
    printf("3. sc_strtrim: %s\n", trim);
    free(trim);
    return 0;
}