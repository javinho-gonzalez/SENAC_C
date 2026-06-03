#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>  //for malloc and free
#include <string.h>

// A simple implementation of strlcpy since it's not standard on all operating systems
/*size_t strlcpy(char *dst, const char *src, size_t siz) {
    size_t i = 0;
    if (siz > 0) {
        while (src[i] && i < (siz - 1)) {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    while (src[i]) i++;
    return i;
}*/

static size_t nb_word(char const *s, char c){
    size_t i;
    size_t nb_word;

    if(!s[0])
     return 0;
    nb_word = 0;
    while(s[i] && s[i] == c)
       i++;
    while (s[i]){
        if (s[i] == c){
            nb_word++;
            while (s[i] && s[i] == c)
               i++;
            continue;
        }
        i++;
    }
    if (s[i - 1] != c)
        nb_word++;
    return (nb_word);
}
//Function Lines

static void get_next_word(char **next_word, size_t *next_word_len, char c){
    size_t i;

    *next_word +=*next_word_len; //*nexxt_word = next_word + *next_word_len
    *next_word_len = 0;
    i = 0;
    while(**next_word && **next_word == c)
        (*next_word)++;
    while((*next_word)[i]){
        if ((*next_word)[i] == c)
          return;
        (*next_word_len)++;
        i++;
    }
}

char **sc_split(char const *s, char c){
    char **tab;
    char *next_word;
    size_t next_word_len;
    size_t i;
    //Se s existe
    if(!s)
        return(NULL);
    tab = (char **)malloc(sizeof(char *) * (nb_word(s, c) + 1));
    if(!tab)
       return(NULL);
    i = 0;
    next_word = (char *)s;
    next_word_len = 0;
    while (i < nb_word(s, c)){
        get_next_word(&next_word, &next_word_len, c);
        tab[i] = (char *) malloc(sizeof(char) * (next_word_len + 1));
        if (!tab[i])
           printf("Erro na allocação de memoria\n");
        strlcpy(tab[i], next_word, next_word_len + 1);
        i++;
    }
    tab[i] = NULL;
    return (tab);
}
// --- THE MAIN FUNCTION ---
/*int main() {
    // 1. Create a test sentence and a divider (space character)
    char const *sentence = "  Hello,dear,friend,welcome,to,C,language! ";
    char delimiter = ',';
    
    printf("Original Sentence: \"%s\"\n", sentence);
    printf("Delimiter used: '%c'\n\n", delimiter);

    // 2. Run your split function
    char **result = sc_split(sentence, delimiter);

    if (result == NULL) {
        printf("Splitting failed!\n");
        return 1;
    }

    // 3. Loop through the resulting grid and print each individual word
    printf("--- Splitting Results ---\n");
    int i = 0;
    while (result[i] != NULL) {
        printf("Word [%d]: %s\n", i, result[i]);
        i++;
    }*/

    // 4. Good practice: Free allocated memory back to the computer
    /*i = 0;
    while (result[i] != NULL) {
        free(result[i]);
        i++;
    }
    free(result);

    return 0;*/
//}
int main() {
    const char *input = "Esta,e,uma,frase,de,exemplo";
    char delimiter = ',';

    char **result = sc_split(input,delimiter);

    if (result) {
        for (int i = 0; result[i] != NULL; i++) {
            printf("Part %d: %s \n", i, result[i]);
            //free(result[i]);
        }
        free(result);
    }
else
   printf("Alocação de memoria falhou.\n");
return 0;
}