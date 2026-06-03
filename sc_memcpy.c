#include <stdio.h>

// Sua função sc_memcpy personalizada
void *sc_memcpy(void *dst, const void *src, size_t n) {
    // 1. Converte ambos os ponteiros genéricos (void*) para ponteiros de byte (unsigned char*)
    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;
    size_t i = 0;

    // 2. Loop para copiar src[i] para dst[i] até atingir o limite 'n'
    while (i < n) {
        d[i] = s[i];
        i++;
    }

    // 3. Boa prática clássica do C: retornar o ponteiro de destino original
    return dst;
}

// Simulando a estrutura de dados que chega do seu sensor de rede
typedef struct {
    int   id_sensor;
    float temperatura;
    float umidade;
} t_sensor_data;

int main() {
    // 1. Dados originais vindos do sensor de rede
    t_sensor_data dados_sensor = {101, 26.5, 65.2};
    
    // 2. Buffer de backup (inicialmente vazio)
    t_sensor_data backup_sensor;

    printf("--- ANTES DA COPIA (BACKUP) ---\n");
    printf("ID: %d | Temp: %.1f | Umid: %.1f\n", backup_sensor.id_sensor, backup_sensor.temperatura, backup_sensor.umidade);

    // 3. Chamando a sua sc_memcpy para clonar a memória inteira da estrutura
    // Passamos o destino, a origem, e o tamanho total em bytes da estrutura (sizeof)
    sc_memcpy(&backup_sensor, &dados_sensor, sizeof(t_sensor_data));

    printf("\n--- DEPOIS DA COPIA (BACKUP REALIZADO) ---\n");
    printf("ID: %d | Temp: %.1f | Umid: %.1f\n", backup_sensor.id_sensor, backup_sensor.temperatura, backup_sensor.umidade);

    return 0;
}