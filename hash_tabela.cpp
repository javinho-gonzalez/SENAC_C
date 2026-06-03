#include <iostream>
#include <unordered_map> // Implementação de hash Table em C++
#include <string>

int maing () {
    //Criando uma tabela hash de contatos (Nome -> Telefone)
    std::unordered_map<std::string, std::string> contatos;

    //Inserindo dados
    contatos["Alice"] = "9988-7766";
    contatos["Bruno"] = "9112-3344";

    //Buscando um valor pela chave 
    std::string nome = "Alice";
    if (contatos.find(nome) != contatos.end()) {
        std::cout << "O telefone de " << nome << "e" << contatos [nome];
    }
    return 0;
}