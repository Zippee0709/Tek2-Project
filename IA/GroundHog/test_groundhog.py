import unittest
import sys
from groundhog import get_input_value
from groundhog import calc_golbal_average
from groundhog import calc_mean_of_n_day
from groundhog import calc_standard_deviation
from groundhog import calc_relative_temperature_evolution
from groundhog import calculate_last_rte
from groundhog import check_occurs


testList1 = [1, 11, 21, 31]
testList2 = [27.4, 28.3, 26.5, 25.4, 24.8, 26.3, 27.8]
class ProjectTest(unittest.TestCase):
    def testGetInput(self):
        self.assertEqual(10.0, get_input_value(10))

    def testGlobalAverage(self):
        self.assertEqual(10.0, calc_golbal_average(testList1, 3))
        self.assertEqual(0.5571428571428575, calc_golbal_average(testList2, 7))

    def testNday(self):
        self.assertEqual(21.0, calc_mean_of_n_day(testList1, 3))
        self.assertEqual(26.642857142857146, calc_mean_of_n_day(testList2, 7))

    def testStandardDeviation(self):
        self.assertEqual(8.164965809277259, calc_standard_deviation(testList1, 3))
        self.assertEqual(1.1794152823171595, calc_standard_deviation(testList2, 7))

    def testRelativeTempEvolution(self):
        self.assertEqual(2000.0, calc_relative_temperature_evolution(testList1, 3, 21))
        self.assertEqual(7.553956834532366, calc_relative_temperature_evolution(testList2, 7, 29.9))

    def testLastRte(self):
        self.assertEqual(0.0, calculate_last_rte(testList1, 3))
        self.assertEqual(0.0, calculate_last_rte(testList2, 7))

    def testCheckOccurs(self):
        self.assertEqual(False, check_occurs(testList1, calc_relative_temperature_evolution(testList1, 3, 21), 3))
        self.assertEqual(False, check_occurs(testList2, calc_relative_temperature_evolution(testList2, 3, 21), 3))

if __name__ == '__main__':
    unittest.main()
