#!/usr/bin/python3

import unittest
import ducks

class TestErrorGestion(unittest.TestCase):
    def test_error_gestion(self):
        self.assertAlmostEqual(ducks.calcAverageReturnTime(1.6), '1.349')
        self.assertAlmostEqual(ducks.calcAverageReturnTime(0.2), '0.824')

