import unittest
import sys
from IQ205 import densityFunction
from IQ205 import twoArgumentFunction
from IQ205 import threeArgumentFunction
from IQ205 import fourArgumentFunction

class ProjecTest(unittest.TestCase):
    def testTwoArgumentFunction(self):
        self.assertEqual(0.000000, float("{:.5f}".format(densityFunction(100, 15, 0))))
        self.assertEqual(0.021300, float("{:.5f}".format(densityFunction(100, 15, 90))))
        self.assertEqual(0.010930, float("{:.5f}".format(densityFunction(100, 15, 120))))
        self.assertEqual(0.000100, float("{:.5f}".format(densityFunction(100, 15, 150))))
        self.assertEqual(0.000000, float("{:.5f}".format(densityFunction(100, 15, 200))))

    def testThreeArgumentFunction(self):
        self.assertEqual(33.8, threeArgumentFunction(100, 24, 90))

    def testFourArgumentFunction(self):
        self.assertEqual(7.9, fourArgumentFunction(100, 24, 90, 95))

if __name__ == '__main__':
    unittest.main()
