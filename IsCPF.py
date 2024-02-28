def auxRange (text,n, n1):
    for i in range (n,n1):
        if text[i].isdigit() == False:
            return False
    return True

def IsCPF (text):
    if len(text) != 14:
        return False

    if text[3] != '.' or text[7] != '.' or text[11] != '-':
        return False
    test = auxRange (text,0, 3)
    if test == True:
        test = auxRange (text,4, 7)
    if test == True:
        test = auxRange (text,8, 11)
    if test == True:
        test = auxRange (text,12, 14)
    return test

