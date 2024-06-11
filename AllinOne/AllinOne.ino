#include <ESP_FlexyStepper.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <DHT.h>
#include <DHT_U.h>

// Definindo os pinos dos motores
const int motor1_step_pin = 35;
const int motor1_direction_pin = 32;
const int motor2_step_pin = 33;
const int motor2_direction_pin = 25;
const int motor3_step_pin = 26;
const int motor3_direction_pin = 27;

// Definindo os sensores
// Acelerômetro
Adafruit_MPU6050 mpu;

#define DHTPIN 15       // Pino onde o DHT22 está conectado
#define DHTTYPE DHT22   // Definindo o tipo do sensor DHT

DHT dht(DHTPIN, DHTTYPE);

// Pino do sensor de umidade
const int sensorPin = 34; // Pino onde o sensor está conectado

// Definindo os motores
ESP_FlexyStepper motor1;
ESP_FlexyStepper motor2;
ESP_FlexyStepper motor3;

void setup() {
  Serial.begin(115200);

  dht.begin();

  // Setup do leitor de umidade
  pinMode(sensorPin, INPUT);

  // Set up stepper motor pins
  motor1.connectToPins(motor1_step_pin, motor1_direction_pin);
  motor2.connectToPins(motor2_step_pin, motor2_direction_pin);
  motor3.connectToPins(motor3_step_pin, motor3_direction_pin);

  // Set stepper motor speed and acceleration
  motor1.setSpeedInStepsPerSecond(1000); // Adjust as needed
  motor1.setAccelerationInStepsPerSecondPerSecond(500);
  motor1.setDecelerationInStepsPerSecondPerSecond(500); // Adjust as needed

  motor2.setSpeedInStepsPerSecond(1000); // Adjust as needed
  motor2.setAccelerationInStepsPerSecondPerSecond(500);
  motor2.setDecelerationInStepsPerSecondPerSecond(500); // Adjust as needed

  motor3.setSpeedInStepsPerSecond(1000); // Adjust as needed
  motor3.setAccelerationInStepsPerSecondPerSecond(500);
  motor3.setDecelerationInStepsPerSecondPerSecond(500); // Adjust as needed

  // Inicializando a conexão I2C com o MPU
  Wire.begin(21, 22);

  // Inicializa o MPU
  if (!mpu.begin()) {
    Serial.println("Falha ao inicializar o MPU-6050!");
    while (1) {
      delay(10);
    }
  }

  Serial.println("MPU-6050 inicializado com sucesso!");
}

void loop() {
  // Cria as variáveis para armazenar os dados
  sensors_event_t a, g, temp;
  
  // Lê os dados do MPU-6050
  mpu.getEvent(&a, &g, &temp);
  
  // Imprime os valores no monitor serial
  Serial.print("Acelerômetro X: ");
  Serial.print(a.acceleration.x);
  Serial.print(" m/s^2, Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(" m/s^2, Z: ");
  Serial.print(a.acceleration.z);
  Serial.println(" m/s^2");
  
  Serial.print("Giroscópio X: ");
  Serial.print(g.gyro.x);
  Serial.print(" rad/s, Y: ");
  Serial.print(g.gyro.y);
  Serial.print(" rad/s, Z: ");
  Serial.print(g.gyro.z);
  Serial.println(" rad/s");
  
  Serial.print("Temperatura: ");
  Serial.print(temp.temperature);
  Serial.println(" C");

  int sensorValue = analogRead(sensorPin);
  
  // Convertendo o valor analógico para uma porcentagem de umidade
  float moisturePercent = map(sensorValue, 0, 4095, 0, 100);
  
  // Imprimindo os valores no monitor serial
  Serial.print("Valor do sensor: ");
  Serial.print(sensorValue);
  Serial.print(" - Umidade do solo: ");
  Serial.print(moisturePercent);
  Serial.println("%");

  float h = dht.readHumidity();
  // Lê a temperatura em Celsius
  float t = dht.readTemperature();
  // Lê a temperatura em Fahrenheit
  float f = dht.readTemperature(true);
  
  // Verifica se houve alguma leitura falha e imprime uma mensagem de erro
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Falha na leitura do sensor DHT!"));
    return;
  }
  
  // Calcular o índice de calor em Fahrenheit
  float hif = dht.computeHeatIndex(f, h);
  // Calcular o índice de calor em Celsius
  float hic = dht.computeHeatIndex(t, h, false);
  
  Serial.print(F("Umidade: "));
  Serial.print(h);
  Serial.print(F("%  Temperatura: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Índice de Calor: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
  
  delay(1000);
  
  Serial.println("Moving motors");
  motor1.moveRelativeInSteps(200000);
  motor2.moveRelativeInSteps(200000);
  motor3.moveRelativeInSteps(200000);
}

