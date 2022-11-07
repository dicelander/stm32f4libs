/**
 * isd1820.c
Copyright (C)David Simon Marques, 2022
Copyright (C)Victor Araujo Sander Silva, 2022

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
----------------------------------------------------------------------
 * Created on: November 4, 2022.
 * Last update: November 6, 2022.
 * Authors:  David Simon Marques <davidsimon@ufmg.br> and Victor Araujo Sander Silva <victorsander@gmail.com>
 * Institution: Universidade Federal de Minas Gerais (UFMG)
 * Version: 1.0.0
----------------------------------------------------------------------
This API was developed as part of the Embedded Systems Programming course at UFMG
	 - Prof. Ricardo de Oliveira Duarte – Department of Electronic Engineering
----------------------------------------------------------------------
ISD1820 recording module API
----------------------------------------------------------------------
This API contains functions to provide use of some hardware resources
from ISD 1820 recording module available at:
https://wiki.keyestudio.com/KS0463_keyestudio_ISD1820_Voice_Recording_and_Playback_Module

* API main files:
	- isd1820.c
	- isd1820.h
* Hardware requirements:
	- ISD 1820 recording module.
		Datasheet: https://www.nuvoton.com/resource-files/EN_ISD1800_Datasheet_Rev_1.0.pdf
	 	Default pinout:
			ISD1820    |STM32F446RE        |DESCRIPTION
		    -----------------------------------------------------
			VCC        |3.3V               |Power source
			GND        |GND                |Ground.
			FT         |FT (GPIO_Output)   |Feed Through: if HIGH, the microphone drives the speaker directly.
			P-L        |PL (GPIO_Output)   |PLAY-L: Playback level-activated. While HIGH, it plays the audio stored on EEPROM, until it is over.
			P-E        |PE (GPIO_Output)   |PLAY-E: Playback edge-activated. if HIGH, even for a short period, it plays the audio stored entirely
			REC        |REC (GPIO_Output)  |Recording pin. This pin must remain HIGH for the duration of the recording.
			SP+        |       None        |Speaker out.
			SP-        |       None        |Speaker out.

	- STM32F446RET6 64 PINS.
		Manufacturer website: https://www.st.com/en/microcontrollers-microprocessors/stm32f446re.html
* Software requirements:
	- STM32CubeIDE 1.6.1: Available at https://www.st.com/en/development-tools/stm32cubeide.html
----------------------------------------------------------------------
 */
#include "isd1820.h"
#include "main.h"

void ISD1820_StartRecording(void){
	HAL_GPIO_WritePin(REC_GPIO_Port, REC_Pin, 1);
}

void ISD1820_StopRecording(void){
	HAL_GPIO_WritePin(REC_GPIO_Port, REC_Pin, 0);
}

void ISD1820_StartPlaying(void){
	HAL_GPIO_WritePin(PL_GPIO_Port, PL_Pin, 1);
}

void ISD1820_StopPlaying(void){
	HAL_GPIO_WritePin(PL_GPIO_Port, PL_Pin, 0);
}

void ISD1820_Record(uint16_t rec_time){
	HAL_GPIO_WritePin(REC_GPIO_Port, REC_Pin, 1);
	HAL_Delay(rec_time);
	HAL_GPIO_WritePin(REC_GPIO_Port, REC_Pin, 0);
}

void ISD1820_PlayComplete(void){
	HAL_GPIO_WritePin(PE_GPIO_Port, PE_Pin, 1);
	HAL_Delay(100);
	HAL_GPIO_WritePin(PE_GPIO_Port, PE_Pin, 0);
}

void ISD1820_Play(uint16_t play_time){
	HAL_GPIO_WritePin(PL_GPIO_Port, PL_Pin, 1);
	HAL_Delay(play_time);
	HAL_GPIO_WritePin(PL_GPIO_Port, PL_Pin, 0);
}

void ISD1820_RecordAndPlay(uint16_t rec_time, uint16_t play_time){
	//Record:
	HAL_GPIO_WritePin(REC_GPIO_Port, REC_Pin, 1);
	HAL_Delay(rec_time);
	HAL_GPIO_WritePin(REC_GPIO_Port, REC_Pin, 0);
	HAL_Delay(100);
	//---
	//Play:
	HAL_GPIO_WritePin(PL_GPIO_Port, PL_Pin, 1);
	HAL_Delay(play_time);
	HAL_GPIO_WritePin(PL_GPIO_Port, PL_Pin, 0);
	//---
}
void ISD1820_EnableFeedThrough(void){
	HAL_GPIO_WritePin(FT_GPIO_Port, FT_Pin, 1);
}

void ISD1820_DisableFeedThrough(void){
	HAL_GPIO_WritePin(FT_GPIO_Port, FT_Pin, 0);
}
