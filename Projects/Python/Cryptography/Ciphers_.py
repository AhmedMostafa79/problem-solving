from tkinter import messagebox
class Ciphers:
   
    @staticmethod
    def Caeser(k, text,enc):
        try:
            k=int(k)
        except ValueError as e:
             raise ValueError("Error","Key must be Integer number")
             return 
        if not text.isalpha():
            raise ValueError("Error,Text must be of only alphabets")
        cipher = ""
        text = text.upper()
        for i in text:
            cap = 32 * (i < 'a')
            c = int(ord(i) - ord('A'))
            c = (c + (k if enc else -k)) % 26 + ord('A')
            cipher += chr(c)
        return cipher
    @staticmethod
    def MAlpha(k, text):
        if(len(k)!=26):
           raise ValueError("Error","Enter 26 Size Key")
        text = text.upper()
        cipher = ""
        for i in range(len(text)):
            c = ord(text[i]) - ord('A')
            cipher += k[c]
        return cipher

    @staticmethod
    def D_MAlpha(k, cipher):
        if(len(k)!=26):
              raise ValueError("Error","Enter 26 Size Key")
        text = ""
        alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\n"
        cipher = cipher.upper()
        for i in (cipher):
            c = k.index(i)
            text += alph[c]
        return text

    # @staticmethod
    def Vigener(k, text,enc):
        if( not k.isalpha() or not text.isalpha()):
            raise ValueError("Error, Key and message must be alphabets only")
       
        k, text = k.upper(), text.upper()
        k2 = k
        while len(k) < len(text):
            k += k2  # repeat key mode
        cipher = ""
        for i in range(len(text)):
            cipher += str(Ciphers.Caeser(ord(k[i]) - ord('A'), text[i],enc))
        return cipher
    @staticmethod
    def PAlpha(k, text,enc):#auto key mode
        k, text = k.upper(), text.upper()
        k2 = text
        while len(k) < len(text):
            k += k2
        print(k)
        return Ciphers.Vigener(k,text,enc)
    
    @staticmethod
    def RailFence(k, text):
        if not k.isdigit():
           raise ValueError("Error,Key must be a number")
        k=int(k)
        if k>len(text) or k<2:
            raise ValueError("Error,Key should be smaller or equal to length of cipher and greater than 1")
        text = text.upper()
        fence = [[] for _ in range(k)]
        row, direction = 0, 1

        for char in text:
            fence[row].append(char)
            row += direction
            if row == k - 1 or row == 0:
                direction *= -1
        return ''.join([''.join(row) for row in fence])

    @staticmethod
    def D_RailFence(k, cipher):
        if not k.isdigit():
           raise ValueError("Error,Key must be a number")
        k=int(k)
        if k>len(cipher) or k<2:
            raise ValueError("Error,Key should be smaller or equal to length of cipher and greater than 1")
        cipher=cipher.upper()
        cycle_length = 2 * (k - 1)
        cycle_count = len(cipher) // cycle_length + 1
        full_cycles = [cipher[i * cycle_length:(i + 1) * cycle_length] for i in range(cycle_count)]
        partial_cycle = cipher[cycle_count * cycle_length:]

        text = ''
        for i in range(cycle_length // 2 + 1):
            for cycle in full_cycles:
                if i < len(cycle):
                    text += cycle[i]
                if cycle_length - i < len(cycle) and i != cycle_length // 2:
                    text += cycle[cycle_length - i]
        text += partial_cycle
        return cipher

    @staticmethod
    def RowTransp(key,text, enc):
    # Remove spaces and convert the key to a list of integers
        try:
            key = list(map(int,key.split()))
        except:
         raise ValueError("Error,Key permutation is invalid")
        num_cols = len(key)
        num_rows = -(-len(text) // num_cols)  # Equivalent to ceil(len(text) / num_cols)
        # Pad the text with 'x' to fill the last row
        text += 'x' * (num_rows * num_cols - len(text))
        # Convert the text into a grid
        grid = [list(text[i:i+num_cols]) for i in range(0, len(text), num_cols)]
        ordered_grid=[]
        if enc:
            # Reorder the columns according to the key
            ar2 = [[0] * 2 for i in range(len(key))]
            for i in range(len(key)):
                ar2[i][0] = key[i]
                ar2[i][1] = i
            ar2 = sorted(ar2)
            cipher = ""
            for j in range(len(ar2)):
                for i in range(len(grid)):
                    cipher += grid[i][ar2[j][1]]
        else:
            cipher=""
            x=len(text)//len(key)
            l=[[''] for i in range(len(key))]
            for i in range(0,len(text),x):
                c=key.index((int(i//x)+1))
                l[c]=(text[i:i+x])
            for j in range(x):
                for i in range(len(key)):
                    cipher+=l[i][j]

        return cipher.upper()
# print(Ciphers.RowTransp("4 3 1 2 5 6 7","TTNAAPTMTSUOAODWCEIXKNLXPETX",False))