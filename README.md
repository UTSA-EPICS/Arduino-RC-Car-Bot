# 🚗 Arduino RC Car Project  

## Overview  
Welcome to the **EPICS Sumo-Bot Competition** repository!  
This branch is for participants who want to control their RC cars using an **Android device via Bluetooth**.

## ⚙️ Setup Instructions  
1. Pair your Bluetooth modules (HC-05).  
2. Upload the Arduino code:  
   `SumoBAndroid-Bluetooth-Arduino-Carot_BT_CAR_Code`  
3. Connect the **Slave HC-05** module to the **Car Arduino**.  
4. Connect the **Master HC-05** module to the **Remote Arduino**.  

## 🧰 Components Required  
- HC-05 Bluetooth Module ×1  
- Arduino Uno ×1  
- Arduino Motor Shield ×1  
- Android Device or Emulator  
- EPICS Sumo-Bot Kit  
- Batteries (LiPo 18650 recommended) ×2  

---

## 🔵 Bluetooth Configuration  

1. Plug your HC-05 into an Arduino running a blank sketch.  
2. While connecting, **press and hold** the small button on the HC-05 module.  
   - After a few seconds, the LED should blink **slowly**, indicating **Command Mode**.  
3. Open the **Serial Monitor** in the Arduino IDE:  
   - Set the **baud rate** to `38400`  
   - Set line ending to **Both NL & CR**  
4. Type `AT` and hit Enter. You should see a response: `OK`.  
5. Type `AT+ROLE?` to check its role:  
   - `0` = Slave  
   - `1` = Master  
6. If the module is set to Master (`1`), change it to Slave:`AT+ROLE=0`
- This sets the module to **Slave** mode — it will go on the **car**.
7. Once in Slave mode, pair it with your Android phone:  
- Power it on and go to your phone’s **Bluetooth settings**.  
- Pair it like a regular Bluetooth device (usually named `HC-05`).  
8. Install the Android APK on your phone.  
- **IMPORTANT**: Grant the app permission to access **Nearby Devices**.  
  You might need to go to `App Info` > `Permissions` to enable it manually.
9. Open the app. Tap on the top menu where it says `Select Bluetooth`, then select `HC-05`.

---

## 🖼️ Reference Images  

### Car Image: 
<img src="Readme%20Files/Arduino-Car.jpg" alt="Car Setup" width="300"/>

### Android App Interface:   
<img src="Readme%20Files/App_Screenshot.png" alt="App Interface:" width="300"/>


