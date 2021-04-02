const int button = 2;
const int base1 = 3;                         // binary base first , decimal value 0 or 1
const int base2 = 4;                         // binary second digit decimal value 2 or not
const int base3 = 5;                         // binary third digit decimal value 4 or not
const int base4 = 6;                         // binary most significant bit  decimal value 8 or not
int delayTime = 500;                         // default delay time
volatile boolean currentButtonValue = false; // if you press button it change
volatile boolean lastButtonValue = false;    // As the button is pressed, arduino will constantly read the value of 1,
                                             //so it will enter the condition within the 'void' continuously. Therefore,
                                             //the condition control was made according to the situation when the button
                                             // was pressed and pulled compared with the last value.
boolean changeFunction = false;              // function change boolean

int counter = 0; //counter for controlling ledArray and counter 15

void setup()
{
    // general settings
    Serial.begin(9600);
    pinMode(base1, OUTPUT); //for led
    pinMode(base2, OUTPUT);
    pinMode(base3, OUTPUT);
    pinMode(base4, OUTPUT);
    pinMode(button, INPUT); // for button
}

void loop()
{
    currentButtonValue = digitalRead(button);  //read button value
    if (lastButtonValue != currentButtonValue) // checking last value . Press the button to make a single change.
    {
        if (currentButtonValue == HIGH) // Pressing button
        {
            changeFunction = !changeFunction; // changing function control boolean
            counter = 0;                      // if you change function counter reset
            delay(50);                        //for safity
        }
    }

    // function change control
    if (changeFunction)
    {
        delayTime = 200; // 200 + 50 = 250 mili second
        experiment2();
    }
    else
    {
        delayTime = 450; // 450+50 = 500 milisecond
        experiment1();
    }
    counter++;
    delay(delayTime);
    lastButtonValue = currentButtonValue; // last button value saving
}

void experiment1()
{
    if (counter > 7) // if counter > 7 MS bit is opern
    {
        digitalWrite(base4, HIGH);
    }
    else
    {
        digitalWrite(base4, LOW);
    }
    if ((counter > 3 && counter < 8) || (counter > 11 && counter < 16)) // third led control
    {
        digitalWrite(base3, HIGH);
    }
    else
    {
        digitalWrite(base3, LOW);
    }
    if ((counter % 4 == 2) || (counter % 4 == 3)) // second led control
    {
        digitalWrite(base2, HIGH);
    }
    else
    {
        digitalWrite(base2, LOW);
    }
    if (counter % 2 == 1) // least significant bit
    {
        digitalWrite(base1, HIGH);
    }
    else
    {
        digitalWrite(base1, LOW);
    }
    if (counter == 16) // counter = 16 reset counter and all led off
    {
        counter = 0;
        digitalWrite(base4, LOW);
        digitalWrite(base3, LOW);
        digitalWrite(base2, LOW);
        digitalWrite(base1, LOW);
    }
}

void experiment2()
{
    int led[8] = {6, 5, 4, 3, 4, 5, 6}; // Output pin numbers of leds required for iteration respectively
    digitalWrite(led[counter], HIGH);   // open led
    if (counter % 6 == 0)               // Setting the counter so that the array wraps over its indexes
    {
        digitalWrite(led[counter - 1], LOW); // closing the last led
        counter = 0;
    }
    if (counter > 0)
    {
        digitalWrite(led[counter - 1], LOW); // closing the before  led
    }
}
