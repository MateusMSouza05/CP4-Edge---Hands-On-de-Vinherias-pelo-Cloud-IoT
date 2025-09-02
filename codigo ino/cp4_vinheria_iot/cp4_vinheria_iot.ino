/*
 * Projeto: Protótipo de Monitoramento de Vinheria com ESP32 e ThingSpeak
 * * Descrição: Este firmware coleta dados de temperatura, umidade (DHT22) e 
 * luminosidade (LDR) e os envia para a plataforma de IoT ThingSpeak 
 * utilizando uma requisição HTTP GET.
 * * Autores:
 * - Mateus Macedo       RM 563294
 * - Gustavo Cavalcanti  RM 565601
 * - Matheus Augusto     RM 565931
 * - Tomás Antonio       RM 563295
 * - Felipe Riofrio      RM 563068
 * * Data: 02/09/2025
 */


// --- Inclusão de Bibliotecas ---
#include <WiFi.h>
#include <HTTPClient.h> 
#include "DHT.h"

// --- Configurações de Rede e ThingSpeak ---
const char* ssid = "Wokwi-GUEST";
const char* password = "";
// Use a sua própria Write API Key
const char* apiKey = "VKTMETB83X7W62KC";
const char* server = "http://api.thingspeak.com";

// --- Definições dos Pinos e Sensores ---
#define DHTPIN 15
#define DHTTYPE DHT22
const int LDR_PIN = 34; // Pino para o sensor de luminosidade LDR

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();

  // Conexão com o Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Conectando ao WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado!");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
  Serial.println("------------------------------------");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    // --- Leitura dos sensores ---
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    int lightValue = analogRead(LDR_PIN); // Leitura do valor de luminosidade (0-4095)

    if (isnan(h) || isnan(t)) {
      Serial.println("Falha ao ler o sensor DHT!");
      delay(2000);
      return;
    }

    // --- Envio de dados para o ThingSpeak com HTTPClient ---
    HTTPClient http;
    
    // Constrói a URL completa para a requisição GET
    String url = String(server) + "/update?api_key=" + apiKey + "&field1=" + String(t) +
                 "&field2=" + String(h) + "&field3=" + String(lightValue);
    
    http.begin(url); // Inicia a requisição

    int httpCode = http.GET(); // Executa a requisição GET

    if (httpCode > 0) {
      String payload = http.getString();
      Serial.println("Dados enviados ao ThingSpeak.");
      Serial.printf("  [HTTP] Código de resposta: %d\n", httpCode);
      // Serial.printf("  [HTTP] Resposta do servidor: %s\n", payload.c_str()); // Opcional
      Serial.println("------------------------------------");
    } else {
      Serial.printf("[HTTP] Falha no GET, erro: %s\n", http.errorToString(httpCode).c_str());
    }
    
    http.end(); // Libera os recursos

  } else {
    Serial.println("WiFi não conectado.");
  }
  
  // ThingSpeak requer um intervalo de no mínimo 15 segundos. Usamos 20 para segurança.
  delay(20000);
}