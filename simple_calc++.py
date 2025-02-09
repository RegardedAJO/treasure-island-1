
# CS 115
# Final project simple_calc++

# Purpose is to create a simple calculator capable of performing basic mathematical function and display the output as a normal
# number, in scientific notation or as a percentage

import tkinter as tk
import tkinter.messagebox
import math

MATH_PI = str(math.pi)

MATH_E = str(math.e)

number_button_width = 16
number_button_height = 3

operator_button_width = 18
operator_button_height = 3

equals_button_width = 34
equals_button_height = 3

clear_button_width = 38
clear_button_height = 3


#define the calculator class
class Calculator:

    # initialize 
    # no additional parameters
    # creates the window and all buttons, box and title

    def __init__(self):
        self.calculator_window = tkinter.Tk()      

        self.calculator_window.title("Calculator") 

        self.display_box = tkinter.Entry(self.calculator_window, width=60)      
        self.display_box.grid(row=0, column=0, columnspan=5)


        self.var = tk.IntVar()
        

        self.radio_button_1 = tk.Radiobutton(self.calculator_window, text="Floating point", variable=self.var, value=1, command=self.display_float)
        self.radio_button_1.grid(row=1, column=0)

        self.radio_button_2 = tk.Radiobutton(self.calculator_window, text="Scientific Notation", variable=self.var, value=2, command=self.display_sci_not)
        self.radio_button_2.grid(row=1, column=1)

        self.radio_button_3 = tk.Radiobutton(self.calculator_window, text="Percentage (%)", variable=self.var, value=3, command=self.display_percentage)
        self.radio_button_3.grid(row=1, column=2)



    # create all of the buttons, size them and organize them on the grid
    # call the respective functions with the button

        self.button_7 = tkinter.Button(self.calculator_window, text="7", width=number_button_width, height=number_button_height, command=lambda: self.button_call(7))
        self.button_7.grid(row=3, column=0)
        self.button_8 = tkinter.Button(self.calculator_window, text="8", width=number_button_width, height=number_button_height, command=lambda: self.button_call(8))
        self.button_8.grid(row=3, column=1)
        self.button_9 = tkinter.Button(self.calculator_window, text="9", width=number_button_width, height=number_button_height, command=lambda: self.button_call(9))
        self.button_9.grid(row=3, column=2)
        self.button_plus = tkinter.Button(self.calculator_window, text="+", width=operator_button_width, height=operator_button_height, command=self.button_add)
        self.button_plus.grid(row=3, column=3)
        self.button_sqrt = tkinter.Button(self.calculator_window, text="\u221A\u203e", width=operator_button_width, height=operator_button_height, command=self.button_sqr_root)
        self.button_sqrt.grid(row=3, column=4)

        self.button_4 = tkinter.Button(self.calculator_window, text="4", width=number_button_width, height=number_button_height, command=lambda: self.button_call(4))
        self.button_4.grid(row=4, column=0)
        self.button_5 = tkinter.Button(self.calculator_window, text="5", width=number_button_width, height=number_button_height, command=lambda: self.button_call(5))
        self.button_5.grid(row=4, column=1)
        self.button_6 = tkinter.Button(self.calculator_window, text="6", width=number_button_width, height=number_button_height, command=lambda: self.button_call(6))
        self.button_6.grid(row=4, column=2)
        self.button_sub = tkinter.Button(self.calculator_window, text="-", width=operator_button_width, height=operator_button_height, command=self.button_subtract)
        self.button_sub.grid(row=4, column=3)
        self.button_cubert = tkinter.Button(self.calculator_window, text="\u221b\u203e", width=operator_button_width, height=operator_button_height, command=self.button_cube_root)
        self.button_cubert.grid(row=4, column=4)

        self.button_1 = tkinter.Button(self.calculator_window, text="1", width=number_button_width, height=number_button_height, command=lambda: self.button_call(1))
        self.button_1.grid(row=5, column=0)
        self.button_2 = tkinter.Button(self.calculator_window, text="2", width=number_button_width, height=number_button_height, command=lambda: self.button_call(2))
        self.button_2.grid(row=5, column=1)
        self.button_3 = tkinter.Button(self.calculator_window, text="3", width=number_button_width, height=number_button_height, command=lambda: self.button_call(3))
        self.button_3.grid(row=5, column=2)
        self.button_mult = tkinter.Button(self.calculator_window, text="\u00d7", width=operator_button_width, height=operator_button_height, command=self.button_multiply)
        self.button_mult.grid(row=5, column=3)
        self.button_square= tkinter.Button(self.calculator_window, text="x\u00b2", width=operator_button_width, height=operator_button_height, command=self.button_sqr)
        self.button_square.grid(row=5, column=4)

        self.button_0 = tkinter.Button(self.calculator_window, text="0", width=number_button_width, height=number_button_height, command=lambda: self.button_call(0))
        self.button_0.grid(row=6, column=0)
        self.button_pi = tkinter.Button(self.calculator_window, text="\u03c0", width=number_button_width, height=number_button_height, command=lambda: self.button_call(MATH_PI))
        self.button_pi.grid(row=6, column=1)
        self.button_divide = tkinter.Button(self.calculator_window, text="e", width=number_button_width, height=number_button_height, command=lambda: self.button_call(MATH_E))
        self.button_divide.grid(row=6, column=2)
        self.button_cubed = tkinter.Button(self.calculator_window, text="\u00f7", width=operator_button_width, height=operator_button_height, command=self.button_division)
        self.button_cubed.grid(row=6, column=3)
        self.button_e = tkinter.Button(self.calculator_window, text="x\u00b3", width=operator_button_width, height=operator_button_height, command=self.button_cube)
        self.button_e.grid(row=6, column=4)

        self.button_decimal = tkinter.Button(self.calculator_window, text=".", width=number_button_width, height=number_button_height, command=lambda: self.button_call("."))
        self.button_decimal.grid(row=7, column=0, columnspan=1)
        self.button_equals = tkinter.Button(self.calculator_window, text="=", width=equals_button_width, height=equals_button_height, command=self.button_equal)
        self.button_equals.grid(row=7, column=1, columnspan=2)
        self.button_clearit = tkinter.Button(self.calculator_window, text="Clear", width=clear_button_width, height=clear_button_height, command=self.button_clear)
        self.button_clearit.grid(row=7, column=3, columnspan=2)
        

    # run the loop to create the window

        tkinter.mainloop()
    
    


    # display_float
    # parameters: self
    # purpose to get the value from the display box, process it to string of numbers, convert to float, format and output back to display box

    def display_float(self):
        value = self.display_box.get()
        if "%" in value:
            value = value.rstrip("%")
            value = (float(value))/100
            self.display_box.delete(0, "end")
            self.display_box.insert(0, str(f"{value:.2f}"))
            
        else:
            value = float(value)
            self.display_box.delete(0, "end")
            self.display_box.insert(0, str(f"{value:.2f}"))


    
    # display_sci_not
    # parameters: self
    # purpose to get the value from the display box, process it to string of numbers, convert to scientific notation, format and output back to display box

    def display_sci_not(self):
        value = self.display_box.get()
        if "%" in value:
            value = value.rstrip("%")
            value = (float(value))/100
            self.display_box.delete(0, "end")
            self.display_box.insert(0, str(f"{value:.2e}"))
            
        else:
            value = float(value)
            self.display_box.delete(0, "end")
            self.display_box.insert(0, str(f"{value:.2e}"))
    
    
    # display_percentage
    # parameters: self
    # purpose to get the value from the display box, process it to string of numbers, convert to percentage, format and output back to display box

    def display_percentage(self):
        value = self.display_box.get()
        if "%" in value:
            value = value.rstrip("%")
            value = (float(value))/100
            self.display_box.delete(0, "end")
            self.display_box.insert(0, str(f"{value:.2%}"))
            
        else:
            value = float(value)
            self.display_box.delete(0, "end")
            self.display_box.insert(0, str(f"{value:.2%}"))


    
    # button_call
    # parameters: self and the number/pi/e on the button
    # purpose to print the number selected in the display box for the user

    def button_call(self, number):
        current = self.display_box.get()
        self.display_box.delete(0, "end")       
        self.display_box.insert(0, str(current) + str(number))
    

    # button_clear
    # parameters: self
    # purpose to clear the display box

    def button_clear(self):
        self.display_box.delete(0, "end")

    # button_add
    # parameters: self
    # purpose to set the math operator that will be used to addtion (+), store the first value and clear the display box

    def button_add(self):
        value = self.display_box.get()
        global f_num
        global operator
        f_num = float(value)
        self.display_box.delete(0, "end")
        operator = "addition"
    
    # button_subtract
    # parameters: self
    # purpose to set the math operator that will be used to subtraction (-), store the first value and clear the display box

    def button_subtract(self):
        value = self.display_box.get()
        global f_num
        global operator
        f_num = float(value)
        self.display_box.delete(0, "end")
        operator = "subtraction"
    
    # button_multiply
    # parameters: self
    # purpose to set the math operator that will be used to multiplication (*), store the first value and clear the display box

    def button_multiply(self):
        value = self.display_box.get()
        global f_num
        global operator
        f_num = float(value)
        self.display_box.delete(0, "end")
        operator = "multiplication"
    
    # button_add
    # parameters: self
    # purpose to set the math operator that will be used to division (/), store the first value and clear the display box

    def button_division(self):
        value = self.display_box.get()
        global f_num
        global operator
        f_num = float(value)
        self.display_box.delete(0, "end")
        operator = "division"

    # button_sqr
    # parameters: self
    # purpose to square the number entered

    def button_sqr(self):
        value = self.display_box.get()
        num = float(value)
        equals = num**2
        self.display_box.delete(0, "end")
        self.display_box.insert(0, str(f"{equals:.2f}"))
        
    
    # button_cube
    # parameters: self
    # purpose to cube the number entered

    def button_cube(self):
        value = self.display_box.get()
        num = float(value)
        equals = num**3
        self.display_box.delete(0, "end")
        self.display_box.insert(0, str(f"{equals:.2f}"))
    
    # button_sqr_root
    # parameters: self
    # purpose to calculate the square root of the number entered

    def button_sqr_root(self):
        value = self.display_box.get()
        num = float(value)
        equals = math.sqrt(num)
        self.display_box.delete(0, "end")
        self.display_box.insert(0, str(f"{equals:.2f}"))
    
    # button_cube_root
    # parameters: self
    # purpose to calculate the cube root of the number entered

    def button_cube_root(self):
        value = self.display_box.get()
        num = float(value)
        equals = math.pow(num, 1/3)
        self.display_box.delete(0, "end")
        self.display_box.insert(0, str(f"{equals:.2f}"))
    
    # button_equal
    # Parameters self
    # purpose to perform the calculation that was selected on the two values and display the result in the box
    # checks to make sure user does not divide by zero, displays error
    
    def button_equal(self):
        
            if operator == "addition":
                value2 = self.display_box.get()
                self.display_box.delete(0, "end")           
                value2 = float(value2)
                equals = f_num + value2
                self.display_box.insert(0, str(f"{equals:.2f}"))

            elif operator == "subtraction":
                value2 = self.display_box.get()
                self.display_box.delete(0, "end")
                value2 = float(value2)
                equals = f_num - value2
                self.display_box.insert(0, str(f"{equals:2f}"))

            elif operator == "multiplication":
                value2 = self.display_box.get()
                self.display_box.delete(0, "end")
                value2 = float(value2)
                equals = f_num * value2
                self.display_box.insert(0, str(f"{equals:.2f}"))

            elif operator == "division":
                value2 = float(self.display_box.get())

                if value2 == 0:
                    self.display_box.delete(0, "end")
                    self.display_box.insert(0, "Invalid input, cannot divide by 0 (zero)")
                    
                else:
                    self.display_box.delete(0, "end")
                    equals = f_num / value2
                    self.display_box.insert(0, str(f"{equals:.2f}"))


calc = Calculator()

