#pip install SymPy
from sympy.crypto.crypto import encipher_hill, decipher_hill
from sympy import Matrix

def getMatrix(msg):
    matrix=[[0 for x in range(3)] for y in range(3)]
    k=0
    for i in range(3):
        for j in range(3):
            matrix[i][j] = ord(msg[k])%65
            k+=1
    return matrix

message=input("Enter text: ")
key = Matrix(getMatrix("GYBNQKURP"))
cipher = encipher_hill(message, key)
print("Ciphered: ", cipher)
print("Deciphered:", decipher_hill(cipher, key))
