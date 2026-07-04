#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CONNECTIONS_PER_MIN 3
#define WHITELIST_SIZE 2

// IP Whitelist de destination
const char* IP_WHITELIST[WHITELIST_SIZE] = {
    "172.19.0.10", // Broker MQTT Interne
    "10.0.4.2"     // Serveur Cloud OTA officiel
};

// Variable d'état
static int connection_count_last_minute = 0;
static unsigned long last_reset_time = 0;

bool check_destination_ip(const char* dest_ip) {
    for (int i = 0; i < WHITELIST_SIZE; i++) {
        if (strcmp(dest_ip, IP_WHITELIST[i]) == 0) {
            return true; // IP de confiance autorisée
        }
    }
    return false; // Tentative suspecte !
}

bool log_and_filter_network_event(const char* dest_ip, int bytes_sent) {
    // 1. Audit de l'IP de destination
    if (!check_destination_ip(dest_ip)) {
        printf("[WATCHDOG ALERT] 🔴 BLOCAGE : Tentative de connexion vers IP non-autorisée: %s\n", dest_ip);
        return false; // Bloquer l'appel réseau
    }

    // 2. Vérification de la fréquence (Rate Limiting)
    connection_count_last_minute++;
    if (connection_count_last_minute > MAX_CONNECTIONS_PER_MIN) {
        printf("[WATCHDOG ALERT] 🔴 DEPASSEMENT DE DEBIT : %d tentatives ce tour. Entrée en mode PROTECTION.\n", connection_count_last_minute);
        return false;
    }

    printf("[WATCHDOG INFO] 🟢 Liaison réseau acceptée vers %s (%d octets transmis)\n", dest_ip, bytes_sent);
    return true;
}

int main() {
    printf("[WATCHDOG INITIALISE] Démarrage du contrôleur d'intégrité réseau... OK\n");
    
    // Simulations d'appels réseaux normaux puis piratés
    log_and_filter_network_event("172.19.0.10", 64);  // OK (MQTT)
    log_and_filter_network_event("10.0.4.2", 1024);   // OK (OTA)
    log_and_filter_network_event("192.168.99.99", 512); // Bloqué (Exfiltration Pirate)
    
    return 0;
}
