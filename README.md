# Flersensorsystem

## Uppgiftsbeskrivning
Programmet är ett flersensorsystem i C++ som simulerar flera olika sensorer
(temperatur, luftfuktighet, tryck). Systemet samlar in mätvärden, lagrar dem
per sensor, visar enkel statistik och kan trigga larm baserat på tröskelregler.
Allt styrs via en textbaserad meny i terminalen.

## Funktionalitet

- **Sensor (abstrakt klass)**  
  Gemensam basklass för alla sensorer. Innehåller bl.a. stöd för:
  - tröskelvärden
  - larm
  - lagring av mätvärden
  - utskrift av statistik och historik

- **TemperatureSensor / HumiditySensor / PressureSensor**  
  Konkreta sensorer som ärver från `Sensor` och implementerar:
  - hur ett mätvärde genereras (`read()`)
  - vilket namn och vilken enhet sensorn har

- **MeasurementStorage**  
  Ansvarar för att:
  - spara alla mätningar
  - beräkna statistik (min, max, medelvärde, standardavvikelse)
  - skriva ut mätningar
  - spara/läsa till/från fil
  - skriv ut överskridande mätningar

- **Measurement / Threshold / Alarm (structs)**  
  - `Measurement`: ett enskilt mätvärde (namn, enhet, värde, tidsstämpel)  
  - `Threshold`: gränsvärde kopplat till en sensor  
  - `Alarm`: representerar ett larm som utlöstes p.g.a. ett tröskelvärde

## Kompilering & körning

## Tröskelregler
Det konfigureras via menyn av användaren.

## Design 
Designen utgår från en abstrakt basklass `Sensor` som definierar gränssnittet (`read()`, `name()`, `unit()`), och flera konkreta sensorer som specialiserar beteendet. Det följer samma idé som Strategy-pattern, där olika varianter av ett beteende byts ut via polymorfism. Alla sensorer lagras polymorft i en `std::vector<std::unique_ptr<Sensor>>`, vilket gör att meny- och statistikdelarna bara ser basklassen och slipper if-else på sensortyp. Lagring av mätvärden ligger i en separat klass `MeasurementStorage`, och tröskelregler/larm är egna strukturer, vilket håller ansvar tydligt separerade och gör det enklare att ändra sensorer eller regelhantering utan att ändra resten av systemet.
Jag räknar ut värdena för statistiken vid skapandet av ett nytt mätvärde för att slippa räkna ut det varje gång man ska skriva ut statistiken.
