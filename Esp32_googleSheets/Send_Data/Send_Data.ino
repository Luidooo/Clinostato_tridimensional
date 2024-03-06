#include <WiFi.h>
#include <ESP_Google_Sheet_Client.h>

#define WIFI_SSID "Luis Eduardo's iPhone"
#define WIFI_PASSWORD "999618010"

#define PROJECT_ID "esp32-416412"
#define CLIENT_EMAIL "esp32-242@esp32-416412.iam.gserviceaccount.com"

const char PRIVATE_KEY[] PROGMEM = "-----BEGIN PRIVATE KEY-----\nMIIEvgIBADANBgkqhkiG9w0BAQEFAASCBKgwggSkAgEAAoIBAQC3Mn50prPIAQcK\n011fKd2Es+KxPBg/6dKlmWs/qfosqleAZ1b3QK1LtRk41NMHMqJ/qC0z6RtKRGgS\nV/CneS8nSmEnjzrMr1/+qH5u6SX2W/lMBXDycLBzrHCwuL3H84e1RuyVWv58NKkr\nCQpdSCYmL7xcppqS1WReAfqSlr4wIROIpjIlhKlBtjjIK15IDCSiKqaWK8zoS99X\n3I5PLRDKSCT1aVkCw+nnF6Ydw2Rb/z+DMVEIPEFBDfDkncr+upnxdj1Rq969nMLL\nvZVL+qVuQdYxwKUOdH7Wvl/PhsLrw65/l4X4NgPpk3RffxX6kqIGb/9rImcQUos9\nuRufdNg9AgMBAAECggEALgPnYoqa3tJvP+debTBZXWNHvifvmWI0kHbsSvX5im2R\nBAYxAHME9F69QpqmlQjBa1pFXGQhgDKVh4ICRza3wuE6bRLbfJ1Seec9tsMmT27D\nvDYjrCnlEHEQbztAJDDF9iEl/M/52x3pHg+rxEmCl5Xm9Mi+S8KA7uIFW/u0Muc2\neYIYJOknkDG2XfbicEYLBDHIZIWjvgxw86AibNSWdIb6x5Wx0gMLFE3K54jg0ceG\nXbeED1D1BH4HAn4Hw424dz0Cla0sfSF9smiZ93w26q6d9hiqZ+Bi3XuxLMqulqMw\npTkpS4+m92gIs4LZ6j/PtiFLhuaRs8y0JPVJVRrHiwKBgQDzE0JArSk0IsWjCzE4\nBW0xvjhhp5V6B0UlJn8CfPA8i2h1iLCfaFpTHDthCsaNzUiKsjRqzS6mSzDqmz+N\ncCdPtUH3VxdhXOsuqNxzmbzYE6ySmMck4rJrjKT9X2SN5x7BJZd02IzWQJ9Hw1zY\nR3BHhfmiFUO+isC703uQedq4/wKBgQDA8Cz7aktKzMr1DtgB/eg6/a/m8yyjzEkb\nzuRyQ1PVPzOMpJUvBWaUEsO1+vTO3WYL6I7UaU2INsRARxDeOa4noEcvyLXYU1fT\ngooZlbeePA4YtBAwr9b3BtiYQwVoXy4uBArt5W3nU+MuwVr1UGMGWJqa0qEyiPgR\nzzGSeygSwwKBgCs2mkmrPy8Am4gv3jEqbc4xFg7uXxmRn05KeLv1gDQTSJ/UjCna\nwGwUEc5fvwrImwPlSIJQNeHkbi7XKMY5URPPkompVwO9JCZoaMC4bSUw4jYxqP26\nu6N5Hn/Y7KR5mTMXPsTMFsWkOWzlo2Tj1mcwvz98bk26lycNIuN9dk/7AoGBAJrw\nBN99k6sk3JOA8RxgX18IHHs1qxJ62fb35WKRCMCF+YqnHJpfFuowS3RXbMK27tz/\nS7vuOHH7sQwBRd1/qoht4NzRrJ5lB3F2MhqrrYHnrlZOO3Ytr04+9C8KG0yeqsIP\nQwuaI/ER363LXpUDkhIlkzpjjUm8zqHWpnOAbUTrAoGBAMq3wF/6dz7txKo2Hlj9\nDdiINPYxIgWbBlJ7XOQJQN5EB91ecXkjGxZdZs8s0NfMy9GHfjfHFxAYHHHKivgK\nknjCsNPsjx45U2cbDdKNLD2+PKeeRG/4cbjDw4kujX0TOHHgPpJkGNIJGl7PjFYg\n4qDdlVrGnwEnQkjSWz+HXt3K\n-----END PRIVATE KEY-----\n";

const char SPREADSHEET_ID[] PROGMEM = "1nf92L44JtpoKj4GnRspyor4o4JrWag3kG-KhAKvOk2U";
//https://docs.google.com/spreadsheets/d/1nf92L44JtpoKj4GnRspyor4o4JrWag3kG-KhAKvOk2U/edit#gid=0

void tokenStatusCallback(TokenInfo info);

void setup(void){
    Serial.begin(115200);
    delay(1000);
    Serial.println();

    //Serial.println("Esp Google Sheet Client v%s\n\n", ESP_GOOGLE_SHEET_CLIENT_VERSION);

    WiFi.setAutoReconnect(true);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to WiFi");
    while(WiFi.status() != WL_CONNECTED){
        Serial.print(".");
        delay(300);
    }

    Serial.println();
    Serial.print("Conectando com o ip: ");
    Serial.println(WiFi.localIP());
    Serial.println();

    GSheet.setTokenCallback(tokenStatusCallback);
    GSheet.begin(CLIENT_EMAIL, PROJECT_ID, PRIVATE_KEY);
}

void loop(void){

    static unsigned long ms;
    static unsigned long interval = 25000;
    bool ready = GSheet.ready();

    FirebaseJson response;
    Serial.println("\nAppend spreedsheet values");

    FirebaseJson valueRange;

    valueRange.add("majorDimension", "COLUMNS");
    uint8_t aux = random(20, 28);
    valueRange.set("values/[0]/[0]", aux);
    aux = random(35, 96);
    valueRange.set("values/[1]/[0]", aux);

    //bool sucess = GSheet.values.append(&response , SPREADSHEET_ID, "Log1!A7");
    //response.toString(Serial, true);
    Serial.println();


    Serial.println("\n Get Spreedsheet values from range...");

    //sucess = GSheet.values.get(&response, SPREADSHEET_ID, "Log1!B3");
    //response.toString(Serial, true);

    //FirebaseJson result;

    /*
    response.get(result, "Values/[0]/[0]");
    if(result.sucess){
        interval = result.to<String>().toInt() * 1000;
        Serial.printf("\nWarning %idms to next event!", interval);
    }else Serial.println("Read failure:(");
    Serial.println("----------------------------------------------");
    */
}
