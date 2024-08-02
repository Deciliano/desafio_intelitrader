#include <stdio.h>
#include <stdlib.h>

#define MAX_OFFERS 1000

typedef struct {
    int position;
    double value;
    int quantity;
} Offer;

Offer offers[MAX_OFFERS];
int num_offers = 0;

// Função para encontrar a posição no livro de ofertas
int find_offer_index(int position) {
    for (int i = 0; i < num_offers; i++) {
        if (offers[i].position == position) {
            return i;
        }
    }
    return -1;
}

// Função para inserir ou modificar uma oferta
void insert_or_modify_offer(int position, double value, int quantity) {
    int index = find_offer_index(position);
    if (index != -1) {
        // Modificar oferta existente
        offers[index].value = value;
        offers[index].quantity = quantity;
    } else {
        // Inserir nova oferta
        if (num_offers < MAX_OFFERS) {
            offers[num_offers].position = position;
            offers[num_offers].value = value;
            offers[num_offers].quantity = quantity;
            num_offers++;
        } else {
            printf("Erro: Limite máximo de ofertas alcançado.\n");
        }
    }
}

// Função para deletar uma oferta
void delete_offer(int position) {
    int index = find_offer_index(position);
    if (index != -1) {
        // Remover oferta existente
        for (int i = index; i < num_offers - 1; i++) {
            offers[i] = offers[i + 1];
        }
        num_offers--;
    }
}

// Função para processar as notificações
void process_notifications(int n) {
    int position, action, quantity;
    double value;

    for (int i = 0; i < n; i++) {
        if (scanf("%d,%d,%lf,%d", &position, &action, &value, &quantity) != 4) {
            printf("Erro na leitura da notificação. Verifique o formato da entrada.\n");
            return;
        }
        
        switch (action) {
            case 0: // Inserir
            case 1: // Modificar
                if (quantity > 0) { // Apenas insere ou modifica se a quantidade for positiva
                    insert_or_modify_offer(position, value, quantity);
                }
                break;
            case 2: // Deletar
                delete_offer(position);
                break;
            default:
                printf("Ação desconhecida: %d\n", action);
                break;
        }
    }
}

// Função para ordenar ofertas por posição
void sort_offers() {
    for (int i = 0; i < num_offers - 1; i++) {
        for (int j = i + 1; j < num_offers; j++) {
            if (offers[i].position > offers[j].position) {
                Offer temp = offers[i];
                offers[i] = offers[j];
                offers[j] = temp;
            }
        }
    }
}

// Função para imprimir o resultado
void print_result() {
    sort_offers();
    printf("POSICAO - VALOR - QUANTIDADE\n");
    for (int i = 0; i < num_offers; i++) {
        printf("%d - %.2f - %d\n", offers[i].position, offers[i].value, offers[i].quantity);
    }
}

int main() {
    int n;

    printf("Digite o número de notificações:\n");
    if (scanf("%d", &n) != 1) {
        printf("Erro na leitura do número de notificações.\n");
        return 1;
    }
    
    printf("Digite as notificações (uma por linha):\n");
    process_notifications(n);
    print_result();
    
    return 0;
}
