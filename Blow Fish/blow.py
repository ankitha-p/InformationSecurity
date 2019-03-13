import blowfish
from os import urandom

data = urandom(10 * 8) # data to encrypt

data_encrypted = b"".join(cipher.encrypt_ecb(data))
data_decrypted = b"".join(cipher.decrypt_ecb(data_encrypted))
print("Encrypted data is")
print(data_encrypted)
print("Decrypted data is")
print(data_decrypted)
                          

#assert data == data_decrypted
