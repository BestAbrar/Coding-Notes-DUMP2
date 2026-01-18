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

from typing import TextIO

from poetry_constants import (POETRY_FORMS_DICT, PRONUNCIATION_DICT)


# ===================== Add Your Helper Functions Here =====================

def strip_string(s: str) -> str:
    """Return a new string based on s in which punctuation characters have
    been stripped from both ends. Inner punctuation is left untouched.

    >>> transform_string('Birthday!!!')
    'BIRTHDAY'
    >>> transform_string('"Quoted?"')
    'QUOTED'
    >>> transform_string('To be? Or not to be?')
    'TO BE? OR NOT TO BE'
    """

    punctuation = """!"'`@$%^&_-+={}|\\/,;:.-?)([]<>#\n\t\r"""
    result = s.strip(punctuation)
    return result

def skip_copyright(text:list)->list[str]:
    """Return list without the initial copyright claim at the beginning of the
    pronunciation dictionary .txt file
    """
    
    lst = []
    for line in text:
        if line[0]!=';':
            lst.append(line)
    return lst
# ===================== Required Functions =================================

def read_pronunciation(pronunciation_file: TextIO) -> PRONUNCIATION_DICT:
    """Return the pronunciation dictionary formed from reading
    pronunciation_file, an open file that is in the format of the CMU
    Pronouncing Dictionary.

    >>> small_pd = open('datasets/pronunciation_dictionary_small.txt')
    >>> word_to_phonemes = read_pronunciation(small_pd)
    >>> small_pd.close()
    >>> word_to_phonemes == {'CAMPBELL': ('K', 'AE1', 'M', 'B', 'AH0', 'L'),
    ...                      'GRIES': ('G', 'R', 'AY1', 'Z'),
    ...                      'SMITH': ('S', 'M', 'IH1', 'TH')}
    True
    """
    text = skip_copyright(pronunciation_file.readlines())
    word_to_phonemes = {}
    for n in range(len(text)):
        text[n]=strip_string(text[n])
        word_to_phonemes[text[n].split()[0]]=tuple(text[n].split()[1:])
    return word_to_phonemes

def read_poetry_form_descriptions(poetry_forms_file: TextIO) \
        -> POETRY_FORMS_DICT:
    """Return a dictionary of poetry form name to poetry form description for
    the poetry forms in poetry_forms_file.

    >>> small_pf = open('datasets/poetry_forms_small.txt')
    >>> name_to_description = read_poetry_form_descriptions(small_pf)
    >>> small_pf.close()
    >>> name_to_description == {
    ...     'Haiku': ((5, 7, 5), ('*', '*', '*')),
    ...     'Limerick': ((8, 8, 5, 5, 8), ('A', 'A', 'B', 'B', 'A'))}
    True
    """
    syllables = []
    rhyme = []
    description = {}
    text = poetry_forms_file.readlines()
    for n in range(len(text)):
        text[n]=strip_string(text[n])
        if text[n]=='':
            description[text[m]]=tuple(syllables),tuple(rhyme)
            syllables.clear()
            rhyme.clear()
        elif text[n][0].isalpha():
            m=n
        elif text[n][0].isnumeric():
            syllables.append(int(text[n].split()[0]))
            rhyme.append(text[n].split()[1])
    description[text[m]]=tuple(syllables),tuple(rhyme)
    return description

if __name__ == '__main__':
    import doctest
    # Uncomment the line below if you prefer to test your examples with doctest
    # doctest.testmod()
