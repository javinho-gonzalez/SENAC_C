# SENAC_C
# Análise Técnica e Execução de Funções em C (Projeto LibC)

## 📌 Introdução
Seja bem-vindo(a) ao repositório do projeto **LibC**! Este projeto consiste no estudo detalhado, mapeamento conceitual e reimplementação de funções clássicas da biblioteca padrão do C (`libc`), além do desenvolvimento de utilitários adicionais de manipulação textual e estruturas de dados dinâmicas (Listas Ligadas). 

Antes de digitar uma única linha de código, o projeto exigiu uma imersão profunda na engenharia reversa do comportamento de ponteiros, alocação de memória e tratamento estrito de falhas no ecossistema C.

---

## 🎯 Objetivo do Projeto
O objetivo principal é consolidar o domínio absoluto sobre o gerenciamento manual de memória RAM em C. Através do desenvolvimento e isolamento do ecossistema de funções prefixadas com `sc_`, o projeto visa eliminar o comportamento indefinido (*undefined behavior*) em cenários críticos, antecipando erros de vazamento de memória (*memory leaks*) e falhas de segmentação (*segmentation faults*).

---

## 🛠️ O Que Foi Utilizado (Tecnologias e Ferramentas)
* **Linguagem C:** Padrão ANSI/ISO C99.
* **Compilador GCC:** Para tradução do código e aplicação de flags estritas de erro (`-Wall -Wextra -Werror`).
* **Editor de Código / IDE:** VS Code (ou qualquer editor de texto via terminal como Vim/Nano).
* **Terminal Linux/POSIX:** Para chamadas de sistema nativas como a `write`.
* **Git:** Para controle de versão e gerenciamento do repositório.

---

## 💻 Desenvolvimento e Divisão do Projeto
O projeto foi segmentado estrategicamente em três grandes blocos de engenharia de software:

### 1. Funções da Libc (Reimplementações)
Reconstrução fiel das funções nativas da linguagem, focando em:
* **Classificação e Conversão:** Varreduras de caracteres e conversões matemáticas de tipos (Ex: `sc_atoi`, `sc_isalnum`, `sc_toupper`).
* **Manipulação de Memória Bruta:** Operações em blocos de bytes puros usando ponteiros genéricos `void *` (Ex: `sc_memcpy`, `sc_memmove`, `sc_memset`).
* **Manipulação de Strings:** Controle seguro de cadeias de caracteres terminadas em `\0` (Ex: `sc_strlcpy`, `sc_strlcat`, `sc_strnstr`).
* **Alocação Dinâmica:** Gerenciamento seguro da memória Heap através da inicialização zerada de vetores com `sc_calloc`.

### 2. Funções Adicionais
Criação de ferramentas mais complexas de manipulação e transformação de dados que não existem nativamente na biblioteca padrão com a mesma assinatura:
* Fatiamento avançado (`sc_substr`, `sc_split`, `sc_strtrim`).
* Conversores inversos (`sc_itoa`).
* Mapeamento por ponteiros de função (`sc_strmapi`, `sc_striteri`).
* Exibição abstrata através de Descritores de Arquivos (`sc_putchar_fd`, `sc_putnbr_fd`).

### 3. Funções de Lista Ligada (Estruturas Dinâmicas)
Desenvolvimento de uma biblioteca de manipulação para a estrutura encadeada `t_list`. Permite a inserção, busca, contagem, iteração e destruição de nós em tempo de execução sem a necessidade de vetores estáticos de tamanho fixo (Ex: `sc_lstnew`, `sc_lstadd_back`, `sc_lstclear`, `sc_lstmap`).

---

## 🧠 O Que Eu Aprendi Desenvolvendo Este Projeto
A construção deste projeto transformou minha percepção sobre programação de baixo nível. Dentre os principais aprendizados técnicos e práticos, destacam-se:

* **A "Escada" de Dependências em C:** Compreendi de forma prática como o compilador faz a leitura linear do código (de cima para baixo). Aprendi a estruturar arquivos de forma modular, posicionando protótipos e funções auxiliares (`basic_strlen`, `is_in_set`) na ordem correta para evitar o erro de *implicit declaration*.
* **Importância Crítica dos Casos de Borda:** Aprendi a blindar funções contra cenários de colapso do sistema operacional, protegendo ponteiros contra valores `NULL` e tratando buffers de tamanho zero (`size_t = 0`) para retornar respostas previsíveis e seguras em vez de travar a aplicação (*SegFault*).
* **Diferença entre `memcpy` e `memmove`:** Entendi o perigo de copiar dados quando as áreas de memória se sobrepõem (*overlap*) e como a leitura reversa (da direita para a esquerda) soluciona o problema.
* **Ponteiros Duplos (`**lst`):** Dominar o uso de ponteiros para ponteiros para conseguir modificar o endereço da "cabeça" de uma lista encadeada diretamente de dentro de funções como `sc_lstadd_front` e `sc_lstclear`.
* **Abstração com Ponteiros de Função:** Descobri como criar códigos genéricos e reutilizáveis passando comportamentos inteiros como parâmetros de função (mapeamentos e limpezas personalizadas nas listas).
* **Responsabilidade com a Memória RAM:** Cada `malloc` exige uma estratégia de liberação. Aprendi a usar ferramentas de limpeza profunda (`sc_lstclear`) para garantir que nenhum byte fique perdido na Heap após o término da execução.

---

## 🚀 Como Executar o Projeto

### Pré-requisitos
Certifique-se de ter um ambiente baseado em Unix (Linux/macOS) ou WSL no Windows, com o compilador `gcc` instalado.

### Passo a Passo
1. Clone o repositório para sua máquina local:
   ```bash
   git clone [https://github.com/seu-usuario/seu-repositorio.git](https://github.com/seu-usuario/seu-repositorio.git)