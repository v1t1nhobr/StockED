#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAP 100
#define M 23

typedef struct  {
    int codigo, quantidade;
    char nome[80];
} Produto;
typedef struct No  {
    Produto p;
    struct No *prox;
} No;
Produto vetor[CAP];
int n=0;
No *lista=NULL, *hash[M]= {
    0
};
int ler(const char *msg, int min, int max)  {
    char s[128], extra;
    int x;
    for (;;)  {
        printf("%s",msg);
        if(!fgets(s,sizeof s,stdin)) exit(0);
        if(sscanf(s,"%d %c",&x,&extra)==1 && x>=min && x<=max) return x;
        puts("Valor invalido.");
    }
}
No **inicio(int modo,int codigo) {
    return modo==2? &lista : &hash[codigo%M];
}
Produto *buscar(int modo,int codigo,int *passos) {
    *passos=0;
    if(modo==1) {
        for(int i=0;i<n;i++) {
            ++*passos;
            if(vetor[i].codigo==codigo)return &vetor[i];
        }
    } else {
        for(No *p=*inicio(modo,codigo);p;p=p->prox) {
            ++*passos;
            if(p->p.codigo==codigo)return &p->p;
        }
    }
    return NULL;
}
/* Verifica duplicidade antes de inserir. */
int inserir(int modo,Produto p) {
    int passos;
    if(buscar(modo,p.codigo,&passos))return 0;
    if(modo==1) {
        if(n==CAP)return 0;
        vetor[n++]=p;
    } else {
        No *novo=malloc(sizeof *novo);
        if(!novo)return 0;
        No **cab=inicio(modo,p.codigo);
        novo->p=p;
        novo->prox=*cab;
        *cab=novo;
    }
    return 1;
}
/* Remove por troca no vetor ou ajuste de ponteiros nas listas. */
int remover(int modo,int codigo) {
    if(modo==1) {
        for(int i=0;i<n;i++)if(vetor[i].codigo==codigo) {
            vetor[i]=vetor[--n];
            return 1;
        }
    } else {
        No **p=inicio(modo,codigo);
        while(*p) {
            if((*p)->p.codigo==codigo) {
                No *old=*p;
                *p=old->prox;
                free(old);
                return 1;
            }p=&(*p)->prox;
        }
    }
    return 0;
}
void mostrar(Produto p) {
    printf("%d | %s | estoque: %d\n",p.codigo,p.nome,p.quantidade);
}
void listar(int modo) {
    if(modo==1) {
        for(int i=0;i<n;i++)mostrar(vetor[i]);
    } else if(modo==2) {
        for(No *p=lista;p;p=p->prox)mostrar(p->p);
    } else {
        for(int i=0;i<M;i++)for(No *p=hash[i];p;p=p->prox)mostrar(p->p);
    }
}
void comparar(void) {
    int total_lista = 0, total_hash = 0, passos;
    for (No *q = lista; q; q = q->prox) total_lista++;
    for (int i = 0; i < M; i++)
        for (No *q = hash[i]; q; q = q->prox) total_hash++;
    if (n != total_lista || n != total_hash) {
        puts("Comparacao indisponivel: estoques diferentes. Reinicie o programa.");
        return;
    }
    for (int i = 0; i < n; i++) {
        Produto *a = buscar(2, vetor[i].codigo, &passos);
        Produto *b = buscar(3, vetor[i].codigo, &passos);
        if (!a || !b || a->quantidade != vetor[i].quantidade ||
            b->quantidade != vetor[i].quantidade ||
            strcmp(a->nome, vetor[i].nome) || strcmp(b->nome, vetor[i].nome)) {
            puts("Comparacao indisponivel: estoques diferentes. Reinicie o programa.");
            return;
        }
    }
    int c = ler("Codigo para comparar: ", 1, 1000000);
    for (int m = 1; m <= 3; m++) {
        int passos;
        Produto *p = buscar(m, c, &passos);
        printf("%s: %s, %d comparacoes\n", m == 1 ? "Vetor" : m == 2 ? "Lista" : "Hash", p ? "encontrado" : "ausente", passos);
    }
}
/* Libera os nos alocados dinamicamente. */
void limpar(No *p) {
    while(p) {
        No *q=p->prox;
        free(p);
        p=q;
    }
}
int main(void) {
    Produto amostra[]= {
        {
            101,10,"Acai 5L"
        }, {
            102,20,"Copo 500ml"
        }, {
            103,15,"Tampa 500ml"
        }, {
            124,8,"Granola"
        }, {
            105,12,"Leite em po"
        }
    };
    for(int m=1;m<=3;m++)for(int i=0;i<5;i++)inserir(m,amostra[i]);
    int modo=1;
    for(;;) {
        printf("\nStockED | %s\n1 Cadastrar\n2 Buscar\n3 Atualizar\n4 Remover\n5 Listar\n6 Trocar estrutura\n7 Comparar buscas\n0 Sair\n",modo==1?"Vetor":modo==2?"Lista":"Hash");
        int op=ler("Opcao: ",0,7);
        if(!op)break;
        if(op==6) {
            modo=ler("1 Vetor, 2 Lista, 3 Hash: ",1,3);
            continue;
        }
    if(op==7) {
            comparar();
            continue;
        }
    if(op==5) {
            listar(modo);
            continue;
        }
    int c=ler("Codigo: ",1,1000000),passos;
        Produto *p=buscar(modo,c,&passos);
        if(op==1) {
            if(p) {
                puts("Codigo duplicado.");
                continue;
            }Produto novo= {
                .codigo=c
            };
            printf("Nome: ");
            if(!fgets(novo.nome,sizeof novo.nome,stdin))break;
            novo.nome[strcspn(novo.nome,"\n")]=0;
            if(!novo.nome[0]) {
                puts("Nome vazio.");
                continue;
            }novo.quantidade=ler("Quantidade: ",0,1000000);
            puts(inserir(modo,novo)?"Cadastrado.":"Falha na insercao.");
        } else if(op==2) {
            if(p)mostrar(*p);
            else puts("Nao encontrado.");
            printf("Comparacoes: %d\n",passos);
        } else if(op==3) {
            if(p) {
                p->quantidade=ler("Nova quantidade: ",0,1000000);
                puts("Atualizado.");
            } else puts("Nao encontrado.");
        } else if(op==4)puts(remover(modo,c)?"Removido.":"Nao encontrado.");
    }
    limpar(lista);
    for(int i=0;i<M;i++)limpar(hash[i]);
    return 0;
}
