#include <stdio.h>

// Sua função sc_strncmp personalizada
int sc_strncmp(const char *s1, const char *s2, size_t n) {
    size_t i = 0;

    // Se n for zero, nenhuma comparação deve ser feita, então são "iguais" no limite 0
    if (n == 0)
        return 0;

    // Loop roda enquanto s1[i] for igual a s2[i], 
    // enquanto não chegarmos ao fim de s1,
    // e enquanto ainda restarem caracteres para checar (n - i > 1)
    while (s1[i] && s1[i] == s2[i] && (i + 1) < n) {
        i++;
    }

    // Retorna a subtração dos caracteres onde o loop parou (ou divergiu)
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int main() {
    // Cenário: O sistema só exige que os primeiros 8 dígitos da senha mestra coincidam
    char *senha_cadastrada = "12345678_admin_extra";
    char *senha_digitada1   = "12345678_user_comum";  // Igual nos primeiros 8 dígitos
    char *senha_digitada2   = "1234567X_tentativa";    // Diferente no 8º dígito (índice 7)

    printf("Senha Cadastrada: \"%s\"\n\n", senha_cadastrada);

    // TESTE 1: Comparando com a primeira senha digitada (Apenas os primeiros 8 caracteres)
    int resultado1 = sc_strncmp(senha_cadastrada, senha_digitada1, 8);
    printf("Tentativa 1 (\"%s\"):\n", senha_digitada1);
    if (resultado1 == 0) {
        printf("-> ACESSO LIBERADO! Os primeiros 8 digitos sao iguais.\n\n");
    } else {
        printf("-> ACESSO NEGADO! Senha incorreta.\n\n");
    }

    // TESTE 2: Comparando com a segunda senha digitada
    int resultado2 = sc_strncmp(senha_cadastrada, senha_digitada2, 8);
    printf("Tentativa 2 (\"%s\"):\n", senha_digitada2);
    if (resultado2 == 0) {
        printf("-> ACESSO LIBERADO!\n");
    } else {
        printf("-> ACESSO NEGADO! Senha incorreta.\n");
    }

    return 0;
}