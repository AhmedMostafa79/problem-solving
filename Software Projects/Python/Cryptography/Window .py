from tkinter import *
from tkinter import ttk
from customtkinter import *
import customtkinter
from PIL import Image,ImageTk
from Crypto.Cipher import DES
from tkinter import messagebox
from DES_Cipher import DES_Cipher
from Play_Fair_Cipher import PlayfairCipher
from AES_Encryption import AES_Cipher 
from Ciphers_ import Ciphers
import binascii
class Form:
    def __init__(self):
        self.window = CTk()
        self.window.geometry('800x500+600+100')
        self.window.title('Cryptography')
        set_appearance_mode("dark")
        self.window.config(background='#1A1616')
        self.window.resizable(False, False)
        self.frames()
        # self.header()
        self.input_field()
        self.output_field()
        self.buttons()
        self.window.mainloop()
        
    def frames(self):
        self.outer_frame=CTkFrame(master=self.window,fg_color='black',width=400,height=450,corner_radius=10,bg_color='#1A1616')  
        self.outer_frame.place(x=13,y=13,relheight=0.95,relwidth=0.95)

        self.inner_frame = CTkFrame(master=self.outer_frame,width=750, height=450,corner_radius=10,bg_color='red')# #050816
        self.inner_frame.place(x=14, y=13,relheight=0.96,relwidth=0.96)


        img1=ImageTk.PhotoImage(Image.open("Image2.jpg"))
        l1=customtkinter.CTkLabel(master=self.inner_frame,image=img1,text='')
        l1.place(x=0,y=0,relheight=1,relwidth=1)

        lbl_header = CTkLabel(master=self.inner_frame, text='ANONYMOUS',bg_color='black', text_color='#1A1616',fg_color='transparent',font=('',20,'bold')
                              ,width=100,corner_radius=10)
        lbl_header.place(x=290, y=10)

    def input_field(self):
        #text Input
        lb_text=CTkLabel(master=self.inner_frame,text='Enter Text/Cipher :',text_color='black',corner_radius=5,fg_color='grey',bg_color='#7A6B6B',font=('',15,'bold'),
                         height=25)
        lb_text.place(x=10, y=150)

        self.input_text=CTkEntry(master=self.inner_frame,font=('',15,'bold'),width=200,text_color='#7A6B6B',fg_color='black')
        self.input_text.place(x=190, y=150)

        #Key input
        lb_key=CTkLabel(master=self.inner_frame,text='Enter Key :',text_color='black',corner_radius=5,fg_color='grey',bg_color='#7A6B6B',font=('',15,'bold'),
                        height=25)

        lb_key.place(x=10, y=190)

        self.input_key=CTkEntry(master=self.inner_frame,font=('',15,'bold'),width=200,text_color='#7A6B6B',fg_color='black')

        self.input_key.place(x=190, y=190)

        #Select Cipher
        self.select_cipher=CTkComboBox(master=self.inner_frame,state='readonly',fg_color='black',dropdown_fg_color='#1A1616',border_color='grey',
                                       values=['Caeser', 'Monoalphabetic', 'Playfair', 'Polyalphabetic', 'Vigenère',
                                       'Rail Fence', 'Row Transposition', 'DES', 'AES'],text_color='grey',font=('',15),width=170)
        self.select_cipher.place(x=460, y=150)

    def buttons(self):
        #encryption button
        self.encr_button=CTkButton(master=self.inner_frame,cursor='pirate',text="Encrypt",hover_color='#3B342F',width=100,height=20,text_color='#1A1616',fg_color='grey',
                                   bg_color='transparent',font=('',15,'bold'),command=self.encrypt)
        self.encr_button.place(x=180, y=330)
        #Decryption Button

        self.decr_button=CTkButton(master=self.inner_frame,text="Decrypt",hover_color='#3B342F',width=100,height=20,text_color='#1A1616',fg_color='grey',
                                   bg_color='black',font=('',15,'bold'),command=self.decrypt,cursor='pirate')
        self.decr_button.place(x=300, y=330)

    def output_field(self):

        lb_output=CTkLabel(master=self.inner_frame,text='Output :',corner_radius=5,text_color='black',fg_color='grey',bg_color='#7A6B6B',font=('',15,'bold'),
                           height=25)
        lb_output.place(x=10, y=260)

        self.output_text=CTkTextbox(master=self.inner_frame,font=('',15,'bold'),height=50,width=200,fg_color='black',bg_color='grey',text_color='grey')

        self.output_text.place(x=190, y=250)

    def encrypt(self):
        input_text = self.input_text.get()  # Get input text from input field
        key = self.input_key.get()  # Get encryption key from input field
        cipher=self.select_cipher.get()
        if not cipher:
            messagebox.showerror("Error", "Please select a cipher.")
            return
        if len(input_text)==0:
            messagebox.showerror("Error","You didn't Enter a text ")
            return
        if len(key)==0:
            messagebox.showerror("Error","You didn't Enter key")
            return
        if cipher=="Caeser":
            try:
                encrypted_text = Ciphers.Caeser(key,input_text,True) 
            except ValueError as e:
                messagebox.showerror("Error",str(e))
                return
        elif cipher=="Monoalphabetic":
            try:
                encrypted_text = Ciphers.MAlpha(key,input_text)
            except ValueError as e:
                messagebox.showerror("Error",str(e))
                return 
        elif cipher=="Playfair":
            try:
                playfair= PlayfairCipher(key)
                encrypted_text = playfair.encrypt(input_text)
            except ValueError as e:
                messagebox.showerror("Error",str(e))
                return
        elif cipher=="Polyalphabetic":
            try:
                encrypted_text = Ciphers.PAlpha(key,input_text,True)
            except ValueError as e:
                messagebox.showerror("Error",str(e))
                return 
        elif cipher=="Vigenère":
            try:
                 encrypted_text = Ciphers.Vigener(key,input_text,True)
            except ValueError as e:
                messagebox.showerror("Error",str(e))
                return
        elif cipher=="Monoalphabetic":
            try:
                encrypted_text = Ciphers.MAlpha(key,input_text,True)
            except ValueError as e:
                messagebox.showerror("Error",str(e))
                return
        elif cipher=="Rail Fence":
            try:
                encrypted_text = Ciphers.RailFence(key,input_text)
            except ValueError as e:
                messagebox.showerror("Error",str(e))
                return
        elif cipher=="Row Transposition":
            try:
                encrypted_text = Ciphers.RowTransp(key,input_text,True)
            except ValueError as e:
                messagebox.showerror("Error",str(e))
                return
        elif cipher=="DES":
            try:
                des_cipher = DES_Cipher(key)#key
                encrypted_text = des_cipher.encrypt(input_text)#plain text
            except ValueError as e:
                messagebox.showerror("Error:", str(e))
                return
        else :
            try:
                 aes_cipher=AES_Cipher(key)
                 encrypted_text = aes_cipher.encrypt(input_text)
            except ValueError as e:
                messagebox.showerror("Error",str(e))
                return
        self.output_text.delete('1.0', END)  # Clear output field
        self.output_text.insert('1.0',encrypted_text)  # Set encrypted text to output field

    def decrypt(self):
        input_text = self.input_text.get()  # Get input text from input field
        key = self.input_key.get()  # Get decryption key from input field
        cipher = self.select_cipher.get()
        
        if not cipher:
            messagebox.showerror("Error", "Please select a cipher.")
            return
        
        if len(input_text) == 0:
            messagebox.showerror("Error", "You didn't enter any text.")
            return
        
        if len(key) == 0:
            messagebox.showerror("Error", "You didn't enter a key.")
            return
        
        decrypted_text = ""
        
        if cipher == "Caeser":
            try:
                decrypted_text = Ciphers.Caeser(key, input_text,False)  # Decrypt input text using Caesar cipher
            except ValueError as e:
                messagebox.showerror("Error", str(e))
                return
        elif cipher == "Monoalphabetic":
            try:
                decrypted_text = Ciphers.D_MAlpha(key, input_text)
            except ValueError as e:
                messagebox.showerror("Error", str(e))
                return
        elif cipher == "Playfair":
            try:
                playfair = PlayfairCipher(key)
                decrypted_text = playfair.Decrypt(input_text)
            except ValueError as e:
                messagebox.showerror("Error", str(e))
                return
        elif cipher == "Polyalphabetic":
            try:
                decrypted_text = Ciphers.PAlpha(key, input_text,False)
            except ValueError as e:
                messagebox.showerror("Error", str(e))
                return
        elif cipher == "Vigenère":
            try:
                decrypted_text = Ciphers.Vigener(key, input_text,False)
            except ValueError as e:
                messagebox.showerror("Error", str(e))
                return
        elif cipher == "Rail Fence":
            try:
                decrypted_text = Ciphers.D_RailFence(key, input_text)
            except ValueError as e:
                messagebox.showerror("Error", str(e))
                return
        elif cipher == "Row Transposition":
            try:
                decrypted_text = Ciphers.RowTransp(key, input_text,False)
            except ValueError as e:
                messagebox.showerror("Error", str(e))
                return
        elif cipher == "DES":
            try:
                des_cipher = DES_Cipher(key)
                decrypted_text = des_cipher.decrypt(input_text)
            except ValueError as e:
                messagebox.showerror("Error:", str(e))
                return
        elif cipher == "AES":
            try:
                aes_cipher = AES_Cipher(key)
                decrypted_text = aes_cipher.decrypt(input_text)
            except ValueError as e:
                messagebox.showerror("Error", str(e))
                return
        
        self.output_text.delete('1.0', END)  # Clear output field
        self.output_text.insert('1.0', decrypted_text)  # Set decrypted text to output field


#Display
Form()

