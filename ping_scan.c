#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#ifdef _WIN32
    #define PING_CMD "ping -n 1 "
#else
    #define PING_CMD "ping -c 1 "
#endif

#define MAX_THREADS 10  // Anzahl gleichzeitiger Threads
#define IP_BUFFER_SIZE 20

typedef struct {
    char ip[IP_BUFFER_SIZE];
} PingTask;

void* ping_ip(void* arg) {
    PingTask* task = (PingTask*)arg;
    char command[IP_BUFFER_SIZE + 10];  // Puffer für Ping-Befehl
    snprintf(command, sizeof(command), "%s%s", PING_CMD, task->ip);

    // Ping ausführen und Ergebnis prüfen
    if (system(command) == 0) {
        printf("✔ IP %s ist erreichbar!\n", task->ip);
        FILE* file = fopen("ips.txt", "a");
        if (file) {
            fprintf(file, "%s\n", task->ip);
            fclose(file);
        }
    }
    free(task);
    return NULL;
}

int main() {
    char base_ip[16];
    int start_ip, end_ip;

    printf("🔎 Effizienter Ping-Scanner\n");
    printf("Gib das Subnetz an (z. B. 192.168.1): ");
    scanf("%15s", base_ip);
    printf("Start-IP (Standard: 1): ");
    scanf("%d", &start_ip);
    printf("End-IP (Standard: 40): ");
    scanf("%d", &end_ip);

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int i = start_ip; i <= end_ip; i++) {
        PingTask* task = malloc(sizeof(PingTask));
        snprintf(task->ip, IP_BUFFER_SIZE, "%s.%d", base_ip, i);

        // Thread starten
        pthread_create(&threads[thread_count], NULL, ping_ip, task);
        thread_count++;

        // Warte auf freie Threads, falls Limit erreicht ist
        if (thread_count >= MAX_THREADS) {
            for (int j = 0; j < thread_count; j++) {
                pthread_join(threads[j], NULL);
            }
            thread_count = 0;
        }
    }

    // Letzte Threads warten lassen
    for (int j = 0; j < thread_count; j++) {
        pthread_join(threads[j], NULL);
    }

    printf("✅ Scan abgeschlossen! Ergebnisse in 'ips.txt'.\n");
    return 0;
}
