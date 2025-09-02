# CP4-Edge---Hands-On-de-Vinherias-pelo-Cloud-IoT

Monitoramento de Vinherias com ESP32 e Cloud IoT (ThingSpeak)
Sobre o Projeto
Este projeto, desenvolvido para a disciplina de Edge Computing & Computer Systems do 4º semestre de Engenharia de Software, consiste em um protótipo de um sistema de monitoramento de vinherias. Utilizando um microcontrolador ESP32 e sensores de ambiente, o sistema coleta dados vitais como temperatura, umidade e luminosidade, e os envia em tempo real para a plataforma de nuvem IoT ThingSpeak, permitindo a visualização e análise remota dos dados.

A simulação e o desenvolvimento inicial foram realizados na plataforma Wokwi, que permite testar o hardware e o firmware em um ambiente virtual antes da implementação física.

Tecnologias e Componentes Utilizados
Hardware
Microcontrolador: DOIT ESP32 DEVKIT V1

Sensor de Temperatura e Umidade: DHT22 (AM2302)

Sensor de Luminosidade: LDR (Resistor Dependente de Luz)

Software e Plataformas
Linguagem de Programação: C++ (no framework Arduino)

Plataforma de Simulação: Wokwi

Plataforma Cloud IoT: ThingSpeak

Bibliotecas Arduino:

WiFi.h

HTTPClient.h

DHT.h

Funcionalidades
Leitura de Sensores: Coleta de dados de temperatura (°C), umidade relativa do ar (%) e nível de luminosidade (valor analógico).

Conectividade Wi-Fi: O ESP32 se conecta a uma rede Wi-Fi para obter acesso à internet.

Comunicação com a Nuvem: Envio dos dados coletados para um canal específico no ThingSpeak através de requisições HTTP GET.

Visualização de Dados: Os dados podem ser visualizados em tempo real através de gráficos e dashboards configurados no ThingSpeak.

Monitoramento Remoto: Permite que as condições ambientais da vinheria sejam acompanhadas de qualquer lugar com acesso à internet.

Como Configurar e Usar
Para replicar este projeto, siga os passos abaixo:

1. Configuração do ThingSpeak
Crie uma conta gratuita no ThingSpeak.

Vá em Channels > My Channels e clique em New Channel.

Configure o canal com os seguintes campos (fields):

Field 1: Temperatura

Field 2: Umidade

Field 3: Luminosidade

Salve o canal.

Clique na aba API Keys e copie a sua Write API Key.

2. Configuração do Código
Clone este repositório para a sua máquina ou abra o projeto no Wokwi.

Abra o arquivo principal (.ino).

Localize a seguinte linha e substitua "SUA_API_KEY_AQUI" pela chave que você copiou do ThingSpeak:

C++

const char* apiKey = "SUA_API_KEY_AQUI";
Se estiver usando um ESP32 físico, altere também as credenciais de Wi-Fi:

C++

const char* ssid = "NOME_DA_SUA_REDE";
const char* password = "SENHA_DA_SUA_REDE";
3. Execução
No Wokwi: Abra o link do projeto e clique no botão de "Play" para iniciar a simulação. Acompanhe a saída no Monitor Serial para ver o status da conexão e do envio de dados.

Em um ESP32 Físico: Conecte a placa ao seu computador, configure a Arduino IDE com o suporte para ESP32 e faça o upload do código.

Autores
Este projeto foi desenvolvido por:

Nome	RM
Mateus Macedo	563294
Gustavo Cavalcanti	565601
Matheus Augusto	565931
Tomás Antonio	563295
Felipe Riofrio	563068
