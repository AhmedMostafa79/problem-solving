from Crypto.Cipher import DES
from tkinter import messagebox
def is_hexadecimal(s):
    try:
        bytes.fromhex(s)
        return True
    except ValueError:
        return False

class DES_Cipher:
    def __init__(self, key_hex):
        if not is_hexadecimal(key_hex) or len(key_hex) != 16:
            raise ValueError("Key must be a 16-character hexadecimal string")

        self.key = bytes.fromhex(key_hex)

    def encrypt(self, plaintext_hex):
        if not is_hexadecimal(plaintext_hex) or len(plaintext_hex)!=16:
            raise ValueError("Plaintext must be a 16-character hexadecimal string")

        des = DES.new(self.key, DES.MODE_ECB)
        plaintext_bytes = bytes.fromhex(plaintext_hex)
        return des.encrypt(plaintext_bytes).hex().upper()

    def decrypt(self, ciphertext_hex):
        if not is_hexadecimal(ciphertext_hex) or len (ciphertext_hex)!=16:
            raise ValueError("Ciphertext must be a 16-character hexadecimal string")

        des = DES.new(self.key, DES.MODE_ECB)
        ciphertext_bytes = bytes.fromhex(ciphertext_hex)
        return des.decrypt(ciphertext_bytes).hex().upper()

