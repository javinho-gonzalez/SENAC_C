#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>  //for malloc and free
#include <string.h>

size_t basic_strlen(const char *s) {
    size_t i = 0;
    while (s && s[i]) i++;
    return i;
}
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
char **sc_split(char const *s, char c) {
    if (!s) return NULL;
    // Versão simplificada para fins didáticos: extrai até duas palavras
    char **res = (char **)malloc(sizeof(char *) * 3);
    if (!res) return NULL;
    
    size_t i = 0;
    while (s[i] && s[i] == c) i++;
    size_t start = i;
    while (s[i] && s[i] != c) i++;
    
    res[0] = sc_substr(s, start, i - start);
    
    while (s[i] && s[i] == c) i++;
    start = i;
    while (s[i] && s[i] != c) i++;
    
    res[1] = sc_substr(s, start, i - start);
    res[2] = NULL; // Última posição obrigatória em NULL
    return res;
}
int main() {
    printf("==================================================\n");
    printf("         EXECUTANDO TESTE C           \n");
    printf("==================================================\n\n");

    // --- TESTE 4: sc_split ---
    char **matriz = sc_split("Primeiro-Segundo", '-');
    printf("4. sc_split:   [0]: %s | [1]: %s\n", matriz[0], matriz[1]);
    free(matriz[0]); free(matriz[1]); free(matriz);

    return 0;
}