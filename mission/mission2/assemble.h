#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "car.h"
#include "car_type.h"
#include "car_engine.h"
#include "car_breakSystem.h"
#include "car_steeringSytem.h"
#include "car_runtest.h"


#define CLEAR_SCREEN "\033[H\033[2J"

void delay(int ms);
void forword_next_assemble_step(car& new_car);
void getUserInput(char  buf[100]);
void registAssemblePart(car& new_car);
int isExit(char  buf[100]);
int processAssembleLine(char  buf[100], car& new_car);
int checkUserWantFirstStage(int answer, car& new_car);
int checkValidRange(char* checkNumber, car& new_car, int answer);
void startAssembleAccordingToAseembleStep(car& new_car, int answer);