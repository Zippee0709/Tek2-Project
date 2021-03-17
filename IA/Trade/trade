#!/usr/bin/python3
##
## EPITECH PROJECT, 2020
## 202unsold_2019
## File description:
## 202unsold
##
# node /home/Zhiwen/Delivery/Epitech2019/CNAT/CNA_trade_2019/cryptotrader-starterbot-javascript-master/main.js

import sys, os
import math
import statistics

class Trade:
    def __init__(self):
        self.playerNames = -1
        self.BotNames = -1
        self.timeBank = -1
        self.timePerMove = -1
        self.candleInterval = -1
        self.candleFormat = -1
        self.candlesTotals = -1
        self.candlesGiven = -1
        self.initialStack = -1
        self.transactionFeePercent = -1
        self.listBTC_ETH = list()
        self.listUSDT_ETH = list()
        self.listUSDT_BTC = list()
        self.stacks = dict()
        self.std = dict()
        self.mm = dict()
        self.trends = False
        self.sell = False
        self.lastBuyPrice = dict()
    
    def runBot(self):
        command = 0

        while (1):
            command = getInput()
            if self.parsingCommand(command) == 0:
                return 0

    def parsingCommand(self, command):
        parse = command.split()
        if (parse[0] == "settings"):
            self.parseSettings(parse)
            return 1
        elif (parse[0] == "update"):
            self.updateGameNextCandles(parse)
            return 1
        elif (parse[0] == "action"):
            self.updateAlgorithme()
            self.nextAction()
            return 1
        elif (command == "end"):
            return 0

    def calculateMeanMobile(self, myList, periode):
        if (len(myList) >= periode):
            lastPeriodeValues = myList[-periode:]
            total = 0
            for value in lastPeriodeValues:
                total += value["close"]
            meanMobile = total / periode
        return (meanMobile)

    def calculateStd(self, myList, periode):
        if (len(myList) >= periode):
            lastPeriodeValues = myList[-periode:]
            total = list()
            for value in lastPeriodeValues:
                total.append(value["close"])
            std = statistics.stdev(total)
        return (std)

    def sellByLastBuyPrice(self, currency, actualPrice, percentage):
        newPrice = self.lastBuyPrice[currency] * percentage / 100
        if (actualPrice - newPrice > self.lastBuyPrice[currency]):
            return True
        return False

    def completeOrder(self, currency, price, inferiore_bande, superiore_bande):
        if (price <= inferiore_bande and self.stacks[currency.split('_')[0]] > 0 and price <= 65):
            self.order = "buy " + currency + " " + str(self.stacks[currency.split('_')[0]] / price)
            self.stacks[currency.split('_')[0]] = 0
            self.lastBuyPrice[currency] = price
        elif (price >= superiore_bande and self.stacks[currency.split('_')[1]] > 0 and price >= 90):
            self.order = "sell " + currency + " " + str(self.stacks[currency.split('_')[1]])
            self.stacks[currency.split('_')[1]] = 0
        else:
            self.order = "pass"

    def calculateNewTrends(self, currency, myList, periode):
        tmpMM = self.calculateMeanMobile(myList, periode)
        tmpStd = self.calculateStd(myList, periode)
        superiore_bande = tmpMM + 2 * tmpStd
        inferiore_bande = tmpMM - 2 * tmpStd
        tmpActualValue = myList[-periode:]

        if (tmpActualValue[0]["close"] > tmpActualValue[periode - 1]["close"]):
            self.trends = False
        elif (tmpActualValue[0]["close"] < tmpActualValue[periode - 1]["close"]):
            self.trends = True
        tmpActualValue = myList[-1:]
        self.completeOrder(currency, tmpActualValue[0]["close"], inferiore_bande, superiore_bande)


    def updateAlgorithme(self):
        self.calculateNewTrends("BTC_ETH", self.listBTC_ETH, 20)
        self.calculateNewTrends("USDT_BTC", self.listUSDT_BTC, 20)
        self.calculateNewTrends("USDT_ETH", self.listUSDT_ETH, 20)


    def parseSettings(self, parse):
        if (parse[1] == "player_names"):
            self.playerNames = parse[2]
        elif (parse[1] == "your_bot"):
            self.BotNames = parse[2]
        elif (parse[1] == "timebank"):
            self.timeBank = int(parse[2])
        elif (parse[1] == "time_per_move"):
            self.timePerMove = int(parse[2])        
        if (parse[1] == "candle_interval"):
            self.candleInterval = int(parse[2])
        elif (parse[1] == "candle_format"):
            self.candleFormat = parse[2].split(',')
        elif (parse[1] == "candles_total"):
            self.candlesTotals = int(parse[2])
        elif (parse[1] == "candles_given"):
            self.candlesGiven = int(parse[2])
        elif (parse[1] == "initial_stack"):
            self.initialStack = int(parse[2])
        elif (parse[1] == "transaction_fee_percent"):
            self.transactionFeePercent = float(parse[2])
    
    def updateGameNextCandles(self, parse):
        if (parse[1] == "game" and parse[2] == "next_candles"):
            self.parseGameNextCandles(parse[3])
        if (parse[1] == "game" and parse[2] == "stacks"):
            self.parseGameStacks(parse[3])

    def parseGameStacks(self, str):
        tabAll = str.split(',')
        i = 0
        while (i < len(tabAll)):
            tmpInfo = tabAll[i].split(':')
            self.stacks[tmpInfo[0]] = float(tmpInfo[1])
            i += 1
        self.status = True
            
    def parseGameNextCandles(self, str):
        tabAll = str.split(';')
        i = 0        
        while (i < len(tabAll)):
            tmpDict = dict()
            tmpInfo = tabAll[i].split(',')
            for x in range (len(tmpInfo)):
                if (self.candleFormat[x] == "pair"):
                    tmpDict[self.candleFormat[x]] = tmpInfo[x]
                else:
                    tmpDict[self.candleFormat[x]] = float(tmpInfo[x])
            if (tmpInfo[0] == "BTC_ETH"):
                self.listBTC_ETH.append(tmpDict)
            if (tmpInfo[0] == "USDT_ETH"):
                self.listUSDT_ETH.append(tmpDict)
            if (tmpInfo[0] == "USDT_BTC"):
                self.listUSDT_BTC.append(tmpDict)
            i += 1

    def nextAction(self):
        print(self.order)

def getInput():
    try:
        info = input()
    except ValueError:
        sys.stderr.write("Error : Read Input\n")
        sys.exit(84)
    return info

def main():
    newTrade = Trade()
    newTrade.runBot()

if __name__ == "__main__":
    try:
        main()
        sys.exit(0)
    except ValueError as ve:
        print(ve)
        sys.exit(84)
