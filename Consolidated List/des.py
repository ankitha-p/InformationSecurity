from pyDes import *
data = input("Please enter text to be encoded: ").encode('ascii')
k = des("\0\0\0\0\0\0\0\0", CBC, "\0\0\0\0\0\0\0\0", padmode=PAD_PKCS5)
e = k.encrypt(data)
d = k.decrypt(e)
print("Encrypted text: ", e.decode("windows-1252"))
if d != data:
    print ("Error: decrypt does not match. %r != %r" % (data, e))
else:
    print ("Decrypted text: ", d.decode("UTF-8"))
