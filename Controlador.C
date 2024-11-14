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
    <head>
    <meta charset = "UTF-8">
    <title>Controlador interessante</title>
      <style>
        body {
          font-family: 'Arial', sans-serif;
          background-color: #f0f8ff; 
          color: #333;
          display: flex;
          justify-content: center;
          align-items: center;
          height: 100vh;
          margin: 0;
        }

        h2 {
          color: #4a90e2; 
          font-size: 2em;
          text-align: center;
          margin-bottom: 20px;
        }

        button {
          background-color: #4a90e2; 
          color: white;
          border: none;
          border-radius: 10px;
          padding: 15px 30px;
          font-size: 1.2em;
          margin: 10px;
          cursor: pointer;
          transition: background-color 0.3s ease;
        }

        button:hover {
          background-color: #357ab7; 
        }

        button:active {
          background-color: #2a5d8d; 
        }

        .container {
          text-align: center;
        }

      </style>
    </head>
    <body>
      <div class="container">
        <h2>Controlador remoto</h2>
        <button onclick="ligar()">Ligar</button>
        <button onclick="desligar()">Desligar</button>
      </div>

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
