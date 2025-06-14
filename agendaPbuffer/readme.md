 João Pedro Rocha da Silva M1

Agenda em C com Buffer Único
Um programa de agenda de contatos simples, desenvolvido em C, com o objetivo de gerenciar toda a memória manualmente dentro de um único buffer.

Conceito Principal
Este projeto é um exercício de programação em C com a restrição de não utilizar variáveis convencionais para o armazenamento de dados. Toda a informação do programa, incluindo metadados, listas de contatos e buffers temporários de entrada, é guardada e manipulada dentro de um único bloco de memória alocado (void*), exigindo gerenciamento manual de ponteiros e offsets.