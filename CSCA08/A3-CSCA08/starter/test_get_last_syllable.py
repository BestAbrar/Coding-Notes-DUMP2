"""CSCA08H1: Assignment 3: Poetry Form Checker

Instructions (READ THIS FIRST!)
===============================

Make sure that the code files:
    poetry_functions.py, poetry_program.py, poetry_reader.py,
    test_get_last_syllable.py,
    a3_checker.py, a3_pyta.json and checker_generic.py,
the folder dataset that includes files:
    pronunication_dictionary.txt, pronunication_dictionary_small.txt,
    poetry_forms.txt and poetry_forms_small.txt, and
the folder sample_poems that includes files:
    haiku1.txt, haiku2.txt, etc.
are in the same folder as this file (poetry_constants.py).

Copyright and Usage Information
===============================

This code is provided solely for the personal and private use of students
taking the course CSC108/CSCA08 at the University of Toronto. Copying for
purposes other than this use is expressly prohibited. All forms of distribution
of this code, whether as given or with any changes, are expressly prohibited.

All of the files in this folder are:
Copyright (c) 2022 the University of Toronto CSC108/CSCA08 Teaching Team.
"""

import unittest
import poetry_functions


class TestGetLastSyllable(unittest.TestCase):

    def test_get_last_syllable_empty(self):
        """Test get_last_syllable on an empty tuple."""

        actual = poetry_functions.get_last_syllable(())
        expected = ()
        self.assertEqual(actual, expected, 'empty tuple')

    # Place your unittest method definitions after this line.
    def test_get_last_syllable_no_syllable(self):
        """Test get_last_syllable on a non-empty tuple with no phoneme"""
        actual = poetry_functions.get_last_syllable(('B'))
        expected = ()
        self.assertEqual(actual, expected, 'no syllables')
        
    def test_get_last_syllable_single_syllable(self):
        """Test get_last_syllable on a tuple with single phoneme"""
        actual = poetry_functions.get_last_syllable(('AE1', 'B'))
        expected = ('AE1', 'B')
        self.assertEqual(actual, expected, 'single syllable')

    def test_get_last_syllable_single_syllable(self):
        """Test get_last_syllable on a tuple with multiple phoneme"""
        actual = poetry_functions.get_last_syllable(('AA1', 'R', 'D', 'V',\
                                                     'AA2', 'R', 'K'))
        expected = ('AA2', 'R', 'K')
        self.assertEqual(actual, expected, 'multiple syllables')
    

# Place your unittest method definitions before this line.
if __name__ == '__main__':
    unittest.main(exit=False)
