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
\t./204IQ u s [IQ1] [IQ2]\n\n\
DESCRIPTION\n\
\tu\tmean\n\
\ts\tstandard deviation\n\
\tIQ1\tmaximun IQ\n\
\tIQ2\tminimum IQ")

def densityFunction(mean, standardDeviation, x):
    if (standardDeviation == 0):
        raise ZeroDivisionError("Error, the standard Deviation can't be 0")
    res = 1 / (standardDeviation * math.sqrt(2 * math.pi)) * math.exp((-1/2) * pow((x - mean)/standardDeviation, 2))
    return res

def twoArgumentFunction(mean, standardDeviation):
    total = 0   
    for i in range (0, 201):
        res = densityFunction(mean, standardDeviation, i)
        total += res
        print("{} {:.5f}".format(i, res))

def threeArgumentFunction(mean, standardDeviation, IQMin):
    total = 0
    step = 1
    for x in range(0, int(IQMin), step):
        fx = densityFunction(mean, standardDeviation, x)
        fxPlusOne = densityFunction(mean, standardDeviation, x + step)
        total += ((fx + fxPlusOne) * step) / 2  # Méthodes des trapèzes : (coté * (f(x) + f(x + 1))/ 2)
    total *= 100
    print("{}% of people have an IQ inferior to {}".format(round(total, 1), int(IQMin)))
    return (round(total, 1))

def fourArgumentFunction(mean, standardDeviation, IQMin, IQMax):
    total = 0
    step = 1
    for x in range(int(IQMin), int(IQMax), step):
        fx = densityFunction(mean, standardDeviation, x)
        fxPlusOne = densityFunction(mean, standardDeviation, x + step)
        total += ((fx + fxPlusOne) * step) / 2
    total *= 100
    print("{}% of people have an IQ between {} and {}".format(round(total, 1), int(IQMin), int(IQMax)))
    return (round(total, 1))

def error_gestion(nbrArgument):
    try:
        mean = float(sys.argv[1])
        standardDeviation = float(sys.argv[2])
    except Exception:
        raise ValueError("Error: The IQ must be a int or float value")
    if (mean < 0 or mean > 200):
        raise ValueError("Error: The mean must between 0 and 200")
    if (standardDeviation <= 0):
        raise ValueError("Error: The mean standard deviation must be positive") 
    if (nbrArgument == 4):
        try :
            IQ = float(sys.argv[3])
            if (IQ < 0 or IQ > 200):
                raise ValueError("Error: The IQ must between 0 and 200")
        except ValueError:
            print("Error: The IQ must be a int or float value")
            sys.exit(84)
    if (nbrArgument == 5):
        try :
            IQmin = float(sys.argv[3])
            IQmax = float(sys.argv[4])
            if (IQmin < 0 or IQmin > 200):
                raise ValueError("Error: The IQ must between 0 and 200")
            elif (IQmax < 0 or IQmax > 200):
                raise ValueError("Error: The IQ must between 0 and 200")
            elif (IQmax < IQmin):
                raise ValueError("Error: The IQmax must be superior to IQmin")
        except ValueError:
            print("Error: The IQ must be a int or float value")
            sys.exit(84)

def startIq():
    nbrArgument = len(sys.argv)
    error_gestion(nbrArgument)
    try:
        mean = float(sys.argv[1])
        standardDeviation = float(sys.argv[2])
        if (nbrArgument == 4):
            IQMin = float(sys.argv[3])
            threeArgumentFunction(mean, standardDeviation, IQMin)
        elif (nbrArgument == 5):
            IQMin = float(sys.argv[3])
            IQMax = float(sys.argv[4])
            fourArgumentFunction(mean, standardDeviation, IQMin, IQMax)
        else:
            twoArgumentFunction(mean, standardDeviation)
    except ValueError:
        print("Error: Argument need to be a number")
        sys.exit(84)

def main():
    if (len(sys.argv) == 2 and sys.argv[1] == "-h"):
        printUsage()
    elif (len(sys.argv) >= 3 and len(sys.argv) <= 5):
        startIq()
    else:
        raise ValueError("Error: please look -h for using 205IQ")

if __name__ == "__main__":
    try:
        main()
        sys.exit(0)
    except (ValueError, ZeroDivisionError) as ve:
        print(ve)
        sys.exit(84)