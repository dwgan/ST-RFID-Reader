# ST-RFID-Reader

It's a basic demo that read ID type and ID number from RFID tag, then output to UART

requirement materials: NUCLEO-G071RB, X-NUCLEO-NFC06A1

Software: STM32CubeIDE 1.7.0 or IAR Embedded Workbench for ARM 9.40.1, STM32CubeMx  6.3.0

Firmware Package: STM32Cube FW_G0 V1.5.1



## How to use

This repository contain to branch including ST-RFID-Reader project for NUCLEO-G071RB (**main**) and STKNX-development-board (STM32G070CBxx) (**master**).

To change to another branch:

```sh
git checkout [target branch name]
```



## Variant for Charge Station

This version is not a full version, which is modified to support RFID detection for charge station. 

This version only support the type of the card of NFCA and NFCV.

It's recommended to use IAR compiler rather than STM32CubeIDE due to some unknown problem.
