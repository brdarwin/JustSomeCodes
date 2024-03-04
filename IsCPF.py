import re
import sys

def hasCPF (text):
    cpfRegex = re.compile(r'\d{3}.\d{3}.\d{3}-\d{2}')
    try:
        CPF =  cpfRegex.findall(text)
        return print ("True: " + str(CPF))
    except AttributeError:
       return False
