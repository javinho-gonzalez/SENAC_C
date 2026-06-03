#include <stdio.h>

// Sua função sc_memmove personalizada
void *sc_memmove(void *dst, const void *src, size_t len) {
    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;

    // Segurança básica: se os ponteiros forem iguais ou o tamanho for 0, não faz nada
    if (d == s || len == 0)
        return dst;

    // SE O DESTINO ESTIVER DEPOIS DA ORIGEM -> Copia de TRÁS PARA FRENTE
    if (d > s) {
        // Começamos o índice no último byte (len - 1)
        size_t i = len;
        while (i > 0) {
            i--; // Decrementa primeiro para pegar a posição correta
            d[i] = s[i];
        }
    } 
    // CASO CONTRÁRIO -> Copia normal de FRENTE PARA TRÁS
    else {
        size_t i = 0;
        while (i < len) {
            d[i] = s[i];
            i++;
        }
    }

    return dst;
}

int main() {
    // Criamos um array com a palavra "ABCDE" seguida de espaços livres
    char texto[10] = "ABCDE";

    printf("Texto Original:              \"%s\"\n", texto);

    // VAMOS SIMULAR UMA SOBREPOSIÇÃO:
    // Queremos mover as 5 letras "ABCDE" apenas 2 posições para a direita.
    // Origem (src): '&texto[0]' (onde está o 'A')
    // Destino (dst): '&texto[2]' (duas posições para a direita)
    // Como o destino (índice 2) está DEPOIS da origem (índice 0), ele vai copiar de trás para frente.
    
    sc_memmove(&texto[2], &texto[0], 5);

    printf("Texto apos mover (sc_memmove): \"%s\"\n", texto);

    return 0;
}