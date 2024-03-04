import re
import sys

def hasCPF (text):
    cpfRegex = re.compile(r'\d{3}.\d{3}.\d{3}-\d{2}')
    CPF =  cpfRegex.findall(text)
    if CPF == []:
        return False
    return print ("True: " + str(CPF))

