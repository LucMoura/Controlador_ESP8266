# Controle de Relé via ESP8266

Este projeto permite controlar um relé remotamente por meio de uma interface web hospedada no ESP8266. Através da página, você pode ligar e desligar o relé, que pode ser usado para controlar dispositivos como lâmpadas, ventiladores ou outros equipamentos elétricos.

## Requisitos

- **Hardware:**
  - ESP8266 (NodeMCU ou outro módulo com chip ESP8266)
  - Relé de 5V (utilizado para controlar dispositivos externos)
  - Fonte de alimentação para o ESP8266 e o relé
  - Fios para conexão
  - (Opcional) LED para indicar o estado do relé
  
- **Software:**
  - Arduino IDE
  - Biblioteca **ESP8266WiFi**
  - Biblioteca **ESPAsyncWebServer**
  - Biblioteca **ESPAsyncTCP**

## Como Funciona

Este programa utiliza o ESP8266 para se conectar a uma rede Wi-Fi e hospedar um servidor web simples. A página web permite ao usuário ligar e desligar um relé conectado ao ESP8266. A página pode ser acessada de qualquer dispositivo conectado à mesma rede Wi-Fi.

## Configuração

1. **Instalar as Bibliotecas Necessárias**:

   - No Arduino IDE, instale as bibliotecas necessárias:
     - **ESP8266WiFi**: Usada para a conexão Wi-Fi.
     - **ESPAsyncWebServer**: Usada para criar o servidor web assíncrono.
     - **ESPAsyncTCP**: Usada pelo **ESPAsyncWebServer** para comunicação TCP.

2. **Baixar e Instalar o Código**:

   - Abra o Arduino IDE e crie um novo esboço.
   - Copie e cole o código-fonte adaptado abaixo, substituindo o nome da sua rede Wi-Fi e a senha.

3. **Carregar o Código para o ESP8266**:

   - Selecione a placa correta em **Ferramentas > Placa** e escolha seu modelo de ESP8266 (por exemplo, **NodeMCU 1.0 (ESP-12E Module)**).
   - Conecte o ESP8266 ao computador e carregue o código usando o Arduino IDE.

4. **Conectar o Relé ao ESP8266**:

   - Conecte o pino de controle do relé a um dos pinos GPIO do ESP8266 (geralmente GPIO5 ou GPIO0).
   - O relé pode ser conectado para controlar dispositivos elétricos, como lâmpadas.

## Testar o Sistema

1. Após carregar o código para o ESP8266, abra o Monitor Serial no Arduino IDE.
2. Quando o ESP8266 estiver conectado ao Wi-Fi, ele exibirá o endereço IP atribuído a ele.
3. Abra o navegador web e acesse o IP do ESP8266. Você verá a página web com dois botões:
   - **Ligado**: Aciona o relé.
   - **Desligado**: Desliga o relé.

## Observações

- **Segurança**: Este sistema não possui qualquer tipo de autenticação. Para projetos mais avançados, você pode adicionar autenticação ou criptografia (HTTPS).
- **Capacidade de Controle**: A partir da página web, você pode controlar o estado do relé de qualquer dispositivo conectado à mesma rede Wi-Fi.

## Conclusão

Este projeto é uma excelente maneira de aprender a controlar dispositivos remotamente utilizando o ESP8266 e um servidor web simples. O código pode ser facilmente modificado para controlar mais relés ou adicionar funcionalidades adicionais, como controle por aplicativo ou integração com sistemas de automação.
