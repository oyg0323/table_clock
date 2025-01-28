# Arduino Temperature and Humidity Monitoring Clock

This project integrates multiple Arduino modules and sensors to create a real-time clock with temperature and humidity monitoring. The system displays the current date, time, temperature, and humidity on an LCD screen.

## Features

### Real-Time Clock with Temperature and Humidity Monitoring
- **Components Used:**
  - **DS1302 RTC Module:** Tracks real-time date and time.
  - **DHT11 Sensor:** Measures temperature and humidity.
  - **LiquidCrystal_I2C LCD:** Displays time, date, temperature, and humidity.
- **How It Works:**
  - The system reads the date and time from the RTC module.
  - Temperature and humidity are measured using the DHT11 sensor.
  - All data is displayed on the LCD.

## Hardware Components

1. **Microcontroller:** Arduino board.
2. **Sensors:**
   - DHT11 (Temperature and Humidity)
   - DS1302 (Real-Time Clock)
3. **Modules:**
   - LiquidCrystal_I2C (LCD Display)

## Software Setup

### Libraries Required
- `Wire.h`
- `LiquidCrystal_I2C.h`
- `DS1302.h`
- `DHT11.h`

### Code File
- **`temp_clock.ino`:** Implements the RTC-based clock and environmental monitoring system.

## Usage Instructions

1. Assemble the hardware as per the pin configurations in the `temp_clock.ino` file.
2. Install the required libraries in the Arduino IDE.
3. Upload the `temp_clock.ino` file to the Arduino board.
4. Power on the system and monitor the LCD for real-time date, time, temperature, and humidity readings.

## Future Enhancements

- Add wireless communication (e.g., Bluetooth or Wi-Fi) for remote monitoring.

## License

This project is open-source and available under the [MIT License](LICENSE).

---

For detailed implementation, refer to the `temp_clock.ino` file provided with this project.
