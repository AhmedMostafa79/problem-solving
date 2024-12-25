from tkinter import messagebox
class PlayfairCipher:
    def __init__(self, key):
        if not key.isalpha():
            raise ValueError("Error","Key must consist of alphabet only")
        self.key = key
        self.ar = PlayfairCipher.generateMatrix(key)

    def generateMatrix(key):
        key=key.upper()
        ar = [[0 for i in range(5)] for j in range(5)]
        isin = [0] * 26
        for i in key:
            isin[ord(i) - ord('A')] = 1
        c = 0
        x = 0
        for i in range(5):
            for j in range(5):
                if c < len(key):
                    ar[i][j] = key[c]
                    c += 1
                else:
                    while isin[x] or chr(ord('A') + x) == 'J':
                        x += 1
                    ar[i][j] = chr(x + ord('A'))
                    x += 1
        return ar
    
    def Find(f, ar):
            r, c = -1, -1
            for i in range(5):
                for j in range(5):
                    if ar[i][j] == f:
                        r, c = i, j
            if f == 'J' and i == -1 and j == -1:
                return 2, 3
            else:
                return r, c

    def encrypt(self, text,enc=True):
        ar = self.ar  # Accessing the matrix generated in __init__
        if not text.isalpha() :
            raise ValueError("Error, message must consist of alphabet only")
        if len(text) % 2 == 1:
            text += 'X'
        text = text.upper()
        cipher = ""
        for i in range(0, len(text), 2):
            r1, c1 = PlayfairCipher.Find(text[i], ar)
            r2, c2 = PlayfairCipher.Find(text[i + 1], ar)
            if r1 == r2:
                cipher += ar[r1][(c1 + (1 if enc else -1)) % 5]
                cipher += ar[r2][(c2 + enc) % 5]
            elif c1 == c2:
                cipher += ar[(r1 + enc+5) % 5][c1]
                cipher += ar[(r2 + enc+5) % 5][c2]
            else:
                cipher += ar[r1][c2]
                cipher += ar[r2][c1]
        return cipher

    def Decrypt(self, cipher):
        return self.encrypt(cipher,False)
