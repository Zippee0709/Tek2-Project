#!/usr/bin/python3
##
## EPITECH PROJECT, 2020
## 202unsold_2019
## File description:
## 202unsold
##

import sys, os
import time
import math

def printUsage():
    print("USAGE\n\
\t./204ducks a\n\n\
DESCRIPTION\n\
\ta\tconstant\n")

def error_gestion():
    if (len(sys.argv) == 2):
        try :
            nb = float(sys.argv[1])
        except ValueError:
            raise ValueError("Error : input must be a positive number")
    if (nb < 0 or nb > 2.5):
        raise ValueError("Error : The number must be between 0 to 2.5")
    return nb

def formula(a, t):
    return (a * math.exp(-t) + (4 - 3 * a) * math.exp(-2 * t) + (2 * a - 4) * math.exp(-4 * t))

def calcAverageReturnTime(a):
    probability = 0
    time = 0.001
    while(time < 100):
        probability += time * formula(a, time) / 1000
        time += 0.001
    print("Average return time: {}m {:02d}s".format(math.floor(probability * 60 // 60), math.floor(probability * 60 % 60) + 1))
    return (probability)

def calcStd(p, a, time):
    return (math.pow(time - p, 2) * (formula(a, time) / 10))

def calcGlobalStd(a, probability):
    time = 100
    std = 0
    while (time > 0.001):
        std += calcStd(probability, a, time)
        time -= 0.001
    std = math.sqrt(std / 100)
    print("Standard deviation: {:.3f}".format(std))

def duckBack(a, percentage):
    res = 0
    idx = 0.01

    while (1):
        res += formula(a, idx)
        if (res >= percentage):
            return (idx)
        idx += 0.01
    return (res)

def calcTimeAfterDucksBack(a):
    first = duckBack(a, 50) * 60
    second = duckBack(a, 99) * 60
    print("Time after which 50% of the ducks come back: {}m {:02d}s".format(math.floor(first // 60), math.floor(first % 60)))    
    print("Time after which 99% of the ducks come back: {}m {:02d}s".format(math.floor(second // 60), math.floor(second % 60)))    

def calcPercentageAfterNtime(a):
    a = 0
    b = 0
    print("Percentage of ducks back after 1 minute: {}m {}s".format(a, b))
    print("Percentage of ducks back after 2 minute: {}m {}s".format(a, b))

def start_ducks():
    a = error_gestion()
    probability = calcAverageReturnTime(a)
    calcGlobalStd(a, probability)
    calcTimeAfterDucksBack(a)
    calcPercentageAfterNtime(a)

def main():
    if (len(sys.argv) == 2 and sys.argv[1] == "-h"):
        printUsage()
    elif (len(sys.argv) == 2):
        start_ducks()
    else:
        raise ValueError("Error: please look -h for using 204ducks")

if __name__ == "__main__":
    try:
        main()
        sys.exit(0)
    except ValueError as ve:
        print(ve)
        sys.exit(84)
