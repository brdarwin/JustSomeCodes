import re

def hasCPF (text):
    cpfRegex = re.compile(r'\d{3}.\d{3}.\d{3}-\d{2}')
    try:
        CPF =  cpfRegex.search(text)
        print ("True: " + CPF.group())
    except AttributeError:
       return False


