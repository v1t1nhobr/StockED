# StockED – Sistema de Gerenciamento de Estoque

## Informações Acadêmicas

- **Instituição:** UniRuy Wyden
- **Curso:** Análise e Desenvolvimento de Sistemas
- **Disciplina:** Estrutura de Dados
- **Professor:** Heleno Cardoso
- **Aluno:** João Vitor Ferreira da Silva
- **Ano:** 2026

## Sobre o Projeto

O StockED é um sistema de gerenciamento de estoque desenvolvido em linguagem C, com o objetivo de aplicar e comparar três estruturas de dados na resolução de um problema real do cotidiano.

## Situação-Problema

Pequenos estabelecimentos comerciais, como lojas de açaí, possuem dificuldades relacionadas à organização, consulta e atualização dos produtos em estoque.

Com o aumento da quantidade de produtos cadastrados, a escolha da estrutura de dados pode influenciar diretamente na eficiência das operações realizadas pelo sistema.

## Solução Proposta

Desenvolvimento de um sistema computacional que permite gerenciar produtos em estoque utilizando três estruturas de dados diferentes:

- Vetor;
- Lista encadeada;
- Tabela hash.

O sistema permite realizar operações de gerenciamento e comparar a quantidade de verificações necessárias para localizar um produto em cada estrutura.

## Objetivos

- Aplicar estruturas de dados em uma situação real;
- Desenvolver uma solução computacional funcional;
- Comparar o desempenho das três estruturas;
- Analisar suas vantagens e limitações;
- Identificar a estrutura mais adequada ao problema apresentado.

## Funcionalidades

- Cadastro de produtos;
- Busca de produtos pelo código;
- Atualização da quantidade em estoque;
- Remoção de produtos;
- Listagem dos produtos cadastrados;
- Alternância entre estruturas de dados;
- Comparação da quantidade de verificações durante as buscas.

## Estruturas de Dados Utilizadas

### 1. Vetor

Armazena os produtos de maneira sequencial na memória.

**Vantagens:**
- Fácil implementação;
- Acesso direto por índice;
- Simplicidade na organização dos dados.

**Limitações:**
- Capacidade limitada na implementação utilizada;
- Busca sequencial;
- Necessidade de deslocamento de elementos em determinadas remoções.

### 2. Lista Encadeada

Armazena os produtos em nós conectados por ponteiros, utilizando alocação dinâmica de memória.

**Vantagens:**
- Flexibilidade no armazenamento;
- Alocação dinâmica de memória;
- Inserção e remoção sem deslocamento dos demais elementos.

**Limitações:**
- Busca sequencial;
- Utilização adicional de memória para ponteiros;
- Ausência de acesso direto por índice.

### 3. Tabela Hash

Utiliza uma função hash para determinar a posição de armazenamento dos produtos a partir de seus códigos.

**Vantagens:**
- Busca eficiente em condições médias;
- Rapidez nas operações de atualização;
- Acesso baseado no código do produto.

**Limitações:**
- Possibilidade de colisões;
- Maior complexidade de implementação;
- Desempenho dependente da distribuição dos elementos.

## Comparação das Estruturas de Dados

| Operação | Vetor | Lista Encadeada | Tabela Hash |
|---|---|---|---|
| Busca por código | O(n) | O(n) | O(1) em média |
| Inserção com verificação de duplicidade | O(n) | O(n) | O(1) em média |
| Remoção por código | O(n) | O(n) | O(1) em média |
| Atualização por código | O(n) | O(n) | O(1) em média |
| Listagem | O(n) | O(n) | O(n + m) |
| Implementação | Simples | Intermediária | Intermediária |

Na tabela hash, `m` representa a quantidade de posições da tabela. Em situações com muitas colisões, determinadas operações podem apresentar complexidade O(n).

## Resultados Obtidos

Durante a execução do sistema, foram realizadas buscas utilizando os mesmos produtos nas três estruturas.

| Código pesquisado | Vetor | Lista Encadeada | Tabela Hash |
|---|---:|---:|---:|
| 101 - Produto existente | 1 | 5 | 2 |
| 999 - Produto inexistente | 5 | 5 | 1 |

Os valores representam a quantidade de comparações realizadas durante cada busca.

Os resultados demonstram que o desempenho pode variar de acordo com a organização dos dados e o produto pesquisado.

## Escolha da Melhor Estrutura de Dados

A tabela hash foi considerada a estrutura mais adequada para a situação-problema apresentada, pois um sistema de gerenciamento de estoque realiza frequentemente operações de busca e atualização de produtos pelo código.

Sua complexidade média O(1) nessas operações representa uma vantagem em relação à busca sequencial utilizada pelo vetor e pela lista encadeada.

Apesar da possibilidade de colisões e da capacidade fixa da tabela implementada, a tabela hash apresenta características favoráveis às necessidades do sistema proposto.

## Tecnologias Utilizadas

- Linguagem C;
- Visual Studio Code;
- Compilador GCC;
- GitHub.

## Como Executar

### Pelo Visual Studio Code

1. Baixe o arquivo `main.c`;
2. Abra o arquivo no Visual Studio Code;
3. Certifique-se de que o compilador GCC está instalado;
4. Utilize a opção Compile & Run, caso esteja configurada;
5. Interaja com o menu apresentado no terminal.

### Pelo terminal do Windows

Compile o código:

```bash
gcc main.c -o StockED.exe
```

Execute o programa:

```powershell
.\StockED.exe
```

## Estrutura do Repositório

```text
StockED/
├── main.c
├── Relatorio.pdf
└── README.md
```

## Documentação e Código-Fonte

- [Código-fonte do sistema](./main.c)
- [Relatório acadêmico completo](./Relatorio.pdf)

## Conclusão

O desenvolvimento do StockED permitiu compreender, na prática, como diferentes estruturas de dados podem ser utilizadas para solucionar um mesmo problema.

A comparação realizada demonstrou a importância da escolha de uma estrutura de dados adequada, considerando as operações mais frequentes e as necessidades da aplicação.

O projeto possui finalidade acadêmica e foi desenvolvido como um protótipo funcional, sem armazenamento permanente dos dados.

---

Projeto desenvolvido para a disciplina de Estrutura de Dados
do curso de Análise e Desenvolvimento de Sistemas — UniRuy Wyden.
