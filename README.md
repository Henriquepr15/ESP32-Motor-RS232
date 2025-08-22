# ESP32 Motor RS232  

Projeto desenvolvido como parte de um teste prático para posição de Desenvolvedor de Hardware/Firmware.  

## Descrição  
Circuito com ESP32 para acionamento de motor a partir de sinal externo, utilizando reguladores de tensão, conversor buck LM2596, driver de motor e comunicação serial RS232 (MAX3232).  

## Funcionalidades  
- Leitura de sinal externo  
- Acionamento de motor por 10 segundos em nível baixo  
- Envio de mensagens de status via UART RS232  
- LEDs indicadores de funcionamento e debug  

## Estrutura do Projeto  
- Esquemáticos e PCB: Arquivos KiCad  
- Gerber, Drill, PnP e BOM: Saída de fabricação  
- Código em C: Arquivo main.c  
- Documentação: Datasheets e anotações  

## Requisitos de Software  
Código em linguagem C, leitura de entrada digital, controle de saída para o motor, temporização de 10 segundos e comunicação UART.  

## Como Compilar  
O código foi escrito em C padrão, podendo ser adaptado para o ESP32 com ESP-IDF ou Arduino IDE.  

## Requisitos de Hardware  
- ESP32-WROOM-32  
- LM2596 (buck converter)  
- AMS1117-3.3 (regulador LDO)  
- MAX3232 (interface RS232)  
- MOSFET AO3400A  
- Indutor, capacitores, resistores e conectores auxiliares  

## Autor  
Henrique Pires  

## Imagens do projeto  
<img width="1059" height="863" alt="image" src="https://github.com/user-attachments/assets/de014dee-79eb-460e-a447-a153f0ae4b80" />
<img width="905" height="781" alt="image" src="https://github.com/user-attachments/assets/7fb08f5c-5769-4d3a-b745-448164e10f41" />
