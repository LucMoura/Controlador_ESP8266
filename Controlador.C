#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>

const char *ssid = "NOME DO SEU WIFI";
const char *password = "SENHA DO SEU WIFI";

const int relayPin = D4;  
AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);
  Serial.println("Iniciando...");


  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); 

  WiFi.begin(ssid, password);
  Serial.print("Conectando ao Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConectado ao WiFi!");

  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
     request->send(200, "text/html", R"rawliteral(
    <!DOCTYPE html>
    <html>
    <body>
      <h2>Controle do Relé</h2>
      <button onclick="ligar()">Ligar</button>
      <button onclick="desligar()">Desligar</button>
      <script>
        function ligar() {
          fetch('/ligar').then(response => response.text()).then(data => {
            console.log(data);
          });
        }
        function desligar() {
          fetch('/desligar').then(response => response.text()).then(data => {
            console.log(data);
          });
        }
      </script>
    </body>
    </html>
  )rawliteral");
  });

  server.on("/ligar", HTTP_GET, [](AsyncWebServerRequest *request) {
    digitalWrite(relayPin, LOW);
    Serial.println("Relé Ligado");
    request->send(200, "text/plain", "Relé Ligado");
  });

  server.on("/desligar", HTTP_GET, [](AsyncWebServerRequest *request) {
    digitalWrite(relayPin, HIGH);
    Serial.println("Relé Desligado");
    request->send(200, "text/plain", "Relé Desligado");
  });

  server.begin();
}

void loop() {
}
