cmake_minimum_required(VERSION 3.25)
project(Shared C)

set(CMAKE_C_STANDARD 11)

include_directories(AC_Control_Project)
include_directories(AC_Control_Project/APP)
include_directories(AC_Control_Project/HAL/lcd)
include_directories(AC_Control_Project/HAL/temp_sensor)
include_directories(AC_Control_Project/LIB)
include_directories(AC_Control_Project/MCAL/dio)
include_directories(AC_Control_Project/MCAL/timer)

add_executable(Shared
        AC_Control_Project/APP/app_interface.h
        AC_Control_Project/APP/app_program.c
        AC_Control_Project/HAL/lcd/lcd_config.h
        AC_Control_Project/HAL/lcd/lcd_interface.h
        AC_Control_Project/HAL/lcd/lcd_private.h
        AC_Control_Project/HAL/lcd/lcd_program.c
        AC_Control_Project/HAL/temp_sensor/temp_sensor.c
        AC_Control_Project/HAL/temp_sensor/temp_sensor.h
        AC_Control_Project/LIB/bit_math.h
        AC_Control_Project/LIB/std.h
        AC_Control_Project/MCAL/dio/dio_config.h
        AC_Control_Project/MCAL/dio/dio_interface.h
        AC_Control_Project/MCAL/dio/dio_private.h
        AC_Control_Project/MCAL/dio/dio_program.c
        AC_Control_Project/MCAL/timer/timer_config.h
        AC_Control_Project/MCAL/timer/timer_interface.h
        AC_Control_Project/MCAL/timer/timer_private.h
        AC_Control_Project/MCAL/timer/timer_program.c
        AC_Control_Project/main.c
        AC_Control_Project/main.h)
